#include "Init.h"
#include "../Instructions/INSTRUCTION.h"
#include "../Memory/Memory.h"
#include <stdio.h>

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
	OP_CODES[0x70] = JNZ;                        OP_CODES[0x71] = ACALL_0x71;                 OP_CODES[0x72] = ORL_C_0x72;                 OP_CODES[0x73] = JMP_at_A_DPTR;              OP_CODES[0x74] = MOV_A_data;                 OP_CODES[0x75] = MOV_data_addr_data;         OP_CODES[0x76] = MOV_at_R0;                  OP_CODES[0x77] = MOV_at_R1;                  
	OP_CODES[0x78] = MOV_R0;                     OP_CODES[0x79] = MOV_R1;                     OP_CODES[0x7a] = MOV_R2;                     OP_CODES[0x7b] = MOV_R3;                     OP_CODES[0x7c] = MOV_R4;                     OP_CODES[0x7d] = MOV_R5;                     OP_CODES[0x7e] = MOV_R6;                     OP_CODES[0x7f] = MOV_R7;                     
	OP_CODES[0x80] = SJMP;                       OP_CODES[0x81] = AJMP_0x81;                  OP_CODES[0x82] = ANL_C_0x82;                 OP_CODES[0x83] = MOVC;                       OP_CODES[0x84] = DIV;                        OP_CODES[0x85] = MOV_data_addr_data_addr;    OP_CODES[0x86] = MOV_data_addr_atR0;         OP_CODES[0x87] = MOV_data_addr_atR1;         
	OP_CODES[0x88] = MOV_data_addr_R0;           OP_CODES[0x89] = MOV_data_addr_R1;           OP_CODES[0x8a] = MOV_data_addr_R2;           OP_CODES[0x8b] = MOV_data_addr_R3;           OP_CODES[0x8c] = MOV_data_addr_R4;           OP_CODES[0x8d] = MOV_data_addr_R5;           OP_CODES[0x8e] = MOV_data_addr_R6;           OP_CODES[0x8f] = MOV_data_addr_R7;           
	OP_CODES[0x90] = MOV_DPTR_data;              OP_CODES[0x91] = ACALL_0x91;                 OP_CODES[0x92] = MOV_bit_C;                  OP_CODES[0x93] = MOVC_A_dptr;                OP_CODES[0x94] = SUBB_A_data;                OP_CODES[0x95] = SUBB_A_data_addr;           OP_CODES[0x96] = SUBB_A_atR0;                OP_CODES[0x97] = SUBB_A_atR1;                
	OP_CODES[0x98] = SUBB_R0;                    OP_CODES[0x99] = SUBB_R1;                    OP_CODES[0x9a] = SUBB_R2;                    OP_CODES[0x9b] = SUBB_R3;                    OP_CODES[0x9c] = SUBB_R4;                    OP_CODES[0x9d] = SUBB_R5;                    OP_CODES[0x9e] = SUBB_R6;                    OP_CODES[0x9f] = SUBB_R7;                    
	OP_CODES[0xa0] = ORL_C_0xA0;                 OP_CODES[0xa1] = AJMP_0xA1;                  OP_CODES[0xa2] = MOV_C;                      OP_CODES[0xa3] = INC_dptr;                   OP_CODES[0xa4] = MUL;                        /*OP_CODES[0xa5] = XXXXXXXX;*/               OP_CODES[0xa6] = MOV_atR0_data_addr;         OP_CODES[0xa7] = MOV_atR1_data_addr;         
	OP_CODES[0xa8] = MOV_R0_data_addr;           OP_CODES[0xa9] = MOV_R1_data_addr;           OP_CODES[0xaa] = MOV_R2_data_addr;           OP_CODES[0xab] = MOV_R3_data_addr;           OP_CODES[0xac] = MOV_R4_data_addr;           OP_CODES[0xad] = MOV_R5_data_addr;           OP_CODES[0xae] = MOV_R6_data_addr;           OP_CODES[0xaf] = MOV_R7_data_addr;               
	OP_CODES[0xb0] = ANL_C_0xB0;                 OP_CODES[0xb1] = ACALL_0xB1;                 OP_CODES[0xb2] = CPL;                        OP_CODES[0xb3] = CPL_C;                      OP_CODES[0xb4] = CJNE_A_data_codeaddr;       OP_CODES[0xb5] = CJNE_A_data_addr_codeaddr;  OP_CODES[0xb6] = CJNE_atR0_data_codeaddr;    OP_CODES[0xb7] = CJNE_atR1_data_codeaddr;    
	OP_CODES[0xb8] = CJNE_R0;                    OP_CODES[0xb9] = CJNE_R1;                    OP_CODES[0xba] = CJNE_R2;                    OP_CODES[0xbb] = CJNE_R3;                    OP_CODES[0xbc] = CJNE_R4;                    OP_CODES[0xbd] = CJNE_R5;                    OP_CODES[0xbe] = CJNE_R6;                    OP_CODES[0xbf] = CJNE_R7;                    
	OP_CODES[0xc0] = PUSH;                       OP_CODES[0xc1] = AJMP_0xC1;                  OP_CODES[0xc2] = CLR;                        OP_CODES[0xc3] = CLR_C;                      OP_CODES[0xc4] = SWAP;                       OP_CODES[0xc5] = XCH_A_dataaddr;             OP_CODES[0xc6] = XCH_A_at_R0;                 OP_CODES[0xc7] = XCH_A_at_R1;                
	OP_CODES[0xc8] = XCH_A_R0;                   OP_CODES[0xc9] = XCH_A_R1;                   OP_CODES[0xca] = XCH_A_R2;                   OP_CODES[0xcb] = XCH_A_R3;                   OP_CODES[0xcc] = XCH_A_R4;                   OP_CODES[0xcd] = XCH_A_R5;                   OP_CODES[0xce] = XCH_A_R6;                   OP_CODES[0xcf] = XCH_A_R7;                   
	OP_CODES[0xd0] = POP;                        OP_CODES[0xd1] = ACALL_0xD1;                 OP_CODES[0xd2] = SETB;                       OP_CODES[0xd3] = SETB_C;                     OP_CODES[0xd4] = DA;                         OP_CODES[0xd5] = DJNZ;                       OP_CODES[0xd6] = XCHD_A_at_R0;               OP_CODES[0xd7] = XCHD_A_at_R1;               
	OP_CODES[0xd8] = DJNZ_R0;                    OP_CODES[0xd9] = DJNZ_R1;                    OP_CODES[0xda] = DJNZ_R2;                    OP_CODES[0xdb] = DJNZ_R3;                    OP_CODES[0xdc] = DJNZ_R4;                    OP_CODES[0xdd] = DJNZ_R5;                    OP_CODES[0xde] = DJNZ_R6;                    OP_CODES[0xdf] = DJNZ_R7;                    
	OP_CODES[0xe0] = MOVX_at_DPTR;               OP_CODES[0xe1] = AJMP_0xE1;                  OP_CODES[0xe2] = MOVX_A_at_R0;               OP_CODES[0xe3] = MOVX_A_at_R1;               OP_CODES[0xe4] = CLR_A;                      OP_CODES[0xe5] = MOV_A_dataaddr;             OP_CODES[0xe6] = MOV_A_at_R0;                OP_CODES[0xe7] = MOV_A_at_R1;                
	OP_CODES[0xe8] = MOV_A_R0;                   OP_CODES[0xe9] = MOV_A_R1;                   OP_CODES[0xea] = MOV_A_R2;                   OP_CODES[0xeb] = MOV_A_R3;                   OP_CODES[0xec] = MOV_A_R4;                   OP_CODES[0xed] = MOV_A_R5;                   OP_CODES[0xee] = MOV_A_R6;                   OP_CODES[0xef] = MOV_A_R7;                   
	OP_CODES[0xf0] = MOVX_at_DPTR_A;             OP_CODES[0xf1] = ACALL_0xF1;                 OP_CODES[0xf2] = MOVX_at_R0_A;               OP_CODES[0xf3] = MOVX_at_R1_A;               OP_CODES[0xf4] = CPL_A;                      OP_CODES[0xf5] = MOV_data_addr_A;            OP_CODES[0xf6] = MOV_at_R0_A;                OP_CODES[0xf7] = MOV_at_R1_A;                
	OP_CODES[0xf8] = MOV_R0_A;                   OP_CODES[0xf9] = MOV_R1_A;                   OP_CODES[0xfa] = MOV_R2_A;                   OP_CODES[0xfb] = MOV_R3_A;                   OP_CODES[0xfc] = MOV_R4_A;                   OP_CODES[0xfd] = MOV_R5_A;                   OP_CODES[0xfe] = MOV_R6_A;                   OP_CODES[0xff] = MOV_R7_A;                   

}

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

void show_CodeMemory ( ) {
	
	printf ("\t");
	for ( int i = 0; i < 16; i++) printf ("%hhx\t",i);
	printf ("\n");
	
	for ( int i = 0; i < 130; i++) printf ("-");
	printf ("\n");
	
	for ( int i = 0,z=0; i < FLASH/16 ; i++) {
		printf ("\n%d\t", i);

		for (int j = 0; j <= 0xF; j++) {

			printf ("%hhx\t", CPU_8051.Code_Memory[z++]);
		}			 
	}
	printf ("\n");
}