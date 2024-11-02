#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_
#include <string>
#include <iostream>

using namespace std;

template<class T>
struct Node{
    Node* link = nullptr;
    T value; = 0; 
    
};

template <class T>
class List342{

    public: 
    
    //constructors
    List342();

    //deconstructor
    ~List342();

    //takes input from a file and builds list
    bool BuildList(string file_name);

    bool Insert(T* obj);

    bool Remove(T target, T& result);

    //finds and returns a T object
    bool Peek(T target, T& result) const; 

    //getters and setters
    int size() const; 

//deletes list and deallocates all memmory, 
    void DeleteList(); //probably uses Remove()

    //merges 2 lists, deletes list1
    bool Merge(List342& list1); //definetely uses DeleteList()

    //operator overloads
    List342& operator+=(const List342 &other); 

    List342 operator+(const List342 &other) const;

    friend ostream& operator<<(ostream& stream, const List342& print_list) const; 

    bool operator==(const List342 &other) const; 

    List342& operator=(list342 &other); // needs to dcall DeleteList(); 


    private:

    //private method to Sort list
    //bool Sort(Node* insert_node); 

    //checks to see if a T objct is in the list. 
    bool Contains(const T* obj) const; 

    Node head_; 
    Node tail_; 
    unsigned int size_; 



};
#endif

