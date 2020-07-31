#include <iostream>
#include <math.h>
#include <cstring>
using namespace std;
int num[1001];
int num2[1001];
int main() {
    int n;
    cin >> n;
    memset(num, 0, sizeof(num));
    memset(num2, 0, sizeof(num2));
    for(int i=0;i<n;i++)
        cin >> num[i];
    num2[0] = int(floor((num[0]+num[1])/2));
    num2[n-1] = int(floor((num[n-1]+num[n-2])/2));
    for(int i=1;i<n-1;i++)
    {
        num2[i] = int(floor((num[i-1]+num[i+1]+num[i])/3));
    }
    for(int i=0;i<n;i++)
        cout << num2[i] << ' ';
    return 0;
}
