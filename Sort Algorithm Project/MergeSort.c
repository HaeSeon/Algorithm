#include <stdio.h>
#include<time.h>
int count_m = 0;


void Merge(int array[],int p,int q,int r){
	int i, j, k, a;
	int resultarray[1024] = {0};
	i = p;
	j = q + 1;
	k = p;

	while (i <= q && j <= r) {
		if (array[i] < array[j]) {
			resultarray[k] = array[i];
			k++;
			i++;
			count_m++;
		
		}
		else {
			resultarray[k] = array[j];
			j++;
			k++;
			count_m++;
		}
	}

	while (i <= q) {
		resultarray[k] = array[i];
		k++;
		i++;
		count_m++;
	}
	while (j <= r) {
		resultarray[k] = array[j];
		j++;
		k++;
		count_m++;
	}

	k--;

	for (a = p; a <= r; a++) {
		count_m++;
		array[a] = resultarray[a];
	}

}


void MergeSort(int array[],int p,int r) {
	if (p < r) {
		count_m++;
		int q = p+(r-p) / 2;
		MergeSort(array, p, q);
		MergeSort(array, q + 1, r);
		Merge(array, p, q, r);
	}


}



int main_Merge(int array[], int length) {

	//printf("original array : ");
	for (int a = 0; a < length; a++) {
		//printf("%d ", array[a]);
	}
	//clock함수를 이용한 실핼시간측정
	clock_t start, end;
	start = clock();
	MergeSort(array, 0, length - 1);
	end = clock();
	float result = (float)(end - start) / CLOCKS_PER_SEC;

	//printf("\nsorted array : ");
	for (int a = 0; a < length; a++) {
	//	printf("%d ", array[a]);
	}
	printf("\nnumber of key : %d 번", count_m);
	printf("\nclock time : %f 초", result);
	return array;
}
