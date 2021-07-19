#include "../Memory/Memory.h"
#include "../Instructions/INSTRUCTION.h"
#include "../Init/Init.h"
#include "../disassembler/disassembler.h"
#include "../UI/ui.h"
#include <stdio.h>
#include <string.h>

int PPRINT = 1;

uint16_t ConvertToInt (char *);

int main ( int argc, char *argv[]) {
	
	if (argc == 1 || argc > 2) {
		printf ("invalid number of command line arguments \n");
		printf ("Give only location of hex file as argument \n");
		return 0;
	}

	Init_CPU ( );
	WriteTOCodeMemory (argv[1]);
	printf ("program written to code memory successfully \n");
	char command[100], *command_token, delimit[] = " \t";
	
	while (1) {
	again:
		gets (command);
		if (!strcmp (command, "\0")) goto again; // in case you enter \n 
		// parsing this command using strtok
		command_token = strtok (command, delimit);

		if (!strcmp (command_token, "exit") | (command_token == NULL)) {
			return 0;
		}
		else {
			
			if (! ( strcmp ( command_token, "reg"))) // show registers
			{
				show_Registers ( );
			}

			else if ( ! (strcmp (command_token, "mem"))) // show memory range
			{
				uint16_t low, high;
				command_token = strtok ( NULL, delimit);
				
				if (command_token == NULL) {
					printf ( "Invalid low address range argument\n");
					goto again;
				}
				low = ConvertToInt (command_token);

				command_token = strtok ( NULL, delimit);
				
				if (command_token == NULL) {
					printf ( "Invalid high address argument\n");
					goto again;
				}

				high = ConvertToInt (command_token);

				show_memory (low, high);

				// we discard other arguments
			}

			else if ( !strcmp (command_token, "code")) // show code memory
			{
				uint16_t low, high;
				command_token = strtok ( NULL, delimit);
				
				if (command_token == NULL) {
					printf ( "Invalid low address range argument\n");
					goto again;
				}
				low = ConvertToInt (command_token);

				command_token = strtok ( NULL, delimit);
				
				if (command_token == NULL) {
					printf ( "Invalid high address argument\n");
					goto again;
				}

				high = ConvertToInt (command_token);

				show_CodeMemory (low, high);

				// we discard other arguments


			}

			else if (! (strcmp (command_token, "sfr")))  // show SFR
			{
				command_token = strtok (NULL, delimit);
				if (command_token == NULL) {
					printf ("No argument given \n");
				}

				while (command_token != NULL){
					for ( int i = 0; command_token[i] != '\0'; i++) command_token[i] = toupper (command_token[i]);
					show_SFR ( command_token);
					command_token = strtok (NULL, delimit);
				}
			}

			else if (! (strcmp (command_token, "bit"))) // show bit addressable area
			{
				show_BitAddressable ( );
			}

			else if (! (strcmp (command_token, "pc"))) // show pc
			{
				show_PC ( );
			}

			else if (! (strcmp (command_token, "set"))) // set register
			{
				command_token = strtok (NULL, delimit);
				if (command_token == NULL) {
					printf ("No argument for register name \n");
					continue;
				}

				char chosen_register[5];
				for ( int i = 0; command_token[i] != '\0'; i++) 
					command_token[i] = toupper (command_token[i]);

				strcpy (chosen_register, command_token);

				// now parse the value from the command
				command_token = strtok (NULL, delimit);
				if (command_token == NULL) {
					printf ("No argument for Value given, try again \n");
					continue;
				}

				uint16_t value = ConvertToInt (command_token);
				set_reg (chosen_register, value);	
			}

			else if (! (strcmp (command_token, "next")) | !(strcmp(command_token, "n"))) {
				
				uint8_t index = fetch ( );
				if ( OP_CODES[index] ( )  == 0)  {
					printf ("error executing command at PC : %x\n", CPU_8051.PC);
				}
			}

			else if (! (strcmp (command_token, "wr"))) // to write to memory
			{
				uint16_t addr; uint8_t val;

				command_token = strtok (NULL, delimit);
				if (command_token == NULL) {
					printf ("Invalid argument for address to write to\n");
					continue;
				}

				addr = ConvertToInt (command_token);

				command_token = strtok (NULL, delimit);
				if (command_token == NULL) {
					printf ("Invalid argument for value to write to\n");
					continue;
				}

				val = (uint8_t)ConvertToInt (command_token);

				write_memory (addr, val);
			}

			else if (! (strcmp (command_token, "clear"))) // clear the screen
			{
				clear ( );
			}

			else {
				continue;
			}

			printf ("\n\n");
			
		}
	}



}



uint16_t ConvertToInt (char *num) 
{
	uint16_t tmp = 0;
	if (num[1] == 'x' | num[1] == 'X') goto hex;

	for (int i = 0; num[i] != '\0'; i++) {
		tmp = tmp * 10 + IntfromHex (num[i]);
	}
hex:
	for ( int i = 2; num[i] != '\0'; i++) {
		tmp = tmp * 16 + IntfromHex(num[i]);
	}

	return tmp;
}
