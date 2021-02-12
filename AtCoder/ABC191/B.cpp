#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, X;
    cin >> N >> X;

    int elem;
    for(int i = 1; i <= N; ++i){
        cin >> elem;
        if(elem != X){
            cout << elem << " ";
        }
    }

    return 0;
}