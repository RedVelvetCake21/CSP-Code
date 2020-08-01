#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int hist[1000];
int main() {
    memset(hist, 0, sizeof(hist));
    int n, max_hist = 0;
    int ans = 0;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> hist[i];
        if(hist[i]>max_hist)
            max_hist = hist[i];
    }
    if(n==1)
        ans = hist[0];
    else{
        int tmp,max_s = 0;
        for(int weight = 2;weight<=n;weight++)
        {
            tmp = 0;
            for(int left = 0;left<=n-weight;left++)
            {
                tmp = *min_element(hist+left, hist+left+weight); //时间花费较大
                tmp*=weight;
                if(tmp > max_s)
                    max_s = tmp;
            }
        }
        if(max_s>max_hist)
            ans = max_s;
        else
            ans = max_hist;
    }
    cout << ans << endl;
    return 0;
}

