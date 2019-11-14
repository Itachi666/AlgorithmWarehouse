//
// Created by Niujx on 2019/10/3.
//

#include <algorithm>
#include "Sort.h"

void Sort::InsertSort(int *a, int n) {
    for (int i = 1; i < n; i++) {
        int j = i;
        while (a[j] < a[j - 1] && j > 0) {
            std::swap(a[j], a[j - 1]);
            j--;
        }
    }
}

void Sort::BubbleSort(int *a, int n) {
    for (int j = 0; j < n - 1; j++)
        for (int i = 0; i < n - 1 - j; i++)
            if (a[i] > a[i + 1])
                std::swap(a[i], a[i + 1]);
}

void Sort::SelectSort(int *a, int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j])
                std::swap(a[i], a[j]);
}

void Sort::QuickSort(int *a, int l, int r) {
    int i, j, x, y;
    i = l;
    j = r;
    x = a[(l + r) / 2];
    do {
        while (a[i] < x) i++;
        while (a[j] > x) j--;
        if (i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    } while (i <= j);
    if (l < j) QuickSort(a, l, j);
    if (i < r) QuickSort(a, i, r);
}

void Sort::MergeSort(int *a, int l, int r) {
    int i, j, k, m;
    if (r - l == 1)
        return;
    m = (l + r) / 2;

    MergeSort(a, l, m);
    MergeSort(a, m, r);

    int o[1000];
    i = l;
    j = m;
    k = l;
    while (i < m || j < r) {
        if (i == m) {
            o[k++] = a[j++];
            continue;
        }

        if (j == r) {
            o[k++] = a[i++];
            continue;
        }

        if (a[i] < a[j])
            o[k++] = a[i++];
        else
            o[k++] = a[j++];
    }

    for (i = l; i < r; i++)
        a[i] = o[i];
}

void Sort::healthy(int *a, int k, int n) {
    int left_child = 2 * k + 1;
    int right_child = 2 * k + 2;
    int max = k;
    if (left_child < n && a[left_child] > a[max])
        max = left_child;
    if (right_child < n && a[right_child] > a[max])
        max = right_child;
    if (max != k)
    {
        std::swap(a[k], a[max]);
        healthy(a, max, n);
    }
}

void Sort::HeapSort(int *a, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        healthy(a, i, n);

    int size = n-1;

    while (size > 0)
    {
        std::swap(a[0],a[size]);
        healthy(a,0,size);
        size--;
    }
}



