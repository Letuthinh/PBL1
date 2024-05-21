#ifndef NHANVIEN_H
#define NHANVIEN_H
#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<windows.h>
#include<vector>
#include<fstream>
#include<iomanip>
#include<stdlib.h>
#include<sstream>
using namespace std;

class NhanVien{
private:
    string user;
    string pass;
    string maNv;
    string ten;
    int tuoi;
    long luong;
    int giolamviec;
    public:
    NhanVien(){};
    NhanVien(string user,string pass,string maNv,string ten,int tuoi,long luong,int giolamviec);
    void SetUser(string user);
    void setPass(string pass);
    void setMaNv(string maNv);
    void setTen(string ten);
    void setTuoi(int tuoi);
    void setLuong(long luong);
    void setGioLamViec(int giolamviec);
    string getUser() const ;
    string getPass() const ;
    string getMaNv() const ;
    string getTen() const ;
    int getTuoi() const ;
    long getLuong() const ;
    int getGioLamViec() const ;

    //getter:
    vector<NhanVien> docDanhSachNhanVien();
    void nhapthongtinNV();
    void hienThiDanhSachNhanVien(const vector<NhanVien>& danhSachNhanVien);
    void themNhanVien(vector<NhanVien>& danhSachNhanVien);
    void suaNhanVien(vector<NhanVien>& danhSachNhanVien);
    void xoaNhanVien(vector<NhanVien>& danhSachNhanVien);
    void timkiemNhanVien(vector<NhanVien>& danhSachNhanVien);
    void luudssv(const vector<NhanVien>& danhSachNhanVien, const string& tenTepTin);

};

#endif // NHANVIEN_H
