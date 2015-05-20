#include "murid.h"


murid::murid()
{
	tulis_log("Akses Menu Murid");
	int x;
	
	do {
		
		x = 0;

// clear screen		
		system("cls");
		
// menu murid
		cout << "Menu Murid." << endl
			 << endl
			 << "Tampilkan Semua Siswa.		(S)" << endl
			 << "Tampilkan Murid Laki-Laki.	(L)" << endl
			 << "Tampilkan Murid Perempuan.	(P)" << endl
			 << "Tambah Murid.			(T)" << endl
			 << "Kembali ke Menu Utama.		(B)" << endl
			 << "Masukan Pilihan." << endl;

// kosongkan stdin
		fflush(stdin);	 

// kondisi masukan
		switch (toupper(getch()))
		{
			
			case 'S':{
				
				murid::semua(0);
				break;
			}
			
			case 'L':{
				
				murid::semua(1);
				break;
			}
			
			case 'P':{
				
				murid::semua(2);
				break;
			}
			
			case 'T':{
				
				t_murid murid_baru;
				murid_baru.~t_murid();
				break;
			}
			
			case 'B':{
				
				
				x = 1;
				break;
			}
			
			default:{
				
			}
		
		}

	}	
	while (x != 1);
}

murid::~murid()
{
}

void murid::semua(int mode)
{
// buffer file
	FILE * siswa; 
	char *line;
	
// clear screen
	system("cls");
	
// buka file
	siswa = FileOpen("student.txt");

// kop tabel
	kop_tabel_murid(); 

// baca file
	while (!feof(siswa))
	{
		line = new char[MAX_MURID];
		fgets(line, 100, siswa);
		line[strlen(line) - 1] = '\0';
// mode semua
		if (mode == 0)	
			puts(line);
			
// mode hanya laki
		if (mode == 1 && line[38] == 'L')
			puts(line);
		
// mode hanya perempuan
		if (mode == 2 && line[38] == 'P')
			puts(line);
		
		delete[] line;
	}

// tutup file
	fclose(siswa);

// instruksi kembali
	cout << endl
		 << "Kembali ke Menu Utama? (Tekan B)";
	while(toupper(getch()) != 'B');
}
