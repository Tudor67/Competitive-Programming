#include <bits/stdc++.h>
using namespace std;

void countSort(vector<pair<long long, int>>& v, vector<pair<long long, int>>& temp, vector<int>& count, const int& SHIFT_BITS){
    const int N = v.size();
    const int BUCKET_SIZE = count.size();

    fill(count.begin(), count.end(), 0);

    for(int i = 0; i < N; ++i){
        int bucketIdx = (v[i].first >> SHIFT_BITS) & (BUCKET_SIZE - 1);
        count[bucketIdx] += 1;
    }

    for(int bucketIdx = 1; bucketIdx < BUCKET_SIZE; ++bucketIdx){
        count[bucketIdx] += count[bucketIdx - 1];
    }

    for(int i = N - 1; i >= 0; --i){
        int bucketIdx = (v[i].first >> SHIFT_BITS) & (BUCKET_SIZE - 1);
        temp[--count[bucketIdx]] = v[i];
    }
}

void radixSort(vector<pair<long long, int>>& v){
    // radix sort on v[i].first only
    const int N = v.size();
    const int INT_BITS = 40;
    const int BUCKET_BITS = 8;
    const int BUCKET_SIZE = (1 << BUCKET_BITS);

    // static variables
    static vector<pair<long long, int>> temp;
    static vector<int> count;
    temp.resize(N);
    count.resize(BUCKET_SIZE);

    int step = 0;
    while(step * BUCKET_BITS < INT_BITS){
        if(step % 2 == 0){
            countSort(v, temp, count, step * BUCKET_BITS);
        }else{
            countSort(temp, v, count, step * BUCKET_BITS);
        }
        step += 1;
    }

    if((step - 1) % 2 == 0){
        copy(temp.begin(), temp.end(), v.begin());
    }
}

void suffixArray(const string& S, vector<int>& suff){
    const int N = S.length();
    const int LOG_N = 1 + floor(log2(N));

    vector<vector<int>> c(2, vector<int>(N));

    for(int i = 0; i < N; ++i){
        c[0][i] = S[i] - 'a';
    }

    vector<pair<long long, int>> v(N);
    for(int k = 1; k <= LOG_N; ++k){
        int len = (1 << k);
        int prevKParity = (k - 1) % 2;
        int currentKParity = k % 2;
        for(int i = 0; i < N; ++i){
            int l = c[prevKParity][i];
            int r = (i + len / 2 < N ? c[prevKParity][i + len / 2] : -1);
            v[i].first = ((l + 1LL) << 20) | (r + 1LL);
            v[i].second = i;
        }

        radixSort(v);

        int classID = 0;
        c[currentKParity][v[0].second] = 0;
        for(int i = 1; i < N; ++i){
            if(v[i - 1].first != v[i].first){
                ++classID;
            }
            c[currentKParity][v[i].second] = classID;
        }
    }

    suff.resize(N);
    const int LOG_N_PARITY = LOG_N % 2;
    for(int i = 0; i < N; ++i){
        suff[c[LOG_N_PARITY][i]] = i;
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