#include<iostream>
#include<vector>
using namespace std;
struct Point{
	int x,y,sta;
	Point(int a, int b, int c):x(a),y(b),sta(c){}
};
vector<Point> points;
bool judge(int t0, int t1, int t2)
{
	int tmp,flag;
	tmp = t0+points[0].x*t1+points[0].y*t2;
	if(points[0].sta*tmp < 0)
	    flag = -1;
	else if(points[0].sta*tmp > 0)
	    flag = 1;
	else
	    return false;
	for(int i=1;i<points.size();i++)
	{
		
		tmp = t0+points[i].x*t1+points[i].y*t2;
		if(tmp*points[i].sta*flag>0)
		    continue;
		else 
		    return false;
	}
	return true;
}
int main()
{
	int n, m;
	cin >> n >> m;
	int x,y;
	char c;
	while(n--)
	{
		cin >> x >> y >> c;
		if(c=='A')
		    points.push_back(Point(x, y, -1));
		else
		    points.push_back(Point(x, y, 1));
	}
	int t0,t1,t2;
	while(m--)
	{
		cin >> t0 >> t1 >> t2;
		if(judge(t0, t1, t2))
		    cout << "Yes" << endl;
		else
		    cout << "No" << endl;
	}
	return 0;
}
