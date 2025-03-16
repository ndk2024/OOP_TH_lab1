#include <iostream>
#include <bits/stdc++.h>

//Bài 7
using namespace std;
struct times
{
    int gio, phut;
};
struct datetime
{
    int ngay, thang,nam;
};
struct ThongTin // Thông tin chuyến bay
{
    string mabay;
    datetime ngaybay;
    times giobay;
    string noidi;
    string noiden;
};
bool check_mabay(string a)//Kiểm tra mã bay
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
void nhap_mabay(string &a)// Nhập mã bay
{
    cout<<"Nhap ma bay: ";
    cin >> ws;
    getline(cin, a);
    if(check_mabay(a)==false)
    {
        cout<<"Nhap Sai. ";
        nhap_mabay(a);
    }
}

bool check_day(datetime ngay)//Kiểm tra ngày có hợp lệ
{
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
void nhap_ngaybay(datetime &a)//Nhập ngày bay
{
    cout<<"Nhap ngay bay: ";
    cin>>a.ngay>>a.thang>>a.nam;
    if(check_day(a) == false)
    {
        cout<<"Nhap Sai. ";
        nhap_ngaybay(a);
    }
}

bool check_giobay(times a)//Kiểm tra giờ có hợp lệ
{
    if(a.gio<0 || a.phut<0||a.gio>24||a.phut>59) return false;
    return true;

}
void nhap_giobay(times &a)//Nhập giờ bay
{
    cout<<"Nhap gio bay: ";
    cin>>a.gio>>a.phut;
    if(check_giobay(a)==false)
    {
        cout<<"Nhap Sai. ";
        nhap_giobay(a);
    }
}

bool check_ten(string a)//Kiểm tra tên có hợp lệ
{
    if(a.length()>20) return false;
    if(a.empty()) return false;
    regex pattern("^[a-zA-Z\\s]+$");
    return regex_match(a, pattern);
}
void nhap_di(string &a)//Hàm nhập nơi đi
{
    cout<<"Nhap noi di: ";
    cin >> ws;
    getline(cin,a);
    if(check_ten(a)==false)
    {
        cout<<"Nhap Sai. ";
        nhap_di(a);
    }
}
void nhap_den(string &a)// Hàm nhập nơi đến
{
    cout<<"Nhap noi den: ";
    cin >> ws;
    getline(cin,a);
    if(check_ten(a)==false)
    {
        cout<<"Nhap Sai. ";
        nhap_den(a);
    }
}
void nhap(ThongTin &a)// Hàm nhập thông tin mỗi chuyến bay
{
    nhap_mabay(a.mabay);
    nhap_ngaybay(a.ngaybay);
    nhap_giobay(a.giobay);
    nhap_di(a.noidi);
    nhap_den(a.noiden);
}
void nhapdanhsach(ThongTin a[], int n)// Hàm nhập danh sách
{
    for(int i=0; i<n; i++)
    {
        nhap(a[i]);
    }
}

void xuat(ThongTin a)// Hàm xuất thông tin mỗi chuyến bay
{
    cout<<endl;
    cout<<a.mabay<<endl;
    cout<<a.ngaybay.ngay<<"/"<<a.ngaybay.thang<<"/"<<a.ngaybay.nam<<endl;
    cout<<a.giobay.gio<<":"<<a.giobay.phut<<endl;
    cout<<a.noidi<<endl;
    cout<<a.noiden<<endl;
    cout<<endl;
}
void xuatdanhsach(ThongTin a[], int n)// Hàm xuất danh sách
{
    for(int i=0; i<n; i++)
    {
        xuat(a[i]);
    }
}

//Ý thứ 2.1 - Tìm kiếm chuyến bay theo mã bay, nơi đi hoặc đến
void nhapcantim(string &cantim)
{
    cout<<"Nhap ma bay, noi di hoac noi den can tim: ";
    cin >> ws;
    getline(cin,cantim);
    if(check_mabay(cantim) == false && check_ten(cantim)==false)
    {
        cout<<"Hay nhap lai: ";
        nhapcantim(cantim);
    }
}
bool checkCantim(string cantim, string sosanh)
{
    return cantim == sosanh;
}
void xuat_cantim(string cantim, ThongTin a[], int n)
{
    int index=0;
    for(int i=0; i<n; i++)
    {
        if(checkCantim(cantim, a[i].mabay) || checkCantim(cantim, a[i].noidi) || checkCantim(cantim, a[i].noiden))
        {
            xuat(a[i]);
            index=1;
        }
    }
    if(index==0) cout<<"Khong tim thay!"<<endl;
}

//Ý thứ 2.2 - sắp xếp danh sách chuyến bay theo thứ tự ngày và giờ
bool operator <(const datetime &a, const datetime &b)// Hàm < so sánh ngày(datetime)
{
    if (a.nam != b.nam) return a.nam < b.nam;
    if (a.thang != b.thang) return a.thang < b.thang;
    return a.ngay < b.ngay;
}

bool operator ==(const datetime &a, const datetime &b)//Hàm == so sánh ngày(datetime)
{
    return a.nam == b.nam && a.thang == b.thang && a.ngay == b.ngay;
}
bool operator <(const times &a, const times &b)// Hàm < so sánh giờ(times)
{
    if (a.gio != b.gio) return a.gio < b.gio;
    return a.phut < b.phut;
}

bool operator ==(const times &a, const times &b)//Hàm == so sánh giờ(times)
{
    return a.gio == b.gio && a.phut == b.phut;
}
bool operator <(const ThongTin &a, const ThongTin &b)// Hàm so sánh thời gian giữa của mỗi chuyến bay
{
    if (!(a.ngaybay == b.ngaybay)) return a.ngaybay < b.ngaybay;
    return a.giobay < b.giobay;
}
void Sort_danhsach(ThongTin a[], int n)// Hàm sắp xếp lại danh sách theo yêu cầu
{
    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            if(a[j]<a[i])
                swap(a[i],a[j]);
        }
    }
}

//Ý 3 - Hiển thị danh sách các chuyến bay theo ngày chỉ định với nơi đi cụ thể
void check_chi_dinh(datetime ngaycd, string noicd, ThongTin a[], int n)
{
    int index=0;
    for(int i=0; i<n; i++)
    {
        if(a[i].ngaybay==ngaycd && a[i].noidi==noicd)
        {
            index=1;
            xuat(a[i]);
        }
    }
    if(index==0)
        cout<<"Khong co chuyen bay! "<<endl;
}

//Ý 4 - Đếm số lượng chuyến bay từ nơi đi đến nơi đến theo chỉ đinh
int demSL_chuyenbay(ThongTin a[],int n,string noidi, string noiden)
{
    int dem=0;
    for(int i=0; i<n; i++)
    {
        if(a[i].noiden==noiden && a[i].noidi==noidi)
            dem+=1;
    }
    return dem;
}

int main()
{
    cout<<"Nhap so luong chuyen bay: ";
    int n;
    cin>>n;
    ThongTin *danhsach= new ThongTin[n];
    //Ý 1
    nhapdanhsach(danhsach,n);
    xuatdanhsach(danhsach,n);

    //Ý 2.1
    string cantim;
    nhapcantim(cantim);
    xuat_cantim(cantim, danhsach, n);

    //Ý 2.2
    Sort_danhsach(danhsach, n);
    cout<<"Danh sach sau khi sap xep"<<endl;
    xuatdanhsach(danhsach,n);

    //Ý 3
    cout<<"Nhap noi chi dinh va ngay chi dinh"<<endl;
    string noi_chi_dinh;
    datetime ngay_chi_dinh;
    nhap_di(noi_chi_dinh);
    nhap_ngaybay(ngay_chi_dinh);
    check_chi_dinh(ngay_chi_dinh,noi_chi_dinh,danhsach,n);

    //Ý 4
    string noidi,noiden;
    nhap_di(noidi);
    nhap_den(noiden);
    int k= demSL_chuyenbay(danhsach,n, noidi, noiden);
    cout<<"So luong chuyen bay duoc chi dinh: "<<k<<endl;
    delete[] danhsach;
    return 0;
}

