#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Selection Sort function
void selectionSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int min_idx = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[min_idx]) {
				min_idx = j;
			}
		}

		// Swap the found minimum element with the first element
		int temp = arr[min_idx];
		arr[min_idx] = arr[i];
		arr[i] = temp;
	}
}

int main() {
	FILE *fp;
	fp = fopen("time_complexity_data.csv", "w"); // Open a file to record time complexity data
	fprintf(fp, "n,Time Taken\n"); // Write header to the file
	srand(time(NULL)); // Seed for random number generation
	int n_values[] = {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000}; // Varying values of n
	int num_values = sizeof(n_values) / sizeof(n_values[0]);

	for (int i = 0; i < num_values; i++) {
		int n = n_values[i];
		int arr[n];
		// Generating random numbers for the array
		for (int j = 0; j < n; j++) {
			arr[j] = rand() % 1000; // Random numbers from 0 to 999
		}

		clock_t start_time = clock(); // Start the clock
		selectionSort(arr, n); // Sort the array using Selection Sort
		clock_t end_time = clock(); // End the clock
		double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
		printf("Time taken to sort %d elements: %.6f seconds\n", n, time_taken);
		fprintf(fp, "%d,%.6f\n", n, time_taken); // Write data to the file
	}

	fclose(fp);
	return 0;
}

