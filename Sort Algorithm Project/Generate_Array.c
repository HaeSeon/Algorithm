#include <stdio.h>
#include <stdlib.h>
#include<time.h>

//배열 위치 바꾸는 함수
void swap(int* aa, int* bb) {
	int temp = *aa;
	*aa = *bb;
	*bb = temp;
}


//난수 배열 생성 함수
int Generate_Array(int data[], int length) {
	srand(time(NULL));
	for (int i = 0; i < length; i++) {
		data[i] = rand() % 500;    //500이하의 수로 구성된 난수 생성
	}
	return data;
}
