#include"nhanvien.h"



NhanVien::NhanVien(string user,string pass,string maNv,string ten,int tuoi,long luong,int giolamviec){
     this->user=user;
     this->pass=pass;
     this->maNv=maNv;
     this->ten=ten;
     this->tuoi=tuoi;
     this->luong=luong;
     this->giolamviec=giolamviec;
    }
    void NhanVien::SetUser(string user){this->user=user;};
    void NhanVien::setPass(string pass){this->pass=pass;};
    void NhanVien::setMaNv(string maNv){this->maNv=maNv;}
    void NhanVien::setTen(string ten){this->ten=ten;}
    void NhanVien::setTuoi(int tuoi){this->tuoi=tuoi;}
    void NhanVien::setLuong(long luong){this->luong=luong;}
    void NhanVien::setGioLamViec(int giolamviec){this->giolamviec=giolamviec;}
    string NhanVien::getUser() const {return user;}
    string NhanVien::getPass() const {return pass;}
    string NhanVien::getMaNv() const {return maNv;}
    string NhanVien::getTen() const {return ten;}
    int NhanVien::getTuoi() const {return tuoi;}
    long NhanVien::getLuong() const {return luong;}
    int NhanVien::getGioLamViec() const {return giolamviec;}

vector<NhanVien> NhanVien::docDanhSachNhanVien() {
    vector<NhanVien> danhSachNhanVien;
    ifstream inFile("dulieunhanvien.txt");
    if (inFile.is_open()) {
    string line,header;
    getline(inFile,header);
    while (getline(inFile,line)) {
        stringstream str(line);
        string user,pass,maNv, ten, tuoi, giolamviec, luong;
    	getline(str,user,';');
    	getline(str,pass,';');
    	getline(str,maNv,';');
		getline(str,ten,';');
        getline(str,tuoi,';');
        getline(str,luong,';');
        getline(str,giolamviec,';');
        danhSachNhanVien.push_back(NhanVien(user,pass,maNv,ten,stoi(tuoi),stol(luong),stoi(giolamviec)));
}
    inFile.close();
}
    return danhSachNhanVien;
}


void NhanVien::hienThiDanhSachNhanVien(const vector<NhanVien>& danhSachNhanVien) {
	system("cls");
    printf("+---+---------+---------+---------+---------------------------------------------------+---------+----------+-----------+\n");
    cout<<setw(4)<<"STT"<<"|"<< setw(9)<<left<<"User"<<"|"
    <<setw(9)<<left<<"Pass"<<"|"
    <<setw(9)<<left <<"MaNV"<<"|"
    <<setw(51)<<left<<"Ho Va Ten"<<"|"
    <<setw(9)<<left<<"Tuoi"<<"|"
    <<setw(9)<<"Luong" << "|"
    <<setw(10)<<left<<"Gio lam viec" << "|\n";
    printf("+---+---------+---------+---------+---------------------------------------------------+---------+----------+-----------+\n");
    for (int i=0;i<danhSachNhanVien.size();i++) {
        cout<<setw(4)<< i+1 <<"|"<<setw(9)<<left <<danhSachNhanVien[i].getUser()<<"|"
        <<setw(9)<<left <<danhSachNhanVien[i].getPass()<<"|"
        <<setw(9)<<left <<danhSachNhanVien[i].getMaNv()<<"|"
        <<setw(51)<<left<<danhSachNhanVien[i].getTen()<<"|"
        <<setw(9)<<left<< danhSachNhanVien[i].getTuoi()<<"|"
        <<setw(9)<<danhSachNhanVien[i].getLuong() <<left << "|"
        <<setw(12)<<left<<danhSachNhanVien[i].getGioLamViec() << "|\n";
    }
     printf("+---+---------+---------+---------+---------------------------------------------------+---------+----------+-----------+\n");
}



void NhanVien::themNhanVien(vector<NhanVien>&danhSachNhanVien){
    int choice;
    cout <<"Nhap so luong nhan vien can nhap thong tin moi:";
    cin>>choice;
    for(int i=0;i<choice;i++){
    NhanVien l;
    l.nhapthongtinNV();
    danhSachNhanVien.push_back(l);
 }
}

void NhanVien::nhapthongtinNV() {
        cin.ignore();
        cout << "\t\t\t\tNhap Ten nguoi dung:";getline(cin,user);
        cout << "\t\t\t\tNhap Matkhau:";getline(cin,pass);
        cout << "\t\t\t\tNhap ma NV: "; getline(cin,maNv);
        cout << "\t\t\t\tNhap Ten: ";getline(cin,ten);
        cout << "\t\t\t\tNhap Tuoi: "; cin>>tuoi;
        cout << "\t\t\t\tNhap Luong: "; cin >> luong;
        cout << "\t\t\t\tNhap Gio Lam Viec : ";cin >> giolamviec;

}

void NhanVien::suaNhanVien(vector<NhanVien>& danhSachNhanVien) {
      string ma;
      cout <<"Nhap ma NV can chinh sua: "<<endl;
      cin.ignore();
      cin>>ma;
    bool found=false;
    for (int i=0;i<danhSachNhanVien.size();i++){
      if(danhSachNhanVien[i].getMaNv()== ma){
           danhSachNhanVien[i].nhapthongtinNV();

        cout<<"Da cap nhat thong tin nhan vien"<<endl;
        found=true;
        break;
    }
    }
    if (!found){
        cout <<"Khong tim thay nhan vien co ma so "<< ma<<endl;
    }
}

void NhanVien::xoaNhanVien(vector<NhanVien>& danhSachNhanVien) {
      string ma;
      cout <<"Nhap ma NV can xoa: "<<endl;
      cin.ignore();
      cin>>ma;
    for (int i=0;i<danhSachNhanVien.size();i++) {
        if (danhSachNhanVien[i].getMaNv()==ma) {
            danhSachNhanVien.erase(danhSachNhanVien.begin()+1);
            cout << "Xoa nhan vien thanh cong!" << endl;
            return;
        }
    }
    cout << "Khong tim thay nhan vien co ma " << ma << endl;
}
void NhanVien::timkiemNhanVien(vector<NhanVien>& danhSachNhanVien){
      string ma;
      cout <<"\t\t\t\tNhap ma nhan vien can tim kiem: ";
      cin >> ma;
      bool found=false;
    for (int i=0;i<danhSachNhanVien.size();i++){
      if(danhSachNhanVien[i].getMaNv()==ma){
            cout<<setw(4)<< i+1 <<"|"<<setw(9)<<left <<danhSachNhanVien[i].getUser()<<"|"
            <<setw(9)<<left <<danhSachNhanVien[i].getPass()<<"|"
            <<setw(9)<<left <<danhSachNhanVien[i].getMaNv()<<"|"
            <<setw(51)<<left<<danhSachNhanVien[i].getTen()<<"|"
            <<setw(9)<<left<< danhSachNhanVien[i].getTuoi()<<"|"
            <<setw(9)<<danhSachNhanVien[i].getLuong() <<left << "|"
            <<setw(12)<<left<<danhSachNhanVien[i].getGioLamViec() << "|\n";
        found =true;
      }
      }
    if (!found){
        cout <<"Khong tim thay laptop co ma so "<< ma<<endl;
    }
}

void NhanVien::luudssv(const vector<NhanVien>& danhSachNhanVien, const string& tenTepTin) {
    ofstream file("dulieunhanvien.txt");
    if (!file.is_open()) {
        cout << "Khong the mo tep tin " << endl;
        return;
    }
    file << "MaNV;HovaTen;Tuoi;Luong;GioLamViec" << endl;
    for (const auto& nv : danhSachNhanVien) {
        file <<nv.getUser()<< ";"<<nv.getPass()<< ";"<< nv.getMaNv() << ";" << nv.getTen() << ";" << nv.getTuoi() << ";"<< nv.getGioLamViec() << ";" << nv.getLuong() << endl;
    }

    file.close();
    cout << "Luu danh sach nhan vien vao tep tin thanh cong!" << endl;
}




