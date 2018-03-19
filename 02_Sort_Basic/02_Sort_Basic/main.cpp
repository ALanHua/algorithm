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

int main(int argc, const char * argv[]) {

    int n = 10000;
    
    int* arr = SortTestHelper::generateRandomArray(n, 0, n);
    SortTestHelper::testSort("slectionSort", selectionSort, arr, n);
    delete [] arr;
    
    return 0;
}
