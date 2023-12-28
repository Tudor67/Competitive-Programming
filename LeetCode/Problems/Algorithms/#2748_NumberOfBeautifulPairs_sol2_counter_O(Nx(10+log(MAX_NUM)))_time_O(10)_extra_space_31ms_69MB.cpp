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
        vector<int> freq(10);
        for(int i = 0; i < N; ++i){
            int lastDigit = getLastDigit(nums[i]);
            for(int firstDigit = 1; firstDigit <= 9; ++firstDigit){
                if(gcd(firstDigit, lastDigit) == 1){
                    beautifulPairs += freq[firstDigit];
                }
            }
            freq[getFirstDigit(nums[i])] += 1;
        }
        
        return beautifulPairs;
    }
};