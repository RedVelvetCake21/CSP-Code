#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<set>
using namespace std;
struct Deal{
    int type; //1为sell、0为cancel、-1为buy
    double price;
    int quatity;
    Deal(){}//vector定义大小
    Deal(int t,double p, int q):type(t),price(p),quatity(q){}
};
vector<Deal> deals(5000);
set<double> price;
void get_price(int n){
    double p_tmp = 0,max_p = 0;
    long long qua_tmp,buyp,sellp, max_d = 0;
    for(set<double>::iterator it=price.begin();it!=price.end();it++)
    {
        p_tmp=*it;
        buyp = sellp = qua_tmp = 0;
        for(int j=0;j<n;j++)
        {
            if(deals[j].type==-1 && deals[j].price>=p_tmp)
                buyp+=deals[j].quatity;
            else if(deals[j].type==1 && deals[j].price<=p_tmp)
                sellp+=deals[j].quatity;
        }
        qua_tmp = buyp<sellp?buyp:sellp;
        if(qua_tmp>=max_d)
        {
            max_d = qua_tmp;
            if(max_p<p_tmp) max_p = p_tmp;
        }
    }
    printf("%.2f %lld\n", max_p, max_d);
}

int main() {
    string s;
    int num,id,index = 0;
    double p;
    while(cin >> s)
    {
        if(s=="cancel")
        {
            cin >> id;
            deals[id-1].type = 0;
            deals[index] = Deal(0,0,0);//填充空白操作
        }
        else
        {
            cin >> p >> num;
            if(s=="buy")
                deals[index] = Deal(-1,p,num);
            else
                deals[index] = Deal(1,p,num);
            price.insert(p);
        }
        index++;
    }
    get_price(index);
    return 0;
}
