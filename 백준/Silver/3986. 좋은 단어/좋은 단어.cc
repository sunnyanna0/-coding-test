#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    int sum=0;
    while(n--){
        bool check=true;
        string s;
        cin>>s;
        vector<char> v;
        for(int i=0 ; i<s.size() ; i++){
            if(v.size()>0){
                if(v.back()==s[i]){
                    v.pop_back();
                }
                else{
                    v.push_back(s[i]);
                }
            }
            else{
                v.push_back(s[i]);
            }
        }
        if(v.size()==0){
            sum++;
        }

        // for(int i=0 ; i<s.size() ; i++){
        //     if(v[i]==v[i+1]){
        //         if(v[i+1]==v[i+2]){
        //             check=false;
        //         }
        //         else{
        //             continue;
        //         }
        //     }
        //     else{
        //         check=false;
        //     }
        // }
        // if(check){
        //     sum++;
        // }
    }

    cout<<sum;
    
    return 0;
}
