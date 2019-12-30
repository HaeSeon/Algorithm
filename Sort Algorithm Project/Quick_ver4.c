#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int count_q4 = 0;



void QuickSort_4(int array[], int p, int r) {

	if (p < r) {
		count_q4++;
		int q = Partition_4(array, p, r);
		QuickSort_4(array, p, q - 1);
		QuickSort_4(array, q + 1, r);
	}
	else {
		return;
	}
}


int Partition_4(int array[], int p, int r) {
	int i;
	int q = p;

	//랜덤하게 3개의 배열값을 선택
	srand(time(NULL));
	int num1 = p + (rand() % (r - p + 1));
	int num2 = p + (rand() % (r - p + 1));
	int num3 = p + (rand() % (r - p + 1));

	//랜덤하게 뽑은 세 배열값의 중간값을 피벗으로 결정
	if (array[num1] > array[num2]) {
		swap(&array[num1], &array[num2]);
		count_q4++;
	}
	if (array[num2] > array[num3]) {
		swap(&array[num2], &array[num3]);
		count_q4++;
	}
	if (array[num1] > array[num2]) {
		swap(&array[num1], &array[num2]);
		count_q4++;
	}
	swap(&array[num2], &array[r]);
	int pivot = array[r];



	for (i = p; i < r; i++) {
		if (array[i] <= pivot) {
			count_q4++;
			swap(&array[i], &array[q]);
			q++;
		}
	}
	swap(&array[r], &array[q]);

	return q;

}

int main_Quick_4(int array[], int length) {

	//printf("original array : ");
	for (int a = 0; a < length; a++) {
		//printf("%d ", array[a]);
	}
	//clock함수를 이용한 실핼시간측정
	clock_t start, end;
	start = clock();
	QuickSort_4(array, 0, length - 1);
	end = clock();
	float result = (float)(end - start) / CLOCKS_PER_SEC;

	//printf("\nsorted array : ");
	for (int a = 0; a < length; a++) {
		//printf("%d ", array[a]);
	}
	printf("\nnumber of key : %d 번", count_q4);
	printf("\nclock time : %f 초", result);

	return array;
}
