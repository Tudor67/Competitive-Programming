#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<set<pair<int, int>>> s1(1);
    vector<set<pair<int, int>>> s2(1);
    for(int i = 1; i <= N; ++i){
        int a;
        cin >> a;
        s1[0].insert({i, a});
        s2[0].insert({a, i});
    }

    int Q;
    cin >> Q;

    s1.resize(1 + Q);
    s2.resize(1 + Q);

    for(int i = 1; i <= Q; ++i){
        int t, s, x;
        cin >> t >> s >> x;

        if(t == 1){
            int sSize = s1[s].size();
            if(x <= sSize / 2){
                for(int j = 1; j <= x; ++j){
                    pair<int, int> p = *s1[s].begin();
                    s1[s].erase(p);
                    s2[s].erase({p.second, p.first});
                    s1[i].insert(p);
                    s2[i].insert({p.second, p.first});
                }
                swap(s1[s], s1[i]);
                swap(s2[s], s2[i]);
            }else{
                for(int j = 1; j <= sSize - x; ++j){
                    pair<int, int> p = *s1[s].rbegin();
                    s1[s].erase(p);
                    s2[s].erase({p.second, p.first});
                    s1[i].insert(p);
                    s2[i].insert({p.second, p.first});
                }
            }
        }else{
            set<pair<int, int>> leftSet;
            set<pair<int, int>> rightSet;

            while(!s2[s].empty()){
                pair<int, int> p = *s2[s].begin();
                
                if(p.first <= x){
                    leftSet.insert(p);
                    s2[s].erase(p);
                }else{
                    break;
                }

                if(s2[s].empty()){
                    break;
                }

                p = *s2[s].rbegin();
                if(x < p.first){
                    rightSet.insert(p);
                    s2[s].erase(p);
                }else{
                    break;
                }
            }

            if(!s2[s].empty() && s2[s].begin()->first <= x){
                for(const pair<int, int>& P: leftSet){
                    s2[s].insert(P);
                }
                for(const pair<int, int>& P: rightSet){
                    s1[s].erase({P.second, P.first});
                    s2[i].insert(P);
                    s1[i].insert({P.second, P.first});
                }
            }else{
                for(const pair<int, int>& P: rightSet){
                    s2[s].insert(P);
                }
                for(const pair<int, int>& P: leftSet){
                    s1[s].erase({P.second, P.first});
                    s2[i].insert(P);
                    s1[i].insert({P.second, P.first});
                }
                swap(s1[s], s1[i]);
                swap(s2[s], s2[i]);
            }
        }

        cout << s1[i].size() << "\n";
    }

    return 0;
}