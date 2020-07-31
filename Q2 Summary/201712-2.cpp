#include <iostream>
#include <cstring>
using namespace std;
bool child[1000];
int main() {
    int n,k;
    cin >> n >> k;
    memset(child, true, sizeof(child));
    int cnt = n;
    int num = 1,index = 0;
    while(cnt>1)
    {
        if(child[index]==false)
        {
            index++;
            index %= n;
            continue;
        }
        if(num%10==k || num%k==0)
        {
            cnt--;
            child[index] = false;
        }
        if(cnt==1)
            break;
        index++;
        index %= n;
        num++;
    }
    for(int i=0;i<n;i++)
        if(child[i])
        {
            cout << i+1 << endl;
            break;
        }
    return 0;
}
