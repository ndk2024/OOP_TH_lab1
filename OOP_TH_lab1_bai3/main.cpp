#include <iostream>
// Bài 3
using namespace std;
int UCLN (int a, int b) // Hàm tính ước chung lớn nhất
{
    a=abs(a); b=abs(b);
    while(b != 0)
    {
      int r = a % b;
      a = b;
      b = r;
   }
   return a;
}
struct PhanSo
{
    int tu, mau;
};
void nhap(PhanSo &a) // Hàm nhập phân số
{
    cout<<"Hay nhap tu va mau: ";
    cin>>a.tu>>a.mau;
    if(a.mau==0)
    {
        cout<<"Error, ";
        nhap(a);
    }
}
void RutGon(PhanSo &a) // Hàm rút gọn phân số
{
    if(a.mau<0)
    {
        a.mau=a.mau*-1;
        a.tu=a.tu*-1;
    }
    int k=UCLN(a.tu, a.mau);
    a.tu=a.tu/k;
    a.mau=a.mau/k;
}

PhanSo operator - (PhanSo a, PhanSo b)// Hàm trừ hai phân số
{
    PhanSo c;
    c.tu=a.tu*b.mau - b.tu*a.mau;
    c.mau=a.mau*b.mau;
    return c;
}
PhanSo operator + (PhanSo a, PhanSo b) // Hàm cộng hai phân số
{
    PhanSo c;
    c.tu=a.tu*b.mau + b.tu*a.mau;
    c.mau=a.mau*b.mau;
    return c;
}
PhanSo operator * (PhanSo a, PhanSo b) // Hàm nhân hai phân số
{
    PhanSo c;
    c.tu=a.tu*b.tu;
    c.mau=a.mau*b.mau;
    return c;
}
PhanSo operator / (PhanSo a, PhanSo b) // Hàm chia hai phân số
{
    PhanSo c;
    c.tu=a.tu*b.mau;
    c.mau=a.mau*b.tu;
    return c;
}

void xuat(PhanSo a)
{
    if(a.mau==1)
        cout<<a.tu<<endl;
    else
    cout<<a.tu<<"/"<<a.mau<<endl;
}
int main()
{
    PhanSo a,b;
    nhap(a);
    nhap(b);
    RutGon(a);
    RutGon(b);

    PhanSo Tong = a+b;
    PhanSo Hieu =a-b;
    PhanSo Tich=a*b;

    RutGon(Tong);
    RutGon(Hieu);
    RutGon(Tich);

    cout<<"Tong hai phan so: ";
    xuat(Tong);
    cout<<"Hieu hai phan so: ";
    xuat(Hieu);
    cout<<"Tich hai phan so: ";
    xuat(Tich);
    if(b.tu==0)
    {
        cout<<"Khong the chia duoc!";
    }
    else
    {
        PhanSo Thuong= a/b;
        RutGon(Thuong);
        cout<<"Thuong hai phan so: ";
        xuat(Thuong);
    }

    return 0;
}
