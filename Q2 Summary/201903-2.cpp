#include <iostream>
#include <stack>
using namespace std;
int sign_value[4] = {1, 1, 2, 2};//+、-、*、/
int sign_to_num(char c)
{
    if(c=='+') return 0;
    else if(c=='-') return 1;
    else if(c=='x') return 2;
    else return 3;
}
int calculate(int a, int b, int c)
{
    if(c==0)
        return a+b;
    else if(c==1)
        return b-a;
    else if(c==2)
        return a*b;
    else
        return b/a;
}
int cal_formula(string formula)
{
    stack<int> numbers;
    stack<int> cal;
    int ans = 0, num = 0, t = 1,i = 0;
    while(formula[i]>='0'&& formula[i]<='9')
    {
        num*=t;
        num += formula[i]-'0';
        t*=10;
        i++;
    }
    numbers.push(num);
    int c;
    while(i<formula.length())
    {
        num = 0;t = 1;
        c = sign_to_num(formula[i++]);
        while(formula[i]>='0'&& formula[i]<='9')
        {
            num*=t;
            num += formula[i]-'0';
            t*=10;
            i++;
        }
        if(cal.size()>=1 && sign_value[cal.top()]>=sign_value[c])
        {
            int a = numbers.top();
            numbers.pop();
            int b = numbers.top();
            numbers.pop();
            int c = cal.top();
            cal.pop();
            numbers.push(calculate(a, b, c));
        }
        cal.push(c);
        numbers.push(num);
    }
    while(!cal.empty())
    {
        int a = numbers.top();
        numbers.pop();
        int b = numbers.top();
        numbers.pop();
        int c = cal.top();
        cal.pop();
        numbers.push(calculate(a, b, c));
    }
    ans = numbers.top();
    return ans;
}

int main() {
    int n;
    cin >> n;
    string formula;
    while(n--)
    {
        cin >> formula;
        if(cal_formula(formula)==24)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}

