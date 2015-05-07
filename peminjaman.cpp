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

// kosongkan stdin
		fflush(stdin);

// kondisi masukan
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

void peminjaman::pinjam()
{
/*
	char judul[31], edisi[4];
	int n;
// file buffer
	FILE *murid, *pinjam, *buku;
	
// buka file
	*buku = FileOpen("book.txt");
	*murid = FileOpen("student.txt");
	*pinjam = FileOpen("peminjaman.txt");
	
//cek judul
	cout << "Masukan Judul Buku: ";
	gets(judul);
	if (strlen(judul) > 30) 
	{
		cout << "Judul Terlalu Panjang." << endl;
		n = 0;
	}
	
	
	cout << "Masukan Edisi: "
	gets(edisi);
*/
}
