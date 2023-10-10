class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        const int N = nums.size();

        vector<int> res;

        srand(time(nullptr));
        for(int iteration = 1; iteration <= 10; ++iteration){
            int randIndex = rand() % N;
            if(find(res.begin(), res.end(), nums[randIndex]) == res.end()){
                if(count(nums.begin(), nums.end(), nums[randIndex]) > N / 3){
                    res.push_back(nums[randIndex]);
                }
            }
        }

        return res;
    }
};