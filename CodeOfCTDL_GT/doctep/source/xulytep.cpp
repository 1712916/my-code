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
	fstream input;
	int SoLuongSinhVien = 0;
	input.open(nameOfFile, ios::in | ios::out);
	if (input.fail() == 1)
	{
		input.close();
		return 0;
	}
	input >> SoLuongSinhVien;
	if (SoLuongSinhVien == 0)
	{
		return 0;
	}
	SoLuongSinhVien += 1;

	input.seekg(0, input.beg);
	input << SoLuongSinhVien << endl;

	input.seekg(0, input.end);
	string data = MSSV + ',' + Ten + ',' + HoVaTenLot + ',' + NgaySinh;
	input << endl << data;
	input.seekg(0, input.beg);
	input << "";

	input.close();
	return 1;
}
void printSV(SINHVIEN *dataSinhVien, int &n)
{
	cout << "SO LUONG SINH VIEN: " << n;
	for (int i = 0; i < n; i++)
	{
		string data = dataSinhVien[i].MSSV + "," + dataSinhVien[i].Ten + "," + dataSinhVien[i].HoVaTenLot + "," + dataSinhVien[i].NgaySinh;
		cout << endl << data;
	}
}
SINHVIEN* list_students(string nameOfFile, int &n)
{
	fstream input;
	string line;
	string getKyTuCuoi;
	SINHVIEN *dataSinhVien;
	int SoLuongSinhVien;
	int memberOfSinhVien = 4;
	input.open(nameOfFile, ios::in);
	input >> SoLuongSinhVien; //sau khi doc so luong nay thi no con mot dau \n xuong dong nua
	n = SoLuongSinhVien;
	getline(input, getKyTuCuoi); //lay them dau \n

	dataSinhVien = new SINHVIEN[SoLuongSinhVien];

	string tempOfMemberSinhVien[4];
	SINHVIEN tempSinhVien;

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
int delete_student(string MSSV, string nameOfFile)
{
	int ktTinhTrangTonTaiMSSV = 0;
	int SoLuongSinhVien;
	SINHVIEN *dataSinhVien = list_students(nameOfFile, SoLuongSinhVien);
	fstream output;
	int demSoLuongCanXoa = 0;
	for (int i = 0; i < SoLuongSinhVien; i++)
	{

		if (dataSinhVien[i].MSSV == MSSV)
		{
			demSoLuongCanXoa++;
		}
	}
	if (demSoLuongCanXoa == 0)
	{
		return 0;
	}
	output.open(nameOfFile, ios::trunc | ios::out);

	output << SoLuongSinhVien - demSoLuongCanXoa;
	for (int i = 0; i < SoLuongSinhVien; i++)
	{

		if (dataSinhVien[i].MSSV == MSSV)
		{
			continue;
		}
		string data = dataSinhVien[i].MSSV + "," + dataSinhVien[i].Ten + "," + dataSinhVien[i].HoVaTenLot + "," + dataSinhVien[i].NgaySinh;
		output << endl << data;
	}
	output.close();
	return 1;

}
int update_student(SINHVIEN value, string nameOfFile)
{
	int SoLuongSinhVien;
	int KiemTraTinhTrang = 0; //kiem tra xem MSSV nhap vao co ton tai trong DANH SACH SINH VIEN HAY KHONG
	SINHVIEN *dataSinhVien = list_students(nameOfFile, SoLuongSinhVien);
	for (int i = 0; i < SoLuongSinhVien; i++)
	{
		if (dataSinhVien[i].MSSV == value.MSSV)
		{
			ganbang(dataSinhVien[i], value);
			KiemTraTinhTrang++;

		}
	}
	if (KiemTraTinhTrang == 0)
	{
		cout << "KHONG TON TAI SINH VIEN CO MSSV BAN DA NHAP!";
		return 0;
	}
	else
	{
		fstream output;
		output.open(nameOfFile, ios::trunc | ios::out);
		output << SoLuongSinhVien;
		for (int i = 0; i < SoLuongSinhVien; i++)
		{
			string data = dataSinhVien[i].MSSV + "," + dataSinhVien[i].Ten + "," + dataSinhVien[i].HoVaTenLot + "," + dataSinhVien[i].NgaySinh;
			output << endl << data;
		}
		output.close();
	}
	return 1;
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
void update(string nameOfFile)
{
	SINHVIEN value;
	cin.ignore();
	cout << "Nhap MSSV:"; getline(cin, value.MSSV);
	cout << "Nhap Ten:"; getline(cin, value.Ten);
	cout << "Nhap Ho va ten lot:"; getline(cin, value.HoVaTenLot);
	cout << "Nhap ngay sinh:"; getline(cin, value.NgaySinh);
	cout << "KET QUA THUC HIEN UPDATE LA: " << update_student(value, nameOfFile);
}
void Delete(string nameOfFile)
{
	string MSSV;
	cin.ignore();
	cout << "NHAP MSSV CUA SINH VIEN CAN XOA!\n";
	getline(cin, MSSV);
	cout << "Ket qua thuc hien lenh delete_studen: " << delete_student(MSSV, nameOfFile);
}
void List(string nameOfFile)
{
	int n = 0;
	printSV(list_students(nameOfFile, n), n);
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
		cout << "Vui long nhap de thuc hien chuong trinh!\nNhap:\n 0 de thoat!\n1 de doc du lieu sinh vien trong tep!\n2 de them SINH VIEN vao cuoi tep!\n3 de cap nhat thong tin cho SINH VIEN!\n4 de xoa SINH VIEN!";
		cin >> chose;
		if (chose == 1)
		{
			List(filename);
			cout << endl << "NHAP 0 DE THOAT, NHAP SO BAT KY DE TIEP TUC!" << endl;
			cin >> chose;
		}
		else if (chose == 2)
		{
			add(filename);
			cout << endl << "NHAP 0 DE THOAT, NHAP SO BAT KY DE TIEP TUC!" << endl;
			cin >> chose;
		}
		else if (chose == 3)
		{
			update(filename);
			cout << endl << "NHAP 0 DE THOAT, NHAP SO BAT KY DE TIEP TUC!" << endl;
			cin >> chose;
		}
		else if (chose == 4)
		{
			Delete(filename);
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