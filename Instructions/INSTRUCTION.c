#include "INSTRUCTION.h"
#include "../Memory/Memory.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef complete

void assign_functions ( ) {

	// working tree clean @CALL 

	OP_CODES[0x0] = NOP;                         OP_CODES[0x1] = AJMP_0x01;                   OP_CODES[0x2] = LJMP;                        OP_CODES[0x3] = RR;                          OP_CODES[0x4] = INC_A;                       OP_CODES[0x5] = INC_data_addr;               OP_CODES[0x6] = INC_at_R0;                   OP_CODES[0x7] = INC_at_R1;                   
	OP_CODES[0x8] = INC_R0;                      OP_CODES[0x9] = INC_R1;                      OP_CODES[0xa] = INC_R2;                      OP_CODES[0xb] = INC_R3;                      OP_CODES[0xc] = INC_R4;                      OP_CODES[0xd] = INC_R5;                      OP_CODES[0xe] = INC_R6;                      OP_CODES[0xf] = INC_R7;                      
	OP_CODES[0x10] = JBC;                        OP_CODES[0x11] = ACALL_0x11;                 OP_CODES[0x12] = LCALL;                      OP_CODES[0x13] = RRC_A;                      OP_CODES[0x14] = DEC_A;                      OP_CODES[0x15] = DEC_data_addr;              OP_CODES[0x16] = DEC_at_R0;                  OP_CODES[0x17] = DEC_at_R1;                  
	OP_CODES[0x18] = DEC_R0;                     OP_CODES[0x19] = DEC_R1;                     OP_CODES[0x1a] = DEC_R2;                     OP_CODES[0x1b] = DEC_R3;                     OP_CODES[0x1c] = DEC_R4;                     OP_CODES[0x1d] = DEC_R5;                     OP_CODES[0x1e] = DEC_R6;                     OP_CODES[0x1f] = DEC_R7;                     
	OP_CODES[0x20] = JB;                         OP_CODES[0x21] = AJMP_0x21;                  OP_CODES[0x22] = RET;                        OP_CODES[0x23] = RL;                         OP_CODES[0x24] = ADD_data;                   OP_CODES[0x25] = ADD_data_addr;              OP_CODES[0x26] = ADD_at_R0;                  OP_CODES[0x27] = ADD_at_R1;                  
	OP_CODES[0x28] = ADD_R0;                     OP_CODES[0x29] = ADD_R1;                     OP_CODES[0x2a] = ADD_R2;                     OP_CODES[0x2b] = ADD_R3;                     OP_CODES[0x2c] = ADD_R4;                     OP_CODES[0x2d] = ADD_R5;                     OP_CODES[0x2e] = ADD_R6;                     OP_CODES[0x2f] = ADD_R7;                     
	OP_CODES[0x30] = JNB;                        OP_CODES[0x31] = ACALL_0x31;                 OP_CODES[0x32] = RETI;                       OP_CODES[0x33] = RLC;                        OP_CODES[0x34] = ADDC_data;                  OP_CODES[0x35] = ADDC_data_addr;             OP_CODES[0x36] = ADDC_at_R0;                 OP_CODES[0x37] = ADDC_at_R1;                 
	OP_CODES[0x38] = ADDC_R0;                    OP_CODES[0x39] = ADDC_R1;                    OP_CODES[0x3a] = ADDC_R2;                    OP_CODES[0x3b] = ADDC_R3;                    OP_CODES[0x3c] = ADDC_R4;                    OP_CODES[0x3d] = ADDC_R5;                    OP_CODES[0x3e] = ADDC_R6;                    OP_CODES[0x3f] = ADDC_R7;                    
	OP_CODES[0x40] = JC;                         OP_CODES[0x41] = AJMP_0x41;                  OP_CODES[0x42] = ORL_data_addr_A;            OP_CODES[0x43] = ORL_data_addr_data;         OP_CODES[0x44] = ORL_A_data;                 OP_CODES[0x45] = ORL_A_data_addr;            OP_CODES[0x46] = ORL_acc_at_R0;              OP_CODES[0x47] = ORL_acc_at_R1;              
	OP_CODES[0x48] = ORL_R0;                     OP_CODES[0x49] = ORL_R1;                     OP_CODES[0x4a] = ORL_R2;                     OP_CODES[0x4b] = ORL_R3;                     OP_CODES[0x4c] = ORL_R4;                     OP_CODES[0x4d] = ORL_R5;                     OP_CODES[0x4e] = ORL_R6;                     OP_CODES[0x4f] = ORL_R7;                     
	OP_CODES[0x50] = JNC;                        OP_CODES[0x51] = ACALL_0x51;                 OP_CODES[0x52] = ANL_data_addr_A;            OP_CODES[0x53] = ANL_data_addr_data;         OP_CODES[0x54] = ANL_A_data;                 OP_CODES[0x55] = ANL_A_data_addr;            OP_CODES[0x56] = ANL_A_at_R0;                OP_CODES[0x57] = ANL_A_at_R1;                
	OP_CODES[0x58] = ANL_R0;                     OP_CODES[0x59] = ANL_R1;                     OP_CODES[0x5a] = ANL_R2;                     OP_CODES[0x5b] = ANL_R3;                     OP_CODES[0x5c] = ANL_R4;                     OP_CODES[0x5d] = ANL_R5;                     OP_CODES[0x5e] = ANL_R6;                     OP_CODES[0x5f] = ANL_R7;                     
	OP_CODES[0x60] = JZ;                         OP_CODES[0x61] = AJMP_0x61;                  OP_CODES[0x62] = XRL_data_addr_A;            OP_CODES[0x63] = XRL_data_addr_data;         OP_CODES[0x64] = XRL_A_data;                 OP_CODES[0x65] = XRL_A_dataaddr;             OP_CODES[0x66] = XRL_A_at_R0;                OP_CODES[0x67] = XRL_A_at_R1;                
	OP_CODES[0x68] = XRL_R0;                     OP_CODES[0x69] = XRL_R1;                     OP_CODES[0x6a] = XRL_R2;                     OP_CODES[0x6b] = XRL_R3;                     OP_CODES[0x6c] = XRL_R4;                     OP_CODES[0x6d] = XRL_R5;                     OP_CODES[0x6e] = XRL_R6;                     OP_CODES[0x6f] = XRL_R7;                     
	OP_CODES[0x70] = JNZ;                        OP_CODES[0x71] = ACALL_0x71;                 OP_CODES[0x72] = ORL_C;                      OP_CODES[0x73] = JMP_at_A_DPTR;              OP_CODES[0x74] = MOV_A_data;                 OP_CODES[0x75] = MOV_data_addr_data;         OP_CODES[0x76] = MOV_at_R0;                  OP_CODES[0x77] = MOV_at_R1;                  
	OP_CODES[0x78] = MOV_R0;                     OP_CODES[0x79] = MOV_R1;                     OP_CODES[0x7a] = MOV_R2;                     OP_CODES[0x7b] = MOV_R3;                     OP_CODES[0x7c] = MOV_R4;                     OP_CODES[0x7d] = MOV_R5;                     OP_CODES[0x7e] = MOV_R6;                     OP_CODES[0x7f] = MOV_R7;                     
	OP_CODES[0x80] = SJMP;                       OP_CODES[0x81] = AJMP_0x81;                  OP_CODES[0x82] = ANL_C;                      OP_CODES[0x83] = MOVC;                       OP_CODES[0x84] = DIV;                        OP_CODES[0x85] = MOV_data_addr_data_addr;    OP_CODES[0x86] = MOV_data_addr_atR0;         OP_CODES[0x87] = MOV_data_addr_atR1;         
	OP_CODES[0x88] = MOV_data_addr_R0;           OP_CODES[0x89] = MOV_data_addr_R1;           OP_CODES[0x8a] = MOV_data_addr_R2;           OP_CODES[0x8b] = MOV_data_addr_R3;           OP_CODES[0x8c] = MOV_data_addr_R4;           OP_CODES[0x8d] = MOV_data_addr_R5;           OP_CODES[0x8e] = MOV_data_addr_R6;           OP_CODES[0x8f] = MOV_data_addr_R7;           
	OP_CODES[0x90] = MOV_DPTR_data;              OP_CODES[0x91] = ACALL_0x91;                 OP_CODES[0x92] = MOV_bit_C;                  OP_CODES[0x93] = MOVC_A_dptr;                OP_CODES[0x94] = SUBB_A_data;                OP_CODES[0x95] = SUBB_A_data_addr;           OP_CODES[0x96] = SUBB_A_atR0;                OP_CODES[0x97] = SUBB_A_atR1;                
	OP_CODES[0x98] = SUBB_R0;                    OP_CODES[0x99] = SUBB_R1;                    OP_CODES[0x9a] = SUBB_R2;                    OP_CODES[0x9b] = SUBB_R3;                    OP_CODES[0x9c] = SUBB_R4;                    OP_CODES[0x9d] = SUBB_R5;                    OP_CODES[0x9e] = SUBB_R6;                    OP_CODES[0x9f] = SUBB_R7;                    
	OP_CODES[0xa0] = ORL_C;                      OP_CODES[0xa1] = AJMP_0xA1;                  OP_CODES[0xa2] = MOV_C;                      OP_CODES[0xa3] = INC_dptr;                   OP_CODES[0xa4] = MUL;                        /*OP_CODES[0xa5] = XXXXXXXX;*/               OP_CODES[0xa6] = MOV_atR0_data_addr;         OP_CODES[0xa7] = MOV_atR1_data_addr;         
	OP_CODES[0xa8] = R0_data_addr;               OP_CODES[0xa9] = R1_data_addr;               OP_CODES[0xaa] = R2_data_addr;               OP_CODES[0xab] = R3_data_addr;               OP_CODES[0xac] = R4_data_addr;               OP_CODES[0xad] = R5_data_addr;               OP_CODES[0xae] = R6_data_addr;               OP_CODES[0xaf] = R7_data_addr;               
	OP_CODES[0xb0] = ANL_C;                      OP_CODES[0xb1] = ACALL_0xB1;                 OP_CODES[0xb2] = CPL;                        OP_CODES[0xb3] = CPL_C;                      OP_CODES[0xb4] = CJNE_A_data_codeaddr;       OP_CODES[0xb5] = CJNE_A_data_addr_codeaddr;  OP_CODES[0xb6] = CJNE_atR0_data_codeaddr;    OP_CODES[0xb7] = CJNE_atR1_data_codeaddr;    
	OP_CODES[0xb8] = CJNE_R0;                    OP_CODES[0xb9] = CJNE_R1;                    OP_CODES[0xba] = CJNE_R2;                    OP_CODES[0xbb] = CJNE_R3;                    OP_CODES[0xbc] = CJNE_R4;                    OP_CODES[0xbd] = CJNE_R5;                    OP_CODES[0xbe] = CJNE_R6;                    OP_CODES[0xbf] = CJNE_R7;                    
	OP_CODES[0xc0] = PUSH;                       OP_CODES[0xc1] = AJMP_0xC1;                  OP_CODES[0xc2] = CLR;                        OP_CODES[0xc3] = CLR_C;                      OP_CODES[0xc4] = SWAP;                       OP_CODES[0xc5] = XCH_A_dataaddr;             OP_CODES[0xc6] = XCH_A_atR0;                 OP_CODES[0xc7] = XCH_A_at_R1;                
	OP_CODES[0xc8] = XCH_A_R0;                   OP_CODES[0xc9] = XCH_A_R1;                   OP_CODES[0xca] = XCH_A_R2;                   OP_CODES[0xcb] = XCH_A_R3;                   OP_CODES[0xcc] = XCH_A_R4;                   OP_CODES[0xcd] = XCH_A_R5;                   OP_CODES[0xce] = XCH_A_R6;                   OP_CODES[0xcf] = XCH_A_R7;                   
	OP_CODES[0xd0] = POP;                        OP_CODES[0xd1] = ACALL_0xD1;                 OP_CODES[0xd2] = SETB;                       OP_CODES[0xd3] = SETB_C;                     OP_CODES[0xd4] = DA;                         OP_CODES[0xd5] = DJNZ;                       OP_CODES[0xd6] = XCHD_A_at_R0;               OP_CODES[0xd7] = XCHD_A_at_R1;               
	OP_CODES[0xd8] = DJNZ_R0;                    OP_CODES[0xd9] = DJNZ_R1;                    OP_CODES[0xda] = DJNZ_R2;                    OP_CODES[0xdb] = DJNZ_R3;                    OP_CODES[0xdc] = DJNZ_R4;                    OP_CODES[0xdd] = DJNZ_R5;                    OP_CODES[0xde] = DJNZ_R6;                    OP_CODES[0xdf] = DJNZ_R7;                    
	OP_CODES[0xe0] = MOVX_at_DPTR;               OP_CODES[0xe1] = AJMP_0xE1;                  OP_CODES[0xe2] = MOVX_A_at_R0;               OP_CODES[0xe3] = MOVX_A_at_R1;               OP_CODES[0xe4] = CLR_A;                      OP_CODES[0xe5] = MOV_A_dataaddr;             OP_CODES[0xe6] = MOV_A_at_R0;                OP_CODES[0xe7] = MOV_A_at_R1;                
	OP_CODES[0xe8] = MOV_A_R0;                   OP_CODES[0xe9] = MOV_A_R1;                   OP_CODES[0xea] = MOV_A_R2;                   OP_CODES[0xeb] = MOV_A_R3;                   OP_CODES[0xec] = MOV_A_R4;                   OP_CODES[0xed] = MOV_A_R5;                   OP_CODES[0xee] = MOV_A_R6;                   OP_CODES[0xef] = MOV_A_R7;                   
	OP_CODES[0xf0] = MOVX_at_DPTR_A;             OP_CODES[0xf1] = ACALL_0xF1;                 OP_CODES[0xf2] = MOVX_at_R0_A;               OP_CODES[0xf3] = MOVX_at_R1_A;               OP_CODES[0xf4] = CPL_A;                      OP_CODES[0xf5] = MOV_data_addr_A;            OP_CODES[0xf6] = MOV_at_R0_A;                OP_CODES[0xf7] = MOV_at_R1_A;                
	OP_CODES[0xf8] = MOV_R0_A;                   OP_CODES[0xf9] = MOV_R1_A;                   OP_CODES[0xfa] = MOV_R2_A;                   OP_CODES[0xfb] = MOV_R3_A;                   OP_CODES[0xfc] = MOV_R4_A;                   OP_CODES[0xfd] = MOV_R5_A;                   OP_CODES[0xfe] = MOV_R6_A;                   OP_CODES[0xff] = MOV_R7_A;                   

}
#endif
/*----------------------------------------------EXTRA HELPING FUNCTIONS---------------------------------------------------*/
void Init_CPU (void) {

	// default values of SFR at power up 

	CPU_8051.SFR[ACC] 	=	0x00;
	CPU_8051.SFR[SP]	=	0x00;  // for now it points to scratch pad area
	CPU_8051.SFR[B]   	=	0x00;
	CPU_8051.SFR[PSW] 	= 	0x00;
	CPU_8051.SFR[PSW] 	= 	0x07;
	CPU_8051.SFR[DPH] 	= 	0x00;
	CPU_8051.SFR[DPL] 	=	0x00;
	CPU_8051.SFR[P0]  	=	0xFF;
	CPU_8051.SFR[P1]  	=	0xFF;
	CPU_8051.SFR[P2]  	=	0xFF;
	CPU_8051.SFR[P3]  	= 	0xFF;
	CPU_8051.SFR[IE]  	=	0x00;
	CPU_8051.SFR[TMOD]	=	0x00;
	CPU_8051.SFR[TCON]	=	0x00;
	CPU_8051.SFR[TH0] 	=	0x00;
	CPU_8051.SFR[TL0] 	=	0x00;
	CPU_8051.SFR[TH1] 	=	0x00;
	CPU_8051.SFR[TL1] 	=	0x00;
	CPU_8051.SFR[SCON]	=	0x00;
	CPU_8051.SFR[SBUF]	=	0x00;
	CPU_8051.SFR[PCON]	=	0x00;

	/** initialize the registers in CPU */
	for (int i = 0; i < 3; i++)	{
		CPU_8051.REGISTERS[i].R0 = 0;
		CPU_8051.REGISTERS[i].R1 = 0;
		CPU_8051.REGISTERS[i].R2 = 0;
		CPU_8051.REGISTERS[i].R3 = 0;
		CPU_8051.REGISTERS[i].R4 = 0;
		CPU_8051.REGISTERS[i].R5 = 0;
		CPU_8051.REGISTERS[i].R6 = 0;
		CPU_8051.REGISTERS[i].R7 = 0;
	}

	// bit addressable area 
	for (int i = 0; i < 16; i ++)	CPU_8051.Bit_Addressable[i] = 0x0;

	// Scratch Pad
	for (int i = 0; i < 0x4F; i++)	CPU_8051.ScratchPad[i] = 0x0;

	// zeroing the code memory
	for (int i = 0; i < FLASH; i++)	CPU_8051.Code_Memory[i] = 0x0;

	CPU_8051.PC = 0x00;
	CPU_8051.Bank = 0x0;

}

int8_t fetch ( ) {
	int16_t temp = CPU_8051.PC;
	CPU_8051.PC += 1;
	return CPU_8051.Code_Memory[temp];
}
void update_parity ( ) {
	int8_t temp = CPU_8051.SFR[ACC];
	char ones = 0;
	for (int i = 0; i < 8; i++) {
		if (temp & (1 << i))	ones++;
	}

	if (ones % 2) { 	// even 1, P = 0
		CPU_8051.SFR[PSW] &= ~(1 << P);
	}
	else { 			// odd parity, P = 1
		CPU_8051.SFR[PSW] |= (1 << P);
	}
}

/*------------------------------------------------------------------------------------------------------------------------*/


/*----------------------------------------------CPU Instructions----------------------------------------------------------*/

/** by default SP = 0x81H
 * which means it is in upper area of RAM,
 * above the scratch pad area
 */
int PUSH (int8_t data) {
	CPU_8051.ScratchPad [CPU_8051.SFR[SP]] = data;
	CPU_8051.SFR [SP] += 1;
	return 1;
}			

int NOP () {
	return 1;
}





int AJMP_0x01 () { 
	uint16_t low_add_byte = fetch ( );
	CPU_8051.PC = ( ( CPU_8051.PC & 0xF800) | (0x01 & 0x70) ) | low_add_byte;
	return 1;
}

/** 0x02, 
 * assuming data or address is stored in little endian format
 */
int LJMP ( ) {
	uint8_t low_byte = fetch ( );
	uint16_t high_byte = fetch ( );
	high_byte = (high_byte << 8) | low_byte;
	CPU_8051.PC = high_byte;
	return 1;	
}

// 0x03
int RR ( ) {
	int8_t tmp = CPU_8051.SFR[ACC];
	CPU_8051.SFR[ACC] = (CPU_8051.SFR[ACC] << 1) | (tmp >> 7);
	return 1;
}

// 0x04
int INC_A ( ) {
	int8_t temp = CPU_8051.SFR[ACC];
	temp++;
	CPU_8051.SFR[ACC] = temp;
	update_parity();
	return 1;
}

// 0x05
int INC_data_addr ( ) {
	int8_t addr = fetch ( );
	CPU_8051.Code_Memory[addr] += 1;
	return 1;
}	

// 0x06
int INC_at_R0 ( ) {
	int8_t tmp = CPU_8051.REGISTERS[BANK].R0;

	/** we can only address code memory here, not give RAM address in R0 */
	CPU_8051.Code_Memory[tmp] += 1;
	return 1;
}

// 0x07
int INC_at_R1 ( ){
	int8_t tmp = CPU_8051.REGISTERS[BANK].R1;
	/** we can only address code memory here, not give RAM address in R1 */
	CPU_8051.Code_Memory[tmp] += 1;
	return 1;

}

// 0x08
int INC_R0 ( ) {
	CPU_8051.REGISTERS[BANK].R0 += 1;
	return 1;
}

// 0x09
int INC_R1 ( ) {
	CPU_8051.REGISTERS[BANK].R1 += 1;
	return 1;
}

// 0x0A
int INC_R2 ( ) {
	CPU_8051.REGISTERS[BANK].R2 += 1;
	return 1;
}

// 0x0B
int INC_R3 ( ) {
	CPU_8051.REGISTERS[BANK].R3 += 1;
	return 1;	
}

// 0x0C
int INC_R4 ( ) {
	CPU_8051.REGISTERS[BANK].R4 += 1;
	return 1;	
}

// 0x0D
int INC_R5 ( ) {
	CPU_8051.REGISTERS[BANK].R5 += 1;
	return 1;
}

//0x0E
int INC_R6 ( ) {
	CPU_8051.REGISTERS[BANK].R6 += 1;
	return 1;
}

//0x0F
int INC_R7 ( ) {
	CPU_8051.REGISTERS[BANK].R7 += 1;
	return 1;
}

//int JBC ( ) {  return 0;} 		//0x10	

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

	uint16_t push_addr = CPU_8051.PC + 2;
	PUSH (push_addr & 0x00FF); // pushing lower byte
	PUSH ( (push_addr & 0xFF00) >> 8); //have to push it lower by 8 otherwise it will give error.

	// change PC to jmp to subroutine
	uint8_t lower_addr_byte = fetch();
	CPU_8051.PC = ( (CPU_8051.PC & 0xF800) | (0x11 & 0x70) ) | lower_addr_byte;
	return 1; 
	
}

//0x12
int LCALL ( ) {

	uint16_t push_addr = CPU_8051.PC + 3;
	PUSH (push_addr & 0x00FF); // pushing lower byte
	PUSH ( (push_addr & 0xFF00) >> 8); //have to push it lower by 8 otherwise it will give error.

	// change PC to jmp to subroutine
	uint8_t lower_addr_byte = fetch( );
	uint8_t upper_addr_byte = fetch ( );
	uint16_t new_addr = ( upper_addr_byte << 8) | lower_addr_byte;
	CPU_8051.PC = new_addr;
	return 1;
	
}

// 0x13
//int RRC_A ( ) {  return 0;} 

// 0x14
int DEC_A ( ) {
	CPU_8051.SFR[ACC] -= 1;
	return 1;
}
// 0x15
int DEC_data_addr ( ) {
	int8_t addr = fetch();
	CPU_8051.Code_Memory[addr] -= 1;
}

// 0x16
int DEC_at_R0 ( ) {
	int8_t tmp = CPU_8051.REGISTERS[BANK].R0;
	/** we can only address code memory here, not give RAM address in R0 */
	CPU_8051.Code_Memory[tmp] -= 1;
}

// 0x17
int DEC_at_R1 ( ) {
	int8_t tmp = CPU_8051.REGISTERS[BANK].R1;
	/** we can only address code memory here, not give RAM address in R1 */
	CPU_8051.Code_Memory[tmp] -= 1;
}
//0x18
int DEC_R0 ( ) {
	CPU_8051.REGISTERS[BANK].R0 -= 1;
	return 1;	
}

// 0x19
int DEC_R1 ( ) {
	CPU_8051.REGISTERS[BANK].R1 -= 1;
	return 1;	
}

// 0x1A
int DEC_R2 ( ) {
	CPU_8051.REGISTERS[BANK].R2 -= 1;
	return 1;	
}

// 0x1B
int DEC_R3 ( ) {
	CPU_8051.REGISTERS[BANK].R3 -= 1;
	return 1;	
}

// 0x1C
int DEC_R4 ( ) {
	CPU_8051.REGISTERS[BANK].R4 -= 1;
	return 1;	
}

// 0x1D
int DEC_R5 ( ) {
	CPU_8051.REGISTERS[BANK].R5 -= 1;
	return 1;	
}

// 0x1E
int DEC_R6 ( ) {
	CPU_8051.REGISTERS[BANK].R6 -= 1;
	return 1;	
}

// 0x1F
int DEC_R7 ( ) {
	CPU_8051.REGISTERS[BANK].R7 -= 1;
	return 1;	
}

// int JB ( ) {  return 0;} 		//0x20

//0x21
int AJMP_0x21 ( ) { 
	uint16_t low_add_byte = fetch ( );
	CPU_8051.PC = ( ( CPU_8051.PC & 0xF800) | (0x21 & 0x70) ) | low_add_byte;
	return 1;
}
// int RET ( ) {  return 0;} 		
// int RL ( ) {  return 0;} 
// int ADD_data ( ) {  return 0;} 
// int ADD_data_addr ( ) {  return 0;} 
// int ADD_at_R0 ( ) {  return 0;} 
// int ADD_at_R1 ( ) {  return 0;} 	//0x27
// int ADD_R0 ( ) {  return 0;} 
// int ADD_R1 ( ) {  return 0;} 
// int ADD_R2 ( ) {  return 0;} 
// int ADD_R3 ( ) {  return 0;} 
// int ADD_R4 ( ) {  return 0;} 
// int ADD_R5 ( ) {  return 0;} 
// int ADD_R6 ( ) {  return 0;} 
// int ADD_R7 ( ) {  return 0;} 		//0x2F
// int JNB ( ) {  return 0;} 		//0x30

//0x31
int ACALL_0x31 ( ) {

	uint16_t push_addr = CPU_8051.PC + 2;
	PUSH (push_addr & 0x00FF); // pushing lower byte
	PUSH ( (push_addr & 0xFF00) >> 8); //have to push it lower by 8 otherwise it will give error.

	// change PC to jmp to subroutine
	uint8_t lower_addr_byte = fetch();
	CPU_8051.PC = ( (CPU_8051.PC & 0xF800) | (0x31 & 0x70) ) | lower_addr_byte;
	return 1; 
	
}
// int RETI ( ) {  return 0;} 
// int RLC ( ) {  return 0;} 
// int ADDC_data ( ) {  return 0;} 
// int ADDC_data_addr ( ) {  return 0;} 
// int ADDC_at_R0 ( ) {  return 0;} 
// int ADDC_at_R1 ( ) {  return 0;} 	//0x37
// int ADDC_R0 ( ) {  return 0;} 
// int ADDC_R1 ( ) {  return 0;} 
// int ADDC_R2 ( ) {  return 0;} 
// int ADDC_R3 ( ) {  return 0;} 
// int ADDC_R4 ( ) {  return 0;} 
// int ADDC_R5 ( ) {  return 0;} 
// int ADDC_R6 ( ) {  return 0;} 
// int ADDC_R7 ( ) {  return 0;} 	//0x3F
// int JC ( ) {  return 0;} 		//0x40

//0x41
int AJMP_0x41 ( ){ 
	uint16_t low_add_byte = fetch ( );
	CPU_8051.PC = ( ( CPU_8051.PC & 0xF800) | (0x41 & 0x70) ) | low_add_byte;
	return 1;
}	

// int ORL_data_addr_A ( ) {  return 0;} 
// int ORL_data_addr_data ( ) {  return 0;} 
// int ORL_A_data ( ) {  return 0;} 
// int ORL_A_data_addr ( ) {  return 0;} 
// int ORL_acc_at_R0 ( ) {  return 0;} 
// int ORL_acc_at_R1 ( ) {  return 0;} 	//0x47
// int ORL_R0 ( ) {  return 0;} 
// int ORL_R1 ( ) {  return 0;} 
// int ORL_R2 ( ) {  return 0;} 
// int ORL_R3 ( ) {  return 0;} 
// int ORL_R4 ( ) {  return 0;} 
// int ORL_R5 ( ) {  return 0;} 
// int ORL_R6 ( ) {  return 0;} 
// int ORL_R7 ( ) {  return 0;} 		//0x4F
// int JNC ( ) {  return 0;} 		//0x50

//0x51
int ACALL_0x51 ( ) {

	uint16_t push_addr = CPU_8051.PC + 2;
	PUSH (push_addr & 0x00FF); // pushing lower byte
	PUSH ( (push_addr & 0xFF00) >> 8); //have to push it lower by 8 otherwise it will give error.

	// change PC to jmp to subroutine
	uint8_t lower_addr_byte = fetch();
	CPU_8051.PC = ( (CPU_8051.PC & 0xF800) | (0x51 & 0x70) ) | lower_addr_byte;
	return 1; 
	
}
// int ANL_data_addr_A ( ) {  return 0;} 
// int ANL_data_addr_data ( ) {  return 0;} 
// int ANL_A_data ( ) {  return 0;} 
// int ANL_A_data_addr ( ) {  return 0;} 
// int ANL_A_at_R0 ( ) {  return 0;} 
// int ANL_A_at_R1 ( ) {  return 0;} 	//0x57
// int ANL_R0 ( ) {  return 0;} 
// int ANL_R1 ( ) {  return 0;} 
// int ANL_R2 ( ) {  return 0;} 
// int ANL_R3 ( ) {  return 0;} 
// int ANL_R4 ( ) {  return 0;} 
// int ANL_R5 ( ) {  return 0;} 
// int ANL_R6 ( ) {  return 0;} 
// int ANL_R7 ( ) {  return 0;} 		//0x5F
// int JZ ( ) {  return 0;} 		//0x60

//0x61
int AJMP_0x61 ( ) { 
	uint16_t low_add_byte = fetch ( );
	CPU_8051.PC = ( ( CPU_8051.PC & 0xF800) | (0x61 & 0x70) ) | low_add_byte;
	return 1;
}


// int XRL_data_addr_A ( ) {  return 0;} 
// int XRL_data_addr_data ( ) {  return 0;} 
// int XRL_A_data ( ) {  return 0;} 
// int XRL_A_dataaddr ( ) {  return 0;} 
// int XRL_A_at_R0 ( ) {  return 0;} 
// int XRL_A_at_R1 ( ) {  return 0;} 	//0x67
// int XRL_R0 ( ) {  return 0;} 
// int XRL_R1 ( ) {  return 0;} 
// int XRL_R2 ( ) {  return 0;} 
// int XRL_R3 ( ) {  return 0;} 
// int XRL_R4 ( ) {  return 0;} 
// int XRL_R5 ( ) {  return 0;} 
// int XRL_R6 ( ) {  return 0;} 
// int XRL_R7 ( ) {  return 0;} 		//0x6F
// int JNZ ( ) {  return 0;} 		//0x70
//0x71
int ACALL_0x71 ( ) {
	{

	uint16_t push_addr = CPU_8051.PC + 2;
	PUSH (push_addr & 0x00FF); // pushing lower byte
	PUSH ( (push_addr & 0xFF00) >> 8); //have to push it lower by 8 otherwise it will give error.

	// change PC to jmp to subroutine
	uint8_t lower_addr_byte = fetch();
	CPU_8051.PC = ( (CPU_8051.PC & 0xF800) | (0x71 & 0x70) ) | lower_addr_byte;
	return 1; 
	
}
}
// int ORL_C_0x72 ( ) {  return 0;} 
// int JMP_at_A_DPTR ( ) {  return 0;} 
// int MOV_A_data ( ) {  return 0;} 
// int MOV_data_addr_data ( ) {  return 0;} 
// int MOV_at_R0 ( ) {  return 0;} 
// int MOV_at_R1 ( ) {  return 0;} 	//0x77
// int MOV_R0 ( ) {  return 0;} 
// int MOV_R1 ( ) {  return 0;} 
// int MOV_R2 ( ) {  return 0;} 
// int MOV_R3 ( ) {  return 0;} 
// int MOV_R4 ( ) {  return 0;} 
// int MOV_R5 ( ) {  return 0;} 
// int MOV_R6 ( ) {  return 0;} 
// int MOV_R7 ( ) {  return 0;} 		//0x7F

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
}

//0x81
int AJMP_0x81 ( ) { 
	uint16_t low_add_byte = fetch ( );
	CPU_8051.PC = ( ( CPU_8051.PC & 0xF800) | (0x81 & 0x70) ) | low_add_byte;
	return 1;
}		
// int ANL_C_0x82 ( ) {  return 0;} 
// int MOVC ( ) {  return 0;} 
// int DIV ( ) {  return 0;} 
// int MOV_data_addr_data_addr ( ) {  return 0;} 
// int MOV_data_addr_atR0 ( ) {  return 0;} 
// int MOV_data_addr_atR1 ( ) {  return 0;} 	//0x87
// int MOV_data_addr_R0 ( ) {  return 0;} 	
// int MOV_data_addr_R1 ( ) {  return 0;} 
// int MOV_data_addr_R2 ( ) {  return 0;} 
// int MOV_data_addr_R3 ( ) {  return 0;} 
// int MOV_data_addr_R4 ( ) {  return 0;} 
// int MOV_data_addr_R5 ( ) {  return 0;} 
// int MOV_data_addr_R6 ( ) {  return 0;} 
// int MOV_data_addr_R7 ( ) {  return 0;} 	//0x8F
// int MOV_DPTR_data ( ) {  return 0;} 		//0x90
// 0x91
int ACALL_0x91 ( ) {

	uint16_t push_addr = CPU_8051.PC + 2;
	PUSH (push_addr & 0x00FF); // pushing lower byte
	PUSH ( (push_addr & 0xFF00) >> 8); //have to push it lower by 8 otherwise it will give error.

	// change PC to jmp to subroutine
	uint8_t lower_addr_byte = fetch();
	CPU_8051.PC = ( (CPU_8051.PC & 0xF800) | (0x91 & 0x70) ) | lower_addr_byte;
	return 1; 
	
}
// int MOV_bit_C ( ) {  return 0;} 
// int MOVC_A_dptr ( ) {  return 0;} 
// int SUBB_A_data ( ) {  return 0;} 
// int SUBB_A_data_addr ( ) {  return 0;} 
// int SUBB_A_atR0 ( ) {  return 0;} 
// int SUBB_A_atR1 ( ) {  return 0;} 		//0x97
// int SUBB_R0 ( ) {  return 0;} 
// int SUBB_R1 ( ) {  return 0;} 
// int SUBB_R2 ( ) {  return 0;} 
// int SUBB_R3 ( ) {  return 0;} 
// int SUBB_R4 ( ) {  return 0;} 
// int SUBB_R5 ( ) {  return 0;} 
// int SUBB_R6 ( ) {  return 0;}    
// int SUBB_R7 ( ) {  return 0;} 		//0x9F
// int ORL_C_0xA0 ( ) {  return 0;} 			//0xA0

//0xA1
int AJMP_0xA1 ( ) { 
	uint16_t low_add_byte = fetch ( );
	CPU_8051.PC = ( ( CPU_8051.PC & 0xF800) | (0xA1 & 0x70) ) | low_add_byte;
	return 1;
}
// int MOV_C ( ) {  return 0;} 
// int INC_dptr ( ) {  return 0;} 
// int MUL ( ) {  return 0;} 
//reserved
// int MOV_atR0_data_addr ( ) {  return 0;} 
// int MOV_atR1_data_addr ( ) {  return 0;} 	//0xA7
// int R0_data_addr ( ) {  return 0;} 
// int R1_data_addr ( ) {  return 0;} 
// int R2_data_addr ( ) {  return 0;} 
// int R3_data_addr ( ) {  return 0;} 
// int R4_data_addr ( ) {  return 0;} 
// int R5_data_addr ( ) {  return 0;} 
// int R6_data_addr ( ) {  return 0;} 
// int R7_data_addr ( ) {  return 0;} 		//0xAF
// int ANL_C_0xB0 ( ) {  return 0;} 			//0xB0

//0xB1
int ACALL_0xB1 ( ){

	uint16_t push_addr = CPU_8051.PC + 2;
	PUSH (push_addr & 0x00FF); // pushing lower byte
	PUSH ( (push_addr & 0xFF00) >> 8); //have to push it lower by 8 otherwise it will give error.

	// change PC to jmp to subroutine
	uint8_t lower_addr_byte = fetch();
	CPU_8051.PC = ( (CPU_8051.PC & 0xF800) | (0xB1 & 0x70) ) | lower_addr_byte;
	return 1; 
	
}
// int CPL ();
// int CPL_C ();
// int CJNE_A_data_codeaddr ( ) {  return 0;} 
// int CJNE_A_data_addr_codeaddr ( ) {  return 0;} 
// int CJNE_atR0_data_codeaddr ( ) {  return 0;} 
// int CJNE_atR1_data_codeaddr ( ) {  return 0;} 	//0xB7
// int CJNE_R0 ( ) {  return 0;} 
// int CJNE_R1 ( ) {  return 0;} 
// int CJNE_R2 ( ) {  return 0;} 
// int CJNE_R3 ( ) {  return 0;} 
// int CJNE_R4 ( ) {  return 0;} 
// int CJNE_R5 ( ) {  return 0;} 
// int CJNE_R6 ( ) {  return 0;} 
// int CJNE_R7 ( ) {  return 0;} 		//0xBF
// int PUSH (int8_t data) {
// 	return 0;
// }			

//0xC1
int AJMP_0xC1 ( ) { 
	uint16_t low_add_byte = fetch ( );
	CPU_8051.PC = ( ( CPU_8051.PC & 0xF800) | (0xC1 & 0x70) ) | low_add_byte;
	return 1;
}
// int CLR ( ) {  return 0;} 
// int CLR_C ();
// int SWAP ( ) {  return 0;} 
// int XCH_A_dataaddr ( ) {  return 0;} 
// int XCH_A_atR0 ( ) {  return 0;} 
// int XCH_A_at_R1 ( ) {  return 0;} 		//0xC7
// int XCH_A_R0 ( ) {  return 0;} 
// int XCH_A_R1 ( ) {  return 0;} 
// int XCH_A_R2 ( ) {  return 0;} 
// int XCH_A_R3 ( ) {  return 0;} 
// int XCH_A_R4 ( ) {  return 0;} 
// int XCH_A_R5 ( ) {  return 0;} 
// int XCH_A_R6 ( ) {  return 0;} 
// int XCH_A_R7 ( ) {  return 0;} 		//0xCF
// int POP ( ) {  return 0;} 			//0xD0
//0xD1
int ACALL_0xD1 ( ) {

	uint16_t push_addr = CPU_8051.PC + 2;
	PUSH (push_addr & 0x00FF); // pushing lower byte
	PUSH ( (push_addr & 0xFF00) >> 8); //have to push it lower by 8 otherwise it will give error.

	// change PC to jmp to subroutine
	uint8_t lower_addr_byte = fetch();
	CPU_8051.PC = ( (CPU_8051.PC & 0xF800) | (0xD1 & 0x70) ) | lower_addr_byte;
	return 1; 
	
}
// int SETB ( ) {  return 0;} 
// int SETB_C ( ) {  return 0;} 
// int DA ( ) {  return 0;} 
// int DJNZ ( ) {  return 0;} 
// int XCHD_A_at_R0 ( ) {  return 0;} 
// int XCHD_A_at_R1 ( ) {  return 0;} 		//0xD7
// int DJNZ_R0 ( ) {  return 0;} 	
// int DJNZ_R1 ( ) {  return 0;} 
// int DJNZ_R2 ( ) {  return 0;} 
// int DJNZ_R3 ( ) {  return 0;} 
// int DJNZ_R4 ( ) {  return 0;} 
// int DJNZ_R5 ( ) {  return 0;} 
// int DJNZ_R6 ( ) {  return 0;} 
// int DJNZ_R7 ( ) {  return 0;} 		//0xDF
// int MOVX_at_DPTR ( ) {  return 0;} 		//0xE0

//0xE1
int AJMP_0xE1 ( ) { 
	uint16_t low_add_byte = fetch ( );
	CPU_8051.PC = ( ( CPU_8051.PC & 0xF800) | (0xE1 & 0x70) ) | low_add_byte;
	return 1;
}
// int MOVX_A_at_R0 ( ) {  return 0;} 
// int MOVX_A_at_R1 ( ) {  return 0;} 
// int CLR_A ();
// int MOV_A_dataaddr ();
// int MOV_A_at_R0 ( ) {  return 0;} 
// int MOV_A_at_R1 ( ) {  return 0;} 		//0xE7
// int MOV_A_R0 ( ) {  return 0;} 
// int MOV_A_R1 ( ) {  return 0;} 
// int MOV_A_R2 ( ) {  return 0;} 
// int MOV_A_R3 ( ) {  return 0;} 
// int MOV_A_R4 ( ) {  return 0;} 
// int MOV_A_R5 ( ) {  return 0;} 
// int MOV_A_R6 ( ) {  return 0;} 
// int MOV_A_R7 ( ) {  return 0;} 		//0xEF
// int MOVX_at_DPTR_A ( ) {  return 0;} 		//0xF0
//0xF1
int ACALL_0xF1 ( ) {

	uint16_t push_addr = CPU_8051.PC + 2;
	PUSH (push_addr & 0x00FF); // pushing lower byte
	PUSH ( (push_addr & 0xFF00) >> 8); //have to push it lower by 8 otherwise it will give error.

	// change PC to jmp to subroutine
	uint8_t lower_addr_byte = fetch();
	CPU_8051.PC = ( (CPU_8051.PC & 0xF800) | (0xF1 & 0x70) ) | lower_addr_byte;
	return 1; 
	
}
// int MOVX_at_R0_A ( ) {  return 0;} 
// int MOVX_at_R1_A ( ) {  return 0;} 
// int CPL_A ( ) {  return 0;} 
// int MOV_data_addr_A ( ) {  return 0;} 
// int MOV_at_R0_A ( ) {  return 0;} 
// int MOV_at_R1_A ( ) {  return 0;} 		//0xF7
// int MOV_R0_A ( ) {  return 0;} 
// int MOV_R1_A ( ) {  return 0;} 
// int MOV_R2_A ( ) {  return 0;} 
// int MOV_R3_A ( ) {  return 0;} 
// int MOV_R4_A ( ) {  return 0;} 
// int MOV_R5_A ( ) {  return 0;} 
// int MOV_R6_A ( ) {  return 0;} 
// int MOV_R7_A ( ) {  return 0;} 		//0xFF
