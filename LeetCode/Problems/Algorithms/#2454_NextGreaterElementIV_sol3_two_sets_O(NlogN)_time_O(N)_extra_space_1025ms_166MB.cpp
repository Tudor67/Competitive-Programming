class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        const int N = nums.size();
        
        vector<int> answer(N, -1);
        set<pair<int, int>> set0;
        set<pair<int, int>> set1;
        
        for(int i = 0; i < N; ++i){
            set<pair<int, int>>::iterator it = set1.begin();
            while(it != set1.end()){
                int num = it->first;
                int numIndex = it->second;
                if(num < nums[i]){
                    answer[numIndex] = nums[i];
                    it = set1.erase(it);
                }else{
                    it = set1.end();
                }
            }
            
            it = set0.begin();
            while(it != set0.end()){
                int num = it->first;
                int numIndex = it->second;
                if(num < nums[i]){
                    it = set0.erase(it);
                    set1.emplace(num, numIndex);
                }else{
                    it = set0.end();
                }
            }
            
            set0.emplace(nums[i], i);
        }
        
        return answer;
    }
};