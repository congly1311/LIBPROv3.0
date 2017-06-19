#pragma once
#include "TruyXuat.h"
#include "Sach.h"
#include "MuonSach.h" 
#include "YeuCau.h"
#include "ThongBao.h"
#include "ThongBaoTuDong.h"
#include "InMuonSach.h"
void muontrasach(Sach sach[], MuonSach muonsach[], NguoiDung ngDung[], int hientai, YeuCau yc[], ThongBao thongbao[], int w){
	time_t baygio = time(0);
	tm *ltm = localtime(&baygio);
	//nguoi dung hien tai
	char id[13];
	int op;
	int sl1 = TruyXuatSach(sach);
	int sl2 = TruyXuatMuonSach(muonsach);
	int dem = 0;
	for (int i = 0; i < sl2; i++) {
		if (strcmp(muonsach[i].IDmuon, ngDung[hientai].sCMND) == 0)
		if (muonsach[i].trangthai == 0)
			dem++;
	}
	system("cls");
	if (w == 1){
		cout << " _________________________________________" << endl;
		cout << "|           DANG KY MUON SACH             |" << endl;
		cout << "|_________________________________________|" << endl;
		cout << endl;
		if (dem != 0) {
			cout << "Co " << dem << " Sach da muon: " << endl;
			inmuonsach(ngDung, muonsach, hientai, 0);
			}
		cout << "Nhap ID sach muon muon: "; cin.getline(id, 13);
		for (int i = 0; i < sl1; i++) {
			if (strcmp(id, sach[i].ID) == 0) {
				if (sach[i].trangthai == 1) {
					cout << "Tim thay: " << sach[i].tensach << endl;
					cout << "Ban co muon muon sach nay?" << endl;
					cout << "1. Co " << endl;
					cout << "2. Khong " << endl;
					cout << "Nhap lua chon: "; cin >> op; cin.ignore();
					switch (op) {
					case 1: {
								muonsach[sl2].ID = sl2 + 1;
								strcpy(muonsach[sl2].IDmuon, ngDung[hientai].sCMND);
								strcpy(muonsach[sl2].IDsach, sach[i].ID);


								strcpy(muonsach[sl2].tensach, sach[i].tensach);
								strcpy(muonsach[sl2].tentacgia, sach[i].tentacgia);
								strcpy(muonsach[sl2].ngonngu, sach[i].ngonngu);
								strcpy(muonsach[sl2].theloai, sach[i].theloai);
								muonsach[sl2].ngayMuon[0] = ltm->tm_mday;
								muonsach[sl2].ngayMuon[1] = 1 + ltm->tm_mon;
								muonsach[sl2].ngayMuon[2] = 1900 + ltm->tm_year;
								muonsach[sl2].ngayTra[0] = ltm->tm_mday + 15;
								muonsach[sl2].trangthai = 2;// dang xu ly
								if (muonsach[sl2].ngayMuon[0] + 15 > 30) {
									muonsach[sl2].ngayTra[0] = ltm->tm_mday + 15 - 29;
									muonsach[sl2].ngayTra[1] = muonsach[sl2].ngayMuon[1] + 1;
									if (muonsach[sl2].ngayTra[1] > 12) {
										muonsach[sl2].ngayTra[1] = 1;
										muonsach[sl2].ngayTra[2] = muonsach[sl2].ngayMuon[2] + 1;
									}
									else {
										muonsach[sl2].ngayTra[2] = muonsach[sl2].ngayMuon[2];
									}
								}
								else {
									muonsach[sl2].ngayTra[0] = ltm->tm_mday + 15;
									muonsach[sl2].ngayTra[1] = 1 + ltm->tm_mon;
									muonsach[sl2].ngayTra[2] = 1900 + ltm->tm_year;
								}
								fstream outFile("MuonSach.DAT", ios::app);
								muonsach[sl2].ghi(outFile);
								outFile.close();
								cout << "Yeu cau muon sach cua ban dang duoc xu ly! Ban se nhan duoc thong bao xac nhan sau. Xin cam on.";
								sach[i].trangthai = 2; // dang xu ly

								int slyc = TruyXuatYeuCau(yc);
								yc[slyc].stt = slyc + 1;
								//yc[slyc].GetInf(1, ngDung[hientai].sCMND, ngDung[hientai].tenNguoiDung, muonsach[sl2].IDsach, muonsach[sl2].tensach, sl2);

								yc[slyc].mayc = 1;
								strcpy(yc[slyc].ID, ngDung[hientai].sCMND);
								strcpy(yc[slyc].IDsach, muonsach[sl2].IDsach);
								strcpy(yc[slyc].tensach, muonsach[sl2].tensach);
								strcpy(yc[slyc].tenND, ngDung[hientai].tenNguoiDung);
								yc[slyc].IDmuon = sl2;

								fstream out1File("YeuCau.DAT", ios::app);
								yc[slyc].ghi(out1File);
								out1File.close();
								fstream out2File("Sach.DAT", ios::out);
								for (int j = 0; j < sl1; j++){
									sach[j].ghi(out2File);
								}
								out2File.close();
								//ThongBaoTuDong(ngDung, hientai, thongbao, 2, muonsach);

					}
					default:
						break;
					}
				}
				else cout << "Khong thay sach can tim hoac sach da duoc muon" << endl;
			}
		}
		Sleep(3000);
	}
	else {
		
		
		system("cls");
		cout << " _________________________________________" << endl;
		cout << "|                TRA SACH                 |" << endl;
		cout << "|_________________________________________|" << endl;
		char id[13];
		int dem = 0;

		for (int i = 0; i < sl2; i++) {
			if (strcmp(muonsach[i].IDmuon, ngDung[hientai].sCMND) == 0)
			if (muonsach[i].trangthai == 0)
				dem++;
		}
		if (dem == 0) {
			cout << "Ban chua muon sach nao." << endl;
		}
		else {
			cout << "Co " << dem << " Sach da muon: " << endl;
			inmuonsach(ngDung, muonsach, hientai, 0);
			cout << "Nhap ID sach muon tra: "; cin.getline(id, 13);
			for (int i = 0; i < sl2; i++) {
				if (strcmp(muonsach[i].IDsach, id) == 0) {
					if (strcmp(muonsach[i].IDmuon, ngDung[hientai].sCMND) == 0) {
						cout << "Tim thay sach " << muonsach[i].tensach << endl;
						cout << "Ban co muon tra sach nay khong? " << endl;
						int op;
						cout << "1. Co" << endl;
						cout << "2. Khong" << endl;
						cout << "Nhap lua chon: "; cin >> op; cin.ignore();
						switch (op) {
						case 1: {
									for (int j = i; j < sl2; j++)
										muonsach[j] = muonsach[j + 1];
									fstream outFile("MuonSach.DAT", ios::out);
									for (int l = 0; l < sl2 - 1; l++) {
										muonsach[l].ghi(outFile);
									}
									for (int l = 0; l < sl1; l++) {
										if (strcmp(sach[l].ID, id) == 0) sach[l].trangthai = 1;
									}
									//sach[id - 1].trangthai = 1;
									cout << "Da tra sach!" << endl;
									int choose;
									int diem;
									cout << " _________________________________________" << endl;
									cout << "|                DANH GIA                 |" << endl;
									cout << "|_________________________________________|" << endl;
									cout << "Ban co muon danh gia sach" << endl;
									cout << "1. Co \n2. Khong" << endl;
									cout << "Nhap lua chon: ";
									cin >> choose;
									int k = 0;
									for (k = 0; k < sl2; k++) {
										if (strcmp(sach[k].ID, id) == 0)break;

									}
									if (choose == 1) {
										cout << "Nhap so diem ban danh gia: ";
										cin >> diem;
										sach[k].danhgia = (sach[k].danhgia*sach[k].soluotdanhgia + diem) / (sach[k].soluotdanhgia + 1);
										sach[k].soluotdanhgia = sach[k].soluotdanhgia + 1;
										cout << "Cam on ban da danh gia !!!";
									}
									fstream out1File("Sach.DAT", ios::out);
									for (int j = 0; j < sl1; j++) {
										sach[j].ghi(out1File);
									}
									ThongBaoTuDong(ngDung, hientai, thongbao, 3, muonsach);
									break;
						}
						default:
							break;
						}
					}
					else cout << "Ban khong muon sach nay." << endl;
				}
			}

		}
		Sleep(1311);

	}
}