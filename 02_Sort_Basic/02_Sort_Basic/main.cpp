//
//  main.cpp
//  02_Sort_Basic
//
//  Created by yhp on 2018/3/19.
//  Copyright © 2018年 none. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include "SortTestHelper.h"
#include "SlectionSort.h"
#include "InsertionSort.h"
#include "BubbleSort.h"


/**
 排序算法总结:
 o(n*n):
 优化后插入排序的算法效率要高于选择排序
 */
int main(int argc, const char * argv[]) {

    int n = 10000;
    
    int* arr = SortTestHelper::generateRandomArray(n, 0, n);
//    SortTestHelper::printArray(arr, n);
//    SortTestHelper::testSort("slectionSort", selectionSort, arr, n);
//    SortTestHelper::testSort("insertionSortAdvance", insertionSortAdvance, arr, n);
    SortTestHelper::testSort("bubbleSort", bubbleSortAdvance2, arr, n);
//    SortTestHelper::printArray(arr, n);
    delete [] arr;
    
    return 0;
}
