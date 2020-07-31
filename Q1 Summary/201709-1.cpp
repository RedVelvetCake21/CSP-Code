#include <iostream>
using namespace std;
int main() {
    int money,a,b,c;
    cin >> money;
    int cnt = 0;
    a = money/50;
    cnt += a*7;
    b = (money-a*50)/30;
    cnt += b*4;
    c = (money-a*50-b*30)/10;
    cnt += c;
    cout << cnt << endl;
    return 0;
}
