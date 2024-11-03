#include "linked_list.h"

int main() {

    List342<int> test;

    int a = 4;
    int b = 2;
    int c = 7;

    test.Insert(&a);
    test.Insert(&b);
    test.Insert(&c);

    cout << test << endl; 
}