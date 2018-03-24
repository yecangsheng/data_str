#include<iostream>
#include<vector>
using namespace std;
template <typename T>
void shell_sort(vector<T> &arr)
{
    for(int gap=arr.size()/2;gap>0;gap/=2)
    {
        for(int i=gap;i<arr.size();i++)
        {
            T temp=arr[i];
            int j;
            for(j=i;j>=gap&&temp<arr[j-gap];j-=gap)
            {
                arr[j]=arr[j-gap];
          //      arr[j-gap]=temp;
            }
            arr[j]=temp;
                
        }
        for(auto v:arr)
        {
            cout<<v<<" ";
        }
        cout<<endl;
    }

}

int main()
{
    vector<int> a={81,94,44,96,12,48,28,14,5};
    shell_sort(a);    
return 0;
}

