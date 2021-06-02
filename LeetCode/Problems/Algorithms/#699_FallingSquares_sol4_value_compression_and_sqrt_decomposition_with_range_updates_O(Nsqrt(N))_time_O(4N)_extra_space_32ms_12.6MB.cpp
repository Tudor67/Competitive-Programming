class Range{
private:
    const int BLOCK_SIZE;
    vector<int> v;
    vector<int> blocksQuery;
    vector<int> blocksUpdate;
    
public:
    Range(const int& N): BLOCK_SIZE((int)sqrt(N)){
        v.resize(N, 0);
        blocksQuery.resize(1 + (N - 1) / BLOCK_SIZE, 0);
        blocksUpdate.resize(1 + (N - 1) / BLOCK_SIZE, 0);
    }
    
    void update(int l, int r, const int& VAL){
        blocksQuery[l / BLOCK_SIZE] = max(VAL, blocksQuery[l / BLOCK_SIZE]);
        blocksQuery[r / BLOCK_SIZE] = max(VAL, blocksQuery[r / BLOCK_SIZE]);
        while(l <= r && l % BLOCK_SIZE != 0){
            v[l] = VAL;
            l += 1;
        }
        while(l <= r && r % BLOCK_SIZE != BLOCK_SIZE - 1){
            v[r] = VAL;
            r -= 1;
        }
        while(l <= r){
            blocksUpdate[l / BLOCK_SIZE] = VAL;
            blocksQuery[l / BLOCK_SIZE] = VAL;
            l += BLOCK_SIZE;
        }
    }
    
    int query(int l, int r){
        int maxVal = max(blocksUpdate[l / BLOCK_SIZE], blocksUpdate[r / BLOCK_SIZE]);
        while(l <= r && l % BLOCK_SIZE != 0){
            maxVal = max(v[l], maxVal);
            l += 1;
        }
        while(l <= r && r % BLOCK_SIZE != BLOCK_SIZE - 1){
            maxVal = max(v[r], maxVal);
            r -= 1;
        }
        while(l <= r){
            maxVal = max(blocksQuery[l / BLOCK_SIZE], maxVal);
            l += BLOCK_SIZE;
        }
        return maxVal;
    }
};

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
        
        map<int, int> compressedValue;
        int idx = 0;
        compressedValue[v[0]] = 0;
        for(int i = 1; i < 2 * N; ++i){
            if(v[i - 1] != v[i]){
                idx += 1;
                compressedValue[v[i]] = idx;
            }
        }
        
        // Step 2: SQRT decomposition on compressed values
        const int M = compressedValue.size();
        Range range(M);
        vector<int> answer(N);
        for(int i = 0; i < N; ++i){
            int leftPos = positions[i][0];
            int rightPos = positions[i][0] + positions[i][1] - 1;
            int sideLength = positions[i][1];
            int maxHeight = sideLength + range.query(compressedValue[leftPos], compressedValue[rightPos]);
            range.update(compressedValue[leftPos], compressedValue[rightPos], maxHeight);
            answer[i] = range.query(0, M - 1);
        }
        
        return answer;
    }
};