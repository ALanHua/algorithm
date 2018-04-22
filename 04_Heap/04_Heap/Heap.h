//
//  Heap.h
//  04_Heap
//
//  Created by yhp on 2018/3/14.
//  Copyright © 2018年 none. All rights reserved.
//

#ifndef Heap_h
#define Heap_h
#include <cassert>
#include <algorithm>
using namespace std;

template <typename Item>
class MaxHeap {
private:
//    成员变量
    Item*  data_;
    int    count_;
    int    capacity_;
//    成员方法

    /**
     将子节点与自己的父节点比较，如果比父节点大就调整位置
     @param k 插入下标
     如:
                    62
                42      30
            28    (52)
        *52 是添加到数组的元素，但这样不符合最大堆的定义
            所以需要与其父节点比较
     */
    void shiftUp(int k){
        while (k > 1 && data_[k/2] < data_[k]) {
            swap(data_[k/2], data_[k]);
            k /= 2;
        }
    }
    
    /**
     左右节点比较谁大就和谁交换，类似上面的逆向过程
     @param k 位置
     */
    void shiftDown(int k){
        //  k*2 小于count 表示有节点
        while (k * 2 <= count_) {
            int j = k * 2;
            //   左右节点比较谁大就和谁交换
            if (data_[j + 1] > data_[j] && j + 1 <= count_) {
                j++;
            }
            swap(data_[k], data_[j]);
            k = j;
        }
    }
    
public:
//    构造及析构
    MaxHeap(int capacity){
        data_     = new Item[capacity + 1];
        count_    = 0;
        capacity_ = capacity;
    }
    ~MaxHeap(){
        delete [] data_;
    }
//    成员函数
    
    /**
     堆中元素个数
     @return 个数
     */
    int size(){
        return count_;
    }
    
    /**
     判断堆是否为空
     @return bool
     */
    bool isEmpty(){
        return count_ == 0;
    }
    
    /**
     向堆中插入元素
     @param item 元素
     */
    void insert(Item item){
        assert(count_ + 1 <= capacity_);
        data_[count_ + 1] = item;
        // 完全二叉树操作
        shiftUp(count_ + 1);
        count_++;
    }
    
    /**
     取出最大元素
     @return 元素
     */
    Item extractMax(){
        assert(count_ > 0);
        Item ret = data_[1];
        swap(data_[1], data_[count_]);
        --count_;
        //   对堆进行调整,找出最大数放在位置1出
        shiftDown(1);
        return ret;
    }
    
    /**
     取最大值
     @return 最大值
     */
    Item getMax(){
        assert(count_ > 0);
        return data_[1];
    }
    
};


template <typename Item>
class MinHeap {
    Item* data;
    int   count;
    int   capacity;
//    function
    void shiftUp(int k){
        while (k > 1 && data[k / 2] > data[k]) {
            swap(data[k / 2], data[k]);
            k /= 2;
        }
    }
    void shiftDown(int k){
        while (2 * k <= count) {
            int j = 2 * k;
//           判断是往左还是右子树shiftdown
            if ( j + 1 <= count && data[j + 1] < data[j]) {
                j ++;
            }
            if (data[k] <= data[j]) {
                break;
            }
            swap(data[k], data[j]);
            k = j;
        }
    }
public:
    MinHeap(int capacity){
        data  = new Item[capacity +1];
        count = 0;
        this->capacity = capacity;
    }
    ~MinHeap(){
        delete [] data;
    }
    int size(){
        return count;
    }
    
    bool isEmpty(){
        return count == 0;
    }
    
    void insert(Item item){
        assert(count + 1 <= capacity);
        data[count + 1] = item;
        shiftUp(count + 1);
        count++;
    }
    
    Item extractMin(){
        assert(count > 0);
        Item ret = data[1];
//      从数组末尾copy一个元素到数组1的位置
        swap(data[1], data[count]);
        count--;
        shiftDown(1);
        return ret;
    }
    
    Item getMin(){
        assert(count > 0);
        return data[1];
    }
    
    void show(){
        count << "| ";
        for (int i = 1; i <= count; ++i) {
            cout << data[i] << " | ";
        }
        cout << endl;
    }
    
    
};


#endif /* Heap_h */
