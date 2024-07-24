class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        const int N = healths.size();

        vector<int> currentHealths = healths;
        set<pair<int, int>> rSet; // robots with movement direction 'R'
        set<pair<int, int>> lSet; // robots with movement direction 'L'
        for(int i = 0; i < N; ++i){
            if(directions[i] == 'R'){
                rSet.insert({positions[i], i});
            }else{
                lSet.insert({positions[i], i});
            }
        }

        while(!rSet.empty() && !lSet.empty()){
            int rIndex = rSet.rbegin()->second;
            set<pair<int, int>>::iterator it = lSet.lower_bound({positions[rIndex], -1});
            if(it == lSet.end()){
                // no collision
                rSet.erase({positions[rIndex], rIndex});
            }else{
                // collision
                int lIndex = it->second;
                if(currentHealths[rIndex] < currentHealths[lIndex]){
                    currentHealths[lIndex] -= 1;
                    currentHealths[rIndex] = 0;
                    rSet.erase({positions[rIndex], rIndex});
                }else if(currentHealths[rIndex] > currentHealths[lIndex]){
                    currentHealths[rIndex] -= 1;
                    currentHealths[lIndex] = 0;
                    lSet.erase({positions[lIndex], lIndex});
                }else if(currentHealths[rIndex] == currentHealths[lIndex]){
                    currentHealths[rIndex] = 0;
                    currentHealths[lIndex] = 0;
                    rSet.erase({positions[rIndex], rIndex});
                    lSet.erase({positions[lIndex], lIndex});
                }
            }
        }

        vector<int> res;
        for(int i = 0; i < N; ++i){
            if(currentHealths[i] > 0){
                res.push_back(currentHealths[i]);
            }
        }

        return res;
    }
};