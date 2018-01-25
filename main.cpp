/// Table of contents
///
/// 1. set_node (convenience)
/// 2. add_to_tail
/// 3. add_to_head
/// 4. get_node_count
/// 5. remove_by_index
/// 6. remove_by_content
/// 7. print_list

#include <iostream>

using namespace std;

struct Node{
    int     data;
    Node*   next;
};

void    set_node(Node* &node_set, int data, bool init = false)
/// Sets data of 'node_set' node. If 'init' is specified as true, 'next' adress of 'node_set' is set to NULL.
///
/// Set MyNode's data to 42
///     set_node(MyNode, 42);
///
/// Set MyNode's data to 42, set NULL 'next' address
///     set_node(MyNode, 42, true);
{
    node_set -> data = data;            /// Sets data of 'node_set' to 'data'
    if (init == true)
        node_set -> next = NULL;        /// Sets 'next' address to NULL if 'init' is true
}

void    add_to_tail(Node* &head_node, Node* &new_node)
/// Adds 'new_node' node as the last node in the linked list with the 'head_node' head
{
    Node* head_ptr = head_node;         /// Auxiliary pointer is used to preserve the head address

    new_node -> next = NULL;            /// The node added last will have a NULL 'next' address

    if (head_ptr == NULL)               /// Check if the head exists. If not, set 'head_node' to point to 'new_node'
        head_node = new_node;
    else
    {                                   /// If the head exists,
        while (head_ptr -> next != NULL)/// go through the list until the last node,
            head_ptr = head_ptr -> next;
        head_ptr -> next = new_node;    /// add 'new_node' as the last node
    }
}

void    add_to_head(Node* &head_node, Node* &new_node)
/// Adds 'new_node' node as the first node in the linked list which started with 'head_node' before
///
/// Address of list's head node CHANGES.
{
    new_node -> next = head_node;       /// Sets the old head as the next node after 'new_node', making 'new_node' the new head of the list
}

int     get_node_count(Node* &head_node)
/// Get number of elements in list starting with 'head_node' node
{
     Node* head_ptr = head_node;        /// Auxiliary pointer is used to preserve the head address
     int k = 0;                         /// Counter used for going through list

     while (head_ptr != NULL)           /// While in the list
     {
         head_ptr = head_ptr -> next;   /// 'head_ptr' pointer advances in list
         k++;                           /// Increment counter
     }
     return k;                          /// Return calculated size
}

void    remove_by_index(Node* &head_node, int index)
/// Removes the node numbered 'index' from list which starts with head_node
{
    Node* actual_ptr = head_node;       /// Auxiliary pointer is used to preserve the head address
    Node* previous_ptr = NULL;          /// Will hold address of node which is located before the 'actual_ptr' referenced node
    int k = 0;                          /// Counter used for going through list

    while (actual_ptr != NULL && k < index) /// While list end is not reached and the required element index is not reached
    {
        previous_ptr = actual_ptr;      /// Copy 'actual_ptr' to keep chasing its node
        actual_ptr = actual_ptr -> next;/// 'actual_ptr' pointer advances in list
        k++;                            /// Increment counter to search for the desired index
    }
    if (actual_ptr != NULL)             /// Check if the pointers are still pointing to nodes in the list
        previous_ptr -> next = actual_ptr -> next;  /// Remake connections to bypass node located at 'actual_ptr' address
    else
        cout << "Index out of bounds. List size is smaller than index value.";  /// Size matters
}

void    remove_by_content(Node* &head_node, int data)
/// Removes the node numbered 'index' from list which starts with 'head_node'
{
    Node* actual_ptr = head_node;       /// Auxiliary pointer is used to preserve the head address
    Node* previous_ptr = NULL;          /// Will hold address of node which is located before the 'actual_ptr' referenced node
    int k = 0;                          /// Counter used for going through list

    while (actual_ptr != NULL && actual_ptr -> data != data) /// While list end is not reached and the required element data is not reached
    {
        previous_ptr = actual_ptr;      /// Copy 'actual_ptr' to keep chasing its node
        actual_ptr = actual_ptr -> next;/// 'actual_ptr' pointer advances in list
        k++;                            /// Increment counter to find the desired index
    }
    if (actual_ptr != NULL)             /// Check if the pointers are still pointing to nodes in the list
        previous_ptr -> next = actual_ptr -> next;  /// Remake connections to bypass node located at 'actual_ptr' address
    else
        cout << "Element not found.";  /// Try harder
}

void    print_list(Node* &head_node)
/// Prints list as table with index, data, address and next address columns
{
     Node* head_ptr = head_node;        /// Auxiliary pointer is used to preserve the head address
     int k = 0;                         /// Counter used for going through list

     cout << "--------------------------------------------" << endl; /// Border and table columns
     cout << "Index\tData\tAddress\t\tNext Address" << endl << endl;

     while (head_ptr != NULL)           /// While through the list
     {
         cout << k << "\t" << head_ptr -> data << "\t" << head_ptr << "\t" << head_ptr -> next << endl; /// Individual node info
         head_ptr = head_ptr -> next;   /// 'head_ptr' pointer advances in list
         k++;                           /// Increment counter
     }

     cout << "--------------------------------------------" << endl << endl;
}

int main()
{
    Node* node1 = new Node;
    Node* node2 = new Node;
    Node* node3 = new Node;

    set_node(node1, 10, true);
    set_node(node2, 20);
    set_node(node3, 30);

    /// Nodes containing 1 2 3 exist, but are not linked in a list

    add_to_tail(node1, node2);

    /// 1 -> 2 (Node1 and  Node2, containing 10 and 20, are now linked). Node2 is added after Node1. Node3, containing 30, is not linked

    add_to_head(node1, node3);

    /// Tremendous list

    print_list(node3);

    /// 3 -> 1 -> 2 (all nodes are linked). Node3 is added before Node1.

    remove_by_index(node3, 1);

    /// 3 -> 2 (node number 1, indexed from 0, is removed). Node3 is now linked directly to Node2.

    cout << "Number of nodes: " << get_node_count(node3) << endl << endl;
    print_list(node3);

    /// There are only 2 nodes left

    remove_by_content(node3, 20);

    /// Node2, which contains 20, is removed

    cout << "Number of nodes: " << get_node_count(node3) << endl << endl;
    print_list(node3);

    /// There is only 1 node left
    return 0;
}
