#include <iostream>
using namespace std;

#ifndef ARR_HPP
#define ARR_HPP

template <typename X>
class Stack{
    int top;
    int size;
    int num_chunk;
    X * dynamic_arr;
    void increment_size(){
        X arr[size];
        for(int i = 0; i < size; i++){
            arr[i] = dynamic_arr[i];
        }
        delete[] dynamic_arr;

        num_chunk++;
        dynamic_arr = new X[num_chunk * size];

        for(int i = 0; i < ((num_chunk - 1) * size); i++){
            dynamic_arr[i] = arr[i];
        }
    }

public:
    // keeping the default constructor just in case
    Stack(){
        size = 10;
        num_chunk = 1;
        dynamic_arr = new X[size];
        top = 0;
    }

    void print_stack(){
        cout << "This is the current stack:" << endl;
        cout << "<";
        for(int i = 0; i < top; i++){
            if(i != top - 1){
                cout << dynamic_arr[i] << ", ";
            }
            else{
                cout << dynamic_arr[i];
            }
            
        }
        cout << ">" << endl;
    }

    Stack(int elem_num, int size){
        if(elem_num > size){
            cout << "Error: Invalid Input" << endl;
            return;
        }
        dynamic_arr = new X[size];
        for(int i = 0; i < elem_num; i++){
            cin >> dynamic_arr[i];
        }
        top = elem_num;
        this->size = size;
        num_chunk = 1;
        print_stack();
    }

    void clear(){
        if(top == 0){
            cout << "Error Message: Can't clear any element from an empty stack!" << endl;
        }
        top = 0;
        //delete[] dynamic_arr;
        //dynamic_arr = new X[size];
        //num_chunk = 1;
    }

    void push(X item){
        if(top == size){
            increment_size();
        }
        dynamic_arr[top++] = item;
        //cout << "Gets Called!!" << endl;
    }

    X pop(){
        if(top == 0){
            cout << "Error Message: Can't Pop any element from an empty stack!" << endl;
            return X();
        }

        return dynamic_arr[--top];
    }

    int length(){
        return top;
    }

    X topValue(){
        if(top == 0){
            cout << "Your Stack is empty!!!" << endl;
            return X();
        }
        return dynamic_arr[top - 1];
    }

    bool isEmpty(){
        if(top == 0) return true;
        else return false;
    }

    ~Stack(){
        delete[] dynamic_arr;
    }

};



#endif
