#include <iostream>

using namespace std;

bool isPrime(int num){
if(num<2) return false;
for(int i=2; i*i<=num; i++){
    if(num%i==0) return false;
}
return true;
}
int main(void){
ios::sync_with_stdio(0);
cin.tie(0);

int m, n;
cin>>m>>n;

for(int i=m; i<n+1; i++){

if(isPrime(i))
cout<<i<<'\n';


}



}