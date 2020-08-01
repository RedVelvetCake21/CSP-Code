#include<iostream>
#include<cstring>
#include<string>
#include<cctype>
using namespace std;
string target;

int main() {
    cin >> target;
    int option,n;
    cin >> option >> n;
    string s,s1;
    while(n--)
    {
        cin >> s;
        s1 = s;
        if(option==0)
        {
            for(int i=0;i<target.size();i++)
                target[i] = tolower(target[i]);
            for(int i=0;i<s.size();i++)
                s1[i] = tolower(s1[i]);
        }
        if(s1.find(target)!=-1)
            cout << s << endl;
        else
            continue;
    }
    return 0;
}
