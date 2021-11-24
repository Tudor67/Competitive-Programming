class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        multiset<int> changedMultiset(changed.begin(), changed.end());
        vector<int> original;
        
        while(!changedMultiset.empty()){
            int num = *changedMultiset.begin();
            changedMultiset.erase(changedMultiset.begin());
            
            auto it = changedMultiset.find(2 * num);
            if(it == changedMultiset.end()){
                original.clear();
                break;
            }else{
                changedMultiset.erase(it);
                original.push_back(num);
            }
        }
        
        return original;
    }
};