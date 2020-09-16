#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> a(N);
    vector<int> aCount(N + 1, 0);
    for(int i = 0; i < N; ++i){
        cin >> a[i];
        aCount[a[i]] += 1;
    }

    vector<int> b(N);
    vector<int> bCount(N + 1, 0);
    for(int i = 0; i < N; ++i){
        cin >> b[i];
        bCount[b[i]] += 1;
    }

    bool isPossible = true;
    for(int elem = 1; elem <= N; ++elem){
        if(aCount[elem] + bCount[elem] > N){
            isPossible = false;
        }
    }

    if(isPossible){
        set<pair<int, int>> countVal;
        for(int elem = 1; elem <= N; ++elem){
            if(bCount[elem] > 0){
                countVal.insert({aCount[elem] + bCount[elem], elem});
            }
        }

        for(int i = 0; i < N; ++i){
            if(bCount[a[i]] > 0){
                countVal.erase({aCount[a[i]] + bCount[a[i]], a[i]});
                aCount[a[i]] -= 1;
                countVal.insert({aCount[a[i]] + bCount[a[i]], a[i]});
            }

            set<pair<int, int>>::iterator it = prev(countVal.end());
            if(a[i] == it->second){
                it = prev(prev(countVal.end()));
            }
            
            b[i] = it->second;
            countVal.erase(it);

            bCount[b[i]] -= 1;
            if(bCount[b[i]] > 0){
                countVal.insert({aCount[b[i]] + bCount[b[i]], b[i]});
            }
        }

        cout << "Yes\n";
        for(int i = 0; i < N; ++i){
            cout << b[i] << " ";
        }
    }else{
        cout << "No";
    }

    return 0;
}