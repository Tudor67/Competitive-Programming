class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        const int N = positions.size();
        
        // Step 1: value compression for positions
        vector<int> v(2 * N);
        for(int i = 0; i < N; ++i){
            int leftPos = positions[i][0];
            int rightPos = positions[i][0] + positions[i][1] - 1;
            v[i] = leftPos;
            v[i + N] = rightPos;
        }
        
        sort(v.begin(), v.end());
        
        unordered_map<int, int> compressedValue;
        int idx = 0;
        compressedValue[v[0]] = 0;
        for(int i = 1; i < 2 * N; ++i){
            if(v[i - 1] != v[i]){
                idx += 1;
                compressedValue[v[i]] = idx;
            }
        }
        
        // Step 2: simulation using compressed values
        const int M = compressedValue.size();
        vector<int> maxHeightAt(M);
        vector<int> answer(N);
        int maxHeight = 0;
        for(int i = 0; i < N; ++i){
            int leftPos = positions[i][0];
            int rightPos = positions[i][0] + positions[i][1] - 1;
            int sideLength = positions[i][1];
            int rangeMaxHeight = maxHeightAt[compressedValue[leftPos]];
            for(int pos = compressedValue[leftPos]; pos <= compressedValue[rightPos]; ++pos){
                maxHeightAt[pos] += sideLength;
                rangeMaxHeight = max(maxHeightAt[pos], rangeMaxHeight);
            }
            for(int pos = compressedValue[leftPos]; pos <= compressedValue[rightPos]; ++pos){
                maxHeightAt[pos] = rangeMaxHeight;
            }
            maxHeight = max(rangeMaxHeight, maxHeight);
            answer[i] = maxHeight;
        }
        
        return answer;
    }
};