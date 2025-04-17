#include <iostream>
#include <vector>
#include <chrono>
#include "sorting_algorithms.h"
#include "searching_algorithms.h"

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

    cout << "\nWorst case (In reverse Order):\n ---------------------------------------";

    for (int size: sizes) {
        vector<int> base = generateArray(size, true);
        vector<int> arr1 = base;
        vector<int> arr2 = base;

        insertionCount = 0;
        auto start1 = high_resolution_clock::now();
        insertionSort(arr1);
        auto stop1 = high_resolution_clock::now();
        auto duration1 = duration_cast<microseconds>(stop1 - start1);

        mergeCount = 0;
        auto start2 = high_resolution_clock::now();
        mergeSort(arr2, 0, size - 1);
        auto stop2 = high_resolution_clock::now();
        auto duration2 = duration_cast<microseconds>(stop2 - start2);

        cout << "\nSize: " << size << endl;
        cout << "Time elapsed (Insertion Sort): " << duration1.count() <<" microseconds." << " Iterations:" << insertionCount << endl;
        cout << "Time elapsed (MergeSort): " << duration2.count() <<" microseconds." << " Iterations:" << mergeCount << endl;
        cout << "----------------------------------------" << endl;
    }

    cout <<"\n Best Case (Sorted):\n ----------------------------------------";
    for (int size: sizes) {
        vector<int> base = generateArray(size, false);
        vector<int> arr1 = base;
        vector<int> arr2 = base;

        insertionCount = 0;
        auto start1 = high_resolution_clock::now();
        insertionSort(arr1);
        auto stop1 = high_resolution_clock::now();
        auto duration1 = duration_cast<microseconds>(stop1 - start1);

        mergeCount = 0;
        auto start2 = high_resolution_clock::now();
        mergeSort(arr2, 0, size - 1);
        auto stop2 = high_resolution_clock::now();
        auto duration2 = duration_cast<microseconds>(stop2 - start2);

        cout << "\nSize: " << size << endl;
        cout << "Time Elapsed (Insertion Sort): " << duration1.count() <<" microseconds."<< " Iterations:"<< insertionCount << endl;
        cout << "Time Elapsed (Merge Sort): " << duration2.count() <<"m icroseconds."<< " Iterations:"<<mergeCount << endl;



    }
    cout << "\nSearch Algorithms (Linear & Binary):\n";

    for (int size: sizes) {
        vector<int> arr(size);
        for (int i = 0; i < size; i++) arr[i] = i;

        int key = -1;
        int linCount = 0;
        int binCount = 0;

        auto start1 = high_resolution_clock::now();
        linearSearch(arr, key, linCount);
        auto stop1 = high_resolution_clock::now();
        auto duration1 = duration_cast<microseconds>(stop1 - start1);

        auto start2 = high_resolution_clock::now();
        binarySearch(arr, key, binCount);
        auto stop2 = high_resolution_clock::now();
        auto duration2 = duration_cast<microseconds>(stop2 - start2);

        cout << "\nSize: " << size << endl;
        cout << "Time Elapsed (Linear Search): " << duration1.count() <<" microseconds."<< " Iterations:" <<linCount<< endl;
        cout << "Time Elapsed (Binary Search): " << duration2.count() <<" microseconds."<< " Iterations:" <<binCount<< endl;
    }
    return 0;
    }



