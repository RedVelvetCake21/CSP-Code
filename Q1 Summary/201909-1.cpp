#include <iostream>
using namespace std;
int main() {
    int n,m;
    cin >> n >> m;
    int id = 1;
    int tot,num,k = 1,min_dele=0;
    int t = 0;
    while(n--)
    {
        cin >> tot;
        t+=tot;
        int tmp = 0;
        for(int i=0;i<m;i++)
        {
            cin >> num;
            t+=num;
            tmp+=num;
        }
        if(tmp<min_dele)
        {
            min_dele = tmp;
            k = id;
        }
        id++;
    }
    cout << t << ' ' << k << ' ' << -min_dele << endl;
    return 0;
}
