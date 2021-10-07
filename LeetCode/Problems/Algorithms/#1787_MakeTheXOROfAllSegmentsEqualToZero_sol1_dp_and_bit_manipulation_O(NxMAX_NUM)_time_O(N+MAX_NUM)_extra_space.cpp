class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        const int N = nums.size();
        const int MAX_NUM = max(1, *max_element(nums.begin(), nums.end()));
        const int MAX_BIT = (int)floor(log2(MAX_NUM));
        const int FULL_MASK = (1 << (MAX_BIT + 1)) - 1;
        
        // General idea:
        // (a) Let's suppose that the XOR of the segment nums[l .. r] is zero;
        //     (i.e., nums[l] ^ nums[l + 1] ^ ... ^ nums[r] == 0);
        
        // (b) Then the XOR of the next segment nums[l + 1 .. r + 1] is nums[l] ^ nums[r + 1];
        //     It is equal to zero when nums[l] ^ nums[r + 1] is zero (i.e., when nums[l] == nums[r + 1]);
        //     (Details: nums[l + 1] ^ ... ^ nums[r] ^ nums[r + 1] = nums[l] ^ nums[l] ^ nums[l + 1] ^ ... ^ nums[r] ^ nums[r + 1] = 
        //                                                           nums[l] ^                  0                    ^ nums[r + 1] =
        //                                                           nums[l] ^ nums[r + 1]);
        //     So, the XOR of the next segment nums[l + 1 .. r + 1] is zero <=> nums[l] ^ nums[r + 1] is zero <=> nums[l] == nums[r + 1];
        
        // (c) We deal with segments of fixed size k;
        //     So, the segment nums[l .. r] of fixed size k is nums[l .. l + k - 1];
        
        // (d) The XOR of each segment nums[0 .. k - 1], nums[1 .. k], nums[2 .. k + 1] ..., nums[N - k .. N - 1] is zero
        //     is equivalent to:
        //                     -> fixing first k elements such that their XOR is zero
        //                        (i.e., nums[0] ^ nums[1] ^ nums[2] ^ ... ^ nums[k - 1] == 0) and
        //                     -> setting all nums at position (i % k) to be equal
        //                        (nums[i] == nums[i + k] == nums[i + 2 * k] == nums[i + 3 * k] == ... == nums[i + c * k]);
        
        // (e) The main idea is to create a repeated pattern;
        //     Example for k = 3: [a, b, c, a, b, c, a, b, c, a] with a ^ b ^ c == 0;
        
        // buckets[i] (with 0 <= i <= k - 1) is a counter for {nums[i], nums[i + k], nums[i + 2 * k], ..., nums[i + c * k]}
        vector<unordered_map<int, int>> buckets(k);
        for(int i = 0; i < N; ++i){
            buckets[i % k][nums[i]] += 1;
        }
        
        // At step i:
        //    maxKept[i][mask]: max number of elements from buckets[0 .. i] that we can keep
        //                      such that the xor of i elements will be equal to mask;
        // Example for k = 3 and nums = [a, b, d, a, b, e]
        //                  best nums = [a, b, c, a, b, c],
        //                  such that a ^ b ^ c == 0 and
        //                  we modify only 2 elements (d -> c, e -> c)
        //                  which is the same as keeping 6 - 2 = 4 elements (a = a, b = b, a = a, b = b);
        // We need this DP to minimize the number of modifications in the array such that the xor of each segment is equal to zero;
        // This is equivalent to maximization of the number of unmodified elements, which is easier to implement (and cleaner);
        vector<vector<int>> maxKept(2, vector<int>(FULL_MASK + 1));
        for(auto [mask, maskFreq]: buckets[0]){
            maxKept[0][mask] = maskFreq;
        }
        
        for(int i = 1; i < k; ++i){
            // At step i we can keep at least maxKept elements from step i - 1
            // by fixing the max value from step i - 1 and
            // - adding elements which are not in buckets[i] (with freq == 0) => this will keep the max value from step i - 1
            //                                                                   for some maxKept[i][..] values;
            // - or adding elements from buckets[i] (with freq > 0) => this can only increase some maxKept[i][..] values;
            // In both cases, values at step i are greater than or equal to max value from step i - 1,
            // because each mask at step i has a frequency >= 0;
            // So, it's ok to initialize maxKept[i][..] with max value from maxKept[i - 1][..];
            int prevMaxKept = *max_element(maxKept[(i - 1) % 2].begin(), maxKept[(i - 1) % 2].end());
            fill(maxKept[i % 2].begin(), maxKept[i % 2].end(), prevMaxKept);
            for(int mask1 = 0; mask1 <= FULL_MASK; ++mask1){
                for(auto [mask2, mask2Freq]: buckets[i]){
                    maxKept[i % 2][mask1 ^ mask2] = max(maxKept[i % 2][mask1 ^ mask2], maxKept[(i - 1) % 2][mask1] + mask2Freq);
                }
            }
        }
        
        return N - maxKept[(k - 1) % 2][0];
    }
};