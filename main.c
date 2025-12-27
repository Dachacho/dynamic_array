#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int idx;
	int size;
	int *ptr;
} Arr;

Arr arr;

int* add(int num){
	int *tmp;
	int new_size = 0;
	if(arr.idx < arr.size){
		arr.ptr[arr.idx] = num;
		arr.idx++;
	}else{
		//times it by 2 to avoid 1.5 multiply overhead
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
	arr.size = 8;
	arr.idx = 0;
	
	arr.ptr = malloc(arr.size * sizeof(int));
	if(arr.ptr == NULL){
		printf("memory allocation failed\n");
		return 1;
	}

	printf("size of array: %d \n", arr.size);
	if(arr.ptr == NULL){
		printf("memory not allocated\n");
		return 0;
	}
	
	for (int k = 0; k < arr.size; k++){
		printf("%d ", arr.ptr[k]);
	}

	for (int i = 0; i < 2000; i++){
		arr.ptr = add(2);
		if(arr.ptr == NULL){
			printf("add failed\n");
			return 1;
		}
	}	
	
	free(arr.ptr);
	printf("\n");
	printf("size of array: %d \n", arr.size);
}
