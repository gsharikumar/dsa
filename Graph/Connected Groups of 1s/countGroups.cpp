//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find the number of 'X' total shapes.
    int rows;
    int cols;
    int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    bool isPosValid(int pos[2]){
        if(pos[0]<0 || pos[1]<0 || pos[0]>=rows || pos[1]>=cols){
            return false;
        }
        return true;
    }
    void dfsRecur(vector<vector<char>>&grid,int pos[2],vector<vector<bool>>&visited){
        if(!isPosValid(pos)){
            return;
        }
        if(grid[pos[0]][pos[1]]!='X'){
            return;
        }
        grid[pos[0]][pos[1]]='O';
        //visited[pos[0]][pos[1]]=true;
        for(int i=0;i<4;i++){
            int nPos[2]={pos[0]+dir[i][0],pos[1]+dir[i][1]};
            dfsRecur(grid,nPos,visited);
        }
        return;
    }
    
    int xShape(vector<vector<char>>& grid) 
    {
        // Code here
        int cnt=0;
        rows=grid.size();
        cols=grid[0].size();
        vector<vector<bool>> visited(rows,vector<bool>(cols,false));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(visited[i][j]==false && grid[i][j]=='X'){
                    int pos[2]={i,j};
                    dfsRecur(grid,pos,visited);  
                    cnt++;  
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}
// } Driver Code Ends