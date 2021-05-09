#ifndef DISASSEMBLE_H
#define DISASSEMBLE_H

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

struct section;

struct section {
	uint32_t address;
	uint16_t len;
	uint8_t checksum;
	uint8_t type;
	uint8_t *data;
	struct section *next;	
} HEAD;

char address_buffer[4], len_buffer[2];

struct section  DecodeSection (FILE *objfile);
int IntfromHex (char tmp);




#endif