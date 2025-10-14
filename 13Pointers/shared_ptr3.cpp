// Implementing a Linked List Using std::shared_ptr

#include <iostream>
#include <memory>
using namespace std;

// Define a singly linked list node
struct Node {
    int data;
    shared_ptr<Node> next;

    Node(int val)
        : data(val)
        , next(NULL)
    {
    }
};

class LinkedList {
public:
    LinkedList()
        : head(NULL)
    {
    }

    // Insert a new node at the end of the linked list
    void insert(int val)
    {
        shared_ptr<Node> newNode = make_shared<Node>(val);
        if (!head) {
            head = newNode;
        }
        else {
            shared_ptr<Node> current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Delete a node with a given value from the linked list
    void del(int val)
    {
        if (!head) {
            return;
        }
        if (head->data == val) { //先比较一下head->data，因为下面的逻辑里只用到current->next，从head开始会把head漏掉
            head = head->next;
            return;
        }
        shared_ptr<Node> current = head;
        while (current->next
               && current->next->data != val) {
            current = current->next;
        }
        if (current->next && current->next->data == val) {
            current->next = current->next->next;
        }
    }

    // Traverse and print the linked list
    void Print()
    {
        shared_ptr<Node> current = head;
        while (current) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

private:
    shared_ptr<Node> head;
};

int main()
{
    LinkedList linkedList;

    // Insert nodes into the linked list
    linkedList.insert(1);
    linkedList.insert(2);
    linkedList.insert(3);

    // Print the linked list
    cout << "Linked List: ";
    linkedList.Print();

    // Delete a node and print the updated linked list
    linkedList.del(2);
    cout << "Linked List after deleting 2: ";
    linkedList.Print();

    return 0;
}

// we can also use unique pointers to implement LinkedList