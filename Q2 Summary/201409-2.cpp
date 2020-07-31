#include<iostream>
#include <cstring>
using namespace std;
int main() {
    int n,x1,y1,x2,y2;
    int square[101][101];
    memset(square, 0, sizeof(square));
    cin >> n;
    int tot = 0;
    while(n--)
    {
        cin >> x1 >>y1 >> x2 >> y2;
        for(int i=x1;i<x2;i++)
            for(int j=y1;j<y2;j++)
                square[i][j]  = 1;
    }
    for(int i=0;i<101;i++)
        for(int j=0;j<101;j++)
            if(square[i][j]==1)
                tot++;
    cout << tot << endl;
    return 0;
}
