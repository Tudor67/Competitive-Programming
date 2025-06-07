class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        const int N = status.size();

        queue<int> q;
        vector<bool> isWaitingBox(N, false);
        vector<int> canOpen = status;
        for(int i: initialBoxes){
            if(canOpen[i]){
                q.push(i);
            }else{
                isWaitingBox[i] = true;
            }
        }

        int totalTakenCandies = 0;
        while(!q.empty()){
            int i = q.front();
            q.pop();

            totalTakenCandies += candies[i];

            for(int key: keys[i]){
                canOpen[key] = true;
                if(isWaitingBox[key]){
                    isWaitingBox[key] = false;
                    q.push(key);
                }
            }

            for(int j: containedBoxes[i]){
                if(canOpen[j]){
                    q.push(j);
                }else{
                    isWaitingBox[j] = true;
                }
            }
        }

        return totalTakenCandies;
    }
};