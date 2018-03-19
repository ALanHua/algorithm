//
//  SortTestHelper.h
//  02_Sort_Basic
//
//  Created by yhp on 2018/3/19.
//  Copyright © 2018年 none. All rights reserved.
//

#ifndef SortTestHelper_h
#define SortTestHelper_h

#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cassert>

using namespace std;

namespace SortTestHelper {
    
    /**
     产生一个【range_l，rang_r】范围内的随机数组
     @param n 元素个数
     @param range_l 开始位置
     @param rang_r  结束位置
     @return 数组
     */
    int* generateRandomArray(int n,int range_l,int rang_r){
        int* arr = new int[n];
        srand((unsigned int)time(NULL));
        for (int i = 0; i < n; ++i) {
            arr[i] = rand() % (rang_r - range_l + 1) + range_l;
        }
        return arr;
    }
    
    int *generateNearlyOrderedArray(int n, int swapTimes){
        int *arr = new int[n];
        for(int i = 0 ; i < n ; i ++ )
            arr[i] = i;
        
        srand((unsigned int)time(NULL));
        for( int i = 0 ; i < swapTimes ; i ++ ){
            int posx = rand()%n;
            int posy = rand()%n;
            swap( arr[posx] , arr[posy] );
        }
        return arr;
    }
    
    int *copyIntArray(int a[], int n){
        int *arr = new int[n];
        copy(a, a+n, arr);
        return arr;
    }
    
    template<typename T>
    void printArray(T arr[], int n) {
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
        return;
    }
    
    template<typename T>
    bool isSorted(T arr[], int n) {
        for (int i = 0; i < n - 1; i++){
            if (arr[i] > arr[i+1]) {
                return false;
            }
        }
        return true;
    }
    
    /**
     计算排序算法耗时
     @param sortName 算法名字
     @param sort 算法
     */
    template<typename T>
    void testSort(const string &sortName, void (*sort)(T[], int), T arr[], int n) {
        clock_t startTime = clock();
        sort(arr, n);
        clock_t endTime = clock();
        cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s"<<endl;
        assert(isSorted(arr, n));
        return;
    }
    
}



#endif /* SortTestHelper_h */
