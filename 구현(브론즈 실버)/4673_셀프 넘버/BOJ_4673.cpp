#include <iostream>

int arr[10000]={0, };
// 모두 0으로 초기화,
// 셀프 넘버에다가는 i로 저장
// 셀프 넘버 검수를 다했는데도 0이면 출력

using namespace std;

int main(void){


ios::sync_with_stdio(0);
cin.tie(0);
    for(int i=1; i<1000; i++ ){

        int sel;
        if(i<10){
        sel=i+i;    
        }
        else if(i>9 && i<100){
            sel=i+i/10+i%10;
        }
        else if(i>99 && i<1000){
            sel+=i;
            sel+=i/100;
            i-=(i/100)*100;
            sel+=i/10;
            sel+=i%10;
        }
        else if(i>999 && i<9999){
            sel+=i;
            sel+=i/1000;
            i-=(i/1000)*1000;
            sel+=i/100;
            i-=(i/100)*100;
            sel+=i/10;
            sel=i%10;

        }

        if(sel<10001)
            arr[sel]=sel;

    }

for(int i=1; i<10001; i++){
    if(arr[i]==0){
        cout<<i<<"\n";
    }
}

}