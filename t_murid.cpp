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
		 << "Masukkan Data.				(T)" << endl  //is T okay? from prev menu
		 << "Kembali ke Menu Murid.		(B)" << endl  //is B okay?
		 << "Masukkan pilihan.";
	
	
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
//NIM:			 unchecked
//nama:			 checked
//jenis kelamin: unchecked
//email	:		 unchecked
void t_murid::tambahmurid() {
	
	//variables
	char field[47]; //i=0-46 [47]
	char *temp;
	int x=0;
	char c;
	string s;
	
	
	temp = new char[6];
	cout << "Masukkan NIM: " << endl;
	
	
	//after inputed, nim has to be checked for its uniqueness[unchecked]
	//AND IT HAS TO BE 6 DIGITS[checked]
	//invalid 000000[unchecked]
	//add to array field
	
	//do {
	
		do {
			gets(temp);
			if(strlen(temp)==6 && temp!="000000") { //000000
				
				x=1;
				for(int i=0;i<=strlen(temp);i++) {
				
					if(i==strlen(temp)) field[i] = ' ';
					else field[i] = temp[i];
					
					
				}
				
			}
			else {
				x=0;
				cout << "NIM tidak valid. NIM harus terdiri dari 6 digit angka." << endl;
				
			}
		
		}while(x!=1);
		
	//while();
	
	
	//nim and one space is down. delete the temp
	delete[] temp;
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
			field[38] = ' ';
			
		} 
		else {
			x=0;
			cout << "error. panjang lebih dari 30. harap diulang." << endl;
			
			
		}	
	
		delete[] temp;
		
	}while(x!=1);
	//done. up to field[38]
	// next!
	
	
	// well duh, problem.
	// http://puu.sh/hAcHA/2fc1f4d707.png
	// status: unfixed
	do {
		cout << "Masukkan Jenis Kelamin(L/P): " << endl;
		x=1;
		//c=getchar(); seems like it's also take enter as input data
		cin >> s;
		
		/*
		if(s[0]=='L' || s[0]=='l') {
			field[39] = 'L';
			
		} 
		else if(s[0]=='P' || s[0]=='p') {
			field[39] = 'P';
			
		} 
		else {
			
			cout << "error. harap diulang." << endl;
			x=0;
			
			
		}
		*/
		
		///*
		switch (s[0]) {
			case 'L': case 'l':
				field[39] = 'L';
				break;
			case 'P': case 'p':
				field[39] = 'P';
				break;
			default:
				cout << "error. harap diulang." << endl;
				x=0;
				break;
		
		}
		//*/
	
	}while(x!=1);
	
	for(int i=40;i<=46;i++) {
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
				
			}
			
			
		}
		else if(c=='N') {
			//let's redirect to previous menu.
			cout << "Data batal dimasukkan." << endl;
			break;
			
			
		}
		else x=0;

		
	}while(x!=1);
	
	
}
