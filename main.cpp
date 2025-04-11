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
    vector<int> test = generateArray(1000, true);


    auto start = high_resolution_clock::now();
    insertionSort(test);
    auto stop = high_resolution_clock::now();

    cout << "Sorted array: ";
    for (int i = 0; i < test.size(); i++) {
        cout << test[i] << " ";
    }
    cout << endl;

auto timeTaken = duration_cast<microseconds>(stop - start).count();
    cout <<"Insertion Sort Time Taken: " << timeTaken << " Microseconds" << endl;
    cout << "Insertion Sort Iteration: " << insertionCount << endl;
    return 0;
}


