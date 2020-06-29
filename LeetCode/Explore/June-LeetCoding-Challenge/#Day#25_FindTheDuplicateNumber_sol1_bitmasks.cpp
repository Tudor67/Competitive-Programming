class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        const int BITS = 31;
        const int N = (int)nums.size() - 1;
        
        vector<int> cnt1(BITS);
        for(int i = 1; i <= N; ++i){
            for(int bit = 0; bit < cnt1.size(); ++bit){
                if(i & (1 << bit)){
                    ++cnt1[bit];
                }
            }
        }
        
        vector<int> cnt2(BITS);
        for(int num: nums){
            for(int bit = 0; bit < cnt2.size(); ++bit){
                if(num & (1 << bit)){
                    ++cnt2[bit];
                }
            }
        }
        
        int answer = 0;
        for(int bit = 0; bit < cnt1.size(); ++bit){
            if(cnt1[bit] < cnt2[bit]){
                answer |= (1 << bit);
            }
        }
        
        return answer;
    }
};