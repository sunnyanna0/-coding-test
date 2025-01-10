#include <iostream>
#include <vector>
using namespace std;

int main(void){
    int a;
    cin>>a;

    int arr[10]={};
    for(int i=0 ; i<10 ; i++){
        arr[i]=1;
    }

    int need=1;
    while(a>0){
        if(arr[a%10]<1){
            if(a%10==6){
                if(arr[9]>0){
                    arr[9]--;
                }
                else{
                    need++;
                    for(int i=0 ; i<10 ; i++){
                        arr[i]++;
                    }
                    arr[a%10]--;
                }
            }
            else if(a%10==9){
                if(arr[6]>0){
                    arr[6]--;
                }
                else{
                    need++;
                    for(int i=0 ; i<10 ; i++){
                        arr[i]++;
                    }
                    arr[a%10]--;
                }
            }
            else{
                need++;
                for(int i=0 ; i<10 ; i++){
                    arr[i]++;
                }
                arr[a%10]--;
            }
        }
        else{
            arr[a%10]--;
        }
        a=a/10;
    }
    cout<<need;
}