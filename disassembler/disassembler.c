#ifndef DISASSEMBLER_H
#define DISASSEMBLER_H

#include "disassembler.h"
#include "../Memory/Memory.h"

struct section DecodeSection (FILE *objfile) {

	struct section CurrSection;

	CurrSection.len = CurrSection.checksum = CurrSection.address = 0;
	char tmp[2]; 

	// reading the initial colon
	fread (tmp, sizeof (char), 1, objfile);

	// reading the length of current section
	fread (len_buffer, sizeof (char), 2, objfile);
	CurrSection.len = ( 16 * IntfromHex( len_buffer[0]) ) + IntfromHex (len_buffer[1]);

	//reading the address to load
	fread (&address_buffer, sizeof(char), 4, objfile);
	CurrSection.address = (16 * 16 * 16 * IntfromHex ( address_buffer[0] ) ) + \
				(16 * 16 * IntfromHex ( address_buffer[1] ) ) + \
				(16 * IntfromHex ( address_buffer[2] ) ) + \
				IntfromHex ( address_buffer[3] );

	// reading the type of section
	fread (len_buffer, sizeof (char), 2, objfile);
	CurrSection.type = ( 16 * IntfromHex ( len_buffer[0])) + \
				IntfromHex (len_buffer[1]);

	//reading data and converting it to equivalent 
	// byte and storing them in data of section 

	CurrSection.data = malloc (sizeof (uint8_t) * CurrSection.len);
	for (int i = 0; i < CurrSection.len; i++) {
		fread (tmp, sizeof (char), 2, objfile);
		
		CurrSection.data[i] = (16 * IntfromHex(tmp[0] )) +  IntfromHex (tmp[1]);
	}


	// parsing the checksumaddr
	fread ( len_buffer, sizeof (char), 2, objfile);
	CurrSection.checksum = ( 16 * IntfromHex(len_buffer[0]) ) + IntfromHex (len_buffer[1]);

	// checking the checksum
	uint8_t checksum_buffer = CurrSection.address + CurrSection.len + CurrSection.type;
	for (int i = 0; i < CurrSection.len; i++)	checksum_buffer += (CurrSection.data[i]);

	// checksum = summing all bytes subtracted form 256
	checksum_buffer = 256 - checksum_buffer;
	checksum_buffer = checksum_buffer < 0? (-1 *checksum_buffer): checksum_buffer;

	if (CurrSection.checksum != checksum_buffer) {
		printf ("Checksum Error!\n");
		printf ("give valid file location\n");
		printf ("Exiting ! \n");
		exit (1);
	}

	// reading the trailing newline character form hex file
	fread ( len_buffer, sizeof (char), 2, objfile);

	return CurrSection;
}

#ifdef DEBUG

void printSection (struct section temp) {
	
		printf("length : %x \n\
address : %X \n\
checksum : %X \n\
type : %X \n", temp.len, temp.address, temp.checksum, temp.type);

	printf ("data : ");
	for (int j = 0; j < temp.len; j++)	printf("%X ",temp.data[j]);

}
#endif

int IntfromHex (char tmp) {
	switch (tmp)
	{
	case '1':
		return 1;
	case '2':
		return 2;
	case '3':
		return 3;
	case '4':
		return 4;
	case '5':
		return 5;
	case '6':
		return 6;
	case '7':
		return 7;
	case '8':
		return 8;
	case '9':
		return 9;
	case 'A':
	case 'a':
		return 10;
	case 'B':
	case 'b':
		return 11;
	case 'C':
	case 'c':
		return 12;
	case 'D':
	case 'd':
		return 13;
	case 'E':
	case 'e':
		return 14;
	case 'F':
	case 'f':
		return 15;
	case '0':
		return 0;
	default:
		return 0;
		break;
	}
}


int WriteTOCodeMemory ( char* Hex_file_addr) {

	struct section temp;
	uint16_t load_addr;
	FILE *HEXFILE = fopen (Hex_file_addr, "r");
	while (1) {
		temp = DecodeSection (HEXFILE);
		
		if (temp.type == 01) { // if its last section, dont write to code memory
			break;
		}

		load_addr = temp.address;
		for (int i = 0; load_addr < temp.address + temp.len; load_addr++, i++) {
			CPU_8051.Code_Memory[load_addr] = temp.data[i];

		}	
	}
	
	
}

#endif