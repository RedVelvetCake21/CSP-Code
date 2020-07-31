
#include<iostream>
using namespace std;
int gross_pay; // 税前工资
int net_pay; // 税后工资
int main()
{
    cin>>net_pay;
    if (net_pay <= 3500)
        gross_pay = net_pay;
    else if (net_pay <= 4955)
        gross_pay = ((net_pay - 3500) / 97) * 100 + 3500;
    else if (net_pay <= 7655)
        gross_pay = (net_pay - 4955) / 90 * 100 + 5000;
    else if (net_pay <= 11255)
        gross_pay = (net_pay - 7655) / 80 * 100 + 8000;
    else if (net_pay <= 30755)
        gross_pay = (net_pay - 11255) / 75 * 100 + 12500;
    else if (net_pay <= 44755)
        gross_pay = (net_pay - 30755) / 70 * 100 + 38500;
    else if (net_pay <= 61005)
        gross_pay = (net_pay - 44755) / 65 * 100 + 58500;
    else
        gross_pay = (net_pay - 61005) / 55 * 100 + 83500;
    cout<< gross_pay;
    return 0;
}
