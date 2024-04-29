class Solution {
private:
    int f(string& ring, int ringIndex, string& key, int keyIndex, vector<vector<int>>& memo){
        const int R = ring.length();

        if(keyIndex == (int)key.length()){
            return 0;
        }

        if(memo[ringIndex][keyIndex] != -1){
            return memo[ringIndex][keyIndex];
        }

        int minSteps = INT_MAX;
        for(int i = 0; i < R; ++i){
            int nextRingIndex = (ringIndex + i) % R;
            if(ring[nextRingIndex] == key[keyIndex]){
                int dist = min(i, R - i);
                int steps = 1 + dist + f(ring, nextRingIndex, key, keyIndex + 1, memo);
                minSteps = min(minSteps, steps);
            }
        }

        memo[ringIndex][keyIndex] = minSteps;
        return minSteps;
    }

public:
    int findRotateSteps(string ring, string key) {
        vector<vector<int>> memo(ring.length(), vector<int>(key.length(), -1));
        return f(ring, 0, key, 0, memo);
    }
};