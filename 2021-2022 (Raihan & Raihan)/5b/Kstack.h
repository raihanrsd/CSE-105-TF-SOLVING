#include <iostream>
using namespace std;

#define DEFAULT_SIZE 10

#ifndef Kstack_H
#define Kstack_H

template <typename X>
class Kstack{
    int top1;
    int top2;
    int size;
    
    X * dynamic_arr;

    // main trick is over here 
    void increment_size(){
        X arr[size];
        for(int i = 0; i < size; i++){
            arr[i] = dynamic_arr[i];
        }
        delete[] dynamic_arr;
        int prev_size = size;
        size *= 2;
        top2 += prev_size; // important line


        dynamic_arr = new X[size];

        for(int i = 0; i < top1; i++){
            dynamic_arr[i] = arr[i];
        }
    
        int j = size - 1;
        while(j > top2){
            dynamic_arr[j--] = arr[prev_size--];
        }
    }

public:
    // keeping the default constructor just in case
    Kstack(){
        top1 = 0;
        top2 = DEFAULT_SIZE - 1;
        size = DEFAULT_SIZE;
        dynamic_arr = new X[size];
    }



    void print_stack(){
        cout << "This is the current stack 1:" << endl;
        for(int i =0 ; i < top1; i++){
            cout << dynamic_arr[i] << " ";
        }
        cout << endl;

        cout << "This is the current stack 2: " << endl;
        for(int i = size - 1; i > top2; i--){
            cout << dynamic_arr[i] << " ";
        }
        cout << endl;
    }

    void push1(X item){
        if(top1 == top2){
            increment_size();
        }
        dynamic_arr[top1++] = item;
    }

    void push2(X item){
        if(top1 == top2){
            increment_size();
        }

        dynamic_arr[top2--] = item;
    }

    X pop1(){
       if(top1 == 0){
        cout << "nothing to pop at Stack 1" << endl;
        return X();
       }



       --top1;
       return dynamic_arr[top1];
    }

    X pop2(){
        if(top2 == size - 1){
            cout << "nothing to pop at Stack 2" << endl;
            return X();
        }

        top2++;
        return dynamic_arr[top2];
    }

   

    
    ~Kstack(){
        delete[] dynamic_arr;
    }

};



#endif
