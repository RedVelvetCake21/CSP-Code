#include <iostream>
using namespace std;
int main() {
    int n,ans = 0;
    int flag1 = 0;
    int cnt = 0;
    while(cin >> n)
    {
        if(n==0) break;
        if(!flag1)
        {
            if(n==2)
                ans = 2;
            else
                ans = 1;
            cnt = n;
            flag1 = 1;
            continue;
        }
        if(n==1)
            cnt = 1;
        else if(n==2 && cnt==1)
            cnt = 2;
        else
            cnt += 2;
        ans += cnt;
    }
    cout << ans << endl;
    return 0;
}
