#include <iostream>
#include "Stack.h"
#include <string>
using namespace std;







template <typename X>
void moveToDown(Stack<X> & st, X val){
    if(st.isEmpty()) st.push(val);
    else{
        int v = st.pop();
        moveToDown(st, val);
        st.push(v);
    }
}


template <typename X>
void reverseStack(Stack<X>& st){
    if(st.isEmpty()) return;
    X val = st.pop();
    reverseStack(st);
    moveToDown(st, val);
}

int main()
{
    Stack<int> stack;
    for(int i = 0; i < 10; i++){
        stack.push(i + 1);
    }
    stack.print_stack();
    reverseStack(stack);
    stack.print_stack();
}