#include "ui.h"
#include "../Memory/Memory.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void show_memory ( uint16_t low, uint16_t high) {
	
	if ( (low > high) || low < 0 || high < 0 || low > FLASH || high > FLASH) {
		printf ("Invalid Range of memory, Try again low : %d high %d \n", low, high);
		return;
	}

	else {
		char *cpu_mem_pointer = &CPU_8051;
		printf ("\naddr\t");
		for ( char i = 0; i <= 0xF; i++) printf ("0x%1X\t", i);
		printf ("\n\n");

		for ( ; low <= high; ) {

			printf ("0x%X \t", low);

			for ( uint8_t i = 0; (i <= 0xF) && (low <= high); i++) {
				printf ("%x|%02hhX\t",low, *(cpu_mem_pointer + low));
				low += 1;
			}

			printf ("\n");
		}
	}
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
		printf ("R%d\t%3hhX \t %3hhX \t %3hhX \t %3hhX \n", i, \
		*((char*)bank0 + i), \
		*((char*)bank1 + i), \
		*((char*)bank2 + i), \
		*((char*)bank3 + i));
	}

}

void show_SFR ( char* chosen_register ) {
	
	if (!strcmp (chosen_register, "ALL")) {
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
				printf ("PC	: 0x%0X\n", CPU_8051.PC);

	}
	else if (!strcmp (chosen_register, "ACC")) {
		printf ("ACC 	: 0x%02hhX\n", CPU_8051.SFR[ACC]);

	}
	else if (!strcmp (chosen_register, "P0")) {
		printf ("P0 	: 0x%02hhX\n", CPU_8051.SFR[P0]);

	}
	else if (!strcmp (chosen_register, "SP")) {
		printf ("SP 	: 0x%02hhX\n", CPU_8051.SFR[SP]);

	}
	else if (!strcmp (chosen_register, "DPL")) {
		printf ("DPL 	: 0x%02hhX\n", CPU_8051.SFR[DPL]);

	}
	else if (!strcmp (chosen_register, "DPH")) {
		printf ("DPH 	: 0x%02hhX\n", CPU_8051.SFR[DPH]);

	}
	else if (!strcmp (chosen_register, "PCON")) {
		printf ("PCON 	: 0x%02hhX\n", CPU_8051.SFR[PCON]);

	}
	else if (!strcmp (chosen_register, "TCON")) {
		printf ("TCON 	: 0x%02hhX\n", CPU_8051.SFR[TCON]);

	}
	else if (!strcmp (chosen_register, "TMOD")) {
		printf ("TMOD 	: 0x%02hhX\n", CPU_8051.SFR[TMOD]);

	}
	else if (!strcmp (chosen_register, "TL0")) {
		printf ("TL0 	: 0x%02hhX\n", CPU_8051.SFR[TL0]);

	}
	else if (!strcmp (chosen_register, "TL1")) {
		printf ("TL1 	: 0x%02hhX\n", CPU_8051.SFR[TL1]);

	}
	else if (!strcmp (chosen_register, "TH0")) {
		printf ("TH0 	: 0x%02hhX\n", CPU_8051.SFR[TH0]);

	}
	else if (!strcmp (chosen_register, "TH1")) {
		printf ("TH1 	: 0x%02hhX\n", CPU_8051.SFR[TH1]);

	}
	else if (!strcmp (chosen_register, "P1")) {
		printf ("P1 	: 0x%02hhX\n", CPU_8051.SFR[P1]);

	}
	else if (!strcmp (chosen_register, "SCON")) {
		printf ("SCON 	: 0x%02hhX\n", CPU_8051.SFR[SCON]);

	}
	else if (!strcmp (chosen_register, "SBUF")) {
		printf ("SBUF 	: 0x%02hhX\n", CPU_8051.SFR[SBUF]);

	}
	else if (!strcmp (chosen_register, "P2")) {
		printf ("P2 	: 0x%02hhX\n", CPU_8051.SFR[P2]);

	}
	else if (!strcmp (chosen_register, "IE")) {
		printf ("IE 	: 0x%02hhX\n", CPU_8051.SFR[IE]);

	}
	else if (!strcmp (chosen_register, "P3")) {
		printf ("P3 	: 0x%02hhX\n", CPU_8051.SFR[P3]);

	}
	else if (!strcmp (chosen_register, "IP")) {
		printf ("IP 	: 0x%02hhX\n", CPU_8051.SFR[IP]);

	}
	else if (!strcmp (chosen_register, "PSW")) {
		printf ("PSW 	: 0x%02hhX\n", CPU_8051.SFR[PSW]);

	}
	else if (!strcmp (chosen_register, "B")) {
		printf ("B 	: 0x%02hhX\n", CPU_8051.SFR[B]);

	}
	else {
		printf ("Invalid register name\n");
	}

}

void Help ( ) {

	printf ("\n, 8051 Emulator, make sure location of intel hex file loaded is correct and you see file successfully loaded on your terminal\n");
	printf ("-----------Commands for debugging------------\n");
	printf ("Code <low range addr> <high range  address> \n");
	printf ("\t will show the code memory, where the hex file contents will be stored at given address\n");
	printf ("\t make sure low addr < high address, and high address < FLASH memory limit.");
	printf ("\tSFR [Special Function register seperated by spaces]");
	printf ("\t if no argument is passed, it will show all the registers");
	printf ("\t register include P0, SP, DPL, DPH, PCON, TCON, TMOD, \
TL0, TL1, TH0, TH1, P1, SCON, SBUF, P2, IE, P3, IP, PSW, ACC, B");
	printf ("\nMem <low Range> <high Range");
	printf ("\t shows memory of 8051, will show raw memory output, at which all \
registers and bit addressable memory are stored");
	printf ("\nBit <low addr value> <high addr value> : will show bit addressable space");
	printf ("\nNext or n : execute the current instruction to with pc is pointing at");
	printf ("\n PC : shows value stored in PC");
	printf ("\nsetPC <value in hex> : set pc to given hex value \n");
	printf ("\n help or ? : show help");

}

void show_BitAddressable ( ) {
	/**
	 * bit addressable memory range is 0x20 to 0x30, so we can just use show_memory ( ) 
	 * function instead of writing another function from scratch ( );
	 */
	show_memory (0x20, 0x30);
}


void show_PC ( ) {
	printf ("PC : %0hX\n", CPU_8051.PC);
}


void set_reg (char *chosen_register, uint16_t val) {

	if ( !strcmp (chosen_register, "PC")) {
		CPU_8051.PC = val;	
	}

	else if (!strcmp (chosen_register, "ACC")) {
		CPU_8051.SFR[ACC] = val & 0xFF;
	}

	else if (!strcmp (chosen_register, "P0")) {
		CPU_8051.SFR[P0] = val & 0xFF;

	}
	else if (!strcmp (chosen_register, "SP")) {
		CPU_8051.SFR[SP] = val & 0xFF;

	}
	else if (!strcmp (chosen_register, "DPL")) {
		CPU_8051.SFR[DPL] = val & 0xFF;

	}
	else if (!strcmp (chosen_register, "DPH")) {
		CPU_8051.SFR[DPH] = val & 0xFF;

	}
	else if (!strcmp (chosen_register, "PCON")) {
		CPU_8051.SFR[PCON] = val & 0xFF;

	}
	else if (!strcmp (chosen_register, "TCON")) {
		CPU_8051.SFR[TCON] = val & 0xFF;

	}
	else if (!strcmp (chosen_register, "TMOD")) {
		CPU_8051.SFR[TMOD] = val & 0xFF;

	}
	else if (!strcmp (chosen_register, "TL0")) {
		CPU_8051.SFR[TL0] = val & 0xFF;

	}
	else if (!strcmp (chosen_register, "TL1")) {
		CPU_8051.SFR[TL1] = val & 0xFF;

	}
	else if (!strcmp (chosen_register, "TH0")) {
		CPU_8051.SFR[TH0] = val & 0xFF;

	}
	else if (!strcmp (chosen_register, "TH1")) {
		CPU_8051.SFR[TH1] = val & 0xFF;

	}
	else if (!strcmp (chosen_register, "P1")) {
		CPU_8051.SFR[P1] = val & 0xFF;

	}
	else if (!strcmp (chosen_register, "SCON")) {
		CPU_8051.SFR[SCON] = val & 0xFF;

	}
	else if (!strcmp (chosen_register, "SBUF")) {
		CPU_8051.SFR[SBUF] = val & 0xFF;

	}
	else if (!strcmp (chosen_register, "P2")) {
		CPU_8051.SFR[P2] = val & 0xFF;

	}
	else if (!strcmp (chosen_register, "IE")) {
		CPU_8051.SFR[IE] = val & 0xFF;

	}
	else if (!strcmp (chosen_register, "P3")) {
		CPU_8051.SFR[P3] = val & 0xFF;

	}
	else if (!strcmp (chosen_register, "IP")) {
		CPU_8051.SFR[IP] = val & 0xFF;

	}
	else if (!strcmp (chosen_register, "PSW")) {
		CPU_8051.SFR[PSW] = val & 0xFF;

	}
	else if (!strcmp (chosen_register, "B")) {
		CPU_8051.SFR[B] = val & 0xFF;

	}
	else {
		printf ("Invalid register name\n");
	}
	

}

