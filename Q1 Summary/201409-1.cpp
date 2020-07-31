#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
    int n,num;
    vector<int> numbers;
    cin >> n;
    int tot = 0;
    while(n--)
    {
        cin >> num;
        numbers.push_back(num);
    }
    sort(numbers.begin(),numbers.end());
    for(int i=0;i<numbers.size()-1;i++)
    {
        if(numbers[i+1]-numbers[i]==1)
            tot++;
    }
    cout << tot << endl;
    return 0;
}
