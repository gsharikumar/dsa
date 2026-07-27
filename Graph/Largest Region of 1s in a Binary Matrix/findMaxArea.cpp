//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int rows;
    int cols;
    int dir[8][2]={{0,1},{0,-1},{1,0},{-1,0},{-1,1},{1,-1},{1,1},{-1,-1}};
    bool isPosValid(int r,int c){
        if(r<0||c<0||r>=rows||c>=cols){
            return false;
        }
        return true;
    }
    //Function to find unit area of the largest region of 1s.
    int dfsRecur(vector<vector<int>>& grid,int r,int c,vector<vector<bool>>& visited){
        if(!isPosValid(r,c)){
            return 0;
        }
        if(visited[r][c]==true){
            return 0;
        }
        visited[r][c]=true;
        if(grid[r][c]==0){
            return 0;
        }

        int area=0;
        if(grid[r][c]==1){
            area=1;
        }

        for(int i=0;i<8;i++){
            int nR;
            int nC;
            nR=r+dir[i][0];
            nC=c+dir[i][1];
            area+=dfsRecur(grid,nR,nC,visited);
        }
        return area;
    }
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        rows=grid.size();
        cols=grid[0].size();
        vector<vector<bool>> visited(rows,vector<bool>(cols,false));
        int maxArea=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(visited[i][j]==false){
                    int currArea=dfsRecur(grid,i,j,visited);
                    if(maxArea<currArea){
                        maxArea=currArea;
                    }
                }
            }
        }
        return maxArea;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends