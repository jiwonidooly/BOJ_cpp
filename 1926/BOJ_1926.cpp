#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define X first
#define Y second

int board[502][502]; // 1이 파란 칸, 0이 빨간 칸에 대응
bool vis[502][502]; // 해당 칸을 방문했는지 여부를 저장
int n, m; // n=행의 수, m=열의 수
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1}; // 상하좌우 네 방향을 의미

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

cin>>n>>m; // 입출력 받기
// 배열 입출력 트릭
for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin>> board[i][j];
		}
	}

    int mx=0; // 그림 넓이 최대
    int num=0; // 그림의 개수

// 이중 포문으로 시작점이 될 수 있는지 보자.
for(int i=0; i<n;i++){
    for(int j=0; j<m; j++){
    if(board[i][j]==0 || vis[i][j]) continue; // 방문했거나 빨간칸이면 시작점이 될 수 없다.
    num++;
    queue<pair<int, int>> Q;
    vis[i][j]=1; // (i,j)을 방문했다고 명시
    Q.push({i,j}); // 큐에 시작점인 (i,j)을 삽입
    int area=0;
    while(!Q.empty()){
        pair<int, int> cur =Q.front(); Q.pop(); area++;// 프론트 확인하고 빼라
        // pop의 횟수가 그림의 크기다.
        cout<<'('<<cur.X<<", "<<cur.Y<<") -> ";
        for(int dir=0; dir<4; dir++){ // 상하좌우 칸 살펴본다.
        int nx = cur.X+dx[dir];
        int ny=cur.Y+dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
           if(nx<0 || nx>=n || ny<0 || ny>=m) continue; // 범위 밖일 경우 넘어감
           if(vis[nx][ny]||board[nx][ny]!=1) continue; // 이미 방문한 칸이거나 파란 칸이 아닐 경우
           vis[nx][ny]=1; // (nx, ny)를 방문했다고 명시
           Q.push({nx, ny});
           mx+=1;//큐 푸시할 때마다 그림 넓이 키우기

        //큐가 비워지면 그림 개수 늘리기
           if(Q.empty()){
            num+=1;
           }
        }
        mx=max(mx, area);
    }
}
cout<<num<<'\n'<<mx;
}