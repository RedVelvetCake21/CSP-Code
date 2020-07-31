#include <iostream>
#include <cstring>
using namespace std;
int sq[1001][1001];
int main() {
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> sq[i][j];
    for(int j=m-1;j>=0;j--)
    {
        for(int i=0;i<n;i++)
            cout << sq[i][j] <<" ";
        cout << endl;
    }
    return 0;
}
