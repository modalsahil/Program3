#include "linked_list.h"

int main() {

    List342<int> test;

    int a = 4;
    int b = 5;
    int c = 7;
    int d = 6;
    int e = 1;

    int f = 6;

    int g = 2;
    int h = 8;
    int i = 3;

    test.Insert(&a);
    test.Insert(&b);
    test.Insert(&c);
    test.Insert(&d);
    test.Insert(&e);
    test.Insert(&d);
    test.Insert(&f);
    test.Insert(&g);
    test.Insert(&h);
    test.Insert(&i);

    cout << test << endl;

    List342<int> test2;
    test2.BuildList("build_list.txt");

    cout << test2 << endl;

}