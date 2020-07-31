#include <iostream>
using namespace std;
int month1[] = {31,28,31,30,31,30,31,31,30,31,30,31};
int month2[] = {31,29,31,30,31,30,31,31,30,31,30,31};
bool is_year(int y){
    return y%400==0||(y%4==0&&y%100!=0);
}
int main() {
    int year, day;
    cin >> year >> day;
    int month = 1,date = 1;
    if(!is_year(year))
    {
        for(int i=0;i<12;i++)
        {
            if(day>month1[i])
                day -= month1[i];
            else
            {
                month = i+1;
                date = day;
                break;
            }
        }
    }
    else
    {
        for(int i=0;i<12;i++)
        {
            if(day>month2[i])
                day -= month2[i];
            else
            {
                month = i+1;
                date = day;
                break;
            }
        }
    }
    cout << month << endl << date << endl;
    return 0;
}
