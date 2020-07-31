#include<iostream>
using namespace std;
int student[1001];
int n, m;
void move_front(int id, int strike)
{
    for(int i=n;i>=1;i--)
    {
        if(student[i]==id)
        {
            for(int k=i;k>i-strike;k--)
            {
                student[k] = student[k-1];
            }
            student[i-strike] = id;
            return;
        }
    }
}
void move_back(int id, int strike)
{
    for(int i=1;i<=n;i++)
    {
        if(student[i]==id)
        {
            for(int k=i;k<i+strike;k++)
            {
                student[k] = student[k+1];
            }
            student[i+strike] = id;
            return;
        }
    }
}
int main()
{
    for(int i=0;i<1001;i++)
        student[i] = i;
    int id, order;
    cin >> n >> m;
    while(m--)
    {
        cin >> id >> order;
        if(order<0)
            move_front(id, -order);
        else
            move_back(id, order);
    }
    for(int i=1;i<=n;i++)
        cout << student[i] << ' ';
    return 0;
}
