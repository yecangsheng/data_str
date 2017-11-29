#ifndef AVL_H
#define AVL_H
#include<iostream>
using namespace std;
#include<algorithm>
template<typename T>
struct AVLNode{
    T data;
    AVLNode* left;
    AVLNode* right;
    int height;
    AVLNode(T value,AVLNode* l, AVLNode* r,int h):data(value),left(l),right(r),height(h){}
};

template<typename T>
class AVLTree{

private:
    AVLNode<T>* root;
public:
    AVLTree():root(NULL){}
    ~AVLTree(){destroy();}

    void insert(T key){insert(root,key);}
    void remove(T key){remove(root,key);}
    int height(AVLNode<T> *t){return t==NULL?-1:t->height;}

	T findMin(){
		return findMin(root)->data;
        }
    void destroy(){destroy(root);}
	
    void print(){print(root,root->data,0);}
private:

	AVLNode<T>* findMin(AVLNode<T>* tree);
    void insert(AVLNode<T>* &tree,const T& x);
    void remove(AVLNode<T>* &tree,const T& x);
    
    void rotatelchild(AVLNode<T>* &t);
    void doublelchild(AVLNode<T>* &t);
    void rotaterchild(AVLNode<T>* &t);
    void doublerchild(AVLNode<T>* &t);

    void destroy(AVLNode<T>* &tree);
    void print(AVLNode<T>* tree,T key,int direction);


};



template<typename T>
void AVLTree<T>:: rotatelchild(AVLNode<T>* &k2){
    AVLNode<T>* k1=k2->left;
    k2->left=k1->right;
    k1->right=k2;
    k2->height=max(height(k2->left),height(k2->right))+1;
    k1->height=max(height(k1->left),k2->height)+1;
    k2=k1;
}

template<typename T>
void AVLTree<T>:: rotaterchild(AVLNode<T>* &k2){
    AVLNode<T>* k1=k2->right;
    k2->right=k1->left;
    k1->left=k2;
    k2->height=max(height(k2->left),height(k2->right))+1;
    k1->height=max(height(k1->right),k2->height)+1;
    k2=k1;
}

template<typename T>
void AVLTree<T>:: doublelchild(AVLNode<T>* &k3){//k3 is root
    rotaterchild(k3->left);
    rotatelchild(k3);
}
template<typename T>
void AVLTree<T>:: doublerchild(AVLNode<T>* &k3){//k3 is root
    rotatelchild(k3->right);
    rotaterchild(k3);
}

template<typename T>
void AVLTree<T>:: insert(AVLNode<T>* &tree,const T& x){
    if(tree==NULL)
        tree=new AVLNode<T>(x,NULL,NULL,0);
    else if(x<tree->data)
        {
            insert(tree->left,x);
            if(height(tree->left)-height(tree->right)==2)
            {
                if(x<tree->left->data)
                    rotatelchild(tree);
                else
                    doublelchild(tree);
            }
        }
    else if(x>tree->data)
        {
            insert(tree->right,x);
            if(height(tree->right)-height(tree->left)==2)
            {
                if(x>tree->right->data)
                    rotaterchild(tree);
                else
                    doublerchild(tree);
            }
        }
    else
    ;
    tree->height= 1 +( height(tree->left)>height(tree->right)? height(tree->left):height(tree->right));
}


template<typename T>
void AVLTree<T>:: remove(AVLNode<T>* &tree,const T& x){ 
    if(tree==NULL)
        return;
    if(x<tree->data)
    {
        remove(tree->left,x);
        if(height(tree->right)-height(tree->left)==2)
        {
            if(tree->right->left!=NULL&&(height(tree->right->left)>height(tree->right->right)))
                doublerchild(tree);
            else
                rotaterchild(tree);
        }
        
    }
    else if(x>tree->data)
    {
        remove(tree->right,x);
        if(height(tree->left)-height(tree->right)==2)
        {
            if(tree->left->right!=NULL&&(height(tree->left->right)>height(tree->left->left)))
                doublelchild(tree);
            else
                rotatelchild(tree);
        }
    }
 	else if(tree->left!=NULL && tree->right!=NULL)
    {
        tree->data=findMin(tree->right)->data;
        remove(tree->right,tree->data);
    }
    else
    {
        AVLNode<T>* old=tree;
        tree=(tree->left!=NULL)?tree->left:tree->right;
        delete old;
    }
}

template<typename T>
void AVLTree<T>:: destroy(AVLNode<T>* &tree){
    if(tree==NULL)
        return;
    if(tree->left!=NULL)
        return destroy(tree->left);
    if(tree->right==NULL)
        return destroy(tree->right);
    delete tree;
    tree==NULL;

}
template<typename T>
void AVLTree<T>:: print(AVLNode<T>* tree,T key,int direction){
    if(tree!=NULL)
    {
        if(direction==0)
            cout<<tree->data<<" is root. "<<endl;
        else  if(direction==-1)
            cout<<tree->data<<" is the "<<key<<"'s left child. "<<endl;
        else
            cout<<tree->data<<" is the "<<key<<"'s right child. "<<endl;
        
        print(tree->left,tree->data,-1);
        print(tree->right,tree->data,1);
    }


}

template<typename T>
AVLNode<T>* AVLTree<T>:: findMin(AVLNode<T>* tree)
{
	if(tree==NULL)
		return NULL;
	if(tree->left==NULL)
		return tree;
	return findMin(tree->left);
}


#endif
