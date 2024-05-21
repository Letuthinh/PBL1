#include "laptop.cpp"
#include "nhanvien.cpp"
int menu1(){
    chon:
        system("cls");
        cout<<"\n\n\t\t\t\t *********************************************************** \n";
        cout<<"\t\t\t\t     ****************      MENU QuanLiKho     ****************\n";
        cout<<"\t\t\t\t 1.Hien thi danh sach laptop trong kho "<<endl;
        cout<<"\t\t\t\t 2.Nhap laptop moi "<<endl;
        cout<<"\t\t\t\t 3.Chinh sua laptop"<<endl;
        cout<<"\t\t\t\t 4.Xuat kho laptop "<<endl;
        cout<<"\t\t\t\t 5.Sap xep theo gia"<<endl;
        cout<<"\t\t\t\t 6.Tim kiem laptop"<<endl;
        cout<<"\t\t\t\t 7.Nhat Ky Xuat Nhap Kho"<<endl;
        cout<<"\t\t\t\t 8.Tro lai man hinh chinh "<<endl;
        cout<<"\t\t\t\t NHAP LUA CHON CUA BAN :";

        int chon;
        cin>>chon;
        cout<<endl;
    Laptop laptops;
    vector<Laptop> dslaptop = laptops.docdulieu();

    switch (chon){
    case 1:
    laptops.hienThiDanhSach(dslaptop);
    cout<<"Nhan ENTER de tro lai:"<<endl;
    getch();
    goto chon;
    break;
    case 2:
    laptops.nhapmoiLaptop(dslaptop);
    laptops.writeData(dslaptop,"Input/kholaptop.txt");
    cout<<"Nhan ENTER de tro lai:"<<endl;
    getch();
    goto chon;
    break;
   case 3:
    laptops.chinhSuaLaptop(dslaptop);
    cout<<"Nhan ENTER de tro lai:"<<endl;
    laptops.writeData(dslaptop,"Input/kholaptop.txt");
    getch();
    goto chon;
    break;
    case 4:
    laptops.xuatlaptop(dslaptop);
    cout<<"Nhan ENTER de tro lai:"<<endl;
    laptops.writeData(dslaptop,"Input/kholaptop.txt");
    getch();
    goto chon;
    break;
    case 5:
    laptops.sapXepTheoGia(dslaptop);
    cout<<"Nhan ENTER de tro lai:"<<endl;
    getch();
    goto chon;
    break;
    case 6:
    laptops.timkiem(dslaptop);
    cout<<"Nhan ENTER de tro lai:"<<endl;
    getch();
    goto chon;
    case 7:
    laptops.Nhatkyxuatnhap();
    cout<<"Nhan ENTER de tro lai:"<<endl;
    getch();
    goto chon;
    case 8:
    return 1;
    default:
    cout<<"Gia tri khong hop le. Vui long nhap lai:"<<endl;
    goto chon;
    }
    laptops.writeData(dslaptop,"Input/kholaptop.txt");
    }
int menu2(){
    chon3:
        system("cls");
        cout<<"\n\n\t\t\t\t *********************************************************** \n";
        cout<<"\t\t\t\t     ****************      MENU QuanLiNhanVien     ****************\n";
        cout<<"\t\t\t\t 1.Hien thi danh sach nhan vien trong kho "<<endl;
        cout<<"\t\t\t\t 2.Them nhan vien moi "<<endl;
        cout<<"\t\t\t\t 3.Chinh sua thong tin nhan vien"<<endl;
        cout<<"\t\t\t\t 4.Xoa nhan vien "<<endl;
        cout<<"\t\t\t\t 5.Tim kiem nhan vien"<<endl;
        cout<<"\t\t\t\t 6.Nhat Ky Xuat Nhap Kho"<<endl;
        cout<<"\t\t\t\t 7.Tro lai man hinh chinh "<<endl;
        cout<<"\t\t\t\t NHAP LUA CHON CUA BAN :";

        int chon;
        cin>>chon;
        cout<<endl;
    Laptop laptops;
    vector<Laptop> dslaptop = laptops.docdulieu();
    NhanVien nhanviens;
    vector<NhanVien> dsnv=nhanviens.docDanhSachNhanVien();
    switch (chon){
    case 1:
    nhanviens.hienThiDanhSachNhanVien(dsnv);
    cout<<"Nhan ENTER de tro lai:"<<endl;
    getch();
    goto chon3;
    break;
    case 2:
    nhanviens.themNhanVien(dsnv);
    nhanviens.luudssv(dsnv,"Input/dulieunhanvien.txt");
    cout<<"Nhan ENTER de tro lai:"<<endl;
    getch();
    goto chon3;
    break;
   case 3:
    nhanviens.suaNhanVien(dsnv);
    cout<<"Nhan ENTER de tro lai:"<<endl;
    nhanviens.luudssv(dsnv,"Input/dulieunhanvien.txt");
    getch();
    goto chon3;
    break;
    case 4:
    nhanviens.xoaNhanVien(dsnv);
    cout<<"Nhan ENTER de tro lai:"<<endl;
    nhanviens.luudssv(dsnv,"Input/dulieunhanvien.txt");
    getch();
    goto chon3;
    break;
    case 5:
    nhanviens.timkiemNhanVien(dsnv);
    cout<<"Nhan ENTER de tro lai:"<<endl;
    getch();
    goto chon3;
    case 6:
//    laptops.Nhatkyxuatnhap();
    cout<<"Nhan ENTER de tro lai:"<<endl;
    getch();
    goto chon3;
    case 7:
    return 1;
    default:
    cout<<"Gia tri khong hop le. Vui long nhap lai:"<<endl;
    goto chon3;
    }
    nhanviens.luudssv(dsnv,"Input/dulieunhanvien.txt");
    }
