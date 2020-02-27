#include <algorithm>
using namespace std;
 
#ifdef ONLINE_JUDGE
    #include <iostream>
#else
    #include <fstream>
#endif
 
const int MAX_N = 4e5 + 1;

int cnt_complete_seq, y_with_min_freq, distinct_values;
int modulo_freq[MAX_N];
int dst_gt[MAX_N]; // dst_gt[i]: counter of distinct values (frequencies) >= i at the current query (not in general)
int q, x, y;
 
int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
        ifstream cin(string(argv[1]) + ".in");
        ofstream cout(string(argv[1]) + ".out");
    #endif

    // O(Q)
    cin >> q >> x;

    for(; q > 0; --q){
        cin >> y;
        y %= x;

        ++modulo_freq[y];

        if(modulo_freq[y] - 1 == cnt_complete_seq){
            ++distinct_values;

            if(distinct_values == x){
                ++cnt_complete_seq;
                y_with_min_freq = 0;
                distinct_values = dst_gt[cnt_complete_seq + 1];
            }

            int j = y_with_min_freq;
            while(j < x && modulo_freq[j] != cnt_complete_seq) ++j;
            if(j < x) y_with_min_freq = j;
        }else{
            ++dst_gt[modulo_freq[y]];
        }

        cout << cnt_complete_seq * x + y_with_min_freq << "\n";
    }
 
    return 0;
}