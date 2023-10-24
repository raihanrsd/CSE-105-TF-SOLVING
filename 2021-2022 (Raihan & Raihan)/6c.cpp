#include <iostream>
#include <queue>

using namespace std;

template <typename X>
class Stack{
    queue <X> q;
    int s;

    public:

    Stack(){
        s = 0;
    }

    void push(X item){
        q.push(item); // similar to q.enqueue();
        s++;
    }

    X pop(){
        if(s == 0){
            cout << "Nothing to pop" << endl;
            return X();
        }

        for(int i = 0; i < s - 1; i++){
            X item = q.pop(); // write q.dequeue() in your answer script
            q.push(item);
        }
        X item = q.front();
        q.pop();
        s--;
        return item;
    }

    int size() const{
        return s;
    }

    int top() const{
        return q.back();
    }


};