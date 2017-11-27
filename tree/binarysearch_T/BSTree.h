#ifndef BSTree_H_
#define BSTree_H_

#include<iostream>
using namespace std;

template<typename T>
struct BSTNode{
    T data;
    BSTNode* left;
    BSTNode* right;
    BSTNode* parent;
    BSTNode(T value,BSTNode* p,BSTNode* l,BSTNode* r):data(value),parent(p),left(l),right(r){}
};

template<typename T>
class BSTree{
private:
    BSTNode<T>* root;
public:
    BSTree():root(NULL){}
    BSTree(BSTNode<T>* r):root(r){}
    ~BSTree(){destroy();}
    void preOrder(){preOrder(root);}//前序遍历
    void inOrder(){inOrder(root);}//中序遍历
    void postOrder(){postOrder(root);}//后序遍历

    BSTNode<T>* search(T key){return search(root,key);}//在树中查找key

    T findMin(){
        BSTNode<T>* r=findMin(root);
        return r->data;                    
    }
    T findMax(){
        BSTNode<T>* r=findMax(root);
        return r->data;
    }

    BSTNode<T>* successor(BSTNode<T>* x);//后继（比节点大的最小节点）
    BSTNode<T>* predecessor(BSTNode<T>* x);//前驱（比结点小的最大节点）

    void insert(T key) {insert(root,key); }
    void remove(T key) {remove(root,key);}

    void destroy(){destroy(root);}

    void print(){print(root,root->data,0);}
private:
    void preOrder(BSTNode<T>* tree) const;
    void inOrder(BSTNode<T>* tree) const;
    void postOrder(BSTNode<T>* tree) const;

    BSTNode<T>* search(BSTNode<T>* x,T key) const;
    BSTNode<T>* findMin(BSTNode<T>* tree);
    BSTNode<T>* findMax(BSTNode<T>* tree);

    void insert(BSTNode<T>* &tree,const T& x);
    void remove(BSTNode<T>* &tree,const T& x);

    void destroy(BSTNode<T>* &tree);
    void print(BSTNode<T>* tree,T key,int direction);


};

template <typename T>
void BSTree<T>::preOrder(BSTNode<T>* tree) const
{
    if(tree!=NULL)
    {
        cout<<tree->data<<" ";
        preOrder(tree->left);
        preOrder(tree->right);
    }
}
template <typename T>
void BSTree<T>::inOrder(BSTNode<T>* tree) const
{
    if(tree!=NULL)
    {
        inOrder(tree->left);
        cout<<tree->data<<" ";
        inOrder(tree->right);
    }
}
template <typename T>
void BSTree<T>::postOrder(BSTNode<T>* tree) const
{
    if(tree!=NULL)
    {
        postOrder(tree->left);
        postOrder(tree->right);
        cout<<tree->data<<" ";
    }
}

template <typename T>
BSTNode<T>* BSTree<T>::search(BSTNode<T>* x,T key) const
{
    if(x==NULL)
        return NULL;
    else if(key<x->data)
        return search(x->left,key);
    else if(key>x->data)
        return search(x->right,key);
    else 
        return x;
}


template <typename T>
BSTNode<T>* BSTree<T>::findMin(BSTNode<T>* tree)
{
    if(tree==NULL)
        return NULL;
    if(tree->left==NULL)
        return tree;
    return findMin(tree->left);
}
template <typename T>
BSTNode<T>* BSTree<T>::findMax(BSTNode<T>* tree)
{
    if(tree==NULL)
        return NULL;
    if(tree->right==NULL)
        return tree;
    return findMax(tree->right);
}

template <typename T>
BSTNode<T>* BSTree<T>::successor(BSTNode<T>* x)
{
    if(x->right!=NULL)
        return findMin(x->right);
    BSTNode<T>* y=x->parent;
    while((y!=NULL)&&(x==y->right))
    {
        x=y;
        y=y->parent;
    }
    return y;
}

template <typename T>
BSTNode<T>* BSTree<T>::predecessor(BSTNode<T>* x)
{
    if(x->left!=NULL)
        return findMax(x->left);
    BSTNode<T>* y=x->parent;
    while((y!=NULL)&&(x==y->left))
    {
        x=y;
        y=y->parent;
    }
    return y;
}
template <typename T>
void BSTree<T>::insert(BSTNode<T>* &tree,const T& x)
{
    if(tree==NULL)
        tree=new BSTNode<T>(x,NULL,NULL,NULL);
    else if(x<tree->data)
        insert(tree->left,x);
    else if(x>tree->data)
        insert(tree->right,x);
}
template <typename T>
void BSTree<T>::remove(BSTNode<T>* &tree,const T& x)
{
    if(tree==NULL)
        return;
    if(x<tree->data)
        remove(tree->left,x);
    else if(x>tree->data)
        remove(tree->right,x);
    else if(tree->left!=NULL && tree->right!=NULL)
    {
        tree->data=findMin(tree->right)->data;
        remove(tree->right,tree->data);
    }
    else
    {
        BSTNode<T>* old=tree;
        tree=(tree->left!=NULL)?tree->left:tree->right;
        delete old;
    }
}


template <typename T>
void BSTree<T>::destroy(BSTNode<T>* &tree)
{
    if(tree==NULL)
    return;
    if(tree->left!=NULL)
        return destroy(tree->left);
    if(tree->right!=NULL)
        return destroy(tree->right);
    delete tree;
    tree==NULL;
}
template <typename T>
void BSTree<T>::print(BSTNode<T>* tree,T key,int direction)
{
    if(tree!=NULL)
    { 
        if(direction==0)
            cout<<"  "<<tree->data<<" is the root."<<endl;
        else if(direction==-1)
            cout<<"  "<<tree->data<<" is "<< key <<"'s left child."<<endl;
        else
            cout<<"  "<<tree->data<<" is "<<key <<"'s right child."<<endl;

    print(tree->left,tree->data,-1);
    print(tree->right,tree->data,1);
    }
    //cout<<"it is a empty tree!"<<endl;
}
#endif
