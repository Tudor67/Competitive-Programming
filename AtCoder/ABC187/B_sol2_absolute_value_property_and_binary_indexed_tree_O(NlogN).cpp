#include <bits/stdc++.h>
using namespace std;

class BinaryIndexedTree{
private:
    vector<int> a;
    int MIN_VAL;
    int MAX_VAL;
    int N;

    int shiftPos(int pos){
        return pos - MIN_VAL + 1;
    }

public:
    BinaryIndexedTree(const int& MIN_VAL, const int& MAX_VAL){
        this->MIN_VAL = MIN_VAL;
        this->MAX_VAL = MAX_VAL;
        this->N = shiftPos(MAX_VAL);
        a.resize(N + 1, 0);
    }

    void add(int pos, int val){;
        for(int i = shiftPos(pos); i <= N; i += (i & (-i))){
            a[i] += val;
        }
    }

    int query(int pos){
        int sum = 0;
        for(int i = shiftPos(pos); i >= 1; i -= (i & (-i))){
            sum += a[i];
        }
        return sum;
    }

    int query(int startPos, int endPos){
        if(shiftPos(startPos) <= 1){
            return query(endPos);
        }
        return query(endPos) - query(startPos - 1);
    }
};

bool incY(const pair<int, int>& LHS, const pair<int, int>& RHS){
    return (LHS.second < RHS.second);
}

int main(){
    int n;
    cin >> n;

    vector<pair<int, int>> xy(n);
    for(int i = 0; i < n; ++i){
        cin >> xy[i].first >> xy[i].second;
    }

    sort(xy.begin(), xy.end(), incY);

    int count = 0;
    const int MIN_VAL = -2e3;
    const int MAX_VAL = 2e3;
    BinaryIndexedTree treeSum(MIN_VAL, MAX_VAL);
    BinaryIndexedTree treeDiff(MIN_VAL, MAX_VAL);
    for(int i = 0; i < n; ++i){
        int sum = xy[i].second + xy[i].first;
        int diff = xy[i].second - xy[i].first;
        count += treeSum.query(sum, MAX_VAL);
        count += treeDiff.query(diff, MAX_VAL);
        treeSum.add(xy[i].second + xy[i].first, 1);
        treeDiff.add(xy[i].second - xy[i].first, 1);
    }

    cout << count;

    return 0;
}