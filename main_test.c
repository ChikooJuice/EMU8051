#include "disassembler.h"
#include <stdlib.h>
#include <string.h>

struct section *main_head;

int main (int argc, char *argv[]) {

	FILE *objfile;
	objfile = fopen ("test.hex", "rb");
	
	struct section *temp; char buffer;

	fread (&buffer, sizeof (char), 1, objfile); 
	if (buffer == ':') {
		
		printf ("new section start \n");
		main_head = DecodeSection (objfile, main_head);

		printf ("%x \n", main_head);
	}
	temp = main_head;
	fread (&buffer, sizeof (char), 1, objfile);
	fread (&buffer, sizeof (char), 1, objfile);

	temp->next = DecodeSection (objfile, temp->next);
	temp = temp->next;

	printf ("head -> next : %x \n", temp->next);

}