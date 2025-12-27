#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int idx;
	int size;
	int *ptr;
} Arr;

Arr arr;

int* add(int num, int *ptr){
	int *tmp;
	int new_size = 0;
	if(arr.idx < arr.size){
		arr.ptr[arr.idx] = num;
		arr.idx++;
	}else{
		new_size = arr.size * 2;
		tmp = realloc(arr.ptr, new_size * sizeof(int));
		if (!tmp){
			perror("realoc problem");
			return NULL;
		}

		arr.ptr = tmp;
		arr.size = new_size;
		arr.ptr[arr.idx] = num;
		arr.idx++;
	}
	return arr.ptr;
}

int main(){
	arr.size = 10;
	arr.idx = 0;
	
	arr.ptr = (int*) malloc(arr.size * sizeof(int));

	printf("size of array: %d \n", arr.size);
	if(arr.ptr == NULL){
		printf("memory not allocated\n");
		return 0;
	}
	
	for (int k = 0; k < arr.size; k++){
		printf("%d ", arr.ptr[k]);
	}

	for (int i = 0; i < 20; i++){
		printf("\n");
		arr.ptr = add(2, arr.ptr);
		if(arr.ptr == NULL){
			printf("add failed\n");
			return 1;
		}
		printf("step:\n");
		for (int k = 0; k < arr.size; k++){
			printf("%d ", arr.ptr[k]);
		}
	}
	
	free(arr.ptr);
	printf("\n");
	printf("size of array: %d \n", arr.size);
}
