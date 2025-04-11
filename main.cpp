#include <iostream>
#include <vector>
#include <chrono>

using namespace std::chrono;
using namespace std;

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

int main() {
    vector<int> sizes = {1000, 10000, 50000, 100000, 200000};

    for (int size: sizes) {
        vector<int> base = generateArray(size, true);
        vector<int> arr1 = base;
        vector<int> arr2 = base;

        insertionCount = 0;
        auto start = high_resolution_clock::now();
        insertionSort(arr1);
        auto stop = high_resolution_clock::now();

        mergeCount = 0;
        start = high_resolution_clock::now();
        mergeSort(arr2, 0, size - 1);
        stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        cout << "Size: " << size << endl;
        cout << "Time elapsed (Insertion Sort): " << duration.count() << " microseconds" << endl;
        cout << "Time elapsed (MergeSort): " << duration.count() << " microseconds" << endl;
        cout << "----------------------------------------" << endl;
    }


    }



