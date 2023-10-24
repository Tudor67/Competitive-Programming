#include <bits/stdc++.h>
using namespace std;

int hammingDistance(const string& A, const string& B){
    const int N = A.length();
    int dist = 0;
    for(int i = 0; i < N; ++i){
        if(A[i] != B[i]){
            dist += 1;
        }
    }
    return dist;
}

int computeSubsequenceLen(const string& A, const string& B){
    const int A_LEN = A.length();
    const int B_LEN = B.length();
    int i = 0;
    int j = 0;
    while(i < A_LEN && j < B_LEN){
        if(A[i] == B[j]){
            i += 1;
        }
        j += 1;
    }
    return i;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string T;
    cin >> N >> T;

    vector<int> res;
    for(int i = 1; i <= N; ++i){
        string S;
        cin >> S;

        int subseqLenST = computeSubsequenceLen(S, T);
        int subseqLenTS = computeSubsequenceLen(T, S);

        if((S.length() == T.length() && hammingDistance(S, T) <= 1) ||
           (subseqLenST == (int)S.length() && S.length() + 1 == T.length()) ||
           (subseqLenTS == (int)T.length() && T.length() + 1 == S.length())){
            res.push_back(i);
        }
    }

    cout << res.size() << "\n";
    for(int i: res){
        cout << i << " ";
    }

    return 0;
}