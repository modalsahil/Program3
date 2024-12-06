#include <string>
#include <iostream>
using namespace std;

template <typename T>
int removeItem(T arr[], int length, T item) {
    int newLength = 0;
    for (int i = 0; i < length; ++i) {
        if (arr[i] != item) {
            arr[newLength++] = arr[i];
        }
    }
    return newLength;
}


int main() {

    int arr[4];

    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 2;
    arr[3] = 4;

    int x = removeItem(arr, 4, 2);

    for (int i = 0; i < x; i++){
        cout << arr[i] << endl; 
    }
}