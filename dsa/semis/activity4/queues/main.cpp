#include <iostream>
using namespace std;

class Queue {
private:
    int front, rear, capacity;
    string* queue;

public:
    Queue(int cap) {
        front = 0;
        rear = -1;
        capacity = cap;
        queue = new string[capacity];
    }

    ~Queue() {
        delete[] queue;
    }

    void enqueue(string request) {
        if (isFull()) {
            cout << "Server busy: Cannot handle more requests right now." << endl;
            return;
        } else {
            cout << "Received request: " << request << endl;
            queue[++rear] = request;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "No pending requests to process." << endl;
            return;
        } else {
            cout << "Processing request: " << queue[front] << endl;
            // Shift all elements left (simple approach)
            for (int i = 0; i < rear; i++) {
                queue[i] = queue[i + 1];
            }
            rear--;
        }
    }

    string peek() {
        if (isEmpty()) {
            cout << "No requests in queue." << endl;
            return "";
        }
        return queue[front];
    }

    bool isFull() {
        return rear == capacity - 1;
    }

    bool isEmpty() {
        return rear == -1;
    }

    void display() {
        if (isEmpty()) {
            cout << "Request queue is empty." << endl;
            return;
        }

        cout << "Current request queue: ";
        for (int i = front; i <= rear; i++) {
            cout << "[" << queue[i] << "]";
            if (i < rear) cout << " <- ";
        }
        cout << endl;
    }
};


int main() {
    Queue requestQueue(5);
    int choice;
    string url;

    while (true) {
        cout << "\nWeb Server Request Queue" << endl;
        cout << "1. Receive new request" << endl;
        cout << "2. Process next request" << endl;
        cout << "3. View next request" << endl;
        cout << "4. Show all pending requests" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        cin.ignore(); // Clear leftover newline from input

        switch (choice) {
            case 1:
                cout << "Enter request URL (e.g., /api/users or /home): ";
                getline(cin, url);
                requestQueue.enqueue(url);
                break;

            case 2:
                requestQueue.dequeue();
                break;

            case 3:
                if (!requestQueue.isEmpty())
                    cout << "Next request to process: " << requestQueue.peek() << endl;
                else
                    cout << "No pending requests." << endl;
                break;

            case 4:
                requestQueue.display();
                break;

            case 5:
                cout << "Server shutting down..." << endl;
                return 0;

            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}
