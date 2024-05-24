#ifndef LAPTOP_H
#define LAPTOP_H
#include<iostream> // thu vien chuan c+++
#include<ctime> // lay thoi gian tu he thong tu do xuat ra man hinh va ghi vao file du lieu dau ra
#include<fstream> // dung de doc xuat file
#include<string> // c++ string class
#include<string.h> // cstring
#include<vector> // dung vector de nhap du lieu
#include<sstream> /* bien xau string tu du lieu dau vao thanh mot luong (tuong tu nhu nhap tu ban phim) ket hop voi do la tach du lieu tu 
                    thanh tung phan rieng biet de tiep tuc xu li nhung cong viec tiep theo*/
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
    //setters
        void setMalaptop(string malaptop);
		void setTen(string ten);
		void setGia(long gia);
		void setHang(string hang);
		void setSoluong(int soluong);
		void setNamsanxuat(int namsanxuat);
    // getters
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

    //Ham chuc nang
    void phieunhapkho(int& choice); // ham de in phieu nhap kho ra file
    void nhapthongtinLaptop(); // ham de nhap thong tin mot laptop
    void hienThiDanhSach(const vector<Laptop>& dslaptop); // hien thi danh sach ra man hinh console
    void nhapmoiLaptop(vector<Laptop>& dslaptop); // ham de nhap them laptop vao kho
    void timkiem(vector<Laptop>& dslaptop);//ham tim kiem laptop trong kho thong qua ten hang hoac malaptop
    void chinhSuaLaptop(vector<Laptop>& dslaptop); // ham de chinh sua thong tin laptop 
    void sapXepTheoGia(vector<Laptop>& dslaptop); //ham sap xep theo gia tang dan hoac giam dan
    void xuatlaptop(vector<Laptop>& dslaptop); //ham voi 2 chuc nang, mot la xoa laptop, hai la xuat laptop di
    void Nhatkyxuatnhap();// in ra nhat ky xuat nhap cua kho ra man hinh console
};
#endif // LAPTOP_H
