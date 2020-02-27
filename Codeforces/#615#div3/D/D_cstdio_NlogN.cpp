#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <string>
using namespace std;

char* get_new_c_string(const char* a, const char* b){
    char* c_s = (char*)malloc((strlen(a) + strlen(b) + 1) * sizeof(char));
    strcpy(c_s, a);
    strcat(c_s, b);
    return c_s;
}
 
const int MAX_N = 4e5 + 1;

int modulo_freq[MAX_N];
set <pair<int, int>> vals;
int q, x, y;
 
int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
        freopen(get_new_c_string(argv[1], ".in"), "r", stdin);
        freopen(get_new_c_string(argv[1], ".out"), "w", stdout);
    #endif

    // First solution: O(QlogQ)
    scanf("%d %d\n", &q, &x);

    for(int i = 0; i < x; ++i){
        vals.insert(make_pair(0, i));
    }

    for(; q > 0; --q){
        scanf("%d\n", &y); 
        y %= x;

        vals.erase(make_pair(modulo_freq[y], y));
        vals.insert(make_pair(++modulo_freq[y], y));
 
        printf("%d\n", vals.begin()->first * x + vals.begin()->second);
    }
 
    return 0;
}