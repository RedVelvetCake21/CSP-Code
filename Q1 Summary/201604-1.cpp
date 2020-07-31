#include <iostream>
#include <cstring>
using namespace std;
int num[1001];
int main() {
    int n;
    cin >> n;
    int tot = 0;
    memset(num, 0, sizeof(num));
    for(int i=0;i<n;i++)
        cin >> num[i];
    for(int i=1;i<n-1;i++)
    {
        if(num[i]>num[i-1]&&num[i]>num[i+1])
            tot++;
        else if(num[i]<num[i-1]&&num[i]<num[i+1])
            tot++;
    }
    cout << tot << endl;
    return 0;
}
