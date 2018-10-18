#include"Header.h"

int main()
{
	srand(time(NULL));

	vector <int> a;
	a = createdRandom(10);
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << "\t";
	}	cout << endl;
	int n = a.size();
	mergeSort(a, n);
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << "\t";
	}	cout << endl;

	
	system("pause");
	return 0;
}