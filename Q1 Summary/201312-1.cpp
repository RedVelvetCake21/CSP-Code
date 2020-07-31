#include<iostream>
#include<cstring>
using namespace std;
int main() {
    int n;
    cin >> n;
    int vec[10005];
    memset(vec, 0, sizeof(vec));
    int num, max = 0;
    while(n--)
    {
        cin >> num;
        if(num>max)
            max = num;
        vec[num] ++;
    }
    int max_num = 10005,max_size = 0;
    for(int i=1;i<=max;i++)
    {
        if(vec[i] >= max_size)
        {
            max_size = vec[i];
            if(i < max_num || vec[max_num] < max_size )
                max_num = i;
        }
    }
    cout << max_num << endl;
    return 0;
}
