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
				
				murid::semua();
				break;
			}
			
			case 'L':{
				
				murid::laki();
				break;
			}
			
			case 'P':{
				
				murid::perempuan();
				break;
			}
			
			case 'T':{
				
				
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

murid::~murid()
{
}

void murid::semua()
{
	int n = 0;
	char temp;
	FILE * siswa; // buffer file
	char *nama, *gender, *nim, *email, line[79];
	system("cls");
	siswa = FileOpen("student.txt");
	cout << "-------------------------------------------------------------------------------" << endl
		 << left << setw(7) << "NIM" << setw(31) << "Nama" << setw(8) << "Gender" << setw(32) << "Email" << endl
		 << "-------------------------------------------------------------------------------" << endl;
	while (!feof(siswa))
	{
		line[n] = fgetc(siswa);
//		cout << (int)line[n]; // << ' '; 
		if (line[n] == '\n')
		{	
			//cout << left << setw(7) << "NIM" << setw(31) << "Nama" << setw(8) << "Gender" << setw(32) << "Email" << endl;
			//cout << endl;
//			cout << "triggered!";
			
			puts(line);
//			cout << n;
			n = 0;
//			memset(line, '  ', 90);
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

void murid::laki()
{
	
	
	
}

void murid::perempuan()
{
	
	
	
}
