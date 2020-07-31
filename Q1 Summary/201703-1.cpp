#include <iostream>
#include <math.h>
#include <cstring>
using namespace std;
int num[1001];
int main() {
    memset(num, 0, sizeof(num));
    int n, k;
    cin >> n >> k;
    int cake = 0;
    for(int i=0;i<n;i++)
    {
        cin >> num[i];
    }
    int tot = 0;
    for(int i=0;i<n;i++)
    {
        tot += num[i];
        if(tot>=k)
        {
            tot = 0;
            cake++;
        }
    }
    if(tot!=0)
        cake++;
    cout << cake << endl;
    return 0;
}
