#include <iostream>

using namespace std;

int arr[10][10];
int main(void){

    int n,m;

    cin>>n>>m; // 행 렬
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
        {
            cin>>arr[i][j];
        }
    }

}