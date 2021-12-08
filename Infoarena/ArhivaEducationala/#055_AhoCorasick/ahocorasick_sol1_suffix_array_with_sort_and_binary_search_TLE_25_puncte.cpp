#include <bits/stdc++.h>
using namespace std;

void suffixArray(const string& S, vector<int>& suff){
    const int N = S.length();
    const int LOG_N = 1 + floor(log2(N));

    vector<vector<int>> c(2, vector<int>(N));

    for(int i = 0; i < N; ++i){
        c[0][i] = S[i] - 'a';
    }

    vector<pair<pair<int, int>, int>> v(N);
    for(int k = 1; k <= LOG_N; ++k){
        int len = (1 << k);
        for(int i = 0; i < N; ++i){
            int l = c[(k - 1) % 2][i];
            int r = (i + len / 2 < N ? c[(k - 1) % 2][i + len / 2] : -1);
            v[i].first = {l, r};
            v[i].second = i;
        }

        sort(v.begin(), v.end());

        int classID = 0;
        c[k % 2][v[0].second] = 0;
        for(int i = 1; i < N; ++i){
            if(v[i - 1].first != v[i].first){
                ++classID;
            }
            c[k % 2][v[i].second] = classID;
        }
    }

    suff.resize(N);
    for(int i = 0; i < N; ++i){
        suff[c[LOG_N % 2][i]] = i;
    }
}

int lowerBound(const string& S, const string& WORD, vector<int>& suff){
    const int N = S.length();
    const int WORD_LEN = WORD.length();
    int l = 0;
    int r = N - 1;
    while(l != r){
        int mid = (l + r) / 2;
        int i = suff[mid];
        if(WORD.compare(0, WORD_LEN, S, i, WORD_LEN) <= 0){
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    return r;
}

int upperBound(const string& S, const string& WORD, vector<int>& suff){
    const int N = S.length();
    const int WORD_LEN = WORD.length();
    int l = 0;
    int r = N;
    while(l != r){
        int mid = (l + r) / 2;
        int i = suff[mid];
        if(WORD.compare(0, WORD_LEN, S, i, WORD_LEN) < 0){
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    return r;
}

int main(){
    ifstream cin("ahocorasick.in");
    ofstream cout("ahocorasick.out");

    string s;
    cin >> s;

    vector<int> suff;
    suffixArray(s, suff);
    
    int n;
    cin >> n;

    vector<string> words(n);
    for(int i = 0; i < n; ++i){
        cin >> words[i];
    }

    for(int i = 0; i < n; ++i){
        int firstPos = lowerBound(s, words[i], suff);
        int lastPos = upperBound(s, words[i], suff);
        cout << lastPos - firstPos << "\n";
    }

    cin.close();
    cout.close();
    return 0;
}