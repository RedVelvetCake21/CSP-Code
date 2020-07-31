#include <iostream>
#include <cstring>
using namespace std;
bool dtree[1000]; //是否掉果
long long tree[1000]; //树上果子总数
int main() {
    memset(dtree, false, sizeof(dtree));
    memset(tree, 0, sizeof(tree));
    int n, m;
    long long aij,start;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> m;
        cin >> start;
        for(int j=1;j<m;j++)
        {
            cin >> aij;
            if(aij<=0) //疏果
            {
                start += aij;
            }
            else //统计
            {
                if(start>aij) //有果掉落
                    dtree[i] = true;
                start = aij;
            }
        }
        tree[i] = start;
    }
    long long t = 0;
    int d = 0, e = 0;
    for(int i=0;i<n;i++)
    {
        t+= tree[i];
        if(dtree[i])
            d++;
    }
    for(int i=0;i<n-2;i++)
    {
        if(dtree[i]&&dtree[i+1]&&dtree[i+2])
            e++;
    }
    if(dtree[n-1]&&dtree[0]&&dtree[1])
        e++;
    if(dtree[n-2]&&dtree[n-1]&&dtree[0])
        e++;
    cout << t << ' ' << d << ' ' << e << endl;
    return 0;
}

