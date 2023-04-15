#include <iostream>
#include <queue>

using namespace std;
#define X first
#define Y second

int n,m;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int board[1002][1002];
int day[1002][1002]; // 언제 방문했는지 나타냄 //bfs 돌리며 이걸로 채움.
 

int main(void){

ios::sync_with_stdio(0);
cin.tie(0);

    cin>>m>>n;
    // m이 가로, n이 세로

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>board[i][j];
        }
    }
    
    
    // m이 가로, n이 세로
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            day[i][j]=-1;
        }
    }
    queue<pair<int, int>> Q;

    // 토마토 시작점 표시
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j]==1){
            Q.push({i,j});
            day[i][j]=0; // 시작점이니 익는데 0일 걸림
            } // 중괄호 조심!!!!!!!!!!!
        }
    }

    while(!Q.empty()){
        auto cur=Q.front(); Q.pop();
        for(int dir=0; dir<4; dir++){
            int nx=cur.X+dx[dir];
            int ny=cur.Y+dy[dir];
            //범위 초과 시,
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
        //토마토가 없거나 이미 익은 곳이면
           if(board[nx][ny] == -1 || day[nx][ny]!=-1) continue;
            day[nx][ny]=day[cur.X][cur.Y]+1;
            Q.push({nx,ny});

        }
    }

int mx=0;
    // day에서 -1이 발견되면 -1을 출력하고 return 종료
    // 아니면 max 값 찾기
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(day[i][j]==-1 && board[i][j]!=-1){
            //정말로 없어서 -1 된 경우는 제외해준다.
                cout<<-1;
                return 0;
            }
            mx=max(mx, day[i][j]);
        }
    }
    
    cout<<mx;


}