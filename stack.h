#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Badfull{};
class Badempty{};
template<typename T>
class stack{
    public:
        stack():top{-1},elem{nullptr},capacity{0}{

        }
        stack(int size):top{-1},elem{new T[size]},capacity{size}{

        }
        //~stack(){
            //delete[] elem;
        //}
        int top;
        int capacity;
        T* elem;
};

template <typename T>
bool isFull(stack<T>);
template <typename T>
bool isEmpty(stack<T>);
template <typename T>
stack<T> Initstack(stack<T>);
template <typename T>
void Clear(stack<T>&);
template <typename T>
T Top(stack<T>&); 
template <typename T>            //稍会做模板化处理
void Push(stack<T>&,T);
template <typename T>
void Pop(stack<T>&);



template <typename T>
bool isFull(stack<T> s){
    if(s.top == s.capacity - 1){
        return true;
    }
    return false;
}

template <typename T>
bool isEmpty(stack<T> s){
    if (s.top == -1){
        return true;
    }
    return false;
}

template <typename T>
stack<T> Initstack(stack<T> s){
    delete[] s.elem;
    s.top = -1;
    s.capacity = 0;
    s.elem = new double[100];
    return s;
}

template <typename T>
void Clear(stack<T>& s){
    while(s.top != -1){
        Pop(s);
    }
}

template <typename T>
T Top(stack<T>& s){
    return s.elem[s.top];
}

template <typename T>
void Push(stack<T>& s,T x){
    if(isFull(s) == true){
        throw Badfull{};
    }
    s.top += 1;
    s.elem[s.top] = x;
}
template <typename T>
void Pop(stack<T>& s){
    if(isEmpty(s) == true){
        throw Badempty{};
    }
    s.top -= 1;
    //s.elem[s.top+1] = 0;
}
