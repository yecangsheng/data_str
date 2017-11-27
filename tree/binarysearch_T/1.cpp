#include<iostream>
using namespace std;
struct Node{    
    int data;
    Node* left;
    Node* right;
    Node(int x,Node* l,Node* r):data(x),left(l),right(r){}
};
void print(Node* r)
{
    if(r!=NULL)
    cout<<'\t';
    cout<<r->data;
    print(r->left);
    print(r->right);

}
int main()
{
    Node d2(2000,NULL,NULL);
    Node d3(3000,NULL,NULL);
    Node d1(1000,NULL,NULL);
    d1.left=&d2;
    d1.right=&d3;
    print(d1.left);
   
    return 0;
}
