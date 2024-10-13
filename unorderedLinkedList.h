#ifndef H_UnorderedLinkedList
#define H_UnorderedLinkedList
#include "linkedList.h"

template <class Type>
class unorderedLinkedList : public linkedListType<Type> {
public:
    bool search(const Type& searchItem) const;
    void insertFirst(const Type& newItem);
    void insertLast(const Type& newItem);
    void deleteNode(const Type& deleteItem);
};

template <class Type>
bool unorderedLinkedList<Type>::search(const Type& searchItem) const {
    nodeType<Type>* current = this->first; // Start with the first node
    while (current != nullptr) {
        if (current->info == searchItem)
            return true; // Item found
        current = current->link; // Move to next node
    }
    return false; // Item not found
}

template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type& newItem) {
    nodeType<Type>* newNode = new nodeType<Type>; // Create new node
    newNode->info = newItem; // Set data
    newNode->link = this->first; // Link to old first
    this->first = newNode; // Update first
    if (this->last == nullptr)
        this->last = newNode; // Update last if list was empty
    this->count++; // Increment count
}

template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type& newItem) {
    nodeType<Type>* newNode = new nodeType<Type>; // Create new node
    newNode->info = newItem; // Set data
    newNode->link = nullptr; // Link to null
    if (this->first == nullptr) { // If the list is empty
        this->first = newNode;
        this->last = newNode; // Update last
    }
    else {
        this->last->link = newNode; // Link the old last to new node
        this->last = newNode; // Update last
    }
    this->count++; // Increment count
}

template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem) {
    nodeType<Type>* current = this->first; // Pointer to traverse the list
    nodeType<Type>* trailCurrent = nullptr; // Pointer to previous node
    bool found = false;

    // Case 1: The list is empty
    if (this->first == nullptr) {
        std::cout << "Cannot delete from an empty list." << std::endl;
        return;
    }

    // Case 2: The item is in the first node
    if (this->first->info == deleteItem) {
        current = this->first;
        this->first = this->first->link; // Update first
        this->count--; // Decrease count
        if (this->first == nullptr) // If the list is now empty
            this->last = nullptr;
        delete current; // Delete node
        return;
    }

    // Search for the node to delete
    trailCurrent = this->first;
    current = this->first->link;
    while (current != nullptr && !found) {
        if (current->info != deleteItem) {
            trailCurrent = current;
            current = current->link; // Move to next node
        }
        else {
            found = true; // Item found
        }
    }

    // Case 3: If found, delete the node
    if (found) {
        trailCurrent->link = current->link; // Bypass current
        this->count--; // Decrease count
        if (this->last == current) // Update last if needed
            this->last = trailCurrent;
        delete current; // Delete the node
    }
    else {
        std::cout << "The item to be deleted is not in the list." << std::endl;
    }
}

#endif
