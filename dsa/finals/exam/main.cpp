#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct AIMock {
    string name;
    double score;
};

void display_mocks(const vector<AIMock> &mocks, const string &title = "AI Mock Database") {
    cout << "\n[" << title << "]\n";
    cout << left << setw(20) << "Name" << setw(10) << "Score" << endl;
    cout << "-----------------------------------\n";
    for (const auto &mock : mocks)
        cout << left << setw(20) << mock.name << setw(10) << mock.score << endl;
    cout << "-----------------------------------\n";
}

void add_mock(vector<AIMock> &mocks) {
    AIMock mock;
    cout << "\n[ADD NEW AI MOCK]" << endl;
    cout << "Enter AI Mock Name: ";
    cin.ignore();
    getline(cin, mock.name);
    cout << "Enter Accuracy Score (0 - 100): ";
    cin >> mock.score;
    mocks.push_back(mock);
    cout << "Mock added successfully!\n";
}

void selection_sort(vector<AIMock> &mocks) {
    for (size_t i = 0; i < mocks.size() - 1; ++i) {
        size_t min_idx = i;
        for (size_t j = i + 1; j < mocks.size(); ++j) {
            if (mocks[j].score < mocks[min_idx].score)
                min_idx = j;
        }
        swap(mocks[i], mocks[min_idx]);
    }
}

void insertion_sort(vector<AIMock> &mocks) {
    for (size_t i = 1; i < mocks.size(); ++i) {
        AIMock key = mocks[i];
        int j = i - 1;
        while (j >= 0 && mocks[j].score > key.score) {
            mocks[j + 1] = mocks[j];
            --j;
        }
        mocks[j + 1] = key;
    }
}

void bubble_sort(vector<AIMock> &mocks) {
    for (size_t i = 0; i < mocks.size() - 1; ++i) {
        for (size_t j = 0; j < mocks.size() - i - 1; ++j) {
            if (mocks[j].score > mocks[j + 1].score)
                swap(mocks[j], mocks[j + 1]);
        }
    }
}

void merge(vector<AIMock> &mocks, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<AIMock> left_half(n1);
    vector<AIMock> right_half(n2);

    for (int i = 0; i < n1; ++i)
        left_half[i] = mocks[left + i];
    for (int j = 0; j < n2; ++j)
        right_half[j] = mocks[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (left_half[i].score <= right_half[j].score)
            mocks[k++] = left_half[i++];
        else
            mocks[k++] = right_half[j++];
    }

    while (i < n1)
        mocks[k++] = left_half[i++];
    while (j < n2)
        mocks[k++] = right_half[j++];
}

void merge_sort(vector<AIMock> &mocks, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(mocks, left, mid);
        merge_sort(mocks, mid + 1, right);
        merge(mocks, left, mid, right);
    }
}

void sort_mocks(vector<AIMock> &mocks) {
    if (mocks.empty()) {
        cout << "\nNo mocks to sort.\n";
        return;
    }

    cout << "\n[SORT AI MOCKS BY SCORE]" << endl;
    cout << "Select sorting algorithm:\n";
    cout << "1. Selection Sort\n";
    cout << "2. Insertion Sort\n";
    cout << "3. Bubble Sort\n";
    cout << "4. Merge Sort\n";
    cout << "Enter choice (1-4): ";

    int choice;
    cin >> choice;

    string sort_name;
    switch (choice) {
        case 1: sort_name = "Selection Sort"; break;
        case 2: sort_name = "Insertion Sort"; break;
        case 3: sort_name = "Bubble Sort"; break;
        case 4: sort_name = "Merge Sort"; break;
        default: cout << "Invalid choice.\n"; return;
    }

    vector<AIMock> before_sort = mocks;

    cout << "\nSorting using: " << sort_name << "\n";
    display_mocks(before_sort, "Before Sorting");

    switch (choice) {
        case 1: selection_sort(mocks); break;
        case 2: insertion_sort(mocks); break;
        case 3: bubble_sort(mocks); break;
        case 4: merge_sort(mocks, 0, mocks.size() - 1); break;
    }

    cout << "\nSorted successfully using " << sort_name << "!\n";
    display_mocks(mocks, "After Sorting");
}

void linear_search(const vector<AIMock> &mocks, const string &name) {
    cout << "\n[LINEAR SEARCH RESULTS]" << endl;
    bool found = false;
    for (const auto &mock : mocks) {
        if (mock.name == name) {
            cout << "Found: " << mock.name << " | Score: " << mock.score << endl;
            found = true;
        }
    }
    if (!found) cout << "No mock found with that name.\n";
}

void binary_search_mocks(vector<AIMock> mocks, const string &name) {
    cout << "\n[BINARY SEARCH RESULTS]" << endl;
    sort(mocks.begin(), mocks.end(), [](const AIMock &a, const AIMock &b) {
        return a.name < b.name;
    });

    int left = 0, right = mocks.size() - 1;
    bool found = false;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (mocks[mid].name == name) {
            cout << "Found: " << mocks[mid].name << " | Score: " << mocks[mid].score << endl;
            found = true;
            break;
        }
        if (mocks[mid].name < name)
            left = mid + 1;
        else
            right = mid - 1;
    }
    if (!found) cout << "No mock found with that name.\n";
}

void search_mocks(const vector<AIMock> &mocks) {
    if (mocks.empty()) {
        cout << "\nNo mocks to search.\n";
        return;
    }

    cout << "\n[SEARCH AI MOCKS]" << endl;
    cout << "Enter AI Mock Name to search: ";
    string name;
    cin.ignore();
    getline(cin, name);

    cout << "Select search algorithm:\n";
    cout << "1. Linear Search\n";
    cout << "2. Binary Search\n";
    cout << "Enter choice (1-2): ";
    int choice;
    cin >> choice;

    switch (choice) {
        case 1: linear_search(mocks, name); break;
        case 2: binary_search_mocks(mocks, name); break;
        default: cout << "Invalid choice.\n"; break;
    }
}

int main() {
    vector<AIMock> mocks;
    int choice;

    cout << "=============================\n";
    cout << "   AI Mock Database (CLI)\n";
    cout << "=============================\n";

    do {
        cout << "\nMAIN MENU\n";
        cout << "[1] Add New AI Mock\n";
        cout << "[2] Sort AI Mocks\n";
        cout << "[3] Search AI Mocks\n";
        cout << "[4] Exit\n";
        cout << "Select an option (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1: add_mock(mocks); break;
            case 2: sort_mocks(mocks); break;
            case 3: search_mocks(mocks); break;
            case 4: cout << "\nExiting program... Goodbye!\n"; break;
            default: cout << "\nInvalid choice. Please select 1-4.\n"; break;
        }
    } while (choice != 4);

    return 0;
}
