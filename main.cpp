#include "lib.h"
#include "murid.h"
#include "buku.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
// var	
	int k;
	char x = '\0';

// main	
	do {
		system("cls");
		
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
				
				
				break;
			}
			
			case 'E': { // exit.
				
				exit(1);
				break;
			}
			
			default:{ // jika masukan salah.
				
				
				break;
			}
			
		}
		
//		cout << (int) x << endl;
//		Sleep(1000);
	}
	while (1);
	return 0;
}
