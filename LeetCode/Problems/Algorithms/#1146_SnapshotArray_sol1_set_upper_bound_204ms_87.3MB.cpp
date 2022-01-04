class SnapshotArray {
private:
    int snapId;
    set<tuple<int, int, int>> indexSnapIdVal;
    
public:
    SnapshotArray(int length) {
        snapId = 0;
    }
    
    void set(int index, int val) {
        auto it = indexSnapIdVal.upper_bound({index, snapId, INT_MIN});
        if(it != indexSnapIdVal.end() && std::get<0>(*it) == index && std::get<1>(*it) == snapId){
            indexSnapIdVal.erase(it);
        }
        indexSnapIdVal.emplace(index, snapId, val);
    }
    
    int snap() {
        snapId += 1;
        return snapId - 1;
    }
    
    int get(int index, int snap_id) {
        auto it = indexSnapIdVal.upper_bound({index, snap_id, INT_MIN});
        if(it != indexSnapIdVal.end() && std::get<0>(*it) == index && std::get<1>(*it) == snap_id){
            return std::get<2>(*it);
        }
        if(it != indexSnapIdVal.begin() && std::get<0>(*prev(it)) == index){
            return std::get<2>(*prev(it));
        }
        return 0;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */