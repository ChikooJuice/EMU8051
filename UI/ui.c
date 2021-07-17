#include "ui.h"
#include "../Memory/Memory.h"
#include <stdio.h>
#include <stdlib.h>


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


void show_CodeMemory (uint16_t low, uint16_t high ) {
	
	if ( (low > high) || low < 0 || high < 0 || low > FLASH || high > FLASH) {
		printf ("Invalid Range of memory, Try again low : %d high %d \n", low, high);
		return;
	}

	else {
		printf ("\naddr\t");
		for ( char i = 0; i <= 0xF; i++) printf ("0x%1X\t", i);
		printf ("\n\n");

		for ( ; low <= high; ) {

			printf ("0x%X \t", low);

			for ( uint8_t i = 0; (i <= 0xF) && (low <= high); i++) {
				printf ("%02hhX\t", CPU_8051.Code_Memory[low]);
				low += 1;
			}

			printf ("\n");
		}
	}

}


void show_Registers ( ) {

	void *bank1, *bank2, *bank3, *bank0;
	bank0 = &CPU_8051.REGISTERS[0];
	bank1 = &CPU_8051.REGISTERS[1];
	bank2 = &CPU_8051.REGISTERS[2];
	bank3 = &CPU_8051.REGISTERS[3];

	printf ("\tBANK 0\t BANK 1\t BANK 3\t BANK 4\n");
	
	for (int i = 0; i < 8; i++) {
		printf ("R%d\t%3X \t %3X \t %3X \t %3X \n", i, \
		*((char*)bank0 + i), \
		*((char*)bank1 + i), \
		*((char*)bank2 + i), \
		*((char*)bank3 + i));
	}

}

void show_SFR ( ) {
	
	printf ("\n showing special function registers\n");
	printf ("P0 	: 0x%02hhX\n", CPU_8051.SFR[P0]);
	printf ("SP 	: 0x%02hhX\n", CPU_8051.SFR[SP]);
	printf ("DPL 	: 0x%02hhX\n", CPU_8051.SFR[DPL]);
	printf ("DPH 	: 0x%02hhX\n", CPU_8051.SFR[DPH]);
	printf ("PCON 	: 0x%02hhX\n", CPU_8051.SFR[PCON]);
	printf ("TCON 	: 0x%02hhX\n", CPU_8051.SFR[TCON]);
	printf ("TMOD 	: 0x%02hhX\n", CPU_8051.SFR[TMOD]);
	printf ("TL0 	: 0x%02hhX\n", CPU_8051.SFR[TL0]);
	printf ("TL1 	: 0x%02hhX\n", CPU_8051.SFR[TL1]);
	printf ("TH0 	: 0x%02hhX\n", CPU_8051.SFR[TH0]);
	printf ("TH1 	: 0x%02hhX\n", CPU_8051.SFR[TH1]);
	printf ("P1 	: 0x%02hhX\n", CPU_8051.SFR[P1]);
	printf ("SCON 	: 0x%02hhX\n", CPU_8051.SFR[SCON]);
	printf ("SBUF 	: 0x%02hhX\n", CPU_8051.SFR[SBUF]);
	printf ("P2 	: 0x%02hhX\n", CPU_8051.SFR[P2]);
	printf ("IE 	: 0x%02hhX\n", CPU_8051.SFR[IE]);
	printf ("P3 	: 0x%02hhX\n", CPU_8051.SFR[P3]);
	printf ("IP 	: 0x%02hhX\n", CPU_8051.SFR[IP]);
	printf ("PSW 	: 0x%02hhX\n", CPU_8051.SFR[PSW]);
	printf ("ACC 	: 0x%02hhX\n", CPU_8051.SFR[ACC]);
	printf ("B	: 0x%02hhX\n", CPU_8051.SFR[B]);

}