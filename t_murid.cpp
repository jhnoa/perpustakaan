#include "t_murid.h"

t_murid::t_murid()
{	
	// not sure how to do this. i'm going to mess up.
	// will drop comment as erv to make it easy to find.
	
	
	// clear screen		
	system("cls");
	
	// menu tambah murid	
	cout << "Menu Tambah Murid." << endl
		 << endl
		 << "Masukkan Data.			(T)" << endl  //is T okay? from prev menu
		 << "Kembali ke Menu Murid.		(B)" << endl  //is B okay?
		 << "Masukkan pilihan." << endl;
	              
	
	
	// copy-pasting
	// kosongkan stdin
	fflush(stdin);	 
	
	switch (toupper(getch())) {			
		case 'T':
			
			t_murid::tambahmurid();
			break;
			
		case 'B':
			
			// i dont know what happens here.
			break;
		
		
	}
	
	
}

t_murid::~t_murid()
{
}

//displaying menus for adding (a) new student field
//this version: successfully insert new field
//verification:
//NIM:			 checked
//nama:			 checked (temporarily)
//jenis kelamin: unchecked
//email	:		 unchecked
void t_murid::tambahmurid() {
	
	//variables
	char field[47]; //i=0-45 [46]
	char *temp, * tempnim, * tempdata;
	int x=0;
	char c;
	string s;
	FILE * ceknim;
	
	
	// clear screen		
	system("cls");

	
	// main

	
	
	//after inputed, nim has to be checked for its uniqueness[unchecked]
	//6 DIGITS limitation[checked]
	//invalid 000000[CHECKED]
	//integer only [CHECKED]
	//add to array field
	
	//do {
	
		do {
			temp = new char[6];
			cout << "Masukkan NIM: " << endl;
			gets(temp);
			s = temp;
			if(strlen(temp)==6 && s!="000000") { //000000
				
				x=1;
				for(int i=0;i<6;i++) {
					
					if(!isdigit(temp[i])) x=0;
					
				}
				
			} else x=0;
			
			
			if(x==1) {
				
				ceknim = FileOpen("student.txt");
				while (!feof(ceknim))
				{
					tempdata = new char[81];
					tempnim = new char[7];
					fgets(tempdata,100,ceknim);
//					puts(tempdata);
					
					if (strncmp(temp, tempdata, 5) == 0)
					{
						x = 0;
						break;
					}
					else x = 1;
				}
				fclose(ceknim);
				if (x == 0)	cout << "Nim telah terdaftar." << endl;
			}
			else {
				
				cout << "NIM tidak valid. NIM harus terdiri dari 6 digit angka." << endl;
				
			}
			delete[] temp;
		}while(x!=1);
		
	//while();
	
	
	//nim and one space is down. delete the temp

	//next!
	
	
	cout << "Masukkan Nama: " << endl;
	
	do {
		temp = new char[30];
		gets(temp);
		
		
		//check if true
		if(strlen(temp)<=30) {
			x=1;
			
			for(int i=0;i<=30;i++) {
		
				if(i<strlen(temp)) field[i+7] = temp[i];
				else field[i+7] = ' ';
			
			}
			//field[38] = ' ';
			
		} 
		else {
			x=0;
			cout << "error. panjang lebih dari 30. harap diulang." << endl;
			
			
		}	
	
		delete[] temp;
		
	}while(x!=1);
	//done. up to field[38] harusnya field[37] karena index mulai dari 0
	// next!
	
	
	// well duh, problem.
	// http://puu.sh/hAcHA/2fc1f4d707.png
	// status: unfixed
	do {
		cout << "Masukkan Jenis Kelamin(L/P): " << endl;
		x=1;
		//c=getchar(); seems like it's also take enter as input data
		cin >> s;
		
		//changing the index all!!!
		switch (s[0]) {
			case 'L': case 'l':
				field[38] = 'L';
				break;
			case 'P': case 'p':
				field[38] = 'P';
				break;
			default:
				cout << "error. harap diulang." << endl;
				x=0;
				break;
		
		}
	
	}while(x!=1);
	
	for(int i=39;i<=45;i++) {
		field[i] = ' ';
		
	}

	//next, email
	
	string email;
	cout << "Masukkan Email: " << endl;
	cin >> email;
	
	//how to check email, btw?
	//i will return 0 for false, and 1 for true.
	//make function later!!!!
	
	
	//displaying field to confirm before applying data
	
	cout << endl << "Data murid:\n" << field << email << endl;
	
	do {
		
		FILE *student;
		cout << "apply? (Y/N)" << endl;
		
		// char c
		
		//c=getchar();
		cin >> c;
		
		if(c=='Y') {
			//this menu adds a new field, so file mode is "a"
			student = fopen("student.txt","a");
			
			//err... what to do here?
			if(student==NULL) {
				cout << "no database available." << endl;
				//exit(1);
				//cant do exit... then just break
				break;
			}
			else {
				
				fprintf(student, "%s%s\n", field, email.c_str());
				
				//fclose(student); cuz i am paranoid
				do {
					x = fclose(student);
				}while(x!=0);
				
				x=1;
				cout << "Successfully written." << endl;
				
				// after cout, program immediately returns to MENU MURID less than a second.
				
			}
			
			
		}
		else if(c=='N') {
			//let's redirect to previous menu.
			//how?
			cout << "Data batal dimasukkan." << endl;
			break;
			
			
		}
		else x=0;

		
	}while(x!=1);
	
	
}
