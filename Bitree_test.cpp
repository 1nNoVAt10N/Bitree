#include "BItree.h"
int main(){
    Bitree<char> T1;
    T1.root->data = 'x';
    BiNode<char> T2;
    T2.data = 'c';
    T1.root->lchild = &T2;
    BiNode<char> T3;
    T3.data = 'v';
    T1.root->rchild = &T3;
    BiNode<char> T5;
    T5.data = 'b';
    T2.rchild = &T5;
    BiNode<char> T6;
    T6.data = 'n';
    T3.lchild = &T6;
    //Preorder(T1.root);
    //cout << endl;
    //Inorder(T1.root);
    //cout << endl;
    //Postorder(T1.root);
    //cout << endl;
    //cout << T1.nodenumber() << endl;
    //cout << T1.Isempty() << endl;
    //cout << T1.leafnodenumber() << endl;
    //cout << T1.Isempty() << endl;
    //cout << T1.Treehight();
    //cout << endl;
    //Bitree<char> T7;
    //cout << T7.Treehight() << endl;
    //ClearBitree(T7.root);
    //cout << T7.Treehight();
    //T1.Insert_node(4,'g');
    //Preorder(T1.root);
    Bitree<char> T9 = Creat_a_tree_from_Inorder_and_Postorder<char>();
    Preorder(T9.root);
    system("pause");
    
}