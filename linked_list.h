#ifndef nextED_LIST_H_
#define nextED_LIST_H_
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

template <class T>
struct Node {
    Node<T> *next = nullptr;
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
    bool Merge(List342 &list1); // definetely uses DeleteList() //O(n) CANNOT ALLOCATE MEMMORY

    // operator overloads
    List342 &operator+=(const List342 &other); // O(n) x+= b , x = x  +b

    List342 operator+(const List342 &other) const; // O(n) //c = x + b 

    template <typename U>
    friend ostream &operator<<(ostream &stream, const List342<U> &print_list);

    bool operator==(const List342 &other) const;

    List342<T> &operator=(List342<T> &other); // needs to dcall DeleteList();

private:
    bool ClearNode(Node<T> *clear_node);

    Node<T> *head_;
    unsigned int size_;
};

template <class T>
List342<T>::List342() : head_(nullptr) {
}

template <class T>
List342<T>::~List342() {
    DeleteList();
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
        head_->next = nullptr;
        return true;
    }
    if ((*head_->value) > *(insert_node->value)) {
        insert_node->next = head_;
        head_ = insert_node;
        size_++;
        return true;
    }

    for (Node<T> *current_node = head_; current_node != nullptr; current_node = current_node->next) {

        // if equal
        if (*(current_node->value) == *(insert_node->value)) {
            delete insert_node->value;
            delete insert_node;
            return false;
        }
        // end of list
        if (current_node->next == nullptr) {
            current_node->next = insert_node;
            insert_node->next = nullptr;
            size_++;
            return true;
        }

        // middle of list
        if (*(current_node->next->value) > *(insert_node->value)) {
            insert_node->next = current_node->next;
            current_node->next = insert_node;
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
        head_ = head_->next;
        ClearNode(temp_head);
        size_--;
        return true;
    }

    for (Node<T> *current_node = head_; current_node != nullptr; current_node = current_node->next) {

        // if target is at the last node.
        if ((current_node->next == nullptr) && (*(current_node->value) == target)) {
            result = *(current_node->value);
            delete current_node->value; // no need to create a tempt node because no memmory leak
            delete current_node;        // occures do to deleting current_node.
            ClearNode(current_node);
            size_--;
            return true;
        }

        // middle
        if (*(current_node->next->value) == target) {
            // Save node as temp pointer, change nexts and then delete temp pointer
            Node<T> *temp_node = current_node->next;
            result = *(temp_node->value);
            current_node->next = current_node->next->next;
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

    for (Node<T> *current_node = head_; current_node != nullptr; current_node = current_node->next) {

        // if middle or end
        if ((*(current_node->value) == target)) {
            result = *(current_node->value);
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

/*
template <class T>
void List342<T>::DeleteList() {
    cout << "here1" << endl;

    for (Node<T> *current_node = head_; current_node != nullptr; current_node = current_node->next) {

        //save node after current_node to not lose the list.
        Node<T> *temp_node = current_node->next; //curent gets deleted

        //clear the node before temp_node. 
        ClearNode(current_node);
    }
}
*/

template <class T>
void List342<T>::DeleteList(){
    Node<T>* current_node = head_;
    while(current_node != nullptr){
        Node<T>* temp_node = current_node;
        current_node = current_node->next;
        delete temp_node->value;
        delete temp_node;
    }
    head_ = nullptr;
}



template <class T>
ostream &operator<<(ostream &stream, const List342<T> &print_list) {

    for (Node<T> *current_node = print_list.head_; current_node != nullptr; current_node = current_node->next) {
        stream << *(current_node->value) << " ";
    }
    return stream;
}

template <class T>
List342<T> &List342<T>::operator=(List342<T> &other) {
    if(this!= &other){
        DeleteList();
        *(head_->data) = *(other.head_);
        for(Node<T> current_node = head_->next; current_node != nullptr; current_node->next){
            *(current_node->data) = *(other_node->data)
        }

    }

}

template <class T>
bool List342<T>::ClearNode(Node<T> *clear_node) {
    // cout << "here" << endl;
    cout << *(clear_node->value) << endl;

    if (clear_node != nullptr) {
        delete clear_node->value;
        delete clear_node;
        return true;
    }
    cerr << "Failed to Delete Node with value: " << *(clear_node->value) << "\n";
    return false;
}
#endif