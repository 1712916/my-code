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
vector<SINHVIEN> list_students(string nameOfFile, int &n);
int sequential_search(string MSSV, string nameOfFile);
int binary_search(string MSSV, string nameOfFile);
int TimKiemNhiPhan(string MSSV, int left, int right, vector<SINHVIEN>dataSinhVien);
void add(string nameOfFile);

void menu();

#endif