#include"BSTree.h"

int main()
{
    BSTNode<int> d1(0,NULL,NULL,NULL);
    BSTree<int> itree;
   // itree.print();
    itree.insert(11);
    itree.insert(8);
    itree.insert(6);
    itree.insert(15);
    itree.insert(12);
    itree.insert(17);
    itree.print();
    itree.remove(17);
    itree.insert(20);
    itree.insert(2);
    itree.print();
    itree.inOrder();
    cout<<"______________________________"<<endl;
    cout<<"the max of itree:"<<itree.findMax();
    cout<<"the min of itree:"<<itree.findMin();
    cout<<"________________________________"<<endl;
    
    cout<<"the predecessor of the 15: "<<(itree.predecessor(itree.search(15)))->data<<endl;
    cout<<"the successor of the 11: "<<(itree.successor(itree.search(11)))->data<<endl;
return 0;
}
