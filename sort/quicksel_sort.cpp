#include<iostream>
#include<vector>
using namespace std;
template <typename T>
void swap(vector<T> &A,int i,int j)
{
    T temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

template <typename T>
const T& partion3(vector<T>& B,int left,int right )
{
    int center=(left+right)/2;
    if(B[left]>B[center])
        swap(B,left,center);
    if(B[left]>B[right])
        swap(B,left,right);
    if(B[center]>B[right])
        swap(B,center,right);

    swap(B,center,right-1);
    return B[right-1];
}

/*template <typename T>
const T& partion(vector<T>& B,int left,int right)
{


}*/
template<typename T>
void bub_sort(vector<T>&D,int i,int j)
{
    for(int y=i;y<j-1;y++)
    {
        for(int z=i;j<j-i-1;j++)
        {
            if(D[j]>D[j+1])
            {
                T temp=D[j];
                D[j]=D[j+1];
                D[j+1]=temp;
            }
        }
    }
}
template <typename T>
void quicksel_sort(vector<T>& C,int left,int right)
{
    if(left+3<=right)
    {
        T pivot=partion3(C,left,right);
        int i=left,j=right-1;
        for(;;)
        {
            while(C[++i]<pivot){}
            while(C[--j]>pivot){}
            if(i<j)
            swap(C,i,j);
            else
            break;
        }
        swap(C,i,right-1);
        quicksel_sort(C,left,i-1);
        quicksel_sort(C,i+1,right);
    }
    else
    bub_sort(C,left,right);
}

int main()
{
vector<int> a={2,8,12,5,45,123,87,32,45,67,21,39,6,13,59,14};
vector<int> b={2,89,2,14,24,0,21};
quicksel_sort(a,0,a.size()-1);
for(auto v:a)
cout<<v<<" ";


return 0;
}
