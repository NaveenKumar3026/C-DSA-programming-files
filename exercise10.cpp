#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int value) {
        this->value = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* front;
    Node* rear;
    int length;

public:
    static int size;

    LinkedList(int value) {
        Node* newNode = new Node(value);
        front = newNode;
        rear = newNode;
        length = 1;   // initialize properly
    }

    bool isFull() {
        if (length == size) return true;
        return false;
    }

    bool isEmpty() {
        if (length == 0) return true;
        return false;
    }

    void enqueue(int value) {
        if (isFull()) {   // FIXED condition (your code had !isFull() by mistake)
            cout << "Queue is full, cannot insert any element into it\n";
            return;
        }

        Node* newNode = new Node(value);
        if (length == 0) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        length++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty and cannot delete any elements in the queue\n";
            return;
        }

        Node* temp = front;
        front = front->next;
        delete temp;

        if (front == nullptr) {
            rear = nullptr;
        }
        length--;
    }

    void display() {
        cout << "Displaying the queue\n";
        if (length == 0) {
            cout << "Queue is empty\n";
            return;
        }

        Node* temp = front;
        while (temp) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void info() {
        cout << "\nEnter 1 for enqueue function\nEnter 2 for dequeue function\n";
    }
};

int LinkedList::size = 10;

int main() {
    int choice, value;
    char c;

    cout << "Enter first element of the queue: ";
    cin >> value;

    LinkedList* q = new LinkedList(value);
    q->info();

    do {
        cout << "Enter the choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value: ";
                cin >> value;
                q->enqueue(value);
                q->display();
                break;

            case 2:
                q->dequeue();
                q->display();
                break;

            default:
                cout << "Invalid choice\n";
        }

        cout << "Do you want to continue (y/n)?: ";
        cin >> c;
    } while (c == 'Y' || c == 'y');

    return 0;
}
