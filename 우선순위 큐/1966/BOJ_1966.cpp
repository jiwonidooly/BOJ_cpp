#include <iostream>
#include <queue>

using namespace std;
int main(void){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin>>T;

    for(int i=0; i<T; i++){
    int n;
    int m;
    cin>>n>>m;

    // 인덱스가 m인 문서가 몇 번째로 인쇄되었는지 카운트하는 변수
    int cnt=0;

    queue<pair<int, int>> q;
    priority_queue<int> prq;

    int x;// 각 문서의 중요도
    for(int j=0; j<n; j++){
        
        cin>>x;

        // 각 문서의 인덱스와 중요도 x를 묶어서 일반 큐에 넣기
        q.push({j, x});

        // 우선순위 큐는 중요도가 높은 순으로 push
        prq.push(x);
        
    }

    while(!q.empty()){
        // 큐의 front 꺼내기
        int idx=q.front().first;
        int val=q.front().second;
        q.pop();

        // 우선순위 큐의 top과 중요도가 일치 시,
        if(prq.top()==val){
            prq.pop();
            cnt++;

            // 현재 문서의 인덱스가 m인 경우
            if(idx==m){
                cout<<cnt<<'\n';
                break;
            }
        }
        // 중요도가 일치 하지 않으면 큐의 rear에 다시 push
        else
        q.push({idx, val});
    }
    }
    return 0;
}