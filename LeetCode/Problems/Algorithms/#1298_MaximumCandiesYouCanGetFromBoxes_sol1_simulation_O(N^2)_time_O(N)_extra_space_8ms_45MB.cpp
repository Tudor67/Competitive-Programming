class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        const int N = status.size();

        vector<int> parent(N);
        iota(parent.begin(), parent.end(), 0);

        for(int i = 0; i < N; ++i){
            for(int j: containedBoxes[i]){
                parent[j] = i;
            }
        }

        vector<int> canOpen = status;
        vector<bool> hasBox(N, false);
        for(int i: initialBoxes){
            if(canOpen[i]){
                for(int key: keys[i]){
                    canOpen[key] = 1;
                }
            }
            hasBox[i] = true;
        }

        bool updated = true;
        while(updated){
            updated = false;

            for(int j = 0; j < N; ++j){
                if(hasBox[j]){
                    continue;
                }
                if(canOpen[parent[j]] && hasBox[parent[j]]){
                    if(canOpen[j]){
                        for(int key: keys[j]){
                            canOpen[key] = 1;
                        }
                    }
                    hasBox[j] = true;
                    updated = true;
                }
            }
        }

        int totalTakenCandies = 0;
        for(int i = 0; i < N; ++i){
            if(hasBox[i] && canOpen[i]){
                totalTakenCandies += candies[i];
            }
        }

        return totalTakenCandies;
    }
};