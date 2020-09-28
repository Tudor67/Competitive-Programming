#include <algorithm>
#include <climits>
#include <cmath>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

#ifdef ONLINE_JUDGE
    #include <iostream>
#else
    #include <fstream>
#endif

long long modInverse(long long a, const long long& MODULO){
    long long res = 1;
    int n = MODULO - 2;
    a %= MODULO;
    while(n > 0){
        if(n & 1){
            res = (res * a) % MODULO;
        }
        a = (a * a) % MODULO;
        n /= 2;
    }
    return res;
}

long long nCk(const long long& N, const long long& K, const long long& MODULO, const vector<long long>& FACTORIAL){
    return ((FACTORIAL[N] % MODULO) * modInverse(FACTORIAL[N - K] * FACTORIAL[K], MODULO)) % MODULO;
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
        ifstream cin(string(argv[1]) + ".in");
        ofstream cout(string(argv[1]) + ".out");
    #endif
    
    const long long MODULO = 998244353;

    int n, k;
    cin >> n >> k;

    long long answer = 0;
    if(k == 1){
        answer = n;
    }else{
        vector<long long> factorial(n + 1);
        factorial[0] = 1;
        for(int i = 1; i <= n; ++i){
            factorial[i] = (i * factorial[i - 1]) % MODULO;
        }

        vector<pair<int, bool>> events(2 * n);
        int eventStart;
        int eventEnd;
        for(int i = 0; i < n; ++i){
            cin >> eventStart >> eventEnd;
            events[2 * i] = {eventStart, 0};
            events[2 * i + 1] = {eventEnd, 1};
        }

        sort(events.begin(), events.end());
        
        int eventCnt = 0;
        for(const pair<int, bool>& EVENT: events){
            bool isEventStart = !EVENT.second;
            if(isEventStart){
                eventCnt += 1;
            }else{
                eventCnt -= 1;
                if(eventCnt >= k - 1){
                    answer += nCk(eventCnt, k - 1, MODULO, factorial);
                    answer %= MODULO;
                }
            }
        }
    }

    cout << answer;

    return 0;
}