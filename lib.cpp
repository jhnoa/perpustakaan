#include "lib.h"

FILE * FileOpen (const char *Filename)
{
	FILE *le;
	le=fopen (Filename, "a+");
	if (!le)
	le = fopen (Filename, "w+");
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
