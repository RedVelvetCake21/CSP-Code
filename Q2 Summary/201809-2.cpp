#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1000000;
bool H[maxn];
bool W[maxn];
int main() {
    memset(H, false, sizeof(H));
    memset(W, false, sizeof(W));
    int n, a, b;
    cin >> n;
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        cin >> a >> b;
        for(int k=a;k<b;k++)
            H[k] = true;
    }
    for(int i=0;i<n;i++)
    {
        cin >> a >> b;
        for(int k=a;k<b;k++)
            W[k] = true;
    }
    for(int i=0;i<maxn;i++)
    {
        if(H[i]&&W[i])
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}
