#include <iostream>
// Bài 2
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
PhanSo operator - (PhanSo a, PhanSo b) // Hàm trừ hai phân số
{
    PhanSo c;
    c.tu=a.tu*b.mau - b.tu*a.mau;
    c.mau=a.mau*b.mau;
    return c;
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
PhanSo maxx(PhanSo a, PhanSo b) // Hàm tìm lớn nhất trong hai phân số
{
    PhanSo Hieu = a-b; //Tính hiệu của phân số a và b
    RutGon(Hieu);
    if(Hieu.tu>=0 )
        return a;
    else
        return b;
}
void xuat(PhanSo a) // Hàm xuất phân số
{
    cout<<"Phan so lon hon la: ";
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
    PhanSo maxNum= maxx(a,b);
    xuat(maxNum);
    return 0;
}
