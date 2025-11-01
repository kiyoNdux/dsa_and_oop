#include <iostream>
#include <string>
using namespace std;

// Stack – Edit History
struct EditNode {
    string action;
    EditNode* next;
    EditNode(string a) : action(a), next(nullptr) {}
};

class EditHistory {
private:
    EditNode* top;
public:
    EditHistory() : top(nullptr) {}

    void pushEdit(const string& action) {
        EditNode* newNode = new EditNode(action);
        newNode->next = top;
        top = newNode;
        cout << "Edit applied: " << action << endl;
    }

    void undoEdit() {
        if (!top) {
            cout << "No edits to undo.\n";
            return;
        }
        cout << "↩️ Undoing last edit: " << top->action << endl;
        EditNode* temp = top;
        top = top->next;
        delete temp;
    }

    void displayHistory() const {
        if (!top) {
            cout << "No edit history.\n";
            return;
        }
        cout << "Edit History:\n";
        EditNode* current = top;
        while (current) {
            cout << "  - " << current->action << endl;
            current = current->next;
        }
    }

    ~EditHistory() {
        while (top) {
            EditNode* temp = top;
            top = top->next;
            delete temp;
        }
    }
};


// Queue – Export Jobs
struct ExportNode {
    string photoName;
    ExportNode* next;
    ExportNode(string name) : photoName(name), next(nullptr) {}
};

class ExportQueue {
private:
    ExportNode* front;
    ExportNode* rear;
public:
    ExportQueue() : front(nullptr), rear(nullptr) {}

    void enqueueExport(const string& photoName) {
        ExportNode* newNode = new ExportNode(photoName);
        if (!rear) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Added to export queue: " << photoName << endl;
    }

    void dequeueExport() {
        if (!front) {
            cout << "No export jobs pending.\n";
            return;
        }
        cout << "Exporting photo: " << front->photoName << "...\nExport complete!\n";
        ExportNode* temp = front;
        front = front->next;
        if (!front) rear = nullptr;
        delete temp;
    }

    void displayQueue() const {
        if (!front) {
            cout << "No photos in export queue.\n";
            return;
        }
        cout << "Export Queue:\n";
        ExportNode* current = front;
        while (current) {
            cout << "  - " << current->photoName << endl;
            current = current->next;
        }
    }

    ~ExportQueue() {
        while (front) {
            ExportNode* temp = front;
            front = front->next;
            delete temp;
        }
    }
};


// Binary Tree – Photo Library
struct PhotoNode {
    string name;
    PhotoNode* left;
    PhotoNode* right;
    PhotoNode(string n) : name(n), left(nullptr), right(nullptr) {}
};

class PhotoLibrary {
private:
    PhotoNode* root;

    PhotoNode* insert(PhotoNode* node, const string& name) {
        if (!node) return new PhotoNode(name);
        if (name < node->name)
            node->left = insert(node->left, name);
        else if (name > node->name)
            node->right = insert(node->right, name);
        else
            cout << "Photo already exists.\n";
        return node;
    }

    bool search(PhotoNode* node, const string& name) const {
        if (!node) return false;
        if (node->name == name) return true;
        if (name < node->name) return search(node->left, name);
        else return search(node->right, name);
    }

    void inorder(PhotoNode* node) const {
        if (!node) return;
        inorder(node->left);
        cout << "  - " << node->name << endl;
        inorder(node->right);
    }

    void clear(PhotoNode* node) {
        if (!node) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

public:
    PhotoLibrary() : root(nullptr) {}

    void addPhoto(const string& name) {
        root = insert(root, name);
        cout << "Photo added: " << name << endl;
    }

    void searchPhoto(const string& name) const {
        if (search(root, name))
            cout << "Found photo: " << name << endl;
        else
            cout << "Photo not found: " << name << endl;
    }

    void displayLibrary() const {
        if (!root) {
            cout << "Library is empty.\n";
            return;
        }
        cout << "Photo Library (A–Z):\n";
        inorder(root);
    }

    ~PhotoLibrary() {
        clear(root);
    }
};


// Main – Photo Editor

int main() {
    PhotoLibrary library;
    EditHistory edits;
    ExportQueue exports;

    int choice;
    string input;

    cout << "=============================\n";
    cout << " Mini Photo Editing Software\n";
    cout << "=============================\n";

    do {
        cout << "\nMenu:\n";
        cout << "1. Add new photo\n";
        cout << "2. Search photo\n";
        cout << "3. Display all photos\n";
        cout << "4. Apply edit\n";
        cout << "5. Undo last edit\n";
        cout << "6. View edit history\n";
        cout << "7. Add export job\n";
        cout << "8. Process next export\n";
        cout << "9. View export queue\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter photo name: ";
                getline(cin, input);
                library.addPhoto(input);
                break;
            case 2:
                cout << "Enter photo name to search: ";
                getline(cin, input);
                library.searchPhoto(input);
                break;
            case 3:
                library.displayLibrary();
                break;
            case 4:
                cout << "Enter edit action: ";
                getline(cin, input);
                edits.pushEdit(input);
                break;
            case 5:
                edits.undoEdit();
                break;
            case 6:
                edits.displayHistory();
                break;
            case 7:
                cout << "Enter photo name to export: ";
                getline(cin, input);
                exports.enqueueExport(input);
                break;
            case 8:
                exports.dequeueExport();
                break;
            case 9:
                exports.displayQueue();
                break;
            case 0:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
