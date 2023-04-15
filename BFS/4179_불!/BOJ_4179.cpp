#include <iostream>
#include <queue>
using namespace std;
#define X first
#define Y second
string board[1002];
int dist1[1002][1002]; // 불의 전파 시간
int dist2[1002][1002]; // 지훈이의 이동 시간
int n, m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;

  for(int i=0; i<n; i++){
    fill(dist1[i], dist1[i]+m, -1);
    fill(dist2[i], dist2[i]+m, -1);
  }

  for(int i=0; i<n; i++)
  cin>>board[i]; // 붙여 입력 받아서

  queue<pair<int, int>> Q1;
  queue<pair<int, int>> Q2;
  
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(board[i][j]=='F'){ // 불의 시작점
        Q1.push({i,j});
        dist1[i][j]=0;
      }
      if(board[i][j]=='J'){ // 지훈이의 시작점
      Q2.push({i,j});
      dist2[i][j]=0;
      }
    }
  }

  // 불에 대한 BFS
  while(!Q1.empty()){
    auto cur=Q1.front(); Q1.pop();
    for(int dir=0; dir<4; dir++)
    {
      int nx=cur.X+dx[dir];
      int ny=cur.Y+dy[dir];
      if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
      // 이미 불이 전파된 곳 dist1[nx][ny]>=0 이거나 벽이면
      if(dist1[nx][ny]>=0 || board[nx][ny]=='#') continue;
      // 불을 전파 시켜주는 코드
      dist1[nx][ny]=dist1[cur.X][cur.Y]+1;
      Q1.push({nx, ny});
    }
  }

  // 지훈이에 대한 BFS
  while(!Q2.empty()){
    auto cur=Q2.front(); Q2.pop();
    for(int dir=0; dir<4; dir++){
      int nx=cur.X+dx[dir];
      int ny=cur.Y+dy[dir];
      // 범위 벗어났다면 틸출 성공
      if(nx<0 || nx>=n || ny<0 || ny>=m){
        cout<<dist2[cur.X][cur.Y]+1;
        return 0;
      }

      // 지훈이가 이미 지나간 자리거나 벽이면 continue
      if(dist2[nx][ny]>=0 || board[nx][ny]=='#') continue;
      // 불이 지나간 부분인 조건 dist1[nx][ny]!=-1이면서
      // dist1[nx][ny]에서의 값보다 dist2[cur.X][cur.Y]+1의 값이 더 커서
      // 지훈이가 불보다 늦게 도착할 때
      if(dist1[nx][ny]!=-1 && dist1[nx][ny] <= dist2[cur.X][cur.Y]+1) continue;
      dist2[nx][ny]=dist2[cur.X][cur.Y]+1; // 지훈이에 대한 BFS 코드
      Q2.push({nx,ny});
    }
  }
  cout<<"IMPOSSIBLE"; // 범위 밖으로 못 간 경우 임파써블 한 경우다.

}