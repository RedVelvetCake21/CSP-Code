#include<iostream>
#include <cstring>
using namespace std;
int main() {
    int n;
    cin >> n;
    int sq[n][n];
    memset(sq, 0, sizeof(sq));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> sq[i][j];
    cout << sq[0][0];
    for(int k=1;k<n;k++)  //上半个z
    {
        for(int x=0;x<=k;x++)
        {
            if(k%2==1)
                cout << ' ' << sq[x][k-x];
            else
                cout << ' ' << sq[k-x][x];
        }
    }
    for(int k=n;k<=2*(n-1);k++)  //下半个z
    {
        for(int x=n-1;x>=k-n+1;x--)
        {
            if(k%2==0)
                cout << ' ' << sq[x][k-x];
            else
                cout << ' ' << sq[k-x][x];
        }
    }
    cout << endl;
    return 0;
}
