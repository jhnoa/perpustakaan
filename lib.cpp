#include "lib.h"


FILE *FileOpen(const char *Filename)
{
	FILE * le;
	le=fopen (Filename, "r+");
	if (!le)
	le = fopen (Filename, "w+");
	fseek(le,0,SEEK_SET);
	return le;
}
