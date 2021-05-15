#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "../Memory/Memory.h"
#include <stdio.h>
#include <stdlib.h>


typedef int (*Inst_function_pointer)( );

Inst_function_pointer INST_ARRAY[0xFF];

int NOP ( );
int AJMP ( );
int LJMP ( );
int RR ( );
int INC_A ( );
int INC_data_addr ( );
int INC_at_R0 ( );
int INC_at_R1 ( );
int INC_R0 ( );
int INC_R1 ( );
int INC_R3 ( );
int INC_R4 ( );
int INC_R5 ( );
int INC_R6 ( );
int INC_R7 ( );
int JBC ( );
int ACALL ( );
int LCALL ( );
int RRC_A ( );
int DEC_A ( );
int DEC_data_addr ( );
int DEC_at_R0 ( );
int DEC_at_R1 ( );
int DEC_R0 ( );
int DEC_R1 ( );
int DEC_R2 ( );
int DEC_R3 ( );
int DEC_R4 ( );
int DEC_R5 ( );
int DEC_R6 ( );
int DEC_R7 ( );
int JB ( );
// 0x21 is also code for AJMP
int RET ( );
int RL ( );
int ADD_data ( );
int ADD_data_addr ( );
int ADD_at_R0 ( );
int ADD_at_R1 ( );
int ADD_R0 ( );
int ADD_R1 ( );
int ADD_R2 ( );
int ADD_R3 ( );
int ADD_R4 ( );
int ADD_R5 ( );
int ADD_R6 ( );
int ADD_R7 ( );
int JNB ( );
// 0x31 also ACALL same as 0x11
int RETI ( );
int RLC ( );
int ADDC_data ( );
int ADDC_data_addr ( );
int ADDC_at_R0 ( );
int ADDC_at_R1 ( );
int ADDC_R0 ( );
int ADDC_R1 ( );
int ADDC_R2 ( );
int ADDC_R3 ( );
int ADDC_R4 ( );
int ADDC_R5 ( );
int ADDC_R6 ( );
int ADDC_R7 ( );
int JC ( );
// AJMP
int ORL_a ( );
int ORL_data ( );
int ORL_acc_at_R0 ( );
int ORL_acc_at_R1 ( );
int ORL_R0 ( );
int ORL_R1 ( );
int ORL_R2 ( );
int ORL_R3 ( );
int ORL_R4 ( );
int ORL_R5 ( );
int ORL_R6 ( );
int ORL_R7 ( );
int JNC ( );
// int ACALL ( );
int ANL_data_addr_A ( );
int ANL_data_addr_data ( );
int ANL_A_data ( );
int ANL_A_data_addr ( );
int ANL_A_at_R0 ( );
int ANL_A_at_R1 ( );
int ANL_R0 ( );
int ANL_R1 ( );
int ANL_R2 ( );
int ANL_R3 ( );
int ANL_R4 ( );
int ANL_R5 ( );
int ANL_R6 ( );
int ANL_R7 ( );
int JZ ( );
// int AJMP ( );
int XRL_data_addr_A ( );
int XRL_data_addr_data ( );
int XRL_A_at_R0 ( );
int XRL_A_at_R1 ( );
int XRL_R0 ( );
int XRL_R1 ( );
int XRL_R2 ( );
int XRL_R3 ( );
int XRL_R4 ( );
int XRL_R5 ( );
int XRL_R6 ( );
int XRL_R7 ( );
int JNZ ( );
int ACALL ( );
int ORL_C ( );
int JMP_at_A_DPTR ( );
int MOV_A_data ( );
int MOV_data_addr_data ( );
int MOV_at_R0 ( );
int MOV_at_R1 ( );
int MOV_R0 ( );
int MOV_R1 ( );
int MOV_R2 ( );
int MOV_R3 ( );
int MOV_R4 ( );
int MOV_R5 ( );
int MOV_R6 ( );
int MOV_R7 ( );
int SJMP ( );
int AJMP ( );
int ANL_C ( );
int MOVC ( );
int DIV ( );
int MOV_data_addr_data_addr ( );
int MOV_data_addr_atR0 ( );
int MOV_data_addr_atR1 ( );
int MOV_data_addr_R0 ( );
int MOV_data_addr_R1 ( );
int MOV_data_addr_R2 ( );
int MOV_data_addr_R3 ( );
int MOV_data_addr_R4 ( );
int MOV_data_addr_R5 ( );
int MOV_data_addr_R6 ( );
int MOV_data_addr_R7 ( );
int MOV_DPTR_data ( );
int ACALL ( );
int MOV_bit_C ( );
int MOVC_A_dptr ( );
int SUBB_A_data ( );
int SUBB_A_data_addr ( );
int SUBB_A_atR0 ( );
int SUBB_A_atR1 ( );
int SUBB_R0 ( );
int SUBB_R1 ( );
int SUBB_R2 ( );
int SUBB_R3 ( );
int SUBB_R4 ( );
int SUBB_R5 ( );
int SUBB_R6 ( );   
int SUBB_R7 ( );








#endif