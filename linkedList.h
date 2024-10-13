#ifndef H_LinkedList
#define H_LinkedList

template <class Type>
struct nodeType {
    Type info;                   // Data item
    nodeType<Type>* link;       // Pointer to next node
};

template <class Type>
class linkedListType {
protected:
    nodeType<Type>* first;      // Pointer to the first node
    nodeType<Type>* last;       // Pointer to the last node
    int count;                  // Number of nodes in the list

public:
    linkedListType();           // Constructor
    ~linkedListType();          // Destructor

    bool isEmpty() const;       // Check if list is empty
    int getCount() const;       // Get number of nodes
    void deleteList();          // Delete the entire list

    // Accessor to get the first node (needed for splitting)
    nodeType<Type>* getFirst() const {
        return first;
    }
};

template <class Type>
linkedListType<Type>::linkedListType() {
    first = nullptr;
    last = nullptr;
    count = 0;
}

template <class Type>
linkedListType<Type>::~linkedListType() {
    deleteList();
}

template <class Type>
bool linkedListType<Type>::isEmpty() const {
    return (first == nullptr);
}

template <class Type>
int linkedListType<Type>::getCount() const {
    return count;
}

template <class Type>
void linkedListType<Type>::deleteList() {
    nodeType<Type>* temp;
    while (first != nullptr) {
        temp = first;
        first = first->link;
        delete temp;
    }
    last = nullptr;
    count = 0;
}

#endif
