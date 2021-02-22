#include <bits/stdc++.h>
using namespace std;

map<pair<int, int>, int> cache;

int query(int l, int r){
    int pos = -1;
    if(l < r){
        if(cache.count({l, r})){
            pos = cache[{l, r}];
        }else{
            cout << "? " << l << " " << r << endl;
            cin >> pos;
            cache[{l, r}] = pos;
        }
    }
    return pos;
}

void solve(istream& cin, ostream& cout){
    int N;
    cin >> N;

    int secondMaxPos = query(1, N);
    bool isMaxAtLeft = (query(1, secondMaxPos) == secondMaxPos);
    int sign = (isMaxAtLeft ? -1 : 1);
    int l = 0;
    int r = (isMaxAtLeft ? secondMaxPos - 1 : N - secondMaxPos);
    while(l != r){
        int mid = (l + r) / 2;
        int nextPos = secondMaxPos + sign * mid;
        if(query(min(nextPos, secondMaxPos), max(nextPos, secondMaxPos)) == secondMaxPos){
            r = mid;
        }else{
            l = mid + 1;
        }
    }

    cout << "! " << secondMaxPos + sign * r << endl;
}

int main(int argc, char** argv){
    solve(cin, cout);
    return 0;
}