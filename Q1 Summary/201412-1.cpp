#include<iostream>
#include <cstring>
using namespace std;
int main() {
    int n,id;
    int reader[1001];
    memset(reader, 0, sizeof(reader));
    cin >> n;
    while(n--)
    {
        cin >> id;
        reader[id]++;
        if(n!=0)
            cout << reader[id] << ' ';
        else
            cout << reader[id] << endl;
    }

    return 0;
}
