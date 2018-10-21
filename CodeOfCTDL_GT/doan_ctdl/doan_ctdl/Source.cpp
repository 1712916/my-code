#include"Header.h"
vector<int>	createSorted(int n)
{

	vector<int> data;
	for (int i = 0; i < n; i++)
	{
		data.push_back(i);
	}
	return data;
}
vector<int>	createReversed(int n)
{

	vector<int> data;

	data.push_back(rand());

	int temp = data[0];

	for (int i = n - 1; i>0; i--)
	{
		data.push_back(i);
	}
	return data;
}
vector<int>	createdRandom(int n)
{

	vector<int> data;
	for (int i = 0; i < n; i++)
	{
		data.push_back(rand());
	}
	return data;
}
int swap(int &a, int &b)
{
	int swap = a;
	a = b;
	b = swap;
	return 0;
}
/*******************************/
int bubbleSort(vector<int > &array, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(array[j], array[j + 1]);
			}
		}
	}
	return 1;
}
int selectionSort(vector<int > &array, int n)
{
	int key;
	for (int i = 0; i < n; i++)
	{
		key = i;
		for (int j = i+1; j < n; j++)
		{
			if (array[key] > array[j])
			{
				key = j;
			}
		}
		swap(array[key], array[i]);
	}
	return 0;
}
int insertionSort(vector<int > &array, int n)
{
	
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = array[i];
		j = i - 1;

		while (j >= 0 && array[j] > key)
		{
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = key;
	}
	return 0;
}
/************heapSort***********************/
void heapify(vector<int> &array, int n, int i)
{
	int largest = i; // Initialize largest as root 
	int l = 2 * i + 1; // left = 2*i + 1 
	int r = 2 * i + 2; // right = 2*i + 2 

	// If left child is larger than root 
	if (l < n && array[l] > array[largest])
		largest = l;

	// If right child is larger than largest so far 
	if (r < n && array[r] > array[largest])
		largest = r;

	// If largest is not root 
	if (largest != i)
	{
		swap(array[i], array[largest]);

		// Recursively heapify the affected sub-tree 
		heapify(array, n, largest);
	}
}

// main function to do heap sort 

int heapSort(vector<int > &array, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(array, n, i);

	// One by one extract an element from heap 
	for (int i = n - 1; i >= 0; i--)
	{
		// Move current root to end 
		swap(array[0], array[i]);

		// call max heapify on the reduced heap 
		heapify(array, i, 0);
	}
	return 0;
}
int quick(vector<int > &array,int l, int r)//r=n-1
{
	if (l >= r)
	{
		return 0;
	}
	int pivot = r;
	int left = l - 1;
	for (int i = l; i < r; i++)
	{
		if (array[i] < array[pivot])
		{
			left = left + 1;
			swap(array[left], array[i]);
		}
	}
	left ++;
	swap(array[left], array[pivot]);
	quick(array, l, left-1);
	quick(array, left+1, r);
	return 0;
}
int quickSort(vector<int > &array, int n)
{
	quick(array, 0, n - 1);
	return 1;
}
void merge(vector<int> &array, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	vector<int> L, R;
	L.resize(n1); R.resize(n2);

			/* Copy data to temp arrays L[] and R[] */
		for (i = 0; i < n1; i++)
			L[i] = array[l + i];
		for (j = 0; j < n2; j++)
			R[j] = array[m + 1 + j];

		/* Merge the temp arrays back into arr[l..r]*/
		i = 0; // Initial index of first subarray 
		j = 0; // Initial index of second subarray 
		k = l; // Initial index of merged subarray 
		while (i < n1 && j < n2)
		{
			if (L[i] <= R[j])
			{
				array[k] = L[i];
				i++;
			}
			else
			{
				array[k] = R[j];
				j++;
			}
			k++;
		}

		/* Copy the remaining elements of L[], if there
		are any */
		while (i < n1)
		{
			array[k] = L[i];
			i++;
			k++;
		}

		/* Copy the remaining elements of R[], if there
		are any */
		while (j < n2)
		{
			array[k] = R[j];
			j++;
			k++;
		}
	}

	/* l is for left index and r is right index of the
	sub-array of arr to be sorted */

	int mergesort(vector<int> &array, int l, int r)
	{
		if (l < r)
		{
			// Same as (l+r)/2, but avoids overflow for 
			// large l and h 
			int m = l + (r - l) / 2;

			// Sort first and second halves 
			mergesort(array, l, m);
			mergesort(array, m + 1, r);

			merge(array, l, m, r);
		}
		return 0;
	}
	int mergeSort(vector<int> &array, int n)
	{
		mergesort(array, 0, n-1);
		return 0;
	}
//************radix_sort****************//
int getMax(vector<int> array, int n)
{
	int max = array[0];
	for (int i = 1; i < n; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return max;
}
void countSort(vector<int> &array, int n, int exp)
{
	vector<int> output; 
	output.resize(n);
	int i, count[10] = { 0 };

	
	for (i = 0; i < n; i++)
		count[(array[i] / exp) % 10]++;

	
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}


	for (i = 0; i < n; i++)
		array[i] = output[i];
}
int radixSort(vector<int> &array, int n)
{
	
	int m = getMax(array, n);

	for (int exp = 1; m / exp > 0; exp *= 10)
	{
		countSort(array, n, exp);
	}
		
	return 0;
}
/************************/

double timeOfRun(int (*nameOfSort)(vector<int>& ,int),vector<int> array, int n)
{
	clock_t start, end;
	start = clock();
	nameOfSort(array, n);
	end = clock();// ham đếm thời gian kết thúc
	double duration = (double)(end- start) / CLOCKS_PER_SEC;
	return duration;
}

/************************/

int saveResults(string nameOfCase,vector<int> (*creat)(int), int donvi)
{

	string nameOfFile = "Results.csv";
	fstream file;
	file.open(nameOfFile, ios::app);
	float size;
	float size_a = 10;
	file << setw(8) << left << "case" << setw(10) << left << "size" << setw(10) << left << "bubble" << setw(15) << left << " selection" << setw(15) << left << "insertion" << setw(10) << left << "heap" << setw(10) << left << "quick" << setw(10) << left << "merge" << setw(10) << left << "radix" << endl;
	for (int i = 1; i <= 6; i++)
	{
		vector<int> array;
		if (i != 3 && i != 5)
		{
			size = size_a * pow(10.0, i);
		}
		else
		{
			size = size_a * pow(10.0, i) / 2;
		}
		if (i > 3)
		{
			if (i == 6)
			{
				size = size / 10;
			}
			size = size / 10;
		}
		array = creat(size);
		file << setw(8) << left << nameOfCase << setw(10) << left << size << setw(10) << left << timeOfRun(&bubbleSort, array, size)*donvi << setw(15) << left << timeOfRun(&selectionSort, array, size)*donvi << setw(15) << left << timeOfRun(&insertionSort, array, size)*donvi << setw(10) << left << timeOfRun(&heapSort, array, size)*donvi << setw(10) << left << timeOfRun(&quickSort, array, size)*donvi << setw(10) << left << timeOfRun(&mergeSort, array, size)*donvi << setw(10) << left << timeOfRun(&radixSort, array, size)*donvi << endl;

	}

	file.close();
	return 1;
}