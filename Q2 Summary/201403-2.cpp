#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Window{
    int x1,x2,y1,y2;
    int level;
    int num;
    Window(int a,int b,int c, int d, int l, int n):x1(a),y1(b),x2(c),y2(d),level(l), num(n){}
};
vector<Window> window;
bool cmp(Window a, Window b)
{
    return a.level>b.level;
}
void judge(int x, int y, int n)
{
    int found = -1;
    sort(window.begin(), window.end(), cmp);
    for(int i=0;i<window.size();i++)
    {
        if(window[i].x1<=x && window[i].x2>=x && window[i].y1<=y && window[i].y2>=y)
        {
            found = i;
            window[i].level = n;
            cout << window[i].num << endl;
            break;
        }
    }
    if(found==-1)
    {
        cout << "IGNORED" << endl;
        return;
    }
    for(int i=0;i<found;i++)
    {
        window[i].level = window[i].level-1;
    }
//    for(int i=0;i<window.size();i++)
//        cout <<found<< " window "<<window[i].num<<"level " << window[i].level<< endl;
}
int main() {
    int n, m;
    int nsize;
    cin >> n >> m;
    nsize = n;
    int i = 1;
    int x1,y1,x2,y2;
    while(n--)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        window.push_back(Window(x1,y1,x2,y2,i,i));
        i++;
    }
    int x, y;
    while(m--)
    {
        cin >> x >> y;
        judge(x, y, nsize);
    }
    return 0;
}
