#include <iostream>

using namespace std;
int factorial(int num){
    if (num<=1) return 1;

    return num*factorial(num-1);
}

int main(void){
    int n;
    int k;

    cin>>n>>k;

    if(k==0 || k==n){
    cout<<1;
    return 0;
    }

    int a=factorial(n);
    int b=factorial(k);
    int c=factorial(n-k);

    if(k!=0 && k!=n){
        cout<<a/(b*c);
        return 0;
    }


}