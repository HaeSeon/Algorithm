#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<time.h>
int count_q2 = 0;

void QuickSort_2(int array[], int p, int r) {
	if (p < r) {
		count_q2++;
		int q = Partition_2(array, p, r);
		QuickSort_2(array, p, q - 1);
		QuickSort_2(array, q + 1, r);
	}
	else {
		return;
	}
}


int Partition_2(int array[], int p, int r) {
	srand(time(NULL));

	int num = p + (rand() % (r - p + 1));    //배열 크기보다 작게 랜덤피벗 설정
	swap(&array[num], &array[r]);

	int pivot = array[r];
	int i;
	int q = p;


	for (i = p; i < r; i++) {
		if (array[i] <= pivot) {
			count_q2++;
			swap(&array[i], &array[q]);
			q++;
		}
	}
	swap(&array[r], &array[q]);

	return q;


}






int main_Quick_2(int array[], int length) {

	//printf("original array : ");
	for (int a = 0; a < length; a++) {
		//printf("%d ", array[a]);
	}
	//clock함수를 이용한 실핼시간측정
	clock_t start, end;
	start = clock();
	QuickSort_2(array, 0, length - 1);
	end = clock();
	float result = (float)(end - start) / CLOCKS_PER_SEC;

	//printf("\nsorted array : ");
	for (int a = 0; a < length; a++) {
		//printf("%d ", array[a]);
	}
	printf("\nnumber of key : %d 번", count_q2);
	printf("\nclock time : %f 초", result);
	return array;
}
