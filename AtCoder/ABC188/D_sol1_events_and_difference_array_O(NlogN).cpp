#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, subscriptionC;
    cin >> n >> subscriptionC;

    int a, b, c;
    multiset<pair<int, int>> events;
    for(int i = 0; i < n; ++i){
        cin >> a >> b >> c;
        events.insert({a, c});
        events.insert({b + 1, -c});
    }

    long long answer = 0;
    long long sum = 0;
    int prevDay = events.begin()->first;
    for(const pair<int, int>& EVENT: events){
        int curDay = EVENT.first;
        int c = EVENT.second;
        int days = curDay - prevDay;
        answer += min(sum, subscriptionC) * days;
        sum += c;
        prevDay = curDay;
    }
    
    cout << answer;

    return 0;
}