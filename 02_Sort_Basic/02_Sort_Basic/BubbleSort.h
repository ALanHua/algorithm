//
//  BubbleSort.h
//  02_Sort_Basic
//
//  Created by yhp on 2018/3/20.
//  Copyright © 2018年 none. All rights reserved.
//

#ifndef BubbleSort_h
#define BubbleSort_h
#include <iostream>
#include <algorithm>
using namespace std;

/**
 冒泡排序原理:
 从无序序列头部开始，进行两两比较，根据大小交换位置，直到最后将最大（小）的数据元素交换到了无序队列的队尾，从而成为有序序列的一部分；下一次继续这个过程，直到所有数据元素都排好序。
 每排一次就删选出一个最大或者最小值到最后
 */
template<typename T>
void bubbleSort( T arr[] , int n){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n -(i + 1); ++j) {
            if (arr[j + 1] < arr[j]) {
                swap(arr[j + 1] , arr[j]);
            }
        }
    }
}

template<typename T>
void bubbleSortAdvance( T arr[] , int n){
    for (int i = 0; i < n; ++i) {
        bool swapped = false;
        for (int j = 0; j < n -(i + 1); ++j) {
            if (arr[j + 1] < arr[j]) {
                swap(arr[j + 1] , arr[j]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

template<typename T>
void bubbleSortAdvance2( T arr[] , int n){
    bool swapped;
    
    do {
        swapped = false;
        
        for (int i = 1; i < n; ++i) {
            if (arr[i] < arr[i-1]) {
                swap(arr[i], arr[i-1]);
                swapped = true;
            }
        }
        --n;
        
    } while (swapped);
    
    
}

#endif /* BubbleSort_h */
