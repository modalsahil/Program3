#include "linked_list.h"

int main() {

    List342<int> test4;

    int b1 = 42;
    int b2 = 17;
    int b3 = 63;
    int b4 = 9;
    int b5 = 88;
    int b6 = 29;
    int b7 = 54;
    int b8 = 76;
    int b9 = 31;

    test4.Insert(&b1);
    test4.Insert(&b2);
    test4.Insert(&b3);
    test4.Insert(&b4);
    test4.Insert(&b5);
    test4.Insert(&b6);
    test4.Insert(&b7);
    test4.Insert(&b8);
    test4.Insert(&b9);

    cout << test4 << endl;

    
}