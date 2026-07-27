// { Driver Code Starts
//Initial Template for C

#include <stdio.h>
#include <stdbool.h>


 // } Driver Code Ends
//User function Template for C


//Function is to check whether two strings are anagram of each other or not.
bool isAnagram(char a[], char b[]){
    
    // Your code here
    int i;
    char hash[256]={0};
    int n=strlen(a);
    int m=strlen(b);
    if(n!=m || n==0){
        return false;
    }

    for(i=0;i<n;i++){
        hash[a[i]]++;
        hash[b[i]]--;
    }
    for(i=0;i<256;i++){
        if(hash[i]){
            return false;
        }
    }
    return true;
}


// { Driver Code Starts.

int main() {
    
    int t;

    scanf("%d", &t);

    while(t--){
        char c[10000], d[10000];

        scanf("%s%s", &c, &d);

        if(isAnagram(c, d)) printf("YES\n");
        else  printf("NO\n");
    }

}
  // } Driver Code Ends