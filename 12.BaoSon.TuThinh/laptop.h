#ifndef LAPTOP_H
#define LAPTOP_H
#include<iostream>
#include<ctime>
#include<fstream> // dung de doc xuat file
#include<string> // c++ string class
#include<string.h> // cstring
#include<vector> // dung vector de nhap du lieu
#include<sstream> // dung de tach tung tu trong xau boi dau cach hoac ky tu ....
#include<iomanip> // dung de dinh dang lai du lieu
#include<conio.h> // dung ham getch() để chờ người sử dụng ấn một phím bất kì rồi sẽ kết thúc chương trình
using namespace std;

class Laptop {
private:
    string malaptop;
    string hang;
    string ten;
    long gia;
    int soluong;
    int namsanxuat;

public:
    // Constructor
    Laptop(){};
    Laptop(string malaptop, string hang, string ten,long gia,int soluong, int namsanxuat);
    //setter
        void setMalaptop(string malaptop);
		void setTen(string ten);
		void setGia(long gia);
		void setHang(string hang);
		void setSoluong(int soluong);
		void setNamsanxuat(int namsanxuat);
    // getter
    string getMaLaptop() const;
    string getHang() const;
    string getTen() const;
    long getGia()const;
    int getSoLuong() const;
    int getNamSanXuat() const;

    // Ham doc du lieu tu file
    vector<Laptop> docdulieu();

    // Ham ghi du lieu vao file
    void writeData(const vector<Laptop>& dslaptop,const string& filename);

    // Other methods for managing laptops
    void phieunhapkho(int& choice);
    void nhapthongtinLaptop();
    void hienThiDanhSach(const vector<Laptop>& dslaptop);
    void nhapmoiLaptop(vector<Laptop>& dslaptop);
    void timkiem(vector<Laptop>& dslaptop);
    void chinhSuaLaptop(vector<Laptop>& dslaptop);
    void sapXepTheoGia(vector<Laptop>& dslaptop);
    void xuatlaptop(vector<Laptop>& dslaptop);
    void Nhatkyxuatnhap();
};


#endif // LAPTOP_H
