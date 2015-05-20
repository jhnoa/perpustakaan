#include "t_murid.h"

t_murid::t_murid()
{	
	int x;
	
	do{
		x = 0;
		
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
			case 'T':{
				
				t_murid::tambahmurid();
				break;
			}
			case 'B':{
				x = 1;
				// i dont know what happens here.
				break;
			}
			
		}
		
	}while (x != 1);
}


t_murid::~t_murid()
{
}


int t_murid::isemail() {
	
	//check for alphabet
	//valids only to alphanumerik, underscore, with @domain
	//maximum length is <64 each
	
	//variables
	//string email; how to convert into array??
	int length1, length2, length;
	int domain_begin=0;
	int bool_dot=0;
	char temp[email.length()+1]; //good thing is, this works.
	//delete[] temp; doesnt work. core dumped.
	//temp = new char[email.length()+1];
	//WARNING: when am i going to delete[] temp?
	strcpy(temp,email.c_str());
	length = strlen(temp);
	//&temp = email.
	
	//cout <<  temp[0] << endl << temp[1];
	
	for(int i=0;i<length;i++) {
		
		if(temp[i]==' ') return 0;
		
		if(!isalnum(temp[i])) {
			
			if(temp[i]=='@') {
				if(domain_begin!=0) return 0; //if there's more @
				domain_begin=i;
				length1=i;
				length2=length-1-i;
			}
			
			//first length conditions
			if(domain_begin==0) {
				if(i==0 || i==length-1) return 0; //first and last has to be alphanum
				if(temp[i]!='_') return 0;
				if(temp[i]=='_' && temp[i+1]=='_') return 0;
				
			
			} 
			else { //temp[domain_begin]='@'
			
				if(temp[i]=='.') bool_dot = 1;
				
				if(!isalnum(temp[domain_begin+1]) || !isalnum(temp[domain_begin-1])) return 0; //12a@12b
				if(length1>63 || length2>63) return 0;
				if(temp[i]=='.' && temp[i+1]=='.') return 0;
				
				// an exception for test@io [DOESNT WORK T_____T] then make a temporary minimal . domain
				/* 
				if(temp[i]=='.') bool_dot = 1;
					if(i==length-1 && bool_dot==0) {
						if(length2!=2) return 0;
						if(temp[length-2]!='i' || temp[length-1]!='o') return 0; 
						
					}
				*/
				
				
				
				
			}
			
			
		}
		
		if(i==length-1 && domain_begin==0) return 0;	//if there's no @
		
		
	}
	
	// condition replacement for test@io
	if(bool_dot==0) return 0;
	return 1;
	
}


//displaying menus for adding (a) new student field
//this version: successfully insert new field
//verification:
//NIM:			 checked
//nama:			 checked (don't accept blank name: UNCHECKED)(must alphabet only?? unchecked)
//jenis kelamin: checked
//email	:		 checked (test@io unchecked]
void t_murid::tambahmurid() {
	
	//variables
	char field[46]; //i=0-45 [46]
	char *temp, *data, *nim;
	int x=0;
	char c;
	FILE *student;
	string s;
	
	
	// clear screen		
	system("cls");

	
	// main
	temp = new char[6];
	cout << "Masukkan NIM: " << endl;
	
	
	//after inputed, nim has to be checked for its uniqueness[unchecked]
	//6 DIGITS limitation[checked]
	//invalid 000000[CHECKED]
	//integer only [CHECKED]
	//add to array field
	
		
	do {
		gets(temp);
		s = temp;
		if(strlen(temp)==6 && s!="000000") { 
		
			//000000

			x=1;
			for(int i=0;i<6;i++) {
			
				if(!isdigit(temp[i])) x=0;
				
			}
			
			if(x==1) {
				// temp[6] is here
			
				student = FileOpen("student.txt");
			
				while (!feof(student))
				{
					data = new char[81];
					nim = new char[7];
					
					fgets(data, 82, student);
					strncpy(nim, data, 6);
					
					nim[6] = '\0';
					
					if (strcmp(nim, temp) == 0)
					{
						delete[] data;
						delete[] nim;
						x=1;
					} 
					else 
					{
						delete[] data;
						delete[] nim;
						x=4;
						break;
					}
				}
				fclose(student);
				
			}
		
		} else x=0;
		
		
		
		if(x==1) {
			
			for(int i=0;i<=strlen(temp);i++) {
			
				if(i==strlen(temp)) field[i] = ' ';
				else field[i] = temp[i];
				
			}
			
		}
		else if(x==0){
			
			cout << "NIM tidak valid. NIM harus terdiri dari 6 digit angka." << endl;
			
		}
		else if(x==4){
			cout << "NIM mahasiswa telah terdaftar." << endl;
			
		}
	
	}while(x!=1);
	
	
	delete[] temp;
	//
	
	
	// nama
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
			//field[37] = ' ';
			
		} 
		else {
			x=0;
			cout << "error. panjang lebih dari 30. harap diulang." << endl;
			
			
		}	
	
		delete[] temp;
		
	}while(x!=1);
	//
	
	
	// jenis kelamin
	// only accepts 'L' or 'P' for both upper/lower [CHECKED]
	do {
		
		temp = new char[1];
		cout << "Masukkan Jenis Kelamin(L/P): " << endl;
		x=1;
		gets(temp);
		
		if(strlen(temp)==1) {
			
			switch (temp[0]) {
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
			
		}
		else {
			
			cout << "error. harap diulang." << endl;
			x=0;
			
		}
	
	}while(x!=1);
	
	for(int i=39;i<=45;i++) {
		field[i] = ' ';
		
	}
	//

	
	
	// email
	// using isemail function to validate
	do {
		
		x=1;
		cout << "Masukkan Email: " << endl;
		cin >> email;
		
		if(!t_murid::isemail()) {
			
			x=0;
			cout << "email tidak valid. harap diulang." << endl;
			
		}
		//testing to call function. it works
		//cout << t_murid::emailchecker() << endl;
		
	
	}while(x!=1);
	//
	
	
	//displaying field to confirm before applying data
	
	cout << endl << "Data murid:\n" << field << email << endl;
	
	do {
		
		
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
				
//				fprintf(student, "%s%s\n", field, email.c_str());
				
				if (sizeof(student) != 0) fprintf(student, "\n%s%s", field, email.c_str());
				else fprintf(student, "%s%s", field, email.c_str()); //for first line
				
				//fclose(student); cuz i am paranoid
				do {
					x = fclose(student);
				}while(x!=0);
				
				x=1;
				cout << "Successfully written." << endl;
				
				
				//warning
				//after cout, program STOPPED WORKING. student.txt successfully updated, and looks fine.
				
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

