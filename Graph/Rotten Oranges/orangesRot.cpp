//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    int rows;
    int cols;
    int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    bool isPosValid(int nr,int nc){
        if(nr<0 || nc<0 || nr>=rows || nc>=cols){
            return false;
        }
        return true;
    }
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        queue<pair<pair<int,int>,int>> q;
        int freshOrgCnt=0;
        rows=grid.size();
        cols=grid[0].size();
        vector<vector<bool>> visited(rows,vector<bool>(cols,false));
        vector<vector<int>> minLevel(rows,vector<int>(cols,-1));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==2){
                    visited[i][j]=true;
                    q.push({{i,j},0});
                }else if(grid[i][j]==1){
                    freshOrgCnt++;
                }
            }
        }
        int maxLevelRet=-1;
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int l=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+dir[i][0];
                int nc=c+dir[i][1];
                if(isPosValid(nr,nc) && visited[nr][nc]==false){
                    if(grid[nr][nc]==1){
                        //cout<<"shold not have queued"<<endl;
                        freshOrgCnt--;
                        int currLvl=l+1;
                        int minLvl;
                        if(minLevel[nr][nc]==-1 || minLevel[nr][nc]>currLvl){
                            //initialize
                            minLevel[nr][nc]=currLvl;
                        }
                        if(maxLevelRet==-1 || maxLevelRet<minLevel[nr][nc]){
                            //initialize
                            maxLevelRet=minLevel[nr][nc];
                        }
                        q.push({{nr,nc},minLevel[nr][nc]});
                    }
                    visited[nr][nc]=true;
                }
            }
        }
        return (freshOrgCnt==0)?maxLevelRet:-1;
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends