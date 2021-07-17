#include "INSTRUCTION.h"
#include "../Memory/Memory.h"
#include "../Init/Init.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

extern int PPRINT;

/** 
 * here we take unique approach
 * and try to push data using address of 
 * CPU structure, typecasting it.
 */



int PUSH (int8_t data) {
	
	*(((char*)&CPU_8051) + CPU_8051.SFR[SP]) = data;
	CPU_8051.SFR[SP] += 1;

if ( PPRINT ) {
printf ("\tPUSH %d\n", data);
}
	
	return 1;

}	

int8_t POP ( ) {

	int8_t data;
	CPU_8051.SFR[SP] -= 1;
	data = *(((char*)&CPU_8051) + CPU_8051.SFR[SP]);
	
if ( PPRINT ) {	
printf ("\tPOP ,data : %d\n", data);
}

	return data;
}

int NOP () {
if ( PPRINT ) {		
printf ("\tNOP\n");
}
	return 1;
}


int AJMP_0x01 () { 
	uint16_t low_add_byte = fetch ( );
	CPU_8051.PC = ( ( CPU_8051.PC & 0xF800) | (0x01 & 0x70) ) | low_add_byte;

if ( PPRINT ) {		
printf ("\tAJMP address %hx\n", low_add_byte);
}
	return 1;
}

/** 0x02, 
 * assuming data or address is stored in little endian format
 */
int LJMP ( ) {
	uint8_t high_byte = fetch ( );
	uint8_t low_byte = fetch ( );
	uint16_t jmp_addr = (high_byte << 8) | low_byte;
	CPU_8051.PC = jmp_addr;
	
if ( PPRINT ) {
printf ("\tLJMP %hx\n", jmp_addr);
}
	return 1;	
}

// 0x03
int RR ( ) {
	int8_t tmp = CPU_8051.SFR[ACC];
	CPU_8051.SFR[ACC] = (CPU_8051.SFR[ACC] << 1) | (tmp >> 7);
if ( PPRINT ) {		
printf ("\tRR %hhx\n", tmp);
}
	return 1;
}

// 0x04
int INC_A ( ) {
	int8_t temp = CPU_8051.SFR[ACC];
	temp++;
	CPU_8051.SFR[ACC] = temp;
	update_parity();
if ( PPRINT ) {		
printf ("\tINC A %hhx\n", temp);
}

	return 1;
}

// 0x05
int INC_data_addr ( ) {
	int8_t addr = fetch ( );
	CPU_8051.Code_Memory[addr] += 1;
if ( PPRINT ) {		
printf ("\tINC data_address  address : %hhx\n", addr);
}

	return 1;
}	

// 0x06
int INC_at_R0 ( ) {
	int8_t tmp = CPU_8051.REGISTERS[BANK ( )].R0;

	/** we can only address code memory here, not give RAM address in R0 */
	CPU_8051.Code_Memory[tmp] += 1;
if ( PPRINT ) {		
printf ("\tINC @R0\n");
}

	return 1;
}

// 0x07
int INC_at_R1 ( ){
	int8_t tmp = CPU_8051.REGISTERS[BANK ( )].R1;
	/** we can only address code memory here, not give RAM address in R1 */
	CPU_8051.Code_Memory[tmp] += 1;
if ( PPRINT ) {		
printf ("\tINC @R1\n");
}

	return 1;

}

// 0x08
int INC_R0 ( ) {
	CPU_8051.REGISTERS[BANK ( )].R0 += 1;
if ( PPRINT ) {		
printf ("\tINC R0\n");
}

	return 1;
}

// 0x09
int INC_R1 ( ) {
	CPU_8051.REGISTERS[BANK ( )].R1 += 1;
if ( PPRINT ) {		
printf ("\tINC R1\n");
}

	return 1;
}

// 0x0A
int INC_R2 ( ) {
	CPU_8051.REGISTERS[BANK ( )].R2 += 1;
if ( PPRINT ) {		
printf ("\tINC R2\n");
}

	return 1;
}

// 0x0B
int INC_R3 ( ) {
	CPU_8051.REGISTERS[BANK ( )].R3 += 1;
if ( PPRINT ) {		
printf ("\tINC R3\n");
}

	return 1;	
}

// 0x0C
int INC_R4 ( ) {
	CPU_8051.REGISTERS[BANK ( )].R4 += 1;
if ( PPRINT ) {		
printf ("\tINC R4\n");
}
	return 1;	
}

// 0x0D
int INC_R5 ( ) {
	CPU_8051.REGISTERS[BANK ( )].R5 += 1;
if ( PPRINT ) {		
printf ("\tINC R5\n");
}
	return 1;
}

//0x0E
int INC_R6 ( ) {
	CPU_8051.REGISTERS[BANK ( )].R6 += 1;
if ( PPRINT ) {		
printf ("\tINC R6\n");
}
	return 1;
}

//0x0F
int INC_R7 ( ) {
	CPU_8051.REGISTERS[BANK ( )].R7 += 1;
if ( PPRINT ) {		
printf ("\tINC R7\n");
}
	return 1;
}


/** 
 * JBC : jump if bit is set and clear bit
 * 0x10
 * 3 bytes instruction
 * JBC bit_addr code_addr
 */ 
int JBC ( ) {	
	uint8_t bit_addr = fetch ( );
	int8_t code_addr = fetch ( );

	if (resolve_bit_addr(bit_addr)) {
		CPU_8051.PC += code_addr;		
	}

if ( PPRINT ) {		
printf ("\tJBC | bit address : %X  | jump address : %X\n", bit_addr, code_addr);
}

	return 1;
}

// 0x11
/** uses the 11 bit format, same as AJMP
 * 
 * push next address into the stack, 
 * next instruction address will be
 * PC + 2, as next address stores lower 8 bit of address
 * 
 * stack stores address as byte by byte, so first we will push
 * lower byte of address and then upper byte address of PC,
 * litte endian behaviour
 */
int ACALL_0x11 ( ) {

	uint8_t lower_addr_byte = fetch ( );
	uint16_t push_addr = CPU_8051.PC;
	
	PUSH (push_addr & 0x00FF); // pushing lower byte
	PUSH ( (push_addr & 0xFF00) >> 8); //have to push it lower by 8 otherwise it will give error.

	// change PC to jmp to subroutine
	CPU_8051.PC = ( (CPU_8051.PC & 0xF800) | (0x11 & 0x70) ) | lower_addr_byte;

if ( PPRINT ) {		
printf ("\tACALL_0x11 lower byte addr %X\n", lower_addr_byte);
}
	
	return 1; 
	
}

//0x12
int LCALL ( ) {

	if (PPRINT) { 
	printf ("pprintf = 1\n");
	}
	// change PC to jmp to subroutine
	uint8_t upper_addr_byte = fetch( );
	uint8_t lower_addr_byte = fetch ( );
	uint16_t push_addr = CPU_8051.PC;
	uint16_t new_addr = ( upper_addr_byte << 8) | lower_addr_byte;

	
	PUSH (push_addr & 0x00FF); // pushing lower byte
	PUSH ( (push_addr & 0xFF00) >> 8); //have to push it after lowering or shifting by 8 otherwise it will give error.
	CPU_8051.PC = new_addr;
if ( PPRINT ) {		
printf ("\tLCALL %X\n", new_addr);
}

	return 1;

}

/**
 * 0x13
 * RRC_A : Rotate Accumulator Right through Carry Flag
 * 1 byte instruction
 */
int RRC_A ( ) { 
	uint8_t zero_bit = CPU_8051.SFR[ACC] & ( 1 < 1 );
	uint8_t carry_status = CPU_8051.SFR[PSW] & CY;

	// rotating the accumulator register right
	CPU_8051.SFR[ACC] >>= 1;

	// putting right most bit of accumulator in carry
	if (zero_bit) // is last bit was 1
	{
		CPU_8051.SFR[PSW] |= CY;
	}
	else	// if last bit is zero
	{
		CPU_8051.SFR[PSW] &= (~CY);
	}

	// transfering carry value into the MSB of ACC

	if (carry_status)	// if carry was 1
	{
		CPU_8051.SFR[ACC] |= CY;
	}
	else 			// if carry was 0
	{
		CPU_8051.SFR[ACC] &= ~(CY);
	}

if ( PPRINT ) {		
printf ("\tRRC A\n");
}
	return 1;
} 

// 0x14
int DEC_A ( ) {
	CPU_8051.SFR[ACC] -= 1;

if ( PPRINT ) {		
printf ("\tDEC A\n");
}
	return 1;
}
// 0x15
int DEC_data_addr ( ) {
	int8_t addr = fetch();
	CPU_8051.Code_Memory[addr] -= 1;
if ( PPRINT ) {		
printf ("\tDEC @%X\n",addr);
}
	return 1;
}

// 0x16
int DEC_at_R0 ( ) {
	int8_t tmp = CPU_8051.REGISTERS[BANK ( )].R0;
	/** we can only address code memory here, not give RAM address in R0 */
	CPU_8051.Code_Memory[tmp] -= 1;
if ( PPRINT ) {		
printf ("\tDEC @R0 | R0 : %X\n", CPU_8051.REGISTERS[BANK ( )].R0);
}
	return 1;
}

// 0x17
int DEC_at_R1 ( ) {
	int8_t tmp = CPU_8051.REGISTERS[BANK ( )].R1;
	/** we can only address code memory here, not give RAM address in R1 */
	CPU_8051.Code_Memory[tmp] -= 1;
if ( PPRINT ) {		
printf ("\tDEC @R1 | R1 : %X\n", CPU_8051.REGISTERS[BANK ( )].R1);
}
	return 1;
}
//0x18
int DEC_R0 ( ) {
	CPU_8051.REGISTERS[BANK ( )].R0 -= 1;

if ( PPRINT ) {		
printf ("\tDEC R0\n");
}
	return 1;	
}

// 0x19
int DEC_R1 ( ) {
	CPU_8051.REGISTERS[BANK ( )].R1 -= 1;

if ( PPRINT ) {		
printf ("\tDEC R1\n");
}
	return 1;	
}

// 0x1A
int DEC_R2 ( ) {
	CPU_8051.REGISTERS[BANK ( )].R2 -= 1;

if ( PPRINT ) {		
printf ("\tDEC R2\n");
}
	return 1;	
}

// 0x1B
int DEC_R3 ( ) {
	CPU_8051.REGISTERS[BANK ( )].R3 -= 1;

if ( PPRINT ) {		
printf ("\tDEC R3\n");
}

	return 1;	
}

// 0x1C
int DEC_R4 ( ) {
	CPU_8051.REGISTERS[BANK ( )].R4 -= 1;

if ( PPRINT ) {		
printf ("\tDEC R4\n");
}

	return 1;	
}

// 0x1D
int DEC_R5 ( ) {
	CPU_8051.REGISTERS[BANK ( )].R5 -= 1;

if ( PPRINT ) {		
printf ("\tDEC R5\n");
}

	return 1;	
}

// 0x1E
int DEC_R6 ( ) {
	CPU_8051.REGISTERS[BANK ( )].R6 -= 1;

if ( PPRINT ) {		
printf ("\tDEC R6\n");
}

	return 1;	
}

// 0x1F
int DEC_R7 ( ) {
	CPU_8051.REGISTERS[BANK ( )].R7 -= 1;

if ( PPRINT ) {		
printf ("\tDEC R7\n");
}

	return 1;	
}


// 0x20
/** jump if given bit given by address is set, 
 * opcode bit_addr jump_addr
 * jump addr = increment pc to next instruction + jump addr
 */
int JB ( ) {
	
	uint8_t addr = fetch ( );
	int8_t jump_addr = fetch ( );
	if (resolve_bit_addr (addr)) {
		CPU_8051.PC += jump_addr + 1;
	}

if ( PPRINT ) {		
printf ("\tJB %X | jump address : %X\n", addr, jump_addr);
}

	return 1;
}

//0x21
int AJMP_0x21 ( ) { 
	uint16_t low_add_byte = fetch ( );
	CPU_8051.PC = ( ( CPU_8051.PC & 0xF800) | (0x21 & 0x70) ) | low_add_byte;

if ( PPRINT ) {		
printf ("\tAJMP_0x21  %X\n", low_add_byte);
}

	return 1;
}

/**
 * 0x22 
 * RET : return from subroutine
 * 1 byte instruction
 * 
 * RET pops the high-and low-orderbytes of the PC successively
 * from the stack decrementing the Stack Pointer by two
 */
int RET ( ) {  
	uint8_t high_addr = POP ( );
	uint8_t low_addr = POP ( );

	CPU_8051.PC = (high_addr << 8) | low_addr;

if ( PPRINT ) {		
printf ("\tRET\n");
}

	return 1;
} 

/** 
 * 0x23
 * RL : Rotate Accumulator Left
 * 1 byte instruction
 */	
int RL ( ) {
	uint8_t acc_msb = CPU_8051.SFR[ACC] & ( 1 << 7 );
	CPU_8051.SFR[ACC] << 1;

	if (acc_msb)	// if MSB of ACC was 1 before rotate, make LSB 1
	{
		CPU_8051.SFR[ACC] |= ( 1 << 1);
	}
	else {
		CPU_8051.SFR[ACC] &= ~( 1 << 1);
	}

if ( PPRINT ) {		
printf ("\tRL A\n");
}

	return 1;
}

/** 0x24
 * ADD A, data : add immmediate data to the accumulator
 * 2 byte instruction,
 */
int ADD_data ( ) {
	
	int8_t data = fetch ( );
	CPU_8051.SFR[ACC] = add (CPU_8051.SFR[ACC] , data);
	
if ( PPRINT ) {		
printf ("\tADD A, #%X\n", data);
}

	return 1;
}

int ADD_data_addr ( ) {
	
	uint8_t addr = fetch ( );
	int8_t data = *( (char*)&CPU_8051 + addr );

	CPU_8051.SFR[ACC] = add (CPU_8051.SFR[ACC], data);

if ( PPRINT ) {		
printf ("\tADD A, @data_address\n",addr);
}

	return 1;
}

int ADD_at_R0 ( ) {

	uint8_t addr = CPU_8051.REGISTERS[BANK ( )].R0;
	int8_t data = *( (char*)&CPU_8051 + addr);

	CPU_8051.SFR[ACC] = add ( CPU_8051.SFR[ACC], data);

if ( PPRINT ) {		
printf ("\tADD A, @R0 | R0 : %X\n", addr);
}

	return 1;

} 

// 0x27
int ADD_at_R1 ( ) { 

	uint8_t addr = CPU_8051.REGISTERS[BANK ( )].R1;
	int8_t data = *( (char*)&CPU_8051 + addr);

	CPU_8051.SFR[ACC] = add ( CPU_8051.SFR[ACC], data);

if ( PPRINT ) {		
printf ("\tADD A, @R1  | R1 : %X\n", addr);
}
	return 1;

} 

/** 0x28
 * ADD A, R0
 * 
 * add data from R0 to accumulator
 */
int ADD_R0 ( ) {

	int8_t data = CPU_8051.REGISTERS[BANK ( )].R0;
	CPU_8051.SFR[ACC] = add ( CPU_8051.SFR[ACC], data);

if ( PPRINT ) {		
printf ("\tADD A, R0  | R0 : %X\n", data);
}

	return 0;
}

/** 0x29
 * ADD A, R1
 * 
 * add data from R1 to accumulator
 */
int ADD_R1 ( ) {

	int8_t data = CPU_8051.REGISTERS[BANK ( )].R1;
	CPU_8051.SFR[ACC] = add ( CPU_8051.SFR[ACC], data);

if ( PPRINT ) {		
printf ("\tADD A, R1 | R1 : %X\n", data);
}

	return 0;

}

/** 0x2A
 * ADD A, R2
 * 
 * add data from R2 to accumulator
 */
int ADD_R2 ( ) {

	int8_t data = CPU_8051.REGISTERS[BANK ( )].R2;
	CPU_8051.SFR[ACC] = add ( CPU_8051.SFR[ACC], data);

if ( PPRINT ) {		
printf ("\tADD A, R2  | R2 : %X\n", data);
}

	return 0;

}

/** 0x2B
 * ADD A, R3
 * 
 * add data from R3 to accumulator
 */
int ADD_R3 ( ) {

	int8_t data = CPU_8051.REGISTERS[BANK ( )].R3;
	CPU_8051.SFR[ACC] = add ( CPU_8051.SFR[ACC], data);

if ( PPRINT ) {		
printf ("\tADD A, R3  | R3 : %X\n", data);
}

	return 0;

}

/** 0x2C
 * ADD A, R4
 * 
 * add data from R4 to accumulator
 */
int ADD_R4 ( ) {

	int8_t data = CPU_8051.REGISTERS[BANK ( )].R4;
	CPU_8051.SFR[ACC] = add ( CPU_8051.SFR[ACC], data);

if ( PPRINT ) {		
printf ("\tADD A, R4  | R4 : %X\n", data);
}
	return 0;

}

/** 0x2D
 * ADD A, R5
 * 
 * add data from R5 to accumulator
 */
int ADD_R5 ( ) {

	int8_t data = CPU_8051.REGISTERS[BANK ( )].R5;
	CPU_8051.SFR[ACC] = add ( CPU_8051.SFR[ACC], data);

if ( PPRINT ) {		
printf ("\tADD A, R5  | R5 : %X\n", data);
}
	return 0;

}

/** 0x2E
 * ADD A, R6
 * 
 * add data from R6 to accumulator
 */
int ADD_R6 ( ) {

	int8_t data = CPU_8051.REGISTERS[BANK ( )].R6;
	CPU_8051.SFR[ACC] = add ( CPU_8051.SFR[ACC], data);

if ( PPRINT ) {		
printf ("\tADD A, R6  | R6 : %X\n", data);
}
	
	return 0;

}

/** 0x2F
 * ADD A, R7
 * 
 * add data from R7 to accumulator
 */
int ADD_R7 ( ) {

	int8_t data = CPU_8051.REGISTERS[BANK ( )].R7;
	CPU_8051.SFR[ACC] = add ( CPU_8051.SFR[ACC], data);

if ( PPRINT ) {		
printf ("\tADD A, R7 | R7 : %X\n", data);
}
	return 0;

}

//0x30
/** jump if bit is not zero
 * JNB Bit addr REL addr
 */
int JNB ( ) {

	uint8_t bit_addr = fetch ( );
	int8_t rel_addr = fetch ( );

	int tmp = resolve_bit_addr ( bit_addr);
	
	if (tmp == 0) {
		CPU_8051.PC += rel_addr;
	}

if ( PPRINT ) {		
printf ("\tJNB %X, %X\n", bit_addr, rel_addr);
}

	return 1;
}

//0x31
int ACALL_0x31 ( ) {

	uint8_t lower_addr_byte = fetch ( );
	uint16_t push_addr = CPU_8051.PC;
	
	PUSH (push_addr & 0x00FF); // pushing lower byte
	PUSH ( (push_addr & 0xFF00) >> 8); //have to push it lower by 8 otherwise it will give error.

	// change PC to jmp to subroutine
	CPU_8051.PC = ( (CPU_8051.PC & 0xF800) | (0x31 & 0x70) ) | lower_addr_byte;

if ( PPRINT ) {		
printf ("\tACALL_0x31 lower byte addr %X\n", lower_addr_byte);
}

	return 1; 
	
}

/** 0x32
 * RETI : Return from Interrupt
 * REstoring the previous interrupt mask part is yet to 
 * program
 */
int RETI ( ) {

	uint8_t high_addr = POP ( );
	uint8_t low_addr = POP ( );
	uint16_t return_addr = ((high_addr << 8) | low_addr );
	CPU_8051.PC = return_addr;

if ( PPRINT ) {		
printf ("\tRETI %X\n", return_addr);
}

	return 1;
}


/** 0x33
 * RLC : Rotate Left Through Carry
 * 1 byte instruction 
 */
int RLC ( ) {
	
	int8_t acc_msb = CPU_8051.SFR[ACC] & 0x80;
	CPU_8051.SFR[ACC] <<= 1;

	// now adjsting LSB of ACC from carry.
	if ( CPU_8051.SFR[PSW] & CY ) {
		CPU_8051.SFR[ACC] |= 0x01;
	}
	else {
		CPU_8051.SFR[ACC] &= 0xFE;
	}

	// adjusting carry from MSB of acc before shifting

	if (acc_msb) {
		CPU_8051.SFR[PSW] |= CY;
	}
	else {
		CPU_8051.SFR[PSW] &= ~(CY);
	}

if ( PPRINT ) {		
printf ("\tRLC A\n");
}

	return 1;
}

/** 0x34
 * ADDC A, imm_data : Add with carry the immediate data in accumulator
 * 2 byte instruction
 * 
 * here OV flag is set
 */
int ADDC_data ( ) {

	int8_t data = fetch ( );
	CPU_8051.SFR[ACC] = addc ( CPU_8051.SFR[ACC], data);

if ( PPRINT ) {		
printf ("\tADDC A, #%X\n", data);
}

	return 1;
} 

int ADDC_data_addr ( ) {  

	uint8_t addr = fetch ( );
	int8_t data = *( (char*)&CPU_8051 + addr);
	CPU_8051.SFR[ACC] = addc ( CPU_8051.SFR[ACC], data);

if ( PPRINT ) {		
printf ("\tADDC A, @%X | @%X : %hhX\n", addr, addr, *( (char*)&CPU_8051 + addr));
}

	return 1;

} 

int ADDC_at_R0 ( ) {  

	uint8_t addr = CPU_8051.REGISTERS[BANK ( )].R0;
	int8_t data = *( (char*)&CPU_8051 + addr);
	CPU_8051.SFR[ACC] = addc ( CPU_8051.SFR[ACC], data);

if ( PPRINT ) {		
printf ("\tADDC A, @R0 | @R0 : %X\n", addr);
}

	return 1;
} 
// 0x37 
int ADDC_at_R1 ( ) { 

	uint8_t addr = CPU_8051.REGISTERS[BANK ( )].R1;
	int8_t data = *( (char*)&CPU_8051 + addr);
	CPU_8051.SFR[ACC] = addc ( CPU_8051.SFR[ACC], data);

if ( PPRINT ) {		
printf ("\tADDC A, @R1 | @R1 : %X\n", addr);
}

	return 1;

}

int ADDC_R0 ( ) {  

	int8_t data = CPU_8051.REGISTERS[BANK ( )].R0;
	CPU_8051.SFR[ACC] = addc ( CPU_8051.SFR[ACC], data);

if ( PPRINT ) {		
printf ("\tADDC A, R0 | R0 : %X\n", data);
}

	return 1;

} 

int ADDC_R1 ( ) {  

	int8_t data = CPU_8051.REGISTERS[BANK ( )].R1;
	CPU_8051.SFR[ACC] = addc ( CPU_8051.SFR[ACC], data);

if ( PPRINT ) {		
printf ("\tADDC A, R1 | R1 : %X\n", data);
}

	return 1;

} 

int ADDC_R2 ( ) {  

	int8_t data = CPU_8051.REGISTERS[BANK ( )].R2;
	CPU_8051.SFR[ACC] = addc ( CPU_8051.SFR[ACC], data);

if ( PPRINT ) {		
printf ("\tADDC A, R2 | R2 : %X\n", data);
}

	return 1;

} 

int ADDC_R3 ( ) {  

	int8_t data = CPU_8051.REGISTERS[BANK ( )].R3;
	CPU_8051.SFR[ACC] = addc ( CPU_8051.SFR[ACC], data);

if ( PPRINT ) {		
printf ("\tADDC A, R3 | R3 : %X\n", data);
}

	return 1;

}

int ADDC_R4 ( ) {  

	int8_t data = CPU_8051.REGISTERS[BANK ( )].R4;
	CPU_8051.SFR[ACC] = addc ( CPU_8051.SFR[ACC], data);

if ( PPRINT ) {		
printf ("\tADDC A, R4 | R4 : %X\n", data);
}

	return 1;

} 

int ADDC_R5 ( ) {  

	int8_t data = CPU_8051.REGISTERS[BANK ( )].R5;
	CPU_8051.SFR[ACC] = addc ( CPU_8051.SFR[ACC], data);

if ( PPRINT ) {		
printf ("\tADDC A, R5 | R5 : %X\n", data);
}

	return 1;

} 

int ADDC_R6 ( ) {  

	int8_t data = CPU_8051.REGISTERS[BANK ( )].R6;
	CPU_8051.SFR[ACC] = addc ( CPU_8051.SFR[ACC], data);

if ( PPRINT ) {		
printf ("\tADDC A, R6 | R6 : %X\n", data);
}

	return 1;

} 

//0x3F
int ADDC_R7 ( ) {  

	int8_t data = CPU_8051.REGISTERS[BANK ( )].R7;
	CPU_8051.SFR[ACC] = addc ( CPU_8051.SFR[ACC], data);

if ( PPRINT ) {		
printf ("\tADDC A, R7 | R7 : %X\n", data);
}

	return 1;

}

/** 0x40
 * jump if carry
 */
int JC ( ) {

	int8_t addr = fetch ( );
	if ( (CPU_8051.SFR[PSW] & CY) ) {
		CPU_8051.PC += addr;
	}

if ( PPRINT ) {		
printf ("\tJC %X\n", addr);
}

	return 1;

}

//0x41
int AJMP_0x41 ( ){ 
	uint16_t low_add_byte = fetch ( );
	CPU_8051.PC = ( ( CPU_8051.PC & 0xF800) | (0x41 & 0x70) ) | low_add_byte;

if ( PPRINT ) {		
printf ("\tAJMP_0x41 %X\n", low_add_byte);
}

	return 1;
}	

int ORL_data_addr_A ( ) {

	uint8_t addr = fetch ( );
	int8_t data = *( (char*)&CPU_8051 + addr );
	data |= CPU_8051.SFR[ACC];
	*( (char*)&CPU_8051 + addr ) = data;

if ( PPRINT ) {		
printf ("\tORL @%X,A  | @%X : %X\n", addr, addr, data);
}

	return 1;

} 


int ORL_data_addr_data ( ) {

	uint8_t addr = fetch ( );
	int8_t data = *( (char*)&CPU_8051 + addr );
	int8_t operand2 = fetch ( );
	data &= operand2;
	*( (char*)&CPU_8051 + addr ) = data;

if ( PPRINT ) {		
printf ("\tORL @%X, #%X  | @%X : %X\n", addr, operand2, data);
}

	return 1;

} 


/** ORL A, #data
 * 2 byte instruction
 */
int ORL_A_data ( ) {
	int8_t data = fetch ( );
	CPU_8051.SFR[ACC] |= data;

if ( PPRINT ) {		
printf ("\tORL A, #%X \n", data);
}

	return 1;
} 

int ORL_A_data_addr ( ) {

	uint8_t addr = fetch ( );
	int8_t data = *( (char*)&CPU_8051 + addr );
	CPU_8051.SFR[ACC] |= data;

if ( PPRINT ) {		
printf ("\tORL A, @%X | @%X : %X\n", addr, data);
}

	return 1;

}


int ORL_acc_at_R0 ( ) {

	uint8_t addr = CPU_8051.REGISTERS[BANK ( )].R0;
	int8_t data = *( (char*)&CPU_8051 + addr );
	CPU_8051.SFR[ACC] |= data;

if ( PPRINT ) {		
printf ("\tORL A, @R0 | R0 : %X\n", addr);
}

	return 1;

} 

// 0x47
int ORL_acc_at_R1 ( ) {

	uint8_t addr = CPU_8051.REGISTERS[BANK ( )].R1;
	int8_t data = *( (char*)&CPU_8051 + addr );
	CPU_8051.SFR[ACC] |= data;

if ( PPRINT ) {		
printf ("\tORL A, @R1 | R1 : %X\n", addr);
}

	return 1;
	
} 

/** 0x48 
 * ORL A, R0
 */
int ORL_R0 ( ) { 

	CPU_8051.SFR[ACC] |= CPU_8051.REGISTERS[BANK ( )].R0;

if ( PPRINT ) {		
printf ("\tORL A, R0 | R0 : %X\n", CPU_8051.REGISTERS[BANK ( )].R0);
}

	return 1;

} 

int ORL_R1 ( ) { 
	CPU_8051.SFR[ACC] |= CPU_8051.REGISTERS[BANK ( )].R1;

if ( PPRINT ) {		
printf ("\tORL A, R1 | R1 : %X\n", CPU_8051.REGISTERS[BANK ( )].R1);
}
	return 1;
}  

int ORL_R2 ( ) { 
	CPU_8051.SFR[ACC] |= CPU_8051.REGISTERS[BANK ( )].R2;

if ( PPRINT ) {		
printf ("\tORL A, R2 | R2 : %X\n", CPU_8051.REGISTERS[BANK ( )].R2);
}

	return 1;
} 

int ORL_R3 ( ) { 
	CPU_8051.SFR[ACC] |= CPU_8051.REGISTERS[BANK ( )].R3;

if ( PPRINT ) {		
printf ("\tORL A, R3 | R3 : %X\n", CPU_8051.REGISTERS[BANK ( )].R3);
}

	return 1;
}  

int ORL_R4 ( ) { 
	CPU_8051.SFR[ACC] |= CPU_8051.REGISTERS[BANK ( )].R4;

if ( PPRINT ) {		
printf ("\tORL A, R4 | R4 : %X\n", CPU_8051.REGISTERS[BANK ( )].R4);
}

	return 1;
} 

int ORL_R5 ( ) { 
	CPU_8051.SFR[ACC] |= CPU_8051.REGISTERS[BANK ( )].R5;

if ( PPRINT ) {		
printf ("\tORL A, R5 | R5 : %X\n", CPU_8051.REGISTERS[BANK ( )].R5);
}

	return 1;
} 


int ORL_R6 ( ) { 
	CPU_8051.SFR[ACC] |= CPU_8051.REGISTERS[BANK ( )].R6;

if ( PPRINT ) {		
printf ("\tORL A, R6 | R6 : %X\n", CPU_8051.REGISTERS[BANK ( )].R6);
}

	return 1;
} 

int ORL_R7 ( ) { 
	CPU_8051.SFR[ACC] |= CPU_8051.REGISTERS[BANK ( )].R7;

if ( PPRINT ) {		
printf ("\tORL A, R7 | R7 : %X\n", CPU_8051.REGISTERS[BANK ( )].R7);
}

	return 1;
} 

// 0x50
/** jump is carry not set
 */
int JNC ( ) { 

	int8_t addr = fetch ( );
	if ( CPU_8051.SFR[PSW] & CY) {
		return 1;
	}
	else {
		CPU_8051.PC += addr;	
	}

if ( PPRINT ) {		
printf ("\tJNC %X\n", addr);
}

	return 1;
}

//0x51
int ACALL_0x51 ( ) {

	uint8_t lower_addr_byte = fetch ( );
	uint16_t push_addr = CPU_8051.PC;
	
	PUSH (push_addr & 0x00FF); // pushing lower byte
	PUSH ( (push_addr & 0xFF00) >> 8); //have to push it lower by 8 otherwise it will give error.

	// change PC to jmp to subroutine
	CPU_8051.PC = ( (CPU_8051.PC & 0xF800) | (0x51 & 0x70) ) | lower_addr_byte;

if ( PPRINT ) {		
printf ("\tACALL_0x51 lower byte addr %X\n", lower_addr_byte);
}

	return 1; 
	
}

int ANL_data_addr_A ( ) {

	uint8_t addr = fetch ( );
	int8_t data = *( (char*)&CPU_8051 + addr );
	data &= CPU_8051.SFR[ACC];
	*( (char*)&CPU_8051 + addr ) = data;

if ( PPRINT ) {		
printf ("\tANL @%X, A\n", addr);
}

	return 1;

} 

int ANL_data_addr_data ( ) {

	uint8_t addr = fetch ( );
	int8_t data = *( (char*)&CPU_8051 + addr );
	int8_t operand2 = fetch ( );
	data &= operand2;
	*( (char*)&CPU_8051 + addr ) = data;

if ( PPRINT ) {		
printf ("\tANL @%X, #%X\n", addr, operand2);
}

	return 1;

} 

/** 0x54
 * ANL A, # Data
 */
int ANL_A_data ( ) { 

	int8_t data = fetch ( );
	CPU_8051.SFR[ACC] &= data;

if ( PPRINT ) {		
printf ("\tANL A, #%X\n", data);
}

	return 1;

}  

int ANL_A_data_addr ( ) {

	uint8_t addr = fetch ( );
	int8_t data = *( (char*)&CPU_8051 + addr );
	CPU_8051.SFR[ACC] &= data;

if ( PPRINT ) {		
printf ("\tANL A, @%X\n", addr);
}

	return 1;

}

int ANL_A_at_R0 ( ) {

	uint8_t addr = CPU_8051.REGISTERS[BANK ( )].R0;
	int8_t data = *( (char*)&CPU_8051 + addr );
	CPU_8051.SFR[ACC] &= data;

if ( PPRINT ) {		
printf ("\tANL A, @R0 | R0 : %X\n", addr);
}

	return 1;

}

// 0x57
int ANL_A_at_R1 ( ) {

	uint8_t addr = CPU_8051.REGISTERS[BANK ( )].R1;
	int8_t data = *( (char*)&CPU_8051 + addr );
	CPU_8051.SFR[ACC] &= data;
	return 1;

}


int ANL_R0 ( ) { 

	CPU_8051.SFR[ACC] &= CPU_8051.REGISTERS[BANK ( )].R0;

if ( PPRINT ) {		
printf ("\tANL A, R0 | R0 : %X\n", CPU_8051.REGISTERS[BANK ( )].R0);
}

	return 1;

}  

int ANL_R1 ( ) { 

	CPU_8051.SFR[ACC] &= CPU_8051.REGISTERS[BANK ( )].R1;

if ( PPRINT ) {		
printf ("\tANL A, R1 | R1 : %X\n", CPU_8051.REGISTERS[BANK ( )].R1);
}

	return 1;

}  

int ANL_R2 ( ) { 

	CPU_8051.SFR[ACC] &= CPU_8051.REGISTERS[BANK ( )].R2;

if ( PPRINT ) {		
printf ("\tANL A, R2 | R2 : %X\n", CPU_8051.REGISTERS[BANK ( )].R2);
}

	return 1;

}   

int ANL_R3 ( ) { 

	CPU_8051.SFR[ACC] &= CPU_8051.REGISTERS[BANK ( )].R3;

if ( PPRINT ) {		
printf ("\tANL A, R3 | R3 : %X\n", CPU_8051.REGISTERS[BANK ( )].R3);
}

	return 1;

}  

int ANL_R4 ( ) { 

	CPU_8051.SFR[ACC] &= CPU_8051.REGISTERS[BANK ( )].R4;

if ( PPRINT ) {		
printf ("\tANL A, R4 | R4 : %X\n", CPU_8051.REGISTERS[BANK ( )].R4);
}

	return 1;

}  

int ANL_R5 ( ) { 

	CPU_8051.SFR[ACC] &= CPU_8051.REGISTERS[BANK ( )].R5;

if ( PPRINT ) {		
printf ("\tANL A, R5 | R5 : %X\n", CPU_8051.REGISTERS[BANK ( )].R5);
}

	return 1;

}  

int ANL_R6 ( ) { 

	CPU_8051.SFR[ACC] &= CPU_8051.REGISTERS[BANK ( )].R6;

if ( PPRINT ) {		
printf ("\tANL A, R6 | R6 : %X\n", CPU_8051.REGISTERS[BANK ( )].R6);
}

	return 1;

}  

int ANL_R7 ( ) { 

	CPU_8051.SFR[ACC] &= CPU_8051.REGISTERS[BANK ( )].R7;

if ( PPRINT ) {		
printf ("\tANL A, R7 | R7 : %X\n", CPU_8051.REGISTERS[BANK ( )].R7);
}

	return 1;

}  
/** 0x60
 * jump is accumulator is zero
 */
int JZ ( ) {

	int8_t addr = fetch ( );
	if (!CPU_8051.SFR[ACC]) CPU_8051.PC += addr;

if ( PPRINT ) {		
printf ("\tJZ %X\n", addr);
}

	return 1;

}

//0x61
int AJMP_0x61 ( ) { 
	uint16_t low_add_byte = fetch ( );
	CPU_8051.PC = ( ( CPU_8051.PC & 0xF800) | (0x61 & 0x70) ) | low_add_byte;

if ( PPRINT ) {		
printf ("\tAJMP_0x61  %X\n", low_add_byte);
}

	return 1;
}


int XRL_data_addr_A ( ) {

	uint8_t addr = fetch ( );
	int8_t data = *( (char*)&CPU_8051 + addr );
	data &= CPU_8051.SFR[ACC];
	*( (char*)&CPU_8051 + addr) = data;

if ( PPRINT ) {		
printf ("\tXRL @%X, A\n", addr);
}

	return 1;

}

int XRL_data_addr_data ( ) {

	uint8_t addr = fetch ( );
	int8_t data = *( (char*)&CPU_8051 + addr );
	int8_t op2 = fetch ( );
	data &= op2;
	*( (char*)&CPU_8051 + addr ) = data;

if ( PPRINT ) {		
printf ("\tXRL @%X, #%X\n", addr, op2);
}

	return 1;

} 

/** 
 * XRL A, #data
 * Xor operation
 */
int XRL_A_data ( ) {
	
	int8_t data = fetch ( );
	CPU_8051.SFR[ACC] ^= data;

if ( PPRINT ) {		
printf ("\tXRL A, #%X\n", data);
}

	return 1;

} 

int XRL_A_dataaddr ( ) {

	uint8_t addr = fetch ( );
	int8_t data = *( (char*)&CPU_8051 + addr );
	CPU_8051.SFR[ACC] &= data;

if ( PPRINT ) {		
printf ("\tXRL A, @%X | @%X : %X\n", addr, addr, data);
}

	return 1;

}

int XRL_A_at_R0 ( ) {

	uint8_t addr = CPU_8051.REGISTERS[BANK ( )].R0;
	int8_t data = *( (char*)&CPU_8051 + addr );
	CPU_8051.SFR[ACC] &= data;

if ( PPRINT ) {		
printf ("\tXRL A, @R0 | R0 : %X\n", addr);
}

	return 1;

}

// 0x67
int XRL_A_at_R1 ( ) {

	uint8_t addr = CPU_8051.REGISTERS[BANK ( )].R1;
	int8_t data = *( (char*)&CPU_8051 + addr );
	CPU_8051.SFR[ACC] &= data;

if ( PPRINT ) {		
printf ("\tXRL A, @R1 | R1 : %X\n", addr);
}

	return 1;

}


int XRL_R0 ( ) { 

	CPU_8051.SFR[ACC] ^= CPU_8051.REGISTERS[BANK ( )].R0;

if ( PPRINT ) {		
printf ("\tXRL A, R0\n");
}

	return 1;

}   

int XRL_R1 ( ) { 

	CPU_8051.SFR[ACC] ^= CPU_8051.REGISTERS[BANK ( )].R1;

if ( PPRINT ) {		
printf ("\tXRL A, R1\n");
}

	return 1;

}   

int XRL_R2 ( ) { 

	CPU_8051.SFR[ACC] ^= CPU_8051.REGISTERS[BANK ( )].R2;

if ( PPRINT ) {		
printf ("\tXRL A, R2\n");
}

	return 1;

}   

int XRL_R3 ( ) { 

	CPU_8051.SFR[ACC] ^= CPU_8051.REGISTERS[BANK ( )].R3;

if ( PPRINT ) {		
printf ("\tXRL A, R3\n");
}

	return 1;

}   

int XRL_R4 ( ) { 

	CPU_8051.SFR[ACC] ^= CPU_8051.REGISTERS[BANK ( )].R4;

if ( PPRINT ) {		
printf ("\tXRL A, R4\n");
}

	return 1;

}   

int XRL_R5 ( ) { 

	CPU_8051.SFR[ACC] ^= CPU_8051.REGISTERS[BANK ( )].R5;

if ( PPRINT ) {		
printf ("\tXRL A, R5\n");
}

	return 1;

}   

int XRL_R6 ( ) { 

	CPU_8051.SFR[ACC] ^= CPU_8051.REGISTERS[BANK ( )].R6;

if ( PPRINT ) {		
printf ("\tXRL A, R6\n");
}

	return 1;

}   

int XRL_R7 ( ) { 

	CPU_8051.SFR[ACC] ^= CPU_8051.REGISTERS[BANK ( )].R7;

if ( PPRINT ) {		
printf ("\tXRL A, R7\n");
}

	return 1;

}   

/** 0x70
 * jump if accumulator is not zero
 */

int JNZ ( ) {

	int8_t addr = fetch ( );
	if (ACC) {
		CPU_8051.PC += addr;
	}

if ( PPRINT ) {		
printf ("\tJNZ %X\n", addr);
}

	return 1;

}

//0x71
int ACALL_0x71 ( ) {

	uint8_t lower_addr_byte = fetch ( );
	uint16_t push_addr = CPU_8051.PC;
	
	PUSH (push_addr & 0x00FF); // pushing lower byte
	PUSH ( (push_addr & 0xFF00) >> 8); //have to push it lower by 8 otherwise it will give error.

	// change PC to jmp to subroutine
	CPU_8051.PC = ( (CPU_8051.PC & 0xF800) | (0x71 & 0x70) ) | lower_addr_byte;

if ( PPRINT ) {		
printf ("\tACALL_0x71 lower byte addr %X\n", lower_addr_byte);
}

	return 1; 
	
}

// 0x72
int ORL_C_0x72 ( ) {

	uint8_t bit_addr = fetch ( );
	if (resolve_bit_addr (bit_addr)) {
		CPU_8051.SFR[PSW] | CY;
	}

if ( PPRINT ) {		
printf ("\tORL C, %X\n", bit_addr);
}

	return 1;

}

//0x73
int JMP_at_A_DPTR ( ) {

	uint16_t dptr_data = ( (CPU_8051.SFR[DPH] << 8) | CPU_8051.SFR[DPL] );
	dptr_data += CPU_8051.SFR[ACC];
	CPU_8051.PC = dptr_data;

if ( PPRINT ) {		
printf ("\tJMP @A+DPTR | DPTR : %X\n", dptr_data);
}

	return 1;
}

/** 0x74
 * MOV A, #data;
 * 2 byte instruction
 */
int MOV_A_data ( ) {
	
	CPU_8051.SFR[ACC] = fetch ( );

if ( PPRINT ) {		
printf ("\tMOV A, #%X\n", CPU_8051.SFR[ACC]);
}

	return 1;
}

int MOV_data_addr_data ( ) {

	uint8_t addr = fetch ( );
	int8_t data = fetch ( );
	*( (char*)&CPU_8051 + addr ) = data;

if ( PPRINT ) {		
printf ("\tMOV @%X, #%X\n", addr, data);
}

	return 1;

}

int MOV_at_R0 ( ) {

	int8_t data = fetch ( );
	uint8_t addr = CPU_8051.REGISTERS[BANK ( )].R0;
	*( (char*)&CPU_8051 + addr ) = data;

if ( PPRINT ) {		
printf ("\tMOV @R0, #%X | R0 : %X\n", data, addr);
}

	return 1;

}

//0x77
int MOV_at_R1 ( ) {

	int8_t data = fetch ( );
	uint8_t addr = CPU_8051.REGISTERS[BANK ( )].R1;
	*( (char*)&CPU_8051 + addr ) = data;

if ( PPRINT ) {		
printf ("\tMOV @R1, #%X | R1 : %X\n", data, addr);
}

	return 1;
	
}

int MOV_R0 ( ) {
	
	CPU_8051.REGISTERS[BANK ( )].R0 = fetch ( );

if ( PPRINT ) {		
printf ("\tMOV R0, #%X \n", CPU_8051.REGISTERS[BANK ( )].R0);
}

	return 1;

}

int MOV_R1 ( ) {

	CPU_8051.REGISTERS[BANK ( )].R1 = fetch ( );	

if ( PPRINT ) {		
printf ("\tMOV R1, #%X \n", CPU_8051.REGISTERS[BANK ( )].R1);
}

	return 1;

}

int MOV_R2 ( ) {
	
	CPU_8051.REGISTERS[BANK ( )].R2 = fetch ( );	

if ( PPRINT ) {		
printf ("\tMOV R2, #%X \n", CPU_8051.REGISTERS[BANK ( )].R2);
}

	return 1;

}


int MOV_R3 ( ) {
	
	CPU_8051.REGISTERS[BANK ( )].R3 = fetch ( );	

if ( PPRINT ) {		
printf ("\tMOV R3, #%X \n", CPU_8051.REGISTERS[BANK ( )].R3);
}

	return 1;

}


int MOV_R4 ( ) {
	
	CPU_8051.REGISTERS[BANK ( )].R4 = fetch ( );	

if ( PPRINT ) {		
printf ("\tMOV R4, #%X \n", CPU_8051.REGISTERS[BANK ( )].R4);
}

	return 1;

}


int MOV_R5 ( ) {

	CPU_8051.REGISTERS[BANK ( )].R5 = fetch ( );		

if ( PPRINT ) {		
printf ("\tMOV R5, #%X \n", CPU_8051.REGISTERS[BANK ( )].R5);
}

	return 1;

}


int MOV_R6 ( ) {
	
	CPU_8051.REGISTERS[BANK ( )].R6 = fetch ( );	

if ( PPRINT ) {		
printf ("\tMOV R6, #%X \n", CPU_8051.REGISTERS[BANK ( )].R6);
}

	return 1;

}


int MOV_R7 ( ) {
	
	CPU_8051.REGISTERS[BANK ( )].R7 = fetch ( );	

if ( PPRINT ) {		
printf ("\tMOV R7, #%X \n", CPU_8051.REGISTERS[BANK ( )].R7);
}

	return 1;

}

//0x80
int SJMP ( ) {
	int8_t tmp = fetch ( );
	if (tmp & 0x80 ) // signed bit 1 = negative number
	{
		CPU_8051.PC -= tmp;
	}
	else {
		CPU_8051.PC += tmp;
	}

if ( PPRINT ) {		
printf ("\tSJMP PC + %X \n", tmp);
}

	return 1;
}

//0x81
int AJMP_0x81 ( ) { 
	uint16_t low_add_byte = fetch ( );
	CPU_8051.PC = ( ( CPU_8051.PC & 0xF800) | (0x81 & 0x70) ) | low_add_byte;

if ( PPRINT ) {		
printf ("\tAJMP_0x81  %X\n", low_add_byte);
}

	return 1;
}		

/** 
 * ANL C, Bit addr
 */
int ANL_C_0x82 ( ) {

	uint8_t addr = fetch ( );
	if (!resolve_bit_addr (addr)) {
		CPU_8051.SFR[PSW] &= ~(CY);
	}

if ( PPRINT ) {		
printf ("\tANL C, %X\n", addr);
}

	return 1;

}

/**
 * MOVC A, @A+PC
 * mov code byte
 */
int MOVC ( ) {

	uint8_t addr1 = CPU_8051.SFR[ACC];
	uint16_t pc = CPU_8051.PC;
	pc += addr1;
	CPU_8051.SFR[ACC] = CPU_8051.Code_Memory[pc];

if ( PPRINT ) {		
printf ("\tMOVC A, A+PC | A : %X  | PC : %X\n", CPU_8051.SFR[ACC], CPU_8051.PC);
}

	return 1;

}

/**
 * DIV AB
 * quotient : A
 * remainder : B
 * 
 * OV and CY flags are cleared
 * if B == 0, OV = 1, CY = 0
 */
int DIV ( ) {
	
	// check if B == 0
	if (CPU_8051.SFR[B] == 0) {
		
		CPU_8051.SFR[PSW] |= (OV);
		CPU_8051.SFR[PSW] &= ~(CY);
		return 1;
	}

	uint8_t quotient, remainder;
	uint8_t old_ACC,old_B;
	old_ACC = CPU_8051.SFR[ACC];
	old_B = CPU_8051.SFR[B];
	quotient = CPU_8051.SFR[ACC] / CPU_8051.SFR[B];
	remainder = CPU_8051.SFR[ACC] % CPU_8051.SFR[B];
	CPU_8051.SFR[ACC] = quotient;
	CPU_8051.SFR[B] = remainder;

if ( PPRINT ) {		
printf ("\tDIV AB | A : %X | B : %X\n", old_ACC, old_B);
}

	return 1;
}


int MOV_data_addr_data_addr ( ) {

	uint8_t dest_addr = fetch ( );
	uint8_t sour_addr = fetch ( );
	int8_t data = *( (char*)&CPU_8051 + sour_addr );
	*( (char*)&CPU_8051 + dest_addr ) = data;

if ( PPRINT ) {		
printf ("\tMOV @%X, @%X\n", dest_addr, sour_addr);
}

	return 1;

}

int MOV_data_addr_atR0 ( ) {

	uint8_t dest_addr = fetch ( );
	uint8_t sour_addr = CPU_8051.REGISTERS[BANK ( )].R0;
	int8_t data = *( (char*)&CPU_8051 + sour_addr );
	*( (char*)&CPU_8051 + dest_addr ) = data;

if ( PPRINT ) {		
printf ("\tMOV @%X, @R0 | R0 : %X\n", dest_addr, sour_addr);
}

	return 1;

}

// 0x87
int MOV_data_addr_atR1 ( ) {

	uint8_t dest_addr = fetch ( );
	uint8_t sour_addr = CPU_8051.REGISTERS[BANK ( )].R1;
	int8_t data = *( (char*)&CPU_8051 + sour_addr );
	*( (char*)&CPU_8051 + dest_addr ) = data;

if ( PPRINT ) {		
printf ("\tMOV @%X, @R1 | R1 : %X\n", dest_addr, sour_addr);
}

	return 1;

}

int MOV_data_addr_R0 ( ) {

	uint8_t dest_addr = fetch ( );
	int8_t data = CPU_8051.REGISTERS[BANK ( )].R0;
	*( (char*)&CPU_8051 + dest_addr ) = data;

if ( PPRINT ) {		
printf ("\tMOV @%X, R0 | R0 : %X\n", dest_addr, data);
}

	return 1;

}

int MOV_data_addr_R1 ( ) {

	uint8_t dest_addr = fetch ( );
	int8_t data = CPU_8051.REGISTERS[BANK ( )].R1;
	*( (char*)&CPU_8051 + dest_addr ) = data;

if ( PPRINT ) {		
printf ("\tMOV @%X, R1 | R1 : %X\n", dest_addr, data);
}

	return 1;

}

int MOV_data_addr_R2 ( ) {

	uint8_t dest_addr = fetch ( );
	int8_t data = CPU_8051.REGISTERS[BANK ( )].R2;
	*( (char*)&CPU_8051 + dest_addr ) = data;

if ( PPRINT ) {		
printf ("\tMOV @%X, R2 | R2 : %X\n", dest_addr, data);
}

	return 1;

}

int MOV_data_addr_R3 ( ) {

	uint8_t dest_addr = fetch ( );
	int8_t data = CPU_8051.REGISTERS[BANK ( )].R3;
	*( (char*)&CPU_8051 + dest_addr ) = data;

if ( PPRINT ) {		
printf ("\tMOV @%X, R3 | R3 : %X\n", dest_addr, data);
}

	return 1;

}

int MOV_data_addr_R4 ( ) {

	uint8_t dest_addr = fetch ( );
	int8_t data = CPU_8051.REGISTERS[BANK ( )].R4;
	*( (char*)&CPU_8051 + dest_addr ) = data;

if ( PPRINT ) {		
printf ("\tMOV @%X, R4 | R4 : %X\n", dest_addr, data);
}

	return 1;

}

int MOV_data_addr_R5 ( ) {

	uint8_t dest_addr = fetch ( );
	int8_t data = CPU_8051.REGISTERS[BANK ( )].R5;
	*( (char*)&CPU_8051 + dest_addr ) = data;

if ( PPRINT ) {		
printf ("\tMOV @%X, R5 | R5 : %X\n", dest_addr, data);
}

	return 1;

}

int MOV_data_addr_R6 ( ) {

	uint8_t dest_addr = fetch ( );
	int8_t data = CPU_8051.REGISTERS[BANK ( )].R6;
	*( (char*)&CPU_8051 + dest_addr ) = data;

if ( PPRINT ) {		
printf ("\tMOV @%X, R6 | R6 : %X\n", dest_addr, data);
}

	return 1;

}

//0x8F
int MOV_data_addr_R7 ( ) {

	uint8_t dest_addr = fetch ( );
	int8_t data = CPU_8051.REGISTERS[BANK ( )].R0;
	*( (char*)&CPU_8051 + dest_addr ) = data;

if ( PPRINT ) {		
printf ("\tMOV @%X, R7 | R7 : %X\n", dest_addr, data);
}

	return 1;

}

// 0x90
int MOV_DPTR_data ( ) {

	CPU_8051.SFR[DPH] = fetch ( );
	CPU_8051.SFR[DPL] = fetch ( );

if ( PPRINT ) {		
printf ("\tMOV DPTR, #%X\n", ((CPU_8051.SFR[DPH] << 8) | CPU_8051.SFR[DPL]) );
}

	return 1;

}

// 0x91
int ACALL_0x91 ( ) {

	uint8_t lower_addr_byte = fetch ( );
	uint16_t push_addr = CPU_8051.PC;
	
	PUSH (push_addr & 0x00FF); // pushing lower byte
	PUSH ( (push_addr & 0xFF00) >> 8); //have to push it lower by 8 otherwise it will give error.

	// change PC to jmp to subroutine
	CPU_8051.PC = ( (CPU_8051.PC & 0xF800) | (0x91 & 0x70) ) | lower_addr_byte;

if ( PPRINT ) {		
printf ("\tACALL_0x91 lower byte addr %X\n", lower_addr_byte);
}

	return 1; 
	
}

/** 
 * MOV bit_addr, C
 */
int MOV_bit_C ( ) {  

	uint8_t addr = fetch ( );
	uint8_t byte_addr = addr / 8;

	if ( CPU_8051.SFR[PSW] & CY ) {
			
		CPU_8051.Bit_Addressable[byte_addr] |= (1 << ((addr % 8) + 1) );
	
	}
	else {
		
		CPU_8051.Bit_Addressable[byte_addr] &= ~(1 << ((addr % 8) + 1) );

	}

if ( PPRINT ) {		
printf ("\tMOV @%X, C", addr);
}

	return 1;
} 

int MOVC_A_dptr ( ) {

	uint16_t addr = ( (CPU_8051.SFR[DPH] << 8) | CPU_8051.SFR[DPL] );
	addr += CPU_8051.SFR[ACC];
	CPU_8051.SFR[ACC] = CPU_8051.Code_Memory[addr];

if ( PPRINT ) {		
printf ("\tMOVC A, @A+DPTR | DPTR : %X\n", addr);
}

	return 1;

}
// SUBB A, #data
int SUBB_A_data ( ) {

	int8_t data = fetch ( );
	CPU_8051.SFR[ACC] = subb (CPU_8051.SFR[ACC], data);

if ( PPRINT ) {		
printf ("\tSUBB A, #%X\n", data);
}

	return 1;

} 

// SUBB A, @data_addr
int SUBB_A_data_addr ( ) {  
	
	uint8_t addr = fetch ( );
	int8_t data = *( (char*)&CPU_8051 + addr );
	CPU_8051.SFR[ACC] = subb (CPU_8051.SFR[ACC], data);

if ( PPRINT ) {		
printf ("\tSUBB A, @%X \n", addr);
}

	return 1;

} 

// SUBB A, @R0
int SUBB_A_atR0 ( ) {  
	
	uint8_t addr = CPU_8051.REGISTERS[BANK ( )].R0;
	int8_t data = *( (char*)&CPU_8051 + addr );
	CPU_8051.SFR[ACC] = subb (CPU_8051.SFR[ACC], data);

if ( PPRINT ) {		
printf ("\tSUBB A, @R0 | R0 : %X\n", addr);
}

	return 1;
 
} 

//0x97
// SUBB A, @R1
int SUBB_A_atR1 ( ) {
 
	uint8_t addr = CPU_8051.REGISTERS[BANK ( )].R0;
	int8_t data = *( (char*)&CPU_8051 + addr );
	CPU_8051.SFR[ACC] = subb (CPU_8051.SFR[ACC], data);

if ( PPRINT ) {		
printf ("\tSUBB A, @R1 | R1 : %X\n", addr);
}

	return 1;
  
}

// SUBB A, R0
int SUBB_R0 ( ) {  
	
	int8_t data = CPU_8051.REGISTERS[BANK ( )].R0;
	CPU_8051.SFR[ACC] = subb (CPU_8051.SFR[ACC], data);

if ( PPRINT ) {		
printf ("\tSUBB A, R0 | R0 : %X\n", data);
}

	return 1;
} 

// SUBB A, R1
int SUBB_R1 ( ) {  
  	
	int8_t data = CPU_8051.REGISTERS[BANK ( )].R1;
	CPU_8051.SFR[ACC] = subb (CPU_8051.SFR[ACC], data);

if ( PPRINT ) {		
printf ("\tSUBB A, R1 | R1 : %X\n", data);
}

	return 1;

}

// SUBB A, R2
int SUBB_R2 ( ) {  
	
	int8_t data = CPU_8051.REGISTERS[BANK ( )].R2;
	CPU_8051.SFR[ACC] = subb (CPU_8051.SFR[ACC], data);

if ( PPRINT ) {		
printf ("\tSUBB A, R2 | R2 : %X\n", data);
}

	return 1;

} 

// SUBB A, R3
int SUBB_R3 ( ) {  
	
	int8_t data = CPU_8051.REGISTERS[BANK ( )].R3;
	CPU_8051.SFR[ACC] = subb (CPU_8051.SFR[ACC], data);

if ( PPRINT ) {		
printf ("\tSUBB A, R3 | R3 : %X\n", data);
}

	return 1;

} 

// SUBB A, R4
int SUBB_R4 ( ) {  
	
	int8_t data = CPU_8051.REGISTERS[BANK ( )].R4;
	CPU_8051.SFR[ACC] = subb (CPU_8051.SFR[ACC], data);

if ( PPRINT ) {		
printf ("\tSUBB A, R4 | R4 : %X\n", data);
}

	return 1;
}

// SUBB A, R5
int SUBB_R5 ( ) {  
	
	int8_t data = CPU_8051.REGISTERS[BANK ( )].R5;
	CPU_8051.SFR[ACC] = subb (CPU_8051.SFR[ACC], data);

if ( PPRINT ) {		
printf ("\tSUBB A, R5 | R5 : %X\n", data);
}

	return 1;

}

// SUBB A, R6
int SUBB_R6 ( ) {  
	
	int8_t data = CPU_8051.REGISTERS[BANK ( )].R6;
	CPU_8051.SFR[ACC] = subb (CPU_8051.SFR[ACC], data);

if ( PPRINT ) {		
printf ("\tSUBB A, R6 | R6 : %X\n", data);
}

	return 1;

}     

// 0x9F
// SUBB A, R7
int SUBB_R7 ( ) {  
	
	int8_t data = CPU_8051.REGISTERS[BANK ( )].R7;
	CPU_8051.SFR[ACC] = subb (CPU_8051.SFR[ACC], data);

if ( PPRINT ) {		
printf ("\tSUBB A, R7 | R7 : %X\n", data);
}

	return 1;

} 

// 0xA0
// ORL C, bit_addr
int ORL_C_0xA0 ( ) {

	uint8_t addr = fetch ( );
	if (resolve_bit_addr (addr)) {

		CPU_8051.SFR[PSW] |= CY;
	}
	else {

		CPU_8051.SFR[PSW] &= (~CY);
	}

if ( PPRINT ) {		
printf ("\tORL C, %X\n", addr);
}

	return 1;
}

//0xA1
int AJMP_0xA1 ( ) { 
	uint16_t low_add_byte = fetch ( );
	CPU_8051.PC = ( ( CPU_8051.PC & 0xF800) | (0xA1 & 0x70) ) | low_add_byte;

if ( PPRINT ) {		
printf ("\tAJMP_0xA1  %X\n", low_add_byte);
}

	return 1;
}

// MOV C, bit_addr
int MOV_C ( ) {  


	uint8_t addr = fetch ( );
	if (resolve_bit_addr (addr)) {

		CPU_8051.SFR[PSW] |= CY;
	}
	else {

		CPU_8051.SFR[PSW] &= (~CY);
	}

if ( PPRINT ) {		
printf ("\tMOV C, %X\n", addr);
}

	return 1;
} 

// INC DPTR
int INC_dptr ( ) {

	uint16_t dptr = ( (CPU_8051.SFR[DPH] << 8) | CPU_8051.SFR[DPL] );
	dptr++;
	CPU_8051.SFR[DPH] = dptr >> 8;
	CPU_8051.SFR[DPL] = dptr & 0x00FF;

if ( PPRINT ) {		
printf ("\tINC %X\n", dptr-1);
}

	return 1;

} 

// MUL AB
/** 
 * multiplies unsigned values in ACC and B,
 * higher byte of 16 bit result -> B
 * lower byte of 16 bit result -> ACC
 * if result > 255, ov = 1
 * else ov = 0
 * carry always cleared 
 */
int MUL ( ) {  
	
	uint16_t result = CPU_8051.SFR[ACC] * CPU_8051.SFR[B];
	if (result > 255) CPU_8051.SFR[PSW] |= OV;
	else  CPU_8051.SFR[PSW] &= ~OV;

	CPU_8051.SFR[ACC] = result & 0x00FF;
	CPU_8051.SFR[B] = result >> 8;

	CPU_8051.SFR[PSW] &= ~CY;

if ( PPRINT ) {		
printf ("\tMUL AB \n");
}

	return 1;

} 
//reserved

int MOV_atR0_data_addr ( ) {

	uint8_t dest_addr = CPU_8051.REGISTERS[BANK ( )].R0;
	uint8_t sour_addr = fetch ( );

	*( (char*)&CPU_8051 + dest_addr) = *( (char*)&CPU_8051 + sour_addr );

if ( PPRINT ) {		
printf ("\tMOV @R0, %X | R0 : %X\n", sour_addr, dest_addr);
}

	return 1;
}

// 0xA7
int MOV_atR1_data_addr ( ) {

	uint8_t dest_addr = CPU_8051.REGISTERS[BANK ( )].R1;
	uint8_t sour_addr = fetch ( );

	*( (char*)&CPU_8051 + dest_addr) = *( (char*)&CPU_8051 + sour_addr );

if ( PPRINT ) {		
printf ("\tMOV @R1, %X | R1 : %X\n", sour_addr, dest_addr);
}

	return 1;

}

int MOV_R0_data_addr ( ) {
	
	uint8_t sour_addr = fetch ( );
	CPU_8051.REGISTERS[BANK ( )].R0 = *( (char*)&CPU_8051 + sour_addr );

if ( PPRINT ) {		
printf ("\tMOV R0, @%X \n", sour_addr);
}

	return 1;

}

int MOV_R1_data_addr ( ) {
	
	uint8_t sour_addr = fetch ( );
	CPU_8051.REGISTERS[BANK ( )].R1 = *( (char*)&CPU_8051 + sour_addr );

if ( PPRINT ) {		
printf ("\tMOV R1, @%X \n", sour_addr);
}

	return 1;
	
}

int MOV_R2_data_addr ( ) {
	
	uint8_t sour_addr = fetch ( );
	CPU_8051.REGISTERS[BANK ( )].R2 = *( (char*)&CPU_8051 + sour_addr );

if ( PPRINT ) {		
printf ("\tMOV R2, @%X \n", sour_addr);
}

	return 1;
	
}

int MOV_R3_data_addr ( ) {
	
	uint8_t sour_addr = fetch ( );
	CPU_8051.REGISTERS[BANK ( )].R3 = *( (char*)&CPU_8051 + sour_addr );

if ( PPRINT ) {		
printf ("\tMOV R3, @%X \n", sour_addr);
}

	return 1;
	
}

int MOV_R4_data_addr ( ) {
	
	uint8_t sour_addr = fetch ( );
	CPU_8051.REGISTERS[BANK ( )].R4 = *( (char*)&CPU_8051 + sour_addr );

if ( PPRINT ) {		
printf ("\tMOV R4, @%X \n", sour_addr);
}

	return 1;
	
}

int MOV_R5_data_addr ( ) {
	
	uint8_t sour_addr = fetch ( );
	CPU_8051.REGISTERS[BANK ( )].R5 = *( (char*)&CPU_8051 + sour_addr );

if ( PPRINT ) {		
printf ("\tMOV R5, @%X \n", sour_addr);
}

	return 1;
	
}

int MOV_R6_data_addr ( ) {
	
	uint8_t sour_addr = fetch ( );
	CPU_8051.REGISTERS[BANK ( )].R6 = *( (char*)&CPU_8051 + sour_addr );

if ( PPRINT ) {		
printf ("\tMOV R6, @%X \n", sour_addr);
}

	return 1;
	
}

// 0xAF
int MOV_R7_data_addr ( ) {
	
	uint8_t sour_addr = fetch ( );
	CPU_8051.REGISTERS[BANK ( )].R7 = *( (char*)&CPU_8051 + sour_addr );

if ( PPRINT ) {		
printf ("\tMOV R7, @%X \n", sour_addr);
}

	return 1;
	
}

// 0xB0
int ANL_C_0xB0 ( ) {

	uint8_t addr = fetch ( );
	if ( resolve_bit_addr (addr)) {
		
		CPU_8051.SFR[PSW] |= CY;
	}
	else {
		CPU_8051.SFR[PSW] &= ~CY;
	}

if ( PPRINT ) {		
printf ("\tANL C, %X \n", addr);
}

	return 1;
}

//0xB1
int ACALL_0xB1 ( ) {

	uint8_t lower_addr_byte = fetch ( );
	uint16_t push_addr = CPU_8051.PC;
	
	PUSH (push_addr & 0x00FF); // pushing lower byte
	PUSH ( (push_addr & 0xFF00) >> 8); //have to push it lower by 8 otherwise it will give error.

	// change PC to jmp to subroutine
	CPU_8051.PC = ( (CPU_8051.PC & 0xF800) | (0xB1 & 0x70) ) | lower_addr_byte;

if ( PPRINT ) {		
printf ("\tACALL_0xB1 lower byte addr %X\n", lower_addr_byte);
}

	return 1; 
	
}

int CPL ( ) {

	CPU_8051.SFR[ACC] ^= 0xFF;

if ( PPRINT ) {		
printf ("\tCPL A\n");
}

	return 1;

}

int CPL_C ( ) {

	CPU_8051.SFR[ACC] ^= CY;

if ( PPRINT ) {		
printf ("\tCPL C\n");
}

	return 1;

}

/** CJNE : Compare and Jump if Not Equal
 * branch destination = PC + signed value of last byte after incrementing
 * pc to next instruction
 * if destination < src, carry is set otherwise not set. not other flag are affected
 */

// CJNE A, #data, code_addr
int CJNE_A_data_codeaddr ( ) { 

	int8_t data = fetch ( );
	int8_t displacement =  fetch ( );
	
	if (CPU_8051.SFR[ACC] == data ) {
		// jump
		CPU_8051.PC += displacement;
		if (data < CPU_8051.SFR[ACC]) CPU_8051.SFR[PSW] |= CY;
	}

if ( PPRINT ) {		
printf ("\tCJNE A, #%X, %X \n", data, displacement);
}

	return 1;

} 

//	CJNE A, data_addr, code_addr 
int CJNE_A_data_addr_codeaddr ( ) { 

	uint8_t addr = fetch ( );
	int8_t data = *( (char*)&CPU_8051 + addr);
	int8_t displacement =  fetch ( );
	
	if (CPU_8051.SFR[ACC] == data ) {
		// jump
		CPU_8051.PC += displacement;
		if (data < CPU_8051.SFR[ACC]) CPU_8051.SFR[PSW] |= CY;
	}

if ( PPRINT ) {		
printf ("\tCJNE A, @%X, %X \n", addr, displacement);
}

	return 1;

} 

// CJNE @R0, data, code addr
int CJNE_atR0_data_codeaddr ( ) { 

	int8_t addr = CPU_8051.REGISTERS[BANK ( )].R0;
	int8_t data = *( (char*)&CPU_8051 + addr);
	int8_t imm_data = fetch ( );
	int8_t displacement =  fetch ( );
	
	if (imm_data != data ) {
		// jump
		CPU_8051.PC += displacement;
		if (data < CPU_8051.SFR[ACC]) CPU_8051.SFR[PSW] |= CY;
	}

if ( PPRINT ) {		
printf ("\tCJNE @R0, #%X, %X | R0 : %X\n", imm_data, displacement, addr);
}

	return 1;

} 

// CJNE @R1, data, code addr 
int CJNE_atR1_data_codeaddr ( ) { 

	int8_t addr = CPU_8051.REGISTERS[BANK ( )].R1;
	int8_t data = *( (char*)&CPU_8051 + addr);
	int8_t imm_data = fetch ( );
	int8_t displacement =  fetch ( );
	
	if (imm_data != data ) {
		// jump
		CPU_8051.PC += displacement;
		if (data < CPU_8051.SFR[ACC]) CPU_8051.SFR[PSW] |= CY;
	}

if ( PPRINT ) {		
printf ("\tCJNE @R1, #%X, %X | R1 : %X\n", imm_data, displacement, addr);
}

	return 1;

} 

// CJNE R0, data, codeaddr
int CJNE_R0 ( ) { 

	int8_t data = CPU_8051.REGISTERS[BANK ( )].R0;
	int8_t imm_data = fetch ( );
	int8_t displacement =  fetch ( );
	
	if (imm_data != data ) {
		// jump
		CPU_8051.PC += displacement;
		if (data < CPU_8051.SFR[ACC]) CPU_8051.SFR[PSW] |= CY;
	}

if ( PPRINT ) {		
printf ("\tCJNE R0, #%X, %X\n", imm_data,displacement);
}

	return 1;

} 

// CJNE R1, data,displacement
int CJNE_R1 ( ) { 

	int8_t data = CPU_8051.REGISTERS[BANK ( )].R1;
	int8_t imm_data = fetch ( );
	int8_t displacement =  fetch ( );
	
	if (imm_data != data ) {
		// jump
		CPU_8051.PC += displacement;
		if (data < CPU_8051.SFR[ACC]) CPU_8051.SFR[PSW] |= CY;
	}

if ( PPRINT ) {		
printf ("\tCJNE R1, #%X, %X\n", imm_data,displacement);
}

	return 1;

} 


// CJNE R2, data, displacement
int CJNE_R2 ( ) { 

	int8_t data = CPU_8051.REGISTERS[BANK ( )].R2;
	int8_t imm_data = fetch ( );
	int8_t displacement =  fetch ( );
	
	if (imm_data != data ) {
		// jump
		CPU_8051.PC += displacement;
		if (data < CPU_8051.SFR[ACC]) CPU_8051.SFR[PSW] |= CY;
	}

if ( PPRINT ) {		
printf ("\tCJNE R2, #%X, %X\n", imm_data,displacement);
}

	return 1;

} 

 
// CJNE R3, data, displacement
int CJNE_R3 ( ) { 

	int8_t data = CPU_8051.REGISTERS[BANK ( )].R3;
	int8_t imm_data = fetch ( );
	int8_t displacement =  fetch ( );
	
	if (imm_data != data ) {
		// jump
		CPU_8051.PC += displacement;
		if (data < CPU_8051.SFR[ACC]) CPU_8051.SFR[PSW] |= CY;
	}

if ( PPRINT ) {		
printf ("\tCJNE R3, #%X, %X\n", imm_data,displacement);
}

	return 1;

} 

 
// CJNE R4, data, displacement
int CJNE_R4 ( ) { 

	int8_t data = CPU_8051.REGISTERS[BANK ( )].R4;
	int8_t imm_data = fetch ( );
	int8_t displacement =  fetch ( );
	
	if (imm_data != data ) {
		// jump
		CPU_8051.PC += displacement;
		if (data < CPU_8051.SFR[ACC]) CPU_8051.SFR[PSW] |= CY;
	}

if ( PPRINT ) {		
printf ("\tCJNE R4, #%X, %X\n", imm_data,displacement);
}

	return 1;

} 

 
// CJNE R5, data, displacemnt
int CJNE_R5 ( ) { 

	int8_t data = CPU_8051.REGISTERS[BANK ( )].R5;
	int8_t imm_data = fetch ( );
	int8_t displacement =  fetch ( );
	
	if (imm_data != data ) {
		// jump
		CPU_8051.PC += displacement;
		if (data < CPU_8051.SFR[ACC]) CPU_8051.SFR[PSW] |= CY;
	}

if ( PPRINT ) {		
printf ("\tCJNE R5, #%X, %X\n", imm_data,displacement);
}

	return 1;

} 

 
// CJNE R6, data, displacement
int CJNE_R6 ( ) { 

	int8_t data = CPU_8051.REGISTERS[BANK ( )].R6;
	int8_t imm_data = fetch ( );
	int8_t displacement =  fetch ( );
	
	if (imm_data != data ) {
		// jump
		CPU_8051.PC += displacement;
		if (data < CPU_8051.SFR[ACC]) CPU_8051.SFR[PSW] |= CY;
	}

if ( PPRINT ) {		
printf ("\tCJNE R6, #%X, %X\n", imm_data,displacement);
}

	return 1;

} 

// 0xBF 
// CJNE R7, data, displacement
int CJNE_R7 ( ) { 

	int8_t data = CPU_8051.REGISTERS[BANK ( )].R7;
	int8_t imm_data = fetch ( );
	int8_t displacement =  fetch ( );
	
	if (imm_data != data ) {
		// jump
		CPU_8051.PC += displacement;
		if (data < CPU_8051.SFR[ACC]) CPU_8051.SFR[PSW] |= CY;
	}

if ( PPRINT ) {		
printf ("\tCJNE R7, #%X, %X\n", imm_data,displacement);
}

	return 1;

} 


// int PUSH (int8_t data) // declared above

//0xC1
int AJMP_0xC1 ( ) { 
	uint16_t low_add_byte = fetch ( );
	CPU_8051.PC = ( ( CPU_8051.PC & 0xF800) | (0xC1 & 0x70) ) | low_add_byte;

if ( PPRINT ) {		
printf ("\tAJMP_0xC1  %X\n", low_add_byte);
}

	return 1;
}

// clear particular bit, like P1.0
int CLR ( ) {  
	
	uint8_t bit_addr = fetch ( );
	CPU_8051.Bit_Addressable[bit_addr / 8] &= ~(1 << ((bit_addr % 8) + 1));

if ( PPRINT ) {		
printf ("\tCLR %X \n", bit_addr);
}

	return 1;
} 

int CLR_C ( ) {
	
	CPU_8051.SFR[PSW] &= ~(CY);

if ( PPRINT ) {		
printf ("\tCLR C\n");
}

	return 1;

}

/** 0xC4
 * SWap, will swap the nibbles of the accumulator
 */
int SWAP ( ) {
	
	int8_t tmp = CPU_8051.SFR[ACC] & 0xF0;
	CPU_8051.SFR[ACC] = (CPU_8051.SFR[ACC] << 4) | ((tmp >> 4) & 0x0F);

if ( PPRINT ) {		
printf ("\tSWAP A \n");
}

	return 1;
}

int XCH_A_dataaddr ( ) {
	
	uint8_t addr = fetch ( );
	int8_t tmp = CPU_8051.SFR[ACC];
	CPU_8051.SFR[ACC] = *( (char*)&CPU_8051 + addr );
	*( (char*)&CPU_8051 + addr ) = tmp;

if ( PPRINT ) {		
printf ("\tXCH A, @%X \n", addr);
}

	return 1;

}

int XCH_A_at_R0 ( ) {
	
	uint8_t addr = CPU_8051.REGISTERS[BANK ( )].R0;
	int8_t tmp = CPU_8051.SFR[ACC];
	CPU_8051.SFR[ACC] = *( (char*)&CPU_8051 + addr );
	*( (char*)&CPU_8051 + addr ) = tmp;

if ( PPRINT ) {		
printf ("\tXCH A, @R0 | R0 : %X \n", addr);
}

	return 1;
	
}

// 0xC7
int XCH_A_at_R1 ( ) {
	
	uint8_t addr = CPU_8051.REGISTERS[BANK ( )].R1;
	int8_t tmp = CPU_8051.SFR[ACC];
	CPU_8051.SFR[ACC] = *( (char*)&CPU_8051 + addr );
	*( (char*)&CPU_8051 + addr ) = tmp;

if ( PPRINT ) {		
printf ("\tXCH A, @R1 | R1 : %X \n", addr);
}

	return 1;
	
}

/** XCH : Xchange A contant with R0 content
 * 1 byte instruction
 */
int XCH_A_R0 ( ) {

	int8_t temp = CPU_8051.SFR[ACC];
	CPU_8051.SFR[ACC] = CPU_8051.REGISTERS[BANK ( )].R0;
	CPU_8051.REGISTERS[BANK ( )].R0 = temp;

if ( PPRINT ) {		
printf ("\tXCH A, R0\n");
}

	return 1;

} 

int XCH_A_R1 ( ) {

	int8_t temp = CPU_8051.SFR[ACC];
	CPU_8051.SFR[ACC] = CPU_8051.REGISTERS[BANK ( )].R1;
	CPU_8051.REGISTERS[BANK ( )].R1 = temp;

if ( PPRINT ) {		
printf ("\tXCH A, R1\n");
}

	return 1;
	
} 

int XCH_A_R2 ( ) {

	int8_t temp = CPU_8051.SFR[ACC];
	CPU_8051.SFR[ACC] = CPU_8051.REGISTERS[BANK ( )].R2;
	CPU_8051.REGISTERS[BANK ( )].R2 = temp;

if ( PPRINT ) {		
printf ("\tXCH A, R2\n");
}

	return 1;
	
} 

int XCH_A_R3 ( ) {

	int8_t temp = CPU_8051.SFR[ACC];
	CPU_8051.SFR[ACC] = CPU_8051.REGISTERS[BANK ( )].R3;
	CPU_8051.REGISTERS[BANK ( )].R3 = temp;

if ( PPRINT ) {		
printf ("\tXCH A, R3\n");
}

	return 1;
	
} 

int XCH_A_R4 ( ) {

	int8_t temp = CPU_8051.SFR[ACC];
	CPU_8051.SFR[ACC] = CPU_8051.REGISTERS[BANK ( )].R4;
	CPU_8051.REGISTERS[BANK ( )].R4 = temp;

if ( PPRINT ) {		
printf ("\tXCH A, R4\n");
}

	return 1;
	
} 

int XCH_A_R5 ( ) {

	int8_t temp = CPU_8051.SFR[ACC];
	CPU_8051.SFR[ACC] = CPU_8051.REGISTERS[BANK ( )].R5;
	CPU_8051.REGISTERS[BANK ( )].R5 = temp;

if ( PPRINT ) {		
printf ("\tXCH A, R5\n");
}

	return 1;
	
} 

int XCH_A_R6 ( ) {

	int8_t temp = CPU_8051.SFR[ACC];
	CPU_8051.SFR[ACC] = CPU_8051.REGISTERS[BANK ( )].R6;
	CPU_8051.REGISTERS[BANK ( )].R6 = temp;

if ( PPRINT ) {		
printf ("\tXCH A, R6\n");
}

	return 1;
	
} 


int XCH_A_R7 ( ) {

	int8_t temp = CPU_8051.SFR[ACC];
	CPU_8051.SFR[ACC] = CPU_8051.REGISTERS[BANK ( )].R7;
	CPU_8051.REGISTERS[BANK ( )].R7 = temp;

if ( PPRINT ) {		
printf ("\tXCH A, R7\n");
}

	return 1;
	
} 

// int POP ( )  declard above

//0xD1
int ACALL_0xD1 ( ) {

	uint8_t lower_addr_byte = fetch ( );
	uint16_t push_addr = CPU_8051.PC;
	
	PUSH (push_addr & 0x00FF); // pushing lower byte
	PUSH ( (push_addr & 0xFF00) >> 8); //have to push it lower by 8 otherwise it will give error.

	// change PC to jmp to subroutine
	CPU_8051.PC = ( (CPU_8051.PC & 0xF800) | (0xD1 & 0x70) ) | lower_addr_byte;

if ( PPRINT ) {		
printf ("\tACALL_0xD1 lower byte addr %X\n", lower_addr_byte);
}

	return 1; 
	
}

// need to be checked
int SETB ( ) {

	uint8_t addr = fetch ( );
	int8_t data = CPU_8051.Bit_Addressable[addr/8];
	data |= ( 1 << ((addr % 8) + 1) );

if ( PPRINT ) {		
printf ("\tSETB %X\n", addr);
}

	return 1;
	
}

int SETB_C ( ) {

	CPU_8051.SFR[PSW] |= CY;

if ( PPRINT ) {		
printf ("\tSETB C\n");
}

	return 1;

}

// DA A 

// doubtful
int DA ( ) {  

	int8_t data = CPU_8051.SFR[ACC];
	int8_t tmp;
	
	// checking lower nibble
	if ( ((data & 0x0F) > 9) | (CPU_8051.SFR[PSW] & AC)) {
		
		tmp = data >> 4;
		data += 0x06;
		
		if ( (data >> 4) - tmp > 1) // there is aux carry
		{
			CPU_8051.SFR[PSW] |= CY;
		}

		CPU_8051.SFR[ACC] |= (0x0F & data);

		if ( (CPU_8051.SFR[PSW] & CY) | ((data >> 4) > 9) ) {
			 
			data = addc (data, 0x60);
			CPU_8051.SFR[ACC] |= (0xF0 & data);
		}
	}

if ( PPRINT ) {		
printf ("\tDA A\n");
}

	return 1;
} 

// DJNZ byte_addr, relative offset
int DJNZ ( ) {

	uint8_t addr = fetch ( );
	int8_t displacement = fetch ( );

	int8_t data = *( (char*)&CPU_8051 + addr);
	data -= 1;
	if (data == 0) // branch 
	{
		CPU_8051.PC += displacement;
	}
	*( (char*)&CPU_8051 + addr) = data;

if ( PPRINT ) {		
printf ("\tDJNZ @%X,%X\n", addr, displacement);
}

	return 1;
}

/** XCHD A, @R0
 * xchange digit 
 * exchanges lower order nibble with that RAM location specified
 */
int XCHD_A_at_R0 ( ) {

	uint8_t addr = CPU_8051.REGISTERS[BANK ( )].R0;
	int8_t data = *( (char*)&CPU_8051 + addr);
	int8_t tmp = CPU_8051.SFR[ACC];
	CPU_8051.SFR[ACC] = (CPU_8051.SFR[ACC] & 0xF0) | (0x0F & data);
	data = ( data & 0xF0) | (tmp & 0x0F);
	*( (char*)&CPU_8051 + addr) = data;

if ( PPRINT ) {		
printf ("\tXCHD A, @R0 | R0 : %X\n", addr);
}

	return 1;

}

// 0xD7
// XCHD A, @R1
int XCHD_A_at_R1 ( ) {

	uint8_t addr = CPU_8051.REGISTERS[BANK ( )].R1;
	int8_t data = *( (char*)&CPU_8051 + addr);
	int8_t tmp = CPU_8051.SFR[ACC];
	CPU_8051.SFR[ACC] = (CPU_8051.SFR[ACC] & 0xF0) | (0x0F & data);
	data = ( data & 0xF0) | (tmp & 0x0F);
	*( (char*)&CPU_8051 + addr) = data;

if ( PPRINT ) {		
printf ("\tXCHD A, @R1 | R1 : %X\n", addr);
}

	return 1;

}

// DJNZ, R0, diplacement
int DJNZ_R0 ( ) {

	int8_t displacement = fetch ( );
	CPU_8051.REGISTERS[BANK ( )].R0 -= 1;
	if ( CPU_8051.REGISTERS[BANK ( )].R0  == 0) //branch
	{	
		CPU_8051.PC += displacement;
	}

if ( PPRINT ) {		
printf ("\tDJNZ R0, %X\n", displacement);
}

	return 1;
}

int DJNZ_R1 ( ) {

	int8_t displacement = fetch ( );
	CPU_8051.REGISTERS[BANK ( )].R1 -= 1;
	if ( CPU_8051.REGISTERS[BANK ( )].R1  == 0) //branch
	{	
		CPU_8051.PC += displacement;
	}

if ( PPRINT ) {		
printf ("\tDJNZ R1, %X\n", displacement);
}

	return 1;
} 

int DJNZ_R2 ( ) {

	int8_t displacement = fetch ( );
	CPU_8051.REGISTERS[BANK ( )].R2 -= 1;
	if ( CPU_8051.REGISTERS[BANK ( )].R2  == 0) //branch
	{	
		CPU_8051.PC += displacement;
	}

if ( PPRINT ) {		
printf ("\tDJNZ R2, %X\n", displacement);
}

	return 1;
}

int DJNZ_R3 ( ) {

	int8_t displacement = fetch ( );
	CPU_8051.REGISTERS[BANK ( )].R3 -= 1;
	if ( CPU_8051.REGISTERS[BANK ( )].R3  == 0) //branch
	{	
		CPU_8051.PC += displacement;
	}

if ( PPRINT ) {		
printf ("\tDJNZ R3, %X\n", displacement);
}

	return 1;
}

int DJNZ_R4 ( ) {

	int8_t displacement = fetch ( );
	CPU_8051.REGISTERS[BANK ( )].R4 -= 1;
	if ( CPU_8051.REGISTERS[BANK ( )].R4  == 0) //branch
	{	
		CPU_8051.PC += displacement;
	}

if ( PPRINT ) {		
printf ("\tDJNZ R4, %X\n", displacement);
}

	return 1;
}

int DJNZ_R5 ( ) {

	int8_t displacement = fetch ( );
	CPU_8051.REGISTERS[BANK ( )].R5 -= 1;
	if ( CPU_8051.REGISTERS[BANK ( )].R5  == 0) //branch
	{	
		CPU_8051.PC += displacement;
	}

if ( PPRINT ) {		
printf ("\tDJNZ R5, %X\n", displacement);
}

	return 1;

}

int DJNZ_R6 ( ) {

	int8_t displacement = fetch ( );
	CPU_8051.REGISTERS[BANK ( )].R6 -= 1;
	if ( CPU_8051.REGISTERS[BANK ( )].R6  == 0) //branch
	{	
		CPU_8051.PC += displacement;
	}

if ( PPRINT ) {		
printf ("\tDJNZ R6, %X\n", displacement);
}

	return 1;

}

// 0xDF
int DJNZ_R7 ( ) {

	int8_t displacement = fetch ( );
	CPU_8051.REGISTERS[BANK ( )].R7 -= 1;
	if ( CPU_8051.REGISTERS[BANK ( )].R7  == 0) //branch
	{	
		CPU_8051.PC += displacement;
	}

if ( PPRINT ) {		
printf ("\tDJNZ R7, %X\n", displacement);
}

	return 1;
}

// 0xE0
// MOVX A, @DPTR
// doubtful
int MOVX_at_DPTR ( ) {

	uint16_t addr = (CPU_8051.SFR[DPH] << 8) | (CPU_8051.SFR[DPL]);
	CPU_8051.SFR[ACC] = CPU_8051.Code_Memory[addr];

if ( PPRINT ) {		
printf ("\tMOVX A, @%X\n", addr);
}

	return 1;
}

//0xE1
int AJMP_0xE1 ( ) { 
	uint16_t low_add_byte = fetch ( );
	CPU_8051.PC = ( ( CPU_8051.PC & 0xF800) | (0xE1 & 0x70) ) | low_add_byte;

if ( PPRINT ) {		
printf ("\tAJMP_0xE1 %X\n", low_add_byte);
}

	return 1;
}

/** required port programming 
 * access external memory connected to R0
 * here we assume we are addressing lower memory
 */
// MOVX A, @R0
int MOVX_A_at_R0 ( ) {

	uint8_t addr = CPU_8051.REGISTERS[BANK ( )].R0;
	CPU_8051.SFR[ACC] = CPU_8051.Code_Memory[addr];

if ( PPRINT ) {		
printf ("\tMOVX A, @R0 | R0 : %X\n", addr);
}

	return 1;
}

// MOVX A, @R1
int MOVX_A_at_R1 ( ) {

	uint8_t addr = CPU_8051.REGISTERS[BANK ( )].R1;
	CPU_8051.SFR[ACC] = CPU_8051.Code_Memory[addr];

if ( PPRINT ) {		
printf ("\tMOVX A, @R1 | R1 : %X\n", addr);
}

	return 1;

}


/** 0xE4
 * clear Acc
 */
int CLR_A () {
	
	CPU_8051.SFR[ACC] = 0x00;

if ( PPRINT ) {		
printf ("\tCLR A\n");
}

	return 1;

}


int MOV_A_dataaddr ( ) {
	
	uint8_t addr = fetch ( );
	CPU_8051.SFR[ACC] = *( (char*)&CPU_8051 + addr);

if ( PPRINT ) {		
printf ("\tMOV A, @%X\n", addr);
}

	return 1;

}

int MOV_A_at_R0 ( ) {

	uint8_t addr = CPU_8051.REGISTERS[BANK ( )].R0;
	CPU_8051.SFR[ACC] = *( (char*)&CPU_8051 + addr );

if ( PPRINT ) {		
printf ("\tMOV A, @R0 | R0 : %X\n", CPU_8051.REGISTERS[BANK ( )].R0);
}

	return 1;

}

// 0xE7
int MOV_A_at_R1 ( ) {

	uint8_t addr = CPU_8051.REGISTERS[BANK ( )].R1;
	CPU_8051.SFR[ACC] = *( (char*)&CPU_8051 + addr );

if ( PPRINT ) {		
printf ("\tMOV A, @R1 | R1 : %X\n", CPU_8051.REGISTERS[BANK ( )].R1 );
}

	return 1;
	
}

/** 0xE8
 * MOV A, R0
 */
int MOV_A_R0 ( ) {

	CPU_8051.SFR[ACC] = CPU_8051.REGISTERS[BANK ( )].R0;

if ( PPRINT ) {		
printf ("\tMOV A, R0 | R0 : %X\n", CPU_8051.REGISTERS[BANK ( )].R0);
}

	return 1;

}

int MOV_A_R1 ( ) {

	CPU_8051.SFR[ACC] = CPU_8051.REGISTERS[BANK ( )].R1;

if ( PPRINT ) {		
printf ("\tMOV A, R1 | R1 : %X\n", CPU_8051.REGISTERS[BANK ( )].R1);
}

	return 1;
	
}

int MOV_A_R2 ( ) {

	CPU_8051.SFR[ACC] = CPU_8051.REGISTERS[BANK ( )].R2;

if ( PPRINT ) {		
printf ("\tMOV A, R2 | R2 : %X\n", CPU_8051.REGISTERS[BANK ( )].R2);
}

	return 1;
	
}

int MOV_A_R3 ( ) {

	CPU_8051.SFR[ACC] = CPU_8051.REGISTERS[BANK ( )].R3;

if ( PPRINT ) {		
printf ("\tMOV A, R3 | R3 : %X\n", CPU_8051.REGISTERS[BANK ( )].R3);
}

	return 1;
	
}

int MOV_A_R4 ( ) {

	CPU_8051.SFR[ACC] = CPU_8051.REGISTERS[BANK ( )].R4;

if ( PPRINT ) {		
printf ("\tMOV A, R4 | R4 : %X\n", CPU_8051.REGISTERS[BANK ( )].R4);
}

	return 1;
	
}

int MOV_A_R5 ( ) {

	CPU_8051.SFR[ACC] = CPU_8051.REGISTERS[BANK ( )].R5;

if ( PPRINT ) {		
printf ("\tMOV A, R5 | R5 : %X\n", CPU_8051.REGISTERS[BANK ( )].R5);
}

	return 1;
	
}

int MOV_A_R6 ( ) {

	CPU_8051.SFR[ACC] = CPU_8051.REGISTERS[BANK ( )].R6;

if ( PPRINT ) {		
printf ("\tMOV A, R6 | R6 : %X\n", CPU_8051.REGISTERS[BANK ( )].R6);
}

	return 1;
	
}

//0xEF
int MOV_A_R7 ( ) {

	CPU_8051.SFR[ACC] = CPU_8051.REGISTERS[BANK ( )].R7;

if ( PPRINT ) {		
printf ("\tMOV A, R7 | R7 : %X\n", CPU_8051.REGISTERS[BANK ( )].R7);
}

	return 1;
	
}
// 0xF0
int MOVX_at_DPTR_A ( ) {

	uint16_t addr = (CPU_8051.SFR[DPH] << 8) | CPU_8051.SFR[DPL];
	CPU_8051.Code_Memory[addr] = CPU_8051.SFR[ACC];

if ( PPRINT ) {		
printf ("\tMOVX @DPTR, A | DPTR : %X\n", addr);
}

	return 1;

}

//0xF1
int ACALL_0xF1 ( ) {

	uint8_t lower_addr_byte = fetch ( );
	uint16_t push_addr = CPU_8051.PC;
	
	PUSH (push_addr & 0x00FF); // pushing lower byte
	PUSH ( (push_addr & 0xFF00) >> 8); //have to push it lower by 8 otherwise it will give error.

	// change PC to jmp to subroutine
	CPU_8051.PC = ( (CPU_8051.PC & 0xF800) | (0xF1 & 0x70) ) | lower_addr_byte;

if ( PPRINT ) {		
printf ("\tACALL_0xF1 lower byte addr %X\n", lower_addr_byte);
}

	return 1; 
}

int MOVX_at_R0_A ( ) {

	uint8_t addr = CPU_8051.REGISTERS[BANK ( )].R0;
	*( (char*)&CPU_8051 + addr ) = CPU_8051.SFR[ACC];

if ( PPRINT ) {		
printf ("\tMOVX @R0, A | R0 : %X\n", CPU_8051.REGISTERS[BANK ( )].R0);
}

	return 1;

}

int MOVX_at_R1_A ( ) {

	uint8_t addr = CPU_8051.REGISTERS[BANK ( )].R1;
	*( (char*)&CPU_8051 + addr ) = CPU_8051.SFR[ACC];

if ( PPRINT ) {		
printf ("\tMOVX @R1, A | R1 : %X\n", CPU_8051.REGISTERS[BANK ( )].R1);
}

	return 1;
	
}

/** 0xF4
 * CPL A : Complement A
 */
int CPL_A ( ) {

	CPU_8051.SFR[ACC] ^= 0xFF;

if ( PPRINT ) {		
printf ("\tCPL A \n");
}

	return 1;

}

int MOV_data_addr_A ( ) {

	uint8_t addr = fetch ( );
	*( (char*)&CPU_8051 + addr ) = CPU_8051.SFR[ACC];

if ( PPRINT ) {		
printf ("\tMOV @%X, A \n", addr);
}

	return 1;

} 

int MOV_at_R0_A ( ) {

	uint8_t addr = CPU_8051.REGISTERS[BANK ( )].R0;
	*( (char*)&CPU_8051 + addr ) = CPU_8051.SFR[ACC];

if ( PPRINT ) {		
printf ("\tMOV @R0, A | R0 : %X\n", CPU_8051.REGISTERS[BANK ( )].R0);
}

	return 1;

}  

// 0xF7
int MOV_at_R1_A ( ) {

	uint8_t addr = CPU_8051.REGISTERS[BANK ( )].R1;
	*( (char*)&CPU_8051 + addr ) = CPU_8051.SFR[ACC];

if ( PPRINT ) {		
printf ("\tMOV @R1, A | R1 : %X\n", CPU_8051.REGISTERS[BANK ( )].R1);
}

	return 1;

}  

int MOV_R0_A ( ) {

	CPU_8051.REGISTERS[BANK ( )].R0 = CPU_8051.SFR[ACC];

if ( PPRINT ) {		
printf ("\tMOV R0, A | R0 : %X\n", CPU_8051.REGISTERS[BANK ( )].R0);
}

	return 1;

} 

int MOV_R1_A ( ) {

	CPU_8051.REGISTERS[BANK ( )].R1 = CPU_8051.SFR[ACC];

if ( PPRINT ) {		
printf ("\tMOV R1, A | R1 : %X\n", CPU_8051.REGISTERS[BANK ( )].R1);
}

	return 1;
	
} 

int MOV_R2_A ( ) {

	CPU_8051.REGISTERS[BANK ( )].R2 = CPU_8051.SFR[ACC];

if ( PPRINT ) {		
printf ("\tMOV R2, A | R2 : %X\n", CPU_8051.REGISTERS[BANK ( )].R2);
}

	return 1;
	
} 

int MOV_R3_A ( ) {

	CPU_8051.REGISTERS[BANK ( )].R3 = CPU_8051.SFR[ACC];

if ( PPRINT ) {		
printf ("\tMOV R3, A | R3 : %X\n", CPU_8051.REGISTERS[BANK ( )].R3);
}

	return 1;
	
} 

int MOV_R4_A ( ) {

	CPU_8051.REGISTERS[BANK ( )].R4 = CPU_8051.SFR[ACC];

if ( PPRINT ) {		
printf ("\tMOV R4, A | R4 : %X\n", CPU_8051.REGISTERS[BANK ( )].R4);
}

	return 1;
	
} 

int MOV_R5_A ( ) {

	CPU_8051.REGISTERS[BANK ( )].R5 = CPU_8051.SFR[ACC];

if ( PPRINT ) {		
printf ("\tMOV R5, A | R5 : %X\n", CPU_8051.REGISTERS[BANK ( )].R5);
}

	return 1;
	
} 

int MOV_R6_A ( ) {

	CPU_8051.REGISTERS[BANK ( )].R6 = CPU_8051.SFR[ACC];

if ( PPRINT ) {		
printf ("\tMOV R6, A | R6 : %X\n", CPU_8051.REGISTERS[BANK ( )].R6);
}

	return 1;
	
} 

//0xFF
int MOV_R7_A ( ) {

	CPU_8051.REGISTERS[BANK ( )].R7 = CPU_8051.SFR[ACC];

if ( PPRINT ) {		
printf ("\tMOV R7, A | R7 : %X\n", CPU_8051.REGISTERS[BANK ( )].R7);
}

	return 1;
	
} 
