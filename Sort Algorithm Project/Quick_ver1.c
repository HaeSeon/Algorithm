#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int count_q1 = 0;;


void QuickSort(int array[], int p, int r) {
	
	if (p < r) {
		count_q1++;
		int q = Partition(array, p, r );
		QuickSort(array, p, q - 1);
		QuickSort(array, q + 1, r);	
	}
	else {
		return;
	}
	 
}

int Partition(int array[], int p, int r) {
	int pivot = array[r];
	int i;
	int q=p;
	for (i = p; i < r; i++) {
		if (array[i] <= pivot) {
			swap(&array[i],&array[q]);
			q++;	  
			count_q1++;
		}
	}
	swap(&array[r], &array[q]);
	return q;

}



int main_Quick_1(int array[], int length) {
	//printf("original array : ");
	for (int a = 0; a < length; a++) {
		//printf("%d ", array[a]);
	}
	//clock함수를 이용한 실핼시간측정
	clock_t start, end;
	start = clock(); 
	QuickSort( array,0,length - 1 );
	end = clock(); 
	float result = (float)(end - start) / CLOCKS_PER_SEC;

	//printf("\nsorted array : ");
	for (int a = 0; a < length; a++) {
		//printf("%d ", array[a]);
	}
	printf("\nnumber of key : %d 번", count_q1);
	printf("\nclock time : %f 초", result);

	return array;

}
