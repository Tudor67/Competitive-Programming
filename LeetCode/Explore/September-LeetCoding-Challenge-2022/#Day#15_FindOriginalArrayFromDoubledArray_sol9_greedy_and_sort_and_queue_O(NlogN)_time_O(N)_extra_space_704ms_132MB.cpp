class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> sortedChanged = changed;
        sort(sortedChanged.begin(), sortedChanged.end());
        
        vector<int> original;
        queue<int> q;
        for(int num: sortedChanged){
            if(!q.empty() && num == q.front()){
                q.pop();
            }else{
                original.push_back(num);
                q.push(2 * num);
            }
        }
        
        if(!q.empty()){
            original.clear();
        }
        
        return original;
    }
};