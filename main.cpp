#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> test = generateArray(10, true);
    insertionSort(test);

    cout << "Sorted array: ";
    for (int i = 0; i < test.size(); i++) {
        cout << test[i] << " ";
    }
    cout << endl;

    cout << "Insertion Sort Iteration: " << insertionCount << endl;
    return 0;+
}

vector<int> generateArray(int size, bool reverseOrder) {
    vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        if (reverseOrder) {
            arr[i] = size - i;
        } else {
            arr[i] = i;
        }
    }
    return arr;
}

int insertionCount = 0;

void insertionSort(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            insertionCount++;
        }
        arr[j + 1] = key;
        insertionCount++;
        }
    }


