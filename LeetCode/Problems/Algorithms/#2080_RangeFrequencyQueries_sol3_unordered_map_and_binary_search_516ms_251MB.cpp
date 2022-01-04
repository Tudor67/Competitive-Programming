class RangeFreqQuery {
private:
    unordered_map<int, vector<int>> posOf;
    
    int lowerBound(const vector<int>& V, int l, int r, int val){
        while(l != r){
            int mid = (l + r) / 2;
            if(V[mid] < val){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return r;
    }
    
    int upperBound(const vector<int>& V, int l, int r, int val){
        while(l != r){
            int mid = (l + r) / 2;
            if(V[mid] <= val){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return r;
    }
    
public:
    RangeFreqQuery(vector<int>& arr) {
        const int N = arr.size();
        for(int i = 0; i < N; ++i){
            posOf[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        if(!posOf.count(value)){
            return 0;
        }
        int idx1 = lowerBound(posOf[value], 0, (int)posOf[value].size(), left);
        int idx2 = upperBound(posOf[value], idx1, (int)posOf[value].size(), right);
        return idx2 - idx1;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */