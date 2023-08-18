#include <iostream>
#include "Stack.h"

using namespace std;

int main(){
    Stack<int> stack;

    string str; cin >> str;

    int count = 0;
    int max_count = 0; 
    

    for(int i = 0; i < str.size(); i++){
        if(str[i] == '('){
            stack.push(i);
        }

        else if(str[i] == ')'){
            if(!stack.isEmpty()){
                int last_occurance = stack.pop();
                count = i - last_occurance - 1;
                max_count = max(max_count, count);
            }
            else continue;
        }

        
    }

    cout << max_count << endl;

    
        
}