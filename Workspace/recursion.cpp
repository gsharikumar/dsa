// recursion.cpp
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int getSum(int n) {
	//optimized method is n*(n+1)/2, but following used for practise
	//time complexity O(n+1)->O(n) space complexity O(n+1) ->O(n)
	//T(n)=T(n-1)+O(1)
	if (n <= 1) return n;
	return n + getSum(n - 1);
}

void getSumNaturalNum() {
	int N = 5;
	cout << "Sum of first N natural numbers N=" << N << "is" << getSum(N) << endl;
	return;
}


bool isPalindromeUsingRecursion(string &str,int start, int end) {
	//T(n)=T(n-2)+O(1)
	//O(n) -- auxiliary space
	if (start >=end ) return true;
	if (str.at(start) != str.at(end)) return false;
	return isPalindromeUsingRecursion(str, start+1, end-1);

		
}

void isPanlidrome() {
	string str = "a";
	size_t end = str.length();
	cout << "Palindrome check status for " << str << " is " << isPalindromeUsingRecursion(str, 0, end - 1) << endl;
	return;
}

void genSubSetRecursive(char *str, int strLen) {

	if (strLen <= 0){
		return;
	}
	cout << str[strLen-1] << " " ;
	genSubSetRecursive(str, --strLen);
	return;
}

int maxPieceRecursive(int L, int* cutLenArr,int cutLenArrSize) {
	if (L == 0) {
		return 0;
	}else if(L <0){
		return -1;
	}
	
	int tmpSum;
	int currMaxSum=INT_MIN;
	for (int i = 0; i < cutLenArrSize; i++) {
		tmpSum=maxPieceRecursive(L- cutLenArr[i], cutLenArr, cutLenArrSize);
		//cout <<i <<"="<< tmpSum <<endl;
		if (currMaxSum < tmpSum) {
			currMaxSum = tmpSum;
		}
	}
	if (currMaxSum < 0) {
		return -1;
	}
	return ++currMaxSum;
}

void ropeCutting() {

	//time complexity O(3^n)
	//int L = 5;
	//int cutLenArr[] = { 2, 5, 1 };
	//int cutLenArrSize = 3;
	int L = 23;
	int cutLenArr[] = { 11, 9, 12 };
	int cutLenArrSize = 3;

	cout << "Cut ribbons for length=" << L << " is "<<maxPieceRecursive(L, cutLenArr, cutLenArrSize) << endl;

}

void generateSubsetsRecursive(string curr,string str, int idx) {
	//int conversion required for comparison!!
	if (idx>(int)str.length() ) { 
		return;
	}
	idx++;	
	string nxtStr;
	for (int i = 1; i <= str.length(); i++)
		nxtStr.append(str, i, 1);
	string nxtCurr = curr;
	nxtCurr.append(str, 0, 1);
	cout << nxtCurr << ",";

	generateSubsetsRecursive(curr, nxtStr, idx);

	generateSubsetsRecursive(nxtCurr, nxtStr, idx);
	
	

	return;
}           

void generateSubsets() {
	/*
	generate subsets
	n - len of the string
	number subsets are 2^n
	*/
	string str = "ABC";
	string curr="";
	return generateSubsetsRecursive(curr, str, -1);
}

void towerOfHanoiRecursive(int n, char A, char B, char C) {
	if (n == 1) {
		cout << "Move " << n << " " << static_cast<char>(A) << " to " << static_cast<char>(C) << " via " << static_cast<char>(B)<<endl;
		return;
	}
	towerOfHanoiRecursive(n - 1, A, C, B);
	cout << "Move " << n << " " << static_cast<char>(A) << " to " << static_cast<char>(C) << " via " << static_cast<char>(B)<<endl;
	towerOfHanoiRecursive(n - 1, B, A, C);
	return;
}

void towerOfHanoi() {
/*
	N=2
	
	N=3
	Move 1 A to C via B
	Move 2 A to B via C
	Move 1 C to B via A
	Move 3 A to C via B
	Move 1 B to A via C
	Move 2 B to C via A
	Move 1 A to C via B
*/
	towerOfHanoiRecursive(3, 'A', 'B', 'C');

	return;
}

int josephusProblemRecursive(int n, int k) {
	if (n == 1)
		return 0;
	else 
		return (josephusProblemRecursive(n - 1, k) + k) % n;
}

void josephusProblem() 
{
	int n = 5;
	int k = 5;
	cout << "josephus" << josephusProblemRecursive(n, k) << endl;
	return;
}


int subSetSumRecursive(vector<int> curr, vector<int> arr,int idx,int target_sum) {
	int ret = 0;
	if (arr.size() == idx) {
		int sum = 0;
		std::cout << "{";
		for (int i = 0; i < curr.size(); ++i) {
			sum += curr[i];
			std::cout << curr[i] << ',';
		}
		std::cout << "} = "<<sum<<endl;
		if (0 == target_sum) {
			ret = 1;
		}
	}else {
		vector<int> nxt=curr;
		nxt.push_back(arr.at(idx));
		idx++;
		ret+=subSetSumRecursive(curr, arr, idx,target_sum);
		ret+=subSetSumRecursive(nxt, arr, idx,target_sum-arr.at(idx-1));
	}
	return ret;
}

void subSetSumRecursiveProblem()
{
		/*
	subset sum recursive
	O(2^n) = 2^n(number of end nodes) + 2^-1 (number of intermediate nodes)
	 */
  int arr[] = { 10, 5, 2,3,6 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    vector<int> vect(arr, arr + n);
	int target_sum = 8;

	vector<int> curr;
	curr.clear();
	cout << "matched sum cnt =" << subSetSumRecursive(curr, vect, 0, target_sum) << endl;;
	return;
}

int recursion()
{
	/*
	subset sum recursive
	*/
	subSetSumRecursiveProblem();
	return 0;
	/*
	josephes problem
	*/
	josephusProblem();

	/*
	tower of Hanoi
	*/
	towerOfHanoi();

	/*
	generate subsets	
	*/
	generateSubsets();
	
	/*
	rope cutting problem
	*/
	ropeCutting();

	/*
	sum of first n natural numbers
	*/
	getSumNaturalNum();

	/*
	Chk for palindrome
	*/
	isPanlidrome();

	return 0;
}

