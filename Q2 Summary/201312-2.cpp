#include<iostream>
#include<cstring>
using namespace std;
void judge(string s)
{
    int id = 0;
    id += (s[0]-'0')+(s[2]-'0')*2+(s[3]-'0')*3+(s[4]-'0')*4+(s[6]-'0')*5+(s[7]-'0')*6+(s[8]-'0')*7+(s[9]-'0')*8+(s[10]-'0')*9;
    id %= 11;
    if(s[12]-'0'==id || (s[12]=='X'&&id==10))
        cout << "Right" << endl;
    else
    {
        if(id<10)
            s[12] = id+'0';
        else
            s[12] = 'X';
        cout << s << endl;
    }
    
}
int main() {
    string s;
    cin >> s;
    judge(s);
    return 0;
}
