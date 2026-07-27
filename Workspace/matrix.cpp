// ll.cpp
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void snakePattern1() {
	int mat[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	int rows = 3;
	int cols = 3;
	int r, c;
	int ci = 0;
	int ct = cols;
	int cd = 1;
	for (r = 0; r < rows; r++) {
		for (c = 0; c < cols; c++) {
			cout << mat[r][ci] << ", ";
			ci = ci + cd;
		}
		ci = ((r % 2) == 0) ? cols - 1 : 0;
		cd = cd * -1;
	}
	return;
}

void snakePattern2() {
	/*
	though there is repeat code than the version 1, it is simple and less chance of making mistakes
	*/
	int mat[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	int rows = 3;
	int cols = 3;
	int r, c;
	for (r = 0; r < rows; r++) {
		if (r % 2) {
			for (c = cols-1; c >=0; c--) {
				cout << mat[r][c] << ", ";
			}
		}
		else {
			for (c = 0; c < cols; c++) {
				cout << mat[r][c] << ", ";
			}
		}
	}
	return;
}

#define ROWS 2
#define COLS 3
void boundaryTraversal() {
	/*
	important!! 
	1. seperate case to handle rows ==1 && cols==1 are unavoidable
	2. in switching remember to always skip the element which was printed last
	*/
	int mat[ROWS][COLS] = { {1,2,3},{4,5,6} };// , { 4,5,6 }, 
	int rows = ROWS;
	int cols = COLS;
	int r, c;

	if (rows == 1) {
		for (c = 0; c < cols; c++) {
			cout << mat[0][c] << ", ";
		}
	}
	else if (cols == 1) {
		for (r = 0; r < rows; r++) {
			cout << mat[r][0] << ", ";
		}
	}
	else {
		/*
		method-1
		simple and easy for follow, the next method is not
		mindful about ignoring the already printed elements in the ends
		*/
		cout << "METHOD-1-easy to follow" << endl;
		for (c = 0; c < cols; c++) {
			cout << mat[0][c] << ", ";
		}			
		for (r = 1; r < rows; r++) {
			cout << mat[r][cols - 1] << ", ";
		}
		for (c = cols-2; c >=0 ; c--) {
			cout << mat[rows-1][c] << ", ";
		}
		for (r = rows - 2; r > 0; r--) {
			cout << mat[r][0] << ", ";
		}
		cout << endl;
		cout << "METHOD-2-easy to make mistakes" << endl;
		/*
		method-2
		this appears to be over optimized and difficult to follow, but works though
		*/
		for (r = 0; r < rows; r++) {
			if (r == 0) {
				for (c = 0; c < cols; c++) {
					cout << mat[r][c] << ", ";
				}
			}
			else {
				cout << mat[r][cols - 1] << ", ";
			}
		}
		for (r = rows - 1; r > 0; r--) {
			if (r == rows - 1) {
				for (c = cols - 2; c >= 0; c--) {
					cout << mat[r][c] << ", ";
				}
			}
			else {
				cout << mat[r][0] << ", ";
			}
		}
	}
	return;
}

void transpose() {
	/*
	transpose of a square matrix
	*/
#define N 3
	int mat[N][N] = { {1,2,3},{4,5,6},{7,8,9} };// , { 4,5,6 }, 
	int matT[N][N];
	int r, c;
	/*
	method 2: efficient solution inplace no extra auxiliary space
	*/
	for (r = 0; r < N; r++) {
		for (c = r+1; c < N; c++) {
			swap(mat[r][c], mat[c][r]);
		}
	}

	for (r = 0; r < N; r++) {
		for (c = 0; c < N; c++) {
			cout << mat[r][c] << ",";
		}
		cout << endl;
	}
	return;
	/*
	method 1: non optimal requires O(n+n) auxiliary space
	*/
	for (r = 0; r < N; r++) {
		for (c = 0; c < N; c++) {
			matT[c][r] = mat[r][c];
		}
	}
	for (r = 0; r < N; r++) {
		for (c = 0; c < N; c++) {
			cout << matT[r][c] << ",";
		}
		cout << endl;
	}

	return;
}

void rotateAntiClockwise90Navie() {
	#define N 3
	int mat[N][N] = { {1,2,3},{4,5,6},{7,8,9} };// , { 4,5,6 }, 
	int matT[N][N];
	int r, c;
	for (r = 0; r < N; r++) {
		for (c = 0; c < N; c++) {
			matT[N-c-1][r] = mat[r][c];
		}
	}

	for (r = 0; r < N; r++) {
		for (c = 0; c < N; c++) {
			cout << matT[r][c] << ",";
		}
		cout << endl;
	}

	return;
}

void rotateAntiClockwise90() {
	/*
	efficient solution
	- transpose of a matrix
	- reverse individual cols
	*/
#define N 3
	int mat[N][N] = { {1,2,3},{4,5,6},{7,8,9} };// , { 4,5,6 }, 
	int r, c;
	//first transpose
	for (r = 0; r < N; r++) {
		for (c = r+1; c < N; c++) {
			swap(mat[r][c] , mat[c][r]);
		}
	}
	//invert the columns

	for (c = 0; c < N; c++) {
		int low=0;
		int high = N - 1;
		while (low < high)
		{
			swap(mat[low][c], mat[high][c]);
			low++;
			high--;
		}
	}
	
	
	for (r = 0; r < N; r++) {
		for (c = 0; c < N; c++) {
			cout << mat[r][c] << ",";
		}
		cout << endl;
	}
	return;
}

void spiralTraversal() {
	/*
	1. take care of increments and decrements
	2. using left right top bottom is more intuitive
	3. handling corner cases top<=bottom-1 etc
	*/
#define N 3
#define M 3
	int r = 0, c = 0;
	int rows = M, cols = N;
	int mat[M][N] = { {1,2,3},{4,5,6},{7,8,9} };// , { 4,5,6 }, 
	int left = 0;
	int top = 0;
	int right = cols;
	int bottom = rows;
	while(top <=bottom-1 && left<=right-1){
		for (c = left; c < right; c++) {
			cout << mat[top][c] << ",";
		}
		top++;
		for (r = top; r < bottom; r++) {
			cout << mat[r][right- 1] << ",";
		}
		right--;
		if (top <= bottom-1)  //purpose ??
		{
			for (c = right- 1; c >= left; c--) {
				cout << mat[bottom-1][c] << ",";
			}
			bottom--;
		}
		if (left<= right-1) //purpose 
		{
			//important! be mindful about decrement or increment appropriatly
			for (r = bottom -1; r >= top; r--) {
				cout << mat[r][left] << ",";
			}
			left++;
		}
	}
	return;
}

void searchRowWiseColWiseSortedMatrix() {

	#define N 4
	#define M 4
	int r = 0, c = 0;
	int rows = M, cols = N;
	int mat[M][N] = { {10,20,30,40},{15,25,35,45},{27,29,37,48},{32,33,39,50} };// , { 4,5,6 }, 
	int left = 0;
	int top = 0;
	int right = cols;
	int bottom = rows;
	int i = 0;
	r = 0;
	c = cols - 1;
	int search = -1;
	bool searchStatus = false;
	while (r<rows && c>=0) {
		if (mat[r][c] < search) {
			r++;
		}
		else if (mat[r][c] > search) {
			c--;
		}
		else {
			searchStatus = true;
			cout << "Found" << endl;
			break;
		}
		i++;
	}
	if (!searchStatus) {
		cout << "Not found";
	}
	return;         
}

void matrix() {
	searchRowWiseColWiseSortedMatrix(); return;
	spiralTraversal(); return;
	rotateAntiClockwise90(); return;
	transpose();
	boundaryTraversal();
	snakePattern2();
	//snakePattern1(); - not easy to follow, avoid this


	return;
}