#include<iostream>
using namespace std;
#include<vector>
#include<string>
void insert_sort(int arr[],int l)
{
    for(int i=1;i<l;i++)
    {
        int temp=arr[i];
        for(int j=i;j>0&&arr[j-1]>temp;j--)
        {
            arr[j]=arr[j-1];
            arr[j-1]=temp;
        }

    }


}
template <typename T>
void insert_s(vector<T> &arr)
{
    for(int i=1 ;i<arr.size()-1 ;i++)
    {
        T temp=arr[i];
        int j;
        for( j=i ; j>0 &&arr[j-1]>temp;j-- )
        {
            arr[j]=arr[j-1];
        }
            arr[j]=temp;            
    }
}
int main()
{
int a[]={12,4,857,2,14,6,2,56,4};
int l=sizeof(a)/sizeof(int);
insert_sort(a,l);
for(int i=0;i<l;i++)
{
    cout<<a[i]<<",";
}
cout<<endl;
cout<<"-----------------------------------"<<endl;
vector<string> b={"apple","pen","cell","call","orange","tent"};
insert_s(b);
for(auto v:b)
{
    cout<<v<<" ";
}

return 0;
}
