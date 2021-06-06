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


void update_CY ( uint8_t val) {
	
	if (val)	// if we need to make carry 1
	{
		CPU_8051.SFR[PSW] |= CY;
	}
	else 		// if carry need to be zero
	{
		CPU_8051.SFR[PSW] &= ~(CY);
	}
}

void update_AC ( uint8_t val) {
	
	if (val)	// if we need to make carry 1
	{
		CPU_8051.SFR[PSW] |= AC;
	}
	else 		// if carry need to be zero
	{
		CPU_8051.SFR[PSW] &= ~(AC);
	}
}

void update_OV ( uint8_t val) {
	
	if (val)	// if we need to make carry 1
	{
		CPU_8051.SFR[PSW] |= OV;
	}
	else 		// if carry need to be zero
	{
		CPU_8051.SFR[PSW] &= ~(OV);
	}
}

int8_t add (int8_t op1, int8_t op2) {
	char cy, ov, aux, tmp, result;
	cy = ov = aux = result = tmp = 0;

	// doing binary addition
	for ( int i = 0; i < 8; i++, tmp = 0) {

		tmp = (( (op1 & (1 << i)) + ( op2 & (1 << i))) >> i) + cy;
		
		switch (tmp)
		{	
		case 0:
			cy = 0;
			result |= (tmp << i);
			break;
		
		case 1:
			cy = 0;
			result |= (tmp << i);
			break;
		
		case 2:
			cy = 1;
			result &= ~(1 << i);
			break;
		
		case 3:
			cy = 1;
			result |= (1 << i);
			break;
		
		default:
			break;
		}

		if ( i == 4 && cy == 1)	aux = 1;
		if ( i == 6 && cy == 1) ov = 1;
	}

	if ( ov != cy)	ov = 1;
	else ov = 0;

	update_AC (aux);
	update_CY (cy);
	update_OV (ov);
	update_parity ( );
	
	return result;
}

int8_t addc (int8_t op1, int8_t op2) {
	char cy, ov, aux, tmp, result;
	ov = aux = result = tmp = 0;
	cy = (CPU_8051.SFR[PSW] & CY )? 1 : 0;

	// doing binary addition
	for ( int i = 0; i < 8; i++, tmp = 0) {

		tmp = (( (op1 & (1 << i)) + ( op2 & (1 << i))) >> i) + cy;
		
		switch (tmp)
		{	
		case 0:
			cy = 0;
			result |= (tmp << i);
			break;
		
		case 1:
			cy = 0;
			result |= (tmp << i);
			break;
		
		case 2:
			cy = 1;
			result &= ~(1 << i);
			break;
		
		case 3:
			cy = 1;
			result |= (1 << i);
			break;
		
		default:
			break;
		}

		if ( i == 4 && cy == 1)	aux = 1;
		if ( i == 6 && cy == 1) ov = 1;
	}

	if ( ov != cy)	ov = 1;
	else ov = 0;

	update_AC (aux);
	update_CY (cy);
	update_OV (ov);
	update_parity ( );
	
	return result;
}


int8_t subb ( int8_t op1, int8_t op2) {

	char b, ov, aux, tmp, result;
	ov = aux = result = tmp = 0;
	b = (CPU_8051.SFR[PSW] & CY )? 1 : 0;

	// doing binary addition
	for ( int i = 0; i < 8; i++, tmp = 0) {

		tmp = b - (( (op1 & (1 << i)) - ( op2 & (1 << i))) >> i);
		
		switch (tmp)
		{	
		case 0:
			b = 0;
			break;
		
		case -1:
			b = 1;
			break;
		
		case 1:
			b = 0;
			result |= (1 << i);
			break;
		
		default:
			break;
		}

		if ( i == 4 && b == 1)	aux = 1;
		if ( i == 6 && b == 1) ov = 1;
	}

	if ( ov != b)	ov = 1;
	else ov = 0;

	update_AC (aux);
	update_CY (b);
	update_OV (ov);
	update_parity ( );
	
	return result;

}


void show_memory ( ) {
	
	char *pntr = &CPU_8051;
	char tmp[2];
	
	// printing the upper line of refrence 
	for ( int i = 0; i < 16; i++) printf ("\t %x",i);
	printf ("\n");
	for ( int i = 0; i < 130; i++) printf ("-");

	// printing the memory locations
	for ( int i = 0 ; i < 8 ; i++) {
		printf("\n%4x", i);
		
		for (int j = 0; j < 16 ; j++) {
			
			tmp[0] = *(pntr + j + (i * 0xF));
			tmp[1] = *(pntr + j + (i * 0xF));

			printf ("\t%hhx",tmp[0]);
		}
	}
	printf ("\n");
}

/** will resolve the bit addresses,
 * still need to be expaneded if register which are bit
 * addressable are given,
 * right now works only for bit addressable area of CPU
 */
int resolve_bit_addr (uint8_t bit_addr) {
	uint8_t byte = CPU_8051.Bit_Addressable[bit_addr / 8];
	uint8_t bit = byte & ( 1 < ((bit_addr % 8) + 1) );

	if (bit) return 1;
	else return 0;
}


/*------------------------------------------------------------------------------------------------------------------------*/


/*----------------------------------------------CPU Instructions----------------------------------------------------------*/

/** 
 * here we take unique approach
 * and try to push data using address of 
 * CPU structure, typecasting it.
 */
int PUSH (int8_t data) {
	
	*(((char*)&CPU_8051) + CPU_8051.SFR[SP]) = data;
	CPU_8051.SFR[SP] += 1;
	return 1;

}	

int8_t POP ( ) {

	int8_t data;
	CPU_8051.SFR[SP] -= 1;
	data = *(((char*)&CPU_8051) + CPU_8051.SFR[SP]);
	return data;
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
	return 1;
} 

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
		return 1;
	}
	else {
		return 1;
	}
}

//0x21
int AJMP_0x21 ( ) { 
	uint16_t low_add_byte = fetch ( );
	CPU_8051.PC = ( ( CPU_8051.PC & 0xF800) | (0x21 & 0x70) ) | low_add_byte;
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
	return 0;
	
	
} 

/** 
 * 0x23
 * RL : Rotate Accumulator Left
 * 1 byte instruction
 */	
int RL ( ) {
	uint8_t acc_msb = CPU_8051.SFR[ACC] & ( 1 << 8 );
	CPU_8051.SFR[ACC] << 1;

	if (acc_msb)	// if MSB of ACC was 1 before rotate, make LSB 1
	{
		CPU_8051.SFR[ACC] |= ( 1 << 1);
	}
	else {
		CPU_8051.SFR[ACC] &= ~( 1 << 1);
	}
	return 1;
}

/** 0x24
 * ADD A, data : add immmediate data to the accumulator
 * 2 byte instruction,
 */
int ADD_data ( ) {
	
	CPU_8051.SFR[ACC] = add (CPU_8051.SFR[ACC] , fetch ( ));
	

	return 1;
}

int ADD_data_addr ( ) {
	
	uint8_t addr = fetch ( );
	int8_t data = *( (char*)&CPU_8051 + addr );

	CPU_8051.SFR[ACC] = add (CPU_8051.SFR[ACC], data);
	return 1;
}

int ADD_at_R0 ( ) {

	uint8_t addr = CPU_8051.REGISTERS[BANK].R0;
	int8_t data = *( (char*)&CPU_8051 + addr);

	CPU_8051.SFR[ACC] = add ( CPU_8051.SFR[ACC], data);
	return 1;

} 

// 0x27
int ADD_at_R1 ( ) { 

	uint8_t addr = CPU_8051.REGISTERS[BANK].R1;
	int8_t data = *( (char*)&CPU_8051 + addr);

	CPU_8051.SFR[ACC] = add ( CPU_8051.SFR[ACC], data);
	return 1;

} 

/** 0x28
 * ADD A, R0
 * 
 * add data from R0 to accumulator
 */
int ADD_R0 ( ) {

	int8_t data = CPU_8051.REGISTERS[BANK].R0;
	CPU_8051.SFR[ACC] = add ( CPU_8051.SFR[ACC], data);
	return 0;
}

/** 0x29
 * ADD A, R1
 * 
 * add data from R1 to accumulator
 */
int ADD_R1 ( ) {

	int8_t data = CPU_8051.REGISTERS[BANK].R1;
	CPU_8051.SFR[ACC] = add ( CPU_8051.SFR[ACC], data);
	return 0;

}

/** 0x2A
 * ADD A, R2
 * 
 * add data from R2 to accumulator
 */
int ADD_R2 ( ) {

	int8_t data = CPU_8051.REGISTERS[BANK].R2;
	CPU_8051.SFR[ACC] = add ( CPU_8051.SFR[ACC], data);
	return 0;

}

/** 0x2B
 * ADD A, R3
 * 
 * add data from R3 to accumulator
 */
int ADD_R3 ( ) {

	int8_t data = CPU_8051.REGISTERS[BANK].R3;
	CPU_8051.SFR[ACC] = add ( CPU_8051.SFR[ACC], data);
	return 0;

}

/** 0x2C
 * ADD A, R4
 * 
 * add data from R4 to accumulator
 */
int ADD_R4 ( ) {

	int8_t data = CPU_8051.REGISTERS[BANK].R4;
	CPU_8051.SFR[ACC] = add ( CPU_8051.SFR[ACC], data);
	return 0;

}

/** 0x2D
 * ADD A, R5
 * 
 * add data from R5 to accumulator
 */
int ADD_R5 ( ) {

	int8_t data = CPU_8051.REGISTERS[BANK].R5;
	CPU_8051.SFR[ACC] = add ( CPU_8051.SFR[ACC], data);
	return 0;

}

/** 0x2E
 * ADD A, R6
 * 
 * add data from R6 to accumulator
 */
int ADD_R6 ( ) {

	int8_t data = CPU_8051.REGISTERS[BANK].R6;
	CPU_8051.SFR[ACC] = add ( CPU_8051.SFR[ACC], data);
	return 0;

}

/** 0x2F
 * ADD A, R7
 * 
 * add data from R7 to accumulator
 */
int ADD_R7 ( ) {

	int8_t data = CPU_8051.REGISTERS[BANK].R7;
	CPU_8051.SFR[ACC] = add ( CPU_8051.SFR[ACC], data);
	return 0;

}

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

/** 0x40
 * RETI : Return from Interrupt
 * REstoring the previous interrupt mask part is yet to 
 * program
 */
int RETI ( ) {

	uint8_t high_addr = POP ( );
	uint8_t low_addr = pop ( );

	CPU_8051.PC = ((high_addr << 8) | low_addr );
	return 1;

}


/** 0x41
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
}

/** 0x41
 * ADDC A, imm_data : Add with carry the immediate data in accumulator
 * 2 byte instruction
 * 
 * here OV flag is set
 */
int ADDC_data ( ) {

	int8_t data = fetch ( );
	CPU_8051.SFR[ACC] = addc ( CPU_8051.SFR[ACC], data);
	return 1;
} 

int ADDC_data_addr ( ) {  

	uint8_t addr = fetch ( );
	int8_t data = *( (char*)&CPU_8051 + addr);
	CPU_8051.SFR[ACC] = addc ( CPU_8051.SFR[ACC], data);
	return 1;

} 

int ADDC_at_R0 ( ) {  

	uint8_t addr = CPU_8051.REGISTERS[BANK].R0;
	int8_t data = *( (char*)&CPU_8051 + addr);
	CPU_8051.SFR[ACC] = addc ( CPU_8051.SFR[ACC], data);
	return 1;
	
} 
// 0x37 
int ADDC_at_R1 ( ) { 

	uint8_t addr = CPU_8051.REGISTERS[BANK].R1;
	int8_t data = *( (char*)&CPU_8051 + addr);
	CPU_8051.SFR[ACC] = addc ( CPU_8051.SFR[ACC], data);
	return 1;

}

int ADDC_R0 ( ) {  

	int8_t data = CPU_8051.REGISTERS[BANK].R0;
	CPU_8051.SFR[ACC] = addc ( CPU_8051.SFR[ACC], data);
	return 1;

} 

int ADDC_R1 ( ) {  

	int8_t data = CPU_8051.REGISTERS[BANK].R1;
	CPU_8051.SFR[ACC] = addc ( CPU_8051.SFR[ACC], data);
	return 1;

} 

int ADDC_R2 ( ) {  

	int8_t data = CPU_8051.REGISTERS[BANK].R2;
	CPU_8051.SFR[ACC] = addc ( CPU_8051.SFR[ACC], data);
	return 1;

} 

int ADDC_R3 ( ) {  

	int8_t data = CPU_8051.REGISTERS[BANK].R3;
	CPU_8051.SFR[ACC] = addc ( CPU_8051.SFR[ACC], data);
	return 1;

}

int ADDC_R4 ( ) {  

	int8_t data = CPU_8051.REGISTERS[BANK].R4;
	CPU_8051.SFR[ACC] = addc ( CPU_8051.SFR[ACC], data);
	return 1;

} 

int ADDC_R5 ( ) {  

	int8_t data = CPU_8051.REGISTERS[BANK].R5;
	CPU_8051.SFR[ACC] = addc ( CPU_8051.SFR[ACC], data);
	return 1;

} 

int ADDC_R6 ( ) {  

	int8_t data = CPU_8051.REGISTERS[BANK].R6;
	CPU_8051.SFR[ACC] = addc ( CPU_8051.SFR[ACC], data);
	return 1;

} 

//0x3F
int ADDC_R7 ( ) {  

	int8_t data = CPU_8051.REGISTERS[BANK].R7;
	CPU_8051.SFR[ACC] = addc ( CPU_8051.SFR[ACC], data);
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
	return 1;

}

//0x41
int AJMP_0x41 ( ){ 
	uint16_t low_add_byte = fetch ( );
	CPU_8051.PC = ( ( CPU_8051.PC & 0xF800) | (0x41 & 0x70) ) | low_add_byte;
	return 1;
}	

int ORL_data_addr_A ( ) {

	uint8_t addr = fetch ( );
	int8_t data = *( (char*)&CPU_8051 + addr );
	data |= CPU_8051.SFR[ACC];
	*( (char*)&CPU_8051 + addr ) = data;
	return 1;

} 


int ORL_data_addr_data ( ) {

	uint8_t addr = fetch ( );
	int8_t data = *( (char*)&CPU_8051 + addr );
	data &= fetch ( );
	*( (char*)&CPU_8051 + addr ) = data;
	return 1;

} 


/** ORL A, #data
 * 2 byte instruction
 */
int ORL_A_data ( ) {
	int8_t data = fetch ( );
	CPU_8051.SFR[ACC] |= data;
	return 1;
} 

int ORL_A_data_addr ( ) {

	uint8_t addr = fetch ( );
	int8_t data = *( (char*)&CPU_8051 + addr );
	CPU_8051.SFR[ACC] |= data;
	return 1;

}


int ORL_A_at_R0 ( ) {

	uint8_t addr = CPU_8051.REGISTERS[BANK].R0;
	int8_t data = *( (char*)&CPU_8051 + addr );
	CPU_8051.SFR[ACC] |= data;
	return 1;

} 

// 0x47
int ORL_A_at_R1 ( ) {

	uint8_t addr = CPU_8051.REGISTERS[BANK].R1;
	int8_t data = *( (char*)&CPU_8051 + addr );
	CPU_8051.SFR[ACC] |= data;
	return 1;
	
} 

/** 0x48 
 * ORL A, R0
 */
int ORL_R0 ( ) { 

	CPU_8051.SFR[ACC] |= CPU_8051.REGISTERS[BANK].R0;
	return 1;

} 

int ORL_R1 ( ) { 
	CPU_8051.SFR[ACC] |= CPU_8051.REGISTERS[BANK].R1;
	return 1;
}  

int ORL_R2 ( ) { 
	CPU_8051.SFR[ACC] |= CPU_8051.REGISTERS[BANK].R2;
	return 1;
} 

int ORL_R3 ( ) { 
	CPU_8051.SFR[ACC] |= CPU_8051.REGISTERS[BANK].R3;
	return 1;
}  

int ORL_R4 ( ) { 
	CPU_8051.SFR[ACC] |= CPU_8051.REGISTERS[BANK].R4;
	return 1;
} 

int ORL_R5 ( ) { 
	CPU_8051.SFR[ACC] |= CPU_8051.REGISTERS[BANK].R5;
	return 1;
} 


int ORL_R6 ( ) { 
	CPU_8051.SFR[ACC] |= CPU_8051.REGISTERS[BANK].R6;
	return 1;
} 

int ORL_R7 ( ) { 
	CPU_8051.SFR[ACC] |= CPU_8051.REGISTERS[BANK].R7;
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
		CPU_8051.PC += addr + 1;	
	}
}

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

int ANL_data_addr_A ( ) {

	uint8_t addr = fetch ( );
	int8_t data = *( (char*)&CPU_8051 + addr );
	data &= CPU_8051.SFR[ACC];
	*( (char*)&CPU_8051 + addr ) = data;
	return 1;

} 

int ANL_data_addr_data ( ) {

	uint8_t addr = fetch ( );
	int8_t data = *( (char*)&CPU_8051 + addr );
	data &= fetch ( );
	*( (char*)&CPU_8051 + addr ) = data;
	return 1;

} 

/** 0x54
 * ANL A, # Data
 */
int ANL_A_data ( ) { 

	int8_t data = fetch ( );
	CPU_8051.SFR[ACC] &= data;
	return 1;

}  

int ANL_A_data_addr ( ) {

	uint8_t addr = fetch ( );
	int8_t data = *( (char*)&CPU_8051 + addr );
	CPU_8051.SFR[ACC] &= data;
	return 1;

}

int ANL_A_at_R0 ( ) {

	uint8_t addr = CPU_8051.REGISTERS[BANK].R0;
	int8_t data = *( (char*)&CPU_8051 + addr );
	CPU_8051.SFR[ACC] &= data;
	return 1;

}

// 0x57
int ANL_A_at_R1 ( ) {

	uint8_t addr = CPU_8051.REGISTERS[BANK].R1;
	int8_t data = *( (char*)&CPU_8051 + addr );
	CPU_8051.SFR[ACC] &= data;
	return 1;

}


int ANL_R0 ( ) { 

	CPU_8051.SFR[ACC] &= CPU_8051.REGISTERS[BANK].R0;
	return 1;

}  

int ANL_R1 ( ) { 

	CPU_8051.SFR[ACC] &= CPU_8051.REGISTERS[BANK].R1;
	return 1;

}  

int ANL_R2 ( ) { 

	CPU_8051.SFR[ACC] &= CPU_8051.REGISTERS[BANK].R2;
	return 1;

}   

int ANL_R3 ( ) { 

	CPU_8051.SFR[ACC] &= CPU_8051.REGISTERS[BANK].R3;
	return 1;

}  

int ANL_R4 ( ) { 

	CPU_8051.SFR[ACC] &= CPU_8051.REGISTERS[BANK].R4;
	return 1;

}  

int ANL_R5 ( ) { 

	CPU_8051.SFR[ACC] &= CPU_8051.REGISTERS[BANK].R5;
	return 1;

}  

int ANL_R6 ( ) { 

	CPU_8051.SFR[ACC] &= CPU_8051.REGISTERS[BANK].R6;
	return 1;

}  

int ANL_R7 ( ) { 

	CPU_8051.SFR[ACC] &= CPU_8051.REGISTERS[BANK].R7;
	return 1;

}  
/** 0x60
 * jump is accumulator is zero
 */
int JZ ( ) {

	int8_t addr = fetch ( );
	if (!CPU_8051.SFR[ACC]) CPU_8051.PC += addr;
	return 1;

}

//0x61
int AJMP_0x61 ( ) { 
	uint16_t low_add_byte = fetch ( );
	CPU_8051.PC = ( ( CPU_8051.PC & 0xF800) | (0x61 & 0x70) ) | low_add_byte;
	return 1;
}


int XRL_data_addr_A ( ) {

	uint8_t addr = fetch ( );
	int8_t data = *( (char*)&CPU_8051 + addr );
	data &= CPU_8051.SFR[ACC];
	*( (char*)&CPU_8051 + addr) = data;
	return 1;

}

int XRL_data_addr_data ( ) {

		uint8_t addr = fetch ( );
		int8_t data = *( (char*)&CPU_8051 + addr );
		int8_t op2 = fetch ( );
		data &= op2;
		*( (char*)&CPU_8051 + addr ) = data;
		return 1;

} 

/** 
 * XRL A, #data
 * Xor operation
 */
int XRL_A_data ( ) {
	
	int8_t data = fetch ( );
	CPU_8051.SFR[ACC] ^= data;
	return 1;

} 

int XRL_A_dataaddr ( ) {

	uint8_t addr = fetch ( );
	int8_t data = *( (char*)&CPU_8051 + addr );
	CPU_8051.SFR[ACC] &= data;
	return 1;

}

int XRL_A_at_R0 ( ) {

	uint8_t addr = CPU_8051.REGISTERS[BANK].R0;
	int8_t data = *( (char*)&CPU_8051 + addr );
	CPU_8051.SFR[ACC] &= data;
	return 1;

}

// 0x67
int XRL_A_at_R1 ( ) {

	uint8_t addr = CPU_8051.REGISTERS[BANK].R1;
	int8_t data = *( (char*)&CPU_8051 + addr );
	CPU_8051.SFR[ACC] &= data;
	return 1;

}


int XRL_R0 ( ) { 

	CPU_8051.SFR[ACC] ^= CPU_8051.REGISTERS[BANK].R0;
	return 1;

}   

int XRL_R1 ( ) { 

	CPU_8051.SFR[ACC] ^= CPU_8051.REGISTERS[BANK].R1;
	return 1;

}   

int XRL_R2 ( ) { 

	CPU_8051.SFR[ACC] ^= CPU_8051.REGISTERS[BANK].R2;
	return 1;

}   

int XRL_R3 ( ) { 

	CPU_8051.SFR[ACC] ^= CPU_8051.REGISTERS[BANK].R3;
	return 1;

}   

int XRL_R4 ( ) { 

	CPU_8051.SFR[ACC] ^= CPU_8051.REGISTERS[BANK].R4;
	return 1;

}   

int XRL_R5 ( ) { 

	CPU_8051.SFR[ACC] ^= CPU_8051.REGISTERS[BANK].R5;
	return 1;

}   

int XRL_R6 ( ) { 

	CPU_8051.SFR[ACC] ^= CPU_8051.REGISTERS[BANK].R6;
	return 1;

}   

int XRL_R7 ( ) { 

	CPU_8051.SFR[ACC] ^= CPU_8051.REGISTERS[BANK].R7;
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
	return 1;

}

//0x71
int ACALL_0x71 ( ) {
	
	uint16_t push_addr = CPU_8051.PC + 2;
	PUSH (push_addr & 0x00FF); // pushing lower byte
	PUSH ( (push_addr & 0xFF00) >> 8); //have to push it lower by 8 otherwise it will give error.

	// change PC to jmp to subroutine
	uint8_t lower_addr_byte = fetch();
	CPU_8051.PC = ( (CPU_8051.PC & 0xF800) | (0x71 & 0x70) ) | lower_addr_byte;
	return 1; 
	
}

// 0x72
int ORL_C_0x72 ( ) {

	int8_t val = CPU_8051.SFR[PSW];
	val &= CY;
	if (val) CPU_8051.SFR[PSW] |= CY;
	return 1;

}

//0x73
int JMP_at_A_DPTR ( ) {

	uint16_t dptr_data = ( (CPU_8051.SFR[DPH] << 8) | CPU_8051.SFR[DPL] );
	dptr_data += CPU_8051.SFR[ACC];
	CPU_8051.PC = dptr_data;
	return 1;

}

/** 0x74
 * MOV A, #data;
 * 2 byte instruction
 */
int MOV_A_data ( ) {

	CPU_8051.SFR[ACC] = fetch ( );
	return 1;
}

int MOV_data_addr_data ( ) {

	uint8_t addr = fetch ( );
	int8_t data = fetch ( );
	*( (char*)&CPU_8051 + addr ) = data;
	return 1;

}

int MOV_at_R0 ( ) {

	int8_t data = fetch ( );
	uint8_t addr = CPU_8051.REGISTERS[BANK].R0;
	*( (char*)&CPU_8051 + addr ) = data;
	return 1;

}

//0x77
int MOV_at_R1 ( ) {

	int8_t data = fetch ( );
	uint8_t addr = CPU_8051.REGISTERS[BANK].R1;
	*( (char*)&CPU_8051 + addr ) = data;
	return 1;
	
}

int MOV_R0 ( ) {
	
	CPU_8051.REGISTERS[BANK].R0 = fetch ( );
	return 1;

}

int MOV_R1 ( ) {

	CPU_8051.REGISTERS[BANK].R1 = fetch ( );	
	return 1;

}

int MOV_R2 ( ) {
	
	CPU_8051.REGISTERS[BANK].R2 = fetch ( );	
	return 1;

}


int MOV_R3 ( ) {
	
	CPU_8051.REGISTERS[BANK].R3 = fetch ( );	
	return 1;

}


int MOV_R4 ( ) {
	
	CPU_8051.REGISTERS[BANK].R4 = fetch ( );	
	return 1;

}


int MOV_R5 ( ) {

	CPU_8051.REGISTERS[BANK].R5 = fetch ( );		
	return 1;

}


int MOV_R6 ( ) {
	
	CPU_8051.REGISTERS[BANK].R6 = fetch ( );	
	return 1;

}


int MOV_R7 ( ) {
	
	CPU_8051.REGISTERS[BANK].R7 = fetch ( );	
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
}

//0x81
int AJMP_0x81 ( ) { 
	uint16_t low_add_byte = fetch ( );
	CPU_8051.PC = ( ( CPU_8051.PC & 0xF800) | (0x81 & 0x70) ) | low_add_byte;
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
	return 1;

}

/**
 * MOVC A, @A+PC
 * mov code byte
 */
int MOVC ( ) {

	uint8_t addr1 = CPU_8051.SFR[ACC];
	uint16_t pc = pc;
	pc += addr1;
	CPU_8051.SFR[ACC] = CPU_8051.Code_Memory[pc];
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
	quotient = CPU_8051.SFR[ACC] / CPU_8051.SFR[B];
	remainder = CPU_8051.SFR[ACC] % CPU_8051.SFR[B];
	CPU_8051.SFR[ACC] = quotient;
	CPU_8051.SFR[B] = remainder;
	return 1;

}


int MOV_data_addr_data_addr ( ) {

	uint8_t dest_addr = fetch ( );
	uint8_t sour_addr = fetch ( );
	int8_t data = *( (char*)&CPU_8051 + sour_addr );
	*( (char*)&CPU_8051 + dest_addr ) = data;
	return 1;

}

int MOV_data_addr_atR0 ( ) {

	uint8_t dest_addr = fetch ( );
	uint8_t sour_addr = CPU_8051.REGISTERS[BANK].R0;
	int8_t data = *( (char*)&CPU_8051 + sour_addr );
	*( (char*)&CPU_8051 + dest_addr ) = data;
	return 1;

}

// 0x87
int MOV_data_addr_atR1 ( ) {

	uint8_t dest_addr = fetch ( );
	uint8_t sour_addr = CPU_8051.REGISTERS[BANK].R1;
	int8_t data = *( (char*)&CPU_8051 + sour_addr );
	*( (char*)&CPU_8051 + dest_addr ) = data;
	return 1;

}

int MOV_data_addr_R0 ( ) {

	uint8_t dest_addr = fetch ( );
	int8_t data = CPU_8051.REGISTERS[BANK].R0;
	*( (char*)&CPU_8051 + dest_addr ) = data;
	return 1;

}

int MOV_data_addr_R1 ( ) {

	uint8_t dest_addr = fetch ( );
	int8_t data = CPU_8051.REGISTERS[BANK].R1;
	*( (char*)&CPU_8051 + dest_addr ) = data;
	return 1;

}

int MOV_data_addr_R2 ( ) {

	uint8_t dest_addr = fetch ( );
	int8_t data = CPU_8051.REGISTERS[BANK].R2;
	*( (char*)&CPU_8051 + dest_addr ) = data;
	return 1;

}

int MOV_data_addr_R3 ( ) {

	uint8_t dest_addr = fetch ( );
	int8_t data = CPU_8051.REGISTERS[BANK].R3;
	*( (char*)&CPU_8051 + dest_addr ) = data;
	return 1;

}

int MOV_data_addr_R4 ( ) {

	uint8_t dest_addr = fetch ( );
	int8_t data = CPU_8051.REGISTERS[BANK].R4;
	*( (char*)&CPU_8051 + dest_addr ) = data;
	return 1;

}

int MOV_data_addr_R5 ( ) {

	uint8_t dest_addr = fetch ( );
	int8_t data = CPU_8051.REGISTERS[BANK].R5;
	*( (char*)&CPU_8051 + dest_addr ) = data;
	return 1;

}

int MOV_data_addr_R6 ( ) {

	uint8_t dest_addr = fetch ( );
	int8_t data = CPU_8051.REGISTERS[BANK].R6;
	*( (char*)&CPU_8051 + dest_addr ) = data;
	return 1;

}

//0x8F
int MOV_data_addr_R7 ( ) {

	uint8_t dest_addr = fetch ( );
	int8_t data = CPU_8051.REGISTERS[BANK].R0;
	*( (char*)&CPU_8051 + dest_addr ) = data;
	return 1;

}

// 0x90
int MOV_DPTR_data ( ) {

	CPU_8051.SFR[DPH] = fetch ( );
	CPU_8051.SFR[DPL] = fetch ( );
	return 1;

}

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

	return 1;
} 

int MOVC_A_dptr ( ) {

	uint16_t addr = ( (CPU_8051.SFR[DPH] << 8) | CPU_8051.SFR[DPL] );
	addr += CPU_8051.SFR[ACC];
	CPU_8051.SFR[ACC] = CPU_8051.Code_Memory[addr];
	return 1;

}
// SUBB A, #data
int SUBB_A_data ( ) {

	int8_t data = fetch ( );
	CPU_8051.SFR[ACC] = subb (CPU_8051.SFR[ACC], data);
	return 1;

} 

// SUBB A, @data_addr
int SUBB_A_data_addr ( ) {  
	
	uint8_t addr = fetch ( );
	int8_t data = *( (char*)&CPU_8051 + addr );
	CPU_8051.SFR[ACC] = subb (CPU_8051.SFR[ACC], data);
	return 1;

} 

// SUBB A, @R0
int SUBB_A_atR0 ( ) {  
	
	uint8_t addr = CPU_8051.REGISTERS[BANK].R0;
	int8_t data = *( (char*)&CPU_8051 + addr );
	CPU_8051.SFR[ACC] = subb (CPU_8051.SFR[ACC], data);
	return 1;
 
} 

//0x97
// SUBB A, @R1
int SUBB_A_atR1 ( ) {
 
	uint8_t addr = CPU_8051.REGISTERS[BANK].R0;
	int8_t data = *( (char*)&CPU_8051 + addr );
	CPU_8051.SFR[ACC] = subb (CPU_8051.SFR[ACC], data);
	return 1;
  
}

// SUBB A, R0
int SUBB_R0 ( ) {  
	
	int8_t data = CPU_8051.REGISTERS[BANK].R0;
	CPU_8051.SFR[ACC] = subb (CPU_8051.SFR[ACC], data);
	return 1;
} 

// SUBB A, R1
int SUBB_R1 ( ) {  
  	
	int8_t data = CPU_8051.REGISTERS[BANK].R1;
	CPU_8051.SFR[ACC] = subb (CPU_8051.SFR[ACC], data);
	return 1;

}

// SUBB A, R2
int SUBB_R2 ( ) {  
	
	int8_t data = CPU_8051.REGISTERS[BANK].R2;
	CPU_8051.SFR[ACC] = subb (CPU_8051.SFR[ACC], data);
	return 1;

} 

// SUBB A, R3
int SUBB_R3 ( ) {  
	
	int8_t data = CPU_8051.REGISTERS[BANK].R3;
	CPU_8051.SFR[ACC] = subb (CPU_8051.SFR[ACC], data);
	return 1;

} 

// SUBB A, R4
int SUBB_R4 ( ) {  
	
	int8_t data = CPU_8051.REGISTERS[BANK].R4;
	CPU_8051.SFR[ACC] = subb (CPU_8051.SFR[ACC], data);
	return 1;
}

// SUBB A, R5
int SUBB_R5 ( ) {  
	
	int8_t data = CPU_8051.REGISTERS[BANK].R5;
	CPU_8051.SFR[ACC] = subb (CPU_8051.SFR[ACC], data);
	return 1;

}

// SUBB A, R6
int SUBB_R6 ( ) {  
	
	int8_t data = CPU_8051.REGISTERS[BANK].R6;
	CPU_8051.SFR[ACC] = subb (CPU_8051.SFR[ACC], data);
	return 1;

}     

// 0x9F
// SUBB A, R7
int SUBB_R7 ( ) {  
	
	int8_t data = CPU_8051.REGISTERS[BANK].R7;
	CPU_8051.SFR[ACC] = subb (CPU_8051.SFR[ACC], data);
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
	return 1;
}

//0xA1
int AJMP_0xA1 ( ) { 
	uint16_t low_add_byte = fetch ( );
	CPU_8051.PC = ( ( CPU_8051.PC & 0xF800) | (0xA1 & 0x70) ) | low_add_byte;
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
	return 1;
	
} 

// INC DPTR
int INC_dptr ( ) {

	uint16_t dptr = ( (CPU_8051.SFR[DPH] << 8) | CPU_8051.SFR[DPL] );
	dptr++;
	CPU_8051.SFR[DPH] = dptr >> 8;
	CPU_8051.SFR[DPL] = dptr & 0x00FF;
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

	return 1;

} 
//reserved

int MOV_atR0_data_addr ( ) {

	uint8_t dest_addr = CPU_8051.REGISTERS[BANK].R0;
	uint8_t sour_addr = fetch ( );

	*( (char*)&CPU_8051 + dest_addr) = *( (char*)&CPU_8051 + sour_addr );
	return 1;

}

// 0xA7
int MOV_atR1_data_addr ( ) {

	uint8_t dest_addr = CPU_8051.REGISTERS[BANK].R1;
	uint8_t sour_addr = fetch ( );

	*( (char*)&CPU_8051 + dest_addr) = *( (char*)&CPU_8051 + sour_addr );
	return 1;

}

int MOV_R0_data_addr ( ) {
	
	uint8_t sour_addr = fetch ( );
	CPU_8051.REGISTERS[BANK].R0 = *( (char*)&CPU_8051 + sour_addr );
	return 1;

}

int MOV_R1_data_addr ( ) {
	
	uint8_t sour_addr = fetch ( );
	CPU_8051.REGISTERS[BANK].R1 = *( (char*)&CPU_8051 + sour_addr );
	return 1;
	
}

int MOV_R2_data_addr ( ) {
	
	uint8_t sour_addr = fetch ( );
	CPU_8051.REGISTERS[BANK].R2 = *( (char*)&CPU_8051 + sour_addr );
	return 1;
	
}

int MOV_R3_data_addr ( ) {
	
	uint8_t sour_addr = fetch ( );
	CPU_8051.REGISTERS[BANK].R3 = *( (char*)&CPU_8051 + sour_addr );
	return 1;
	
}

int MOV_R4_data_addr ( ) {
	
	uint8_t sour_addr = fetch ( );
	CPU_8051.REGISTERS[BANK].R4 = *( (char*)&CPU_8051 + sour_addr );
	return 1;
	
}

int MOV_R5_data_addr ( ) {
	
	uint8_t sour_addr = fetch ( );
	CPU_8051.REGISTERS[BANK].R5 = *( (char*)&CPU_8051 + sour_addr );
	return 1;
	
}

int MOV_R6_data_addr ( ) {
	
	uint8_t sour_addr = fetch ( );
	CPU_8051.REGISTERS[BANK].R6 = *( (char*)&CPU_8051 + sour_addr );
	return 1;
	
}

// 0xAF
int MOV_R7_data_addr ( ) {
	
	uint8_t sour_addr = fetch ( );
	CPU_8051.REGISTERS[BANK].R7 = *( (char*)&CPU_8051 + sour_addr );
	return 1;
	
}


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

int CPL ( ) {

	CPU_8051.SFR[ACC] ^= 0xFF;
	return 1;

}

int CPL_C ( ) {

	CPU_8051.SFR[ACC] ^= CY;
	return 1;

}
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
// int PUSH (int8_t data) // declared above

//0xC1
int AJMP_0xC1 ( ) { 
	uint16_t low_add_byte = fetch ( );
	CPU_8051.PC = ( ( CPU_8051.PC & 0xF800) | (0xC1 & 0x70) ) | low_add_byte;
	return 1;
}

// clear particular bit, like P1.0
// int CLR ( ) {  return 0;} 

int CLR_C ( ) {
	
	CPU_8051.SFR[PSW] &= ~(CY);
	return 1;

}

/** 0xC4
 * SWap, will swap the nibbles of the accumulator
 */
int SWAP ( ) {
	
	int8_t tmp = CPU_8051.SFR[ACC] & 0xF0;
	CPU_8051.SFR[ACC] = (CPU_8051.SFR[ACC] << 4) | ((tmp >> 4) & 0x0F);
	return 1;

}

int XCH_A_dataaddr ( ) {
	
	uint8_t addr = fetch ( );
	int8_t tmp = CPU_8051.SFR[ACC];
	CPU_8051.SFR[ACC] = *( (char*)&CPU_8051 + addr );
	*( (char*)&CPU_8051 + addr ) = tmp;
	return 1;

}

int XCH_A_at_R0 ( ) {
	
	uint8_t addr = CPU_8051.REGISTERS[BANK].R0;
	int8_t tmp = CPU_8051.SFR[ACC];
	CPU_8051.SFR[ACC] = *( (char*)&CPU_8051 + addr );
	*( (char*)&CPU_8051 + addr ) = tmp;
	return 1;
	
}

// 0xC7
int XCH_A_at_R1 ( ) {
	
	uint8_t addr = CPU_8051.REGISTERS[BANK].R1;
	int8_t tmp = CPU_8051.SFR[ACC];
	CPU_8051.SFR[ACC] = *( (char*)&CPU_8051 + addr );
	*( (char*)&CPU_8051 + addr ) = tmp;
	return 1;
	
}

/** XCH : Xchange A contant with R0 content
 * 1 byte instruction
 */
int XCH_A_R0 ( ) {

	int8_t temp = CPU_8051.SFR[ACC];
	CPU_8051.SFR[ACC] = CPU_8051.REGISTERS[BANK].R0;
	CPU_8051.REGISTERS[BANK].R0 = temp;
	return 1;

} 

int XCH_A_R1 ( ) {

	int8_t temp = CPU_8051.SFR[ACC];
	CPU_8051.SFR[ACC] = CPU_8051.REGISTERS[BANK].R1;
	CPU_8051.REGISTERS[BANK].R1 = temp;
	return 1;
	
} 

int XCH_A_R2 ( ) {

	int8_t temp = CPU_8051.SFR[ACC];
	CPU_8051.SFR[ACC] = CPU_8051.REGISTERS[BANK].R2;
	CPU_8051.REGISTERS[BANK].R2 = temp;
	return 1;
	
} 

int XCH_A_R3 ( ) {

	int8_t temp = CPU_8051.SFR[ACC];
	CPU_8051.SFR[ACC] = CPU_8051.REGISTERS[BANK].R3;
	CPU_8051.REGISTERS[BANK].R3 = temp;
	return 1;
	
} 

int XCH_A_R4 ( ) {

	int8_t temp = CPU_8051.SFR[ACC];
	CPU_8051.SFR[ACC] = CPU_8051.REGISTERS[BANK].R4;
	CPU_8051.REGISTERS[BANK].R4 = temp;
	return 1;
	
} 

int XCH_A_R5 ( ) {

	int8_t temp = CPU_8051.SFR[ACC];
	CPU_8051.SFR[ACC] = CPU_8051.REGISTERS[BANK].R5;
	CPU_8051.REGISTERS[BANK].R5 = temp;
	return 1;
	
} 

int XCH_A_R6 ( ) {

	int8_t temp = CPU_8051.SFR[ACC];
	CPU_8051.SFR[ACC] = CPU_8051.REGISTERS[BANK].R6;
	CPU_8051.REGISTERS[BANK].R6 = temp;
	return 1;
	
} 


int XCH_A_R7 ( ) {

	int8_t temp = CPU_8051.SFR[ACC];
	CPU_8051.SFR[ACC] = CPU_8051.REGISTERS[BANK].R7;
	CPU_8051.REGISTERS[BANK].R7 = temp;
	return 1;
	
} 

// int POP ( )  declard above

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


// need to be checked
int SETB ( ) {

	uint8_t addr = fetch ( );
	int8_t data = CPU_8051.Bit_Addressable[addr/8];
	data |= ( 1 << ((addr % 8) + 1) );
	return 1;
	
}

int SETB_C ( ) {

	CPU_8051.SFR[PSW] |= CY;
	return 1;

}
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

/** required port programming 
 */
// int MOVX_A_at_R0 ( ) {  return 0;} 
// int MOVX_A_at_R1 ( ) {  return 0;} 


/** 0xE4
 * clear Acc
 */
int CLR_A () {
	
	CPU_8051.SFR[ACC] = 0x00;
	return 1;

}


int MOV_A_dataaddr ( ) {
	
	uint8_t addr = fetch ( );
	CPU_8051.SFR[ACC] = *( (char*)&CPU_8051 + addr);
	return 1;

}

int MOV_A_at_R0 ( ) {

	uint8_t addr = CPU_8051.REGISTERS[BANK].R0;
	CPU_8051.SFR[ACC] = *( (char*)&CPU_8051 + addr );
	return 1;

}

// 0xE7
int MOV_A_at_R1 ( ) {

	uint8_t addr = CPU_8051.REGISTERS[BANK].R1;
	CPU_8051.SFR[ACC] = *( (char*)&CPU_8051 + addr );
	return 1;
	
}

/** 0xE8
 * MOV A, R0
 */
int MOV_A_R0 ( ) {

	CPU_8051.SFR[ACC] = CPU_8051.REGISTERS[BANK].R0;
	return 1;

}

int MOV_A_R1 ( ) {

	CPU_8051.SFR[ACC] = CPU_8051.REGISTERS[BANK].R1;
	return 1;
	
}

int MOV_A_R2 ( ) {

	CPU_8051.SFR[ACC] = CPU_8051.REGISTERS[BANK].R2;
	return 1;
	
}

int MOV_A_R3 ( ) {

	CPU_8051.SFR[ACC] = CPU_8051.REGISTERS[BANK].R3;
	return 1;
	
}

int MOV_A_R4 ( ) {

	CPU_8051.SFR[ACC] = CPU_8051.REGISTERS[BANK].R4;
	return 1;
	
}

int MOV_A_R5 ( ) {

	CPU_8051.SFR[ACC] = CPU_8051.REGISTERS[BANK].R5;
	return 1;
	
}

int MOV_A_R6 ( ) {

	CPU_8051.SFR[ACC] = CPU_8051.REGISTERS[BANK].R6;
	return 1;
	
}

//0xEF
int MOV_A_R7 ( ) {

	CPU_8051.SFR[ACC] = CPU_8051.REGISTERS[BANK].R7;
	return 1;
	
}
// 0xF0
int MOVX_at_DPTR_A ( ) {

	uint16_t addr = (CPU_8051.SFR[DPH] << 8) | CPU_8051.SFR[DPL];
	CPU_8051.Code_Memory[addr] = CPU_8051.SFR[ACC];
	return 1;

}

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
int MOVX_at_R0_A ( ) {

	uint8_t addr = CPU_8051.REGISTERS[BANK].R0;
	*( (char*)&CPU_8051 + addr ) = CPU_8051.SFR[ACC];
	return 1;

}

int MOVX_at_R1_A ( ) {

	uint8_t addr = CPU_8051.REGISTERS[BANK].R1;
	*( (char*)&CPU_8051 + addr ) = CPU_8051.SFR[ACC];
	return 1;
	
}

/** 0xF4
 * CPL A : Complement A
 */
int CPL_A ( ) {

	CPU_8051.SFR[ACC] ^= 0xFF;
	return 1;

}

int MOV_data_addr_A ( ) {

	uint8_t addr = fetch ( );
	*( (char*)&CPU_8051 + addr ) = CPU_8051.SFR[ACC];
	return 1;

} 

int MOV_at_R0_A ( ) {

	uint8_t addr = CPU_8051.REGISTERS[BANK].R0;
	*( (char*)&CPU_8051 + addr ) = CPU_8051.SFR[ACC];
	return 1;

}  

// 0xF7
int MOV_at_R1_A ( ) {

	uint8_t addr = CPU_8051.REGISTERS[BANK].R1;
	*( (char*)&CPU_8051 + addr ) = CPU_8051.SFR[ACC];
	return 1;

}  

int MOV_R0_A ( ) {

	CPU_8051.REGISTERS[BANK].R0 = CPU_8051.SFR[ACC];
	return 1;

} 

int MOV_R1_A ( ) {

	CPU_8051.REGISTERS[BANK].R1 = CPU_8051.SFR[ACC];
	return 1;
	
} 

int MOV_R2_A ( ) {

	CPU_8051.REGISTERS[BANK].R2 = CPU_8051.SFR[ACC];
	return 1;
	
} 

int MOV_R3_A ( ) {

	CPU_8051.REGISTERS[BANK].R3 = CPU_8051.SFR[ACC];
	return 1;
	
} 

int MOV_R4_A ( ) {

	CPU_8051.REGISTERS[BANK].R4 = CPU_8051.SFR[ACC];
	return 1;
	
} 

int MOV_R5_A ( ) {

	CPU_8051.REGISTERS[BANK].R5 = CPU_8051.SFR[ACC];
	return 1;
	
} 

int MOV_R6_A ( ) {

	CPU_8051.REGISTERS[BANK].R6 = CPU_8051.SFR[ACC];
	return 1;
	
} 

//0xFF
int MOV_R7_A ( ) {

	CPU_8051.REGISTERS[BANK].R7 = CPU_8051.SFR[ACC];
	return 1;
	
} 
