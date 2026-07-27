//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    int rows;
    int cols;
    int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    public:
    bool isPosValid(int pos[2]){
        if(pos[0]>=0 && pos[0]<rows && pos[1]>=0 && pos[1]<cols){
            return true;
        }
        return false;
    }
    
    bool isPossibleDFS(vector<vector<int>>& grid,bool *visited,int src[2],int dst[2]){
        bool bRet=false;
        if(src[0]==dst[0] && src[1]==dst[1]){
            return true;
        }
        
        visited[src[0]*cols+src[1]]=true;
        for(int i=0;i<4;i++){
            int newSrc[2]={src[0]+dir[i][0],src[1]+dir[i][1]};
            if(true==isPosValid(newSrc)){
                if(grid[newSrc[0]][newSrc[1]]!=0){
                    if(visited[newSrc[0]*cols+newSrc[1]]==false ){
                        bRet|=isPossibleDFS(grid,visited,newSrc,dst);
                    }
                }
            }
        }
        return bRet;
    }
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        int src[2];
        int dst[2];
        
        rows=grid.size();
        cols=grid[0].size();
        
        bool visited[rows*cols];
        bzero(visited,sizeof(visited));

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                //find src and destinations points
                if(grid[i][j]==1){
                    src[0]=i;src[1]=j;
                }else if(grid[i][j]==2){
                    dst[0]=i;dst[1]=j;
                }
            }
        }
        return isPossibleDFS(grid,visited,src,dst);

    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends