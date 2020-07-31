#include<iostream>
using namespace std;
int main() {
    typedef struct S{
        int index;
        int value;
    } Point;
    Point *u;
    
    int a,b,n,i,j;
    long long sum;
    int index,value;
    cin>>n>>a>>b;
    u=new S[a];
    for (i=0;i<a;i++) {
        cin>>u[i].index>>u[i].value;
    }
    sum=0;j=0;
    for (i=0;i<b && j<a ;i++) {
        cin>>index>>value;
        while ((j<a) && (index>u[j].index))
            j++;
        if ((j<a )&& (u[j].index==index )) {
            sum+= u[j].value*value;  j++;
        }
    }
    cout << sum;
    delete [ ] u;
    return 0;
}
