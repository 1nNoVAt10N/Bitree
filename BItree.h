#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "queue.h"
#include "algorithm"
#include "stack.h"
using namespace std;
template <typename Datatype>
class BiNode{
    public:
    Datatype data;
    BiNode<Datatype>* lchild;
    BiNode<Datatype>* rchild;
    int number;
    BiNode(){lchild = nullptr;rchild = nullptr;}
    BiNode(Datatype x):lchild{nullptr},rchild{nullptr},data{x}{

    }

};
template <typename Datatype>
class Bitree{
    public:
        Bitree(){root = Creat_empty();}
        Bitree(BiNode<Datatype>* root1): root{root1}{
            
        }  
        ~Bitree(){Release(root);}
        //BiNode<Datatype> Root(BiNode<Datatype>);
        BiNode<Datatype>* Creat();
        
        void Preorder_1();  //前序遍历非递归
        void Inorder_1();   //中序遍历非递归
        //void Postorder();
        void Levalorder();   //层序遍历二叉树
        bool Isempty();
        int nodenumber();    //求二叉树的节点数
        int leafnodenumber();  //求叶子节点数
        
        void Insert_node(int,Datatype);    //在二叉树上插入一个节点
        //Bitree<Datatype>(const Bitree<Datatype>& T1){
            //root = _copy1(T1.root);
        //}  //拷贝构造函数
        Bitree<Datatype>& operator=(const Bitree<Datatype>&);
        BiNode<Datatype>* root;       //重载赋值运算
    private:
        
        BiNode<Datatype>* Creat_empty();   //建立一颗空树
        void Release(BiNode<Datatype>* &bt);
};
template<typename Datatype>
BiNode<Datatype> _copy1(BiNode<Datatype>*);

template<typename T>
void Preorder(BiNode<T>* bt);


template<typename T>
void Inorder(BiNode<T>* bt);

template <typename T>
BiNode<T>* Creat_a_preorder_tree();


template<typename T>
void Postorder(BiNode<T>* bt);

template<typename T>
int Treehight(BiNode<T>* bt){
    int count1 = 1;
    int count2 = 1;
    if (bt == nullptr) return 0;
    else{
        count1 += Treehight(bt->lchild);
        count2 += Treehight(bt->rchild);
    }
    if(count1 > count2) return count1;
    else{
        return count2;
    }
}
template <typename T>
BiNode<T>* Bitree<T>::Creat_empty(){
    BiNode<T>* bt;
    bt = new BiNode<T>;
    return bt;
    
}




template <typename T>
BiNode<T>* Bitree<T>::Creat(){
    BiNode<T>* bt;
    char ch;
    cin >> ch;
    if(ch == '#'){
        bt = nullptr;
    }
    else{
        bt = new BiNode<T>;
        bt->data = ch;
        bt->lchild = Creat();
        bt->rchild = Creat();
    }
    return bt;
}
template <typename T>
void Bitree<T>::Release(BiNode<T>* &bt){
    if (bt == nullptr) return;
    else{
        Release(bt->lchild);
        Release(bt->rchild);
        delete bt;
        bt = nullptr;
    }
}


template<typename T>
void Preorder(BiNode<T>* bt){
    if(bt == nullptr) return;
    else{
        cout << bt->data << "\t";
        Preorder(bt->lchild);
        Preorder(bt->rchild);
    }
}


template<typename T>
void Preorder_use(BiNode<T>* bt){
    if(bt == nullptr) return;
    else{
        Preorder_use(bt->lchild);
        Preorder_use(bt->rchild);
    }
}

template <typename T>
void Creat_a_tree_from_preorder(int l1,int r1,int l2,int r2,BiNode<T>* &bt,const T* arr1,const T* arr2){    //arr1前序序列，arr2中序序列
    if (l1 > r1 || l2 > r2){
        bt = nullptr;
        return;
    }
    bt = new BiNode<T>(arr1[l1]);
    int num = 0;
    for (num;num < r2;num++){
        if (arr1[l1] == arr2[num]){
            break;
        }
    }
    Creat_a_tree_from_preorder(l1+1,num+l1-l2,l2,num-1,bt->lchild,arr1,arr2);
    Creat_a_tree_from_preorder(num + 1+r1-r2,r1,num+1,r2,bt->rchild,arr1,arr2);


}


template <typename T>
void Creat_a_tree_from_Postorder(int l1,int r1,int l2,int r2,BiNode<T>* &bt,const T* arr1,const T* arr2){
    if (l1 > r1 || l2 > r2){
        bt = nullptr;
        return;
    }
    bt = new BiNode<T>(arr1[l1]);
    int num = 0;
    for (num;num < r2;num++){
        if (arr1[l1] == arr2[num]){
            break;
        }
    }
    Creat_a_tree_from_Postorder(num + 1+r1-r2,r1,l2,num-1,bt->rchild,arr1,arr2);
    Creat_a_tree_from_Postorder(l1+1,num+l1-l2,num+1,r2,bt->lchild,arr1,arr2);
}
template <typename T>
Bitree<T> Creat_a_tree_from_Inorder_and_Postorder(){
    string s1;
    //cout << "请输入后序序列" << endl;
    cin >> s1;
    reverse(s1.begin(),s1.end());
    //cout << s1;
    string s2;
    //cout << "请输入中序序列" << endl;
    cin >> s2;
    
    BiNode<T>* root;
    Creat_a_tree_from_Postorder(0, int(s1.length()-1),0,int(s2.length()-1),root,s1.data(),s2.data());
    return Bitree<T>(root);

}
template <typename T>
Bitree<T> Creat_a_tree_from_preorder_and_Inorder();             //从前序和中序序列创建一棵树
template <typename T>
Bitree<T> Creat_a_tree_from_preorder_and_Inorder(){
    string s1;
    cout << "请输入前序序列" << endl;
    cin >> s1;
    string s2;
    cout << "请输入中序序列" << endl;
    cin >> s2;
    BiNode<T>* root;
    Creat_a_tree_from_preorder(0, int(s1.length()-1),0,int(s2.length()-1),root,s1.data(),s2.data());
    return Bitree<T>(root);



}


BiNode<int>* Creat_a_preorder_tree(){
    vector<int>v1;
    char c;
    int n;
    string s1;
    stringstream ss1;
    cin.get(c);
    while(c != '\n'){
        if(isdigit(c)){
            cin.putback(c);
            cin >> n;
            v1.push_back(n);
        }
        cin.get(c);
    }
    if (v1[0] == 0){
        return nullptr;
    }
    int index = 0;
    
    stack<BiNode<int>*> st(100);
    BiNode<int>* root = new BiNode<int>(v1[index]);
    BiNode<int>* real_root = root;
    
    index++;
    Push(st,root);
    while(index != v1.size()){
        if(v1[index] == 0 && index == v1.size()-1){
            break;
        }
        if(v1[index] == 0){
            Pop(st);
            index++;
            if(v1[index] == 0){break;}
            else{
                root->rchild = new BiNode<int>(v1[index]);
                Push(st,root->rchild);
                root = root->rchild;
            }
        }
        else{
        if(root->lchild!= nullptr){
            root->rchild = new BiNode<int>(v1[index]);
            Push(st,root->rchild);
        }
        else{root->lchild = new BiNode<int>(v1[index]);
        Push(st,root->lchild);}
        }
        index++;
        
        while(v1[index] != 0 && index != v1.size()){
            if(root->rchild != nullptr){
                root = root->rchild;
            }
            else{root = root->lchild;}
            root->lchild = new BiNode<int>(v1[index]);
            Push(st,root->lchild);
            
            index++;
        }
        
        index++;
        if(v1[index] != 0){
            root->rchild = new BiNode<int>(v1[index]);
            root = Top(st);
            Pop(st);
            index++;
            if(root->lchild == nullptr){
                root = root->rchild;
                Push(st,root);
            }

            while(root->lchild != nullptr && index != v1.size() && v1[index] != 0){

                root->rchild = new BiNode<int>(v1[index]);
                index++;
                root = Top(st);
                Pop(st);
            }

            while(v1[index] == 0 && index != v1.size()){
                root = Top(st);
                Pop(st);
                index ++;
            }
            continue;
        }
        if (v1[index] == 0){
            Pop(st);
            if (index < v1.size()){
                if(isEmpty(st) && v1[index] == 0){break;}
            }
            
            while(v1[index] == 0 && index != v1.size() - 1){
                
                root = Top(st);
                Pop(st);
                index ++;
            }

            continue;
        }
    }
    return real_root;}

template<typename T>
void Bitree<T>::Preorder_1(){             //前序遍历的非递归实现
    BiNode<T>* bt = root;
    stack<BiNode<T>*> st(100);
    while(bt != nullptr || !isEmpty(st)){
        while(bt != nullptr){
            cout << bt->data;
            Push(st,bt);
            bt = bt->lchild;
        }
        if(!isEmpty(st)){
            bt = Top(st);
            Pop(st);
            bt = bt->rchild;
        }
    }
}



template <typename T>
void Bitree<T>::Inorder_1(){
    stack<BiNode<T>*> st(100);
    BiNode<T>* bt = root;
    while(bt != nullptr || !isEmpty(st)){
        while(bt != nullptr){
            Push(st,bt);
            bt = bt->lchild;
        }
        if (bt == nullptr && !isEmpty(st)){
            bt = Top(st);
            Pop(st);
            cout << bt->data << "\t";
            bt = bt->rchild;
            continue;
                 }
        //if(bt != nullptr){
           // cout << bt->data << "\t";
        //}
    }
}
template<typename T>
void Inorder(BiNode<T>* bt){
    if(bt == nullptr) return;
    else{
        Inorder(bt->lchild);
        cout << bt->data << "\t";
        Inorder(bt->rchild);
    }
}



template<typename T>
void Postorder(BiNode<T>* bt){
    if (bt == nullptr) return;
    else{
        Postorder(bt->lchild);
        Postorder(bt->rchild);
        cout << bt->data << "\t";
    }
}


template<typename T>
void Bitree<T>::Levalorder(){
    BiNode<T>* q = nullptr;
    Queue<BiNode<T>*> q1(100);
    if(root == nullptr) return;
    q1.Enqueue(root);
    while(!q1.isempty()){
        q = q1.Getfront();
        q1.Dequeue();
        cout << q->data << "\t";
        if (q->lchild != nullptr){
            q1.Enqueue(q->lchild);
        }
        if (q->rchild != nullptr){
            q1.Enqueue(q->rchild);
        }
    }

}


template<typename T>
bool Bitree<T>::Isempty(){
    if (root == nullptr) return true;
    else{
        return false;
    }
}

template<typename T>
int Bitree<T>::nodenumber(){
    int count;
    //BiNode<T>* bt = root;
    if (root == nullptr) return 0;
    BiNode<T>* q = nullptr;
    Queue<BiNode<T>*> q1(100);
    q1.Enqueue(root);
    while(!q1.isempty()){
        q = q1.Getfront();
        q1.Dequeue();
        count ++;
        if (q->lchild != nullptr){
            q1.Enqueue(q->lchild);
        }
        if (q->rchild != nullptr){
            q1.Enqueue(q->rchild);
        }
    }
    return count;
}


template<typename T>
int Bitree<T>::leafnodenumber(){
    int count;
    if(root == nullptr) return 0;
    BiNode<T>* q = nullptr;
    Queue<BiNode<T>*> q1(100);
    q1.Enqueue(root);
    while(!q1.isempty()){
        q = q1.Getfront();
        q1.Dequeue();
        if (q->lchild == nullptr && q->rchild == nullptr){
            count ++;
        }
        if (q->lchild != nullptr){
            q1.Enqueue(q->lchild);
        }
        if (q->rchild != nullptr){
            q1.Enqueue(q->rchild);
        }
    }
    return count;
}


template<typename T>
void ClearBitree(BiNode<T>*& bt){
    if (bt == nullptr) return;
    else{
        //ClearBitree(bt->lchild);
        //ClearBitree(bt->rchild);
        delete bt;
        bt = nullptr;
    }
}






template <typename T>
void Bitree<T>::Insert_node(int n1,T x){     
    BiNode<T>* tree[100];
    for (int i = 0;i< 101;i++){
        tree[i] = nullptr;
    }
    BiNode<T>* q = nullptr;
    Queue<BiNode<T>*> q1(100);
    if(root == nullptr) return;
    root->number = 1;
    q1.Enqueue(root);
    while(!q1.isempty()){
        q = q1.Getfront();
        q1.Dequeue();
        tree[q->number] = q;
        if (q->lchild != nullptr){
            q->lchild->number = q->number*2;
            q1.Enqueue(q->lchild);
        }
        if (q->rchild != nullptr){
            q->rchild->number = q->number*2 + 1;
            q1.Enqueue(q->rchild);
        }
    }
    for (int i = 0;i<10;i++){
        cout << tree[i] << " ";
    }
    if(n1 % 2 == 0){
        if (tree[n1/2] == nullptr){
            cout << "插入位置错误" << endl;
        }
        else{
            tree[n1] = new BiNode<T>;
            tree[n1]->data = x;
            tree[n1 / 2]->lchild = tree[n1];
        }
    }
    if(n1 % 2 != 0){
        if (tree[(n1-1)/2] == nullptr){
            cout << "插入位置错误" << endl;
        }
        else{
            tree[n1] = new BiNode<T>;
            tree[n1]->data = x;
            tree[(n1-1)/ 2]->rchild = tree[n1];
        }
    }
    /*
    if (n1 <= 0){
        cout << "位置错误" << endl;
        return;
    }
    int count;
    BiNode<T>* q = nullptr;
    Queue<BiNode<T>> q1(100);
    if(root == nullptr) return;
    q1.Enqueue(root);
    while(!q1.isempty()){
        q = q1.Getfront();
        q1.Dequeue();
        count++;
        if (count == n1){
            if (q->lchild != nullptr && q->rchild != nullptr){
                cout << "该位置禁止插入" << endl;
                return;
            }
            if (q->lchild != nullptr && n3 == 0){
                cout << "该位置禁止插入" << endl;
                return;
            }
            if (q->rchild != nullptr && n3 == 1){
                cout << "该位置禁止插入" << endl;
                return;
            }
            else{
                if (n3 == 0){

                    q->lchild = new BiNode<T>;
                    q->lchild->data = x;
                    
                }
                if (n3 == 1){
                    q->rchild = new BiNode<T>;
                    q->rchild->data = x;
                }
            }
        }
        if (q->lchild != nullptr){
            q1.Enqueue(q->lchild);
        }
        if (q->rchild != nullptr){
            q1.Enqueue(q->rchild);
        }
        if (count < n1){
            cout << "未找到插入位置" << endl;
        }
    }
    */
}


template<typename T>
BiNode<T>& Creat_singe(T x){     //建立一个单节点的二叉树
    BiNode<T> T1;
    T1 = new BiNode<T>;
    T1.data = x;
    T1.lchild = nullptr;
    T1.rchild = nullptr;
    return T1;
}


template <typename T>
BiNode<T>& Creat_all(T x,int n){
    int count = 0;
    BiNode<T>  T1;
    if (count == n) return nullptr;
    T1 = new BiNode<T>;
    T1.data = x;
    T1.lchild = Creat_all(x,n);
    T1.rchild = Creat_all(x,n);
}    //建立一个二叉树


template<typename T>
BiNode<T>* _copy1(BiNode<T>* bt){
    if(bt == nullptr) return nullptr;
    BiNode<T>* temp = new BiNode<T>;
    temp->data = bt->data;
    temp->lchild = _copy(bt->lchild);
    temp->rchild = _copy(bt->rchild);
    return temp;
}

template<typename T>
Bitree<T>& Bitree<T>:: operator=(const Bitree<T>& T1){
    root = _copy1(T1.root);
} 



