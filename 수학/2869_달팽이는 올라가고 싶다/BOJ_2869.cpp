#include <iostream>

using namespace std;

int main(void){

ios::sync_with_stdio(0);
cin.tie(0);
    long long a,b,v;

    cin>>a>>b>>v;

    long long org=v-a;
int res=b-a;
    long long result=org/res;
    cout<<result;

}

/* 2 1 5

2 1, 3 2, 4 3, 5 4, =>[4][0]해서 4일
*/

/*
5 1 6
5 4, 9 => [2][0]해서 2일
*/