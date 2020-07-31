#include<iostream>
#include<cstring>
using namespace std;
int main() {
    int n,num;
    int numbers[1001];
    bool visited[1001];
    memset(numbers, 0, sizeof(numbers));
    memset(visited, false, sizeof(visited));
    cin >> n;
    int tot = 0;
    while(n--)
    {
        cin >> num;
        if(num>0)
            numbers[num] += 1;
        else
            numbers[-num] -= 1;
        num = num<0?-num:num;
        visited[num] = true;
    }
    for(int i=0;i<1001;i++)
    {
        if((visited[i])&&numbers[i]==0)
            tot++;
    }
    cout << tot << endl;
    return 0;
}
