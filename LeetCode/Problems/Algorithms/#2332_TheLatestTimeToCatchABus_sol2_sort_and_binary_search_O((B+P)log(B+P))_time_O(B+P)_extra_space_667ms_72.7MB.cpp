class Solution {
private:
    bool isValid(vector<int>& b, vector<int>& p, const int& MY_TIME, int capacity){
        vector<int>::iterator it = lower_bound(p.begin(), p.end(), MY_TIME);
        p.insert(it, MY_TIME);
        
        const int B = b.size();
        const int P = p.size();
        
        int maxTime = -1;
        int j = 0;
        for(int i = 0; i < B && j < P; ++i){
            for(int k = 1; k <= capacity && j < P; ++k){
                if(p[j] <= b[i]){
                    maxTime = p[j];
                    j += 1;
                }else{
                    break;
                }
            }
        }
        
        it = lower_bound(p.begin(), p.end(), MY_TIME);
        p.erase(it);
        
        return (MY_TIME <= maxTime);
    }
    
public:
    int latestTimeCatchTheBus(vector<int>& b, vector<int>& p, int capacity) {
        const int B = b.size();
        const int P = p.size();
        
        sort(b.begin(), b.end());
        sort(p.begin(), p.end());
        
        vector<int> candidates;
        for(int t: b){
            if(!binary_search(p.begin(), p.end(), t)){
                candidates.push_back(t);
            }
        }
        
        for(int t: p){
            if(!binary_search(p.begin(), p.end(), t - 1)){
                candidates.push_back(t - 1);
            }
        }
        
        sort(candidates.begin(), candidates.end());
        candidates.resize(unique(candidates.begin(), candidates.end()) - candidates.begin());
        
        int l = 0;
        int r = (int)candidates.size() - 1;
        while(l != r){
            int mid = (l + r + 1) / 2;
            if(isValid(b, p, candidates[mid], capacity)){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        
        return candidates[r];
    }
};