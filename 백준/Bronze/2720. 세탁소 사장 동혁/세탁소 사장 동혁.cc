#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        int quarter_num=0, dime_num=0, nickel_num=0, penny_num=0;

        while(x>0){
            if(x>=25){
                quarter_num++;
                x-=25;
            }
            else if(x>=10){
                dime_num++;
                x-=10;
            }
            else if(x>=5){
                nickel_num++;
                x-=5;
            }
            else if(x>=1){
                penny_num++;
                x-=1;
            }
        }
        
        cout<<quarter_num<<" "<<dime_num<<" "<<nickel_num<<" "<<penny_num<<"\n";
    }

    return 0;
}
