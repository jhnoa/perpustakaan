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
				peminjaman::kembali();
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
	char * id, * nim;
	int n, x;
	time_t rawtime;
	struct tm * timeinfo;
	
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
		}
		else 
		{
			x = 0;
			delete[] nim;
		}
		
	} while (x != 1);
	
// cek ID
	do {
		x = 0;
		system("cls");
		id = new char[5];
		cout << "Masukan ID Buku: ";
		gets(id);
		
		if (strlen(id) != 4)
		{
			cout << "ID salah." << endl;
			x = 0;
		}
		x = peminjaman::cariid(id);
		if (x != 2) delete[] id;
		if (x == -1){cout << "buku telah dipinjam"; getch();}
	} while (x != 2);
// cek tanggal sekarang
	time ( &rawtime );
	timeinfo = localtime ( &rawtime );

	str = new char[16];

	sprintf(str, "%02i/%02i/%02i %-6s x\0", timeinfo->tm_mday, timeinfo->tm_mon, (timeinfo->tm_year)%100, nim);
//	cout << temp;
	
//	cout <<num;getch();
// ganti data di book.txt
	peminjaman::ganti_data("book.txt", auto_numbering(), 61, str);
	delete[] nim;
	delete[] id;
	delete[] str;
}

void peminjaman::kembali()
{
	char * id;
	int n, x;
	
// cek ID
	do {
		x = 0;
		system("cls");
		id = new char[5];
		cout << "Masukan ID Buku: ";
		gets(id);
		
		if (strlen(id) != 4)
		{
			cout << "ID salah." << endl;
			x = 0;
		}
		x = peminjaman::cariid(id);
		if (x != -1) delete[] id;
	} while (x != -1);
	n = 0;
	n += (id[0] - '0')*1000;
	n += (id[1] - '0')*100;
	n += (id[2] - '0')*10;
	n += (id[3] - '0');
	cout << n; getch();
// ganti data di book.txt
	peminjaman::ganti_data("book.txt", n, 61, "--/--/-- 000000 *");
	delete[] id;
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
	fclose(file);
	return -1;
}



int peminjaman::cariid(char * dat)
{
// file buffer
	FILE * file;
	char * data;
	int tr;
	file = FileOpen("book.txt");
//	cout << 'a';
	while (!feof(file))
	{
		tr = 0;
		data = new char[86];
		fgets(data, 100, file);
//		cout << data;
		
		for (int i = 0; i < 4; i++)
		{
		//	cout << dat[i] << " = " << data[i+79] << ' ' << tr << ' ' << i << endl; getch();
			if (toupper(dat[i]) == toupper(data[79 + i])) tr = 2;
			else {
				tr = 0;
				break;
			}
		}
		if (tr == 2 && data[77] == 'x')
		{
			tr = -1;
		}
		delete[] data;
		if (tr == 2 || tr == -1) break;
	}
	fclose(file);
	return tr;
}
int peminjaman::cek_over(char * buku, int * second)
{
	time_t now;
	now = time(NULL);
	int day = (buku[61]-'0')*10 + (buku[62]-'0');
    int month = ((buku[64]-'0')*10 + (buku[65]-'0'))-1;
	int year = ((buku[67]-'0')*10 + (buku[68]-'0'))+100;
	
	struct tm n = *localtime(&now);
	n.tm_mday = day;
	n.tm_mon = month; 
	n.tm_year = year;
	
	* second = difftime(now, mktime(&n))/86400;
	
	//cout << day << month << year << endl;
	
	if(* second>21) return 1;
	else return -1;
}
void peminjaman::lihat_overdue()
{
   FILE * pFile;
   char * buku;
   time_t now;
   now = time(NULL);
   int second;
   int denda;
   //struct tm n = *localtime(&now);    
	system("cls");
	kop_over();
	pFile = fopen ("book.txt" , "r");
    while(!feof(pFile))
    {
    buku = new char[86];
    fgets (buku , 100 , pFile);
//    puts (buku);
    // fclose (pFile);
    if (buku[61] == '-') continue;
	if(peminjaman::cek_over(buku, &second) == 1)
	{
		int i = 0;
		while(i <30)
		{
			cout << buku[i];
			i++;
		}
		
		
		denda = second*3000;
		cout << "	";
		if (strlen(buku)!=0)
		cout << second << setw(10) << " Hari"<< denda <<" Rupiah" << endl;
		delete[] buku;
	}
	}
	fclose(pFile);
	getch();
}
void peminjaman::ganti_data(char * namafile, int num, int start, char * str)
{
	char x;
	cout << str << endl;
	FILE * awal, * akhir;
	awal = FileOpen(namafile);
	akhir = FileOpen("temp");
	
	for (int i = 1; !feof(awal); i++)
	{
		char * baca = new char[MAX_BUKU];
		fgets(baca, 100, awal);
		if (i != num)
		{
			fputs(baca, akhir);
		}
		else 
		{
			
			for (int j = 0; j < strlen(baca); j++)
			{
				if (j >= start && j < (start + strlen(str)))
					x = str[j-start];
				else
					x = baca[j];
				fputc(x, akhir);
				cout << x << endl;
				/*
				baca[j] = str[j-start];
				cout << baca[j] << ' ' << str[j-start] << endl;
				*/
			}
			cout << baca;
			//fputs(baca, akhir);
		}
		
		delete[] baca;
	}
	getch();
	fclose(awal);
	fclose(akhir);
	remove(namafile);
	rename("temp", namafile);
	
}
