//
//  main.cpp
//  03_Sort_ Advance
//
//  Created by yhp on 2018/3/25.
//  Copyright © 2018年 none. All rights reserved.
//

#include <iostream>
#include "SortTestHelper.h"
#include "MergeSort.h"

int main(int argc, const char * argv[]) {
    
    int n = 10000;
    
    int* arr = SortTestHelper::generateRandomArray(n, 0, n);
//        SortTestHelper::printArray(arr, n);
    SortTestHelper::testSort("mergeSort", mergeSort2, arr, n);
//        SortTestHelper::printArray(arr, n);
    delete [] arr;
    
    return 0;
}
