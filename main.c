#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int idx;
	int size;
} Arr;

Arr arr;

int* add(int num, int *ptr){
	int *tmp;
	if(arr.idx < arr.size){
		ptr[arr.idx] = num;
		arr.idx++;
	}else{
		arr.size = arr.size + arr.size;
		tmp = realloc(ptr, arr.size * sizeof(int));
		if (!tmp){
			perror("realoc problem");
			free(tmp);
			return 1;
		}

		ptr = tmp;
	}
	return ptr;
}

int main(){
	arr.size = 10;
	int *ptr;
	arr.idx = 0;
	
	ptr = (int*) malloc(arr.size * sizeof(int));

	printf("size of array %d: \n", arr.size);
	if(ptr == NULL){
		printf("memory not allocated\n");
		return 0;
	}
	for (int k = 0; k < arr.size; k++){
		printf("%d ", ptr[k]);
	}

	printf("\n");

	ptr = add(2, ptr);
	printf("after insertion:\n");
	for (int k = 0; k < arr.size; k++){
		printf("%d ", ptr[k]);
	}
	printf("\n");
	
	ptr = add(2, ptr);
	printf("after insertion:\n");
	for (int k = 0; k < arr.size; k++){
		printf("%d ", ptr[k]);
	}

	printf("\n");

	ptr = add(2, ptr);
	ptr = add(2, ptr);
	ptr = add(2, ptr);
	ptr = add(2, ptr);
	ptr = add(2, ptr);
	ptr = add(2, ptr);
	ptr = add(2, ptr);
	ptr = add(2, ptr);
	ptr = add(2, ptr);
	ptr = add(2, ptr);
	ptr = add(2, ptr);
	ptr = add(2, ptr);

	printf("after insertion:\n");
	for (int k = 0; k < arr.size; k++){
		printf("%d ", ptr[k]);
	}
	free(ptr);

	printf("size of array %d: \n", arr.size);
}
