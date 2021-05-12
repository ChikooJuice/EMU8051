#include "disassembler.h"
#include <stdlib.h>
#include <string.h>

struct section dissasmbl_list;
void printSections ();

int main (int argc, char *argv[]) {

	FILE *objfile;
	objfile = fopen ("test.hex", "rb");
	char tmp;

	/** initial read */
	fread (&tmp, sizeof (char), 1, objfile); // reading first colon
		if (tmp != ':') {
		printf ("invalid file \n");
		exit;
	}
	dissasmbl_list = DecodeSection (objfile);
	if (dissasmbl_list.type == 0) {
		struct section *pntr = &dissasmbl_list;
		while (1) {
			pntr->next = malloc (sizeof (struct section));
			
			for (int i = 1; i < 4; i++) {
				fread (&tmp, sizeof(char), 1, objfile);
			}

			*pntr->next = DecodeSection (objfile);
			if (pntr->next->type == 01) {
				pntr->next->next = NULL;
				break;
			}
			pntr = pntr->next;
		}
	}

	printf ("Going to enter printSections function \n");
	printSections(&dissasmbl_list);
	

}







