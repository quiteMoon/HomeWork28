#include <iostream>

using namespace std;

template <typename T>
class PriorityQueue {
private:
    struct Node {
        T data;
        int priority;
        Node* next;
    };

    Node* head;
    int size;

public:
    PriorityQueue() : head(nullptr), size(0) {}

    ~PriorityQueue() {
        while (!IsEmpty()) {
            PullHighestPriorityElement();
        }
    }

    bool IsEmpty() const {
        return head == nullptr;
    }

    bool IsFull() const {
        return false; 
    }

    void InsertWithPriority(const T& element, int priority) {
        Node* newNode = new Node{ element, priority, nullptr };

        if (IsEmpty() || head->priority < priority) {
            newNode->next = head;
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != nullptr && current->next->priority >= priority) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
        ++size;
    }

    T PullHighestPriorityElement() {
        if (IsEmpty()) {
            throw runtime_error("Queue is empty");
        }

        Node* temp = head;
        T data = temp->data;
        head = head->next;
        delete temp;
        --size;

        return data;
    }

    T Peek() const {
        if (IsEmpty()) {
            throw runtime_error("Queue is empty");
        }
        return head->data;
    }

    int GetSize() const {
        return size;
    }

    void Show() const {
        Node* current = head;
        while (current != nullptr) {
            cout << "Element: " << current->data << ", Priority: " << current->priority << endl;
            current = current->next;
        }
    }
};

int main() {
    PriorityQueue<int> pq;

    pq.InsertWithPriority(10, 2);
    pq.InsertWithPriority(5, 3);
    pq.InsertWithPriority(15, 1);

    cout << "Queue elements:" << endl;
    pq.Show();

    cout << "Highest priority element: " << pq.Peek() << endl;

    pq.PullHighestPriorityElement();

    cout << "Queue elements after pulling highest priority element:" << endl;
    pq.Show();
}
