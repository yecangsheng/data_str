#ifndef BINARYSTOR_H
#define BINARYSTOR_H
#include<iostream>
using namespace std;
template<typename T>
class BinarySearchTree
{
public:
    BinarySearchTree();
    BinarySearchTree(const BinarySearchTree & rhs);
    ~BinarySearchTree();
    
    const T& findMin()const;
    const T& findMax()const;
    bool contains(const T& x) const {return contains(x,root);}
    bool isEmpty() const {return (root==NULL)?true:false;}
    void printTree()const {printTree(root);}
    
    void makeEmpty();
    void insert(const T& x);
    void remove(const T& x);

    const BinarySearchTree operator=(const BinarySearchTree &rhs);

private:
    struct BinaryNode
    {
        T element;
        BinaryNode *left;
        BinaryNode *right;

        BinaryNode(const T& e,BinaryNode* l,BinaryNode* r):element(e),left(l),right(r){}

    };

    BinaryNode *root;

    void insert(const T& x,BinaryNode* &t)const;
    void remove(const T& x,BInaryNode* &t)const;
    BinaryNode* findMin(BinaryNode *t)const;
    BinaryNode* findMax(BinaryNode *t)const;
    
    bool contains(const T& x,BinaryNode *t)cosnt;
    void makeEmpty(BinaryNode* &t);
    void printTree(BinaryNode *t)const;

    BinaryNode* clone(BinaryNode* t)const;

};

template<typename T>
bool BinarySearchTree<T>:: contains(const T& x,BinaryNode *t)
{
    if(t==NULL)
        return false;
    else if(x<t->element)
        return contains(x,t->left);
    else if(x>t->element)
        return contains(x,t->right);
    else 
        return true;
}
template<typename T>
void BinarySearchTree<T>:: printTree(BinaryTree *t)
{
    if(t!=NULL)
    {
        cout<<'\t';
        cout<<t->element<<endl;
    }
    printTree(t->left);
    printTree(t->right);

}

BinaryNode* findM


















#endif
