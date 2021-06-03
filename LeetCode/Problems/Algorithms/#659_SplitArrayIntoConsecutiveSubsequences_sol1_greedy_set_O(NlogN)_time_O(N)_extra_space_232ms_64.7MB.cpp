class Solution {
public:
    bool isPossible(vector<int>& nums) {
        const int N = nums.size();
        
        set<pair<int, int>> numCnt;
        int cnt = 1;
        for(int i = 1; i < N; ++i){
            if(nums[i - 1] == nums[i]){
                cnt += 1;
            }else{
                numCnt.insert({nums[i - 1], cnt});
                cnt = 1;
            }
        }
        
        numCnt.insert({nums[N - 1], cnt});
        
        while(!numCnt.empty()){
            vector<pair<int, int>> removalCandidates;
            set<pair<int, int>>::iterator it = prev(numCnt.end());
            while(it != numCnt.begin()){
                if(prev(it)->first + 1 == it->first &&
                   prev(it)->second >= it->second){
                    removalCandidates.push_back(*prev(it));
                    it = prev(it);
                }else{
                    break;
                }
            }
            
            if(!removalCandidates.empty()){
                removalCandidates.push_back(*prev(numCnt.end()));
            }
            
            if(removalCandidates.size() >= 3){
                for(const pair<int, int>& P: removalCandidates){
                    numCnt.erase(numCnt.find(P));
                    if(P.second - 1 >= 1){
                        numCnt.insert({P.first, P.second - 1});
                    }
                }
            }else{
                return false;
            }
        }
        
        return true;
    }
};