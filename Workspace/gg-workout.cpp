// gg-workout.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

extern void mem();
extern void search();
extern int array();
extern int recursion();
extern int sort();
extern void ll();
extern void matrix();
extern void string();
extern void bt();
extern void cache_eviction();
extern void bst();
extern void graph();

/*
O(1) < O(log n) < O(n) < O(n log n) < O(n ^ 2)

Note:
1. n>nlog(n) for small values of n, but big values of n, which we are mostly concerned about n<nlogn
2. 1< log n when n is sufficiently high, thus n < n log n
*/

int main()
{
	mem(); return 0;
	ll(); return 0;
	graph(); return 0;
	bst(); return 0;
	cache_eviction(); return 0;
	bt(); return 0;
	matrix(); return 0;
	ll(); return 0;
	sort(); return 0;
	search(); return 0;
	array(); return 0;
	recursion(); return 0;
	string();
	lru();
	return 0;
}
