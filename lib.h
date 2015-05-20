#ifndef LIB_H
#define LIB_H

#ifndef MAX_MURID
#define MAX_MURID 81
#endif

#ifndef NIM
#define NIM 7
#endif

#ifndef JUDUL
#define JUDUL 31
#endif

#ifndef PENGARANG
#define PENGARANG 25
#endif

#ifndef EDISI
#define EDISI 4
#endif

#ifndef TANGGAL_KEMBALI
#define TANGGAL_KEMBALI 9
#endif

#ifndef NAMA
#define NAMA 31
#endif

#ifndef GENDER
#define GENDER 8
#endif

#ifndef EMAIL
#define EMAIL 32
#endif

#ifndef ID
#define ID 5
#endif

#ifndef MAX_BUKU
#define MAX_BUKU 86
#endif

#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <conio.h>
#include <Windows.h>
#include <iomanip>
//#include <ios>
//#include <ostream>

using namespace std;
//void initialize();
FILE *FileOpen (const char *);
void tulis_log (const char *);
void kop_tabel_buku();
void kop_tabel_buku_id();
void kop_tabel_murid();
void kop_over();
void kop_tagih_murid();
int auto_numbering();
char * spesifik_data(char *, int);
void convert_student();
void sorting(char * str, int size);
#endif
