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
			 << "Tambah Buku.				  (T)" << endl
			 << "Kembali Ke Menu Utama.                    (B)" << endl
			 << "Masukan Pilihan.";

// kosongkan stdin
		fflush(stdin);	 

// kondisi masukan
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
			
			case 'T':{
				buku::t_buku();
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
	int tr = 0; 

// buffer file
	FILE * siswa; 
	char *line, *search, *show;

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
	kop_tabel_buku();
	
//	buka file
	siswa = FileOpen("book.txt");

//	baca file
	while (!feof(siswa))
	{
		tr = 0;
		line = new char[86];
		show = new char[86];
		fgets(line, 100, siswa);
		strncpy(show,line,76);
		show[76] = '\n';
		show[77] = '\0';

//		cout << line << endl;
// mode semua
		if (mode == 0)
		{
			if (sizeof(siswa) != 0)
			cout << show;
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
//					cout << search[i] << " = " << line[i+j] << ' ' << tr << ' ' << i << ' ' << j << endl;
				}
//			cout << "triger" << endl;
				if (tr == 1) break;
			}
			if (tr == 1) cout << show;
		}
		
// mde pengarang			
		if (mode == 2)
		{
			for (int i = 30; i < (55 - strlen(search)); i++)
			{
				for (int j = 0; j < strlen(search); j++)
				{
					if (toupper(search[j]) == toupper(line[i+j])) tr = 2;
					else {
						tr = 0;
						break;
					}
				}
				if (tr == 2) break;
			}
			if (tr == 2) cout << show;
		}
		
// mde yang dapat dipinjam
		if (mode == 4)
		{
			if (line[77] == '*') cout << show;
		}
					
		delete[] line;
		delete[] show;
	}
	
// setelah selesai membaca, tutup file
	fclose(siswa);
	if (mode == 1 || mode == 2)	delete[] search;
// instruksi kembali
	cout << endl
		 << "Kembali ke Menu Utama? (Tekan B)";
	while(toupper(getch()) != 'B');
}



void buku::t_buku()
{
	char * judul, * pengarang, * edisi, * buku;
	FILE * file;
	
	int x, num;
	
	system("cls");
	do {
		cout << "Masukan Judul: ";
		judul = new char[31];
		gets (judul);
		if (strlen(judul) < 31) 
		{
			x = 1;
			cout << endl;
		}
		else
		{
			cout << "Error. Karakter lebih dari 30." << endl;
			x = 0;
			delete[] judul;
		}
	} while (x != 1);
	
	do {
		cout << "Masukan Pengarang: ";
		pengarang = new char[26];
		gets (pengarang);
		if (strlen(pengarang) < 26) 
		{
			x = 2;
			cout << endl;
		}
		else
		{
			cout << "Error. Karakter lebih dari 25." << endl;
			x = 0;
			delete[] judul;
		}
	} while (x != 2);
	
	do {
		cout << "Masukan Edisi: ";
		edisi = new char[4];
		gets (edisi);
		if (strlen(edisi) < 4) 
		{
			x = 3;
			cout << endl;
		}
		else
		{
			cout << "Error. Karakter lebih dari 3." << endl;
			x = 0;
			delete[] judul;
		}
	} while (x != 3);
	
	file = FileOpen("book.txt");
	num = 0;
	if (sizeof(file) != 0)
	{
		fseek(file, -4, SEEK_END);
		num += (fgetc(file)-'0') * 1000;
		num += (fgetc(file)-'0') * 100;
		num += (fgetc(file)-'0') * 10;
		num += (fgetc(file)-'0') * 1;
	}
	num++;
	buku = new char[87];
	
	if (sizeof(file) != 0)
	sprintf(buku, "\n%-30s %-25s %-3s --/--/-- 000000 * %04i", judul, pengarang, edisi, num);
	else
	sprintf(buku, "%-30s %-25s %-3s --/--/-- 000000 * %04i", judul, pengarang, edisi, num);
	
	fseek(file, 0, SEEK_END);
	fputs(buku, file);
	fclose(file);
	delete[] judul;
	delete[] pengarang;
	delete[] edisi;
	delete[] buku;
	cout << "Silahkan berikan label bernomorkan " << num << " pada buku yang didaftarkan.";
	getch();
	
}

/*
void buku::tambah()
{	FILE *fp;
	fp = fopen("book.txt", "a+");
	 
	int x;
	char *temp, buku[80];
	
	do{
	system("cls");
		do {
			temp = new char[30];
			cout << "Masukan Judul: ";
			gets(temp);
			if (strlen(temp) <= 30)
			{
				x = 1;
				cout << endl;
			}
			else
			{
				x = 0;
				cout << "error. panjang lebih dari 30. harap diulang";
				delete[] temp;
			}
		} while (x != 1);
	
		//cout << temp << endl;
	
		for(int i = 0;i<strlen(temp); i++ )
		{
			buku[i] = temp[i];
		}
		for(int i= strlen(temp); i<30; i++)
		{
			buku[i] = ' ';
		}
		delete[] temp;
		buku[30] = ' ';
		
		do {
			temp = new char[25];
			cout << "Masukan Pengarang: ";
			gets(temp);
			if (strlen(temp) <= 25)
			{
				x = 1;
				cout << endl;
			}
			else
			{
				x = 0;
				cout << "error. panjang lebih dari 25. harap diulang";
				delete[] temp;
			}
		} while (x != 1);
		//cout << temp << endl;
				
		for(int i = 0; i<strlen(temp); i++ )
		{
			buku[i+31] = temp[i];
		}
		for(int i= (31+strlen(temp)); i<57; i++)
		{
			buku[i] = ' ';
		}	
	
	
		do {
			temp = new char[3];
			cout << "Masukan Edisi: ";
			gets(temp);
			if (strlen(temp) <= 3)
			{
				x = 1;
				cout << endl;
			}
			else
			{
				x = 0;
				cout << "error. panjang lebih dari 3. harap diulang" << endl;
				delete[] temp;
			}
		} while (x != 1);
		//cout << temp << endl;
				
		for(int i = 0; i<strlen(temp); i++ )
		{
			buku[i+57] = temp[i];
		}
		for(int i= (57+strlen(temp)); i<61; i++)
		{
			buku[i] = ' ';
		}	
		
		do {
			temp = new char[8];
			cout << "Masukan Tanggal Kembali (dd/mm/yy): ";
			gets(temp);
			if (strlen(temp) <= 8)
			{
				if (temp[2] == '/' && temp[5] == '/')
				{
					x = 1;
					cout << endl;
				}
				else
				{
					x = 0;
					cout << "error. format tidak sesuai." << endl;
					delete[] temp;
				}
			}
			else
			{
				x = 0;
				cout << "error. panjang lebih dari 8. harap diulang" << endl;
				delete[] temp;
			}
		} while (x != 1);
		//cout << temp << endl;
				
		for(int i = 0; i<strlen(temp); i++ )
		{
			buku[i+61] = temp[i];
		}
		for(int i= (61+strlen(temp)); i<70; i++)
		{
			buku[i] = ' ';
		}	
		
		do {
			temp = new char[6];
			cout << "Masukan NIM: ";
			gets(temp);
			if (strlen(temp) <= 6)
			{
				x = 1;
				cout << endl;
			}
			else
			{
				x = 0;
				cout << "error. panjang lebih dari 6. Harap diulang." << endl;
				delete[] temp;
			}
		} while (x != 1);
		//cout << temp << endl;
				
		for(int i = 0; i<strlen(temp); i++ )
		{
			buku[i+70] = temp[i];
		}
		for(int i= (70+strlen(temp)); i<76; i++)
		{
			buku[i] = ' ';
		}	
		buku[76] = '\n';
		buku[78] = '\0';
	}while(x != 1 );
//	cout << buku;
	
//	for (int i = 0; i< strlen(buku); i++)cout << "buku[" << i << "] = " << buku[i] << endl;
	
	fputs(buku, fp);
	fclose(fp);
}
*/
