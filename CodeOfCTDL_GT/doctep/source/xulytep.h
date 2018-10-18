#ifndef __XULYTEP_H__
#define __XULYTEP_H__
#include<iostream>
#include<string>
#include<fstream>
#include<list>
#include<vector>
using namespace std;
typedef struct{

	string MSSV;
	string Ten;
	string HoVaTenLot;
	string NgaySinh; /* dd/mm/yy  */

}SINHVIEN;
void ganbang(SINHVIEN &A, const SINHVIEN B);
int add_student(string MSSV, string Ten, string HoVaTenLot, string NgaySinh, string nameOfFile);
void printSV(SINHVIEN *dataSinhVien, int &n);
SINHVIEN* list_students(string nameOfFile, int &n);
int delete_student(string MSSV, string nameOfFile);
int update_student(SINHVIEN value, string nameOfFile);
void add(string nameOfFile);
void update(string nameOfFile);
void Delete(string nameOfFile);
void List(string nameOfFile);
void menu();

#endif