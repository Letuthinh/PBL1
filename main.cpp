#include "login.cpp"

#include "Menu.cpp"

int main(){
    chon1:
    int choice;
     system("cls");
     system("color F0");
     SET_MAU(4);
     cout<<"\n\n\t\t\t\t *********************************************************** \n";
     SET_MAU(2);
     cout<<"\t\t\t\t\t    CHAO MUNG BAN DEN MAN HINH DANG NHAP \n";
     SET_MAU(4);
     cout<<"\t\t\t\t     ****************      MENU      ****************\n";
     SET_MAU(2);
        cout<<"\t\t\t\t 1.QUAN LI KHO "<<endl;
        cout<<"\t\t\t\t 2.QUAN LI NHANVIEN "<<endl; //Phan QUANLI co tk va mk co dinh la "admin"
        cout<<"\t\t\t\t 3.DANG KY (DANH CHO NHAN VIEN) "<<endl;
        cout<<"\t\t\t\t 4.QUEN PASSWORD (HOAC) USERNAME"<<endl;
        cout<<"\t\t\t\t 5.THOAT"<<endl;
        cout<<"\t\t\t\t NHAP LUA CHON CUA BAN :";
        cin>>choice;
        cout<<endl;
   switch(choice)
    {
        case 1:/*dang nhap vao muc quan li kho*/
            if(user()==1){
             Sleep(300);
             system("cls");
            if(menu1()==1){goto chon1;} 
            }
            else {goto chon1;}
            break;

        case 2:/*dang nhap vao muc quan li nhan vien*/
            if(admin()==1){
             Sleep(300);
             system("cls");
            if(menu2()==1){goto chon1;} 
            }
            else {goto chon1;}
            break;
        case 3:/*chuyen vao muc dang ky moi*/
            dangky(); 
            goto chon1;;
            break;
	    case 4:/*chuyen vao muc quen mat khau*/
            quen(); 
            goto chon1;
            break;
        case 5:/*ket thuc va thoat khoi chuong trinh*/
            cout <<"CAM ON BAN DA SU DUNG CHUONG TRINH:"<<endl;
            break;
        default:/*dua tro lai menu ban dau khi nhap gia tri ko hop le*/

            cout<<"GIA TRI BAN NHAP KHONG HOP LE. VUI LONG THU LAI =)"<<endl;

            system("pause");
            goto chon1;
            break;
    }
        return 0;
}
