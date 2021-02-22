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

    int l = 1;
    int r = N;
    while(l != r){
        int mid = (l + r) / 2;
        int lrPos = query(l, r);
        int lPos = query(l, mid);
        int rPos = query(mid + 1, r);
        if(lrPos == lPos){
            r = mid;
        }else if(lrPos == rPos){
            l = mid + 1;
        }else{
            if(l <= lrPos && lrPos <= mid){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
    }

    cout << "! " << r << endl;
}

int main(int argc, char** argv){
    solve(cin, cout);
    return 0;
}