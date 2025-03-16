#include <iostream>
//Bài 6_ thứ 1
using namespace std;
bool SoSanh(int a[],int b[],int n) // Hàm so sánh hai mảng có giống nhau không
{
    for(int i=0; i<n; i++)
    {
        if(a[i]!=b[i])
            return false;
    }
    return true;
}
int main()
{
    cout<<"Nhap so phan tu mang A va B: ";
    int n,m;
    cin>>n>>m;
    int *a=new int [n];
    int *b=new int [m];
    bool tontai=false;
    if (n > m || n <= 0 || m <= 0) // Kiểm tra điều kiện nhập vào đúng
    {
        cout<< 0 <<endl;
        return 0;
    }
    else
    {
        int index[1000], counts=1;
        cout<<"Nhap phan tu mang A: ";
        for(int i=0;  i<n; i++)
            cin>>a[i];
        cout<<"Nhap phan tu mang B: ";
        for(int i=0; i<m; i++)
            cin>>b[i];
        for(int i=0; i<=m-n; i++)
        {
            int *c=new int [n];
            for(int j=i, k=0; k<n; k++,j++)
            {
                c[k]=b[j];
            }
            if(SoSanh(a,c,n)==true)
            {
                tontai=true;
                index[counts]=i;
                counts+=1;
            }
            delete []c;
        }
        if(tontai==true)
        {
            cout<<"So lan xuat hien: ";
            cout<<counts-1<<endl;
            for(int i=1; i<counts; i++)
            {
                cout<<index[i]<<" ";
            }
        }
        else cout<<0;
    }


    delete []a;
    delete []b;
    return 0;
}
