#ifndef UI_H
#define UI_H
#include <stdint.h>

void show_memory ( uint16_t low, uint16_t high);
void show_CodeMemory (uint16_t low, uint16_t high );
void show_Registers ( );
void show_SFR (char *chosen_register );
void Help ( );
void show_BitAddressable ( );
void show_PC ( );
void set_reg (char *chosen_register, uint16_t val);
#endif