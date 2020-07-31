#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
#include <cctype>
#include <stack>
using namespace std;
map<string, int[2]> elements;
struct Ele{
    string name;
    int num;
    Ele(string n, int nu):name(n),num(nu){}
};

bool is_equal(string s)
{
    int eq = int(s.find("="));
    string leftf = s.substr(0, eq);
    int lsize = int(leftf.length());
    string rightf = s.substr(eq+1, s.length()-eq-1);
    int rsize = int(rightf.length());
    int tot;//表达式系数
    for(int i=0;i<lsize;)
    {
        tot = 0;
        while(isdigit(leftf[i])) //求系数
        {
            tot*=10;
            tot += leftf[i]-'0';
            i++;
        }
        if(tot==0)
            tot=1;
        if(leftf[i]=='+') //遇到+
        {i++;continue;}
        //处理化学式
        while(i<lsize && leftf[i]!='+'){
            int subt = 0;
            string e;
            if(leftf[i] !='(' && leftf[i] !=')') //表达式无括号
            {
                if(i+1<lsize && islower(leftf[i+1]))//Aa
                {
                    e = leftf.substr(i, 2);
                    i = i+2;
                    while(isdigit(leftf[i])) //求系数
                    {
                        subt*=10;
                        subt += leftf[i]-'0';
                        i++;
                    }
                    if(subt==0)
                        subt = 1;
                    subt = subt*tot;
                    elements[e][0] += subt;
                }
                else  //A
                {
                    e = leftf.substr(i, 1);
                    i = i+1;
                    while(isdigit(leftf[i])) //求系数
                    {
                        subt*=10;
                        subt += leftf[i]-'0';
                        i++;
                    }
                    if(subt==0)
                        subt = 1;
                    subt = subt*tot;
                    elements[e][0] += subt;
                }
            }//表达式无括号
            else//表达式有括号
            {
                stack<Ele> eles;
                eles.push(Ele("(", -1));
                while(!eles.empty())
                {
                    int subt = 0;
                    string e;
                    if(leftf[i] !=')')
                    {
                        if(i+1<lsize && islower(leftf[i+1]))//Aa
                        {
                            e = leftf.substr(i, 2);
                            i = i+2;
                            while(isdigit(leftf[i])) //求系数
                            {
                                subt*=10;
                                subt += leftf[i]-'0';
                                i++;
                            }
                            if(subt==0)
                                subt = 1;
                            subt = subt*tot;
                            eles.push(Ele(e, subt));
                        }
                        else  //A
                        {
                            e = leftf.substr(i, 1);
                            i = i+1;
                            while(isdigit(leftf[i])) //求系数
                            {
                                subt*=10;
                                subt += leftf[i]-'0';
                                i++;
                            }
                            if(subt==0)
                                subt = 1;
                            subt = subt*tot;
                            eles.push(Ele(e, subt));
                        }
                    }//if(leftf[i] !=')')
                    else
                    {
                        i++;//右括号
                        subt = 0;
                        while(isdigit(leftf[i])) //求系数
                        {
                            subt*=10;
                            subt += leftf[i]-'0';
                            i++;
                        }
                        if(subt==0)
                            subt = 1;
                        while(!eles.empty())
                        {
                            Ele tmp = eles.top();
                            eles.pop();
                            if(tmp.name!="("){tmp.num *= subt;elements[tmp.name][0] += tmp.num;}
                        }
                    }
                }//while(!eles.empty())
            }
        }
    }
    //右式
    for(int i=0;i<rsize;)
    {
        tot = 0;
        while(isdigit(rightf[i])) //求系数
        {
            tot*=10;
            tot += rightf[i]-'0';
            i++;
        }
        if(tot==0)
            tot=1;
        if(rightf[i]=='+') //遇到+
        {i++;continue;}
        //处理化学式
        while(i<rsize && rightf[i]!='+'){
            int subt = 0;
            string e;
            if(rightf[i] !='(' && rightf[i] !=')') //表达式无括号
            {
                if(i+1<rsize && islower(rightf[i+1]))//Aa
                {
                    e = rightf.substr(i, 2);
                    i = i+2;
                    while(isdigit(rightf[i])) //求系数
                    {
                        subt*=10;
                        subt += rightf[i]-'0';
                        i++;
                    }
                    if(subt==0)
                        subt = 1;
                    subt = subt*tot;
                    elements[e][1] += subt;
                }
                else  //A
                {
                    e = rightf.substr(i, 1);
                    i = i+1;
                    while(isdigit(rightf[i])) //求系数
                    {
                        subt*=10;
                        subt += rightf[i]-'0';
                        i++;
                    }
                    if(subt==0)
                        subt = 1;
                    subt = subt*tot;
                    elements[e][1] += subt;
                }
            }//表达式无括号
            else//表达式有括号
            {
                stack<Ele> eles;
                eles.push(Ele("(", -1));
                while(!eles.empty())
                {
                    int subt = 0;
                    string e;
                    if(rightf[i] !=')')
                    {
                        if(i+1<rsize && islower(rightf[i+1]))//Aa
                        {
                            e = rightf.substr(i, 2);
                            i = i+2;
                            while(isdigit(rightf[i])) //求系数
                            {
                                subt*=10;
                                subt += rightf[i]-'0';
                                i++;
                            }
                            if(subt==0)
                                subt = 1;
                            subt = subt*tot;
                            eles.push(Ele(e, subt));
                        }
                        else  //A
                        {
                            e = rightf.substr(i, 1);
                            i = i+1;
                            while(isdigit(rightf[i])) //求系数
                            {
                                subt*=10;
                                subt += rightf[i]-'0';
                                i++;
                            }
                            if(subt==0)
                                subt = 1;
                            subt = subt*tot;
                            eles.push(Ele(e, subt));
                        }
                    }//if(leftf[i] !=')')
                    else
                    {
                        i++;//右括号
                        subt = 0;
                        while(isdigit(rightf[i])) //求系数
                        {
                            subt*=10;
                            subt += rightf[i]-'0';
                            i++;
                        }
                        if(subt==0)
                            subt = 1;
                        while(!eles.empty())
                        {
                            Ele tmp = eles.top();
                            eles.pop();
                            if(tmp.name!="("){tmp.num *= subt;elements[tmp.name][1] += tmp.num;}
                        }
                    }
                }//while(!eles.empty())
            }
        }
    }
    map<string, int[2]>::iterator iter;
    for (iter=elements.begin(); iter!=elements.end(); iter++)
    {
//        cout << iter->first;
//        printf(" 左：%d 右：%d\n",iter->second[0],iter->second[1]);
        if(iter->second[0]!=iter->second[1])
            return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    string s;
    while(n--)
    {
        elements.clear();
        cin >> s;
        if(is_equal(s))
            printf("Y\n");
        else
            printf("N\n");
    }
    return 0;
}
