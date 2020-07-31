#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int n,num,last = 0;
    cin >> n;
    int max_min = 0;
    for(int i=0;i<n;i++)
    {
        cin >> num;
        if(i==0)
            last = num;
        else
        {
            if(abs(num-last)>max_min)
                max_min = abs(num-last);
            last = num;
        }
    }
    
    cout << max_min << endl;
    return 0;
}
