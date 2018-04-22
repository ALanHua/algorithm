//
//  main.cpp
//  04_Heap
//
//  Created by yhp on 2018/3/14.
//  Copyright © 2018年 none. All rights reserved.
//

#include <iostream>
#include "Heap.h"

int main(int argc, const char * argv[]) {
    
    int a[10] = {9,10,11,8,1,3,6,5,4,7};
    MinHeap<int>* heap = new MinHeap<int>(10);
    
    for (int i = 0; i < 10; i++) {
        heap->insert(a[i]);
    }
    
    for (int i = 0; i < 10; i++) {
        printf("%d ",heap->extractMin());
    }
    printf("\n");
    
    delete heap;
    
    return 0;
}
