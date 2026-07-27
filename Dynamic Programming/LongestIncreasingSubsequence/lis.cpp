

class Solution
{
public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequenceDP(int n, int a[]) {
        int lis[n];
        int maxLis;
        maxLis = lis[0] = 1;

        for (int i = 1; i < n; i++) {
            lis[i] = 0;
            for (int j = 0; j < i; j++) {
                if (a[i] > a[j]) {
                    lis[i] = max(lis[j], lis[i]);
                }
            }
            lis[i]++;
            maxLis = max(maxLis, lis[i]);
        }

        //instead of maxLis=max(maxLis,lis[i]); 
        //find maximum in a seperate logic, easy for understand
#if 0
        maxLis = lis[0];
        for (int i = 1; i < n; i++) {
            maxLis = max(maxLis, lis[i]);
        }
#endif
        return maxLis;
    }

    int binarySearch(int tail[], int l, int r, int key) {
        while (l < r) {
            int m = l + (r - l) / 2;
            if (key <= tail[m]) {
                r = m;
            }
            else {
                l = m + 1;
            }
        }
        return r;
    }

    int longestSubsequenceOpt(int n, int a[])
    {
        int len;
        int tail[n];
        tail[0] = a[0];
        len = 1;
        for (int i = 1; i < n; i++) {
            if (a[i] > tail[len - 1]) {
                tail[len] = a[i];
                len++;
            }
            else {
                //find Ceil Search Index
                int replaceIdx = binarySearch(tail, 0, len - 1, a[i]);
                tail[replaceIdx] = a[i];
            }
        }
        return len;
    }

    int longestSubsequence(int n, int a[])
    {
        // your code here
         //optimum solution is O(nlogn)
        return longestSubsequenceOpt(n, a);

        //DP solution is O(n^2)
        return longestSubsequenceDP(n, a); //O(N)

        //navie solution is exponential time O(2^n) included and not included tree formation 


    }
};