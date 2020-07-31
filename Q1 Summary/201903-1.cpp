#include <iostream>
using namespace std;
int main() {
    int n,min_n,max_n;
    float mid_n;
    cin >> n;
    int num[n];
    for(int i=0;i<n;i++)
        cin >> num[i];
    int index = int(n/2);
    if(num[n-1]>=num[0])
    {
        min_n = num[0];
        max_n = num[n-1];
    }
    else
    {
        min_n = num[n-1];
        max_n = num[0];
    }
    if(n%2==0)
    {
        if((num[index]+num[index-1])%2==0)
        {
            printf("%d %d %d\n", max_n,(num[index]+num[index-1])/2, min_n);
        }
        else
        {
            mid_n = (num[index]+num[index-1])/2.0;
            printf("%d %.1f %d\n", max_n,mid_n, min_n);
        }
    }
    else
        printf("%d %d %d\n", max_n,num[index], min_n);
    return 0;
}
