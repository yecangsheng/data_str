#include<iostream>
using namespace std;
#include<vector>

void bub_sort(int arr[],int l)
{
    
    for(int i=0;i<l-1;i++)
    {
        for(int j=0;j<l-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
                
            }
            
        }


    }


}
template <typename T>
void bub_s(vector<T> &arr)
{
    for(int i=0;i<arr.size()-1;i++)
    {
        for(int j=0;j<arr.size()-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                T temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }       

    }
    for(auto v:arr)
    {
        cout<<v<<" ";
    }

}
int main()
{
    int a[]={465,45,4,55,7,45,25,9,1,65};
    int l=sizeof(a)/sizeof(int);
    bub_sort(a,l);
    for(int i=0;i<10;i++)
    {
        cout<<a[i]<<",";

    }
    cout<<endl;
    cout<<"--------------------"<<endl;
    vector<float> b={45.2,12.5,78,20.3,12.9};
    bub_s(b);
    
    


}
