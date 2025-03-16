#include <iostream>
#include <bits/stdc++.h>
#include <regex>
//Bài 6_thứ 2
using namespace std;

struct SinhVien
{
    string hoten;
    double toan,van,anh;
    double gpa;
    string phanLoai;
    bool timkiem;
};
bool kiemTraHoTen(const string& hoTen)// Hàm kiểm tra định dạng tên
{
    if(hoTen.length()>30) return false;
    if(hoTen.empty()) return false;
    regex pattern("^[a-zA-Z\\s]+$");
    return regex_match(hoTen, pattern);
}

void nhaphoten(string &a)// Hàm nhập họ tên
{
    cout<<"Hay nhap ten: ";
    cin>>ws;
    getline(cin, a);
    if(kiemTraHoTen(a) == false)
    {
        cout<<"Nhap sai ten: ";
        nhaphoten(a);
    }
}
void nhapdiem (double &a, double &b, double &c)// Hàm nhập điểm
{
    cout<<"Hay nhap diem: ";
    cin>>a>>b>>c;
    if((10<a || a<0)||(10<b || b<0)||(10<c || c<0))
    {
        cout<<"Nhap sai"<<endl;
        nhapdiem(a,b,c);
    }
}
void  nhap(SinhVien &a)// Hàm nhập từng Sinh Viên
{
    nhaphoten(a.hoten);
    nhapdiem(a.toan, a.van, a.anh);
}
void nhapdanhsach(SinhVien a[], int n)//Hàm nhập danh sách
{
    for(int i=0; i<n; i++)
    {
        nhap(a[i]);
    }
}
void xuat(SinhVien a) // Hàm xuất từng Sinh Viên
{
    cout<<a.hoten<<endl;
    cout<<"GPA: "<<a.gpa<<endl;
    cout<<"Phan loai: "<<a.phanLoai<<endl;
}
double gpa(SinhVien a)// Hàm tính điểm trung bình
{
    double diem=(a.toan*2+a.van+a.anh)/4;
    return diem;
}
void xuatdanhsach(SinhVien a[], int n)// Hàm xuất danh sách
{
    for(int i=0; i<n; i++)
        xuat(a[i]);
}
bool checkChuoicon(string cha, string con)//So sánh hai chuỗi tên
{
    return cha.find(con) != string::npos;
}

void TimTheoTen( SinhVien a[], int n, string &check)// Hàm tìm kiếm theo tên
{

    for(char &x: check)
        x=tolower(x);
    for(int i=0; i<n; i++)
    {
        string sosanh=a[i].hoten;
        for(char &x: sosanh)
            x=tolower(x);
        a[i].timkiem = checkChuoicon(sosanh, check);
    }
}
int main()
{
    cout<<"Nhap so luong sinh vien: ";
    int n;
    cin>>n;
    SinhVien *danhsach= new SinhVien[n];
    nhapdanhsach(danhsach,n);
    double maxGPA= 0, minToan=danhsach[0].toan;

    //Yêu cầu 3 - Phân loại học sinh dựa trên điểm trung bình
    for(int i=0; i<n; i++)
    {
        danhsach[i].gpa=gpa(danhsach[i]);

        if(danhsach[i].gpa>=9)
            danhsach[i].phanLoai ="Xuat Sac";
        else if(danhsach[i].gpa>=8)
            danhsach[i].phanLoai ="Gioi";
        else if(danhsach[i].gpa>=6.5)
            danhsach[i].phanLoai ="Kha";
        else if(danhsach[i].gpa>=5)
            danhsach[i].phanLoai ="Trung Binh";
        else
            danhsach[i].phanLoai ="Yeu";
    }

    //Yêu cầu 4 - Tìm kiếm và xuất thông tin của học sinh có điểm trung bình cao nhất.
    xuatdanhsach(danhsach,n);
    for(int i=0; i<n; i++)
    {
        if(danhsach[i].gpa>maxGPA)
            maxGPA= danhsach[i].gpa;
        if(danhsach[i].toan<minToan)
            minToan=danhsach[i].toan;
    }

    for(int i=0; i<n; i++)
    {
        if(danhsach[i].gpa==maxGPA)
        {
            cout<<"Sinh vien co GPA cao nhat: ";
            xuat(danhsach[i]);
        }
    }

    //Yêu cầu 5 - Tìm kiếm học sinh theo tên (cho phép tìm kiếm với từ khóa không phân biệthoa thường và không cần nhập tên đầy đủ).
    string timkiem;
    cout<<"Hay nhap ten can tim: ";
    cin.ignore();
    getline(cin,timkiem);
    TimTheoTen(danhsach,n,timkiem);
    for(int i=0; i<n; i++)
    {
        if(danhsach[i].timkiem==true)
        {
            cout<<"Sinh vien tim thay: ";
            xuat(danhsach[i]);
        }
    }

    //Yêu cầu 6 - Danh sách học sinh có điểm toán thấp nhất
    for(int i=0; i<n; i++)
    {
        if(danhsach[i].toan==minToan)
        {
            cout<<"Sinh vien co diem Toan thap nhat: ";
            xuat(danhsach[i]);
            break;
        }
    }
    delete []danhsach;
    return 0;
}
