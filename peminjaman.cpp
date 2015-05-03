#include "peminjaman.h"

peminjaman::peminjaman()
{
	int x;
	
	do {
		
// clear screen		
		system("cls");
		
// menu peminjaman
		cout << "Menu Peminjaman." << endl
			 << endl
			 << "Pinjam Buku.			(P)" << endl
			 << "Lihat Buku yang Overdue.	(O)" << endl
			 << "Tagih Buku yang Overdue.	(T)" << endl
			 << "Tagih Mahasiswa tertentu.	(M)" << endl
			 << "Kembali Buku.			(K)" << endl
			 << "Kembali ke Menu Utama.		(B)" << endl
			 << "Masukan Pilihan.";
		
		switch (toupper(getch()))
		{	
			case 'P': {
				
				break;
			}
			
			case 'O': {
				
				break;
			}
			
			case 'T': {
				
				break;
			}
			
			case 'M': {
				
				break;
			}
			
			case 'K': {
				
				break;
			}
			
			case 'B': {
				x = 1;
				break;
			}
		}
	} 
	while(x != 1);
}

peminjaman::~peminjaman()
{
}

void peminjaman::welcome()
{
	
	
	
}
