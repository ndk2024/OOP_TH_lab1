#include <iostream>
// Bài 1
using namespace std;
int UCLN (int a, int b) // Hàm tìm ước chung lớn nhất
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
void xuat(PhanSo a) // Hàm xuất phân số
{
    cout<<"Phan so rut gon la: ";
    if(a.mau==1)
        cout<<a.tu<<endl;
    else
    cout<<a.tu<<"/"<<a.mau<<endl;
}
int main()
{
    PhanSo a;
    nhap(a);
    RutGon(a);
    xuat(a);
    return 0;
}
