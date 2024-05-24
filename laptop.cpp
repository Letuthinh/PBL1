#include "laptop.h"

Laptop::Laptop(string malaptop, string hang, string ten,long gia,int soluong, int namsanxuat){
    this->malaptop=malaptop;
    this->ten=ten;
    this->hang=hang;
    this->gia=gia;
    this->soluong=soluong;
    this->namsanxuat=namsanxuat;
}
        void Laptop::setMalaptop(string malaptop){
			this->malaptop=malaptop;
		}
		void Laptop::setTen(string ten){
			this->ten=ten;
		}
		void Laptop::setHang(string hang){
	    	this->hang=hang;
		}
		void Laptop::setGia(long gia){
            this->gia=gia;
		}
		void Laptop::setSoluong(int soluong){
			this->soluong=soluong;
		}
		void Laptop::setNamsanxuat(int namsanxuat){
			this->namsanxuat=namsanxuat;
		}
        string Laptop::getMaLaptop() const { return malaptop; }
        string Laptop::getHang() const { return hang; }
        string Laptop::getTen() const { return ten; }
        long Laptop::getGia()const{return gia;}
        int Laptop::getSoLuong() const { return soluong; }
        int Laptop::getNamSanXuat() const { return namsanxuat; }
vector <Laptop> Laptop::docdulieu(){
        vector<Laptop> dslaptop;
        ifstream inputFile("Input/kholaptop.txt");
        if(inputFile.is_open()){
            string dong,tieude;
			getline(inputFile,tieude);
			while (getline(inputFile,dong)){
			stringstream ss(dong);
			string ma,hang,ten,gia,sl,nsx;
			getline(ss,ma,';');
			getline(ss,hang,';');
			getline(ss,ten,';');
			getline(ss,gia,';');
			getline(ss,sl,';');
			getline(ss,nsx,';');
			dslaptop.push_back(Laptop(ma,hang,ten,stol(gia),stoi(sl),stoi(nsx)));
        }
		inputFile.close();
	}
	return dslaptop;
}
void Laptop::hienThiDanhSach(const vector<Laptop>& dslaptop) {
    printf("+---+---------+---------+---------------------------------------------------+---------+----------+---------------+\n");
	 cout<<setw(4)<<"STT"<<"|"<< setw(9)<<left <<"MaLaptop"<<"|"
	 <<setw(9)<<left<<"Hang"<<"|"
	 <<setw(51)<<left<<"Ten"<<"|"
	 <<setw(9)<<"Gia" << "|"
	 <<setw(10)<<left<<"SoLuong" << "|"
	 <<setw(15)<<left<<"NamSanXuat" << "|\n";
	printf("+---+---------+---------+---------------------------------------------------+---------+----------+---------------+\n");
    for (int i=0;i<dslaptop.size();i++) {
        cout<<setw(4)<< i+1 <<"|"<< setw(9)<<left <<dslaptop[i].getMaLaptop()<<"|"
        <<setw(9)<<left<<dslaptop[i].getHang()<<"|"
        <<setw(51)<<left<< dslaptop[i].getTen()<<"|"
        <<setw(9)<<dslaptop[i].getGia() <<left << "|"
        <<setw(10)<<left<<dslaptop[i].getSoLuong() << "|"
        <<setw(15)<<left<<dslaptop[i].getNamSanXuat() << "|\n";
    }
    printf("+---+---------+---------+---------------------------------------------------+---------+----------+---------------+\n");
}
void Laptop::writeData(const vector<Laptop>& dslaptop,const string& filename) {
    ofstream outputFile(filename);
    if (outputFile.is_open()) {
        outputFile << "Ma;Hang;Tenlaptop;Gia;SoLuong;Namsanxuat" << endl;
         for (int i=0;i<dslaptop.size();i++) {
            outputFile << dslaptop[i].getMaLaptop() << ";" << dslaptop[i].getHang() << ";"
                       << dslaptop[i].getTen() << ";" << dslaptop[i].getGia() << ";"
                       << dslaptop[i].getSoLuong() << ";" << dslaptop[i].getNamSanXuat() << endl;
        }
        outputFile.close();
    }
}

void Laptop::nhapmoiLaptop(vector<Laptop>&dslaptop){
    int choice;
    cout <<"Ban can nhap bao nhieu loai laptop:";
    cin>>choice;
    for(int i=0;i<choice;i++){
    Laptop l;
    l.nhapthongtinLaptop();
    dslaptop.push_back(l);
    l.phieunhapkho(i);
    }
}

void Laptop::nhapthongtinLaptop() {
        cin.ignore();
        cout << "Nhap ma laptop: "; getline(cin,malaptop);
        cout << "Nhap hang laptop: ";getline(cin,hang);
        cout << "Nhap ten laptop: "; getline(cin,ten);
        cout << "Nhap gia laptop: "; cin >> gia;
        cout << "Nhap so luong laptop: ";cin >> soluong;
        cout << "Nhap nam san xuat: "; cin >> namsanxuat;

}
void Laptop::phieunhapkho(int& choice){
        int i=choice;
        time_t tim= time(0);
        tm *gottime = localtime(&tim);
        cout <<"\t----------------------------------------------"<<endl;

        cout <<"\t\t\t Phieu Nhap Kho:"<<i+1<<endl;
        cout <<"\t  MaLapTop:"<<malaptop<<endl;
        cout <<"\t  Hang:"<<hang<<endl;
        cout <<"\t  Ten:"<<ten<<endl;
        cout <<"\t  Gia:"<<gia<<endl;
        cout <<"\t  So luong:"<<soluong<<endl;
        cout <<"\t  Nam san xuat:"<<namsanxuat<<endl;
        cout <<"\t  Ngaythuchien:"<<gottime->tm_mday<<"/"<<1+gottime->tm_mon<<"/"<<1900+gottime->tm_year<<endl;
        cout <<"\t----------------------------------------------"<<endl;


        ofstream out("Input/PhieuXuatNhapKho.txt",ios::app);

        out << "NhapKho " << malaptop << " " << hang
         << " "<< ten << " " <<gia
         << " "<< soluong<< " " <<namsanxuat<<" "<<gottime->tm_mday<<"/"
         <<1+gottime->tm_mon<<"/"<<1900+gottime->tm_year<<endl;
        cout <<"Nhap laptop moi thanh cong: "<<endl;

}
void Laptop::chinhSuaLaptop(vector<Laptop>& dslaptop){
      chon2:
      string ma;

      cout <<"Nhap ma so laptop can chinh sua: "<<endl;
      cin.ignore();
      getline(cin,ma);
    bool found=false;
    for (int i=0;i<dslaptop.size();i++){
      if(strcmp(ma.c_str(),dslaptop[i].getMaLaptop().c_str())==0){
           dslaptop[i].nhapthongtinLaptop();

        cout<<"Da cap nhat thong tin laptop"<<endl;
        found =true;
        break;
    }
    }
    if (!found){
        cout <<"Khong tim thay laptop co ma so "<< ma<<endl;

         goto chon2;
    }
}

void Laptop::xuatlaptop(vector<Laptop>& dslaptop){
    chon7:
    int luachon;
    cout <<"\t\t\t\t 1. Xoa laptop khoi kho: "<<endl;
    cout <<"\t\t\t\t 2. Xuatkho : "<<endl;
    cout <<"\t\t\t\t 3. Trolai : "<<endl;
    cout <<"\t\t\t\t Nhap lua chon cua ban: ";
    cin >> luachon;

    if(luachon==1){

    string ma;
    cout <<"Nhap ma so laptop can xoa: "<<endl;
    cin.ignore();
    getline(cin,ma);
    bool found =false;
    for (int i=0;i<dslaptop.size();i++){
    if(dslaptop[i].getMaLaptop()==ma){
            dslaptop.erase(dslaptop.begin()+i);
            cout << "Da xoa thanh cong"<<endl;
            found =true;

    }}
    if(!found){
        cout<<"Khong tim thay vi tri can xoa: "<<endl;
         luachon=0;
         goto chon7;
    }

    }
  else if(luachon==2){
    cout <<"Ban can xuat kho bao nhieu loai:";
    int choice;
    cin >>choice;
    for(int i=0;i<choice;i++){
    cout<<"Nhap ma laptop ma ban muon xuat:";
	string ma;
	int sl;
	cin>> ma;
	cout<<"\nNhap so luong muon xuat:";
	cin>> sl;
	bool found =false;
	int vt=0;
	for(int i=0; i<dslaptop.size(); i++){
		if(dslaptop[i].getMaLaptop() == ma){
			if(sl == dslaptop[i].getSoLuong()){
				dslaptop.erase(dslaptop.begin()+i);
				found = true;
				vt=i;

			}else{
				int m=dslaptop[i].soluong- sl;
                dslaptop[i].setSoluong(m);
                found = true;
                vt=i;
            }
		}
}

     time_t tim= time(0);
        tm *gottime = localtime(&tim);

    if(vt!=0){
        cout <<"\t----------------------------------------------"<<endl;
        cout <<"\t\t\t\tPhieu Xuat Kho"<<i+1<<endl;
        cout <<"\tMaLapTop:"<<dslaptop[vt].getMaLaptop()<<endl;
        cout <<"\tHang:"<<dslaptop[vt].getHang()<<endl;
        cout <<"\tTen:"<<dslaptop[vt].getTen()<<endl;
        cout <<"\tGia:"<<dslaptop[vt].getGia()<<endl;
        cout <<"\tSo luong:"<< sl<<endl;
        cout <<"\tNam san xuat: "<<dslaptop[vt].getNamSanXuat()<<endl;
        cout <<"\tNgaythuchien:"<<gottime->tm_mday<<"/"<<1+gottime->tm_mon<<"/"<<1900+gottime->tm_year<<endl;
        cout <<"\t----------------------------------------------"<<endl;
        ofstream out("Input/PhieuXuatNhapKho.txt",ios::app);

        out << "XuatKho " << dslaptop[vt].getMaLaptop() << " " << dslaptop[vt].getHang()
         << " "<< dslaptop[vt].getTen() << " " << dslaptop[vt].getGia()
         << " "<< sl << " " << dslaptop[vt].getNamSanXuat()<<" "<<gottime->tm_mday<<"/"
         <<1+gottime->tm_mon<<"/"<<1900+gottime->tm_year<<endl;
    }
  if(!found){
    		cout<<"Ma laptop khong hop le";
            luachon=0;
            goto chon7;
    }
 }
  }

  else if (luachon==3){
        return;
  }
  else{
        cout <<"Gia tri khong hop le: "<<endl;
        goto chon7;




}
luachon=0;
}
void Laptop::sapXepTheoGia(vector<Laptop>& dslaptop){
    chon8:
    int n=dslaptop.size();
    int a;
    cout <<"\t\t\t\t1.Tangdan"<<endl;
    cout <<"\t\t\t\t2.Giamdan"<<endl;
    cout <<"\t\t\t\t3.Trolai"<<endl;
    cout<<"\t\t\t\tNhap lua chon cua ban: "<<endl;
    cin>>a;

    if(a==1){
    for(int i=0;i<n-1;i++){
       for(int j=i+1;j<n;j++){
            if(dslaptop[i].getGia()> dslaptop[j].getGia()){
                string tempMa=dslaptop[i].getMaLaptop();
                string tempHang=dslaptop[i].getHang();
                string tempTen=dslaptop[i].getTen();
                long tempGia=dslaptop[i].getGia();
                int tempSoLuong=dslaptop[i].getSoLuong();
                int tempNamsanxuat=dslaptop[i].getNamSanXuat();

                dslaptop[i].setMalaptop(dslaptop[j].getMaLaptop());
                dslaptop[i].setHang(dslaptop[j].getHang());
                dslaptop[i].setTen(dslaptop[j]. getTen());
                dslaptop[i].setGia(dslaptop[j].getGia());
                dslaptop[i].setSoluong(dslaptop[j].getSoLuong());
                dslaptop[i].setNamsanxuat(dslaptop[j].getNamSanXuat());

                dslaptop[j].setMalaptop(tempMa);
                dslaptop[j].setHang(tempHang);
                dslaptop[j].setTen(tempTen);
                dslaptop[j].setGia(tempGia);
                dslaptop[j].setSoluong(tempSoLuong);
                dslaptop[j].setNamsanxuat(tempNamsanxuat);
        }
}

}

    printf("+---+---------+---------+---------------------------------------------------+---------+----------+---------------+\n");
	 cout<<setw(4)<<"STT"<<"|"<< setw(9)<<left <<"MaLaptop"<<"|"
	 <<setw(9)<<left<<"Hang"<<"|"
	 <<setw(51)<<left<<"Ten"<<"|"
	 <<setw(9)<<"Gia" << "|"
	 <<setw(10)<<left<<"SoLuong" << "|"
	 <<setw(15)<<left<<"NamSanXuat" << "|\n";
	printf("+---+---------+---------+---------------------------------------------------+---------+----------+---------------+\n");
    for (int i=0;i<n;i++) {
        cout<<setw(4)<< i+1 <<"|"<< setw(9)<<left <<dslaptop[i].getMaLaptop()<<"|"
        <<setw(9)<<left<<dslaptop[i].getHang()<<"|"
        <<setw(51)<<left<< dslaptop[i].getTen()<<"|"
        <<setw(9)<<dslaptop[i].getGia() <<left << "|"
        <<setw(10)<<left<<dslaptop[i].getSoLuong() << "|"
        <<setw(15)<<left<<dslaptop[i].getNamSanXuat() << "|\n";

}
    printf("+---+---------+---------+---------------------------------------------------+---------+----------+---------------+\n");
    }
 else if(a==2){
     for(int i=0;i<n-1;i++){
       for(int j=i+1;j<n;j++){
            if(dslaptop[i].getGia()< dslaptop[j].getGia()){
                string tempMa=dslaptop[i].getMaLaptop();
                string tempHang=dslaptop[i].getHang();
                string tempTen=dslaptop[i].getTen();
                long tempGia=dslaptop[i].getGia();
                int tempSoLuong=dslaptop[i].getSoLuong();
                int tempNamsanxuat=dslaptop[i].getNamSanXuat();

                dslaptop[i].setMalaptop(dslaptop[j].getMaLaptop());
                dslaptop[i].setHang(dslaptop[j].getHang());
                dslaptop[i].setTen(dslaptop[j]. getTen());
                dslaptop[i].setGia(dslaptop[j].getGia());
                dslaptop[i].setSoluong(dslaptop[j].getSoLuong());
                dslaptop[i].setNamsanxuat(dslaptop[j].getNamSanXuat());

                dslaptop[j].setMalaptop(tempMa);
                dslaptop[j].setHang(tempHang);
                dslaptop[j].setTen(tempTen);
                dslaptop[j].setGia(tempGia);
                dslaptop[j].setSoluong(tempSoLuong);
                dslaptop[j].setNamsanxuat(tempNamsanxuat);
        }
}

}

    printf("+---+---------+---------+---------------------------------------------------+---------+----------+---------------+\n");
	 cout<<setw(4)<<"STT"<<"|"<< setw(9)<<left <<"MaLaptop"<<"|"<<setw(9)<<left<<"Hang"<<"|"<<setw(51)<<left<<"Ten"<<"|"<<setw(9)<<"Gia" << "|"<<setw(10)<<left<<"SoLuong" << "|"<<setw(15)<<left<<"NamSanXuat" << "|\n";
	printf("+---+---------+---------+---------------------------------------------------+---------+----------+---------------+\n");
    for (int i=0;i<n;i++) {
        cout<<setw(4)<< i+1 <<"|"<< setw(9)<<left <<dslaptop[i].getMaLaptop()<<"|"<<setw(9)<<left<<dslaptop[i].getHang()<<"|"<<setw(51)<<left<< dslaptop[i].getTen()<<"|"<<setw(9)<<dslaptop[i].getGia() <<left << "|"<<setw(10)<<left<<dslaptop[i].getSoLuong() << "|"<<setw(15)<<left<<dslaptop[i].getNamSanXuat() << "|\n";

}
    printf("+---+---------+---------+---------------------------------------------------+---------+----------+---------------+\n");
 }
 else if(a==3){
        return;
    }

    else
        {
            cout<<"Gia tri khong hop le.Vui long nhap lai: \n";
            goto chon8;
        }
    a=0;

}




void Laptop::timkiem(vector<Laptop>& dslaptop){
     chon9:
      int c;
      cout <<"\t\t\t\t1.Tim kiem theo ma:"<<endl;
      cout <<"\t\t\t\t2.Tim kiem theo hang:"<<endl;
      cout <<"\t\t\t\t3.Trolai:"<<endl;
      cout <<"\t\t\t\tNhap lua chon cua ban: ";
      cin >>c;
      if(c==1){
      string ma;
      cout <<"\t\t\t\tNhap ma laptop can tim kiem: ";
      cin.ignore();
      getline(cin,ma);
      bool found=false;
    for (int i=0;i<dslaptop.size();i++){
      if(dslaptop[i].getMaLaptop()==ma){
        cout<<"Da tim thay laptop"<<ma<<" "<<i+1<<endl;
        cout<<setw(4)<< i+1 <<"|"<< setw(9)<<left <<dslaptop[i].getMaLaptop()<<"|"<<setw(9)<<left<<dslaptop[i].getHang()<<"|"<<setw(51)<<left<< dslaptop[i].getTen()<<"|"<<setw(9)<<dslaptop[i].getGia() <<left << "|"<<setw(10)<<left<<dslaptop[i].getSoLuong() << "|"<<setw(15)<<left<<dslaptop[i].getNamSanXuat() << "|\n";
        found =true;

    }
    }
    if (!found){
        cout <<"Khong tim thay laptop co ma so "<< ma<<endl;
        c=0;
        goto chon9;

    }
}
    else if(c==2){
      string hang;
      cout <<"\t\t\t\tNhap Hang laptop can tim kiem: ";
      cin.ignore();
      getline(cin,hang);
      bool found=false;
    for (int i=0;i<dslaptop.size();i++){
      if(dslaptop[i].getHang()==hang){
        cout<<"Da tim thay laptop"<<hang<<" "<<i+1<<endl;
        cout<<setw(4)<< i+1 <<"|"<< setw(9)<<left <<dslaptop[i].getMaLaptop()<<"|"<<setw(9)<<left<<dslaptop[i].getHang()<<"|"<<setw(51)<<left<< dslaptop[i].getTen()<<"|"<<setw(9)<<dslaptop[i].getGia() <<left << "|"<<setw(10)<<left<<dslaptop[i].getSoLuong() << "|"<<setw(15)<<left<<dslaptop[i].getNamSanXuat() << "|\n";
        found =true;
    }
    }
    if (!found){
        cout <<"Khong tim thay hang laptop "<< hang<<endl;
        c=0;
        goto chon9;
    }
}
    else if (c==3) {
        return;
    }
    else{
        cout<<"Gia tri khong hop le vui long nhap lai \n";
        goto chon9;
    }
}

void Laptop:: Nhatkyxuatnhap(){
    ifstream inFile("Input/PhieuXuatNhapKho.txt");
    string header,line;
    if(inFile.is_open()){
    getline(inFile,header);
    while(getline(inFile,line)){
            cout << line <<endl;
    }
}
    inFile.close();
}
