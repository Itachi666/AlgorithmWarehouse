//
// Created by Niujx on 2019/10/3.
//

#ifndef ALGORITHMWAREHOUSE_SORT_H
#define ALGORITHMWAREHOUSE_SORT_H


class Sort {
public:
    static void BubbleSort(int a[], int n);

    static void InsertSort(int a[], int n);

    static void SelectSort(int a[], int n);

    static void QuickSort(int a[], int l, int r);

    static void MergeSort(int a[], int l, int r);

    static void HeapSort(int a[], int n);

private:
    static void healthy(int a[], int k, int n);
};


#endif //ALGORITHMWAREHOUSE_SORT_H
