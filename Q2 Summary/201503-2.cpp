#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef struct ID{
    int num,cnt;
    ID(int n, int c):num(n),cnt(c){}
}ID;
bool cmp(ID a, ID b)
{
    if(a.cnt==b.cnt)
        return a.num<b.num;
    else
        return a.cnt>b.cnt;
}
int numbers[1001];
int main() {
    memset(numbers, 0, sizeof(numbers));
    vector<ID> ans;
    int n,num;
    cin >> n;
    while(n--)
    {
        cin >> num;
        numbers[num]++;
    }
    for(int i=0;i<1001;i++)
    {
        if(numbers[i]>0)
            ans.push_back(ID(i, numbers[i]));
    }
    sort(ans.begin(), ans.end(), cmp);
    for(int i=0;i<ans.size();i++)
        cout << ans[i].num << ' ' << ans[i].cnt << endl;
    return 0;
}
