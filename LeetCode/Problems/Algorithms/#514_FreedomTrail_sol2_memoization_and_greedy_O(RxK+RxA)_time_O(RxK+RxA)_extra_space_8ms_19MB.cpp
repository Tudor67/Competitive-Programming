class Solution {
private:
    int f(string& ring, int ringIndex, string& key, int keyIndex, vector<vector<int>>& memo,
          vector<vector<int>>& leftIndex, vector<vector<int>>& rightIndex){
        const int R = ring.length();

        if(keyIndex == (int)key.length()){
            return 0;
        }

        if(memo[ringIndex][keyIndex] != -1){
            return memo[ringIndex][keyIndex];
        }

        int minSteps = INT_MAX;
        for(int nextRingIndex: {leftIndex[key[keyIndex] - 'a'][ringIndex],
                                rightIndex[key[keyIndex] - 'a'][ringIndex]}){
            if(ring[nextRingIndex] == key[keyIndex]){
                int dist = min((ringIndex - nextRingIndex + R) % R, (R - ringIndex + nextRingIndex) % R);
                int steps = 1 + dist + f(ring, nextRingIndex, key, keyIndex + 1, memo, leftIndex, rightIndex);
                minSteps = min(minSteps, steps);
            }
        }

        memo[ringIndex][keyIndex] = minSteps;
        return minSteps;
    }

public:
    int findRotateSteps(string ring, string key) {
        const int R = ring.length();
        const int K = key.length();
        const int A = 26;

        vector<vector<int>> leftIndex(A, vector<int>(R));
        vector<vector<int>> rightIndex(A, vector<int>(R));
        for(char c = 'a'; c <= 'z'; ++c){
            int cIndex = -1;
            for(int i = 0; i < 2 * R; ++i){
                if(ring[i % R] == c){
                    cIndex = i % R;
                }
                leftIndex[c - 'a'][i % R] = cIndex;
            }

            cIndex = -1;
            for(int i = 2 * R - 1; i >= 0; --i){
                if(ring[i % R] == c){
                    cIndex = i % R;
                }
                rightIndex[c - 'a'][i % R] = cIndex;
            }
        }

        vector<vector<int>> memo(R, vector<int>(K, -1));
        return f(ring, 0, key, 0, memo, leftIndex, rightIndex);
    }
};