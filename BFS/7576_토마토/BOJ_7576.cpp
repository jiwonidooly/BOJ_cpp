// 모든 시작점을 큐에 넣고 BFS를 돌려
// 정수 1은 익은 토마토, 정수 0 은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸을 나타낸다.
#include <iostream>
#include <queue>

using namespace std;
#define X first
#define Y second

int board[1002][1002];
int dist[1002][1002]; // 거리의 배열 dist
int n,m;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>m>>n;
    queue<pair<int, int> > Q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>board[i][j];
            if(board[i][j]==1) // 익은 토마토=>시작점
            Q.push({i,j}); // 시작점이 여러 개면 시작점을 다 넣어준다.
            if(board[i][j]==0) // 토마토가 있는데 익지 않은 곳은 board[i][j]=0으로 해준다.
            dist[i][j]=-1; // 익지 않은 곳은 dist[i][j]=-1로 해준다.
        }
    }

    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int dir=0; dir<4; dir++){
            int nx=cur.X+dx[dir];
            int ny=cur.Y+dy[dir];
            if(nx<0 || nx>=n || ny<0 || ny>=m )continue; // 범위 초과
            if(dist[nx][ny]>=0) continue; // 이 부분) 이미 익은 곳은 내친다.
            dist[nx][ny]=dist[cur.X][cur.Y]+1; // 사방 탐색 후 익지 않은 것 -1에다가 +1해준다.
            Q.push({nx,ny});
        }
        }

        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(dist[i][j]==-1){ // 하나라도 -1이면 다 익지 못했다는 것이다.
                    cout<<-1;
                    return 0; // 그러면 -1을 출력해주고 종료 해준다.
                }
                ans=max(ans, dist[i][j]);
            }
        }
        cout<<ans;
    }
    // 바킹독님께 dist[nx][ny]>=0 이면 continue 하는 이유 물어보고
    // 이미 익은 곳은 탐색 및 push 불필요여서>>
    // 디버깅 통해서 