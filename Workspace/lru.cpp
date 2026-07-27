// bt.cpp
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>

using namespace std;

#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) < (Y)) ? (Y) : (X))



struct MyHash {
	int bucket;
	list <int>* table;
	MyHash(int b) {
		bucket = b;
		table = new list<int>[b];
	}
	void insert(int key) {
		int idx = key % bucket;
		table[idx].push_back(key);
		return;
	}
	bool search(int key) {
		int idx = key % bucket;
		for(auto x:table[idx])
			if (x == key) return true;
		return false;
	}
	void remove(int key) {
		int idx = key % bucket;
		table[idx].remove(key);
		return;
	}
};



void hashing() {
	int arr[] = {1,2,3,4,5};
	int arrLen = sizeof(arr) / sizeof(arr[0]);
	//struct MyHash *hash=MyHash(5);
	return;
}
