class Solution {
public:
    int maximumLength(vector<int>& nums) {
        map<int, int> freq;
        for(int num: nums){
            freq[num] += 1;
        }

        int maxLen = 0;
        if(freq.contains(1)){
            maxLen = max(maxLen, 2 * ((freq[1] - 1) / 2) + 1);
            freq.erase(1);
        }

        while(!freq.empty()){
            int currLen = 0;
            int x = freq.begin()->first;
            
            while(true){
                if(freq[x] >= 2 && x <= INT_MAX / x && freq.contains(x * x)){
                    currLen += 2;
                    freq.erase(x);
                    x *= x;
                }else{
                    currLen += 1;
                    freq.erase(x);
                    break;
                }
            }

            maxLen = max(maxLen, currLen);
        }

        return maxLen;
    }
};