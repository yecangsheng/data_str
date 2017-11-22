#include<iostream>
using namespace std;
#include<stack>
#include<string>
#include<stdlib.h>
stack <char> sCh;
stack <double> sNum;
void cal_1()
{
    char ch;
    double n1,n2;
    ch=sCh.top();
    while(ch!='(')
    {
        n1=sNum.top();
        sNum.pop();
        n2=sNum.top();
        sNum.pop();
        switch(ch){
            case '+':
                n2+=n1;
                break;
            case '-':
                n2-=n1;
                break;
            case '*':
                n2*=n1;
                break;
            case '/':
                n2/=n1;
                break;
        }
        sNum.push(n2);
        sCh.pop();
        ch=sCh.top();
    }
}
void cal_2()
{
    double n1,n2;
    char ch=sCh.top();
    while(ch=='*'||ch=='/')
    {
        n1=sNum.top();
        sNum.pop();
        n2=sNum.top();
        sNum.pop();
        if(ch=='*')
        {
            n2*=n1;
        }else if(ch=='/')
        {
            n2/=n1;
        }
        sNum.push(n2);
        sCh.pop();
        ch=sCh.top();
    }

}
int main()
{
    int k=0;
    double n;
    char num[10];
    string str;
    cout<<"please input the :"<<endl;
    cin>>str;
    str+="=";
    sCh.push('(');
    for(int i=0;i<str.size();++i)
    {
        if(str[i]>='0'&&str[i]<='9'||str[i]=='.')
        {
            num[k++]=str[i];
            continue;
        }
        num[k]=0;
        if(num[0]!=0){
            n=atof(num);
            num[0]=0;
            sNum.push(n);
        }
    
    k=0;
    switch(str[i])
    {
        case '+':
            cal_1();
            sCh.push('+');
            break;
        case '-':
            cal_1();
            sCh.push('-');
            break;
        case '*':
            cal_2();
            sCh.push('*');
            break;
        case '/':
            cal_2();
            sCh.push('/');
            break;
        case '(':
            sCh.push('(');
            break;
        case ')':
            cal_1();
            sCh.pop();
            break;
        case '=':
            cal_1();
            sCh.pop();
            break;


    }
    }
    cout<<sNum.top()<<endl;

    return 0;
}
