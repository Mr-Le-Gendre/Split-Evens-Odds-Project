#ifndef H_IntLinkedList
#define H_IntLinkedList

#include "unorderedLinkedList.h"
using namespace std;

template <class Type>
class intLinkedList : public unorderedLinkedList<Type> {
public:
    void splitEvensOdds(intLinkedList<Type>& evens, intLinkedList<Type>& odds);
};

template <class Type>
void intLinkedList<Type>::splitEvensOdds(intLinkedList<Type>& evens, intLinkedList<Type>& odds) {
    nodeType<Type>* current = this->first;
    while (current != nullptr) {
        if (current->info % 2 == 0) {
            evens.insertLast(current->info);
        }
        else {
            odds.insertLast(current->info);
        }
        current = current->link;
    }
    // Clear the original list after splitting
    this->first = nullptr;
    this->last = nullptr;
    this->count = 0;
}

#endif
