//
//  SlectionSort.h
//  02_Sort_Basic
//
//  Created by yhp on 2018/3/19.
//  Copyright © 2018年 none. All rights reserved.
//

#ifndef SlectionSort_h
#define SlectionSort_h

#include <iostream>
#include <algorithm>

using namespace std;

/**
 算法描述: O(n*n)
 */
template <typename T>
void selectionSort(T arr[],int n) {
    for (int i = 0; i < n; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i],arr[minIndex]);
    }
}

#endif /* SlectionSort_h */
