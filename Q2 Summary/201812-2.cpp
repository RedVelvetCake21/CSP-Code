#include <iostream>
using namespace std;
long long traffic[3]; //0红、1绿、2黄
long long cnt_light(int color, long long last, long long passtime, long long sum)
{
    long long tmp = last, t;
    int flag;
    flag = color;
    tmp = (passtime + traffic[flag] - last)%sum;
    while(tmp>traffic[flag])
    {
        tmp -= traffic[flag];
        flag = (flag+1)%3;
    }
    if(flag==1) // 绿灯
        t = 0;
    else if(flag==0) // 红灯
        t = traffic[0]- tmp;
    else //黄灯
        t = traffic[2]- tmp + traffic[0];
    return t;
}
int main() {
    cin >> traffic[0] >> traffic[2] >> traffic[1];
    long long sum = traffic[0]+traffic[1]+traffic[2];
    int n,k;
    cin >> n;
    long long t0, ans = 0; //注意要用long long
    while(n--)
    {
        cin >> k >> t0;
        if(k==0)
            ans += t0;
        else if(k==1)//红
            ans += cnt_light(0, t0, ans, sum);
        else if(k==2)//黄
            ans += cnt_light(2, t0, ans, sum);
        else//绿
            ans += cnt_light(1, t0, ans, sum);
    }
    cout << ans << endl;
    return 0;
}

