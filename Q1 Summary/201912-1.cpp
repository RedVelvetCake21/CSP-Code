#include <iostream>
#include <cstring>
using namespace std;
int cnt[4];
int main() {
    memset(cnt, 0, sizeof(cnt));
    int n, flag=0;
    cin >> n;
    int tot = 1,num = 0;
    while(true)
    {
        if(num==n)
            break;
        if(tot%10==7 || (tot/10)%10==7 ||tot/100==7) //报的数字含7
        {
            cnt[flag]++;
            //cout << tot << ' '<< flag <<endl;
        }
        else if(tot%7==0)//7的倍数
        {
            cnt[flag]++;
            //cout << tot << ' '<< flag <<endl;
        }
        else//报数
        {
            num++;
        }
        flag = (flag+1)%4;
        tot++;
    }
    printf("%d\n%d\n%d\n%d\n", cnt[0],cnt[1],cnt[2],cnt[3]);
    return 0;
}
