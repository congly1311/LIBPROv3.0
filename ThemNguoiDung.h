#pragma once
#include "ThongBao.h"
#include "Header.h"
#include "MuonSach.h"
#include "NguoiDung.h"
#include "TruyXuat.h"
#include "ThongBaoTuDong.h"
void themnguoidung(NguoiDung ngDung[], int hientai, ThongBao thongbao[], MuonSach muonsach[]){
	system("cls");
	cout << " ________________________________________" << endl;
	cout << "|              THEM NGUOI DUNG           |" << endl;
	cout << "|________________________________________|" << endl;
	char a;
	double sl;
	int ktra = 0;
	int m;
	cout << "Nhap so luong nguoi dung: "; cin >> sl;
	while (cin.bad() || sl < 0 || sl != (int)sl) {
		cin.clear();
		fflush(stdin);
		cout << "Nhap so luong nguoi dung: "; cin >> sl;
	}
	cin.ignore();
	cout << endl;
	for (int i = 0; i < sl; i++) {
		m = TruyXuatNgDung(ngDung);
		ktra = 0;
		cout << "Nhap thong tin nguoi thu " << i + 1 << " : " << endl;
		do {
			cout << "Nhap so CMND: "; cin.getline(ngDung[m].sCMND, 13);
			if (strcmp(ngDung[m].sCMND, "") == 0) cout << "Khong Duoc Bo trong Phan Nay!!!" << endl;
		} while (strcmp(ngDung[m].sCMND, "") == 0);

		for (int j = 0; j < m; j++) {
			if (strcmp(ngDung[m].sCMND, ngDung[j].sCMND) == 0) {
				cout << "Da ton tai so CMND nay !!!" << endl;
				cout << "Tai khoan co vai tro hien tai la: ";
				if (ngDung[j].chucVu.admin == 1) cout << "Admin, ";
				if (ngDung[j].chucVu.thuthu == 1) cout << "Thu thu, ";
				if (ngDung[j].chucVu.docgia == 1) cout << "Doc gia, ";
				cout << endl;
				cout << "Ban co muon thay doi vai tro khong? (Y/N): "; cin >> a; cin.ignore();
				if (a == 'Y' || a == 'y'){
					cout << "Nhap vai tro moi (A T D): ";
					cin >> ngDung[j].chucVu.admin;
					cin >> ngDung[j].chucVu.thuthu;
					cin >> ngDung[j].chucVu.docgia;
					fstream out1File("UserData.DAT", ios::out);
					for (int d = 0; d < m; d++){
						ngDung[d].ghi(out1File);
					}
					out1File.close();
				}

				ktra = 1;
				break;
			}
		}



		if (ktra != 1) {

			do {
				cout << "Nhap Ho Ten: "; cin.getline(ngDung[m].tenNguoiDung, 30);
				if (strcmp(ngDung[m].tenNguoiDung, "") == 0) cout << "Khong Duoc Bo trong Phan Nay!!!" << endl;
			} while (strcmp(ngDung[m].tenNguoiDung, "") == 0);

			do {
				cout << "Nhap Ngay Sinh: "; cin.getline(ngDung[m].ngaySinh, 30);
				if (strcmp(ngDung[m].ngaySinh, "") == 0) cout << "Khong Duoc Bo trong Phan Nay!!!" << endl;
			} while (strcmp(ngDung[m].ngaySinh, "") == 0);
			do {
				cout << "Nhap Dia Chi: "; cin.getline(ngDung[m].diaChi, 15);
				if (strcmp(ngDung[m].diaChi, "") == 0) cout << "Khong Duoc Bo trong Phan Nay!!!" << endl;
			} while (strcmp(ngDung[m].diaChi, "") == 0);
			int kt = 0;
			do {
				kt = 0;
				cout << "Nhap Ten Tai Khoan: "; cin.getline(ngDung[m].tenDangNhap, 30);
				if (strcmp(ngDung[m].tenDangNhap, "") == 0) cout << "Khong Duoc Bo trong Phan Nay!!!" << endl;
				for (int j = 0; j < m; j++){
					if (strcmp(ngDung[m].tenDangNhap, ngDung[j].tenDangNhap) == 0)
					{
						cout << "Ten nay da co nguoi su dung!!!" << endl;
						kt = 1;
						break;
					}
				}
			} while (strcmp(ngDung[m].tenDangNhap, "") == 0 || kt == 1);
			do {
				cout << "Nhap Mat khau: "; cin.getline(ngDung[m].MatKhau, 30);
				if (strcmp(ngDung[m].MatKhau, "") == 0) cout << "Khong Duoc Bo trong Phan Nay!!!" << endl;
			} while (strcmp(ngDung[m].MatKhau, "") == 0);
			cout << "Nhap Ma Chuc Vu (A T D): ";
			cin >> ngDung[m].chucVu.admin;
			cin >> ngDung[m].chucVu.thuthu;
			cin >> ngDung[m].chucVu.docgia;
			cin.ignore();
			fstream outFile("UserData.DAT", ios::app);
			ngDung[m].ghi(outFile);
			outFile.close();
			ThongBaoTuDong(ngDung, hientai, thongbao, 1, muonsach);
			ThongBaoTuDong(ngDung, hientai, thongbao, 4, muonsach);

			cout << endl;
		}
	}
	cout << "Them hoan tat!" << endl;
	Sleep(1311);
}