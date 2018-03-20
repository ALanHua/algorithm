//
//  InsertionSort.h
//  02_Sort_Basic
//
//  Created by yhp on 2018/3/20.
//  Copyright © 2018年 none. All rights reserved.
//

#ifndef InsertionSort_h
#define InsertionSort_h

#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
void insertionSort(T arr[],int n){
    for (int i = 1; i < n; ++i) {
        for (int j = i; j > 0; --j) {
            if (arr[j] < arr[j-1]) {
                swap(arr[j], arr[j-1]);
            }else{
                break;
            }
        }
    }
}

template <typename T>
void insertionSortAdvance(T arr[],int n){
    for (int i = 1; i < n; ++i) {
        T e = arr[i];
        int j;
        for (j = i; j > 0; --j) {
            if (arr[j-1] > e) {
                arr[j] = arr[j-1];
            }else{
                break;
            }
        }
        arr[j] = e;
    }
}

#endif /* InsertSort_h */
