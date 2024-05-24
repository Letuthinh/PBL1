#ifndef NHANVIEN_H //chi thi tien xu li
#define NHANVIEN_H // chi thi tien xu li dinh nghia ten file
#include<iostream> //thu vien chuan cua c++
#include<stdio.h> //thu vien chuan cua c#
#include<string> // thu vien string cua c++
#include<string.h> // thu vien string cua c# ()
#include<windows.h> // dung de dinh dang lai man hinh console như mau sac, mau phong chu ...
#include<vector> // co tinh chat tuong tu nhu mot mang dong, khi xoa hoac them vao se tu thay doi kich thuoc
#include<fstream> //thu vien voi cac ham dung de doc va xuat du lieu tu file
#include<iomanip> // thu vien voi cac ham de dinh dang du lieu dau ra de co tinh tham my cao
#include<sstream> /* bien xau string tu du lieu dau vao thanh mot luong (tuong tu nhu nhap tu ban phim) ket hop voi do la tach du lieu tu 
                    thanh tung phan rieng biet de tiep tuc xu li nhung cong viec tiep theo*/
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
    // Constructor
    NhanVien(){};
    NhanVien(string user,string pass,string maNv,string ten,int tuoi,long luong,int giolamviec);
   //getters:
    void SetUser(string user);
    void setPass(string pass);
    void setMaNv(string maNv);
    void setTen(string ten);
    void setTuoi(int tuoi);
    void setLuong(long luong);
    void setGioLamViec(int giolamviec);
    //setters
    string getUser() const ;
    string getPass() const ;
    string getMaNv() const ;
    string getTen() const ;
    int getTuoi() const ;
    long getLuong() const ;
    int getGioLamViec() const ;
    // Cac ham chuc nang:
    vector<NhanVien> docDanhSachNhanVien(); // doc danh sach nhan vien tu file
    void nhapthongtinNV(); // nhap thong tin 1 nv (thuc hien boi nguoi quan li)
    void hienThiDanhSachNhanVien(const vector<NhanVien>& danhSachNhanVien);//hien thi danh sach doc tu file ra man hinh chinh
    void themNhanVien(vector<NhanVien>& danhSachNhanVien);//them nhung nhan vien moi (bang cach nhapthong tin qua ham nhapthongtin())
    void suaNhanVien(vector<NhanVien>& danhSachNhanVien);//chinh sua thong tin cua nhan vien
    void xoaNhanVien(vector<NhanVien>& danhSachNhanVien);// xoa nhan vien 
    void timkiemNhanVien(vector<NhanVien>& danhSachNhanVien);//tim kiem nhan vien theo ma
    void luudssv(const vector<NhanVien>& danhSachNhanVien, const string& tenTepTin);// xuat thong tin nhan vien ra file

};

#endif // NHANVIEN_H
