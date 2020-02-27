#include <algorithm>
#include <string>
using namespace std;

#ifdef ONLINE_JUDGE
    #include <iostream>
#else
    #include <fstream>
#endif

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
        ifstream cin(string(argv[1]) + ".in");
        ofstream cout(string(argv[1]) + ".out");
    #endif
    
    long long a[5], n, t, r;

    cin >> t;

    for(; t > 0; --t){
        cin >> a[1] >> a[2] >> a[3] >> n;

        sort(a + 1, a + 4);

        r = a[3] - a[2] + a[3] - a[1];

        if(r <= n && (n - r) % 3 == 0){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }

    return 0;
}