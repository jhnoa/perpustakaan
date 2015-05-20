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

void convert_student() {
	
	// variables
	char *temp;
	char *buffer;
	int initial, finale, selisih;
	temp = new char[80];
	
	//rename
	rename("student.txt","student1.txt");
//	remove("student.txt");
	
	//open the file
	FILE *student;
	FILE *stunew;
	student = fopen("student1.txt","r+");
	stunew = fopen("stunew.txt","w+");
	
	
	if(student==NULL) {
		cout << "file error.(1)" << endl;
	}
	else {
		
		
		while(!feof(student)) {
			
			initial = 0;
			finale = 0;
			fgets(temp, 80, student);
			if(temp[strlen(temp)-1]=='\n') temp[strlen(temp)-1]='\0';
			//check the every line
			
			// [6] [37] [39-45] == ' '
			
			if(temp[6]==' ' && temp[37]==' ' && temp[39]==' ' && temp[40]==' ' && temp[41]==' ' && temp[42]==' ' && temp[43]==' ' && temp[44]==' ' && temp[45]==' ') {  // already in the right format, so just fprintf it whole
				
				
				
				if (sizeof(stunew) != 0 && strlen(temp)>4) fprintf(stunew, "\n%s", temp);
				else fprintf(stunew, "%s", temp);
				
				temp[0]='\0';
				
				// confirmed: it worked. but last line got repeated

			}
			else { // for other line that's in different format
				
				buffer = new char[80];
				
				//nim
				for(int i=0;i<=6;i++) {
				
					if(i==6) buffer[i] = ' ';
					else buffer[i] = temp[i];
				
				}
				//
				
				// name
				// decide the initial index and final index
				for(int i=7;finale==0;i++) {
					if(initial==0 && isalpha(temp[i])) initial = i;
					if(initial!=0 && (temp[i]=='\t' || (temp[i]==' ' && temp[i+1]==' ') || (temp[i]==' ' && temp[i+1]=='\t') || ((temp[i]=='L' || temp[i]=='P') && (temp[i+1]==' ' || temp[i+1]=='\t')))) finale = i; 
				}
				
				selisih = initial - 7;
				
				// masukkan ke buffer
				for(int i=7;i<38;i++) {
					
					if(i<finale-selisih) buffer[i] = temp[i+selisih];
					else buffer[i] = ' ';
					
				}
				//
				
				// jenis kelamin
				for(int i = finale;selisih<finale;i++) {
					
					if(temp[i]=='L' || temp[i]=='P') {
						buffer[38]=temp[i];
						selisih = i;
					}
					
				}
				
				for(int i=39;i<=45;i++) {
					buffer[i] = ' ';
		
				}
				//
				
				// email
				initial = 0;
				for(int i=selisih+1;initial==0;i++) {
					if(isalpha(temp[i])) initial = i;
				}
				
				selisih = initial - 46;
				
				for(int i=46;temp[i+selisih]!='\n';i++) {
					buffer[i] = temp[i+selisih];
					
				}
				//
				
				
				if (sizeof(stunew) != 0 && strlen(buffer)>4) fprintf(stunew, "\n%s", buffer);
				else fprintf(stunew, "%s", buffer); //for first line
				
				temp[0]='\0'; // to eliminate double line
				
				delete[] buffer;
				
				
			}
			
			

		}
		fclose(stunew);
		
		
	}
	fclose(student);
	delete[] temp;
	rename("stunew.txt","student.txt");
	remove("student1.txt");
	
	
	
}
