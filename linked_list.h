#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_
#include <iostream>
#include <string>

using namespace std;

template <class T>
struct Node {
    Node *link = nullptr;
    T* value = 0;
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
    ifstream in_file;
    Node<T> temp = new Node<T>();


}

template <class T>
bool List342<T>::Insert(T *obj) {
    Node *insert_node = new Node;
    insert_node->value = *obj;
    
    if (head_ == nullptr) {
        head_ = new Node;
        head_->value = *obj; 
        return true;
    }
    
    Node<T> *next_node = head_; //traversal nodes dont need to be dynamically allocated

    for (int i = 0; i < size(); i++) {
        if ((next_node->link->value > insert_node->value) && (next_node->link != nullptr)) {
            insert_node->link = next_node->link;
            next_node->link = insert_node;
            size_++;
            //NEED TO CHECK IS LINK IS NULL

            return true;
        } else if (next_node->value == insert_node->value) {
            insert_node = nullptr;
            delete insert_node;
            return false;
        }
    }
    cout << "Failed to insert " << *obj << endl;
    return false;
}
template <class T>
bool List342<T>::ClearNode(Node<T> *clear_node) {
    clear_node = nullptr;
    delete clear_node;
    return true;
}

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
    Node<T> *next_node = new Node<T>;
    next_node = print_list.head_;

    for (int i = 0; i < print_list.size(); i++) {
        stream << next_node->value;
        next_node = next_node->link;
    }
    next_node = nullptr;
    delete next_node;
    return stream;
}

#endif
