#include "lib.h"
#include "murid.h"
#include "buku.h"
#include "peminjaman.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
// var	

	char x = '\0';
//	initialize();
// main	
	do {
		system("cls");
		
		tulis_log("Akses Menu Utama");
		
		cout << "Program Perpustakaan v 1.0" << endl
			 << endl
			 << "Menu Murid.	  (M)" << endl
			 << "Menu Buku.	  (B)" << endl
			 << "Menu Peminjaman.  (P)" << endl
			 << "Exit.		  (E)" << endl
			 << "Masukan Pilihan." << endl;
		fflush(stdin);
		switch(x = toupper(getch())) {
			
			case 'M': { // goto class menu.
				//convert_student();
				murid mur;
				mur.~murid();
				break;
			}
			
			case 'B': { // goto class buku.
				
				buku book;
				book.~buku();
				break;
			}
			
			case 'P': { // goto class peminjaman.
				
				peminjaman pinjam;
				pinjam.~peminjaman();
				break;
			}
			
			case 'E': { // exit.
				
				exit(1);
				break;
			}
			
		}
		
//		cout << (int) x << endl;
//		Sleep(1000);
	}
	while (1);
	return 0;
}
