#include<iostream>
using namespace std;
#include<vector>
#include<cstring>
int maxsum(const int a[],int i)
{
    int thissum=0;
    int maxsum=0;
    for(int j=0;j<i;j++)
    {
        thissum += a[j];
        if(thissum<0)
        {
            thissum=0;
        }
        else if(maxsum<thissum)
        {
            maxsum=thissum;
        }
    }
    return maxsum;

}
int maxsum(const vector<int> &a)
{
    int thissum=0;
    int maxsum=0;
    for(int j=0;j<a.size();j++)
    {
        thissum += a[j];
        if(thissum<0)
        {
            thissum=0;
        }
        else if(maxsum<thissum)
        {
            maxsum=thissum;
        }
    }
    return maxsum;
}

int main()
{
    vector<int> b={15,-9,8,-3,-1,19,-50,19,-5,20,8};
    int a[5]={15,-9,18,-3,-1};
    int l=sizeof(a)/sizeof(int);
    cout<<"maxsum:"<<maxsum(a,l)<<endl;
    cout<<"maxsum:"<<maxsum(b)<<endl;


}
