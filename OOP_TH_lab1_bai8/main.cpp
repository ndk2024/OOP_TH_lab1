#include <iostream>
#include <bits/stdc++.h>
//Bài 8
using namespace std;
struct Datetime
{
    int ngay, thang, nam;
};
struct sotietkiem
{
    string maSo;
    string loaiTK;
    string hoTen;
    string cmnd;
    Datetime ngayMoSo;
    double tienGui;
    double laiNam;

};
bool checkMS(string a) // Hàm kiểm tra mã sổ
{
    if(a.length()>5) return false;
    if(a.empty()) return false;
    for(char x: a)
    {
        if(!isalnum(static_cast<unsigned>(x)))
            return false;
    }
    return true;

}
void nhapMS(string &ms) // Hàm nhập mã sổ
{
    cout<<"Nhap ma so: ";
    getline(cin, ms);
    if(checkMS(ms)==false)
    {
        cout<<"Nhap sai, ";
        nhapMS(ms);
    }
}
bool checkLTK(string a) //Hàm kiểm tra loại tiết kiệm
{
    if(a.empty()) return false;
    if(a.length() > 10) return false;
    return true;
}
void nhaploaiTK(string &a) // Hàm nhập loại tiết kiệm
{
    cout<<"Nhap loai tiet kiem: ";
    getline(cin, a);
    if(checkLTK(a)==false)
    {
        cout<<"Nhap sai, ";
        nhaploaiTK(a);
    }
}
bool checkten (string a) // Hàm kiểm tra họ tên
{
    if(a.length()>30) return false;
    if(a.empty()) return false;
    regex pattern("^[a-zA-Z\\s]+$");
    return regex_match(a, pattern);
}
void nhaphoten(string &ten) //Hàm nhập họ tên
{
    cout<<"Nhap ho ten: ";
    getline(cin, ten);
    if(checkten(ten)==false || ten.length() > 30)
    {
        cout<<"Nhap sai, ";
        nhaphoten(ten);
    }
}
void nhaptienGui(double &tien) // Hàm nhập tiền gửi
{
    cout<<"Nhap so tien gui: ";
    cin>>tien;
    if(tien<0)
    {
        cout<<"Nhap sai, ";
        nhaptienGui(tien);
    }
}
bool checkCMND(string cmnd) // Hàm kiểm tra CMND
{
    if(cmnd.empty()) return false;
    if(cmnd.length() != 12) return false; // định dạng độ dài cmnd bắt buộc là 12 chữ số
    for(int i=0; i<cmnd.length(); i++)
    {
        if(!isdigit(static_cast<unsigned char>(cmnd[i])))
            return false;
    }
    return true;
}
void nhapCMND(string &cmnd) // Hàm nhập CMND
{
    cout<<"Nhap CMND: ";
    getline(cin, cmnd);
    if(checkCMND(cmnd)==false)
    {
        cout<<"Nhap sai: ";
        nhapCMND(cmnd);
    }
}
bool checkDay(Datetime ngay)// Hàm kiểm tra ngày mở sổ
{
    if(ngay.nam>2025) return false;
    if(ngay.nam==2025 && ngay.thang>3) return false;
    if(ngay.ngay<=0||ngay.ngay>31||ngay.thang>12||ngay.thang<=0||ngay.nam<=0)
        return false;
    switch (ngay.thang)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if(ngay.ngay>31)
                return false;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if(ngay.ngay>30)
                return false;
            break;
        case 2:
            if((ngay.nam%4==0 && ngay.nam%100!=0)||ngay.nam%400==0)
            {
                if(ngay.ngay>29)
                    return false;
            }
            else
            {
               if(ngay.ngay>28)
                    return false;
            }
            break;
    }
    return true;
}
void nhapDay(Datetime &ngay) // Hàm nhập ngày mở sổ
{
    cout<<"Nhap ngay: ";
    cin>>ngay.ngay>>ngay.thang>>ngay.nam;
    if(checkDay(ngay) == false)
    {
        cout<<"Nhap sai, ";
        nhapDay(ngay);
    }
}
void nhap(sotietkiem &a) // Hàm nhập thông tin một sổ tiết kiệm
{
    cin.ignore();
    nhapMS(a.maSo);
    nhaploaiTK(a.loaiTK);
    nhaphoten(a.hoTen);
    nhapCMND(a.cmnd);
    nhapDay(a.ngayMoSo);
    nhaptienGui(a.tienGui);
    cout<<"Nhap lai suat (%/nam): ";
    cin>>a.laiNam;
}
void nhapdanhsach(sotietkiem a[], int n) // Hàm nhập danh sách các sổ tiết kiệm
{
    for(int i=0; i<n; i++)
        nhap(a[i]);
}
void xuat(sotietkiem a) // Hàm xuất thông tin một sổ tiết kiệm
{
    cout<<endl;
    cout<<a.maSo<<endl<<a.loaiTK<<endl;
    cout<<a.hoTen<<endl<<a.cmnd<<endl;
    cout<<a.ngayMoSo.ngay<<"/"<<a.ngayMoSo.thang<<"/"<<a.ngayMoSo.nam<<endl;
    cout<<a.tienGui<<endl;
}

//Yêu cầu 3
void xuatdanhsach(sotietkiem a[], int n) // Hàm xuất danh sách sổ tiết kiệm
{
    for(int i=0;i<n; i++)
    {
        xuat(a[i]);
    }
}

void tinhLaiSuat(double &a, const int time) // Hàm tính lãi suất 1 tháng
{
    double k=a/12 * time;
    a=k;
}

//Yêu cầu 6.1
sotietkiem *dstienGuiGiam(sotietkiem a[], int n) // Sắp xếp danh sách theo số tiền gửi giảm dần
{
    sotietkiem *ds=new sotietkiem[n];
    for(int i=0; i<n ;i++)
    {
        ds[i]=a[i];
    }
    for(int i=0; i<n; i++) // Interchange Sort
    {
        for(int j=i; j<n; j++)
        {
            if(ds[i].tienGui<ds[j].tienGui)
            {
                swap(ds[i],ds[j]);
            }
        }

    }
    return ds;
}

//Yêu cầu 6.2
bool operator <(const Datetime &a, const Datetime &b)// Hàm < so sánh ngày(Datetime)
{
    if (a.nam != b.nam) return a.nam < b.nam;
    if (a.thang != b.thang) return a.thang < b.thang;
    return a.ngay < b.ngay;
}

bool operator ==(const Datetime &a, const Datetime &b)//Hàm == so sánh ngày(Datetime)
{
    return a.nam == b.nam && a.thang == b.thang && a.ngay == b.ngay;
}
bool operator <(const sotietkiem &a, const sotietkiem &b) {
    return a.ngayMoSo < b.ngayMoSo;
}

sotietkiem *dsngayMSTang(sotietkiem a[], int n) // Sắp xếp danh sách theo ngày mở sổ tăng dần
{
    sotietkiem *danhsach=new sotietkiem[n];
    for(int i=0; i<n; i++)
    {
        danhsach[i]=a[i];
    }
    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            if(danhsach[j]<danhsach[i])
                swap(danhsach[i],danhsach[j]);
        }
    }
    return danhsach;
}

//Yêu cầu 5.1 - Tìm kiếm thông tin khi nhập CMND hoạc mã sổ
void nhapcantim(string &cantim) {
    while (true) {
        cout << "Nhap CMND hoac ma so can tim: ";
        cin >> ws;
        getline(cin, cantim);

        // Kiểm tra hợp lệ
        if (checkCMND(cantim) || checkMS(cantim)) {
            // Hợp lệ thì thoát khỏi vòng lặp
            break;
        } else {
            // Không hợp lệ
            cout << "Du lieu khong hop le. Hay nhap lai.\n";
        }
    }
}
bool checkCanTim(string cantim, string sosanh) // Hàm so sánh hai string với nhau
{
    if(cantim!=sosanh) return false;
    return true;
}

//Yêu cầu 5.2 - Liệt ke tất cả sổ tiết kiệm được mở trong 1 tháng chỉ định
void check_thang_chi_dinh(sotietkiem a[], int n)
{
    cout<<"Nhap thang chi dinh:";
    int thangcd,counts=0;
    cin>>thangcd;
    for(int i=0; i<n; i++)
    {
        if(a[i].ngayMoSo.thang==thangcd)
        {
            counts+=1;
            xuat(a[i]);
        }
    }
    if(counts==0)
    {
        cout<<"Khong co du lieu thang do!"<<endl;
    }
}

//Yêu cầu 4 - Chức năng nâng cao
int tinhSoThangChenhLech(const Datetime &start, const Datetime &end) // Hàm tính số tháng chênh lệch lúc mới gửi so với thời điểm hiện tại
{
    int totalStart = start.nam * 12 + start.thang;
    int totalEnd   = end.nam   * 12 + end.thang;

    int diff = totalEnd - totalStart;

    if (end.ngay < start.ngay)
    {
        diff--;
    }
    return diff;
}
//Hàm tính lãi thực nhận được - Lẫn rút trước hạn hay rút sau hạn
void tinhLaiThucNhan(const sotietkiem &stk, const Datetime &ngayRut, double laiSuat,int thang_chenh_lech)
{
    int soThangGui = tinhSoThangChenhLech(stk.ngayMoSo, ngayRut);
    if (soThangGui < 0)
    {
        cout << "Error: Ngay rut truoc ngay mo so!\n";
    }
    else
    {
    double laiSuat_thang = laiSuat/12.0;

    // Kiểm tra có rút trước kỳ hạn hay không
    bool rutTruocHan = ( soThangGui >0 && soThangGui < thang_chenh_lech);

    if (rutTruocHan)
    {
        cout<<"Canh bao: Rut truoc han!"<<endl;
        // Tiền lãi = (số tiền gửi) * (lãi suất trước hạn theo tháng) * (số tháng gửi)
        double laiTruocHan = stk.tienGui * ((0.5/12) / 100.0) * soThangGui;
        cout<<"Lai truoc han: "<<laiTruocHan<<endl;
    }
    else
    {
        if (soThangGui <= 6) {
            // Lãi suất ngắn hạn
            double laiNganHan = stk.tienGui * (laiSuat_thang / 100.0) * soThangGui;
            cout<<"Lai suat ngan han: "<<laiNganHan<<endl;
        } else {
            // Lãi suất dài hạn
            double laiDaiHan = stk.tienGui * (laiSuat_thang / 100.0) * soThangGui;
            cout<<"Lai suat dai han: "<<laiDaiHan<<endl;
        }
    }
    }
}
int main()
{
    int n;
    cout<<"Nhap so luong danh sach: ";
    cin>>n;
    sotietkiem *a=new sotietkiem[n];
    nhapdanhsach(a,n);
    //Yêu cầu 3
    xuatdanhsach(a,n);

    //Yêu cầu 4
    Datetime hientai; // Chọn mốc thời gian ở hiện tại
    hientai.ngay=12;
    hientai.thang=3;
    hientai.nam=2025;
    for(int i=0; i<n; i++)
    {
        Datetime ngayRut;
        int thang_chenh_lech=tinhSoThangChenhLech(a[i].ngayMoSo, hientai);
        cout<<"Ngay rut tien:";
        nhapDay(ngayRut);
        tinhLaiThucNhan(a[i],ngayRut,a[i].laiNam, thang_chenh_lech);
    }
    //Yêu cầu 5.1
    string cantim;
    nhapcantim(cantim);
    int index_tim=-1;
    for(int i=0; i<n; i++)
    {
        if(checkCanTim(cantim,a[i].cmnd) || checkCanTim(cantim,a[i].maSo))
        {
            index_tim=i;
        }
    }
    for(int i=0; i<n; i++)
    {
        if(i==index_tim)
        {
            xuat(a[i]);
        }
    }
    if(index_tim==-1) cout<<"Khong tim thay"<<endl;

    //Yêu cầu 5.2
    check_thang_chi_dinh(a,n);

    //Yêu cầu 6 -  Sắp xếp danh sách
    sotietkiem *ds_tienGui=dstienGuiGiam(a,n);
    sotietkiem *ds_ngay=dsngayMSTang(a,n);
    cout<<"Danh sach sap xep theo tien gui:"<<endl;
    xuatdanhsach(ds_tienGui,n);
    cout<<"Danh sach sap xep theo thoi gian mo so:"<<endl;
    xuatdanhsach(ds_ngay,n);
    return 0;
}
