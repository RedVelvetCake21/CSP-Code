#include <iostream>
#include <cstring>
using namespace std;
bool seat[20][5];
void buy(int t)
{
    int cnt,start,end;
    bool consist = false; //连续购票标记
    for(int i=0;i<20;i++)
    {
        cnt = 0;
        start = end = 5;
        for(int j=0;j<5;j++)
        {
            if(seat[i][j]==false) //座位为空
            {
                if(j<start) start = j;
                end = j;
                cnt++;
            }
            else
                cnt = 0;
            if(cnt==t)
            {
                for(int k=start;k<=end;k++)
                {
                    cout << 5*i+k+1 << ' ';
                    seat[i][k] = true;
                }
                consist = true;
                cout << endl;
                return;
            }
        }
    }
    if(!consist)
    {
        cnt = 0;
        for(int i=0;i<20;i++)
        {
            for(int j=0;j<5;j++)
            {
                if(!seat[i][j])
                {
                    cnt++;
                    seat[i][j] = true;
                    cout << i*5+j+1 <<' ';
                }
                if(cnt==t)
                {
                    cout << endl;
                    return;
                }
            }
        }
    }
    return;
}
int main() {
    int n,tickets;
    cin >> n;
    memset(seat, false, sizeof(seat));
    for(int i=0;i<n;i++)
    {
        cin >> tickets;
        buy(tickets);
    }
    return 0;
}
