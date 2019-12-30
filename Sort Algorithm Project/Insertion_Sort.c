#include <stdio.h>
#include<time.h>

count_i = 0;  //compcount 계산

void InsertionSort(int array[],int length) {
	int i, j, key;
	i = 0;
	for (j = 1; j < length; j++) {
		key = array[j];
		i = j - 1;
		count_i++;
		while (i >= 0 && array[i] > key){
			array[i + 1] = array[i];
			i = i - 1;
			count_i++;
		}
		array[i + 1] = key;
	}

}

int main_insertion(int array[], int length) {
	//printf("original array : ");
	for (int a = 0; a < length; a++) {
		//printf("%d ", array[a]);
	}
	//clock함수를 이용한 실핼시간측정
	clock_t start, end;
	start = clock();
	InsertionSort(array, length);
	end = clock();
	float result = (float)(end - start) /CLOCKS_PER_SEC;

	//printf("\nsorted array : ");
	for (int a = 0; a < length; a++) {
		//printf("%d ", array[a]);
	}
	printf("\nnumber of key : %d 번", count_i);
	printf("\nclock time : %f 초", result);
	return array;
}
