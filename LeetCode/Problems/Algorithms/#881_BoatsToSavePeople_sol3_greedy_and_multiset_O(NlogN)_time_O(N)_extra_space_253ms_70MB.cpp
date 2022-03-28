class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        multiset<int> mSet(people.begin(), people.end());
        
        int boats = 0;
        while(!mSet.empty()){
            int w = *prev(mSet.end());
            mSet.erase(prev(mSet.end()));
            
            if(!mSet.empty()){
                multiset<int>::iterator it = mSet.upper_bound(limit - w);
                if(it != mSet.begin()){
                    mSet.erase(prev(it));
                }
            }
            
            boats += 1;
        }
        
        return boats;
    }
};