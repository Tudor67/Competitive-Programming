#include <bits/stdc++.h>
using namespace std;

void countSort(vector<int>& v, vector<int>& temp, vector<int>& count, const int& SHIFT_BITS){
    const int N = v.size();
    const int BUCKET_SIZE = count.size();

    fill(count.begin(), count.end(), 0);

    for(int i = 0; i < N; ++i){
        int bucketIdx = (v[i] >> SHIFT_BITS) & (BUCKET_SIZE - 1);
        count[bucketIdx] += 1;
    }

    for(int bucketIdx = 1; bucketIdx < BUCKET_SIZE; ++bucketIdx){
        count[bucketIdx] += count[bucketIdx - 1];
    }

    for(int i = N - 1; i >= 0; --i){
        int bucketIdx = (v[i] >> SHIFT_BITS) & (BUCKET_SIZE - 1);
        temp[--count[bucketIdx]] = v[i];
    }
}

void radixSort(vector<int>& v){
    const int N = v.size();
    const int INT_BITS = 31;
    const int BUCKET_BITS = 8;
    const int BUCKET_SIZE = (1 << BUCKET_BITS);

    vector<int> count(BUCKET_SIZE);
    vector<int> temp(N);

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
        swap(v, temp);
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