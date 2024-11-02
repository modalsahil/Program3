#include "linked_list.h"

using namespace std;

int main() {
}

template <class T>
List342<T>::List342() : head_(nullptr), tail_(nullptr) {
}

template <class T>
bool List342<T>::Insert(T *obj) {
    Node insert_node = new Node();
    insert_node.value = obj;

    Node next_node = head_;

    for (int i = 0; i < size(); i++) {
        if (next_node.value > insert_node.value) {
            next_node.link = insert_node;
            insert_node.link = next_
        } else {
            next_node = next_node.link;
        }
    }
    size++; 
}

template <class T>
int List342<T>::size() const {
    return size;
}