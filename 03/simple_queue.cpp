#include <iostream>
#define SIZE 10

template <class T> class Queue{
public:
    T queue[SIZE];
    int first, last;

    Queue(){
        first = 0;
        last = 0;
    }

    void add(T item){ // 要素をリストの最後に追加する
        if (last + 1 == first || (last + 1 == SIZE && !first)){
            std::cout << "Queue is full" << std::endl;
            throw QueueIsFullException();
            // 連結リストを使った場合は新しいノードを加えるだけなのでこの例外は不要になります
        }
        last++;
        if (last==SIZE) last = 0; // 循環する
        queue[last] = item;
    }

    T remove(){ // 先頭の要素を削除する
        if (first == last){
            std::cout << "Queue is empty" << std::endl;
            throw NoSuchElementException();
        }
        first++;
        if (first == SIZE) first = 0; // 循環する
        return queue[first];
    }

    T peek(){ // 先頭の要素を返す
        if (first == last){
            std::cout << "Queue is empty" << std::endl;
            throw NoSuchElementException();
        }
        return queue[first];
    }

    bool isEmpty(){ // キューが空のときtrue を返す
        if (first == last){
            return true;
        } else {
            return false;
        }
    }

    class NoSuchElementException{
    };

    class QueueIsFullException{
    };
};

void queuetest(){
    Queue<int> q1, q2;

    q1.add(7);
    q1.add(4);
    q1.add(6);
    
    q2.add(8);
    q2.add(2);
    q2.add(0);
    q2.add(5);

    std::cout << std::boolalpha;
    std::cout << q1.isEmpty() << std::endl;
    for(int i = 0; i < 3; i++) std::cout << "remove q1: " << q1.remove() << std::endl;
    std::cout << q1.isEmpty() << std::endl;
    
    std::cout << q2.isEmpty() << std::endl;
    for(int i = 0; i < 4; i++) std::cout << "remove q2: " << q2.remove() << std::endl;
    std::cout << q2.isEmpty() << std::endl;

    std::cout << q2.peek() << std::endl; // 例外

}

int main(){
    queuetest();
}



