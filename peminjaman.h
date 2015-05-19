#ifndef PEMINJAMAN_H
#define PEMINJAMAN_H
#include "lib.h"

class peminjaman
{
	char * str;
	public:
		peminjaman();
		~peminjaman();
	protected:
		int carinim(char *);
		int cariid(char *);
		void pinjam();
		void kembali();
		void lihat_overdue();
		void ganti_data(char *, int, int, char*);
		int cek_over(char *, int *);
};

#endif
