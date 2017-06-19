#pragma once
#include "YeuCau.h"
#include "ThongBao.h"
#include "Header.h"
#include "Quyen.h"
#include "Sach.h"
#include "MuonSach.h"
#include "NguoiDung.h"
#include "TruyXuat.h"
#include "TimKiemChuoi.h"
#include "ThongBaoTuDong.h"
#include "ThemNguoiDung.h"
#include "KhoaNguoiDung.h"
#include "TimSach.h"
#include "ThemSach.h"
#include "MuonTraSach.h"
#include "InMuonSach.h"
int Chucnang(int hientai, NguoiDung ngDung[], int quyen, int &m, Quyen q[], char tdn[], Sach sach[], MuonSach muonsach[], ThongBao thongbao[], YeuCau yc[]) {

	//#######Quyen 0. Them Nguoi dung#######################################################

	if (quyen == 0) {
		themnguoidung(ngDung, hientai, thongbao, muonsach);
	}

	//#######Quyen 1. Khoa nguoi dung#######################################################

	else if (quyen == 1) {
		khoanguoidung(ngDung, 1);
	}

	//#######Quyen 2. Mo Khoa nguoi dung#######################################################

	else if (quyen == 2) {
		khoanguoidung(ngDung, 2);

		
	}

	//#######Quyen 3. Quan ly quyen.########################################################

	else if (quyen == 3) {           //
		system("cls");
		cout << " _________________________________________________________________" << endl;
		cout << "|                          QUAN LY QUYEN                          |" << endl;
		cout << "|_________________________________________________________________|" << endl;
		cout << "__________________________________________________________________" << endl;
		cout << setw(5) << left << "|MS" << setw(30) << left << "|Ten Quyen" << setw(10) << left << "|Admin" << setw(10) << left << "|Thu thu" << setw(10) << left << "|Doc gia" << "|" << endl;
		//fstream inFile("Quyen.DAT", ios::in);
		cout << "|____|_____________________________|_________|_________|_________|" << endl;
		int dem = 23;
		/*
		while (!inFile.eof()){
		q[dem].doc(inFile);
		dem++;
		}
		*/
		for (int i = 0; i < dem; i++) {
			cout << "|" << setw(4) << left << q[i].stt << "|" << setw(29) << left << q[i].tenQuyen;
			if (q[i].Admin == 1) cout << "|" << setw(5) << right << "x" << setw(4) << " ";
			else cout << "|" << setw(9) << right << " ";
			if (q[i].ThuThu == 1) cout << "|" << setw(5) << right << "x" << setw(4) << " ";
			else cout << "|" << setw(9) << right << " ";
			if (q[i].DocGia == 1) cout << "|" << setw(5) << right << "x" << setw(4) << " ";
			else cout << "|" << setw(9) << right << " ";
			cout << "|" << endl;
		}
		cout << "|____|_____________________________|_________|_________|_________|" << endl;
		int op;
		cout << "\t1. Sua Quyen." << endl;
		cout << "\t2. Thoat." << endl;
		cout << "\t Nhap Lua chon: "; cin >> op;
		switch (op) {
		case 2: {
					break;
		}
		case 1: {
					int ms;
					cout << "Nhap ma quyen muon sua: "; cin >> ms; cin.ignore();
					for (int i = 0; i < dem; i++) {
						if (ms == q[i].stt) {
							cout << "Nhap ma tran uy quyen(A T D): ";
							cin >> q[i].Admin >> q[i].ThuThu >> q[i].DocGia; cin.ignore();
							Sleep(1311);
							break;
						}
					}
					cout << "Da sua thanh cong!" << endl;
					fstream outFile("Quyen.DAT", ios::out);
					for (int i = 0; i < dem; i++){
						q[i].ghi(outFile);
					}
					outFile.close();
					Sleep(1311);
					break;
		}
		}
	}

	//#######Quyen 4. Xem kho sach.###########################################################################

	else if (quyen == 4) {
		system("cls");
		cout << " _________________________________________________________________" << endl;
		cout << "|                             KHO SACH                            |" << endl;
		cout << "|_________________________________________________________________|" << endl;
		cout << endl;

		char ql;
		cout << " ____________________________________________________________________________________________________________________";
		cout << endl;
		cout << "|" << setw(5) << left << "Ma so" << "|" << setw(30) << left << "Ten sach" << "|" << setw(20) << left << "Tac gia" << "|" << setw(15) << left << "The loai" << "|" << setw(20) << left << "Ngon ngu" << "|" << setw(10) << left << "Danh gia" << "|" << setw(10) << left << "Trang thai" << "|" << endl;
		cout << "|_____|______________________________|____________________|_______________|____________________|__________|__________|" << endl;
		int s = TruyXuatSach(sach);
		for (int i = 0; i < s; i++) {
			cout << "|" << setw(5) << left << sach[i].ID << "|" << setw(30) << left << sach[i].tensach << "|" << setw(20) << left << sach[i].tentacgia << "|" << setw(15) << left << sach[i].theloai << "|" << setw(20) << left << sach[i].ngonngu << "|" << setw(10) << left << setprecision(2) << sach[i].danhgia << "|";
			cout << setw(10) << left;
			if (sach[i].trangthai == 1) cout << "Chua muon" << "|" << endl;
			else if (sach[i].trangthai == 2) cout << "Dang xu ly" << "|" << endl;
			else cout << "Da muon" << "|" << endl;
		}
		cout << "|_____|______________________________|____________________|_______________|____________________|__________|__________|" << endl;
		system("pause");
	}

	//#######Quyen 5. Tim sach ##############################################################################
	else if (quyen == 5) {
		timsach(sach);
	}

	//#######Quyen 6. Them sach #############################################################################

	else if (quyen == 6) {
		themsach(sach);
	}

	//#######Quyen 7. Muon sach ###############################################################################
	else if (quyen == 7) {
		muontrasach(sach, muonsach, ngDung, hientai, yc, thongbao, 1);
	}

	//#######Quyen 8. Tra sach###############################################################################

	else if (quyen == 8) {
		muontrasach(sach, muonsach, ngDung, hientai, yc, thongbao, 2);

		
	}

	//#######QUyen 9. Xem balo################################################################################

	else if (quyen == 9) {
		//nguoi dung hien tai
		system("cls");
		cout << " _________________________________________" << endl;
		cout << "|                   BALO                  |" << endl;
		cout << "|_________________________________________|" << endl;
		int sl = TruyXuatMuonSach(muonsach);
		int dem = 0;
		for (int i = 0; i < sl; i++) {
			if (strcmp(muonsach[i].IDmuon, ngDung[hientai].sCMND) == 0)
			if (muonsach[i].trangthai == 0)
				dem++;
		}
		cout << "Co " << dem << " Sach da muon: " << endl;
		inmuonsach(ngDung, muonsach, hientai, 0);
		cout << endl;
		int dem1 = 0;
		for (int i = 0; i < sl; i++) {
			if (strcmp(muonsach[i].IDmuon, ngDung[hientai].sCMND) == 0)
			if (muonsach[i].trangthai == 2)
				dem1++;
		}
		cout << "Co " << dem1 << " Sach dang cho phe duyen: " << endl;
		inmuonsach(ngDung, muonsach, hientai, 2);
		system("pause");
	}

	//#######Quyen 10. Doi mat khau###########################################################################

	else if (quyen == 10) {
		system("cls");
		cout << " _________________________________________" << endl;
		cout << "|               DOI MAT KHAU              |" << endl;
		cout << "|_________________________________________|" << endl;
		char mkc[20];
		char mk1[20];
		char mk2[20];
		int kt1 = 0, kt2 = 0;
		for (int i = 0; i < m; i++) {
			if (strcmp(tdn, ngDung[i].tenDangNhap) == 0) {
				while (kt1 == 0) {
					cout << "Nhap mat khau cu: "; inmk(mkc);
					if (strcmp(mkc, ngDung[i].MatKhau) == 0) {
						do {
							cout << "Nhap mat khau moi: "; inmk(mk1);
							cout << "Nhap lai mat khau moi: "; inmk(mk2);
							if (strcmp(mk1, mk2) == 0) {
								strcpy(ngDung[i].MatKhau, mk1);
								kt2 = 1;
							}
							else cout << "Khong khop. Nhap lai: " << endl;
						} while (kt2 == 0);
						cout << "Doi mat khau thanh cong! " << endl;
						kt1 = 1;
					}
					else cout << "Sai mat khau!" << endl;
				}
				break;
			}
		}
		fstream outFile("UserData.DAT", ios::out);
		for (int i = 0; i < m; i++) {
			ngDung[i].ghi(outFile);
		}
		outFile.close();
		Sleep(1311);
	}

	////########Quyen 11. Xem thong bao ########################################################################

	else if (quyen == 11) {
		system("cls");
		cout << " _________________________________________" << endl;
		cout << "|               THONG BAO                 |" << endl;
		cout << "|_________________________________________|" << endl;
		int sl = TruyXuatThongBao(thongbao);
		fstream inFile("ThongBao.DAT", ios::in);
		for (int i = 0; i < sl; i++) {
			thongbao[i].doc(inFile);
		}
		inFile.close();
		int kt = 0;
		int op;
		cout << "_______________________############QUANG" << endl;
		cout << setw(10) << left << "Ma so" << setw(15) << left << "Nguoi gui" << setw(20) << left << "thoi gian" << setw(100) << left << "tieu de" << endl;
		for (int i = 0; i < sl; i++) {
			if (strcmp(ngDung[hientai].sCMND, thongbao[i].IDnhan) == 0) {
				cout << setw(10) << left << thongbao[i].IDthongbao;
				if (strcmp(thongbao[i].IDgui, "1") == 0) cout << setw(15) << left << "Admin";
				else if (strcmp(thongbao[i].IDgui, "2") == 0) cout << setw(15) << left << "Thu thu";
				else cout << setw(15) << left << "He thong";
				cout << setw(20) << left << thongbao[i].time << setw(100) << left << thongbao[i].tieude << endl;
				kt = 1;
			}
		}
		if (kt == 0) cout << "Ban khong co khong bao nao." << endl;
		else {
			cout << "Nhap ma so thong bao de xem, nhap 0 de thoat." << endl;
			cout << "Nhap lua chon: "; cin >> op; cin.ignore();
			if (op != 0) {
				for (int i = 0; i < sl; i++) {
					if (strcmp(ngDung[hientai].sCMND, thongbao[i].IDnhan) == 0) {
						if (thongbao[i].IDthongbao == op) {
							cout << endl;
							cout << "Chu De: " << thongbao[i].tieude << endl << endl;
							cout << "Noi Dung: " << endl;
							cout << thongbao[i].noidung << endl;
							cout << endl;
						}
					}
				}
			}
		}
		system("pause");
	}

	////########Quyen 12. Reset mat khau #######################################################################

	else if (quyen == 12) {
		system("cls");
		char cm[13];
		int i;
		int kt = 0;
		cout << " _________________________________________" << endl;
		cout << "|             RESET MAT KHAU              |" << endl;
		cout << "|_________________________________________|" << endl;
		cout << "Nhap so CMND: "; cin >> cm; cin.ignore();
		for (i = 0; i < m; i++) {
			if (strcmp(cm, ngDung[i].sCMND) == 0) {
				strcpy(ngDung[i].MatKhau, "1");
				cout << "Mat khau da duoc reset" << endl;
				kt = 1;
			}
		}
		fstream outFile("UserData.DAT", ios::out);
		for (i = 0; i < m; i++) {
			ngDung[i].ghi(outFile);
		}
		if (kt == 0) cout << "Khong tim thay nguoi nay";

		outFile.close();
		Sleep(1311);
	}

	////########## quyen 13. Tim kiem tai khoan ###############################################################
	////nghia sua gd
	else if (quyen == 13) {
		system("cls");
		int op;
		fstream inFile("UserData.DAT", ios::in);
		int m = TruyXuatNgDung(ngDung);
		cout << " _________________________________________________________________________________________________" << endl;
		cout << "|                                       TIM KIEM TAI KHOAN                                        |" << endl;
		cout << "|_________________________________________________________________________________________________|" << endl;
		cout << "|                                         1. Tim theo ID.                                         |" << endl;
		cout << "|                                         2. Tim theo ten.                                        |" << endl;
		cout << "|                                         3. Tim theo Dia chi.                                    |" << endl;
		cout << "|                                         4. Tim theo ngay sinh.                                  |" << endl;
		cout << "|_________________________________________________________________________________________________|" << endl;

		cout << "Nhap lua chon: "; cin >> op; cin.ignore();
		switch (op) {
		case 1: {
					system("cls");
					cout << " ______________________________________" << endl;
					cout << "|             TIM THEO ID              |" << endl;
					cout << "|______________________________________|" << endl << endl << endl;
					char id[13];
					int i;
					char ql;
					cout << "Nhap ID can tim :"; cin >> id;
					cout << endl << endl;
					for (i = 0; i < m; i++) {
						if (strcmp(ngDung[i].sCMND, id) == 0) {
							cout << " ___________________________________________" << endl;
							cout << "|                   TIM THAY  !             |" << endl;
							cout << "|___________________________________________|" << endl;
							cout << endl << endl;
							cout << "Ten nguoi dung " << ngDung[i].tenNguoiDung << endl;
							cout << "So CMND        " << ngDung[i].sCMND << endl;
							cout << "Ngay sinh      " << ngDung[i].ngaySinh << endl;
							cout << "Dia chi        " << ngDung[i].diaChi << endl;
							cout << "Chuc vu        ";
							if (ngDung[i].chucVu.admin == 1) cout << "Admin";
							else if (ngDung[i].chucVu.thuthu == 1) cout << "Thu Thu";
							else cout << "Doc Gia";
							cout << endl;
							cout << "Trang thai     ";
							if (ngDung[i].trangThai == 1) cout << "Hoat Dong" << endl;
							else cout << "Bi khoa" << endl;
							break;
						}
					}
					if (i == m) {
						cout << " ___________________________________________" << endl;
						cout << "|               KHONG TIM THAY !            |" << endl;
						cout << "|___________________________________________|" << endl;
					}
					system("pause");
					break;

		}
		case 2: {
					system("cls");
					cout << " ______________________________________" << endl;
					cout << "|             TIM THEO ID              |" << endl;
					cout << "|______________________________________|" << endl << endl << endl;
					char name[30];
					int i;
					char ql;
					cout << "Nhap ten nguoi can tim :"; cin.getline(name, 30);
					cout << endl << endl;
					for (i = 0; i < m; i++) {
						if (timkiemchuoi(ngDung[i].tenNguoiDung, name) == 1) {
							cout << " ___________________________________________" << endl;
							cout << "|                   TIM THAY  !             |" << endl;
							cout << "|___________________________________________|" << endl;
							cout << endl << endl;
							cout << " _________________________________________________________________________________________________________________" << endl;
							cout << "|" << setw(10) << left << "So CMND" << "|" << setw(25) << left << "Ho va ten"
								<< "|" << setw(15) << left << "Ngay sinh" << "|" << setw(30) << left << "Dia chi"
								<< "|" << setw(13) << left << "Trang thai" << "|" << setw(15) << left << "Chuc vu" << "|" << endl;
							cout << "|__________|_________________________|_______________|______________________________|_____________|_______________|" << endl;
							for (int j = i; j < m; j++) {
								if (timkiemchuoi(ngDung[j].tenNguoiDung, name) == 1) {
									cout << "|" << setw(10) << left << ngDung[j].sCMND << "|" << setw(25) << left << ngDung[j].tenNguoiDung
										<< "|" << setw(15) << left << ngDung[j].ngaySinh << "|" << setw(30) << left << ngDung[j].diaChi << "|";
									cout << setw(13) << left;
									if (ngDung[j].trangThai == 1) cout << "Hoat Dong" << "|";
									else cout << "Bi khoa" << "|";
									cout << setw(15) << left;
									if (ngDung[j].chucVu.admin == 1) cout << "Administration" << "|" << endl;
									else if (ngDung[j].chucVu.thuthu == 1) cout << "Thu Thu" << "|" << endl;
									else cout << "Doc Gia" << "|" << endl;
								}
							}
							cout << "|__________|_________________________|_______________|______________________________|_____________|_______________|" << endl;
							break;
						}
					}
					if (i == m){
						cout << " ___________________________________________" << endl;
						cout << "|               KHONG TIM THAY !            |" << endl;
						cout << "|___________________________________________|" << endl;
					}
					system("pause");
					break;
		}
		case 3: {
					system("cls");
					cout << " ______________________________________" << endl;
					cout << "|           TIM THEO DIA CHI           |" << endl;
					cout << "|______________________________________|" << endl << endl << endl;
					char name[30];
					int i;
					char ql;
					cout << "Nhap dia chi can tim :"; cin.getline(name, 30);
					for (i = 0; i < m; i++) {
						if (timkiemchuoi(ngDung[i].diaChi, name) == 1) {
							cout << " ___________________________________________" << endl;
							cout << "|                   TIM THAY  !             |" << endl;
							cout << "|___________________________________________|" << endl;
							cout << endl << endl;
							cout << " _________________________________________________________________________________________________________________" << endl;
							cout << "|" << setw(10) << left << "So CMND" << "|" << setw(25) << left << "Ho va ten"
								<< "|" << setw(15) << left << "Ngay sinh" << "|" << setw(30) << left << "Dia chi"
								<< "|" << setw(13) << left << "Trang thai" << "|" << setw(15) << left << "Chuc vu" << "|" << endl;
							cout << "|__________|_________________________|_______________|______________________________|_____________|_______________|" << endl;
							for (int j = i; j < m; j++) {
								if (timkiemchuoi(ngDung[j].diaChi, name) == 1) {
									cout << "|" << setw(10) << left << ngDung[j].sCMND << "|" << setw(25) << left << ngDung[j].tenNguoiDung
										<< "|" << setw(15) << left << ngDung[j].ngaySinh << "|" << setw(30) << left << ngDung[j].diaChi << "|";
									cout << setw(13) << left;
									if (ngDung[j].trangThai == 1) cout << "Hoat Dong" << "|";
									else cout << "Bi khoa" << "|";
									cout << setw(15) << left;
									if (ngDung[j].chucVu.admin == 1) cout << "Administration" << "|" << endl;
									else if (ngDung[j].chucVu.thuthu == 1) cout << "Thu Thu" << "|" << endl;
									else cout << "Doc Gia" << "|" << endl;
								}
							}
							cout << "|__________|_________________________|_______________|______________________________|_____________|_______________|" << endl;
							break;
						}
					}
					if (i == m)
					{
						cout << " ___________________________________________" << endl;
						cout << "|               KHONG TIM THAY !            |" << endl;
						cout << "|___________________________________________|" << endl;
					}
					system("pause");
					break;
		}
		case 4: {
					system("cls");
					cout << " ______________________________________" << endl;
					cout << "|          TIM THEO NGAY SINH          |" << endl;
					cout << "|______________________________________|" << endl << endl << endl;
					char name[30];
					int i;
					char ql;
					cout << "Nhap ngay sinh can tim :"; cin.getline(name, 30);
					for (i = 0; i < m; i++) {
						if (timkiemchuoi(ngDung[i].ngaySinh, name) == 1) {
							cout << " ___________________________________________" << endl;
							cout << "|                   TIM THAY  !             |" << endl;
							cout << "|___________________________________________|" << endl;
							cout << endl << endl;
							cout << " _________________________________________________________________________________________________________________" << endl;
							cout << "|" << setw(10) << left << "So CMND" << "|" << setw(25) << left << "Ho va ten"
								<< "|" << setw(15) << left << "Ngay sinh" << "|" << setw(30) << left << "Dia chi"
								<< "|" << setw(13) << left << "Trang thai" << "|" << setw(15) << left << "Chuc vu" << "|" << endl;
							cout << "|__________|_________________________|_______________|______________________________|_____________|_______________|" << endl;
							for (int j = i; j < m; j++) {
								if (timkiemchuoi(ngDung[j].ngaySinh, name) == 1) {
									cout << "|" << setw(10) << left << ngDung[j].sCMND << "|" << setw(25) << left << ngDung[j].tenNguoiDung
										<< "|" << setw(15) << left << ngDung[j].ngaySinh << "|" << setw(30) << left << ngDung[j].diaChi << "|";
									cout << setw(13) << left;
									if (ngDung[j].trangThai == 1) cout << "Hoat Dong" << "|";
									else cout << "Bi khoa" << "|";
									cout << setw(15) << left;
									if (ngDung[j].chucVu.admin == 1) cout << "Administration" << "|" << endl;
									else if (ngDung[j].chucVu.thuthu == 1) cout << "Thu Thu" << "|" << endl;
									else cout << "Doc Gia" << "|" << endl;
								}
							}
							cout << "|__________|_________________________|_______________|______________________________|_____________|_______________|" << endl;
							break;
						}
					}
					if (i == m)
					{
						cout << " ___________________________________________" << endl;
						cout << "|               KHONG TIM THAY !            |" << endl;
						cout << "|___________________________________________|" << endl;
					}
					system("pause");
					break;
		}
		default:
			break;
		}
	}

	////##########Quyen 14. Tao thong bao #################################################

	else if (quyen == 14) {
		int op;
		system("cls");
		cout << " _________________________________________" << endl;
		cout << "|              TAO THONG BAO              |" << endl;
		cout << "|_________________________________________|" << endl;
		int sl = TruyXuatThongBao(thongbao);
		//thongbao[sl].IDgui = ngDung[hientai].chucVu;
		cout << "|  Chon doi tuong gui:                    |" << endl;
		cout << "|_________________________________________|" << endl;
		cout << "|      1. Ca nhan.                        |" << endl;
		cout << "|      2. Nhom nguoi.                     |" << endl;
		cout << "|      3. Tat ca Admin.                   |" << endl;
		cout << "|      4. Tat ca thu thu.                 |" << endl;
		cout << "|      5. Tat ca doc gia.                 |" << endl;
		cout << "|      6. Toan bo nguoi dung.             |" << endl;
		cout << "|_________________________________________|" << endl;
		cout << "Lua chon: "; cin >> op; cin.ignore();
		switch (op) {
		case 1: {

					system("cls");
					cout << " _________________________________________" << endl;
					cout << "|              TAO THONG BAO              |" << endl;
					cout << "|_________________________________________|" << endl;
					cout << endl;
					thongbao[sl].IDthongbao = sl + 1;
					char a[13];
					if (ngDung[hientai].chucVu.admin == 1) strcpy(a, "1");
					else if (ngDung[hientai].chucVu.thuthu == 1) strcpy(a, "2");
					else strcpy(a, "-1");
					strcpy(thongbao[sl].IDgui, a);
					cout << "Nhap ID nguoi nhan: "; cin.getline(thongbao[sl].IDnhan, 13);
					cout << "Nhap tieu de(<100 ky tu): "; cin.getline(thongbao[sl].tieude, 100);
					cout << "Nhap noi dung(<1000 ky tu): "; cin.getline(thongbao[sl].noidung, 100);
					time_t rawtime;
					struct tm *info;
					char buffer[50];

					time(&rawtime);

					info = localtime(&rawtime);

					strftime(buffer, 80, "%x - %I:%M%p", info);
					strcpy(thongbao[sl].time, buffer);
					fstream outFile("ThongBao.DAT", ios::app);
					thongbao[sl].ghi(outFile);
					outFile.close();
					cout << "Gui thanh cong!" << endl;
					Sleep(1311);
					break;
		}
		case 2: {
					system("cls");
					cout << " _________________________________________" << endl;
					cout << "|              TAO THONG BAO              |" << endl;
					cout << "|_________________________________________|" << endl;
					cout << endl;
					int sln = 0;
					char td[100];
					char nd[1000];

					cout << "Nhap tieu de(<100 ky tu): "; cin.getline(td, 100);
					cout << "Nhap noi dung(<1000 ky tu): "; cin.getline(nd, 1000);
					cout << "Nhap so luong nguoi nhan: "; cin >> sln;
					char nguoinhan[13];
					cin.ignore();
					//cout << "Nhap ID nguoi nhan, cach nhau mot khoang trang : ";
					char a[13];
					for (int i = 0; i < sln; i++) {
						cout << "Nhap ID nguoi thu " << i + 1 << " : ";
						cin.getline(nguoinhan, 13);

						if (ngDung[hientai].chucVu.admin == 1) strcpy(a, "1");
						else if (ngDung[hientai].chucVu.thuthu == 1) strcpy(a, "2");
						else strcpy(a, "-1");
						strcpy(thongbao[sl + i].IDgui, a);
						thongbao[sl + i].IDthongbao = sl + i + 1;
						//itoa(nguoinhan[i], thongbao[sl + i].IDnhan, 13);
						//cout << thongbao[sl + i].IDnhan << endl;
						strcpy(thongbao[sl + i].IDnhan, nguoinhan);
						strcpy(thongbao[sl + i].tieude, td);
						strcpy(thongbao[sl + i].noidung, nd);

						time_t rawtime;
						struct tm *info;
						char buffer[50];

						time(&rawtime);

						info = localtime(&rawtime);

						strftime(buffer, 80, "%x - %I:%M%p", info);
						strcpy(thongbao[sl + i].time, buffer);
						fstream outFile("ThongBao.DAT", ios::app);
						thongbao[sl + i].ghi(outFile);
						outFile.close();
					}
					cout << "Gui thanh cong!" << endl;

					Sleep(1311);
					break;
		}
		case 3: {
					system("cls");
					int slnd = TruyXuatNgDung(ngDung);
					int dem = 0;
					cout << " _________________________________________" << endl;
					cout << "|              TAO THONG BAO              |" << endl;
					cout << "|_________________________________________|" << endl;
					cout << endl;
					char td[100];
					char nd[1000];
					cout << "Nhap tieu de(<100 ky tu): "; cin.getline(td, 100);
					cout << "Nhap noi dung(<1000 ky tu): "; cin.getline(nd, 1000);
					char a[13];
					for (int i = 0; i < slnd; i++) {
						if (ngDung[i].chucVu.admin == 1) {

							if (ngDung[hientai].chucVu.admin == 1) strcpy(a, "1");
							else if (ngDung[hientai].chucVu.thuthu == 1) strcpy(a, "2");
							else strcpy(a, "-1");
							strcpy(thongbao[sl + dem].IDgui, a);
							//thongbao[sl + dem].IDgui = ngDung[hientai].chucVu;
							thongbao[sl + dem].IDthongbao = sl + dem + 1;
							strcpy(thongbao[sl + dem].IDnhan, ngDung[i].sCMND);
							strcpy(thongbao[sl + dem].tieude, td);
							strcpy(thongbao[sl + dem].noidung, nd);

							time_t rawtime;
							struct tm *info;
							char buffer[50];

							time(&rawtime);

							info = localtime(&rawtime);

							strftime(buffer, 80, "%x - %I:%M%p", info);
							strcpy(thongbao[sl + dem].time, buffer);
							fstream outFile("ThongBao.DAT", ios::app);
							thongbao[sl + dem].ghi(outFile);
							outFile.close();
							dem++;
						}

					}
					cout << "Gui thanh cong!" << endl;
					Sleep(1311);
					break;
		}
		case 4: {
					system("cls");
					int slnd = TruyXuatNgDung(ngDung);
					int dem = 0;
					cout << " _________________________________________" << endl;
					cout << "|              TAO THONG BAO              |" << endl;
					cout << "|_________________________________________|" << endl;
					cout << endl;
					char td[100];
					char nd[1000];
					cout << "Nhap tieu de(<100 ky tu): "; cin.getline(td, 100);
					cout << "Nhap noi dung(<1000 ky tu): "; cin.getline(nd, 1000);
					char a[13];
					for (int i = 0; i < slnd; i++) {
						if (ngDung[i].chucVu.thuthu == 1) {
							if (ngDung[hientai].chucVu.admin == 1) strcpy(a, "1");
							else if (ngDung[hientai].chucVu.thuthu == 1) strcpy(a, "2");
							else strcpy(a, "-1");
							strcpy(thongbao[sl + dem].IDgui, a);
							//thongbao[sl + dem].IDgui = ngDung[hientai].chucVu;
							thongbao[sl + dem].IDthongbao = sl + dem + 1;
							strcpy(thongbao[sl + dem].IDnhan, ngDung[i].sCMND);
							strcpy(thongbao[sl + dem].tieude, td);
							strcpy(thongbao[sl + dem].noidung, nd);

							time_t rawtime;
							struct tm *info;
							char buffer[50];

							time(&rawtime);

							info = localtime(&rawtime);

							strftime(buffer, 80, "%x - %I:%M%p", info);
							strcpy(thongbao[sl + dem].time, buffer);
							fstream outFile("ThongBao.DAT", ios::app);
							thongbao[sl + dem].ghi(outFile);
							outFile.close();
							dem++;
						}

					}
					cout << "Gui thanh cong!" << endl;
					Sleep(1311);
					break;
		}
		case 5: {
					system("cls");
					int slnd = TruyXuatNgDung(ngDung);
					int dem = 0;
					cout << " _________________________________________" << endl;
					cout << "|              TAO THONG BAO              |" << endl;
					cout << "|_________________________________________|" << endl;
					cout << endl;
					char td[100];
					char nd[1000];
					cout << "Nhap tieu de(<100 ky tu): "; cin.getline(td, 100);
					cout << "Nhap noi dung(<1000 ky tu): "; cin.getline(nd, 1000);
					char a[13];
					for (int i = 0; i < slnd; i++) {
						if (ngDung[i].chucVu.docgia == 1) {
							if (ngDung[hientai].chucVu.admin == 1) strcpy(a, "1");
							else if (ngDung[hientai].chucVu.thuthu == 1) strcpy(a, "2");
							else strcpy(a, "-1");
							strcpy(thongbao[sl + dem].IDgui, a);
							//thongbao[sl + dem].IDgui = ngDung[hientai].chucVu;
							thongbao[sl + dem].IDthongbao = sl + dem + 1;
							strcpy(thongbao[sl + dem].IDnhan, ngDung[i].sCMND);
							strcpy(thongbao[sl + dem].tieude, td);
							strcpy(thongbao[sl + dem].noidung, nd);

							time_t rawtime;
							struct tm *info;
							char buffer[50];

							time(&rawtime);

							info = localtime(&rawtime);

							strftime(buffer, 80, "%x - %I:%M%p", info);
							strcpy(thongbao[sl + dem].time, buffer);
							fstream outFile("ThongBao.DAT", ios::app);
							thongbao[sl + dem].ghi(outFile);
							outFile.close();
							dem++;
						}

					}
					cout << "Gui thanh cong!" << endl;
					Sleep(1311);
					break;
		}
		case 6: {
					system("cls");
					int slnd = TruyXuatNgDung(ngDung);
					int dem = 0;
					cout << " _________________________________________" << endl;
					cout << "|              TAO THONG BAO              |" << endl;
					cout << "|_________________________________________|" << endl;
					cout << endl;
					char td[100];
					char nd[1000];
					cout << "Nhap tieu de(<100 ky tu): "; cin.getline(td, 100);
					cout << "Nhap noi dung(<1000 ky tu): "; cin.getline(nd, 1000);
					char a[13];
					for (int i = 0; i < slnd; i++) {
						strcpy(thongbao[sl + i].IDgui, "-1");
						thongbao[sl + i].IDthongbao = sl + i + 1;
						strcpy(thongbao[sl + i].IDnhan, ngDung[i].sCMND);
						strcpy(thongbao[sl + i].tieude, td);
						strcpy(thongbao[sl + i].noidung, nd);


						time_t rawtime;
						struct tm *info;
						char buffer[50];

						time(&rawtime);

						info = localtime(&rawtime);

						strftime(buffer, 80, "%x - %I:%M%p", info);
						strcpy(thongbao[sl + i].time, buffer);
						fstream outFile("ThongBao.DAT", ios::app);
						thongbao[sl + i].ghi(outFile);
						outFile.close();



					}
					cout << "Gui thanh cong!" << endl;
					Sleep(1311);
					break;
		}
		default: {
					 cout << "Khong co lua chon nay. Quay laij menu chinh!" << endl;
					 Sleep(1311);
					 break;
		}
		}

	}

	////##########//Quyen 15. Sua thong tin sach ##########################################

	else if (quyen == 15) {
		system("cls");
		fstream inFile("Sach.DAT", ios::in);
		int sl = TruyXuatSach(sach);

		system("cls");
		cout << " _________________________________________" << endl;
		cout << "|           SUA THONG TIN SACH            |" << endl;
		cout << "|_________________________________________|" << endl;
		char idsach[13];
		bool timkiem = 0;
		cout << "Nhap ID sach can sua: ";
		cin >> idsach; cin.ignore();
		for (int i = 0; i < sl; i++) {
			if (strcmp(idsach, sach[i].ID) == 0) {
				cout << "Sach duoc tim thay: " << sach[i].tensach << endl;
				cout << "Nhap ten sach moi: ";
				cin.getline(sach[i].tensach, 30);
				cout << "Nhap ten tac gia: ";
				cin.getline(sach[i].tentacgia, 30);
				cout << "Nhap ngon ngu: ";
				cin.getline(sach[i].ngonngu, 20);
				cout << "Nhap the loai: ";
				cin.getline(sach[i].theloai, 20);
				timkiem = 1;
				cout << "Da luu thay doi";
			}
		}
		fstream outFile("Sach.DAT", ios::out);
		for (int i = 0; i < sl; i++) {
			sach[i].ghi(outFile);
		}

		inFile.close();
		outFile.close();
		if (timkiem = 0) cout << "Khong tim thay sach";
		inFile.close();
		outFile.close();
		Sleep(1311);
	}
	////##########//Quyen 16. Xoa sach #################################
	else if (quyen == 16) {
		system("cls");
		cout << " ______________________________________" << endl;
		cout << "|                XOA SACH              |" << endl;
		cout << "|______________________________________|" << endl;
		char id[13];
		int luachon;
		bool kt = 0;
		fstream inFile("Sach.DAT", ios::in);
		int sl = TruyXuatSach(sach);
		cout << "Nhap ID sach can xoa: ";
		cin.getline(id, 13);
		for (int i = 0; i < sl; i++) {
			if (strcmp(id, sach[i].ID) == 0) {
				kt = 1;
				cout << "Sach duoc tim thay: " << sach[i].tensach << endl;
				cout << "Ban co muon xoa sach: " << endl;
				cout << "1. Co" << endl;
				cout << "2. Khong" << endl;
				cout << "Nhap lua chon: ";
				cin >> luachon; cin.ignore();
				if (luachon == 1) {
					for (int j = i; j < sl; j++) {
						sach[j] = sach[j + 1];
					}
					cout << "Xoa sach thanh cong" << endl;

				}
				else {
					cout << "Xoa sach that bai" << endl;
					Sleep(1311);
				}
			}
		}
		fstream outFile("Sach.DAT", ios::out);
		for (int a = 0; a < sl; a++)
			sach[a].ghi(outFile);
		if (kt == 0)cout << "Khong tim thay sach";
		Sleep(1311);
	}

	////##########Quyen 17. Xem thong tin tai khoan ##########################################################

	else if (quyen == 17) {
		system("cls");
		cout << " ______________________________________" << endl;
		cout << "|       XEM THONG TIN TAI KHOAN        |" << endl;
		cout << "|______________________________________|" << endl;
		int soluong = TruyXuatNgDung(ngDung);
		cout << "=====================================================" << endl;
		cout << "So CMND:          " << ngDung[hientai].sCMND << endl;
		cout << "Ten Nguoi Dung:   " << ngDung[hientai].tenNguoiDung << endl;
		cout << "Ngay Sinh:        " << ngDung[hientai].ngaySinh << endl;
		cout << "Dia Chi:          " << ngDung[hientai].diaChi << endl;
		cout << "Ten Dang Nhap:    " << ngDung[hientai].tenDangNhap << endl;
		cout << "Chuc Vu:          ";
		if (ngDung[hientai].chucVu.admin == 1)cout << "Administration" << endl;
		else if (ngDung[hientai].chucVu.thuthu == 1)cout << "Thu Thu" << endl;
		else
		{
			cout << "Doc GIa" << endl;
		};
		cout << "======================================================" << endl;
		system("pause");
	}

	////##########//Quyen 18. Xem danh sach Nguoi dung.########################################################

	else if (quyen == 18) {
		system("cls");
		cout << " ______________________________________" << endl;
		cout << "|       XEM DANH SACH TAI KHOAN        |" << endl;
		cout << "|______________________________________|" << endl;
		char ql;
		cout << " ____________________________________________________________________________________________________________________" << endl;
		cout << "|" << setw(13) << left << "So CMND" << "|" << setw(28) << left << "Ho va ten" << "|" << setw(15) << left << "Ngay sinh" << "|" << setw(20) << left << "Dia chi" << "|" << setw(20) << left << "Chuc vu" << "|" << setw(15) << left << "Trang thai" << "|" << endl;
		cout << "|_____________|____________________________|_______________|____________________|____________________|_______________|" << endl;
		m = TruyXuatNgDung(ngDung);
		for (int i = 0; i < m; i++) {
			cout << "|" << setw(13) << left << ngDung[i].sCMND << "|" << setw(28) << left << ngDung[i].tenNguoiDung << "|" << setw(15) << left << ngDung[i].ngaySinh << "|" << setw(20) << left << ngDung[i].diaChi << "|" << setw(20) << left;
			if (ngDung[i].chucVu.admin == 1) cout << "Administration" << "|";
			else if (ngDung[i].chucVu.thuthu == 1) cout << "Thu Thu" << "|";
			else cout << "Doc Gia" << "|";
			cout << setw(15) << left;
			if (ngDung[i].trangThai == 1) cout << "Hoat Dong" << "|" << endl;
			else cout << "Bi khoa" << "|" << endl;
		}
		cout << "|_____________|____________________________|_______________|____________________|____________________|_______________|" << endl;
		system("pause");
	}
	////############Quyen 19. Sua thong tin tai khoan ##########################################################
	////NGHIA SUA GD
	else if (quyen == 19) {
		// QUANG
		system("cls");
		int luachon;
		int sl = TruyXuatNgDung(ngDung);

		cout << " ___________________________________________________________________________________________________________" << endl;
		cout << "|                                        SUA THONG TIN TAI KHOAN                                            |" << endl;
		cout << "|___________________________________________________________________________________________________________|" << endl;
		cout << "|                                          1. So CMND                                                       |" << endl;
		cout << "|                                          2. Ten nguoi dung                                                |" << endl;
		cout << "|                                          3. Ngay sinh                                                     |" << endl;
		cout << "|                                          4. Dia chi                                                       |" << endl;
		cout << "|                                          5. Ten tai khoan                                                 |" << endl;
		cout << "|___________________________________________________________________________________________________________|" << endl;
		cout << "Nhap lua chon: ";
		cin >> luachon; cin.ignore();
		switch (luachon)
		{
		case 1: {
					system("cls");
					cout << " ______________________________________" << endl;
					cout << "|              SUA SO CMND             |" << endl;
					cout << "|______________________________________|" << endl;
					cout << "So CMND cu: " << ngDung[hientai].sCMND << endl;
					cout << "Nhap so CMND moi: ";
					cin.getline(ngDung[hientai].sCMND, 13);
					cout << "Da thay doi so CMND";
					break;
		}
		case 2: {
					cout << "Ten nguoi dung cu: " << ngDung[hientai].tenNguoiDung << endl;
					cout << "Nhap ten nguoi dung moi: ";
					cin.getline(ngDung[hientai].tenNguoiDung, 30);
					cout << "Da thay doi ten nguoi dung";
					break;
		}
		case 3: {
					cout << "Ngay sinh cu: " << ngDung[hientai].ngaySinh << endl;
					cout << "Nhap ngay sinh moi: ";
					cin.getline(ngDung[hientai].ngaySinh, 15);
					cout << "Da thay doi ngay sinh";
					break;
		}
		case 4: {
					cout << "Ten dia chi cu: " << ngDung[hientai].diaChi << endl;
					cout << "Nhap dia chi moi: ";
					cin.getline(ngDung[hientai].diaChi, 50);
					cout << "Da thay doi dia chi";
					break;
		}
		case 5: {
					cout << "Ten tai khoan cu: " << ngDung[hientai].tenDangNhap << endl;
					cout << "Nhap ten tai khoan moi: ";
					cin.getline(ngDung[hientai].tenDangNhap, 30);
					cout << "Da thay doi ten tai khoan";
					break;
		}
		default:
			break;
		}
		fstream outFile("UserData.DAT", ios::out);
		for (int i = 0; i < sl; i++) ngDung[i].ghi(outFile);
		outFile.close();
		Sleep(2000);
	}

	////############Quyen 20. Yeu cau tu doc gia###################################################################3#

	else if (quyen == 20){
		system("cls");
		int choose;
		cout << " _________________________________________" << endl;
		cout << "|            YEU CAU TU DOC GIA           |" << endl;
		cout << "|_________________________________________|" << endl;
		cout << endl;
		int slnd = TruyXuatNgDung(ngDung);
		int sls = TruyXuatSach(sach);
		int slms = TruyXuatMuonSach(muonsach);
		int sl = TruyXuatYeuCau(yc);
		if (sl != 0){
			cout << "Co " << sl << " Yeu cau can giai quyet: " << endl;
			cout << "_______________________________________________________________________________________________" << endl;
			cout << setw(10) << left << "|Stt" << setw(15) << left << "|Ten yeu cau"
				<< setw(30) << left << "|Nguoi yeu cau";
			cout << setw(10) << left << "|ID sach" << setw(30) << left << "|Ten Sach" << "|" << endl;
			for (int i = 0; i < sl; i++) {
				cout << "|" << setw(9) << left << yc[i].stt << "|";
				(yc[i].mayc == 1) ? cout << setw(14) << left << "Muon sach" : cout << setw(14) << left << "Tra sach";
				cout << "|" << setw(29) << left << yc[i].tenND << "|";
				cout << setw(9) << left << yc[i].IDsach << "|" << setw(29) << left << yc[i].tensach << "|" << endl;
			}
			cout << "|_________|______________|_____________________________|_________|_____________________________|" << endl;
			cout << "Nhap lua chon: "; cin >> choose; cin.ignore();
			for (int i = 0; i < sl; i++){
				if (yc[i].stt == choose){
					if (yc[i].mayc == 1){
						cout << "Ban co mot yeu cau ";
						cout << "Muon sach ";
						cout << "tu ID " << yc[i].ID << "(" << yc[i].tenND << "):" << endl;
						cout << "ID sach muon:        " << yc[i].IDsach << endl;
						cout << "Ten sach muon:       " << yc[i].tensach << endl;
						cout << "Ten tac gia:         " << muonsach[yc[i].IDmuon].tentacgia << endl;
						cout << "Ngon ngu:            " << muonsach[yc[i].IDmuon].ngonngu << endl;
						cout << "The loai:            " << muonsach[yc[i].IDmuon].theloai << endl;
						cout << "Ngay muon:           " << muonsach[yc[i].IDmuon].ngayMuon[0] << "/" << muonsach[yc[i].IDmuon].ngayMuon[1] << "/" << muonsach[yc[i].IDmuon].ngayMuon[2] << endl;
						cout << "Xac nhan yeu cau(0-khong dong y, 1-dong y):"; cin >> yc[i].c; cin.ignore();
						if (yc[i].c == 1){
							fstream outFile("Sach.DAT", ios::out);
							for (int l = 0; l < sls; l++) {
								if (strcmp(sach[l].ID, yc[i].IDsach) == 0) sach[l].trangthai = 0; // da muon
								sach[l].ghi(outFile);
							}
							outFile.close();
							fstream out2File("MuonSach.DAT", ios::out);
							for (int l = 0; l < slms; l++) {
								if (strcmp(muonsach[l].IDsach, muonsach[yc[i].IDmuon].IDsach) == 0) muonsach[l].trangthai = 0; // da muon
								muonsach[l].ghi(out2File);
							}
							out2File.close();
							int ndht = 0;



							for (int l = 0; l < slnd; l++){
								if (strcmp(ngDung[l].sCMND, yc[i].ID) == 0) ndht = l;
							}
							cout << "Xac nhan thanh cong!" << endl;
							cout << ndht << endl;
							ThongBaoTuDong(ngDung, thongbao, muonsach, ndht, yc[i].tensach, 0);
							for (int j = i; j < sl; j++){
								yc[j] = yc[j + 1];
							}
							fstream outF("YeuCau.DAT", ios::out);
							for (int j = 0; j < sl - 1; j++){
								yc[j].ghi(outF);
							}
							outF.close();
						}
						else {
							fstream outFile("Sach.DAT", ios::out);
							for (int l = 0; l < sls; l++) {
								if (strcmp(sach[l].ID, yc[i].IDsach) == 0) sach[l].trangthai = 1; // chua muon
								sach[l].ghi(outFile);
							}
							outFile.close();
							fstream out2File("MuonSach.DAT", ios::out);
							for (int l = 0; l < slms; l++) {
								if (strcmp(muonsach[l].IDsach, muonsach[yc[i].IDmuon].IDsach) == 0) muonsach[l].trangthai = 1; // chua muon
								muonsach[l].ghi(out2File);
							}
							out2File.close();
							int ndht = 0;



							for (int l = 0; l < slnd; l++){
								if (strcmp(ngDung[l].sCMND, yc[i].ID) == 0) ndht = l;
							}
							cout << "Xac nhan thanh cong!" << endl;
							cout << ndht << endl;
							ThongBaoTuDong(ngDung, thongbao, muonsach, ndht, yc[i].tensach, 1);
							for (int j = i; j < sl; j++){
								yc[j] = yc[j + 1];
							}
							fstream outF("YeuCau.DAT", ios::out);
							for (int j = 0; j < sl - 1; j++){
								yc[j].ghi(outF);
							}
							outF.close();
						}
					}
				}
			}
		}
		else cout << "Ban khong co yeu cau nao" << endl;
		Sleep(3000);
	}

	//##########QUyen 21. Doi vai tro###############################################################################

	else if (quyen == 21) {
		Quyen q[30];
		TruyXuatQuyen(q);
		int dem = 1;
		int op, op2;
		cout << " ____________________________" << endl;
		cout << "|        DOI VAI TRO         |" << endl;
		cout << "|____________________________|" << endl;
		cout << "| Cac vai tro hien tai:      |" << endl;
		if (ngDung[hientai].chucVu.admin == 1){
			cout << "| " << dem << ". Admin                   |" << endl;
			dem++;
		}
		if (ngDung[hientai].chucVu.thuthu == 1){
			cout << "| " << dem << ". Thu Thu                 |" << endl;
			dem++;
		}
		if (ngDung[hientai].chucVu.docgia == 1){
			cout << "| " << dem << ". Doc Gia                 |" << endl;
			dem++;
		}
		cout << "|____________________________|" << endl;
		cout << "Nhap lua chon: "; cin >> op; cin.ignore();

		switch (op){
		case 1:{
				   if (ngDung[hientai].chucVu.admin == 1){
					   int kt = 0;
					   do {
						   ShowMenu(ngDung, 0, q, 1);
						   cout << "Nhap lua chon: "; cin >> op2; cin.ignore();
						   if (q[op2].Admin == 0) cout << "Ban khong duoc ho tro chuc nang nay!";
						   else kt = Chucnang(hientai, ngDung, op2, m, q, tdn, sach, muonsach, thongbao, yc);
					   } while (kt == 0);
					   return 0;
				   }
				   else cout << "Ban khong co chuc vu nay!" << endl;
		}
		case 2:{
				   if (ngDung[hientai].chucVu.thuthu == 1){
					   int kt = 0;
					   do {
						   ShowMenu(ngDung, 0, q, 2);
						   cout << "Nhap lua chon: "; cin >> op2; cin.ignore();
						   if (q[op2].ThuThu == 0) cout << "Ban khong duoc ho tro chuc nang nay!";
						   else kt = Chucnang(hientai, ngDung, op2, m, q, tdn, sach, muonsach, thongbao, yc);
					   } while (kt == 0);
					   return 0;
				   }
				   else cout << "Ban khong co chuc vu nay!" << endl;
		}
		case 3:{
				   if (ngDung[hientai].chucVu.docgia == 1){
					   int kt = 0;
					   do {
						   ShowMenu(ngDung, 0, q, 3);
						   cout << "Nhap lua chon: "; cin >> op2; cin.ignore();
						   if (q[op2].DocGia == 0) cout << "Ban khong duoc ho tro chuc nang nay!";
						   else kt = Chucnang(hientai, ngDung, op2, m, q, tdn, sach, muonsach, thongbao, yc);
					   } while (kt == 0);
					   return 0;
				   }
				   else cout << "Ban khong co chuc vu nay!" << endl;
		}
		}
		/*do {
		system("cls");
		int ch = 0;
		if (ngDung[k].chucVu.admin == 1){
		ShowMenu(ngDung, chucvu, quyen, 1);
		cout << "Nhap lua chon: "; cin >> op; cin.ignore();
		if (quyen[op].Admin == 0) cout << "Ban khong duoc ho tro chuc nang nay!";
		else kt = Chucnang(taikhoanhientai, ngDung, op, m, quyen, tdn, sach, muonsach, thongbao, yc);
		}
		else if (ngDung[k].chucVu.thuthu == 1) {
		ShowMenu(ngDung, chucvu, quyen, 2);
		cout << "Nhap lua chon: "; cin >> op; cin.ignore();
		if (quyen[op].ThuThu == 0) cout << "Ban khong duoc ho tro chuc nang nay!";
		else kt = Chucnang(taikhoanhientai, ngDung, op, m, quyen, tdn, sach, muonsach, thongbao, yc);
		}
		else ShowMenu(ngDung, chucvu, quyen, 3);
		Sleep(1311);
		} while (kt != 1);*/

	}

	//##########//Quyen 22. Dang xuat.#########################################################################3##

	else if (quyen == 22) {
		system("cls");
		int qq;
		cout << "Ban muon thoat?(yes = 1, no = 0) "; cin >> qq; cin.ignore();
		if (qq == 1); //exit(0);
		//break;
		return qq;
	}


	return 0;
}