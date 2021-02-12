#include <bits/stdc++.h>
using namespace std;

int main(){
    long double X, Y, R;
    cin >> X >> Y >> R;

    X = abs(X) + abs(ceil(R));
    Y = abs(Y) + abs(ceil(R));

    long long answer = 0;
    for(long long x = ceil(X - R); x <= X + R; ++x){
        long double dx = abs(X - x);
        long double dy = sqrt(R * R - dx * dx);
        long long y1 = floor(Y + dy);
        long long y2 = ceil(Y - dy);
        answer += (y1 - y2 + 1);
    }

    cout << answer;

    return 0;
}