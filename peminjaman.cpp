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
				peminjaman::lihat_overdue();
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

void peminjaman::lihat_overdue()
{
   FILE * pFile;
   char * buku;
   time_t now;
   now = time(NULL);
   int second;
   //struct tm n = *localtime(&now);    

   pFile = fopen ("book.txt" , "r");
	system("cls");
    while(!feof(pFile))
    {
    buku = new char[86];
    fgets (buku , 100 , pFile);
//    puts (buku);
    // fclose (pFile);
    if (buku[61] == '-') continue;
    int day = (buku[61]-'0')*10 + (buku[62]-'0');
    int month = ((buku[64]-'0')*10 + (buku[65]-'0'))-1;
	int year = ((buku[67]-'0')*10 + (buku[68]-'0'))+100;
	
	struct tm n = *localtime(&now);
	n.tm_mday = day; 
	n.tm_mon = month; 
	n.tm_year = year;
	
	second = difftime(now, mktime(&n))/86400;
	
	//cout << day << month << year << endl;
	
	if(second>21)
	{
		int i = 0;
		while(i <30)
		{
			cout << buku[i];
			i++;
		}
		
	}

	cout << "	";
	if (strlen(buku)!=0)
	cout << "overdue" << " " << "by" << " " << second <<  "days" << endl;
	delete[] buku;
	
	}
	fclose(pFile);
	getch();
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
