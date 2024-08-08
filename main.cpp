#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define endl "\n"
using ll = long long;
typedef vector<string> vs;
typedef vector<long long> vll;
typedef vector<char> vc;
using namespace std;

void Find_Path(vector<vector <int> >&maze, vector<vector<int> >&visited, vector<string>&op, int x, int y, int n, string path){
    // if you reach destination
    if(x == n-1 && y == n-1){
        op.push_back(path);
        return;
    }
    // down -> not break through maze, not visit same node, avoid blocked path
    if(y+1<=n-1 && visited[y+1][x] == 0 && maze[y+1][x] == 1){
        visited[y][x] = 1;
        Find_Path(maze, visited, op, x, y+1, n, path+'D');
        visited[y][x] = 0;
    }
    // left 
    if(x-1>=0 && visited[y][x-1]==0 && maze[y][x-1] == 1){
        visited[y][x] = 1;
        Find_Path(maze, visited, op, x-1, y, n, path+'L');
        visited[y][x]=0;
    }
    // right
    if(x+1<=n-1 && visited[y][x+1] == 0 && maze[y][x+1]==1){
        visited[y][x] = 1;
        Find_Path(maze, visited, op, x+1, y, n, path+'R');
        visited[y][x]=0;
    }
    // up
    if(y-1>=0 && visited[y-1][x] == 0 && maze[y-1][x]==1){
        visited[y][x]=1;
        Find_Path(maze, visited, op, x, y-1, n, path+'U');
        visited[y][x]=0;
    }
    return;
}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    vector< vector<int> >maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    vector<vector<int>> visited = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    vs op;
    Find_Path(maze, visited, op, 0, 0, 4, "");
    for(string s:op)cout<<s<<endl;
    return 0;
}
