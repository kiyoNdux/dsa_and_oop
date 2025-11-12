#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct DataEntry {
    int id;
    double feature1;
    double feature2;
    std::string label;
};

class DatasetManager {
private:
    std::vector<DataEntry> data;
    int next_id = 1;

    // Sorting helpers
    void selection_sort(int column);
    void insertion_sort(int column);
    void bubble_sort(int column);
    void merge_sort_helper(int left, int right, int column);
    void merge_sort(int left, int mid, int right, int column);

    // Comparison helper
    bool compare(const DataEntry& a, const DataEntry& b, int column);

public:
    void add_entry(double feature1, double feature2, const std::string& label);
    void display_data();
    void sort_data(int column, int method);
    void search_data(int column, const std::string& value, int method);
};

void DatasetManager::add_entry(double feature1, double feature2, const std::string& label) {
    DataEntry entry = { next_id++, feature1, feature2, label };
    data.push_back(entry);
    std::cout << "Entry added successfully!\n";
}

void DatasetManager::display_data() {
    if (data.empty()) {
        std::cout << "No data available.\n";
        return;
    }
    std::cout << "ID\tFeature1\tFeature2\tLabel\n";
    for (const auto& entry : data) {
        std::cout << entry.id << "\t" << entry.feature1 << "\t\t" << entry.feature2
                  << "\t\t" << entry.label << "\n";
    }
}

// ----------------SORT HELPERS----------------

bool DatasetManager::compare(const DataEntry& a, const DataEntry& b, int column) {
    switch (column) {
        case 1: return a.id < b.id;
        case 2: return a.feature1 < b.feature1;
        case 3: return a.feature2 < b.feature2;
        case 4: return a.label < b.label;
        default: return true;
    }
}

void DatasetManager::selection_sort(int column) {
    int n = data.size();
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
            if (compare(data[j], data[min_index], column))
                min_index = j;
        std::swap(data[i], data[min_index]);
    }
}

void DatasetManager::insertion_sort(int column) {
    int n = data.size();
    for (int i = 1; i < n; i++) {
        DataEntry key = data[i];
        int j = i - 1;
        while (j >= 0 && compare(key, data[j], column)) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }
}

void DatasetManager::bubble_sort(int column) {
    int n = data.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (!compare(data[j], data[j + 1], column))
                std::swap(data[j], data[j + 1]);
}

void DatasetManager::merge_sort(int left, int mid, int right, int column) {
    std::vector<DataEntry> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (compare(data[i], data[j], column))
            temp[k++] = data[i++];
        else
            temp[k++] = data[j++];
    }
    while (i <= mid) temp[k++] = data[i++];
    while (j <= right) temp[k++] = data[j++];

    for (i = left, k = 0; i <= right; i++, k++)
        data[i] = temp[k];
}

void DatasetManager::merge_sort_helper(int left, int right, int column) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    merge_sort_helper(left, mid, column);
    merge_sort_helper(mid + 1, right, column);
    merge_sort(left, mid, right, column);
}

void DatasetManager::sort_data(int column, int method) {
    switch (method) {
        case 1:
            selection_sort(column);
            std::cout << "Selection sort completed.\n";
            break;
        case 2:
            insertion_sort(column);
            std::cout << "Insertion sort completed.\n";
            break;
        case 3:
            bubble_sort(column);
            std::cout << "Bubble sort completed.\n";
            break;
        case 4:
            merge_sort_helper(0, data.size() - 1, column);
            std::cout << "Merge sort completed.\n";
            break;
        default:
            std::cout << "Invalid sort method.\n";
    }
}

// ----------------SEARCH----------------

void DatasetManager::search_data(int column, const std::string& value, int method) {
    if (data.empty()) {
        std::cout << "No data to search.\n";
        return;
    }

    bool found = false;

    if (method == 1) { // Linear Search
        for (const auto& entry : data) {
            bool match = false;
            switch (column) {
                case 1: match = (std::to_string(entry.id) == value); break;
                case 2: match = (std::to_string(entry.feature1) == value); break;
                case 3: match = (std::to_string(entry.feature2) == value); break;
                case 4: match = (entry.label == value); break;
            }
            if (match) {
                std::cout << "Found: " << entry.id << "\t" << entry.feature1 << "\t"
                          << entry.feature2 << "\t" << entry.label << "\n";
                found = true;
            }
        }
    } else if (method == 2) { // Binary Search
        int left = 0, right = data.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            bool mid_match = false;
            switch (column) {
                case 1: mid_match = (data[mid].id == std::stoi(value)); break;
                case 2: mid_match = (data[mid].feature1 == std::stod(value)); break;
                case 3: mid_match = (data[mid].feature2 == std::stod(value)); break;
                case 4: mid_match = (data[mid].label == value); break;
            }
            if (mid_match) {
                std::cout << "Found: " << data[mid].id << "\t" << data[mid].feature1
                          << "\t" << data[mid].feature2 << "\t" << data[mid].label << "\n";
                found = true;
                break;
            }

            bool go_left = false;
            switch (column) {
                case 1: go_left = (std::stoi(value) < data[mid].id); break;
                case 2: go_left = (std::stod(value) < data[mid].feature1); break;
                case 3: go_left = (std::stod(value) < data[mid].feature2); break;
                case 4: go_left = (value < data[mid].label); break;
            }
            if (go_left)
                right = mid - 1;
            else
                left = mid + 1;
        }
    } else {
        std::cout << "Invalid search method.\n";
        return;
    }

    if (!found)
        std::cout << "No matching entry found.\n";
}

// ---------------- MAIN ----------------

int main() {
    DatasetManager manager;
    int choice;

    do {
        std::cout << "\n=============================\n";
        std::cout << "ML Dataset Manager\n";
        std::cout << "=============================\n";
        std::cout << "[1] Add Data\n"
                  << "[2] Sort Data\n"
                  << "[3] Search Data\n"
                  << "[4] Display Data\n"
                  << "[5] Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                double feature1, feature2;
                std::string label;
                std::cout << "Enter Feature1: ";
                std::cin >> feature1;
                std::cout << "Enter Feature2: ";
                std::cin >> feature2;
                std::cout << "Enter Label: ";
                std::cin >> label;
                manager.add_entry(feature1, feature2, label);
                break;
            }
            case 2: {
                int column, method;
                std::cout << "Sort by column [1=ID,2=F1,3=F2,4=Label]: ";
                std::cin >> column;
                std::cout << "Sort method [1=Selection,2=Insertion,3=Bubble,4=Merge]: ";
                std::cin >> method;
                manager.sort_data(column, method);
                break;
            }
            case 3: {
                int column, method;
                std::string value;
                std::cout << "Search by column [1=ID,2=F1,3=F2,4=Label]: ";
                std::cin >> column;
                std::cout << "Search method [1=Linear,2=Binary]: ";
                std::cin >> method;
                std::cout << "Enter value to search: ";
                std::cin >> value;
                manager.search_data(column, value, method);
                break;
            }
            case 4:
                manager.display_data();
                break;
            case 5:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}
