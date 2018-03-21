//
//  ShellSort.h
//  02_Sort_Basic
//
//  Created by yhp on 2018/3/21.
//  Copyright © 2018年 none. All rights reserved.
//

#ifndef ShellSort_h
#define ShellSort_h

#include <iostream>
#include <algorithm>

template <typename T>
void shellSort(T arr[],int n) {
    
    for (int gap = n / 2; gap > 0; gap /= 2) {
//        插入排序
        for (int j = gap; j < n; ++j) {
            for (int i = j; i-gap >= 0; i -= gap) {
                if (arr[i-gap] > arr[i]) {
                    swap(arr[i-gap], arr[i]);
                }else{
                    break;
                }
            }
        }
    }
    
}

template <typename T>
void shellSort2(T arr[],int n) {
    
    for (int gap = n / 2; gap > 0; gap /= 2) {
        //        插入排序
        for (int j = gap; j < n; ++j) {
            T e = arr[j];
            int i;
            for (i = j; i-gap >= 0; i -= gap) {
                if (arr[i-gap] > e) {
                    arr[i] = arr[i-gap];
                }else{
                    break;
                }
            }
            arr[i] = e;
        }
    }
    
}


#endif /* ShellSort_h */
