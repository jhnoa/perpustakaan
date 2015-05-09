#ifndef BUKU_H
#define BUKU_H

#include "lib.h"

class buku
{
	public:
		buku();
		~buku();
	protected:
		void semua(int);
		void dipinjam();
		void print(char *);
		void kop_tabel();
		void tambah();
};

#endif
