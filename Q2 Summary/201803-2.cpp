#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct B{
    int id,pos,direc; //向右为1，向左为-1
    B(int i, int p, int d):id(i),pos(p),direc(d){}
};
bool cmp(B a, B b)
{
    return a.pos<b.pos;
}
bool cmp2(B a, B b)
{
    return a.id<b.id;
}
vector<B> balls;
int main() {
    int n,l,t,pos;
    cin >> n >> l >> t;
    for(int i=0;i<n;i++)
    {
        cin >> pos;
        balls.push_back(B(i+1, pos, 1));
    }
    while(t--)
    {
        for(int i=0;i<n;i++)
        {
            balls[i].pos += balls[i].direc;
        }
        sort(balls.begin(),balls.end(),cmp);
        for(int i=0;i<n;i++)
        {
            if(i+1<n && balls[i].pos==balls[i+1].pos)
            {
                balls[i].direc *= -1;
                balls[i+1].direc *= -1;
                i++;
            }
            else if(balls[i].pos==0 && balls[i].direc==-1)
                balls[i].direc = 1;
            else if(balls[i].pos==l && balls[i].direc==1)
                balls[i].direc = -1;
        }
    }
    sort(balls.begin(),balls.end(),cmp2);
    for(int i=0;i<n;i++)
        cout << balls[i].pos << ' ';
    cout << endl;
    return 0;
}
