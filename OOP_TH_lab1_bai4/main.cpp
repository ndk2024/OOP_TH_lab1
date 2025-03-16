#include <iostream>
#include <cmath>
#include <iomanip>
//Bài 4
using namespace std;

double giai_thua(int n) // Hàm tính giai thừa
{
    double s = 1;
    for (int i = 1; i <= n; i++)
    {
        s *= i;
    }
    return s;
}

int main() {
    double x, sign = 1;
    double epsilon = 1e-10; // Độ chính xác mong muốn
    cin >> x;
    while(x>=360)
    {
        x=x-360;
    }
    while(x<=-360)
    {
        x=x+360;
    }
    x = x * M_PI / 180.0;
    double sinx = 0, term = x;
    int i = 0;
    while (abs(term) > epsilon)
    {
        sinx += term;
        sign = -sign;
        i++;
        term = sign * pow(x, 2 * i + 1) / giai_thua(2 * i + 1);
    }
    cout << fixed << setprecision(6) << sinx << endl;
    return 0;
}
