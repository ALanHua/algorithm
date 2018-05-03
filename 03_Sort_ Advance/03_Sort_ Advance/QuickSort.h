//
//  QuickSort.h
//  03_Sort_ Advance
//
//  Created by yhp on 2018/5/3.
//  Copyright © 2018年 none. All rights reserved.
//

#ifndef QuickSort_h
#define QuickSort_h

#include <iostream>
#include <algorithm>

using namespace std;

/**
 * 确定中间位置
 */
template <typename T>
int __partition(T arr[],int l ,int r) {
    /*
     这个地方还可以优化，<<征服C指针>> 选择的是中间位置
     */
    T v = arr[l];
    int j = l;
    for (int i = l + 1; i <= r; i++) {
        if (arr[i] < v) {
            j++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[l], arr[j]);
    return j;
}

template <typename T>
void __quickSort(T arr[],int l,int r) {
    if (l >= r) {
        return;
    }
    int p = __partition(arr,l,r);
    __quickSort(arr,l,p-1);
    __quickSort(arr,p+1,r);
}

template <typename T>
void quickSort(T arr[],int n){
    __quickSort(arr,0,n-1);
}


#endif /* QuickSort_h */
