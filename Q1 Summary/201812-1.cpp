#include <iostream>
using namespace std;
int main() {
    int r,y,g;
    cin >> r >> y >> g;
    int n,k,t0;
    cin >> n;
    int ans = 0;
    while(n--)
    {
        cin >> k >> t0;
        if(k==0)
            ans+=t0;
        else if(k==1)
            ans+=t0;
        else if(k==2)
            ans += t0+r;
        else
            continue;
    }
    cout << ans << endl;
    return 0;
}
