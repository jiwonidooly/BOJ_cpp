#include <iostream>
#include <stack>
#include <queue>

// 이게 왜 큐를 사용하는 문제인가?
// pop front로 앞 뒤만 이용해주면 되는데
// 자료구조 순서 == 큐큐
using namespace std;
int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin>>n>>k;

    queue<int> Q; // 큐 선언 방법 -- 기존 수열
    queue<int> Q2; // 요세푸스 순열

    for(int i=1; i<=n; i++){
        // 수열 세팅해주기
        Q.push(i);
    }

    //(7, 3)
   

    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            if(j<k-1){
            int x=Q.front();
            Q.pop();
            Q.push(x);
            }
            if(j==k-1){
                int y=Q.front();
                Q.pop(); // 큐Q에다가는 다시 넣지 않는다.
                Q2.push(y);
            }
        }
    }

    cout<<"<";
    for(int i=0; i<n; i++){
        int z=Q2.front();
        Q2.pop();
        cout<<z;
        if(i!=n-1)
        cout<<", ";
    }
    cout<<">";


}