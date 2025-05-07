#include <iostream>
using namespace std;

int main(){
    int a, b, c, d, e, f;
    cin>>a>>b>>c>>d>>e>>f;

    int x = (c * e - b * f) / (a * e - b * d);
    int y = (a * f - c * d) / (a * e - b * d);

    cout<<x<<" "<<y;
}

//오직 하나의 해만 가짐.
// 2x + 2y = 0
// 3x + 3y = 0
// 이 두 식을 보면, 겉보기에 두 방정식이 다른 것처럼 보이지만, 사실은 같은 직선이기 때문에 입력으로 주어지지 않음
// 따라서 분모가 0이 되는 수는 주어지지 않음