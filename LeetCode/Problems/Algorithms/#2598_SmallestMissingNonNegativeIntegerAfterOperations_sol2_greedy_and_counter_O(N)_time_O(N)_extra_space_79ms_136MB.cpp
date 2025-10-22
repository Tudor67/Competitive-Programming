class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        const int N = nums.size();

        unordered_map<int, int> freqOf;
        for(int num: nums){
            freqOf[(num % value + value) % value] += 1;
        }

        for(int num = 0; num <= N; ++num){
            if(freqOf[num % value] >= 1){
                freqOf[num % value] -= 1;
            }else{
                return num;
            }
        }

        return -1;
    }
};