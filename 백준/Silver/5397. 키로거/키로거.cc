#include <iostream>
#include <string>
#include <list>

using namespace std;

int main(void) {
    int case_num;
    cin>>case_num;
    string str;

    for(int i=0 ; i<case_num ; i++){
        cin>>str;
        list<char> L;
        auto cursor = L.begin();

        for(auto c:str){
            if(c=='-'){
                if (cursor != L.begin()){
                    cursor--;
                    cursor=L.erase(cursor);
                }
            }
            else if(c=='<'){
                if(cursor != L.begin()) cursor--;
            }
            else if(c=='>'){
                if(cursor != L.end()) cursor++;
            }
            else
                L.insert(cursor, c);  
        }
        for (auto c : L) cout <<c;
        cout << '\n';
    }
}