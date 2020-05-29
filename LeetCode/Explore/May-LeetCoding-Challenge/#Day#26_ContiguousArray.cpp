class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        const int N = nums.size();
        map<int, int> pos;
        pos[0] = -1;
        
        int answer = 0;
        int pref_sum = 0;
        for(int i = 0; i < N; ++i){
            pref_sum += (nums[i] == 0 ? -1 : 1);
            if(pos.count(pref_sum)){
                answer = max(i - pos[pref_sum], answer);
            }else{
                pos[pref_sum] = i;
            }
        }
        
        return answer;
    }
};