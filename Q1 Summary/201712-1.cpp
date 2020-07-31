#include <iostream>
#include <math.h>
using namespace std;
int a[1000];
int main() {
    int n,tmp;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    int ans = 10000;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            tmp = abs(a[i]-a[j]);
            if(tmp < ans)
                ans = tmp;
        }
    }
    cout << ans << endl;
    return 0;
}
