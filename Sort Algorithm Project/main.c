#include <stdio.h>
#include <stdlib.h>
#include<time.h>



int main() {
	//input배열 만들기
	int sorted_array[32]={0};		//정렬된 크기32의 배열
	for (int i = 0; i < 32; i++)
		sorted_array[i] = i;

	int random_array[32] = { 0 };		 //정렬되지않은 크기 32의 배열
	Generate_Array(random_array, 32);

	int big_size_array[1024] = { 0 };		 //정렬되지않은 크기 1024의 배열
	Generate_Array(big_size_array, 1024);


	//input배열 파일쓰기
	FILE* fp = NULL;
	fopen_s(&fp, "C:\\Users\\user\\source\\repos\\sort_algorithms\\inputfile.txt", "w"); 
	if (fp == NULL) {
		fprintf(stderr, "파일을 쓸 수 없습니다.");
		return -1;                //파일을 쓸 수 없을 때(-1의 반환은 비정상적 종료 의미)
	}
	fprintf(fp, "sorted_array[32] : ");
	for (int i = 0; i < 32; i++) 
		fprintf(fp, "%d " ,sorted_array[i]);
	fprintf(fp, "\nrandom_array[32] : ");
	for (int i = 0; i < 32; i++)
		fprintf(fp, "%d ", random_array[i]);
	fprintf(fp, "\nbig_size_array[32] : ");
	for (int i = 0; i < 1024; i++)
		fprintf(fp, "%d ", big_size_array[i]);

	fclose(fp);

	//outputfile 쓰기
	FILE* fw = NULL;
	fopen_s(&fw, "C:\\Users\\user\\source\\repos\\sort_algorithms\\outputfile.txt", "w");
	if (fp == NULL) {
		fprintf(stderr, "파일을 쓸 수 없습니다.");
		return -1;                //파일을 쓸 수 없을 때(-1의 반환은 비정상적 종료 의미)
	}


//InsertionSort sorted32함수 실행
	int* insertion_result_sorted_32;
	printf("<<<InsertionSort sorted 32>>>\n");
	insertion_result_sorted_32 = main_insertion(sorted_array, 32);
	fprintf(fw, "insertion_result_sorted_32 : ");
	for (int i = 0; i < 32; i++) {
		fprintf(fw,"%d ", insertion_result_sorted_32[i]);
	}
	fprintf(fw, "\n");
	printf("\n\n--------------------------------------------------------------------------------------\n\n");


//InsertionSort random32 함수 실행
	int* insertion_result_random_32;
	printf("<<<InsertionSort random 32>>>\n");
	insertion_result_random_32 = main_insertion(random_array, 32);
	fprintf(fw, "insertion_result_random_32 : ");
	for (int i = 0; i < 32; i++) {
		fprintf(fw, "%d ", insertion_result_random_32[i]);
	}
	fprintf(fw, "\n");
	printf("\n\n--------------------------------------------------------------------------------------\n\n");

//InsertionSort bigsize 함수 실행
	int* insertion_big_size_array;
	printf("<<<insertion_big_size_array>>>\n");
	insertion_big_size_array = main_insertion(big_size_array, 1024);
	fprintf(fw, "insertion_big_size_array : ");
	for (int i = 0; i < 1024; i++) {
		fprintf(fw, "%d ", insertion_big_size_array[i]);
	}
	fprintf(fw, "\n");
	printf("\n\n--------------------------------------------------------------------------------------\n\n");




//MergeSort sorted32함수 실행
	int* merge_result_sorted_32;
	printf("<<<MergeSort sorted 32>>>\n");
	merge_result_sorted_32 = main_Merge(sorted_array, 32);
	fprintf(fw, "Merge_result_sorted_32 : ");
	for (int i = 0; i < 32; i++) {
		fprintf(fw, "%d ", merge_result_sorted_32[i]);
	}
	fprintf(fw, "\n");
	printf("\n\n--------------------------------------------------------------------------------------\n\n");


//MergeSort random32 함수 실행
	int* merge_result_random_32;
	printf("<<<mergeSort random 32>>>\n");
	merge_result_random_32 = main_Merge(random_array, 32);
	fprintf(fw, "merge_result_random_32 : ");
	for (int i = 0; i < 32; i++) {
		fprintf(fw, "%d ", merge_result_random_32[i]);
	}
	fprintf(fw, "\n");
	printf("\n\n--------------------------------------------------------------------------------------\n\n");

//MergeSort bigsize 함수 실행
	int* merge_big_size_array;
	printf("<<<merge_big_size_array>>>\n");
	merge_big_size_array = main_Merge(big_size_array, 1024);
	fprintf(fw, "merge_big_size_array : ");
	for (int i = 0; i < 1024; i++) {
		fprintf(fw, "%d ", merge_big_size_array[i]);
	}
	fprintf(fw, "\n");
	printf("\n\n--------------------------------------------------------------------------------------\n\n");





//HeapSort sorted32함수 실행
	int* heap_result_sorted_32;
	printf("<<<heapSort sorted 32>>>\n");
	heap_result_sorted_32 = main_Heap(sorted_array, 32);
	fprintf(fw, "heap_result_sorted_32 : ");
	for (int i = 0; i < 32; i++) {
		fprintf(fw, "%d ", heap_result_sorted_32[i]);
	}
	fprintf(fw, "\n");
	printf("\n\n--------------------------------------------------------------------------------------\n\n");


//HeapSort random32 함수 실행
	int* heap_result_random_32;
	printf("<<<heapSort random 32>>>\n");
	heap_result_random_32 = main_Heap(random_array, 32);
	fprintf(fw, "heap_result_random_32 : ");
	for (int i = 0; i < 32; i++) {
		fprintf(fw, "%d ", heap_result_random_32[i]);
	}
	fprintf(fw, "\n");
	printf("\n\n--------------------------------------------------------------------------------------\n\n");

//HeapSort bigsize 함수 실행
	int* heap_big_size_array;
	printf("<<<heap_big_size_array>>>\n");
	heap_big_size_array = main_Heap(big_size_array, 1024);
	fprintf(fw, "heap_big_size_array : ");
	for (int i = 0; i < 1024; i++) {
		fprintf(fw, "%d ", heap_big_size_array[i]);
	}
	fprintf(fw, "\n");
	printf("\n\n--------------------------------------------------------------------------------------\n\n");






//QuickSort_v1 sorted32 함수 실행
	int* quick_v1_result_sorted_32;
	printf("<<<quick_v1 sorted 32>>>\n");
	quick_v1_result_sorted_32 = main_Quick_1(sorted_array, 32);
	fprintf(fw, "quick_v1_result_sorted_32 : ");
	for (int i = 0; i < 32; i++) {
		fprintf(fw, "%d ", quick_v1_result_sorted_32[i]);
	}
	fprintf(fw, "\n");
	printf("\n\n--------------------------------------------------------------------------------------\n\n");


//QuickSort_v1 random32 함수 실행
	int* quick_v1_result_random_32;
	printf("<<<quick_v1 random 32>>>\n");
	quick_v1_result_random_32 = main_Quick_1(random_array, 32);
	fprintf(fw, "quick_v1_result_random_32 : ");
	for (int i = 0; i < 32; i++) {
		fprintf(fw, "%d ", quick_v1_result_random_32[i]);
	}
	fprintf(fw, "\n");
	printf("\n\n--------------------------------------------------------------------------------------\n\n");

//QuickSort_v1 bigsize 함수 실행
	int* quick_v1_big_size_array;
	printf("<<<quick_v1_big_size_array>>>\n");
	quick_v1_big_size_array = main_Quick_1(big_size_array, 1024);
	fprintf(fw, "quick_v1_big_size_array : ");
	for (int i = 0; i < 1024; i++) {
		fprintf(fw, "%d ", quick_v1_big_size_array[i]);
	}
	fprintf(fw, "\n");
	printf("\n\n--------------------------------------------------------------------------------------\n\n");







//QuickSort_v2 sorted32 함수 실행
	int* quick_v2_result_sorted_32;
	printf("<<<quick_v2 sorted 32>>>\n");
	quick_v2_result_sorted_32 = main_Quick_2(sorted_array, 32);
	fprintf(fw, "quick_v2_result_sorted_32 : ");
	for (int i = 0; i < 32; i++) {
		fprintf(fw, "%d ", quick_v2_result_sorted_32[i]);
	}
	fprintf(fw, "\n");
	printf("\n\n--------------------------------------------------------------------------------------\n\n");


//QuickSort_v2 random32 함수 실행
	int* quick_v2_result_random_32;
	printf("<<<quick_v2 random 32>>>\n");
	quick_v2_result_random_32 = main_Quick_2(random_array, 32);
	fprintf(fw, "quick_v2_result_random_32 : ");
	for (int i = 0; i < 32; i++) {
		fprintf(fw, "%d ", quick_v2_result_random_32[i]);
	}
	fprintf(fw, "\n");
	printf("\n\n--------------------------------------------------------------------------------------\n\n");

//QuickSort_v2 bigsize 함수 실행
	int* quick_v2_big_size_array;
	printf("<<<quick_v2_big_size_array>>>\n");
	quick_v2_big_size_array = main_Quick_2(big_size_array, 1024);
	fprintf(fw, "quick_v2_big_size_array : ");
	for (int i = 0; i < 1024; i++) {
		fprintf(fw, "%d ", quick_v2_big_size_array[i]);
	}
	fprintf(fw, "\n");
	printf("\n\n--------------------------------------------------------------------------------------\n\n");



//QuickSort_v3 sorted32 함수 실행
	int* quick_v3_result_sorted_32;
	printf("<<<quick_v3 sorted 32>>>\n");
	quick_v3_result_sorted_32 = main_Quick_3(sorted_array, 32);
	fprintf(fw, "quick_v3_result_sorted_32 : ");
	for (int i = 0; i < 32; i++) {
		fprintf(fw, "%d ", quick_v3_result_sorted_32[i]);
	}
	fprintf(fw, "\n");
	printf("\n\n--------------------------------------------------------------------------------------\n\n");


//QuickSort_v3 random32 함수 실행
	int* quick_v3_result_random_32;
	printf("<<<quick_v3 random 32>>>\n");
	quick_v3_result_random_32 = main_Quick_3(random_array, 32);
	fprintf(fw, "quick_v3_result_random_32 : ");
	for (int i = 0; i < 32; i++) {
		fprintf(fw, "%d ", quick_v3_result_random_32[i]);
	}
	fprintf(fw, "\n");
	printf("\n\n--------------------------------------------------------------------------------------\n\n");

//QuickSort_v3 bigsize 함수 실행
	int* quick_v3_big_size_array;
	printf("<<<quick_v3_big_size_array>>>\n");
	quick_v3_big_size_array = main_Quick_3(big_size_array, 1024);
	fprintf(fw, "quick_v3_big_size_array : ");
	for (int i = 0; i < 1024; i++) {
		fprintf(fw, "%d ", quick_v3_big_size_array[i]);
	}
	fprintf(fw, "\n");
	printf("\n\n--------------------------------------------------------------------------------------\n\n");


	//QuickSort_v4 sorted32 함수 실행
	int* quick_v4_result_sorted_32;
	printf("<<<quick_v4 sorted 32>>>\n");
	quick_v4_result_sorted_32 = main_Quick_4(sorted_array, 32);
	fprintf(fw, "quick_v4_result_sorted_32 : ");
	for (int i = 0; i < 32; i++) {
		fprintf(fw, "%d ", quick_v4_result_sorted_32[i]);
	}
	fprintf(fw, "\n");
	printf("\n\n--------------------------------------------------------------------------------------\n\n");


	//QuickSort_v4 random32 함수 실행
	int* quick_v4_result_random_32;
	printf("<<<quick_v4 random 32>>>\n");
	quick_v4_result_random_32 = main_Quick_4(random_array, 32);
	fprintf(fw, "quick_v4_result_random_32 : ");
	for (int i = 0; i < 32; i++) {
		fprintf(fw, "%d ", quick_v4_result_random_32[i]);
	}
	fprintf(fw, "\n");
	printf("\n\n--------------------------------------------------------------------------------------\n\n");

	//QuickSort_v4 bigsize 함수 실행
	int* quick_v4_big_size_array;
	printf("<<<quick_v4_big_size_array>>>\n");
	quick_v4_big_size_array = main_Quick_4(big_size_array, 1024);
	fprintf(fw, "quick_v4_big_size_array : ");
	for (int i = 0; i < 1024; i++) {
		fprintf(fw, "%d ", quick_v4_big_size_array[i]);
	}
	fprintf(fw, "\n");
	printf("\n\n--------------------------------------------------------------------------------------\n\n");
















}
