#include <iostream>
#include "Kstack.h"

using namespace std;

int main(){
    Kstack<int> kstack;

    int n; cin >> n;

    while(n!=0){
        if (n == 1){
            int tmp; cin >> tmp;
            kstack.push1(tmp);
            kstack.print_stack();
        }
        else if (n == 2){
            int tmp; cin >> tmp;
            kstack.push2(tmp);
            kstack.print_stack();
        }
        else if (n == 3){
            kstack.pop1();
            kstack.print_stack();
        }
        else if(n == 4){
            kstack.pop2();
            kstack.print_stack();
        }
        cin >> n;
    }
}