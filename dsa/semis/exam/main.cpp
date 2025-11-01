#include <iostream>
#include <string>
using namespace std;


// ----- Stack – Edit History -----

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

    void push_edit(const string& action) {
        EditNode* new_node = new EditNode(action);
        new_node->next = top;
        top = new_node;
        cout << "Edit applied: " << action << endl;
    }

    void undo_edit() {
        if (!top) {
            cout << "No edits to undo." << endl;
            return;
        }
        cout << "Undoing last edit: " << top->action << endl;
        EditNode* temp = top;
        top = top->next;
        delete temp;
    }

    void display_history() const {
        if (!top) {
            cout << "No edit history." << endl;
            return;
        }
        cout << "Edit History:" << endl;
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


// ----- Queue – Export Jobs -----
struct ExportNode {
    string photo_name;
    ExportNode* next;
    ExportNode(string name) : photo_name(name), next(nullptr) {}
};

class ExportQueue {
private:
    ExportNode* front;
    ExportNode* rear;
public:
    ExportQueue() : front(nullptr), rear(nullptr) {}

    void enqueue_export(const string& photo_name) {
        ExportNode* new_node = new ExportNode(photo_name);
        if (!rear) {
            front = rear = new_node;
        } else {
            rear->next = new_node;
            rear = new_node;
        }
        cout << "Added to export queue: " << photo_name << endl;
    }

    void dequeue_export() {
        if (!front) {
            cout << "No export jobs pending." << endl;
            return;
        }
        cout << "Exporting photo: " << front->photo_name << "..." << endl;
        cout << "Export complete!" << endl;
        ExportNode* temp = front;
        front = front->next;
        if (!front) rear = nullptr;
        delete temp;
    }

    void display_queue() const {
        if (!front) {
            cout << "No photos in export queue." << endl;
            return;
        }
        cout << "Export Queue:" << endl;
        ExportNode* current = front;
        while (current) {
            cout << "  - " << current->photo_name << endl;
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


// ----- Binary Tree – Photo Library -----
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
            cout << "Photo already exists." << endl;
        return node;
    }

    bool find_photo_recursive(PhotoNode* node, const string& name) const {
        if (!node) return false;
        if (node->name == name) return true;
        if (name < node->name) return find_photo_recursive(node->left, name);
        else return find_photo_recursive(node->right, name);
    }

    void inorder(PhotoNode* node) const {
        if (!node) return;
        inorder(node->left);
        cout << "  - " << node->name << endl;
        inorder(node->right);
    }

    void clear_library_recursive(PhotoNode* node) {
        if (!node) return;
        clear_library_recursive(node->left);
        clear_library_recursive(node->right);
        delete node;
    }

public:
    PhotoLibrary() : root(nullptr) {}

    void add_photo(const string& name) {
        root = insert(root, name);
        cout << "Photo added: " << name << endl;
    }

    void search_photo(const string& name) const {
        if (find_photo_recursive(root, name))
            cout << "Found photo: " << name << endl;
        else
            cout << "Photo not found: " << name << endl;
    }

    void display_library() const {
        if (!root) {
            cout << "Library is empty." << endl;
            return;
        }
        cout << "Photo Library (A-Z):" << endl;
        inorder(root);
    }

    ~PhotoLibrary() {
        clear_library_recursive(root);
    }
};



// ----- Main Program – Photo Editor -----
int main() {
    PhotoLibrary library;
    EditHistory edits;
    ExportQueue exports;

    int choice;
    string input;

    cout << "=============================" << endl;
    cout << " Mini Photo Editing Software" << endl;
    cout << "=============================" << endl;

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
                library.add_photo(input);
                break;
            case 2:
                cout << "Enter photo name to search: ";
                getline(cin, input);
                library.search_photo(input);
                break;
            case 3:
                library.display_library();
                break;
            case 4:
                cout << "Enter edit action: ";
                getline(cin, input);
                edits.push_edit(input);
                break;
            case 5:
                edits.undo_edit();
                break;
            case 6:
                edits.display_history();
                break;
            case 7:
                cout << "Enter photo name to export: ";
                getline(cin, input);
                exports.enqueue_export(input);
                break;
            case 8:
                exports.dequeue_export();
                break;
            case 9:
                exports.display_queue();
                break;
            case 0:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != 0);

    return 0;
}
