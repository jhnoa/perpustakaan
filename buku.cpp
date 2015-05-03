#include "buku.h"

buku::buku()
{
	int x;
	
	do {
// clear screen		
		system("cls");

// menu buku		
		cout << "Menu Buku." << endl
			 << endl
			 << "Tampilkan Semua Buku.                     (S)" << endl
			 << "Tampilkan Buku yang Bisa Dipinjam.        (D)" << endl
			 << "Tampilkan Buku dengan Judul Tertentu.     (J)" << endl
			 << "Tampilkan Buku dengan Pengarang Tertentu. (P)" << endl
			 << "Kembali Ke Menu Utama.                    (B)" << endl
			 << "Masukan Pilihan.";

// kosongkan stdin
		fflush(stdin);	 
		switch (toupper(getch()))
		{
			
			case 'S':{
				buku::semua(0);
				break;
			}
			
			case 'D':{
				buku::semua(4);
				break;
			}
			
			case 'J':{
				buku::semua(1);
				break;
			}
			
			case 'P':{
				buku::semua(2);
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

void buku::semua(int mode)
{
	int n = 0, tr = 0;
	char temp; 

// buffer file
	FILE * siswa; 
	char *line, *search;

// clear screen
	system("cls");

// simpan kata kunci
	if (mode == 1)
	{
		search = new char[30];
		cout << "Keyword yang Dicari: ";
		gets(search);
	}
	if (mode == 2)
	{
		search = new char[25];
		cout << "Keyword yang Dicari: ";
		gets(search);
	}
	
// kolom tabel
	buku::kop_tabel();
	
//	buka file
	siswa = FileOpen("book.txt");

//	baca file	
	while (!feof(siswa))
	{
		if (n == 0) line = new char[82];
		line[n] = fgetc(siswa);
		
		if (line[n] == '\n')
		{
			line[n] = '\0';	

// mode semua
			if (mode == 0)
			{
				buku::print(line);
			}
			
// mode judul
			if (mode == 1)
			{
				for (int i = 0; i < (30 - strlen(search)); i++)
				{
					for (int j = 0; j < strlen(search); j++)
					{
						if (toupper(search[j]) == toupper(line[i+j])) tr = 1;
						else {
							tr = 0;
							break;
						}
//						cout << search[i] << " = " << line[i+j] << ' ' << tr << ' ' << i << ' ' << j << endl;
					}
//				cout << "triger" << endl;
					if (tr == 1) break;
				}
				if (tr == 1) buku::print(line);
			}
// mode pengarang			
			if (mode == 2)
			{
				for (int i = 30; i < (55 - strlen(search)); i++)
				{
					for (int j = 0; j < strlen(search); j++)
					{
						if (search[j] = line[i+j]) tr = 1;
						else {
							tr = 0;
							break;
						}
					}
					if (tr == 1) break;
				}
				if (tr == 1) buku::print(line);
			}
			
// mode yang dapat dipinjam
			if (mode == 4)
			{
				if (line[79] == '*')
				buku::print(line);
			}
						
// ulangi membaca setelah '\n'
			n = 0;
			delete[] line;
		}
		else 
		{
			n++;
		}
		
	}
	fclose(siswa);
	cout << endl
		 << "Kembali ke Menu Utama? (Tekan B)";
	while(toupper(getch()) != 'B');
	if (mode == 1 || mode == 2)
	delete[] search;
	
}

void buku::dipinjam()
{
	
	
	
}

void buku::print(char * s)
{
	for (int i = 0; i< (strlen(s) - 1); i++)
	{
		cout << s[i];
	}
	cout << endl;
}

void buku::kop_tabel()
{
	cout << "-------------------------------------------------------------------------------" << endl
		 << left << setw(31) << "Judul" << setw(26) << "Pengarang" << setw(4) << "Ed." << setw(9) << "Kembali" << setw(7) << "Pinjam" << endl
		 << "-------------------------------------------------------------------------------" << endl;
}
