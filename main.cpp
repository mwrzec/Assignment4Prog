#include <iostream>
#include <vector>
#include <chrono>

using namespace std::chrono;
using namespace std;

int insertionCount = 0;

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


void insertionSort(vector<int>& arr) {
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

int mergeCount = 0;

void merge(vector<int>& arr, int left, int mid, int right) {
    mergeCount++;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        mergeCount++;
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int> arr, int left, int right) {
    if (left < right) {
        mergeCount++;
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
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



