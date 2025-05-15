#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        bool answer = true;
        int k=0;
        for(int i=0 ; i<s.size() ; i++){
            if(s[i]=='('){
                k++;
            }
            else {
                if(k-1<0){
                    answer=false;
                    break;
                }
                else{
                    k--;
                }
            }
        }
        if(answer==true && k==0) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
