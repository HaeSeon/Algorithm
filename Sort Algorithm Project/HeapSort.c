#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int count_h = 0;;


void MaxHeapify(int* array, int heapsize, int parent) {
	int largest = parent;
	int left = 2 * parent + 1;  //루트노드를 0으로했기때문
	int right = 2 * parent + 2;

	if (left < heapsize && array[left] > array[largest]) {
		largest = left;
		count_h++;
	}

	if (right < heapsize && array[right] > array[largest]) {
		largest = right;
		count_h++;
	}

	if (largest != parent) {
		swap(&array[parent], &array[largest]);
		MaxHeapify(array, heapsize, largest);
		count_h++;
	}

}

void BuiildMaxHeap(int* array, int heapsize) {
	int mid = heapsize / 2 - 1;
	for (int i = mid; i >= 0; i--) {
		MaxHeapify(array, heapsize, i);
		count_h++;
	}

}

void HeapSort(int* array, int heapsize) {
	BuiildMaxHeap(array, heapsize);
	while (heapsize > 1) {
		swap(&array[0], &array[heapsize - 1]);
		heapsize--;
		MaxHeapify(array, heapsize, 0);
		count_h++;

	}
}





int main_Heap(int array[], int length) {

	//printf("original array : ");
	for (int a = 0; a < length; a++) {
		//printf("%d ", array[a]);
	}
	//clock함수를 이용한 실핼시간측정
	clock_t start, end;
	start = clock();
	HeapSort(array, length);
	end = clock();
	float result = (float)(end - start) / CLOCKS_PER_SEC;

	//printf("\nsorted array : ");
	for (int a = 0; a < length; a++) {
		//printf("%d ", array[a]);
	}
	printf("\nnumber of key : %d 번", count_h);
	printf("\nclock time : %f 초", result);
	return array;
}
