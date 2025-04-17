//
// Created by marce on 2025-04-08.
//

#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include <vector>
using namespace std;

extern long long insertionCount;
extern long long mergeCount;

void insertionSort(vector<int>& arr);
void mergeSort(vector<int>& arr, int left, int right);
void merge(vector<int>& arr, int left, int mid, int right);


#endif //SORTING_ALGORITHMS_H
