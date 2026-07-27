//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
	struct cell{
		int x;
		int y;
		int steps;
	};

    private:
    int n;
    int tx;
    int ty;
    int offset[8][2] = {{1,2},{2,1},{-1,-2},{-2,-1},{-1,2},{-2,1},{1,-2},{2,-1}};

    bool isValid(int x,int y,vector<vector<bool>> &visited ){
        if(x<0 || x>n-1 || y<0 || y>n-1){
            return false;
        }
        if(visited[x][y]==true){
            return false;
        }
        return true;
    }    
    public:

	int minStepToReachTarget(vector<int>& KnightPos, vector<int>& TargetPos, int N)
	{
		// Code here
		int x;
		int y;
        int steps;
        int size;
		vector<vector<bool>> visited(N, vector<bool>(N, false));

		n = N;
		tx = TargetPos[0]-1;
		ty = TargetPos[1]-1;

		queue<cell> q;
		q.push({ KnightPos[0]-1,KnightPos[1]-1,0 });
		while (q.empty() == false ) {
			size = q.size();
			x =  q.front().x; y = q.front().y; steps=q.front().steps;
			if (x == tx && y == ty) {
				return steps;
			}
			
			q.pop();

			for (int i = 0; i < 8; i++) {
				int nx = x + offset[i][0];
				int ny = y + offset[i][1];
				if (isValid(nx, ny, visited) == true) {
					q.push({ nx,ny,steps+1 });
					visited[nx][ny] = true;
				}
			}
		}
		return -1;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends