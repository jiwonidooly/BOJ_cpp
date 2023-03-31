#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
#define X first
#define Y second
int board[502][502];
bool vis[502][502];

int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      cin >> board[i][j];
    
	int num = 0; // 그림의 수
	int mx = 0; // 그림의 최댓값
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i][j] || board[i][j] == 0) continue;
				
				num++; // 그림 수 늘어나고
				queue<pair<int, int>> Q; // pair<int,int>를 자료형으로 갖는 큐 선언
				vis[i][j] = 1; // 시작점 표시
                Q.push({ i,j });
                int area = 0; // 넓이는 0부터 시작하고
				while (!Q.empty()) {
                    area++;
					pair<int, int> cur = Q.front(); Q.pop();
					 // pop하는 것만큼 - push로 하면 저 위에서 push한게 있어서 문제가 생김
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (vis[nx][ny] || board[nx][ny] != 1) continue;
						vis[nx][ny] = 1;
						Q.push({nx, ny});
	
					}
				}
				mx = max(area, mx);
		}
	}
		
	cout<<num<<'\n'<<mx;
	
}