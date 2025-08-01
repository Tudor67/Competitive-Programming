class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        const int N = arr.size();
        const int MAX_NUM = *max_element(arr.begin(), arr.end());
        const int MAX_BIT = log2(MAX_NUM + 1);

        unordered_set<int> orSet;
        vector<int> closestPos(MAX_BIT + 1);

        for(int i = N - 1; i >= 0; --i){
            for(int bit = 0; bit <= MAX_BIT; ++bit){
                if((arr[i] >> bit) & 1){
                    closestPos[bit] = i;
                }
            }

            int orVal = arr[i];
            int currPos = i;
            while(currPos < N){
                orSet.insert(orVal);
                int nextPos = N;
                for(int bit = 0; bit <= MAX_BIT; ++bit){
                    if(closestPos[bit] > currPos){
                        nextPos = min(nextPos, closestPos[bit]);
                    }
                }
                if(nextPos < N){
                    orVal |= arr[nextPos];
                }
                currPos = nextPos;
            }
        }

        return orSet.size();
    }
};