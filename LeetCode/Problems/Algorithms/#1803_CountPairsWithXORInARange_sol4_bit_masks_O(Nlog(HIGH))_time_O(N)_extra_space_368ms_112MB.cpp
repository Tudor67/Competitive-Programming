class Solution {
private:
    int countLess(vector<int>& nums, int limit){
        vector<unordered_map<int, int>> count(2);
        for(int num: nums){
            count[0][num] += 1;
        }
        
        // --- Count all pairs (i, j) such that nums[i] ^ nums[j] < limit ---
        // At current step:
        //    for each fixed (num, numCount):
        //        - update the count of (num >> 1) for the next step: count[nextStep][num >> 1] += numCount;
        //          at next step we will use only the prefix of binary representation of num (which is num without LSB: num >> 1);
        //        - if the LSB of limit is 1:
        //             limit:         xxxxxxxx1
        //             limit ^ 1:     xxxxxxxx0, where x can take any value from {0, 1};
        //             - find (complementNum, complementNumCount) such that num ^ complementNum = limit ^ 1
        //               (remember that limit ^ 1 < limit because LSB of limit is 1);
        //             - update pairsCount:
        //                      pairsCount += (numCount * (numCount - 1)) if num == numComplement;
        //                      pairsCount += (numCount * complementNumCount) if num != numComplement;
        //
        //     - remove LSB of limit: limit >>= 1;
        //       at next step we will use only the prefix of binary representation of limit (which is num without LSB: num >> 1);
        //
        // Example:
        //            limit (binary representation)
        //  Step 0:   110100
        //  Step 1:    11010
        //  Step 2:     1101 => update pairsCount by adding all counts of (num, complementNum) where num ^ complementNum = limit ^ 1 = 1100;
        //  Step 3:      110
        //  Step 4:       11 => update pairsCount by adding all counts of (num, complementNum) where num ^ complementNum = limit ^ 1 = 10;
        //  Step 5:        1 => update pairsCount by adding all counts of (num, complementNum) where num ^ complementNum = limit ^ 1 = 0;
        int step = 0;
        int pairsCount = 0;
        while(limit >= 1){
            count[(step + 1) % 2].clear();
            
            for(const pair<int, int>& P: count[step % 2]){
                int num = P.first;
                int numCount = P.second;
                count[(step + 1) % 2][num >> 1] += numCount;
                if(limit & 1){
                    int complementNum = num ^ limit ^ 1;
                    if(count[step % 2].count(complementNum)){
                        if(num == complementNum){
                            pairsCount += numCount * (numCount - 1);
                        }else{
                            pairsCount += numCount * count[step % 2][complementNum];
                        }
                    }
                }
            }
            
            step += 1;
            limit >>= 1;
        }
        
        // Count of all pairs (i, j) with i < j, such that nums[i] ^ nums[j] < limit;
        return pairsCount / 2;
    }
    
public:
    int countPairs(vector<int>& nums, int low, int high) {
        return countLess(nums, high + 1) - countLess(nums, low);
    }
};