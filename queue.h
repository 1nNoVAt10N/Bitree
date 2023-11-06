#include <iostream>
using namespace std;

class Bad_full{};
class Bad_empty{};
template <typename T>
class Queue{
    public:
        Queue():
            front{0},rear{0},capacity{100},elem{new T[100]}
            {

            }
        Queue(int n):
            front{0},rear{0},capacity{n+1},elem{new T[n+1]}{

            }
        ~Queue(){
            delete[] elem;
        }
        int front;
        int rear;
        int capacity;
        T* elem;
        bool isfull();
        bool isempty();
        void Enqueue(T x);
        T Getfront();
        void Dequeue();
    private:

};

template <typename T>
bool Queue<T>::isfull(){
    if ((rear + 1) % (capacity) == front){
        return true;
    }
    return false;
}


template <typename T>
bool Queue<T>::isempty(){
    if (rear == front){
        return true;
    }
    return false;
}

template <typename T>
void Queue<T>::Enqueue(T x){
    if (isfull()){
        cout << "队列已满" << endl;
        throw Bad_full{};
    }
    elem[rear] = x;
    rear = (rear + 1) % capacity;
}


template <typename T>
T Queue<T>::Getfront(){
    if (isempty()){
        cout << "队列空" << endl;
        throw Bad_empty{};
    }
    return elem[front];
}


template <typename T>
void Queue<T>::Dequeue(){
    if (isempty()){
        cout << "队列空" << endl;
        throw Bad_empty{};
    }
    front = (front + 1) % capacity;
}


