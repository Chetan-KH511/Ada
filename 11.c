#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void merge(int arr[], int l, int m, int r) {
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1], R[n2];

	for (int i = 0; i < n1; i++)
		L[i] = arr[l + i];
	
	for (int j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];
	
	int i = 0, j = 0, k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		} else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}
void mergeSort(int arr[], int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

int main() {
	srand(time(NULL)); 
	FILE *fp;
	fp = fopen("time_complexity_data.csv", "w");
	fprintf(fp, "n,Time Taken\n");

	int n_values[] = {6000, 7000, 8000, 9000, 10000}; 
	int num_values = sizeof(n_values) / sizeof(n_values[0]);

	for (int i = 0; i < num_values; i++) {
		int n = n_values[i];
		int arr[n];
		
		for (int j = 0; j < n; j++) {
			arr[j] = rand() % 1000; 
		}

		clock_t start_time = clock(); 
		mergeSort(arr, 0, n - 1); 
		clock_t end_time = clock(); 
		double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
		printf("Time taken to sort %d elements: %.6f seconds\n", n, time_taken);
		fprintf(fp, "%d,%.6f\n", n, time_taken);
	}

	fclose(fp);
	return 0;
}

