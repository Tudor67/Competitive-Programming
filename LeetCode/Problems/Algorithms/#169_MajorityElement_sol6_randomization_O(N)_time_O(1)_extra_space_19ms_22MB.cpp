class Solution {
public:
    int majorityElement(vector<int>& nums) {
        const int N = nums.size();

        srand(time(nullptr));
        for(int iteration = 1; iteration <= 10; ++iteration){
            int candidate = nums[rand() % N];
            int candidateFreq = count(nums.begin(), nums.end(), candidate);
            if(candidateFreq > N / 2){
                return candidate;
            }
        }

        return INT_MIN;
    }
};