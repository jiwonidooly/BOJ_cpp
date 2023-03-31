#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

#define fio ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;

int n,m,s,a,b,idx=1;
vector<int> adj[100005]; // 인접리스트
int answer[100005];
bool visited[100005];

void dfs1(int cur){ // cur이 시작 정점
    //cout<<"지금 cur은"<<cur<<"입니다.\n";
    //cout<<"지금 idx는 "<<idx<<"입니다.\n";
    visited[cur]=true; // # 시작 정점 R 방문표시
    answer[cur]=idx++; // 정점 번호 오름차순으로 방문
   // cout<<"idx가 "<<idx<<"로 변화하고 좀 있으면 재귀 돌기 시작\n\n";
    for(int x:adj[cur]) // 정점 R의 인접 정점 집합
    if(!visited[x]) dfs1(x);
}

int main() {
    fio;
    cin>>n>>m>>s; // s는 시작 정점

// 다음은 서로 이어진 node들을 넣는다. 가중치는 1로 모두 같다.
    for(int i=0; i<m; i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=1; i<=n; i++){ // 정렬
    sort(adj[i].begin(), adj[i].end());} // vector

    //{공집합, {2,4}, {1,3,4}, {2,4}, {2,3}, 공집합}

    dfs1(s);
    for (int i = 1; i <= n; ++i) { // i++해도 상관 없다.
        cout << answer[i] << '\n';
    }
    return 0;
}