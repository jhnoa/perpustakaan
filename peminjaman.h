#ifndef PEMINJAMAN_H
#define PEMINJAMAN_H
#include "lib.h"

class peminjaman
{
	public:
		peminjaman();
		~peminjaman();
	protected:
		int carinim(char *);
		int cariID(char *);
		void pinjam();
		
};

#endif
