#include "login.h"


/* Bảng màu
0	BLACK
1	BLUE
2	GREEN
3	AQUA
4	RED
5	PURPLE
6	YELLOW
7	WHITE
8	GRAY
9	LIGHT BLUE
10 ( A )	LIGHT GREEN
11 ( B )	LIGHT AQUA
12 ( C )	LIGHT RED
13 ( D )	LIGHT PURPLE
14 ( E )	LIGHT YELLOW
15 ( F )	BRIGHT WHITE */


void SET_MAU(int MAU)
{
	WORD chonmau;


     HANDLE Out = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO a;
     if(GetConsoleScreenBufferInfo(Out, &a))
     {
          chonmau = (a.wAttributes & 0xF0) + (MAU & 0x0F);
          SetConsoleTextAttribute(Out, chonmau);
     }
}
int admin(){
	string nguoidung,mk;
	int check;
	system("cls");
    cout << "\t\t\t\t HAY NHAP CHI TIET NHUNG THONG TIN BEN DUOI CHO TK ADMIN : \t ";
    cout << "\n\t\t\t\t TENNGUOIDUNG: ";
    cin >> nguoidung;
    cout << "\t\t\t\t MATKHAU: ";
    cin >> mk;
    if (nguoidung=="admin" && mk=="admin"){
         system("cls");
        cout<<"\t\t\t\t CHAO MUNG "<<nguoidung<<"\n\t\t\t\t <BAN DA DANG NHAP THANH CONG>" <<"\n\t\t\t\t CHUC BAN CO TRAI NGHIEM TOT\n";
        return check=1;
    }
    else
    {
        cout<<"\n\t\t\t\t DANG NHAP THAT BAI \n"<<"\t\t\t\t LAM ON KIEM TRA LAI\n ";
        return check=0;

    }
    return check;
}
int user(){
    int count;
    int check;
    string nguoidung,mk,user,pass,manv,ten,tuoi,luong,glv;
    system("cls");
    cout << "\t\t\t\t HAY NHAP CHI TIET NHUNG THONG TIN BEN DUOI CHO TK ADMIN : \n ";
    cout << "\t\t\t\t TENNGUOIDUNG: ";
    cin >> nguoidung;
    cout << "\t\t\t\t MATKHAU: ";
    cin >> mk;
    ifstream dauvao("Input/dulieunhanvien.txt");
    if(dauvao.is_open()){
    string line,header;
    getline(dauvao,header);
    while(getline(dauvao,line)){
        stringstream str(line);
        getline(str,user,';');
        getline(str,pass,';');
        getline(str,manv,';');
        getline(str,ten,';');
        getline(str,tuoi,';');
        getline(str,luong,';');
        getline(str,glv,';');
    }
    dauvao.close();

    }
    if ((strcmp(nguoidung.c_str(),user.c_str())==0 )&&(strcmp(mk.c_str(),pass.c_str())==0)){
         count=1;
    }
    if (count==1){
        system("cls");
        cout<<"\t\t\t\t Chao mung "<<ten<<"\n\t\t\t\t <BAN DA DANG NHAP THANH CONG>" <<"\n\t\t\t\t CHUC BAN CO TRAI NGHIEM TOT\n";
        check=1;

    }
	else
	{
		cout<<"\n\t\t\t\t DANG NHAP THAT BAI \n"<<"\t\t\t\t LAM ON KIEM TRA LAI\n ";
        check=0;
        system ("pause");
	}

return check;
}
void dangky(){
    string nguoidungmoi,mkmoi,ten,manv,tuoi,luong,giolamviec;

    cout << "\t\t\t\t NHAP TEN NGUOI DUNG MOI: ";
    cin >> nguoidungmoi;
    cout << "\t\t\t\t NHAP MK MOI: ";
    cin >> mkmoi;
    cout << "\t\t\t\t NHAP MaNv: ";
    cin >> manv;
    cout << "\t\t\t\t NHAP HovaTen: ";
    cin >> ten;
    cout << "\t\t\t\t NHAP Tuoi: ";
    cin >> tuoi;
    cout << "\t\t\t\t NHAP Luong: ";
    cin >> luong;
    cout << "\t\t\t\t NHAP GioLamViec: ";
    cin >> giolamviec;
    ofstream daura("Input/dulieunhanvien.txt",ios::app);
    if(daura.is_open()){
    daura<<nguoidungmoi<<';'<<mkmoi<<';'<<manv <<';'<<ten <<';'<<tuoi <<';'<<luong<<';'<<giolamviec<<';'<<endl;
    daura.close();
	system("cls");
    cout<<"DANG KY THANH CONG. VUI LONG DANG NHAP LAI ";
    }

 }
void quen(){
    int lc;
    cout << "\t\t\t\t NHAP NHUNG THONG TIN SAU DE TIM TAI KHOAN: \n";
    cout << "\t\t\t\t 1.TIM TAI KHOAN CUA BAN BANG TEN NGUOI DUNG: \n";
    cout << "\t\t\t\t 2.TIM TAI KHOAN CUA BAN BANG MAT KHAU: \n";
    cout << "\t\t\t\t 3.TRO LAI MAN HINH CHINH: \n";
    cout << "\t\t\t\t NHAP LUA CHON CUA BAN: ";
    cin >> lc;
    switch (lc){
        case 1:
        {int dem=0;
        string tkten,user,pass,ten,manv,tuoi,luong,glv,su,sp,st;
        system("cls");
        cout <<"\t\t\t\t VUI LONG NHAP TEN NGUOI DUNG MA BAN NHO:";
        cin>>tkten;
        ifstream timten("Input/dulieunhanvien.txt");
        if(timten.is_open()){
        string line,header;
        getline(timten,header);
        while(getline(timten,line)){
        stringstream str(line);
        getline(str,user,';');
        getline(str,pass,';');
        getline(str,manv,';');
        getline(str,ten,';');
        getline(str,tuoi,';');
        getline(str,luong,';');
        getline(str,glv,';');
        }
        timten.close();
        }
        if ((strcmp(tkten.c_str(),user.c_str())==0)){
                dem=1;

            }

        if (dem==1){
            system("cls");
            cout <<"\t\t\t\t CHUC MUNG BAN DA TIM RA TAI KHOAN CUA MINH: \n";
            cout <<"\t\t\t\t TENNGUOIDUNG: "<<user<<"\n\t\t\t\t MATKHAU: "<< pass <<"\n\t\t\t\t Ten"<<ten;
            cin.get();
            cin.get();

        }
        else
        {   system("cls");
            cout <<"\t\t\t\t KHONG TIM THAY TAI KHOAN \n\t\t\t\t VUI LONG LIEN HE VA THU LAI: ";
            cin.get();
            cin.get();

        }
       break;
    }
        case 2:
        {int dem=0;
        string mktk,user,pass,ten,manv,tuoi,luong,glv;
        system("cls");
        cout <<"\t\t\t\t VUI LONG NHAP TEN NGUOI DUNG MA BAN NHO:";
        cin>>mktk;
        ifstream timmk("Input/dulieunhanvien.txt");
        if(timmk.is_open()){
        string line,header;
        getline(timmk,header);
        while(getline(timmk,line)){
        stringstream str(line);
        getline(str,user,';');
        getline(str,pass,';');
        getline(str,manv,';');
        getline(str,ten,';');
        getline(str,tuoi,';');
        getline(str,luong,';');
        getline(str,glv,';');
        }
        timmk.close();
        }

        if (pass==mktk){
                dem=1;
            }

        timmk.close();
        if (dem==1){
            system("cls");
            cout<<"\t\t\t\t CHUC MUNG BAN DA TIM RA TAI KHOAN CUA MINH: \n";
            cout<<"\t\t\t\t TENNGUOIDUNG: "<<user<<"\n\t\t\t\t MATKHAU: "<<pass<<"\n\t\t\t\t Ten"<<ten;
            cin.get();
            cin.get();

        }
        else
        {   system("cls");
            cout <<"\t\t\t\t KHONG TIM THAY TAI KHOAN \n\t\t\t\t VUI LONG LIEN HE VA THU LAI: ";
            cin.get();
            cin.get();

        }
       break;
        }
        case 3:
            {
                return;
            }

 }
 }
