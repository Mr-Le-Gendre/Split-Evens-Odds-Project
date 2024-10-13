#include <iostream>
#include "unorderedLinkedList.h"

void splitEvensOdds(unorderedLinkedList<int>& list, unorderedLinkedList<int>& evens, unorderedLinkedList<int>& odds) {
    nodeType<int>* current = list.getFirst(); // Access first node
    while (current != nullptr) {
        if (current->info % 2 == 0) {
            evens.insertLast(current->info); // Insert even numbers
        }
        else {
            odds.insertLast(current->info); // Insert odd numbers
        }
        current = current->link; // Move to the next node
    }
    list.deleteList(); // Clear the original list
}

int main() {
    unorderedLinkedList<int> list; // Original list
    unorderedLinkedList<int> evens; // Even numbers list
    unorderedLinkedList<int> odds; // Odd numbers list

    // Sample input
    list.insertLast(10);
    list.insertLast(15);
    list.insertLast(20);
    list.insertLast(25);
    list.insertLast(30);

    splitEvensOdds(list, evens, odds); // Split into evens and odds

    // Display the results
    std::cout << "Evens: ";
    for (nodeType<int>* current = evens.getFirst(); current != nullptr; current = current->link) {
        std::cout << current->info << " "; // Print even numbers
    }
    std::cout << std::endl;

    std::cout << "Odds: ";
    for (nodeType<int>* current = odds.getFirst(); current != nullptr; current = current->link) {
        std::cout << current->info << " "; // Print odd numbers
    }
    std::cout << std::endl;

    return 0;
}
