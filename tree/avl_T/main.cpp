#include"avltree.h"

int main()
{
    AVLTree<int> itree;
    itree.insert(11);
    itree.insert(9);
    itree.insert(15);
    itree.insert(7);
    itree.insert(10);
    itree.insert(6);
    itree.insert(20);
    itree.insert(17);
    itree.print();
    
    AVLTree<int> itree2;
    itree2.insert(20);
    itree2.insert(23);
    itree2.insert(15);
    itree2.insert(7);
    itree2.insert(16);
    itree2.insert(17);
    itree2.print();
    
    AVLTree<int> itree3;
    itree3.insert(8);
    itree3.insert(6);
    itree3.insert(11);
    itree3.insert(10);
    itree3.insert(15);
    itree3.remove(6);
    itree3.print();
    return 0;
}
