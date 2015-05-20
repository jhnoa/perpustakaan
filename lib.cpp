#include "lib.h"

FILE * FileOpen (const char *Filename)
{
	FILE *le;
	
	if (!(le=fopen (Filename, "a+")))
	{
		le = fopen (Filename, "w+");
	}
	else
	{
		cout << "File " << Filename << " dibuka." << endl;
	}
	
	fseek(le,0,SEEK_SET);
	return le;
}

void tulis_log (const char * text)
{
	FILE * log;
	time_t clock;
	char * x;
	x = new char[26];
	log = fopen("log.txt", "a+");
	fseek(log, 0, SEEK_END);
	time (&clock);
	x = asctime(localtime(&clock));
	x[24] = '\0';
	fprintf(log, "[%s] - %s\n", x, text);
	fclose(log);
	delete[] x;
}

void kop_tabel_buku()
{
	cout << "-------------------------------------------------------------------------------" << endl
		 << left << setw(31) << "Judul" << setw(26) << "Pengarang" << setw(4) << "Ed." << setw(9) << "Kembali" << setw(7) << "Pinjam" << endl
		 << "-------------------------------------------------------------------------------" << endl;
}

void kop_tabel_buku_id()
{
	cout << "------------------------------------" << endl
		 << left << setw(31) << "Judul" << setw(5) << "ID"  << endl
		 << "------------------------------------" << endl;
}

void kop_tabel_murid()
{
	cout << "-------------------------------------------------------------------------------" << endl
		 << left << setw(7) << "NIM" << setw(31) << "Nama" << setw(8) << "Gender" << setw(32) << "Email" << endl
		 << "-------------------------------------------------------------------------------" << endl;
}

void kop_over()
{
	cout << "---------------------------------------------------------------------------" << endl
		 << left << setw(31) << "Judul" << "Terlambat" << endl
		 << "---------------------------------------------------------------------------" << endl;
}

int auto_numbering()
{
	int num = 0;
	char * data = new char[ID];
	FILE * file;
	file = FileOpen("book.txt");
	fseek (file, -4, SEEK_END);
	fgets(data, 4, file);
	num += (data[0] - '0') * 1000;
	num += (data[1] - '0') * 100;
	num += (data[2] - '0') * 10;
	num += (data[3] - '0') * 1;
	delete[] data;
	return num;
}

char * spesifik_data(char * str, int num)
{
	FILE * file;
	char * data;
	file = FileOpen(str);
	for (int i = 1; i <= num || !feof(file); i++)
	{
		data = new char[MAX_BUKU];
		fgets(data, 100, file);
		if(i != num) delete[] data;
	}
	fclose(file);
	return data;
	
}
