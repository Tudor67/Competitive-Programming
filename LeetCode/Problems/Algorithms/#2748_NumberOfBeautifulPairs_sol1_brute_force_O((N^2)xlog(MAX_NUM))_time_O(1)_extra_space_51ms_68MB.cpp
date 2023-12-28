class Solution {
private:
    int getFirstDigit(int num){
        while(num > 9){
            num /= 10;
        }
        return num;
    }

    int getLastDigit(int num){
        return num % 10;
    }

public:
    int countBeautifulPairs(vector<int>& nums) {
        const int N = nums.size();
        
        int beautifulPairs = 0;
        for(int i = 0; i < N; ++i){
            for(int j = i + 1; j < N; ++j){
                if(gcd(getFirstDigit(nums[i]), getLastDigit(nums[j])) == 1){
                    beautifulPairs += 1;
                }
            }
        }
        
        return beautifulPairs;
    }
};