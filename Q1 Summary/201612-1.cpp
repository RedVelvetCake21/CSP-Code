#include <iostream>
#include <math.h>
#include <cstring>
using namespace std;
int num[1001];
int main() {
    memset(num, 0, sizeof(num));
    int large,small,cnt;
    int n;
    cin >> n;
    int middle = -1;
    for(int i=0;i<n;i++)
    {
        cin >> num[i];
    }
    for(int i=0;i<n;i++)
    {
        large=small=0;
        cnt = 1;
        int tmp = num[i];
        for(int j=0;j<n;j++)
        {
            if(j==i)
                continue;
            else if(tmp>num[j])
                large++;
            else if(tmp<num[j])
                small++;
            else
                cnt++;
        }
        if(large==small && large+small==(n-cnt))
        {
            middle = tmp;
            break;
        }
    }
    cout << middle << endl;
    return 0;
}
