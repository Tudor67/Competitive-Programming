#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int startPerson = -1;
    vector<int> nextPerson(N + 1);
    for(int i = 1; i <= N; ++i){
        int p;
        cin >> p;
        if(p == -1){
            startPerson = i;
        }else{
            nextPerson[p] = i;
        }
    }

    int x = startPerson;
    for(int i = 1; i <= N; ++i){
        cout << x << " ";
        x = nextPerson[x];
    }

    return 0;
}