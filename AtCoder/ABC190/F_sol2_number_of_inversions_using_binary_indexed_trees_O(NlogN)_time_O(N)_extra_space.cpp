#include <bits/stdc++.h>
using namespace std;

class BinaryIndexedTree{
private:
    const int N;
    vector<int> a;

public:
    BinaryIndexedTree(const int& N): N(N){
        a.resize(N + 1, 0);
    }

    void add(const int& POS, const int& VAL){
        for(int i = POS; i <= N; i += i - (i & (i - 1))){
            a[i] += VAL;
        }
    }

    int query(const int& POS){
        int sum = 0;
        for(int i = POS; i >= 1; i &= (i - 1)){
            sum += a[i];
        }
        return sum;
    }

    int query(const int& L, const int& R){
        if(L > R){
            return 0;
        }
        return query(R) - query(L - 1);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> a(N + 1);
    for(int i = 1; i <= N; ++i){
        cin >> a[i];
        a[i] += 1;
    }

    long long inversions = 0;
    BinaryIndexedTree tree(N);
    for(int i = 1; i <= N; ++i){
        inversions += tree.query(a[i] + 1, N);
        tree.add(a[i], 1);
    }

    cout << inversions << "\n";
    for(int i = 1; i <= N - 1; ++i){
        inversions -= (a[i] - 1);
        inversions += (N - a[i]);
        cout << inversions << "\n";
    }

    return 0;
}