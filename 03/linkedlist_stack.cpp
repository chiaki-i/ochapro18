#include<iostream>
// compile with option -std=c++11

template <typename StackType> class Stack {
private:
    struct StackNode{
        StackType data;
        StackNode *next;

        StackNode(StackType &&d, StackNode *n) : data(std::move(d)),
                                                 next(n){
        }

        // やってることは以下とほぼ同じ, 上の方が効率が良い
        // StackNode(StackType &&d, StackNode *n){
        //     data = std::move(d);
        //     next = n;
        // }
    };
    
    StackNode *top;
    int stackSize;
    
public:   
    Stack() : top(nullptr), stackSize(0){
    }

    ~Stack(){
        while (!isEmpty()) pop();
    }

    template <typename ItemType>
    void push(ItemType &&data){
        auto n = new StackNode(std::forward<ItemType>(data), top);
        top = n;
        ++stackSize;
    }

    StackType &peek(){ // 参照型を返した方が効率が良い. コピーを避けたい. 
        if (!top)
            throw StackIsEmptyException();
        return top->data;
    }

    StackType pop(){
        if (!top)
            throw StackIsEmptyException();
        
        auto data = std::move(top->data);
        // これは下と同じ雰囲気. 参照元も破棄する
        // auto data = top->data;
        // top->data = nullptr; // しかし,ここで怒られる nullptr_t型とぶつかる 
        
        auto n = top; // popするものを退避
        top = n->next; // 新しいtop
        delete n; // 古いものを消す
        --stackSize;
        return data;
    }

    bool isEmpty(){
        return !top;
    }

    int size(){
        return stackSize;
    }

    class StackIsEmptyException{
    };
};

void testStack(){
    Stack<int> s1;

    std::cout << "testing..." << std::endl;
    s1.push(3);
    s1.push(8);
    s1.push(4);

    std::cout << std::boolalpha;
    std::cout << s1.isEmpty() << std::endl;
    for(int i = 0; i < 3; i++) std::cout << "s1 pop! " << s1.pop() << std::endl;
    std::cout << s1.isEmpty() << std::endl;
}

int main(){
    testStack();
}
