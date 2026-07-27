// array.cpp
//

#include <iostream>

using namespace std;

#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) < (Y)) ? (Y) : (X))

void stockBuySell1() {
	//int arr[] = { 1,5,3,8,12 }; //--> 13
	//int arr[] = { 30,20,10 }; //--> 0
	//int arr[] = { 10,20,30 }; //-->20
	int arr[] = { 1,5,3,1,2,8 }; //-->11
	int arrLen = sizeof(arr) / sizeof(arr[0]);
	int profit = 0;
	int buy=0;
	int sell=0;
	buy = sell = arr[0];
	int maxProfit = 0;
	int totalProfit=0;
	
	for (int i = 1; i < arrLen; i++) {
		profit = (arr[i] - buy);
		if (profit >= maxProfit) {
			//happy times
			maxProfit = profit;
		} else {
			//woo.. market going down cache the profit, selling non-causal
			totalProfit += maxProfit;
			maxProfit = 0;
			//new buy point or move to new buy point
			buy = arr[i];
		}
	}
	totalProfit += maxProfit;
cout << "profit=" << totalProfit << endl;
//getchar();
return;
}

void stockBuySell2() {
	//wow!! elegant solution, did not think of this before
	int arr[] = { 1,5,3,8,12 }; //--> 13
	//int arr[] = { 30,20,10 }; //--> 0
	//int arr[] = { 10,20,30 }; //-->20
	//int arr[] = { 1,5,3,1,2,8 }; //-->11
	int arrLen = sizeof(arr) / sizeof(arr[0]);
	int profit = 0;
	int totalProfit = 0;
	for (int i = 1; i < arrLen; i++) {
		profit = (arr[i] - arr[i - 1]);
		if (profit > 0) {
			//happy times
			totalProfit += profit;
		}
	}
	cout << "profit=" << totalProfit << endl;
	//getchar();
	return;
}

void trapRainWater()
{
	int arr[] = { 2,0,2 }; //2
	//int arr[] = { 3,0,1,2,5 }; //6
	//int arr[] = { 1,2,3 }; //0
	//int arr[] = { 3,2,1 }; //0 --> corner cases -take note

	int arrLen = sizeof(arr) / sizeof(arr[0]);
	int low;
	int high;
	low = arr[0];
	high = -1;
	int trappedWaterCached = 0;
	int trappedWater = 0;
	for (int i = 1; i < arrLen; i++) {
		if ((low - arr[i]) > 0) {
			trappedWaterCached += low - arr[i];
		}
		else {
			trappedWater += trappedWaterCached;
			trappedWaterCached = 0;
			low = arr[i];
		}
	}
	cout << "trapRainWater=" << trappedWater << endl;
	return;
}

void maxSumSubarray1Attempt() {
	//O(n)
	int arr[] = { -5,1,-2,3, -1,2,-2 };
	int arrLen = sizeof(arr) / sizeof(arr[0]);
	int currSum;
	int prevMaxSum = arr[0];
	int maxSum = arr[0];
	for (int i = 1; i < arrLen; i++) {
		currSum = arr[i] + prevMaxSum;
		if (currSum > arr[i]) {
			prevMaxSum = currSum;
		}
		else {
			prevMaxSum = arr[i];
		}
		if (prevMaxSum > maxSum) {
			maxSum = prevMaxSum;
		}
	}
	cout << "maxSumSubarray=" << maxSum << endl;
	return;
}

void maxSumSubarray() {
	//O(n) - kanade algorithm
	int arr[] = { -5,1,-2,3, -1,2,-2 };
	int arrLen = sizeof(arr) / sizeof(arr[0]);
	int maxEnding = arr[0];
	int res = arr[0];
	for (int i = 1; i < arrLen; i++) {
		maxEnding = MAX(maxEnding + arr[i], arr[i]);
		res = MAX(maxEnding, res);
	}
	cout << "maxSumSubarray=" << res << endl;
	return;
}

void maxLenEvenOddSubarray() {
	//O(n) - similar to kanade maxSumSubArray approach
	int arr[] = { 5, 10, 20, 56, 3, 8 };
	int arrLen = sizeof(arr) / sizeof(arr[0]);
	int res = 1;
	int curr = 1;
	for (int i = 1; i < arrLen; i++) {
		if ((arr[i] % 2 == 0 && arr[i - 1] % 2 != 0) ||
			(arr[i] % 2 != 0 && arr[i - 1] % 2 == 0)){
			curr++;
			 
		}else {
			curr = 1;
		}
	}
	cout << "maxLenEvenOddSubarray=" << res << endl;
	return;
}



void maxSumCircularSubarrayNaive() {
	//not working
	//O(n^2)-naive solution
	int arr[] = { 5,-2,3,4}; //res=12
	int arrLen = sizeof(arr) / sizeof(arr[0]);
	int k;
	int res = arr[0];
	for (int i = 0; i < arrLen; i++) {
		int currMax = arr[i];
		int currMaxEnding = arr[i];
		for (int j = 1; j < arrLen; j++) {
			k = (i + j) % arrLen;
			currMaxEnding = MAX(arr[k], arr[k]+ currMaxEnding);
			currMax = MAX(currMax, currMaxEnding);
		}
		res = MAX(res, currMax);
	}
	cout << "maxSumCircularSubarray=" << res << endl;
	return;
}

void maxSumCircularSubarray() {
	//O(n) - kanade algorithm
	//int arr[] = { -5,-2,3,4 }; //res=5
	int arr[] = { 8,-4,3,-5,4 }; //res=5
	int arrLen = sizeof(arr) / sizeof(arr[0]);
	int maxEnding = arr[0];
	int minEnding = arr[0];
	int resMax = arr[0];
	int resMin = arr[0];
	int arrSum = arr[0];
	for (int i = 1; i < arrLen; i++) {
		//find max Sum - normal subarray
		maxEnding = MAX(maxEnding + arr[i], arr[i]);
		resMax = MAX(maxEnding, resMax);
		//find min  Sum - normal subarray
		minEnding = MIN(minEnding + arr[i], arr[i]);
		resMin = MIN(minEnding, resMin);
		//find array sum
		arrSum += arr[i];
	}

	/*
	
	Used method: find max circular subarray sum use the below formula
	array Sum = maxSum Subarray + minSum Subarray

	Other method: Invert the array elements (negate) and find the max sum subarray using normal method -> gives minimum sum subarray
	*/
	int res;
	if (resMax < 0) {
		res = resMax;
	} else {
		int resMaxCircle = arrSum - resMin;
		//find the max sum of normal sub & max sum of circular subarray
		res = MAX(resMax, resMaxCircle);
	}
	cout << "maxSumCircularSubarray-kanade=" << res <<endl;
	return;
}

int array()
{
	/*
	maximum sum circular subarray
	*/
	maxSumCircularSubarray();
	return 0;
	/*
	maximum even odd subarray
	*/
	maxLenEvenOddSubarray();

	/*
	maximum sum subarray
	*/
	maxSumSubarray();
	/*
	trapping rain water
	*/
	trapRainWater();
	/*
	part 2 - elegant solution
	*/
	stockBuySell2();
	/*
	part 1
	*/
	stockBuySell1();


    std::cout << "Hello World!\n";
}