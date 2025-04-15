#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin>>a>>b;
    for (int i = 1; i <= 1000; i++)
    {
        for (int j = 1; j<=i; j++)
        {
            v.push_back(i);
        }
        
    }
    int sum=0;
    for (int i = a; i <= b; i++)
    {
        // cout<<v[i-1]<<"/";
        sum+=v[i-1];
    }
    cout<<sum;
    
}