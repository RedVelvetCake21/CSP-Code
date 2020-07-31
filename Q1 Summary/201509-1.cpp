#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
    int n,num,tmp = 0;
    cin >> n;
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        cin >> num;
        if(i==0)
        {
            ans = 1;
            tmp = num;
        }
        if(tmp!=num)
            ans++;
        tmp = num;
    }
    cout << ans << endl;
    return 0;
}
