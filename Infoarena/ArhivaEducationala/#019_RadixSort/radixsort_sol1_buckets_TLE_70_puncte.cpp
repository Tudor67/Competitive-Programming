#include <bits/stdc++.h>
using namespace std;

void radixSort(vector<int>& v){
    const int N = v.size();
    const int INT_BITS = 31;
    const int BUCKET_BITS = 8;
    const int BUCKET_SIZE = (1 << BUCKET_BITS);

    vector<queue<int>> buckets(BUCKET_SIZE);
    for(int shiftBits = 0; shiftBits < INT_BITS; shiftBits += BUCKET_BITS){
        for(int i = 0; i < N; ++i){
            int bucketIdx = (v[i] >> shiftBits) & (BUCKET_SIZE - 1);
            buckets[bucketIdx].push(v[i]);
        }
        int i = -1;
        for(int bucketIdx = 0; bucketIdx < BUCKET_SIZE; ++bucketIdx){
            while(!buckets[bucketIdx].empty()){
                v[++i] = buckets[bucketIdx].front();
                buckets[bucketIdx].pop();
            }
        }
    }
}

int main(){
    ifstream cin("radixsort.in");
    ofstream cout("radixsort.out");

    int N;
    cin >> N;

    int A, B, C;
    cin >> A >> B >> C;

    vector<int> v(N);
    v[0] = B;
    for(int i = 1; i < N; ++i){
        v[i] = (A * 1LL * v[i - 1] + B) % C;
    }

    radixSort(v);

    for(int i = 0; i < N; i += 10){
        cout << v[i] << " ";
    }

    cin.close();
    cout.close();
    return 0;
}