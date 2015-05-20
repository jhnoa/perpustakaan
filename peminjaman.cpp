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
				peminjaman::tagih_buku();
				break;
			}
			
			case 'M': {
				peminjaman::tagih_mahasiswa();
				break;
			}
			
			case 'K': {
				peminjaman::kembali();
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
	char * id, * nim, * str;
	int x, n;
	time_t rawtime;
	struct tm * timeinfo;
	
// cek nim
	do {
		system("cls");
		nim = new char[7];
		cout << "Masukan NIM Mahasiswa: ";
		gets(nim);
		if (strlen(nim) == (NIM-1))
		{
			x = peminjaman::carinim(nim);	
			if (x != 1) {cout << nim << " tidak ditemukan." <<endl; getch();}
		}
		else 
		{
			x = 0;
			delete[] nim;
		}
		
	} while (x != 1);
//	getch();
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
		else x = peminjaman::cariid(id);
		if (x != 2) delete[] id;
		if (x == -1){cout << "buku telah dipinjam"; getch();}
	} while (x != 2);
// cek tanggal sekarang
	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	n = 0;
	n += (id[0] - '0')*1000;
	n += (id[1] - '0')*100;
	n += (id[2] - '0')*10;
	n += (id[3] - '0');
	str = new char[16];
	
	sprintf(str, "%02i/%02i/%02i %-6s x", timeinfo->tm_mday, timeinfo->tm_mon +  1, (timeinfo->tm_year)%100, nim);
//	cout << temp;
	
//	cout <<num;getch();
// ganti data di book.txt
	
	peminjaman::ganti_data("book.txt", n, 61, str);
	delete[] nim;
	delete[] id;
	delete[] str;
}

void peminjaman::kembali()
{
	FILE * file;
	char * id;
	int n, x, second;
	
// cek ID
	do {
		x = 0;
		system("cls");
		id = new char[5];
		cout << "Masukan ID Buku: ";
		gets(id);
		
		if (strlen(id) == 4)
		{
			x = peminjaman::cariid(id);
//			if (x == -1) cout << "triggered" << endl;
			if (x == 2){cout << "Buku Belum Dipinjam"; getch();}
			
			else if (x == 0){cout << "ID salah." << endl; getch();}
			
		}
		else x = 0;
		if (x != -1) delete[] id;
	} while (x != -1);
	n = 0;
	n += (id[0] - '0')*1000;
	n += (id[1] - '0')*100;
	n += (id[2] - '0')*10;
	n += (id[3] - '0');
//	cout << n; getch();
// ganti data di book.txt
	str1 = new char[MAX_BUKU];
	file = FileOpen("book.txt");
	for (int i = 0; i < n; i++)
	{
		delete[] str1;
		str1 = new char[MAX_BUKU];
		fgets(str1,100,file);
	}
	fclose(file);
	if (cek_over(str1, &second) == 1)
	{
		cout << "Buku telah Overdue, Silahkan Memilih Menu Overdue."; getch();
	}
	else
		peminjaman::ganti_data("book.txt", n, 61, "--/--/-- 000000 *");
	delete[] id;
	delete[] str1;
}

int peminjaman::carinim(char * dat)
{
// file buffer
	FILE * file;
	char * data, * nim;

// definisi
	file = FileOpen("student.txt");
	
	while (!feof(file))
	{
		data = new char[81];
		nim = new char[7];
		
		fgets(data, 82, file);
		strncpy(nim, data, 6);
		
		nim[6] = '\0';
//		cout << nim << ' ' << dat << endl;
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


// 0 = gk cocok
// 2 = cocok belum dipinjam
// -1 = cocok dipinjam
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
	
	*second = difftime(now, mktime(&n))/86400;
	
	//cout << day << month << year << endl;
	
	if(*second>21) return 1;
	else return -1;
}

void peminjaman::lihat_overdue()
{
   FILE * pFile;
   char * buku;
   int second;
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

	cout << "	";
	if (strlen(buku)!=0)
	cout << second << "Hari"<< endl;
	delete[] buku;
	}
	}
	fclose(pFile);
	getch();
}
void peminjaman::ganti_data(char * namafile, int num, int start, char * str)
{
	char x;
//	cout << str << endl;
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
//				cout << x << endl;
				/*
				baca[j] = str[j-start];
				cout << baca[j] << ' ' << str[j-start] << endl;
				*/
			}
//			cout << baca;
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

void peminjaman::tagih_mahasiswa()
{
	int x;
	FILE * file;
	int a = 0;
	char * nim, * data, * tempnim;
	system("cls");
	nim = new char[NIM];
	cout << "Masukan NIM Mahasiswa. ";
	gets(nim);
	file = FileOpen("book.txt");
	kop_tagih_murid();
	while(!feof(file))
	{
		data = new char[MAX_BUKU];
		fgets(data, 100, file);
		tempnim = new char[NIM];
		a = 0;
		for (int i = 79; i < 84; i++)
		{
			tempnim[i-79] = data[i];
		}
//		cout << tempnim << ' ' << nim;
		x++;
		if (strcmp(tempnim,nim) == 0)
		{
			peminjaman::ganti_data("book.txt", x, 61, "--/--/-- 000000 *");
			cout << "NIM Mahasiswa: " << nim << endl;
			for(int i = 0; i < 30; i++) cout << data[i];
			if ((a-21) > 0)	cout << ' ' << setw(5) << a << " hari " << (a-21)*3000 << "rupiah";
			else cout << ' ' << setw(5) << a << " hari " << "0" << "rupiah";
		}
		
	}
	getch();
	fclose(file);
}
void peminjaman::tagih_buku()
{

FILE * pFile;   

char buku[100];
 
int n;
char idbukua[4];
char * idbukub;
time_t now;
now = time(NULL);
int second;
int x;

system("cls");

	cout << "Masukan ID buku :";
	gets(idbukua);
	if(strlen(idbukua) > 4)
	{
		cout << "ID buku lebih dari 4 digit. Ulangi." << endl;
	}
	else
	{
		pFile = fopen ("book.txt" , "r");
		
		do {
			
			fgets(buku , 100 , pFile);
			idbukub = new char[4];
			for (int i = 0; i < 4; i++)
			{
				idbukub[i]=buku[i+79];
			}	
			if(strcmp(idbukua, idbukub) == 0)
			{
				
				if(buku[61] == '-')
				{
					int a = 0;
					while(a<30)
					{
						cout << buku[a];
						a++;
					}
					cout << "Buku belum di pinjam" << endl;
					x = 0;
					break;
				}
				else
				{
					int day = (buku[61]-'0')*10 + (buku[62]-'0');
	    			int month = ((buku[64]-'0')*10 + (buku[65]-'0'))-1;
					int year = ((buku[67]-'0')*10 + (buku[68]-'0'))+100;
					
					struct tm n = *localtime(&now);
					n.tm_mday = day; 
					n.tm_mon = month; 
					n.tm_year = year;
			
					second = difftime(now, mktime(&n))/86400;
					
					if(second>21)
					{
						for(int a = 0; a < 30; a++)
						{
							cout << buku[a];
						}
						cout << endl << "Terlambat " << second - 21 << " Hari" << endl 
							 << "Tagihan :" << (second-21)*3000 << " Rupiah" << endl;
						x = 1;
						break;
					}
					else 
					{
						for (int a = 0; a<30; a++)
						{
							cout << buku[a];
						}
						cout << "	" << "Sudah dipinjam selama " << second << " hari" << endl
							 << "Tidak ada denda.";
						 x = 1;
						 break;
					}
				}
			}
			else x = -1;
			
			delete[] idbukub;
		} while(!feof(pFile));
		fclose(pFile);
		if (x == -1)
		{
			cout << "ID buku tidak ada yang sama dengan ID buku dalam perpustakaan" << endl;
		}
			
	}
	if(x==1)
	{
		n = 0;
		n += (idbukub[0] - '0')*1000;
		n += (idbukub[1] - '0')*100;
		n += (idbukub[2] - '0')*10;
		n += (idbukub[3] - '0');
		peminjaman::ganti_data("book.txt", n, 61, "--/--/-- 000000 *");
	}
	getch();
}
