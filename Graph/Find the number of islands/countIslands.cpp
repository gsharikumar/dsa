//{ Driver Code Starts
// Initial Template for C

// Program to count islands in boolean 2D matrix
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define COL 501


// } Driver Code Ends
// User function Template for C

void countIslandRecur(int M[][COL],int n,int m,int i,int j,int visited[][COL]){
    //missed diagonal
    if(i<0 || i>(n-1) || j<0 || j>(m-1)){
        return;
    }
    if(visited[i][j]==1){
        return;
    }
    if(M[i][j]==0){
         return;
     }
    visited[i][j]=1;
    //-> |
    countIslandRecur(M,n,m,i+1,j,visited);
    countIslandRecur(M,n,m,i,j+1,visited);
    //-> --
    countIslandRecur(M,n,m,i-1,j,visited);
    countIslandRecur(M,n,m,i,j-1,visited);
    
    //diagonal
    //-> /
    countIslandRecur(M,n,m,i+1,j+1,visited);
    countIslandRecur(M,n,m,i-1,j-1,visited);
    //-> \ - this one missed
    countIslandRecur(M,n,m,i+1,j-1,visited);
    countIslandRecur(M,n,m,i-1,j+1,visited);
    return;
}

int countIslands(int M[][COL], int n, int m) {
    // your code goes here
    int islandCnt=0;
    int visited[n][COL];
    memset(visited,0,sizeof(visited));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
        {
            if(visited[i][j]==0 && M[i][j]==1){
                countIslandRecur(M,n,m,i,j,visited);
                islandCnt++;
            }
        }
    }
    return islandCnt;
}


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {

        int n, m;
        scanf("%d %d", &n, &m);

        int M[n][COL];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &M[i][j]);
            }
        }

        int ans = countIslands(M, n, m);
        printf("%d\n", ans);
    }

    return 0;
}

// } Driver Code Ends