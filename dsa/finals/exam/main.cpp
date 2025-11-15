#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

struct AIMock {
    string name;
    double score;
};

/*
 * Prints all AI mocks in a formatted table with name and score columns
 * Parameters: mocks (vector to display), title (optional header for the table)
 */
void display_mocks(const vector<AIMock> &mocks, const string &title = "AI Mock Database") {
    cout << "\n[" << title << "]\n";
    cout << left << setw(20) << "Name" << setw(10) << "Score" << endl;
    cout << "-----------------------------------\n";
    for (const auto &mock : mocks)
        cout << left << setw(20) << mock.name << setw(10) << mock.score << endl;
    cout << "-----------------------------------\n";
}

/*
 * Prompts user to enter a new AI mock's name and accuracy score,
 * then adds it to the mocks vector.
 */
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

/*
 * Selection Sort
 * Time Complexity: O(n²)
 */
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

/*
 * Insertion Sort
 * Time Complexity: O(n²)
 */
void insertion_sort(vector<AIMock> &mocks) {
    for (size_t i = 1; i < mocks.size(); ++i) {  // Loop through the list, starting from the second item
        AIMock key = mocks[i];  // Store the current item to be inserted in the correct place
        int j = i - 1;  // Start comparing with the item just before the current one
        while (j >= 0 && mocks[j].score > key.score) {  // Loop backwards while the item being compared is larger than the 'key'
            mocks[j + 1] = mocks[j];  // Move the larger item one position to the right
            --j;  // Move to the next item to the left for comparison
        }
        mocks[j + 1] = key;  // Insert the 'key' (current item) into its correct sorted position
    }
}

/*
 *Bubble Sort
 * Time Complexity: O(n²)
 */
void bubble_sort(vector<AIMock> &mocks) {
    for (size_t i = 0; i < mocks.size() - 1; ++i) {  // Make sure we make enough passes to sort the whole list
        for (size_t j = 0; j < mocks.size() - i - 1; ++j) {  // Compares adjacent elements for one pass
            if (mocks[j].score > mocks[j + 1].score)  // Check if the current item is greater than the next item
                swap(mocks[j], mocks[j + 1]);  // If it is, swap them so the larger item "bubbles up"
        }
    }
}

/*
 * Merges two sorted subarrays into one sorted array
 * Helper function for merge_sort
 */
void merge(vector<AIMock> &mocks, int left, int mid, int right) {
    int n1 = mid - left + 1; // Calculate the size of the first (left) subarray
    int n2 = right - mid; // Calculate the size of the second (right) subarray
    vector<AIMock> left_half(n1); // Create a temp array for the left half
    vector<AIMock> right_half(n2); // Create a temp array for the right half

    for (int i = 0; i < n1; ++i) // Copy elements from the main array into the left temp array
        left_half[i] = mocks[left + i];
    for (int j = 0; j < n2; ++j) // Copy elements from the main array into the right temp array
        right_half[j] = mocks[mid + 1 + j];

    int i = 0, j = 0, k = left; // Initialize 'i' for left, 'j' for right, 'k' for the main array
    while (i < n1 && j < n2) { // Loop while there are elements in both temp arrays
        if (left_half[i].score <= right_half[j].score) // Check which element is smaller
            mocks[k++] = left_half[i++]; // Copy the smaller element from the left half back to the main array and advance both indices
        else
            mocks[k++] = right_half[j++]; // Copy the smaller element from the right half back to the main array and advance both indices
    }

    while (i < n1) // If the left half still has remaining elements...
        mocks[k++] = left_half[i++]; // ...copy them all to the main array
    while (j < n2) // If the right half still has remaining elements...
        mocks[k++] = right_half[j++]; // ...copy them all to the main array
}
/*
 * Merge Sort algorithm
 * Time Complexity: O(n log n)
 */
void merge_sort(vector<AIMock> &mocks, int left, int right) {
    if (left < right) { // Base case: Only proceed if the segment has more than one element
        int mid = left + (right - left) / 2; // Find the middle point to split the array
        merge_sort(mocks, left, mid); // Recursively sort the left half
        merge_sort(mocks, mid + 1, right); // Recursively sort the right half
        merge(mocks, left, mid, right); // Merge the two sorted halves back together
    }
}

/*
 * Menu for sorting AI mocks by score
 * Allows user to select a sorting algorithm and displays before/after results with runtime.
 */
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

    auto start = high_resolution_clock::now();

    switch (choice) {
        case 1: selection_sort(mocks); break;
        case 2: insertion_sort(mocks); break;
        case 3: bubble_sort(mocks); break;
        case 4: merge_sort(mocks, 0, mocks.size() - 1); break;
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "\nSorted successfully using " << sort_name
         << " in " << duration.count() << " µs!\n";

}

/*
 * Searches for an AI mock by name using Linear Search
 * Time Complexity: O(n)
 */
void linear_search(const vector<AIMock> &mocks, const string &name) {
    cout << "\n[LINEAR SEARCH RESULTS]" << endl; // Print a header for the search results
    bool found = false; // Initialize a flag to track if the name is found
    for (const auto &mock : mocks) { // Loop through every single item ('mock') in the list
        if (mock.name == name) { // Check if the current item's name matches the target name
            cout << "Found: " << mock.name << " | Score: " << mock.score << endl; // If matched, print the details
            found = true; // Set the flag to true because a match was found
        }
    }
    if (!found) cout << "No mock found with that name.\n"; // After checking all items, if the flag is still false, print a 'not found' message
}

/*
 * Searches for an AI mock by name using Binary Searc
 * Note: First sorts mocks by name (requires sorted data)
 * Time Complexity: O(log n)
 */
void binary_search_mocks(vector<AIMock> mocks, const string &name) {
    cout << "\n[BINARY SEARCH RESULTS]" << endl; // Print a header for the results
    sort(mocks.begin(), mocks.end(), [](const AIMock &a, const AIMock &b) {
        return a.name < b.name;
    });
    int left = 0, right = mocks.size() - 1; // Set 'left' index to the start (0) and 'right' index to the end of the list
    bool found = false; // Initialize a flag to track if the name is found
    while (left <= right) { // Loop as long as the 'left' index hasn't crossed the 'right' index
        int mid = left + (right - left) / 2; // Calculate the middle index of the current search segment
        if (mocks[mid].name == name) { // Check if the item at the middle is the one we are looking for
            cout << "Found: " << mocks[mid].name << " | Score: " << mocks[mid].score << endl; // If matched, print the details
            found = true; // Set the flag to true
            break; // Stop the search loop immediately
        }
        if (mocks[mid].name < name) // If the middle name is alphabetically *before* the target name...
            left = mid + 1; // ...discard the left half and move the 'left' index past the middle
        else // Otherwise (if the middle name is *after* the target name)...
            right = mid - 1; // ...discard the right half and move the 'right' index before the middle
    }
    if (!found) cout << "No mock found with that name.\n"; // If the loop finishes without finding the name, print a message
}

/*
 * Menu for searching AI mocks by name
 * Allows user to choose between Linear Search and Binary Search algorithms
 */
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

/*
 * Generates random AI mock data for testing and benchmarking purposes
 * Returns a vector of randomly generated mocks with random scores (0-100)
 */
vector<AIMock> generate_mocks(int count) {
    vector<AIMock> mocks;
    for (int i = 0; i < count; ++i) {
        AIMock m;
        m.name = "Mock_" + to_string(i + 1);
        m.score = rand() % 101;
        mocks.push_back(m);
    }
    return mocks;
}

/*
 * Compares runtime performance of all sorting algorithms on different data sizes
 * Tests with 10, 100, and 1000 elements to show algorithmic complexity in practice
 */
void benchmark_sorts() {
    cout << "\n[ALGORITHM RUNTIME BENCHMARK]\n";

    // Data sizes to test
    vector<int> sizes = {10, 100, 1000};

    for (int size : sizes) {
        cout << "\nBenchmarking list size: " << size << "\n";

        vector<AIMock> base_mocks = generate_mocks(size);

        // If the dataset is too small, inflate it to avoid 0 µs outputs
        vector<AIMock> testData = base_mocks;
        if (size < 20) {
            testData.clear();
            for (int i = 0; i < 5000; i++) {
                testData.push_back({"Mock_" + to_string(i), rand() % 101});
            }
            cout << "(Dataset auto-expanded to 5000 elements for accurate timings)\n";
        }

        vector<pair<string, void(*)(vector<AIMock>&)>> algorithms = {
            {"Selection Sort", selection_sort},
            {"Insertion Sort", insertion_sort},
            {"Bubble Sort",   bubble_sort}
        };

        // Benchmark O(n²) sorts
        for (auto &[name, func] : algorithms) {
            vector<AIMock> data = testData;

            auto start = high_resolution_clock::now();
            func(data);
            auto end = high_resolution_clock::now();

            auto duration = duration_cast<microseconds>(end - start).count();
            cout << setw(20) << left << name << duration << " µs\n";
        }

        // Benchmark Merge Sort separately (recursive)
        {
            vector<AIMock> data = testData;

            auto start = high_resolution_clock::now();
            merge_sort(data, 0, data.size() - 1);
            auto end = high_resolution_clock::now();

            auto duration = duration_cast<microseconds>(end - start).count();
            cout << setw(20) << left << "Merge Sort" << duration << " µs\n";
        }
    }
}



/*
 * Main program
 */
int main() {
    vector<AIMock> mocks;
    int choice;

    cout << "=============================\n";
    cout << "   AI Mock Database\n";
    cout << "=============================\n";

    do {
        cout << "\nMAIN MENU\n";
        cout << "[1] Add New AI Mock\n";
        cout << "[2] Sort AI Mocks\n";
        cout << "[3] Search AI Mocks\n";
        cout << "[4] Benchmark Sorting Algorithms\n";
        cout << "[5] Exit\n";
        cout << "Select an option (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1: add_mock(mocks); break;
            case 2: sort_mocks(mocks); break;
            case 3: search_mocks(mocks); break;
            case 4: benchmark_sorts(); break;
            case 5: cout << "\nExiting program... Goodbye!\n"; break;
            default: cout << "\nInvalid choice. Please select 1-5.\n"; break;
        }
    } while (choice != 5);

    return 0;
}
