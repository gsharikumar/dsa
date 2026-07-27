// sort.cpp
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) < (Y)) ? (Y) : (X))

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
	return;
}

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
	return;
}

void printArr(int *arr,int n) {
	cout << "[";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ",";
	}
	cout << "]"<<endl;
}

void bubbleSort() {
	int arr[] = { 900,600,10000,500,200,100,3000,4,1,1000000000 };
	int n = sizeof(arr) / sizeof(arr[0]);
	//repeat for lengthofarray-1 
	for (int i = 0; i < n - 1;i++) {
		
		for (int j = 0; j < n - i - 1; j++) {
			cout << "(" << j << "," << j + 1 << ")"<<endl;
			if (arr[j] > arr[j+1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
	cout << "sort-bubble";
	cout << "[";
	for (int i = 0; i < n; i++) {
		cout << arr[i]<<" ";
	}
	cout << "]";
	return;
}

void selectionSort() {
	int arr[] = { 900,600,10000,500,200,100,3000,4,1,1000000000 };
	int n = sizeof(arr) / sizeof(arr[0]);
	//repeat for lengthofarray-1 
	int minIdx;
	for (int i = 0; i < n ; i++) {
		minIdx = i;
		for (int j = i+1; j < n ; j++) {
			cout << "(" << minIdx << "," << j << ")" << endl;
			if (arr[minIdx] > arr[j ]) {
				minIdx = j;
			}
		}
		swap(arr[minIdx], arr[i]);
	}
	cout << "sort-selection";
	cout << "[";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << "]";
	return;
}

void insertionSort() {
	/*
	worst case O(n^2) (array in descending order)
	best case - O(n)  (array already sorted in ascending order)
	in general O(n^2)
	*/
	int arr[] = { 900,600,10000,500,200,100,3000,4,1,1000000000 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int key;
	int j;
	for (int i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;
		while (j >= 0 &&  arr[j] > key) {
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
	cout << "sort-insert";
	cout << "[";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << "]";
	return;
}

void mergeSorted(int *arr, int low, int mid,int high) {
	/*
	only works on sorted arrays
	*/
	int i, j;
	int l = low;
	int r = mid;
	int *mergedArr = new int[high-low];
	i = 0;
	cout << "merge sorted sections "<<"left(" << low << "," << mid << ") right(" << mid <<", " <<high <<")" << endl;
	cout << "before sorting" << endl;
	for (j = low; j < high; j++) {
		cout << arr[j] << ",";
	}
	cout << endl;
	while (l<mid && r<high) {
		if (arr[l] > arr[r]) {
			mergedArr[i] = arr[r];
			r++;
		}
		else {
			mergedArr[i] = arr[l];
			l++;
		}
		i++;
	}
	for (; l < mid; l++,i++) {
		mergedArr[i] = arr[l];
	}
	for (; r < high; r++, i++) {
		mergedArr[i] = arr[r];
	}

	cout << "sorting" << endl;
	for (i =0,j=low; j < high; i++,j++) {
		arr[j] = mergedArr[i];
		cout << arr[j] << "," ;
	}
	cout << endl;
	delete mergedArr;
	return;
}

void mergeSortRecurr(int *arr,int low, int high) {
	//atleaset two elements needed
	
	//this works too
	if (low > high - 2) { 
		return; 
	}
	//for GG condition
	//if (low < high) 
	{
		int mid = (low + high) / 2;
		//mid = low + (high - low) / 2; //GG recommends below, not sure why not above one would fail?? 

		cout << "low=" << low << " mid=" << mid << " high=" << high << endl;
		mergeSortRecurr(arr, low, mid);
		mergeSortRecurr(arr, mid, high);
		mergeSorted(arr, low, mid, high);
	}
	return;

}

void mergeG4G(int arr[], int l, int m, int h) {

	int n1 = m - l + 1, n2 = h - m;
	int *left = new int[n1];
	int *right=new int[n2];
	for (int i = 0; i < n1; i++)
		left[i] = arr[i + l];
	for (int j = 0; j < n2; j++)
		right[j] = arr[m + 1 + j];
	int i = 0, j = 0, k = l;
	while (i < n1 && j < n2) {
		if (left[i] <= right[j])
			arr[k++] = left[i++];
		else
			arr[k++] = right[j++];
	}
	while (i < n1)
		arr[k++] = left[i++];
	while (j < n2)
		arr[k++] = right[j++];
}


void mergeSortG4G(int arr[], int l, int r) {
	//crashing for some reason
	if (r > l) {
		int m = l + (r - l) / 2;
		mergeSortG4G(arr, l, m);
		mergeSortG4G(arr, m + 1, r);
		mergeG4G(arr, l, m, r);
	}
}


void mergeSort() {
	/*
	divide and rule
	ln==> logbase2
	complexity ln(n)* O(n)  ==actual ceil(ln(n)+1)* O(n) 
	space requirement O(n)
	*/
	int arr[] = { 900,600,10000,500,200,100,3000,4,1,1000000000 };
	int n = sizeof(arr) / sizeof(arr[0]);
	mergeSortRecurr(arr,0,n);
	//mergeSortG4G(arr, 0, n); g4g implementation crashing--need to understand

	for (int i=0;i<n;i++)
		cout << arr[i] << " ";
	return;
}

void intersectionTwoSortedArray(int *arr1,int n1,int*arr2,int n2) {
	/*
		efficient solution O(n+m)
		works only for sorted array
		can ask the interviewer if the array needs to be sorted
	*/
	int i1 = 0;
	int i2 = 0;
	int n = (n1> n2)?n1:n2;
	int i = 0;
	int *arr = new int[n];
	while (i1 < n1 && i2 < n2) {
		if (arr1[i1] < arr2[i2]) {
			i1++;
		}
		else if (arr1[i1] > arr2[i2]) {
			i2++;
		}
		else {
			arr[i] = arr1[i1];
			i++;
			//!!handle repeat terms 
			while (i1<n1 && arr1[i1] == arr1[i1 + 1]) {
				i1++;
			}
			while (i2 < n2 && arr2[i2] == arr2[i2 + 1]) {
				i2++;
			}
			i1++;
			i2++;
		}
	}
	for (int j = 0; j < i; j++) {
		cout << arr[j] << ",";
	}
	cout << endl;
	delete arr;
	return;
}

void intersectionTwoSortedArrayG4G(int *arr1, int n1, int*arr2, int n2) {
	/*
		geeks for geeks approach - only print scenario
		efficient solution O(n+m)
		works only for sorted array
	*/
	int i1 = 0;
	int i2 = 0;
	while (i1 < n1 && i2 < n2) {
		//!!handle repeat terms 
		if (i1 > 0 && arr1[i1] == arr1[i1 - 1]) {
			i1++;
			continue;
		}
		if (arr1[i1] < arr2[i2]) {
			i1++;
		}
		else if (arr1[i1] > arr2[i2]) {
			i2++;
		}
		else {
			//just printing, no need to store scenario
			cout << arr1[i1] << ",";
			i1++;
			i2++;
		}
	}
	return;
}

void findIntersectionTwoSortedArray() 
{
	/*
	naive solution O(n*m) - could handle sorted or unsorted

	efficient solution O(n+m) - which is implemented requires sorted
	*/
	int arr1[] = { 1,2,3,4,5,5,5,6,7};
	int n1 = sizeof(arr1) / sizeof(arr1[0]);
	int arr2[] = { 2,3,4,4,4,5,6,7,8 };
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	intersectionTwoSortedArray(arr1,n1,arr2,n2);
	intersectionTwoSortedArrayG4G(arr1, n1, arr2, n2);
	return;
}

void unionOfSortedArrayOptimum(int *arr1, int n1, int*arr2, int n2) {
	/*
		geeks for geeks approach - only print scenario
		efficient solution O(n+m)
		works only for sorted array
	*/
	int i1 = 0;
	int i2 = 0;
	while (i1 < n1 && i2 < n2) {
		//!!handle repeat terms 
		if (i1 > 0 && arr1[i1] == arr1[i1 - 1]) {
			i1++;
			continue;
		}
		if(i2 >0 && arr2[i2] == arr2[i2 - 1]) {
			i2++;
			continue;
		}

		if (arr1[i1] < arr2[i2]) {
			cout << arr1[i1] << " ";
			i1++;
		}
		else if (arr1[i1] > arr2[i2]) {
			cout << arr2[i2] << " ";
			i2++;
		}
		else {
			cout << arr2[i2] << " ";
			i1++;
			i2++;
		}
	}
	//!!! important to handle scenarios of bigger size array ending with the largest
	while (i1 < n1) {
		cout << arr1[i1++] << " ";
	}
	while (i2 < n2) {
		cout << arr2[i2++] << " ";
	}

}

void unionOfSortedArray() {
	/*
	naive solution O[(n+m) *log(m+n)] - could handle sorted or unsorted
	1. Combine two arrays to single array auxiliary space O(n+m)
	2. Sort - O((m+n)*log(n+m))
	3. print skipping duplicates O(n+m)
	efficient solution O(n+m) & aux space O(1) - which is implemented requires sorted
	*/
	int arr1[] = { 1,2,3,4,5,5,5,6,7 };
	int n1 = sizeof(arr1) / sizeof(arr1[0]);
	int arr2[] = { 2,3,4,4,4,5,6,7,8 };
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	unionOfSortedArrayOptimum(arr1, n1, arr2, n2);

	return;
}


int countInvMerge(int *arr, int low, int mid, int high) {
	int lLen = mid - low + 1;
	int rLen = high - mid + 1;
	int tLen = lLen + rLen;
	int *sarr=new int[tLen]; //!!not high + low
	int res = 0;
	int  l=low;
	int  r = mid;
	int k = 0;
	while (l < mid && r < high) { //!start from beginning of both left and right array
		if (arr[l] <= arr[r]) {
			sarr[k++] = arr[l++];
		}
		else {
			//inversion found
			//!!!!!super tricky - using sorted array helps to detect the inversions in one go, rather than having to parse the entire arrasy
			res=res+(lLen-l); 
			sarr[k++] = arr[r++];
		}
	}
	while (l < mid) {
		sarr[k++] = arr[l++];
	}
	while (r < high) {
		sarr[k++] = arr[r++];
	}

	for (int i = 0,j=low; j < high; i++,j++) { //!!mindfull of the indexs of the different arrays
		arr[j] = sarr[i];
		cout << arr[j] << ",";
	}
	cout << endl;
	delete sarr;
	return res;
}

int countInv(int *arr,int low,int high) {
	if (low >= high-1) {
		return 0;
	}
	int res = 0;
	int mid = (low + high) / 2;
	res += countInv(arr, low, mid);
	res += countInv(arr, mid, high);
	res += countInvMerge(arr, low, mid, high);
	return res;
}



void countInversions() {

	/*
	naive solution O(n^2)
	optimum solution O(log(n)) & aux space O(n)- using merge sort
	*/

	int arr[] = { 2,1,4,5,5,5,3,6,7 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "total count of inversions in the array are " << countInv(arr, 0, n) << endl;


	return;
}

int lometoParition(int *arr, int low, int high,int pivot=-1) {
	/*
	- 
	*/
	int i;
	int l = low;
	int pivotVal;
	//move pivot to the end & sample the pivot value
	if (pivot == -1) {
		pivot = high - 1;
	}
	pivotVal = arr[pivot];
	swap(&arr[pivot], &arr[high - 1]);
	l=low-1;
	for (i = low; i < high-1; i++) {
		if (arr[i] <= pivotVal) {
			l++;
			swap(&arr[i],&arr[l]); //corner case 2 swap with same index
		}
	}
	swap(&arr[l+1], &arr[high-1]); //-- corner case 1 is handled here
	return l+1; //return pivot location
}

int hoareParition(int *arr, int low, int high,int pivot=-1) {
	/*
	!! elements the left are all smaller than or equal to the elements to the right
	*/
	int l=low-1;
	int r=high +1-1; //???
	int pivotVal;
	if (pivot != -1) {
		swap(&arr[low], &arr[pivot]);
	}
	pivotVal = arr[low];
	while(1){
		do{
			l++;
		}while(arr[l]<pivotVal);

		do{
			r--;
		}while(arr[r]>pivotVal);

		if(l>=r){ //why = condition??
			return r; //why return r??
		}
		swap(&arr[l],&arr[r]);
	}

	return l;
}


void partition() {
	/*
	given pivot point 
	- move all values less than the pivot to left
	- move all values more than the pivot to right
naive partition - 3 traversal each of O(n) complexity Aux space O(n)

Lometo partition - O(n) & Aux space O(1)
	- complexity O(n) & aux space O(1)
	- pivot is always last element in the simplified case of lometo
	- corner cases
		1. {70,60,80,40,30}
		2. {40,40,20,50,80}
		- Always the pivot needs to be moved to the end of the array, as first step

hoare partition - O(n) & Aux space O(1) 
	- pivot is always the first element
	- gaurentees return of the index of the last element of the lower half (less than pivot). 
	- pivot will lie in the upper half & returned index is not the pivotvalue
	- uses less no.of comparisons compared to lometo partition
	- pivot may not be in  correct position, it will be in the right side
	- corner case
		- {5,10,9,12} - pivot is smallest --> l& r become equal & swap has not effect
		- {12,10,5,9} - pivot is largest
		- {5,5,5,5,5} - all elements are the same --> swap happens and hence order of the element changed, reason hoare algo is not stable and hence quick sort is not stable
	*/
	int arr[] = { 2,1,4,5,3,6,10,11,2,1,4,7 };
	//int arr[] = { 10,80,30,90,40,50,70};
	int n = sizeof(arr) / sizeof(arr[0]);
	int p = 4;
	int l = 0;
	int h = n;
	hoareParition(arr, l, h,p);
	//lometoParition(arr, l, h,p);

	for (int i = 0; i < n; i++) {
	 cout<<arr[i]<<", ";
	}
	cout<<endl;

	
	return;
}

void qSortLometo(int *arr,int low,int high){
	//!! needs atleast two elements to sort 
	if(low<high){ //!! terminate condition high -2 works, high-2 also works hmmm
/* 
- !! important to use the pivot position from the lometoPartition call and reuse for the next recursive call
- !! after every call pivot value is put in the right sorted position, but other values around pivot point will remain outplace or shuffled
- !! after every call to lometoPartition skip the pivot- 
*/
		int p=(high+low)/2; //nned not pass, as the for lometo last element is the pivot by default
		p=lometoParition(arr,low,high,p);
		qSortLometo(arr,low,p);
		qSortLometo(arr,p+1,high);
	}
	return;
}

void qSortHoare(int *arr,int low,int high){
	//!! needs atleast two elements to sort 
	if(low<high-1){ //!!corner case sucks  -work this out
		int p;
//		int p=(high+low)/2; //nned not pass, as the for Hoare first element is the pivot by default
		p=hoareParition(arr,low,high);
		qSortHoare(arr,low,p+1);
		qSortHoare(arr,p+1,high);
	}

	return;
}

void qSort(){
	/*
	- Worst case O(n^2)
	- Average case O(nlogn)
	- inplace algo, cache efficient
	- tail recursive
	*/

	//int arr[] = { -1, 0,2,1,4,5,5,5,5,5,3,6,10,11,11,2,1,4,7,20,21,5 };
	int arr[] = { 10,80,30,90,40,50,70};
	int n = sizeof(arr) / sizeof(arr[0]);
	int p=n/2;
	//qSortLometo(arr,0,n);
	qSortHoare(arr,0,n);
	for (int i = 0; i < n; i++) {
	 cout<<arr[i]<<", ";
	}

	return;	
}

void findKthSmallestElement() {
	int arr[] = { 10,80,30,90,40,50,70 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 2; //k starts from index 1 - ask the interviewer for clarification if required
	int l = 0;
	int h = n;
	int resIdx = -1;
	int res;
	int p = h-1; //point to the last element
	while (l <= h){
		p = lometoParition(arr, l, h);
		if (p < (k-1)) {
			l = p + 1; //!!careful: write this down 
		}
		else if(p > (k-1)) {
			//p>k-1
			h = p; //!!careful: write this down, not p-1
			
		}else {
			res = arr[p];
			resIdx = p;
			break;
		}
		
	}
	if (resIdx == -1) {
		cout << "findKthSmallestElement index out of range??" << endl;
	}
	else {
		cout << "findKthSmallestElement is " << res << endl;
	}
	return;
}

void chocDistProb() {
	/*
	O(nlogn)
	*/
	int arr[] = { 7,3,2,4,9,12,56 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int m = 3;
	int *rarr = new int[m]; //!!not high + low
	int resMin;
	int resMinIdx=-1;
	qSortHoare(arr,0,n);
	
	resMin = arr[m - 1] - arr[0];
	resMinIdx = 0;
	for (int i = 1; i <= n-m; i = i + m) {
		if (resMin > arr[m + i - 1] - arr[i]) {
			resMin = arr[m + i - 1] - arr[i];
			resMinIdx = i;
		}
	}
	cout << "chocDistProb is " << resMin <<" at index"<< resMinIdx << endl;
	return;
}

void segregatePositiveNegativeLometo() {
	/*
	1. naive approach 3*O(n)~O(n) & requires O(n auxiliary space)
	2. optimal solution O(nlog(n))

	*/
	int arr[] = { -7,3,2,4,9,12,-56 };
	int n = sizeof(arr) / sizeof(arr[0]);
	//modified lometo partition, pivot value is set to zero & swap of pivot value is skipped
	int pivotVal = 0;
	int i = 0; 
	int l = i-1;//i-1 or -1 no difference here, not looking for resuable component
	int h = n;

	while (i<h) {
		if (arr[i] <= pivotVal) {
			l++;
			swap(&arr[i], &arr[l]);
		}
		i++;
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ", ";
	}
	return;
}

void segregatePositiveNegativeHoare() {
	/*
	1. naive approach 3*O(n)~O(n) & requires O(n) auxiliary space
	2. optimal solution 1*O(n)) & requires O(1) auxiliary space- Hoare method
	*/
	int arr[] = { -7,3,2,4,9,12,-56 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int l = -1;
	int h = n;
	while (1) {
		do {
			l++;
		} while (arr[l] <= 0 && l<h);  //l<h condition not present
		do {
			h--;
		} while (arr[h] > 0 && h>=0); //l<h condition not present
		if (l >= h) break;
		swap(&arr[l], &arr[h]);
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ", ";
	}
	return;
}

void segregateEvenOdd() {
	/*
	1. naive approach 3*O(n)~O(n) & requires O(n) auxiliary space
	2. optimal solution 1*O(n)) & requires O(1) auxiliary space- Hoare method
	*/
	int arr[] = { -7,3,2,4,9,12,-56 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int l = -1;
	int h = n;
	while (1) {
		do {
			l++;
		} while ((arr[l] % 2)==0 && l < h);  //l<h condition not present
		do {
			h--;
		} while ((arr[h]%2)!=0 && h >= 0); //l<h condition not present
		if (l >= h) break;
		swap(&arr[l], &arr[h]);
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ", ";
	}
	return;
}

void sortBinaryArray() {
	/*
		1. naive approach 3*O(n)~O(n) & requires O(n) auxiliary space
		2. optimal solution 1*O(n)) & requires O(1) auxiliary space- Hoare method
		*/
	int arr[] = { 1,1,0,1,0,1,0 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int l = -1;
	int h = n;
	while (1) {
		do {
			l++;
		} while (arr[l] == 0 && l < h);  //l<h condition not present
		do {
			h--;
		} while ((arr[h] % 2) == 1 && h >= 0); //l<h condition not present
		if (l >= h) break;
		swap(&arr[l], &arr[h]);
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ", ";
	}
	return;
}

void segregate3TypesOfElementsSuboptimum() {
	/*
	2*O(n)
	*/
	int arr[] = { 1,1,0,1,0,1,0,2,1,0,1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int l = -1; //end index of window of 0's
	int h=n; //start index of window of 2's
	int m = n; //start index of windows of 1's
	int i = 0;
	while (1) {
		do {
			l++;
		} while (arr[l] == 0);
		do {
			m--;
		} while (arr[m] > 0);
		if (l >= m) break;
		swap(&arr[m], &arr[l]);
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ", ";
	}
	cout << endl;
	m=--l;
	while (1) {
		do {
			m++;
		} while (arr[m] == 1);
		do {
			h--;
		} while (arr[h] > 1);
		if (m >= h) break;
		swap(&arr[m], &arr[h]);
	}
	cout << "segregate3TypesOfElementsSuboptimum " << endl;
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ", ";
	}
	cout << endl;
	return;
}

void dutchNationalFlagAlgo() {
	/*
	very tricky
	- optimum solution O(n)
	- partition based
	- l points to the start of the 1
	- m points to the start of 2
	- h & m finally converge 
	- 0 to <l represent window 0
	- l to m  represent window 1
	- m to n  represent window 2
	*/
	int arr[] = { 1,1,0,1,0,1,0,2,1,0,1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int l = 0; 
	int m = 0; 
	int h = n-1; 
	int i = 0;
	while (m<=h) {
		if (arr[m] == 0) {
			swap(&arr[m], &arr[l]);
			m++;
			l++;
		}
		else if (arr[m] == 1) {
			m++;
		}
		else {
			//2 case
			swap(&arr[m], &arr[h]);
			h--;
		}
	}
	cout<< "dutchNationalFlagAlgo "<<endl;
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ", ";
	}
	cout << endl;
}

void minDifferenceInArrayNaive() {
	/*
	O(n)
	*/
	int arr[] = { 1,8,12,5,18 }; //o/p 3
	//int arr[] = { 8,15}; //o/p 7
	//int arr[] = {8,-1,0,3 }; //o/p 7
	//int arr[] = { 10 }; //INF
	int n = sizeof(arr) / sizeof(arr[0]);
	int resMinDiff = INT_MAX;
	//navie solution
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			resMinDiff = MIN(resMinDiff, abs(arr[i] - arr[j]));
		}
	}
	cout << "minimumDifferenceInArray navie " << resMinDiff << endl;
	return;
}

void minDifferenceInArrayOptimum() {
	/*
		O(nlogn) + O(n)
	*/
	//int arr[] = { 1,8,12,5,18 }; //o/p 3
	//int arr[] = { 8,15}; //o/p 7
	int arr[] = {8,-1,0,3 }; //o/p 1
	//int arr[] = { 10 }; //INF
	int n = sizeof(arr) / sizeof(arr[0]);

	qSortHoare(arr, 0, n);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ", ";
	}
	int resMinDiff = INT_MAX;
	for (int i = 1; i < n; i++) {
		resMinDiff = MIN(resMinDiff, arr[i] - arr[i-1]);
	}
	cout << "minDifferenceInArray Optimum " << resMinDiff << endl;
	return;
}
void minimumDifferenceInArray() {
	
	minDifferenceInArrayOptimum();
	//minDifferenceInArrayNaive();
	return;
}

void segregate3TypesOfElements() {
	
	dutchNationalFlagAlgo();
//sub optimal
	//segregate3TypesOfElementsSuboptimum();
	return;
}

struct Interval
{
	int s, e;
};


bool mycomp(Interval a, Interval b)
{
	return a.s < b.s;

}
void mergeOverlappingIntervals() {
	Interval arr[] = { {5,10}, {3,15}, {18,30}, {2,7} }; 	
	int n = sizeof(arr) / sizeof(arr[0]);
	//sort(arr, arr+n, mycomp);
	for (int i = 0; i < n; i++) {
		cout << "{"<<arr[i].s<<","<<arr[i].e << "}, "<<endl;
	}
	int res = 0;
	for (int i = 1; i < n;i++) {
		if (arr[res].e <= arr[i].s) {
			arr[res].s = MIN(arr[res].s, arr[i].s);
			arr[res].e = MAX(arr[res].e, arr[i].e);
		}
		else {
			res++;
		}
	}
	cout << "merged" << endl;
	for (int i = 0; i < res; i++) {
		cout << "{" << arr[i].s << "," << arr[i].e << "}, " << endl;
	}
	/*output {{1,4},{5,8}}*/
	return;
}

void cycleSortNoDuplicates() {

	int arr[] = { -7,3,2,4,9,12,-56 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int cs,pos,item;
	for (cs = 0; cs < n; cs++) {
		item = arr[cs];
		do {
			pos = 0;
			for (int j = 0; j < n; j++) {
				if (arr[j] < item) {
					pos++;
				}
			}
			swap(&arr[pos], &item);
			//break when cycle detected
		} while (pos!=cs);
	}
	return;
}

void cycleSortDuplicates() {

	int arr[] = { -7,-7,2,4,9,12,-56 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int cs, pos, item,dup;
	int i;
	//cycle up until n-1??
	//cs==>cycle start
	for (cs = 0; cs < n-1; cs++) {
		item = arr[cs];
		do {
			pos = 0;
			dup = 0;
			for (i = 0; i < n; i++) {
				if (arr[i] < item) {
					pos++;
				}
				else if (arr[i] == item) {
					dup++;
					arr[i] = INT_MAX;
				}
			}
			swap(&arr[pos], &item);
			//break when cycle detected
		} while (pos != cs);
		for (i=1; i <= dup && cs+i < n-1 ; i++) {
			swap(&arr[cs+i], &arr[cs + i+1]);
		}
		cs = cs + i;
	}
	return;
}


void cycleSort() {
	/*
	usable where minimum writes is expected, for example in the case of eeprom etc
	O(n^2)
	*/
	//cycleSortNoDuplicates();
	//cycleSortDuplicates();

	return;
}

void heapSort() {
	int arr[] = { 10,20,15,30,30,40 };
	int n = sizeof(arr) / sizeof(arr[0]);
	/*
		heap data structure insertion/deletion is O(logn) 
		heap best data structure for implementing priority queue - delete always the top parent node - FIFO
	*/
	/*
	heap creation two methods
	1. Normal:  O(nlogn) scan from left to right of array or bottom to top approach	
	2. heapify: O(n) approach create a heap scanning from right to left array  or top to bottom --> similar procedure as deletion ??
	*/
	int ci, pi, i,j;
	for (i = 1; i < n; i++) {
		ci = i;
		while (ci >= 0) {
			pi = floor((ci+1) / 2)-1;
			if (arr[pi] < arr[ci]) {
				swap(&arr[pi],&arr[ci]);
				ci = pi;
				break;
			}
		}
	}
	/*	
	deletion procedure del top node and stuck it at the end-- > nlogn
		total complexity-- > 2nlogn-- > O(nlogn)
	*/
	int li;
	int ri;
	int largesti;
	for (i = 0; i < n; i++) {
		swap(&arr[0], &arr[n-i-1]);
		pi = 0;
		while (1) {
			li = (pi+1) * 2 - 1;
			ri = (pi+1) * 2 + 1 - 1;
			if (!(ri<n-i-1)) {
				break;
			}
			largesti = pi;
			if (arr[pi] < arr[li]) {
				largesti = li;
			}
			if (arr[largesti] < arr[ri]) {
				largesti = ri;
			}
			swap(&arr[pi], &arr[largesti]);
			pi = largesti;
			
		}
		cout << "i="<<i<<endl;
		for (j = 0; j < n; j++) {
			cout << arr[j] << ", ";
		}
	}
	return;
}

void heapifyIterative(int *arr,int n) {
//TODO:

	return;
}

void heapifyRecursive(int *arr, int n,int pi) {

	int li, ri,bi;
	printArr(arr, n);

	li = 2 * (pi+1) - 1;
	ri = (2 * (pi+1) + 1)-1;	
	bi = pi;

	if (li <n && arr[li] > arr[bi]) bi=li;
	if (ri <n && arr[ri] > arr[bi]) bi=ri;

	if (pi != bi) {
		swap(&arr[bi], &arr[pi]);
		heapifyRecursive(arr, n, bi);
	}
	


	
	return;
}

void heapifyRecursiveSolution(int *arr,int n) {
	// wrong --> for (int pi =floor((n - 1)/2)-1; pi >= 0; pi--)
	for (int pi =floor(n/2)-1; pi >= 0; pi--)
	{
		heapifyRecursive(arr, n, pi);
	}
	return;
}

void heapify() {
	/*
	2. heapify: linear time implementation O(n) approach create a heap scanning from right to left array or top to bottom-- > similar procedure as deletion??
	
	there are more space in the bottom than top, so starting from bottom, will allow less traversal to happen and a complex derivation yields O(n)
	*/
	//int arr[] = { 10,20,15,12,40,25,18 };
	int arr[] = { 10,50,15,4,20};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "heapify " << endl;
	printArr(arr, n);
	heapifyRecursiveSolution(arr, n);
	printArr(arr, n);
	//TODO: heapifyIterative(arr,n); 
	return;
}


int sort()
{
	heapify(); return 0;
	heapSort(); return 0;
	
#if 0
	cycleSort(); //pending on handling duplicates 
	mergeOverlappingIntervals();
	minimumDifferenceInArray();
	segregate3TypesOfElements();
	sortBinaryArray();
	segregateEvenOdd();
	segregatePositiveNegativeHoare();
	segregatePositiveNegativeLometo();
	chocDistProb();
	findKthSmallestElement();
	qSort();
	partition();
	countInversions(); return 0;
	unionOfSortedArray(); return 0;
	findIntersectionTwoSortedArray(); 	return 0;
	mergeSort(); return 0;
	//mergeSort(); return 0;
	insertionSort(); 
	selectionSort(); 
	bubbleSort();
#endif
	return 0;
}

