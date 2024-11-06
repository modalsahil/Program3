#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

template <class T>
struct Node {
    Node<T> *link = nullptr;
    T *value = 0;
};

template <class T>
class List342 {

public:
    // constructors
    List342();

    // deconstructor
    ~List342();

    // takes input from a file and builds list
    bool BuildList(string file_name);

    bool Insert(T *obj);

    bool Remove(T target, T &result);

    // finds and returns a T object
    bool Peek(T target, T &result) const;

    // getters and setters
    int size() const;

    Node<T> &head() const;

    // deletes list and deallocates all memmory,
    void DeleteList(); // probably uses Remove()

    // merges 2 lists, deletes list1
    bool Merge(List342 &list1); // definetely uses DeleteList() //O(n)

    // operator overloads
    List342 &operator+=(const List342 &other); // O(n)

    List342 operator+(const List342 &other) const; // O(n)

    template <typename U>
    friend ostream &operator<<(ostream &stream, const List342<U> &print_list);

    bool operator==(const List342 &other) const;

    List342 &operator=(List342 &other); // needs to dcall DeleteList();

private:
    // private method to Sort list
    // bool Sort(Node* insert_node);

    // checks to see if a T objct is in the list.
    bool ClearNode(Node<T> *clear_node);
    bool Contains(const T *obj) const;

    Node<T> *head_;
    unsigned int size_;
};

template <class T>
List342<T>::List342() : head_(nullptr) {
}

template <class T>
List342<T>::~List342() {
}

template <class T>
bool List342<T>::BuildList(string file_name) {

    ifstream in_file(file_name);
    //in_file.open(file_name);
    while (!in_file.eof()) {
        T new_obj; 
        in_file >> new_obj;
         cout << new_obj << endl;

        Insert(new_obj);
    }
    in_file.close();
    return true;
}

template <class T>
bool List342<T>::Insert(T *obj) {
    cout << *obj << endl; 
    Node<T> *insert_node = new Node<T>;
    insert_node->value = obj;

    // empty list
    if (head_ == nullptr) {
        head_ = insert_node;
        head_->link = nullptr;
        return true;
    }

    for (Node<T> *next_node = head_; next_node != nullptr; next_node = next_node->link) {

        // end of list
        if (next_node->link == nullptr) {
            next_node->link = insert_node;
            insert_node->link = nullptr;
            size_++;
            return true;
        }

        if (*(next_node->value) == *(insert_node->value)) {
            insert_node = nullptr;
            delete insert_node;
            return false;
        }

        // if insert_node needs to be put at front
        if ((*head_->value) > *(insert_node->value)) {
            insert_node->link = head_;
            head_ = insert_node;
            size_++;
            return true;
        }

        // middle of list
        if (*(next_node->link->value) > *(insert_node->value)) {
            insert_node->link = next_node->link;
            next_node->link = insert_node;
            size_++;
            return true;
        }
    }

    cout << "Failed to insert " << *obj << endl;
    return false;
}
/*
template <class T>
bool List342<T>::ClearNode(Node<T> *clear_node) {
    clear_node = nullptr;
    delete clear_node;
    return true;
}
*/

template <class T>
int List342<T>::size() const {
    return size_;
}

template <class T>
Node<T> &List342<T>::head() const {
    return *head_;
}

template <class T>
ostream &operator<<(ostream &stream, const List342<T> &print_list) {

    for (Node<T> *next_node = print_list.head_; next_node != nullptr; next_node = next_node->link) {
        stream << *(next_node->value) << " ";
    }
    return stream;
}

#endif
