class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        const int N = nums.size();
        
        int res = 0;
        map<int, int> f;
        
        for(int i = 0; i < N; ++i){
            int imbNumber = 0;
            f.clear();
            
            for(int j = i; j < N; ++j){
                f[nums[j]] += 1;
                
                map<int, int>::iterator it = f.find(nums[j]);
                if(it->second == 1 && (int)f.size() >= 2){
                    if(it == f.begin()){
                        imbNumber += (int)(next(it)->first - it->first > 1);
                    }else if(next(it) == f.end()){
                        imbNumber += (int)(it->first - prev(it)->first > 1);
                    }else{
                        imbNumber += (int)(it->first - prev(it)->first > 1 &&
                                           next(it)->first - it->first > 1);
                        imbNumber -= (int)(it->first - prev(it)->first == 1 &&
                                           next(it)->first - it->first == 1);
                    }
                }

                res += imbNumber;
            }
        }
        
        return res;
    }
};