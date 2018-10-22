#include"Header.h"

int main()
{
	/**********************************/
	/*srand(time(NULL));
	int DonVi = 1; 
	saveResults("Sorted", createSorted, DonVi);
	saveResults("Reversed", createReversed, DonVi);
	saveResults("Random", createdRandom, DonVi);*/
	/*********************************/
	int n = 10000;
	int(*name)(vector<int> &, int);
	name = &radixSort;
	vector <int> a;
	a = createdRandom(n);

	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "\t";
	}	cout << endl;
	name(a, n);
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "\t";
	}	cout << endl;

	/*double a = 0.5555555555555;
	cout << setprecision(20)<<a;*/
	system("pause");
	return 0;
}