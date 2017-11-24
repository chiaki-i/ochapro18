#include<iostream>
#define SIZE 10

template <class T> class Stack{
public:
    T stack[SIZE];
    int top;
    
    Stack(){
        top = 0;
    }

    void push(T item){ // 一番上にデータ item を追加する
        if (top == SIZE) {
            std::cout << "Stack is full" << std::endl;
            throw FullStackException();
            // 連結リストを使った場合は新しいノードを加えるだけなのでこの例外は不要になります
        }
        stack[top] = item;
        top++;
    }

    T pop(){ // 一番上からデータを削除する
        if (top == 0) {
            std::cout << "Stack is empty" << std::endl;
            throw EmptyStackException();
        }
        top--;
        return stack[top];
    }

    T peek(){ // 一番上のデータを返す
        if (top == 0){
            std::cout << "Stack is empty" << std::endl;
            throw EmptyStackException();
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

    class EmptyStackException{
    };

    class FullStackException{
    };
};
    
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

    std::cout << s2.peek() << std::endl; // 例外
}

int main(){
    stacktest();
}
