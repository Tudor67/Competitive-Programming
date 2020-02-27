#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

char* get_new_c_string(const char* a, const char* b){
    char* c_s = (char*)malloc((strlen(a) + strlen(b) + 1) * sizeof(char));
    strcpy(c_s, a);
    strcat(c_s, b);
    return c_s;
}
 
const int MAX_N = 4e5 + 1;

int cnt_complete_seq, y_with_min_freq, distinct_values;
int modulo_freq[MAX_N];
int dst_gt[MAX_N]; // dst_gt[i]: counter of distinct values (frequencies) >= i at the current query (not in general)
int q, x, y;
 
int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
        freopen(get_new_c_string(argv[1], ".in"), "r", stdin);
        freopen(get_new_c_string(argv[1], ".out"), "w", stdout);
    #endif

    // O(Q)
    scanf("%d %d\n", &q, &x);

    for(; q > 0; --q){
        scanf("%d\n", &y);
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

        printf("%d\n", cnt_complete_seq * x + y_with_min_freq);
    }
 
    return 0;
}