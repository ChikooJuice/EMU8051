#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "../Memory/Memory.h"
#include <stdio.h>
#include <stdlib.h>


int (*OP_CODES[0xFF]) (void);
/** Assign this function pointer to corresponding instruction
 * after defining the functions
 */


/** NOP
 * N OPeration,
 * does nothing
 **/
int NOP ( );		 // 0x00

/**
 *
 * jump address : bit (0-7) : next byte fetch
 *		  bit (8-11): op-code bit (7-5)
 *		  bit (12-16) : previous pc value
 **/
int AJMP_0x01 ( );		

// Long jump
int LJMP ( );

// Rotate Right
int RR ( );	

// Increment A	
int INC_A ( );		
int INC_data_addr ( );	
int INC_at_R0 ( );
int INC_at_R1 ( );	//0x07
int INC_R0 ( );
int INC_R1 ( );
int INC_R2 ( );
int INC_R3 ( );
int INC_R4 ( );
int INC_R5 ( );
int INC_R6 ( );
int INC_R7 ( );		//0x0F
int JBC ( );		//0x10	
int ACALL_0x11 ( );
int LCALL ( );
int RRC_A ( );
int DEC_A ( );
int DEC_data_addr ( );
int DEC_at_R0 ( );
int DEC_at_R1 ( );	//0x17
int DEC_R0 ( );
int DEC_R1 ( );
int DEC_R2 ( );
int DEC_R3 ( );
int DEC_R4 ( );
int DEC_R5 ( );
int DEC_R6 ( );
int DEC_R7 ( );		//0x1F
int JB ( );		//0x20
int AJMP_0x21 ( ); //repeat
int RET ( );		
int RL ( );
int ADD_data ( );
int ADD_data_addr ( );
int ADD_at_R0 ( );
int ADD_at_R1 ( );	//0x27
int ADD_R0 ( );
int ADD_R1 ( );
int ADD_R2 ( );
int ADD_R3 ( );
int ADD_R4 ( );
int ADD_R5 ( );
int ADD_R6 ( );
int ADD_R7 ( );		//0x2F
int JNB ( );		//0x30
int ACALL_0x31 ( ); // same as 0x11
int RETI ( );
int RLC ( );
int ADDC_data ( );
int ADDC_data_addr ( );
int ADDC_at_R0 ( );
int ADDC_at_R1 ( );	//0x37
int ADDC_R0 ( );
int ADDC_R1 ( );
int ADDC_R2 ( );
int ADDC_R3 ( );
int ADDC_R4 ( );
int ADDC_R5 ( );
int ADDC_R6 ( );
int ADDC_R7 ( );	//0x3F
int JC ( );		//0x40
int AJMP_0x41 ( );	//repeat	
int ORL_data_addr_A ( );
int ORL_data_addr_data ( );
int ORL_A_data ( );
int ORL_A_data_addr ( );
int ORL_acc_at_R0 ( );
int ORL_acc_at_R1 ( );	//0x47
int ORL_R0 ( );
int ORL_R1 ( );
int ORL_R2 ( );
int ORL_R3 ( );
int ORL_R4 ( );
int ORL_R5 ( );
int ORL_R6 ( );
int ORL_R7 ( );		//0x4F
int JNC ( );		//0x50
int ACALL_0x51 ( );
int ANL_data_addr_A ( );
int ANL_data_addr_data ( );
int ANL_A_data ( );
int ANL_A_data_addr ( );
int ANL_A_at_R0 ( );
int ANL_A_at_R1 ( );	//0x57
int ANL_R0 ( );
int ANL_R1 ( );
int ANL_R2 ( );
int ANL_R3 ( );
int ANL_R4 ( );
int ANL_R5 ( );
int ANL_R6 ( );
int ANL_R7 ( );		//0x5F
int JZ ( );		//0x60
int AJMP_0x61 ( );
int XRL_data_addr_A ( );
int XRL_data_addr_data ( );
int XRL_A_data ( );
int XRL_A_dataaddr ( );
int XRL_A_at_R0 ( );
int XRL_A_at_R1 ( );	//0x67
int XRL_R0 ( );
int XRL_R1 ( );
int XRL_R2 ( );
int XRL_R3 ( );
int XRL_R4 ( );
int XRL_R5 ( );
int XRL_R6 ( );
int XRL_R7 ( );		//0x6F
int JNZ ( );		//0x70
int ACALL_0x71 ( );
int ORL_C_0x72 ( );
int JMP_at_A_DPTR ( );
int MOV_A_data ( );
int MOV_data_addr_data ( );
int MOV_at_R0 ( );
int MOV_at_R1 ( );	//0x77
int MOV_R0 ( );
int MOV_R1 ( );
int MOV_R2 ( );
int MOV_R3 ( );
int MOV_R4 ( );
int MOV_R5 ( );
int MOV_R6 ( );
int MOV_R7 ( );		//0x7F
int SJMP ( );		//0x80
int AJMP_0x81 ( );		
int ANL_C_0x81 ( );
int MOVC ( );
int DIV ( );
int MOV_data_addr_data_addr ( );
int MOV_data_addr_atR0 ( );
int MOV_data_addr_atR1 ( );	//0x87
int MOV_data_addr_R0 ( );	
int MOV_data_addr_R1 ( );
int MOV_data_addr_R2 ( );
int MOV_data_addr_R3 ( );
int MOV_data_addr_R4 ( );
int MOV_data_addr_R5 ( );
int MOV_data_addr_R6 ( );
int MOV_data_addr_R7 ( );	//0x8F
int MOV_DPTR_data ( );		//0x90
int ACALL_0x91 ( );
int MOV_bit_C ( );
int MOVC_A_dptr ( );
int SUBB_A_data ( );
int SUBB_A_data_addr ( );
int SUBB_A_atR0 ( );
int SUBB_A_atR1 ( );		//0x97
int SUBB_R0 ( );
int SUBB_R1 ( );
int SUBB_R2 ( );
int SUBB_R3 ( );
int SUBB_R4 ( );
int SUBB_R5 ( );
int SUBB_R6 ( );   
int SUBB_R7 ( );		//0x9F
int ORL_C_0xA0 ( );			//0xA0
int AJMP_0xA1 ( );
int MOV_C ( );
int INC_dptr ( );
int MUL ( );
//reserved
int MOV_atR0_data_addr ( );
int MOV_atR1_data_addr ( );	//0xA7
int R0_data_addr ( );
int R1_data_addr ( );
int R2_data_addr ( );
int R3_data_addr ( );
int R4_data_addr ( );
int R5_data_addr ( );
int R6_data_addr ( );
int R7_data_addr ( );		//0xAF
int ANL_C_0xB0 ( );			//0xB0
int ACALL_0xB1 ( );
int CPL ();
int CPL_C ();
int CJNE_A_data_codeaddr ( );
int CJNE_A_data_addr_codeaddr ( );
int CJNE_atR0_data_codeaddr ( );
int CJNE_atR1_data_codeaddr ( );	//0xB7
int CJNE_R0 ( );
int CJNE_R1 ( );
int CJNE_R2 ( );
int CJNE_R3 ( );
int CJNE_R4 ( );
int CJNE_R5 ( );
int CJNE_R6 ( );
int CJNE_R7 ( );		//0xBF
int PUSH (int8_t );			//0xC0
int AJMP_0xC1 ();
int CLR ( );
int CLR_C ();
int SWAP ( );
int XCH_A_dataaddr ( );
int XCH_A_atR0 ( );
int XCH_A_at_R1 ( );		//0xC7
int XCH_A_R0 ( );
int XCH_A_R1 ( );
int XCH_A_R2 ( );
int XCH_A_R3 ( );
int XCH_A_R4 ( );
int XCH_A_R5 ( );
int XCH_A_R6 ( );
int XCH_A_R7 ( );		//0xCF
int POP ( );			//0xD0
int ACALL_0xD1 ( );
int SETB ( );
int SETB_C ( );
int DA ( );
int DJNZ ( );
int XCHD_A_at_R0 ( );
int XCHD_A_at_R1 ( );		//0xD7
int DJNZ_R0 ( );	
int DJNZ_R1 ( );
int DJNZ_R2 ( );
int DJNZ_R3 ( );
int DJNZ_R4 ( );
int DJNZ_R5 ( );
int DJNZ_R6 ( );
int DJNZ_R7 ( );		//0xDF
int MOVX_at_DPTR ( );		//0xE0
int AJMP_0xE1 ( );
int MOVX_A_at_R0 ( );
int MOVX_A_at_R1 ( );
int CLR_A ();
int MOV_A_dataaddr ();
int MOV_A_at_R0 ( );
int MOV_A_at_R1 ( );		//0xE7
int MOV_A_R0 ( );
int MOV_A_R1 ( );
int MOV_A_R2 ( );
int MOV_A_R3 ( );
int MOV_A_R4 ( );
int MOV_A_R5 ( );
int MOV_A_R6 ( );
int MOV_A_R7 ( );		//0xEF
int MOVX_at_DPTR_A ( );		//0xF0
int ACALL_0xF1 ( );
int MOVX_at_R0_A ( );
int MOVX_at_R1_A ( );
int CPL_A ( );
int MOV_data_addr_A ( );
int MOV_at_R0_A ( );
int MOV_at_R1_A ( );		//0xF7
int MOV_R0_A ( );
int MOV_R1_A ( );
int MOV_R2_A ( );
int MOV_R3_A ( );
int MOV_R4_A ( );
int MOV_R5_A ( );
int MOV_R6_A ( );
int MOV_R7_A ( );		//0xFF

void assign_functions ();
int8_t fetch ( );

/** parity flag in SFR 
 * will give 1 even parity
 * w.r.t accumulator
 */
void update_parity ( );

/**
 * program memory registers with initial values
 **/
void Init_CPU (void);

#endif