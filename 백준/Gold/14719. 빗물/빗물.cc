#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w;
    cin>>h>>w;
    vector<int> v;
    int sum=0;

    for (int i = 0; i < w; i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    // for (int i = 0; i < w; i++){
    //     for(int j=0 ; j<v[i] ; j++){
    //         for(int k=i ; k<w ; k++){
    //             if(j<=v[k]){
    //                 sum+=k-i-1;
    //                 break;
    //             }
    //         }
    //     }
        
    // }
    for (int i = 1; i < w - 1; i++) {
        // i번째 위치에서 왼쪽, 오른쪽 벽 중 최대 높이를 구함
        int left = *max_element(v.begin(), v.begin() + i);
        int right = *max_element(v.begin() + i + 1, v.end());

        int water = min(left, right) - v[i];
        if (water > 0)
            sum += water;
    }
    
    cout<<sum;
    
    return 0;
}
