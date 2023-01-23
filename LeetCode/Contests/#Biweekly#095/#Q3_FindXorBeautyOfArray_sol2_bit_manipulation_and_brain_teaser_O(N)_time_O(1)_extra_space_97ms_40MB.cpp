class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int res = 0;
        for(int num: nums){
            res ^= num;
        }
        return res;
    }
};

/*
* Use symmetry to simplify the xor of all triplets;

* Case 1 (i != j):
  * For each triplet (i, j, k) there is another triplet (j, i, k);
  * ((nums[i] | nums[j]) & nums[k]) == ((nums[j] | nums[i]) & nums[k]);
  * ((nums[i] | nums[j]) & nums[k]) ^ ((nums[j] | nums[i]) & nums[k]) == 0;
  * So, triplets (i, j, k) and (j, i, k) cancel each other;
  * The contribution of this case is zero.

* Case 2 (i == j):
  * Triplet (i, j, k) is triplet (i, i, k);
  * ((nums[i] | nums[i]) & nums[k]) == (nums[i] & nums[k]);
  * (nums[0] & nums[k_0]) ^ (nums[1] & nums[k_0]) ^ ... ^ (nums[N - 1] & nums[k_0]) ^
    (nums[0] & nums[k_1]) ^ (nums[1] & nums[k_1]) ^ ... ^ (nums[N - 1] & nums[k_1]) ^
    ....
    (nums[0] & nums[k_N-1]) ^ (nums[1] & nums[k_N-1]) ^ ... ^ (nums[N - 1] & nums[k_N-1])

    = {apply the idea from case 1, each (i, k) pair is cancelled by another pair (k, i) for all i != k;
       as a result the final expression is reduced to the xor of pairs (i, i) <=> (nums[i] & nums[i]) <=> nums[i]}

    = (nums[0] & nums[0]) ^ (nums[1] & nums[1]) ^ ... ^ (nums[N - 1] & nums[N - 1]) =
    = nums[0] ^ nums[1] ^ ... ^ nums[N - 1];
  * The contribution of this case is (nums[0] ^ nums[1] ^ ... ^ nums[N - 1]).
*/