#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_
#include <fstream>
#include <iostream>
#include <string>

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

    void Print();

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
    bool Merge(List342 &list1); // definetely uses DeleteList() //O(n) CANNOT ALLOCATE MEMMORY

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
List342<T>::~List342() {
    for (Node<T> *next_node = head_; next_node != nullptr; next_node = next_node->link) {
        Node<T> *temp_node = next_node;
       ClearNode(temp_node);
       // delete temp_node->value;
        //delete temp_node;
    }
}


template <class T>
List342<T>::List342() : head_(nullptr) {
}



template <class T>
bool List342<T>::BuildList(string file_name) {

    ifstream in_file;
    in_file.open(file_name);

    if (!in_file) {
        return false;
        cerr << "File not oppened\n";
    }
    T new_obj;

    while (!in_file.eof()) {

        in_file >> new_obj;

        Insert(&new_obj);
    }
    in_file.close();
    return true;
}

template <class T>
bool List342<T>::Insert(T *obj) {
    Node<T> *insert_node = new Node<T>;
    insert_node->value = new T(*obj);

    // empty list
    if (head_ == nullptr) {
        head_ = insert_node;
        head_->link = nullptr;
        return true;
    }
    if ((*head_->value) > *(insert_node->value)) {
        insert_node->link = head_;
        head_ = insert_node;
        size_++;
        return true;
    }

    for (Node<T> *next_node = head_; next_node != nullptr; next_node = next_node->link) {

        // if equal
        if (*(next_node->value) == *(insert_node->value)) {
            delete insert_node->value;
            delete insert_node;
            return false;
        }
        // end of list
        if (next_node->link == nullptr) {
            next_node->link = insert_node;
            insert_node->link = nullptr;
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
    delete insert_node->value;
    delete insert_node;
    return false;
}
template <class T>
bool List342<T>::Remove(T target, T &result) {

    // if empty
    if (head_ == nullptr) {
        cerr << "List is empty. Failed to remove " << target << "\n";
        return false;
    }

    // if head is the target, logic is slightly different because the
    // head needs to be moved.
    if ((*(head_->value) == target)) {
        result = *(head_->value);
        Node<T> *temp_head = head_;
        head_ = head_->link;
        ClearNode(temp_head);
        size_--;
        return true;
    }

    for (Node<T> *next_node = head_; next_node != nullptr; next_node = next_node->link) {

        // if target is at the last node.
        if ((next_node->link == nullptr) && (*(next_node->value) == target)) {
            result = *(next_node->value);
            delete next_node->value; // no need to create a tempt node because no memmory leak
            delete next_node;        // occures do to deleting next_node.
            ClearNode(next_node);
            size_--;
            return true;
        }

        // middle
        if (*(next_node->link->value) == target) {
            // Save node as temp pointer, change links and then delete temp pointer
            Node<T> *temp_node = next_node->link;
            result = *(temp_node->value);
            next_node->link = next_node->link->link;
            ClearNode(temp_node);
            size_--;
            return true;
        }
    }
    cerr << "Target not found. Failed to remove " << target << "\n";
    return false;
}

template <class T>
bool List342<T>::Peek(T target, T &result) const {

    for (Node<T> *next_node = head_; next_node != nullptr; next_node = next_node->link) {

        // if middle or end
        if ((*(next_node->value) == target)) {
            result = *(next_node->value);
            return true;
        }
    }
    cerr << "Target not found: " << target << "\n";
    return false;
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
void List342<T>::DeleteList() {
}

template <class T>
ostream &operator<<(ostream &stream, const List342<T> &print_list) {

    for (Node<T> *next_node = print_list.head_; next_node != nullptr; next_node = next_node->link) {
        // cout << *(next_node->value) << endl;
        stream << *(next_node->value) << " ";
    }
    return stream;
}

template <class T>
inline void List342<T>::Print() {

    for (Node<T> *next_node = head_; next_node != nullptr; next_node = next_node->link) {
        cout << *(next_node->value) << endl;
    }
}

template <class T>
bool List342<T>::ClearNode(Node<T> *clear_node) {
    if (clear_node != nullptr) {
        delete clear_node->value;
        delete clear_node;
        //clear_node->value = nullptr;
        clear_node = nullptr;
        return true;
    }
    cerr << "Failed to Delete Node with value: " << *(clear_node->value) << "\n";
    return false;
}
#endif