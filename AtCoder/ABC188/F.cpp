#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll x, y;
    cin >> x >> y;

    unordered_map<ll, ll> steps;
    queue<ll> q;
    q.push(y);
    steps[y] = 0;
    ll answer = abs(x - y);
    while(!q.empty() && steps[q.front()] < answer){
        ll curY = q.front();
        q.pop();
        answer = min(steps[curY] + abs(curY - x), answer);
        if(x < curY){
            vector<ll> nextYV = (curY % 2 == 0 ? vector<ll>{curY / 2} : vector<ll>{curY - 1, curY + 1});
            for(ll nextY: nextYV){
                if(!steps.count(nextY)){
                    q.push(nextY);
                    steps[nextY] = 1 + steps[curY];
                }
            }
        }
    }

    cout << answer;

    return 0;
}