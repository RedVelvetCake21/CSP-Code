#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
struct Point{
    int x,y,score;
    bool is_here;
    Point(int a, int b, int s, bool i):x(a), y(b), score(s), is_here(i){}
};
bool cmp(Point a, Point b)
{
    if(a.x==b.x)
        return a.y < b.y;
    else
        return a.x < b.x;
}
int ans[5];
int main() {
    memset(ans, 0, sizeof(ans));
    vector<Point> points;
    int n, x, y;
    cin >> n;
    while(n--)
    {
        cin >> x >> y;
        points.push_back(Point(x, y, 0, false));
    }
    sort(points.begin(),points.end(),cmp);
    for(int i=0;i<points.size();i++)
    {
        int xx = points[i].x;
        int yy = points[i].y;
        int flag = 0;
        for(int j=0;j<points.size();j++)
        {
            Point tmp = points[j];
            if(tmp.x == xx-1 && tmp.y==yy) //左
                flag++;
            if(tmp.x == xx+1 && tmp.y==yy) //右
                flag++;
            if(tmp.x == xx && tmp.y==yy-1) //上
                flag++;
            if(tmp.x == xx && tmp.y==yy+1) //下
                flag++;
        }
        if(flag==4)
        {
            points[i].is_here = true;
            for(int j=0;j<points.size();j++)
            {
                Point tmp = points[j];
                if(tmp.x == xx-1 && tmp.y==yy-1) //左上
                    points[i].score++;
                if(tmp.x == xx+1 && tmp.y==yy-1) //右上
                    points[i].score++;
                if(tmp.x == xx-1 && tmp.y==yy+1) //左下
                    points[i].score++;
                if(tmp.x == xx+1 && tmp.y==yy+1) //右下
                    points[i].score++;
            }
        }
    }
    for(int i=0;i<points.size();i++)
    {
        if(!points[i].is_here)
            continue;
        int ind = points[i].score;
        ans[ind]++;
    }
    printf("%d\n%d\n%d\n%d\n%d\n", ans[0],ans[1],ans[2],ans[3],ans[4]);
    return 0;
}
