#include <iostream>
#include <cstring>
using namespace std;
int main() {
    string s;
    cin >> s;
    int tot = 0;
    for(int i=0;i<s.length();i++)
    {
        tot+=s[i]-'0';
    }
    cout << tot << endl;
    return 0;
}
