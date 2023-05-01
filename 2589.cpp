#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    char ** board = new char*[n + 1];
    int ** dist = new int*[n + 1];
    int ** visit = new int*[n + 1];
    for(int i = 1; i <=n; i++)
    {
    char * line = new char[m + 1];
    int * line2= new int[m + 1];
    int * line3 = new int[m + 1];
    for(int j = 1; j <=m; j++){
        cin >> line[j];
        line2[j] = 0;
        line3[j] = 10000;
    }
    board[i] = line;
    dist[i] = line3;
    visit[i] = line2;
    }

    int max = 0;
    for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
        if(board[i][j] == 'L') {
            queue<pair<int,int>> q;
            q.push(make_pair(i,j));
            dist[i][j] = 0;
            visit[i][j] = 1;
            while(!q.empty()) {
                pair<int,int> front = q.front();
                visit[front.first][front.second] = 1;
                if(front.first >= 2 && 
                dist[front.first][front.second] + 1 < dist[front.first-1][front.second] 
                && board[front.first-1][front.second] == 'L') {
                    dist[front.first-1][front.second] = dist[front.first][front.second] + 1;
                    if(max < dist[front.first-1][front.second]) {
                        max = dist[front.first-1][front.second];
                    }
                    q.push(make_pair(front.first-1,front.second));
                }
                if(front.first <= n - 1 && 
                dist[front.first][front.second] + 1 < dist[front.first+1][front.second] 
                && board[front.first+1][front.second]  == 'L') {
                    dist[front.first+1][front.second] = dist[front.first][front.second] + 1;
                    if(max < dist[front.first+1][front.second]) {
                        max = dist[front.first+1][front.second];
                    }
                    q.push(make_pair(front.first+1,front.second));
                }
                if(front.second >= 2 && 
                dist[front.first][front.second] + 1 < dist[front.first][front.second-1] 
                && board[front.first][front.second-1] == 'L') {
                    dist[front.first][front.second-1] = dist[front.first][front.second] + 1;
                    if(max < dist[front.first][front.second-1]) {
                        max = dist[front.first][front.second-1];
                    }
                    q.push(make_pair(front.first,front.second-1));
                }
                if(front.second <= m-1 && 
                dist[front.first][front.second] + 1 < dist[front.first][front.second+1] 
                && board[front.first][front.second+1] == 'L') {
                    dist[front.first][front.second+1] = dist[front.first][front.second] + 1;
                    if(max < dist[front.first][front.second+1]) {
                        max = dist[front.first][front.second+1];
                    }
                    q.push(make_pair(front.first,front.second+1));
                }
                q.pop();
                
            }
     for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
        dist[i][j] = 10000;
    }}
        }
    }
    }
    cout << max << endl;
}