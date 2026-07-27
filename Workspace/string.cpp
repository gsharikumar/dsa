// ll.cpp
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

std::string reverseWords(std::string S)
{
	// code here 
	int n = S.length();
	if (n <= 0) {
		return NULL;
	}
	int i;
	char *sdot, *edot;
	char str[64 + 1] = { '\0' };
	std::string rev;
	for (i = 0; i < n; i++) {
		str[n-i-1] = S[i];
	}
	edot=sdot = &str[0];
	while (edot) {
		edot = strchr(sdot, '.');
		if (edot==NULL) {
			if (strlen(sdot) > 0) {
				edot = sdot + strlen(sdot)+1;
			}			
		}
		if(edot){
			for (i = 0; i < (edot - sdot)/2; i++) {
				swap(sdot[i], edot[-i-1]);
			}
			std::string tmp= std::string(sdot, edot+1);
			rev += tmp;
			sdot = edot+1;
		}
	}
	return rev;
}

void string() {
	std::string str = "mno.pno";
	std::cout << "string org=" << str << "reversed=" << reverseWords(str) << endl;
	return;
}