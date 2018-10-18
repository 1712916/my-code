#include"xulytep.h"

void ganbang(SINHVIEN &A, const SINHVIEN B)
{
	A.MSSV = B.MSSV;
	A.Ten = B.Ten;
	A.HoVaTenLot = B.HoVaTenLot;
	A.NgaySinh = B.NgaySinh;
}
int add_student(string MSSV, string Ten, string HoVaTenLot, string NgaySinh, string nameOfFile)
{
	fstream output;
	int SoLuongSinhVien = 0;
	SINHVIEN TrungGian;
	TrungGian.MSSV = MSSV;
	TrungGian.Ten = Ten;
	TrungGian.HoVaTenLot = HoVaTenLot;
	TrungGian.NgaySinh = NgaySinh;
	vector<SINHVIEN>dataSinhVien = list_students(nameOfFile, SoLuongSinhVien);
	output.open(nameOfFile, ios::out);
	if (output.fail() == 1)
	{
		output.close();
		return 0;
	}
	int dem = 0;
	int i = 0;
	do
	{
		if (MSSV.compare(dataSinhVien[i].MSSV) < 0)
		{
			break;
		}
		i++;
	} while (i < SoLuongSinhVien);
	
	dataSinhVien.insert(i+dataSinhVien.begin(), TrungGian);
	output<<dataSinhVien.size();
	for (int i = 0; i<dataSinhVien.size(); i++)
	{
		string data = dataSinhVien[i].MSSV + ',' + dataSinhVien[i].Ten + ',' + dataSinhVien[i].HoVaTenLot + ',' + dataSinhVien[i].NgaySinh;
		output << endl << data;
	}


	output.close();
	return 1;
}

vector<SINHVIEN> list_students(string nameOfFile, int &n)
{
	fstream input;
	string line;
	string getKyTuCuoi;
	vector<SINHVIEN> dataSinhVien;
	int SoLuongSinhVien;
	input.open(nameOfFile, ios::in);
	input >> SoLuongSinhVien; //sau khi doc so luong nay thi no con mot dau \n xuong dong nua
	n = SoLuongSinhVien;
	getline(input, getKyTuCuoi); //lay them dau \n
	dataSinhVien.resize(SoLuongSinhVien);
	string tempOfMemberSinhVien[4];
	for (int i = 0; i < SoLuongSinhVien; i++)
	{
		getline(input, line);
		int flagOfMember = 0;
		int memberOfTemp = 0;
		int lengthOfLine = line.length();

		for (int j = 0; j < lengthOfLine; j++)
		{
			if (line[j] == ',')
			{
				tempOfMemberSinhVien[memberOfTemp] = line.substr(flagOfMember, j - flagOfMember);
				flagOfMember = j + 1;
				memberOfTemp++;
			}
			if (memberOfTemp == 3)
			{
				break;
			}
		}
		tempOfMemberSinhVien[memberOfTemp] = line.substr(flagOfMember, lengthOfLine - flagOfMember);

		dataSinhVien[i].MSSV = tempOfMemberSinhVien[0];
		dataSinhVien[i].Ten = tempOfMemberSinhVien[1];
		dataSinhVien[i].HoVaTenLot = tempOfMemberSinhVien[2];
		dataSinhVien[i].NgaySinh = tempOfMemberSinhVien[3];



	}

	input.close();
	return dataSinhVien;
}

int sequential_search(string MSSV,string nameOfFile)
{
	int SoLuongSinhVien = 0;
	vector<SINHVIEN>dataSinhVien = list_students(nameOfFile, SoLuongSinhVien);
	for (int i = 0; i < SoLuongSinhVien; i++)
	{
		if (dataSinhVien[i].MSSV == MSSV)
		{
			return i;
		}
	}
	return -1;
}
int TimKiemNhiPhan(string MSSV, int left, int right, vector<SINHVIEN>dataSinhVien)
{
	if (left == right)
	{
		return right;
	}
	else if ((MSSV.compare(dataSinhVien[(left + right) / 2].MSSV) == 0))
	{
		return (left + right) / 2;
	}
	else if (MSSV.compare(dataSinhVien[(left + right) / 2].MSSV) > 0)
	{
			return TimKiemNhiPhan(MSSV, (left + right) / 2 + 1, right, dataSinhVien);
	}
	
		return TimKiemNhiPhan(MSSV, left, -1 + (left + right) / 2, dataSinhVien);
	
	
	
}
int binary_search(string MSSV, string nameOfFile)
{
	int SoLuongSinhVien = 0;
	vector<SINHVIEN>dataSinhVien = list_students(nameOfFile, SoLuongSinhVien);
	return TimKiemNhiPhan(MSSV, 0, dataSinhVien.size(), dataSinhVien);
}
/**********************************/

void add(string nameOfFile)
{
	SINHVIEN value;
	cout << "Nhap MSSV:"; cin >> value.MSSV;
	cout << "Nhap Ten:"; cin >> value.Ten;
	cout << "Nhap Ho va ten lot:"; cin >> value.HoVaTenLot;
	cout << "Nhap ngay sinh:"; cin >> value.NgaySinh;
	cout << "Ket qua thuc hien lenh add_student: " << add_student(value.MSSV, value.Ten, value.HoVaTenLot, value.NgaySinh, nameOfFile);
}
void TimKiemTuanTu(string nameOfFile)
{
	string MSSV;
	cout << "NHAP MSSV: "; cin >> MSSV;
	cout << "Vi tri cua SV co MSSV " << MSSV << "la (sequential_search) : " << sequential_search(MSSV, nameOfFile);
	
}
void TimKiemNhiPhan(string nameOfFile)
{
	string MSSV;
	cout << "NHAP MSSV: "; cin >> MSSV;
	cout << "Vi tri cua SV co MSSV " << MSSV << "la (binary_search) : " <<  binary_search(MSSV, nameOfFile);

}

void menu()
{
	string filename;
	int chose;
	do{
		cout << "NHAP TEN TEP(ten tep co san la: 1712916.txt): ";
		getline(cin, filename);
		fstream a;
		a.open(filename, ios::in);
		chose = a.fail();
		a.close();
		if (chose != 0)
		{
			cout << "TEP KHONG TON TAI! VUI LONG NHAP LAI!";
		}
	} while (chose != 0);


	do
	{
		cout << "Vui long nhap de thuc hien chuong trinh!\nNhap:\n 0 de thoat!\n1 de chen thong tin SinhVien!\n2 De tim kiem SinhVien(Tuan Tu)!\n3 De tim kiem SinhVien (Nhi Phan)!\n";
		cin >> chose;
		if (chose == 1)
		{
			add(filename);
			cout << endl << "NHAP 0 DE THOAT, NHAP SO BAT KY DE TIEP TUC!" << endl;
			cin >> chose;
		}
		else if (chose == 2)
		{
			TimKiemTuanTu(filename);
			cout << endl << "NHAP 0 DE THOAT, NHAP SO BAT KY DE TIEP TUC!" << endl;
			cin >> chose;
		}
		else if (chose == 3)
		{
			TimKiemNhiPhan(filename);
			cout << endl << "NHAP 0 DE THOAT, NHAP SO BAT KY DE TIEP TUC!" << endl;
			cin >> chose;
		}
		else if (chose != 0)
		{
			cout << endl << "VUI LONG NHAP LAI!" << endl;
			cin >> chose;
		}
	} while (chose != 0);

}