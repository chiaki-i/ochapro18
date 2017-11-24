#include<iostream>
#include<stdexcept>

#define SIZE 10

template <class T> class Stack{
public:
    T stack[SIZE];
    int top;
    
    // initialization
    Stack(){
        top = 0;
    }

    void push(T item){ // 一番上からデータを削除する
        if (top == SIZE) {
            std::cout << "Stack if Full. \n";
            return;
        }
        stack[top] = item;
        top++;
    }

    T pop(){ // 一番上に要素 item を追加する
        if (top == 0) {
            std::cout << "Stack is Empty. \n";
            return 0; //
        }
        top--;
        return stack[top];
    }

    void peek(){ // 一番上の要素を返す
        if (top == 0){
            std::cout << "Stack is Empty. \n";
            return;
        }
        return stack[top];
    }

    bool isEmpty(){ // スタックが空の場合に true を返す
        if (top == 0){
            return true;
        } else {
            return false;
        }
    }
};

template <class T> class Queue{
public:
    void add(T item); // 要素をリストの最後に追加する
    T remove(); // 先頭の要素を削除する
    T peek(); // 先頭の要素を返す
    bool isEmpty(); // 空の場合のみtrueを返す
}

    
void stacktest(){
    Stack<int> s1, s2;

    s1.push(7);
    s1.push(4);
    s1.push(6);
    
    s2.push(8);
    s2.push(2);
    s2.push(0);
    s2.push(5);

    std::cout << std::boolalpha;
    std::cout << s1.isEmpty() << std::endl;
    for(int i = 0; i < 3; i++) std::cout << "s1 pop! " << s1.pop() << std::endl;
    std::cout << s1.isEmpty() << std::endl;
    
    std::cout << s2.isEmpty() << std::endl;
    for(int i = 0; i < 4; i++) std::cout << "s2 pop! " << s2.pop() << std::endl;
    std::cout << s2.isEmpty() << std::endl;
}

int main(){
    stacktest();
}
