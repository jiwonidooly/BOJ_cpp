#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

#define fio ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;

int n,m,s,a,b,idx=1;
vector<int> adj[100005]; // ��������Ʈ
int answer[100005];
bool visited[100005];

void dfs1(int cur){ // cur�� ���� ����
    //cout<<"���� cur��"<<cur<<"�Դϴ�.\n";
    //cout<<"���� idx�� "<<idx<<"�Դϴ�.\n";
    visited[cur]=true; // # ���� ���� R �湮ǥ��
    answer[cur]=idx++; // ���� ��ȣ ������������ �湮
   // cout<<"idx�� "<<idx<<"�� ��ȭ�ϰ� �� ������ ��� ���� ����\n\n";
    for(int x:adj[cur]) // ���� R�� ���� ���� ����
    if(!visited[x]) dfs1(x);
}

int main() {
    fio;
    cin>>n>>m>>s; // s�� ���� ����

// ������ ���� �̾��� node���� �ִ´�. ����ġ�� 1�� ��� ����.
    for(int i=0; i<m; i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=1; i<=n; i++){ // ����
    sort(adj[i].begin(), adj[i].end());} // vector

    //{������, {2,4}, {1,3,4}, {2,4}, {2,3}, ������}

    dfs1(s);
    for (int i = 1; i <= n; ++i) { // i++�ص� ��� ����.
        cout << answer[i] << '\n';
    }
    return 0;
}