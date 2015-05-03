#include "murid.h"

murid::murid()
{
	int x;
	
	do {
		
		x = 0;
		
		system("cls");
		
		cout << "Menu Murid." << endl
			 << endl
			 << "Tampilkan Semua Siswa.		(S)" << endl
			 << "Tampilkan Murid Laki-Laki.	(L)" << endl
			 << "Tampilkan Murid Perempuan.	(P)" << endl
			 << "Tambah Murid.			(T)" << endl
			 << "Kembali ke Menu Utama.		(B)" << endl
			 << "Masukan Pilihan." << endl;
		
		fflush(stdin);	 
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
	int n = 0;
	char temp;
	FILE * siswa; // buffer file
	char *nama, *gender, *nim, *email, *line;
	system("cls");
	siswa = FileOpen("student.txt");
	cout << "-------------------------------------------------------------------------------" << endl
		 << left << setw(7) << "NIM" << setw(31) << "Nama" << setw(8) << "Gender" << setw(32) << "Email" << endl
		 << "-------------------------------------------------------------------------------" << endl;
	while (!feof(siswa))
	{
		if (n == 0) line = new char[82];
		line[n] = fgetc(siswa);
		
		if (line[n] == '\n')
		{
			line[n] = '\0';
			if (mode == 0)	
			puts(line);
			if (mode == 1 && line[38] == 'L')
			puts(line);
			if (mode == 2 && line[38] == 'P')
			puts(line);
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
}
