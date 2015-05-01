#include "buku.h"

buku::buku()
{
	int x;
	
	do {
		
		system("cls");
		
		cout << "Menu Buku." << endl
			 << endl
			 << "Tampilkan Semua Buku.                     (S)" << endl
			 << "Tampilkan Buku yang Bisa Dipinjam.        (D)" << endl
			 << "Tampilkan Buku dengan Judul Tertentu.     (J)" << endl
			 << "Tampilkan Buku dengan Pengarang Tertentu. (P)" << endl
			 << "Kembali Ke Menu Utama.                    (B)" << endl
			 << "Masukan Pilihan.";
		fflush(stdin);	 
		switch (toupper(getch()))
		{
			
			case 'S':{
				buku::semua();
				break;
			}
			
			case 'D':{
				buku::dipinjam();
				break;
			}
			
			case 'J':{
				buku::judul();
				break;
			}
			
			case 'P':{
				buku::pengarang();
				break;
			}
			
			case 'B':{
				x = 1;
				break;
			}
		
		}
	
	}
	while (x != 1);
}

buku::~buku()
{
}

void buku::semua()
{
	
	
	
}

void buku::dipinjam()
{
	
	
	
}

void buku::judul()
{
	
	
	
}

void buku::pengarang()
{
	
	
	
}
