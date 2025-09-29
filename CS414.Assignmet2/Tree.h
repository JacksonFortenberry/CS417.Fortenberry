#pragma once
#include <iostream>
#include <memory>
#include <stdexcept>

template <typename T>
class Tree {
private:
    struct Node {
        T data;
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;
        Node(const T& val) : data(val), left(nullptr), right(nullptr) {}
    };

    std::unique_ptr<Node> root;

    std::unique_ptr<Node> clone(const std::unique_ptr<Node>& node) {
        if (!node) return nullptr;
        auto newNode = std::make_unique<Node>(node->data);
        newNode->left = clone(node->left);
        newNode->right = clone(node->right);
        return newNode;
    }

    void insertHelper(std::unique_ptr<Node>& node, const T& key) {
        if (!node) {
            node = std::make_unique<Node>(key);
        } else if (key < node->data) {
            insertHelper(node->left, key);
        } else if (key > node->data) {
            insertHelper(node->right, key);
        }
    }

    T findHelper(const Node* node, const T& key) const {
        if (!node) throw std::runtime_error("Key not found");
        if (key == node->data) return node->data;
        if (key < node->data) return findHelper(node->left.get(), key);
        return findHelper(node->right.get(), key);
    }

    void inorderHelper(const Node* node) const {
        if (!node) return;
        inorderHelper(node->left.get());
        std::cout << node->data << "\n";
        inorderHelper(node->right.get());
    }

    void preorderHelper(const Node* node) const {
        if (!node) return;
        std::cout << node->data << "\n";
        preorderHelper(node->left.get());
        preorderHelper(node->right.get());
    }

    void postorderHelper(const Node* node) const {
        if (!node) return;
        postorderHelper(node->left.get());
        postorderHelper(node->right.get());
        std::cout << node->data << "\n";
    }

public:
    Tree() : root(nullptr) {}
    Tree(const T& value) { root = std::make_unique<Node>(value); }
    Tree(const Tree& other) { root = clone(other.root); }

    T find(const T& key) const { return findHelper(root.get(), key); }
    void insert(const T& key) { insertHelper(root, key); }

    void inorder() const { inorderHelper(root.get()); }
    void preorder() const { preorderHelper(root.get()); }
    void postorder() const { postorderHelper(root.get()); }
};
