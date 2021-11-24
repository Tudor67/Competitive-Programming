class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> sortedNums(changed.begin(), changed.end());
        sort(sortedNums.begin(), sortedNums.end());
        
        queue<int> q;
        vector<int> original;
        for(int num: sortedNums){
            if(!q.empty() && q.front() == num){
                q.pop();
            }else{
                q.push(2 * num);
                original.push_back(num);
            }
        }
        
        if(!q.empty()){
            original.clear();
        }
        
        return original;
    }
};