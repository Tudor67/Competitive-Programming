class RangeModule {
private:
    map<int, int> rangeEnd;
    
public:
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        auto it = rangeEnd.upper_bound(left);
        if(it != rangeEnd.begin() && max(left, prev(it)->first) <= min(right, prev(it)->second)){
            it = prev(it);
        }
        while(it != rangeEnd.end() && max(left, it->first) <= min(right, it->second)){
            left = min(it->first, left);
            right = max(it->second, right);
            it = rangeEnd.erase(it);
        }
        rangeEnd[left] = right;
    }
    
    bool queryRange(int left, int right) {
        auto it = rangeEnd.upper_bound(left);
        return (it != rangeEnd.begin() && right <= prev(it)->second);
    }
    
    void removeRange(int left, int right) {
        auto it = rangeEnd.upper_bound(left);
        if(it != rangeEnd.begin() && max(left, prev(it)->first) < min(right, prev(it)->second)){
            it = prev(it);
        }
        while(it != rangeEnd.end() && max(left, it->first) < min(right, it->second)){
            if(left <= it->first && it->second <= right){
                // Case 1: *it is covered by [left, right) => erase *it
                it = rangeEnd.erase(it);
            }else if(it->first < left && right < it->second){
                // Case 2: [left, right) splits *it into [l1, r1) and [l2, r2)
                //                                       [it->first, left) and [right, it->second)
                //         => create new ranges [l1, r1) and [l2, r2)
                //         => erase *it (by overwriting rangeEnd[it->first] = left)
                //         => add new ranges to the map
                //         => break, because *it was the last interval that intersected [left, right)
                int l1 = it->first;
                int r1 = left;
                int l2 = right;
                int r2 = it->second;
                rangeEnd[l1] = r1;
                rangeEnd[l2] = r2;
                break;
            }else if(it->first < left){
                // Case 3: *it shrinks to [it->first, left)
                //         => update [it->first, it->second) to [it->first, left)
                //         => move to the next range (i.e., it = next(it))
                rangeEnd[it->first] = left;
                it = next(it);
            }else if(right < it->second){
                // Case 4: *it shrinks to [right, it->second)
                //         => create [l1, r1) = [right, it->second)
                //         => erase *it
                //         => add [l1, r1) to the map
                //         => break, because *it was the last interval that intersected [left, right)
                int l1 = right;
                int r1 = it->second;
                it = rangeEnd.erase(it);
                rangeEnd[l1] = r1;
                break;
            }
        }
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */