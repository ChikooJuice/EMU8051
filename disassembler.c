#include "disassembler.h"

void DecodeSection (FILE *objfile, struct section *CurrSection) {

	int tmp;

	/**
	 * read the length of section and store it in len of
	 * section struct
	 */
	fread (len_buffer, sizeof (char), 2, objfile);
	CurrSection->len = 0; tmp = atoi (len_buffer);
	
	if ( CurrSection->len == 0) {	// in case this is end of file
		return NULL;
	}
	//given len is in decimal, converting it in hex	
	for (int i = 0; i < 2; i++) {
		CurrSection->len += (16 * (tmp % 10));
		tmp /= 10;
	}

	
	
	
		
	// reading address 
	fread (address_buffer, sizeof(char), 4, objfile);
	CurrSection->address = atoi (address_buffer);
	fread (len_buffer, sizeof(char),2, objfile); // reading the type
	CurrSection->type = atoi (len_buffer);
	CurrSection->data = malloc (sizeof(char) * 2 * CurrSection->len);
	fread (CurrSection->data, sizeof(uint8_t), 2 * CurrSection->len, objfile);

	return CurrSection;

}
	

