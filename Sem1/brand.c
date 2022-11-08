#include <stdio.h>

int main()
{
	int arr1[5] = {40,7,25,28,33};
	int arr2[4] = {11,80,57, 61};
	int arr3[9];

	for (int i = 0; i < 5; i++) {
		int temp;
		temp = arr1[i];
		arr1[i] = arr1[i+1];
		arr1[i+1] = temp;
	}
	for (int j = 0; j < 4; j++) {
		int temp1;
		temp1 = arr2[j];
		arr2[j] = arr2[j+1];
		arr2[j+1] = temp1;
	}

	int i = 0, j = 0, k = 0;
	while (i < 5 && j < 4) {
		if (arr1[i] < arr2[j]) {
			arr3[k++] = arr1[i++];
		}
		else {
			arr3[k++] = arr2[j++];
		}
	}
	while (i < 5) {
		arr3[k++] = arr1[i++];
	}
	while (j < 4) {
		arr3[k++] = arr2[j++];
	}
	for (int i = 0; i < 9; i++) {
		printf("%d,",arr3[i]);
	}
}
