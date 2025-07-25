#ifndef BST_H
#define BST_H

//---------------------------------------------------------------------------------------

#include <iostream>

//---------------------------------------------------------------------------------------

/// A record acting as a node of the binary search tree, containing the actual data and
/// pointers to the left and right nodes
template <class T>
struct Node
{
    T data; /// The actual data in the node
    Node<T> * left; /// The pointer to the left subtree
    Node<T> * right; /// The pointer to the right subtree
};

//---------------------------------------------------------------------------------------

    /**
    * @class BST
    * @brief A Binary Search Tree (BST) class that stores elements in sorted order.
    *
    * This class implements a template-based Binary Search Tree using recursive operations
    * for insertion, searching, traversal, copying, and deleting.
    *
    * @author Nabeel
    * @version 01
    * @date 05/07/2025 Nabeel, Started
    *
    * @author Nabeel
    * @version 02
    * @date 16/07/2025 Nabeel, Changed Insert and Search to be recursive
    *
    * @author Nabeel
    * @version 03
    * @date 21/07/2025 Nabeel, Integrated function pointers to traversal methods
    *
    * @todo Nothing
    *
    * @bug No bugs so far
    */

template <class T>
class BST {
public:
    /**
    * @brief Construct a BST object.
    *
    * This constructor will construct a new object with root set to nullptr.
    *
    * @pre new object is initialized.
    * @post a vector object is created with with root set to nullptr.
    */
    BST();

    /**
    * @brief Construct a BST object by copying the values of another BST object.
    *
    * This constructor will overload the default constructor, passing a BST object. The passed object's data is copied
    * to the constructed object's, and creating a new tree on the heap that copies the data from the passed object's array.
    *
    * @param other - the BST object to be copied.
    * @pre other is a valid constructed BST object or nullptr.
    * @post a BST object is created data copied from other object, and m_root is set to other.m_root or nullptr.
    */
    BST(const BST<T> & other);

    /**
    * @brief Overloaded assignment operator for copying object data during assignment.
    *
    * This method overloads the assignment operator, copying the data in the other BST object into the assigned object.
    *
    * @param other - the BST object to be copied.
    * @return a reference to the assigned BST object.
    * @pre other is a valid constructed BST object or nullptr.
    * @post the assigned vector object's private members are copied from other object, and m_root is set to other.m_root or nullptr.
    */
    BST<T> & operator=(const BST<T> & other);

    /**
    * @brief Destructor for the BST object.
    *
    * This destructor will free the dynamically allocated memory on the heap and set the data of every node in the tree to nullptr.
    *
    * @pre the object is initialized.
    * @post memory for the root and every node in the tree is freed from the heap and set to nullptr.
    */
    ~BST();

    /**
    * @brief Insert a value into the BST.
    *
    * Adds a new value into the tree while maintaining BST ordering rules.
    *
    * @param val - the value to be added to the tree.
    * @return void
    * @pre val is a valid object of type T, and is not already present in the tree.
    * @post val is added to the tree if not already present in the the tree.
    */
    void Insert(const T & val);

    /**
    * @brief Search for a value in the BST.
    *
    * Checks whether a value exists in the BST.
    *
    * @param val - the value to be searched for in the tree.
    * @return true if the value exists, false if it doesn't.
    * @pre val is a valid object of type T.
    * @post The BST remains unchanged.
    */
    bool Search(const T & val);

    /**
    * @brief Perform in-order traversal using a function pointer callback.
    *
    * Traverses the BST in ascending order, calling the provided function on each node's data.
    *
    * @param fp - A function pointer to a callback that accepts a reference to a node's data of type T.
    * @return void
    * @pre The BST object must be fully constructed and initialized.
    * @post The callback function is called on each element in ascending order.
    */
    void InOrderTraversal(void (*fp)(const T &)) const;

    /**
    * @brief Perform pre-order traversal using a function pointer callback.
    *
    * Traverses the BST in pre-order sequence, calling the provided function on each node's data.
    *
    * @param fp - A function pointer to a callback that accepts a reference to a node's data of type T.
    * @return void
    * @pre The BST object must be fully constructed and initialized.
    * @post The callback function is called on each element in pre-order sequence.
    */
    void PreOrderTraversal(void (*fp)(const T &)) const;

    /**
    * @brief Perform post-order traversal using a function pointer callback.
    *
    * Traverses the BST in post-order sequence, calling the provided function on each node's data.
    *
    * @param fp - A function pointer to a callback that accepts a reference to a node's data of type T.
    * @return void
    * @pre The BST object must be fully constructed and initialized.
    * @post The callback function is called on each element in post-order sequence.
    */
    void PostOrderTraversal(void (*fp)(const T &)) const;

private:
    Node<T> * m_root; /// A pointer to the root of the Binary Search Tree.

    /**
    * @brief Copy an entire tree from another BST.
    *
    * Creates a deep copy of another BST into the calling object.
    *
    * @param other - The BST to be copied from.
    * @pre other is a valid constructred BST object.
    * @post The current BST is a deep copy of other.
    */
    void CopyTree(const BST<T> & other);

    /**
    * @brief Recursive helper to copy tree nodes.
    *
    * Recursively copies all nodes from another tree into this calling object's tree.
    *
    * @param thisNode - The destination node reference.
    * @param otherNode - The source node to copy.
    * @return void
    * @pre thisNode is a reference to a pointer, otherNode is a valid node or nullptr.
    * @post A new subtree is created at thisNode with the same structure and values as otherNode.
    */
    void Copy(Node<T> * & thisNode, Node<T> * otherNode);

    /**
    * @brief Recursive helper to delete all nodes in the tree.
    *
    * Frees memory allocated for all nodes starting from the given node.
    *
    * @param node - The root of the subtree to delete.
    * @return void
    * @pre node is a valid node or nullptr.
    * @post All nodes in the subtree are deleted from memory and set to nullptr.
    */
    void DeleteTree(Node<T> * & node);

    /**
    * @brief Recursive helper for insertion.
    *
    * Inserts a value into the correct position in the BST.
    *
    * @param node - Reference to the current node pointer.
    * @param val - The value to insert.
    * @pre node is a valid pointer reference, val is valid.
    * @post val is inserted into the correct position if not present.
    */
    void Insert(Node<T> * & node, const T & val);

    /**
    * @brief Recursive helper for search.
    *
    * Searches for a value in the tree.
    *
    * @param node - The current node to check.
    * @param val - The value to search for.
    * @return True if found, false if not.
    * @pre node is a valid node or nullptr.
    * @post The BST remains unmodified.
    */
    bool Search(Node<T> * node, const T & val) const;


    /**
    * @brief Recursive helper for in-order traversal.
    *
    * Recursively visits all nodes in ascending order and applies the callback function to each node's data.
    *
    * @param fp - A function pointer to a callback that accepts a reference to a node's data of type T.
    * @param node - The current node being visited.
    * @return void
    * @pre node is a valid node pointer or nullptr.
    * @post The callback function is called on each node in in-order sequence.
    */
    void InOrderTraversal(void (*fp)(const T &), Node<T> * node) const;

    /**
    * @brief Recursive helper for pre-order traversal.
    *
    * Recursively visits the current node before its subtrees and applies the callback function to each node's data.
    *
    * @param fp - A function pointer to a callback that accepts a reference to a node's data of type T.
    * @param node - The current node being visited.
    * @return void
    * @pre node is a valid node pointer or nullptr.
    * @post The callback function is called on each node in pre-order sequence.
    */
    void PreOrderTraversal(void (*fp)(const T &), Node<T> * node) const;

    /**
    * @brief Recursive helper for post-order traversal.
    *
    * Recursively visits subtrees before the current node and applies the callback function to each node's data.
    *
    * @param fp - A function pointer to a callback that accepts a reference to a node's data of type T.
    * @param node - The current node being visited.
    * @return void
    * @pre node is a valid node pointer or nullptr.
    * @post The callback function is called on each node in post-order sequence.
    */
    void PostOrderTraversal(void (*fp)(const T &), Node<T> * node) const;
}; // end of class

//---------------------------------------------------------------------------------------

template <class T>
BST<T>::BST()
{
    m_root = nullptr;
}

//---------------------------------------------------------------------------------------

template <class T>
BST<T>::BST(const BST<T> & other)
{
    m_root = nullptr;
    CopyTree(other);
}

//---------------------------------------------------------------------------------------

template <class T>
BST<T> & BST<T>::operator=(const BST<T> & other)
{
    if (this != &other)
    {
        CopyTree(other);
    }
    return *this;
}

//---------------------------------------------------------------------------------------

template <class T>
BST<T>::~BST()
{
    DeleteTree(m_root);
}

//---------------------------------------------------------------------------------------

template <class T>
void BST<T>::Insert(const T & val)
{
    Insert(m_root, val);
}

//---------------------------------------------------------------------------------------

template <class T>
bool BST<T>::Search(const T & val)
{
    return Search(m_root, val);
}

//---------------------------------------------------------------------------------------

template <class T>
void BST<T>::InOrderTraversal(void (*fp)(const T &)) const
{
    InOrderTraversal(fp, m_root);
}

//---------------------------------------------------------------------------------------

template <class T>
void BST<T>::PreOrderTraversal(void (*fp)(const T &)) const
{
    PreOrderTraversal(fp, m_root);
}

//---------------------------------------------------------------------------------------

template <class T>
void BST<T>::PostOrderTraversal(void (*fp)(const T &)) const
{
    PostOrderTraversal(fp, m_root);
}

//---------------------------------------------------------------------------------------

template <class T>
void BST<T>::CopyTree(const BST<T> & other)
{
    DeleteTree(m_root);
    Copy(m_root, other.m_root);
}

//---------------------------------------------------------------------------------------

template <class T>
void BST<T>::Copy(Node<T> * & thisNode, Node<T> * otherNode)
{
    if (otherNode == nullptr)
    {
        thisNode = nullptr;
    }
    else
    {
        thisNode = new Node<T>;
        thisNode->data = otherNode->data;
        Copy(thisNode->left, otherNode->left);
        Copy(thisNode->right, otherNode->right);
    }
}

//---------------------------------------------------------------------------------------

template <class T>
void BST<T>::DeleteTree(Node<T> * & node)
{
    if (node != nullptr)
    {
        DeleteTree(node->left);
        DeleteTree(node->right);
        delete node;
        node = nullptr;
    }
}

//---------------------------------------------------------------------------------------

template <class T>
void BST<T>::Insert(Node<T> * & node, const T & val)
{
    if (node == nullptr)
    {
        node = new Node<T>;
        node->data = val;
        node->left = nullptr;
        node->right = nullptr;
    }
    else if (node->data == val)
    {
        std::cout << "Duplicates not allowed\n\n";
        delete node;
        node = nullptr;
        return;
    }
    else if (node->data > val)
    {
        Insert(node->left, val);
    }
    else
    {
        Insert(node->right, val);
    }
}

//---------------------------------------------------------------------------------------

template <class T>
bool BST<T>::Search(Node<T> * node, const T & val) const
{
    if (node == nullptr)
    {
        return false;
    }

    if (node->data == val)
    {
        return true;
    }
    else if (node->data > val)
    {
        return Search(node->left, val);
    }
    else
    {
        return Search(node->right, val);
    }

    return false;
}

//---------------------------------------------------------------------------------------

template <class T>
void BST<T>::InOrderTraversal(void (*fp)(const T &), Node<T> * node) const
{
    if (node != nullptr)
    {
        InOrderTraversal(fp, node->left);
        fp(node->data);
        InOrderTraversal(fp, node->right);
    }
}

//---------------------------------------------------------------------------------------

template <class T>
void BST<T>::PreOrderTraversal(void (*fp)(const T &), Node<T> * node) const
{
    if (node != nullptr)
    {
        fp(node->data);
        PreOrderTraversal(fp, node->left);
        PreOrderTraversal(fp, node->right);
    }
}

//---------------------------------------------------------------------------------------

template <class T>
void BST<T>::PostOrderTraversal(void (*fp)(const T &), Node<T> * node) const
{
    if (node != nullptr)
    {
        PostOrderTraversal(fp, node->left);
        PostOrderTraversal(fp, node->right);
        fp(node->data);
    }
}

//---------------------------------------------------------------------------------------

#endif // BST_H
