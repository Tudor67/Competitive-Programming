class Solution {
private:
    int getCharMask(vector<vector<int>>& suffCount, int l, int r){
        int mask = 0;
        for(char c = 'a'; c <= 'z'; ++c){
            if(suffCount[c - 'a'][l] - suffCount[c - 'a'][r + 1] >= 1){
                mask |= (1 << (c - 'a'));
            }
        }
        return mask;
    }

public:
    int maxPartitionsAfterOperations(string s, int k) {
        // Step 1: modify input string s such that s = "*" + s
        s.insert(s.begin(), '*');

        const int N = s.length();
        const int A = 26;

        // Step 2: suffix count of each char s[i]
        vector<vector<int>> suffCount(A, vector<int>(N + 1));
        for(int i = N - 1; i >= 1; --i){
            for(char c = 'a'; c <= 'z'; ++c){
                suffCount[c - 'a'][i] = suffCount[c - 'a'][i + 1];
            }
            suffCount[s[i] - 'a'][i] += 1;
        }

        // Step 3: suffBlocks[i]: number of valid blocks/partitions for s[i .. N - 1]
        vector<int> suffBlocks(N + 1, 1);
        int mask = 0;
        for(int i = N - 1; i >= 1; --i){
            suffBlocks[i] = suffBlocks[i + 1];
            mask |= (1 << (s[i] - 'a'));
            if(popcount((unsigned int)mask) > k){
                mask = (1 << (s[i] - 'a'));
                suffBlocks[i] = 1 + suffBlocks[i + 1];
            }
        }
        suffBlocks[N] = 0;

        // Step 4: prefBlocks[i]: number of valid blocks/partitions for s[1 .. i]
        //         lastBlockMask[i]: bitmask containing the corresponding chars of last block of s[1 .. i]
        vector<int> prefBlocks(N);
        vector<int> lastBlockMask(N);
        prefBlocks[0] = 1;
        for(int i = 1; i < N; ++i){
            prefBlocks[i] = prefBlocks[i - 1];
            lastBlockMask[i] = lastBlockMask[i - 1] | (1 << (s[i] - 'a'));
            if(popcount((unsigned int)lastBlockMask[i]) > k){
                prefBlocks[i] = prefBlocks[i - 1] + 1;
                lastBlockMask[i] = (1 << (s[i] - 'a'));
            }
        }
        prefBlocks[0] = 0;

        // Step 5: res: max number of partitions when we change at most one char s[i]
        int res = prefBlocks[N - 1];
        for(int i = 1; i < N; ++i){
            int startMask = lastBlockMask[i - 1];
            if(popcount((unsigned int)lastBlockMask[i - 1]) == k){
                startMask = 0;
            }

            for(char c = 'a'; c <= 'z'; ++c){
                if((s[i] == c) || ((lastBlockMask[i - 1] >> (c - 'a')) & 1)){
                    continue;
                }

                suffCount[s[i] - 'a'][i] -= 1;
                suffCount[c - 'a'][i] += 1;

                int l = i;
                int r = N - 1;
                while(l != r){
                    int mid = (l + r + 1) / 2;
                    int distinctChars = popcount((unsigned int)(startMask | getCharMask(suffCount, i, mid)));
                    if(distinctChars <= k){
                        l = mid;
                    }else{
                        r = mid - 1;
                    }
                }

                int blocks = prefBlocks[i - 1] + (int)(startMask == 0) + suffBlocks[r + 1];
                res = max(res, blocks);
                
                suffCount[s[i] - 'a'][i] += 1;
                suffCount[c - 'a'][i] -= 1;
            }
        }

        return res;
    }
};