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
				peminjaman::pinjam();
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
	char * ID, * edisi, *nim;
	int n, x;
	
// cek nim
	do {
		system("cls");
		nim = new char[7];
		cout << "Masukan NIM Mahasiswa: ";
		gets(nim);
		if (strlen(nim) == 6)
		{
			x = peminjaman::carinim(nim);	
			if (x != 1) cout << nim << " tidak ditemukan." <<endl;
			delete[] nim;
		}
		else 
		{
			x = 0;
			delete[] nim;
		}
		
	} while (x != 1);
	
// cek ID
	do {
		system("cls");
		ID = new char[5];
		cout << "Masukan ID Buku: ";
		gets(ID);
		if (strlen(ID) > 4)
		{
			cout << "ID salah." << endl;
			x = 0;
		}
		x = peminjaman::cariID(ID);
	} while (x != 2);

}

int peminjaman::carinim(char * dat)
{
// file buffer
	FILE * file;
	char * data, temp, * nim;
	int x = 0;

// definisi
	file = FileOpen("student.txt");
	
	while (!feof(file))
	{
		data = new char[81];
		nim = new char[7];
		
		fgets(data, 82, file);
		strncpy(nim, data, 6);
		
		nim[6] = '\0';
		
		if (strcmp(nim, dat) == 0)
		{
			delete[] data;
			delete[] nim;
			return 1;
		} 
		else 
		{
			delete[] data;
			delete[] nim;
		}
	}
	return -1;
	fclose(file);
}
int peminjaman::cariID(char * dat)
{
// file buffer
	FILE * file;
	char * data;
	int x = 0, n = 0, tr;
	file = FileOpen("book.txt");
	while (!feof(file))
	{
		data = new char[86];
		fgets(data, 100, file);
//		cout << data;
		for (int i = 0; i < 4; i++)
		{
			cout << dat[i] << " = " << data[i+79] << ' ' << tr << ' ' << i << endl; getch();
			if (toupper(dat[i]) == toupper(data[79+i])) tr = 2;
			else {
				tr = 0;
				break;
			}
			
			if (tr == 2) break;
		}
		delete[] data;
//		if (tr == 1) cout << show;
	}
	fclose(file);
	return tr;
}
