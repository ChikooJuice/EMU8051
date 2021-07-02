#ifndef INIT_H
#define INIT_H

#include <stdint.h>
#include <stdio.h>

void assign_functions ( );
void Init_CPU (void);
void update_parity ( );
void update_CY ( uint8_t val);
void update_AC ( uint8_t val);
void update_OV ( uint8_t val);
int8_t add (int8_t op1, int8_t op2);
int8_t addc (int8_t op1, int8_t op2);
int8_t subb ( int8_t op1, int8_t op2);
void show_memory ( );
void show_CodeMemory ( );
int resolve_bit_addr (uint8_t bit_addr);



#endif