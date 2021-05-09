#include "disassembler.h"

struct section* DecodeSection (FILE *objfile, struct section *CurrSection) {

	CurrSection = malloc (sizeof (struct section));
	CurrSection->len = CurrSection->checksum = CurrSection->address = 0;
	char tmp[2]; 

	// reading the length of current section
	fread (len_buffer, sizeof (char), 2, objfile);
	CurrSection->len = ( 16 * len_buffer[0] ) + len_buffer[1];
	
	//reading the address to load
	fread (&address_buffer, sizeof(char), 4, objfile);
	CurrSection->address = (16 * 16 * 16 * IntfromHex ( address_buffer[0] ) ) + \
				(16 * 16 * IntfromHex ( address_buffer[1] ) ) + \
				(16 * IntfromHex ( address_buffer[2] ) ) + \
				IntfromHex ( address_buffer[3] ) ;
	
	

	// reading the type of section
	fread (len_buffer, sizeof (char), 2, objfile);
	CurrSection->type = atoi (len_buffer);

	//reading data and converting it to equivalent byte and storing them 
	// in data of section 

	CurrSection->data = malloc (sizeof (uint8_t) * CurrSection->len);
	for (int i = 0; i < CurrSection->len; i++) {
		fread (tmp, sizeof (char), 2, objfile);
		// not applying loop to avoid latency of initialization of new loop
		CurrSection->data[i] = (16 * IntfromHex(tmp[0] )) +  IntfromHex (tmp[1]);
	}

	// parsing the checksum
	fread ( len_buffer, sizeof (char), 2, objfile);
	CurrSection->checksum = ( 16 * IntfromHex(len_buffer[0]) ) + IntfromHex (len_buffer[1]);

	// checking the checksum
	uint8_t checksum_buffer = CurrSection->address + CurrSection->len + CurrSection->type;
	for (int i = 0; i < CurrSection->len; i++)	checksum_buffer += (CurrSection->data[i]);
	// checksum = summing all bytes and subtracting form 256
	checksum_buffer = 256 - checksum_buffer;

	if (CurrSection->checksum != checksum_buffer) {
		printf ("Checksum Error!\n");
		exit (1);
	}

	return CurrSection;
}
	

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
		return 8;
	case '8':
		return 8;
	case '9':
		return 9;
	case 'A':
		return 10;
	case 'B':
		return 11;
	case 'C':
		return 12;
	case 'D':
		return 13;
	case 'E':
		return 14;
	case 'F':
		return 15;
	case '0':
		return 0;
	default:
		return 0;
		break;
	}
}