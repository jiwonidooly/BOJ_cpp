#include <iostream>

using namespace std;

bool isPrime(int num){

    if(num==1) return false;
    for(int i=2; i*i<=num; i++){
        if(num%i==0) return false;
    }
    return true;

}

int main(void){
ios::sync_with_stdio(0);
cin.tie(0);

int cnt=0;

int n;
cin>>n;


for(int i=0; i<n; i++){
    int num;
    cin>>num;

    if(isPrime(num))
    cnt++;
}

cout<<cnt;

}