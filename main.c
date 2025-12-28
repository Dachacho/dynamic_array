#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int idx;
	int size;
	int *ptr;
} Arr;

Arr arr;

int* push(int num){
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

int* pop(){
	int *tmp;
	int new_size = 0;

	if(arr.idx * 2 < arr.size && arr.size > 8){
		new_size = arr.size / 2;
		tmp = realloc(arr.ptr, new_size * sizeof(int));
		if (!tmp){
			perror("realoc problem");
			return NULL;
		}
		arr.ptr = tmp;
		arr.ptr[arr.idx] = 0;
		arr.size = new_size;
		arr.idx--;
	}else{
		arr.ptr[arr.idx] = 0;
		arr.idx--;
	}

	return arr.ptr;
}

int* remove_at(int index){
	int i = 0;
	int *tmp;
	int new_size = 0;

	if(index < 0 || index >= arr.idx){
		perror("can't index out of range");
		return NULL;
	}
	
	for (i = index; i < arr.idx; i++){
		arr.ptr[i] = arr.ptr[i + 1];
	}

	arr.idx--;

	if(arr.idx * 2 < arr.size && arr.size > 8){
		new_size = arr.size / 2;
		tmp = realloc(arr.ptr, new_size * sizeof(int));
		if(!tmp){
			fprintf(stderr, "realoc problem");
			return NULL;
		}
		arr.ptr = tmp;
		arr.size = new_size;
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
	
	for (int k = 0; k < arr.idx; k++){
		printf("%d ", arr.ptr[k]);
	}

	printf("\n");
	for (int i = 0; i < 100; i++){
		arr.ptr = push(2);
		if(arr.ptr == NULL){
			printf("add failed\n");
			return 1;
		}
	}

	printf("\n");
	for (int k = 0; k < arr.idx; k++){
		printf("%d ", arr.ptr[k]);
	}

	for (int i = 0; i < 75; i++){
		arr.ptr = remove_at(1);
		if(arr.ptr == NULL){
			printf("add failed\n");
			return 1;
		}
	}

	printf("\n");
	for (int k = 0; k < arr.idx; k++){
		printf("%d ", arr.ptr[k]);
	}

	free(arr.ptr);
	printf("\n");
	printf("size of array: %d \n", arr.size);
}
