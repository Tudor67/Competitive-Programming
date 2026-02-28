class RangeHelper{
private:
    const int N;
    const int BLOCK_SIZE;
    const int TOTAL_BLOCKS;
    vector<int> v;
    vector<int> blockDelta;
    vector<vector<int>> lastIndexOf;

    int getBlockIndex(int i){
        return (i / BLOCK_SIZE);
    }

    bool isBlockStart(int i){
        return (i % BLOCK_SIZE == 0);
    }

    bool isBlockEnd(int i){
        return (i % BLOCK_SIZE == BLOCK_SIZE - 1);
    }

public:
    RangeHelper(const int N):
            N(N), BLOCK_SIZE(floor(sqrt(N)) + 1), TOTAL_BLOCKS((N + BLOCK_SIZE - 1) / BLOCK_SIZE){
        v.assign(N, 0);
        blockDelta.assign(TOTAL_BLOCKS, 0);
        lastIndexOf.assign(TOTAL_BLOCKS, vector<int>(2 * N + 1, -1));
    }

    void add(int l, int r, const int VAL){
        int lBlock = getBlockIndex(l);
        int rBlock = getBlockIndex(r);

        for(int i = lBlock * BLOCK_SIZE, j = min(N, (lBlock + 1) * BLOCK_SIZE); i < j; ++i){
            lastIndexOf[lBlock][v[i] + N] = -1;
        }
        if(lBlock != rBlock){
            for(int i = rBlock * BLOCK_SIZE, j = min(N, (rBlock + 1) * BLOCK_SIZE); i < j; ++i){
                lastIndexOf[rBlock][v[i] + N] = -1;
            }
        }

        while(l <= r && !isBlockStart(l)){
            v[l] += VAL;
            l += 1;
        }
        while(l <= r && !isBlockEnd(r)){
            v[r] += VAL;
            r -= 1;
        }
        while(l <= r){
            blockDelta[getBlockIndex(l)] += VAL;
            l += BLOCK_SIZE;
        }

        for(int i = lBlock * BLOCK_SIZE, j = min(N, (lBlock + 1) * BLOCK_SIZE); i < j ; ++i){
            lastIndexOf[lBlock][v[i] + N] = i;
        }
        if(lBlock != rBlock){
            for(int i = rBlock * BLOCK_SIZE, j = min(N, (rBlock + 1) * BLOCK_SIZE); i < j; ++i){
                lastIndexOf[rBlock][v[i] + N] = i;
            }
        }
    }

    int getRightmostIndexOfZero(){
        for(int blockIndex = TOTAL_BLOCKS - 1; blockIndex >= 0; --blockIndex){
            if(lastIndexOf[blockIndex][N - blockDelta[blockIndex]] >= 0){
                return lastIndexOf[blockIndex][N - blockDelta[blockIndex]];
            }
        }
        return -1;
    }
};

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        const int N = nums.size();

        int maxLen = 0;
        unordered_map<int, int> nextIndexOf;
        RangeHelper rangeHelper(N);

        for(int i = N - 1; i >= 0; --i){
            int delta = (nums[i] % 2 == 0 ? -1 : 1);
            int j = (nextIndexOf.count(nums[i]) ? nextIndexOf[nums[i]] : N);
            rangeHelper.add(i, j - 1, delta);
            maxLen = max(maxLen, rangeHelper.getRightmostIndexOfZero() - i + 1);
            nextIndexOf[nums[i]] = i;
        }

        return maxLen;
    }
};