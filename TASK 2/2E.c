#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int val;
    int listIdx;
    int idxInList;
} HeapNode;

void swap(HeapNode *a, HeapNode *b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(HeapNode heap[], int size, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < size && heap[left].val < heap[smallest].val)
        smallest = left;

    if (right < size && heap[right].val < heap[smallest].val)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        minHeapify(heap, size, smallest);
    }
}

int main() {
    int list0[] = {4, 10, 15, 24, 26};
    int list1[] = {0, 9, 12, 20};
    int list2[] = {5, 18, 22, 30};

    int *lists[] = {list0, list1, list2};
    int sizes[] = {5, 4, 4};
    int k = 3;
	   HeapNode *heap = malloc(k * sizeof(HeapNode));
    int heapSize = 0;
    int currentMax = INT_MIN;
    for (int i = 0; i < k; i++) {
        heap[heapSize].val = lists[i][0];
        heap[heapSize].listIdx = i;
        heap[heapSize].idxInList = 0;

        if (lists[i][0] > currentMax)
            currentMax = lists[i][0];

        heapSize++;
    }

    for (int i = heapSize/2 - 1; i >= 0; i--)
        minHeapify(heap, heapSize, i);

    int bestStart = 0, bestEnd = INT_MAX;

    while (1) {
        int currentMin = heap[0].val;

        if (currentMax - currentMin < bestEnd - bestStart) {
            bestStart = currentMin;
            bestEnd = currentMax;
        }

        HeapNode root = heap[0];

        if (root.idxInList + 1 == sizes[root.listIdx])
            break;

        heap[0].idxInList++;
        heap[0].val = lists[root.listIdx][heap[0].idxInList];

        if (heap[0].val > currentMax)
            currentMax = heap[0].val;

        minHeapify(heap, heapSize, 0);
    }

    printf("Smallest range is [%d, %d]\n", bestStart, bestEnd);

    free(heap);
    return 0;
}
