#ifndef PEMINJAMAN_H
#define PEMINJAMAN_H
#include "lib.h"

class peminjaman
{
	char * str, * str1;
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
		void tagih_mahasiswa();
		void tagih_buku();		
};

#endif
