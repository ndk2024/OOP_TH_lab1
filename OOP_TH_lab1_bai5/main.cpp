#include <bits/stdc++.h>
using namespace std;
//Bài 5

struct Ngay
{
    int ngay, thang, nam;
};
bool check_day(Ngay ngay) // Kiểm tra ngày hợp lệ
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
void NhapNgay(Ngay &n)// Nhập ngày, tháng, năm
{
    cout<<"Nhap ngay, thang, nam: ";
    cin>>n.ngay>>n.thang>>n.nam;
    if(check_day(n)==false)
    {
        cout<<"Nhap Sai. ";
        NhapNgay(n);
    }
}

bool laNamNhuan(int nam) // kiểm tra năm nhuận
{
    return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}

int soNgayTrongThang(int thang, int nam) // tính số ngày tối đa mỗi tháng
{
    switch (thang)
    {
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return laNamNhuan(nam) ? 29 : 28;
        default:
            return 31;
    }
}

Ngay NgayKeTiep(Ngay ngayHienTai)
{
    int ngayMax = soNgayTrongThang(ngayHienTai.thang, ngayHienTai.nam);

    if (ngayHienTai.ngay < ngayMax)
        ngayHienTai.ngay++;
    else if (ngayHienTai.thang < 12)
    {
        ngayHienTai.ngay = 1;
        ngayHienTai.thang++;
    }
    else
    {
        ngayHienTai.ngay = 1;
        ngayHienTai.thang = 1;
        ngayHienTai.nam++;
    }

    return ngayHienTai;
}


Ngay NgayTruoc(Ngay a) //Tính ngày trước đó
{
    Ngay b;
    if (a.ngay > 1)
    {
        b.ngay = a.ngay - 1;
        b.thang = a.thang;
        b.nam = a.nam;
    }
    else
    {
        if (a.thang == 1)
        {
            b.ngay = 31;
            b.thang = 12;
            b.nam = a.nam - 1;
        }
        else
        {
            b.thang = a.thang - 1;
            b.nam = a.nam;
            switch(b.thang)
            {
                case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                    b.ngay = 31;
                    break;
                case 4: case 6: case 9: case 11:
                    b.ngay = 30;
                    break;
                case 2:
                    if ((b.nam % 4 == 0 && b.nam % 100 != 0) || (b.nam % 400 == 0))
                        b.ngay = 29;
                    else
                        b.ngay = 28;
                    break;
            }
        }
    }
    return b;
}
int ThuTuNgay(Ngay b) // Tính thứ tự ngày trong năm
{
    int thutu;
    switch(b.thang)
    {
        case 1:
            thutu=b.ngay;break;
        case 2:
            thutu=b.ngay+31;break;
        case 3:
            if((b.nam%4==0 && b.nam%100!=0)|| b.nam%400==0)
                thutu=b.ngay+29+31;
            else
                thutu=b.ngay+28+31;
            break;
        case 4:
            if((b.nam%4==0 && b.nam%100!=0)|| b.nam%400==0)
                thutu=b.ngay+31+29+31;
            else
                thutu=b.ngay+31+28+31;
            break;
        case 5:
            if((b.nam%4==0 && b.nam%100!=0)|| b.nam%400==0)
                thutu=b.ngay+30+31+29+31;
            else
                thutu=b.ngay+30+31+28+31;
            break;
        case 6:
            if((b.nam%4==0 && b.nam%100!=0)|| b.nam%400==0)
                thutu=b.ngay+31+30+31+29+31;
            else
                thutu=b.ngay+31+30+31+28+31;
            break;
        case 7:
            if((b.nam%4==0 && b.nam%100!=0)|| b.nam%400==0)
                thutu=b.ngay+30+31+30+31+29+31;
            else
                thutu=b.ngay+30+31+30+31+28+31;
            break;
        case 8:
            if((b.nam%4==0 && b.nam%100!=0)|| b.nam%400==0)
                thutu=b.ngay+31+30+31+30+31+29+31;
            else
                thutu=b.ngay+31+30+31+30+31+28+31;
            break;
        case 9:
            if((b.nam%4==0 && b.nam%100!=0)|| b.nam%400==0)
                thutu=b.ngay+31+31+30+31+30+31+29+31;
            else
                thutu=b.ngay+31+31+30+31+30+31+28+31;
            break;
        case 10:
            if((b.nam%4==0 && b.nam%100!=0)|| b.nam%400==0)
                thutu=b.ngay+30+31+31+30+31+30+31+29+31;
            else
                thutu=b.ngay+30+31+31+30+31+30+31+28+31;
            break;
        case 11:
            if((b.nam%4==0 && b.nam%100!=0)|| b.nam%400==0)
                thutu=b.ngay+31+30+31+31+30+31+30+31+29+31;
            else
                thutu=b.ngay+31+30+31+31+30+31+30+31+28+31;
            break;
        case 12:
            if((b.nam%4==0 && b.nam%100!=0)|| b.nam%400==0)
                thutu=b.ngay+30+31+30+31+31+30+31+30+31+29+31;
            else
                thutu=b.ngay+30+31+30+31+31+30+31+30+31+28+31;
            break;
    }
    return thutu;
}
int main()
{
    Ngay ngay1, ngaykt;
    NhapNgay(ngay1);
    ngaykt=NgayKeTiep(ngay1);
    cout<<"Ngay tiep theo: "<<ngaykt.ngay<<"/"<<ngaykt.thang<<"/"<<ngaykt.nam<<endl;
    Ngay ngayTruoc=NgayTruoc(ngay1);
    cout<<"Ngay truoc do: "<<ngayTruoc.ngay<<"/"<<ngayTruoc.thang<<"/"<<ngayTruoc.nam<<endl;
    int thutu=ThuTuNgay(ngay1);
    cout<<"Ngay do la ngay thu: "<<thutu<<endl;
    return 0;
}
