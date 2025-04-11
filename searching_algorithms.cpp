//
// Created by marce on 2025-04-08.
//

#include "searching_algorithms.h"

int binarySearch(const vector<int>& arr, int key, int& count) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        count ++;
        int mid = (low + high) / 2;
        if (arr[mid] == key) return mid;
        if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }

    return -1;
}

int linearSearch(const vector<int>& arr, int key, int& count) {
    for (int i = 0; i < arr.size(); i++) {
        count ++;
        if (arr[i] == key) return i;
    }
    return -1;
}
