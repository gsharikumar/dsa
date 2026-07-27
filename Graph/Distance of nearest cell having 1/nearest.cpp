//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    int n;
    int m;
    int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    //Function to find distance of nearest 1 in the grid for each cell.
    bool isPosValid(int pos[2]){
        if(pos[0]<0 || pos[1]<0 || pos[0]>=n || pos[1]>=m){
            return false;
        }
        return true;
    }
/*    int nearestRecur(vector<vector<int>>grid,int pos[2],vector<vector<bool>>&visited,vector<vector<int>>&nearestGrid){
        visited[pos[0]][pos[1]]=true;
        if(grid[pos[0]][pos[1]]==1){
            return 0;
        }
        int minDist=INT_MAX;
        for(int i=0;i<4;i++){
            int newDir[2]={pos[0]+dir[i][0],pos[1]+dir[i][1]};
            if(isPosValid(newDir)){
                int ret;
                if(visited[newDir[0]][newDir[1]]==false){
                    ret=nearestRecur(grid,newDir,visited,nearestGrid);
                }else{
                    ret=nearestGrid[newDir[0]][newDir[1]];
                }
                if(ret>=0){
                    int min=abs(newDir[0]-pos[0])+abs(newDir[1]-pos[1]);
                    min=min+ret;
                    if(minDist > min) {
                        minDist=min;
                    }
                }

            }
        }
        //cout<<"("<<pos[0]<<","<<pos[1]<<")"<<"="<<minDist<<endl;
        nearestGrid[pos[0]][pos[1]]=minDist;
        return minDist;    
    }
*/    
    void nearestBFS(vector<vector<int>> grid,vector<vector<int>>&minDistGrid){
        queue<pair<pair<int,int>,int>> q;
        vector<vector<bool>>visited(n,vector<bool> (m, false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({{i,j},0});
                    visited[i][j]=true;
                }
            }
        }
        while(q.empty()==false){
            pair<pair<int,int>,int> w=q.front();
            q.pop();
            
            int pos[2];
            int level;
         
            pos[0]=w.first.first;pos[1]=w.first.second;
            level=w.second;
         
            
            minDistGrid[pos[0]][pos[1]]=level;
         
            for(int i=0;i<4;i++){
                int newDir[2]={pos[0]+dir[i][0],pos[1]+dir[i][1]};
                
                if(isPosValid(newDir) && visited[newDir[0]][newDir[1]]==false){
                    visited[newDir[0]][newDir[1]]=true;
                    q.push({{newDir[0],newDir[1]},level+1});
                }
                
            }
        }
        return;
    }
    
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    n=grid.size();
	    m=grid[0].size();
	    vector<vector<int>>minDistGrid(n,vector<int> (m, 0));
        
        //BFS method
        nearestBFS(grid,minDistGrid);
        
        return minDistGrid;
        
/*        
//DFS method did not work
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==false){
                    int pos[2]={i,j};
	                nearestRecur(grid,pos,visited,minDistGrid);
                }
            }
        }
	    return minDistGrid;
*/
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends