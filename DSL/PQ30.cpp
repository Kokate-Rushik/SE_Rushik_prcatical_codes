#include <iostream>
#include <list>
using namespace std;

// Class to represent an item with data and priority
template <typename T>
class PriorityItem {
public:
    T data;
    int priority;

    // Constructor
    PriorityItem(T d, int p) : data(d), priority(p) {}

    // Overload <= operator to order by priority
    bool operator<=(const PriorityItem& other) const {
        return this->priority > other.priority;
    }
};

// Priority Queue class using an inorder list
template <typename T>
class PriorityQueue {
private:
    list<PriorityItem<T>> items;

public:
    // Function to insert item into the priority queue
    void insert(T data, int priority) {
        PriorityItem<T> newItem(data, priority);
        auto it = items.begin();

        // Find the correct position based on priority
        while (it != items.end() && *it <= newItem) {
            ++it;
        }
        items.insert(it, newItem);
    }

    // Function to remove and return the highest priority item
    T remove() {
        if (items.empty()) {
            throw runtime_error("Priority Queue is empty");
        }
        T data = items.front().data;
        items.pop_front();
        return data;
    }

    // Function to display all items in the priority queue
    void display() const {
        if (items.empty()) {
            cout << "Priority Queue is empty." << endl;
        } else {
            cout << "Priority Queue contents (highest priority first):" << endl;
            for (const auto& item : items) {
                cout << "Data: " << item.data << ", Priority: " << item.priority << endl;
            }
        }
    }
};

int main() {
    PriorityQueue<string> pq;
    int choice, priority;
    string data;

    do {
        cout << "\nPriority Queue Menu:\n";
        cout << "1. Insert Item\n";
        cout << "2. Remove Highest Priority Item\n";
        cout << "3. Display Queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data: ";
                cin >> data;
                cout << "Enter priority (higher number means higher priority): ";
                cin >> priority;
                pq.insert(data, priority);
                break;
            case 2:
                try {
                    cout << "Removed item with highest priority: " << pq.remove() << endl;
                } catch (const exception& e) {
                    cout << e.what() << endl;
                }
                break;
            case 3:
                pq.display();
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
