#include "Tree.h"
#include "IndexCard.h"
#include <iostream>

int main() {
    Tree<IndexCard> deck;

    deck.insert(IndexCard(2, "ML", "Machine Learning applications"));
    deck.insert(IndexCard(1, "AI", "Artificial Intelligence basics"));
    deck.insert(IndexCard(3, "DS", "Data Structures notes"));

    std::cout << "Inorder Traversal (by ID):\n";
    deck.inorder();

    int searchId;
    std::cout << "\nEnter ID to search: ";
    std::cin >> searchId;

    try {
        IndexCard found = deck.find(IndexCard(searchId, "", ""));
        std::cout << "Found: " << found << "\n";
    } catch (std::runtime_error& e) {
        std::cout << e.what() << "\n";
    }

    return 0;
}
