#ifndef __HEADER_H__
#define __HEADER_H__
#include<iostream>
#include<vector>
using namespace std;
#include<string>
#include <cstdlib>
#include<fstream>
#include <ctime>
#include<iomanip>
vector<int>	createSorted(int n);
vector<int>	createReversed(int n);
vector<int>	createdRandom(int n);
int swap(int &a, int &b);
int bubbleSort(vector<int > &array, int n);

int selectionSort(vector<int > &array, int n);

int insertionSort(vector<int > &array, int n);

void heapify(vector<int> &array, int n, int i);
int heapSort(vector<int > &array, int n);

int quickSort(vector<int > &array, int n);
int quick(vector<int > &array, int l, int n);

void merge(vector<int> &array, int l, int m, int r);
int mergesort(vector<int> &array, int l, int r);
int mergeSort(vector<int > &array, int n);

int getMax(vector<int> array, int n);
void countSort(vector<int> &array, int n, int exp);
int radixSort(vector<int > &array, int n);

double timeOfRun(int(*nameOfSort)(vector<int>&, int), vector<int> array, int n);

int saveResults(string nameOfCase, vector<int>(*creat)(int), int donvi);
#endif