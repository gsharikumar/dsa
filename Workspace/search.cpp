// search.cpp 
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) < (Y)) ? (Y) : (X))


int binarySearchRecursive(int arr[], int start,int end,int val) {
	//for (int i = 0; i < log(arrLen)+1; i++)  or better to use while
	if (start > end) {
		return -1;
	}
	int midPt = (end + start) / 2;
	if (arr[midPt] < val) {
		start = midPt+1;
	}
	else if (arr[midPt] > val) {
		end = midPt-1;
	}
	else {
		return midPt;
	}
	return binarySearchRecursive(arr,start,end,val);
}

int binarySearchLoop(int arr[], int arrLen,int val) {
	
	int start = 0;
	int end=arrLen-1;
	int midPt;
	int index = -1;
	//for (int i = 0; i < log(arrLen)+1; i++)  or better to use while
	while(start<=end)
	{
		midPt = (end + start) / 2;
		if (arr[midPt] < val) {
			//move right
			start = midPt+1;
		}
		else if (arr[midPt] > val) {
			//move left
			end = midPt-1;
		}
		else {
			index = midPt;
			break;
		}
	}
	return index ;
}

void binarySearch() {
	int val = 40;
	int arr[] = { 10,20,30,40,50,60,70 };
	int arrLen = sizeof(arr) / sizeof(arr[0]);
	cout << "Binary search arr for value "<<val<< " status= " << binarySearchLoop(&arr[0], arrLen, val) <<" recursive strategy=" << binarySearchRecursive(&arr[0], 0,arrLen-1, val) << endl;
	
}

void countOccurences() {
	//implement with time complexity of O(log(n))

	return;
}
int countOnesInSortedArrayOptimum(int arr[], int arrLen){
	int cnt = 0;
	int low = 0;
	int high = arrLen-1;
	int mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (arr[mid] == 0) {
			//move right
			low = mid + 1;
		}else{
			if (mid == 0 || arr[mid - 1] != 1) {
				return arrLen - mid; //important!!
			}
			else {
				//move left
				high = mid - 1;
			}
		}
	}
	return 0; //important just return zero - arrLen-mid fill fail in all zero case
}

void countOnesInSortedArray() {
	//implement with time complexity of O(log(n))
	int arr[] = { 0,0,0,0,0,0,0 };
	int arrLen = sizeof(arr) / sizeof(arr[0]);
	cout << "Counted ones in sorted array is " << countOnesInSortedArrayOptimum(&arr[0], arrLen) << endl;

	return;
}


int squareRootOptimum(int x) {
	int res=0;
	/*O(log(n)) - binary search
	carefull with corner cases
	*/
	int high = x;
	int low = 0;
	int mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (mid*mid < x) {
			//move right
			low = mid + 1;
			res = mid; //!!important
		}else if(mid*mid > x){
			//move left
			high = mid - 1;
		}else {
			return mid;
		}
	}
	return res;
}

int squareRootNaive(int x) {
	/*
	O(sqrt(n))
	*/
	int i = 0;
	while (i*i <= x) {
		i++;
	}
	return i - 1; //!!important remember to take away 1 from this, hint to run through the code white board
}

void squareRoot() {
	int x=16;
	/*
	!!important hint
	monotonically increasing function, find x for f(x), binary search can be used
	sqrt of 4-8 is 2
	sqrt of 9-15 is 3
	sqrt of 16-24 is 4
	sqrt of 25-35 is 5
	sqrt of 36-48 is 6
	sqrt of 49-63 is 7
	*/
	cout << "Square root navie= "<< squareRootNaive(x) <<" log(n) soultion = "<< squareRootOptimum(x) << endl;

	return;
}

int searchInfiniteArrayOptimum(int arr[], int x) {
	/*
	log(2*pos)=log(pos)
	log(pos)+log(pos)~log(pos)
	*/
	
	//seems need not handle arr[0] check case as the next binary search will handle it  low=1/2=0	, nevertheless just being safer
	if (arr[0] == x) {
		return 0;
	}

	//narrow down the search range
	int i=1;
	while (1) {
		if (arr[i] < x) {
			i *= 2;
		}else {
			break;
		}
	}
	//make your life easy mate
	if (arr[i] == x) {
		return i;
	}

	/*start performing binary search with corrected low and high
	binarySearch(arr,i/2,i-1)
	*/
	int low = i/2; //can start with zero, but optimized solution to tune further exist
	int high = i-1; //important!! without this wrong answer when the element is at end of the array
	int mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (arr[mid] < x) {
			//move right
			low = mid + 1;
		}
		else if (arr[mid] > x) {
			//move left
			high = mid - 1;
		}
		else {
			return mid;
		}
	}

	return -1; //not found
}

int searchInfiniteArrayNaive(int arr[],int x) {
	int resIdx = -1;
	int i = 0;
	while (1) { //this test only for protection
		if (arr[i] == x) {
			resIdx = i;
			break;
		}
		else if (arr[i] > x ) {
			break;
		}
		i++;
	}
	return resIdx;
}


void searchInfiniteArray()
{
	/*
	unbounded binary search
	length is super big
	*/
	//make sure your array is big enough
	int arr[] = {5,10,15,20,21,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40};
	int arrLen = sizeof(arr) / sizeof(arr[0]);
	int x = 26;
	cout << "searchInfiniteArray navie= " << searchInfiniteArrayNaive(arr, x) << " log(n) soultion = " << searchInfiniteArrayOptimum(arr, x) << endl;
	
	return;
}

int binarySearchGeneric(int *arr, int low,int high,int val) {
	int mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (arr[mid] < val) {
			//move right
			low = mid + 1;
		}
		else if (arr[mid] > val) {
			//move left
			high = mid - 1;
		}
		else {
			return mid;
		}
	}
	return -1;
}

int searchSortedRotatedOptimum(int *arr, int arrLen, int val) {
	/*
	use the idea that one half is always be in sorted ascending order
	*/
	
	int high=arrLen-1;
	int low=0;
	while (low <= high) {
		int mid = (low + high) / 2;
		if(arr[mid] == val){
			return mid;
		}
		if (arr[mid] > arr[low]  ) {
			//left half is sorted
			if (val >=arr[low]  && val < arr[mid]){
			//value is in the range of left half of the normal sorted section
				high = mid - 1;
			}
			else {
				//value in the right of the sorted rotated section
				low = mid + 1;
			}
		}
		else if (arr[mid] < arr[high] ){
			//right half sorted
			if (val > arr[mid] && val <=arr[high]) {
				//val in the range of the right half of the normal sorted section
				low = mid + 1;
			}
			else {
				//value in the left half of the sorted section
				high = mid - 1;
			}
		}

	}
	return -1;
}

void searchSortedRotatedArray()
{
	/*
	O(log(n)) solution
	*/
	int arr[] = { 30,31,32,33,34,35,36,37,38,39,40 ,5,10,15,20,21,25,26,27,28,29};
	int arrLen = sizeof(arr) / sizeof(arr[0]);
	int val = 26;
	cout << "searchInfiniteArray optimum= " << searchSortedRotatedOptimum(arr, arrLen,val) << endl;
	return;
}

int findPeakNaive(int *arr, int arrLen) {
	/*
	naive solution O(n)
	*/
	int peak = -1;
	//no harm in handling individual cases separatly - a good example below
	if (arrLen == 1) {
		return arr[0];
	}
/*	if (arrLen == 2 ) {
		if (arr[0] > arr[1]) {
			return arr[0];
		}
		else {
			return arr[1];
		}
	}*/
	//better approach than above, as it eliminates checking for the peak in the the array end
	if (arr[0] > arr[1]) {
		return arr[0];
	}
	if (arr[arrLen-1] > arr[arrLen -2]) {
		return arr[arrLen - 1];
	}
	//now minimum of 2 element exist at this point so it is safe to use i-1
	//starting i with one comes handly, as it allow using i-1 safely
	for (int i = 1; i < arrLen-1; i++) {
		if (arr[i - 1] <= arr[i] && arr[i] >= arr[i + 1]) {
			return arr[i];
		}
	}
	return -1;
}

int findPeakOptimum(int *arr,int arrLen) {
	/*
	O(log(n))
	*/
	//no harm in handling individual cases separatly - a good example below
	if (arrLen == 1) {
		return arr[0];
	}
	if (arr[0] > arr[1]) {
		return arr[0];
	}
	if (arr[arrLen - 1] > arr[arrLen - 2]) {
		return arr[arrLen - 1];
	}
	int low = 0;
	int high = arrLen - 1;
	int mid;
	while (low <= high) {
		mid = (low + high) / 2;
		/*
		fact:
		if mid element is less than the element in a given side (right or left), then there always exists a peak element on that side
		*/
		if (arr[mid] < arr[mid - 1]) {
//			peak should exist on the left 
			high = mid - 1;
		}
		else if (arr[mid] < arr[mid + 1]) {
			//peak should exist on the right
			low = mid + 1;
		}
		else {
			return arr[mid];
		}
	}
}

int findPeakOptimumFromG4G(int *arr, int arrLen) {
	/*
	Solution 2 from G4G - not sure why many of the corner case handling are required
	O(log(n))
	*/
	int low = 0;
	int high = arrLen - 1;
	int mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if ((mid == 0 || arr[mid-1] <= arr[mid] ) && 
			(mid == arrLen-1 || arr[mid +1 ] <= arr[mid]))
		{	
			return arr[mid];
		}
		/*
		fact:
		if mid element is less than the element in a given side (right or left), then there always exists a peak element on that side
		*/
		if(mid>0 && arr[mid-1] >= arr[mid]){
			//			peak should exist on the left 
			high = mid - 1;
		}
		else{
			//peak should exist on the right
			low = mid + 1;
		}
	}
	return -1;
}

void findPeak() {
	/*
	unsorted case
	multiple peaks possible
	*/
	int arr[] = { 6,7,50,22,23,20,12 };
	int arrLen = sizeof(arr) / sizeof(arr[0]);
	cout << "findPeakNaive= " << findPeakNaive(arr, arrLen) <<  "findPeakOptimum= " << findPeakOptimum(arr, arrLen) << endl;
	return;
}


bool countPairGivenSum() {

	return false;
}

bool countTripletGivenSum() {
	
	return false;
}

bool countPythogyreonTripletsGivenSum() {
	
	return false;
}


void countSetsGivenSum() {
	cout << "countPairGivenSum="<< countPairGivenSum() << "countTripletGivenSum=" << countTripletGivenSum() << "countPythogyreonTripletsGivenSum="<< countPythogyreonTripletsGivenSum();
	return;
}

void medianSortedArray() {

	cout << "medianSortedArray=" << countPairGivenSum() << endl;
	return;
}

void majorityElements() {
	//incomplete
	return;
}

int minValueOfMaxPagesReadByStudentNaive(int *arr,int arrLen,int k){

	for (int i = 0; i < arrLen; i++) {
		for (int j = i+1; j < arrLen; j++) {
			
		}
	}
	return 0;
}

int minValueOfMaxPagesReadByStudentOptimum(int *arr, int arrLen,int k) {

	return 0;
}

void minValueOfMaxPagesReadByStudent() {
	//incomplete
	int arr[] = {10,20,30,40};
	int arrLen = sizeof(arr) / sizeof(arr[0]);
	int k = 2; //number of students
	cout << "minValueOfMaxPagesReadByStudent naive=" << minValueOfMaxPagesReadByStudentNaive(arr, arrLen, k) << "optimum=" << minValueOfMaxPagesReadByStudentOptimum(arr, arrLen, k) << endl;
	return;
}

void search()
{
#if 0
	/*
		find if an element repeats itself in an array for more than n/2 time and if so return the index else return -1
	*/
	majorityElements();

	/*
	approcches
	1. count pairs with given sum
	2. count triplets with given sum
	3. find if there is a triplet a,b,c such that a^2+b^2=c^2 - pythogyreon triplets
	*/
	countSetsGivenSum(); return;
#endif
	/*
		findPeakElement -- confusing!! - retry
		
		    |
		    |  
		----|----
	*/
	findPeak(); return;
	/*
	search element in sorted rotated array
	*/
	searchSortedRotatedArray(); return;

	/*
	when array length is huge or unbounded binary search
	*/
	searchInfiniteArray(); return;
	/*
		squareRoot
	*/
	squareRoot();
	/*
	countOccurences
	*/
	countOnesInSortedArray(); return;

	/*
	countOccurences
	*/
	countOccurences(); return;

	/*
	binary search
	*/
	binarySearch();
	return;

}

