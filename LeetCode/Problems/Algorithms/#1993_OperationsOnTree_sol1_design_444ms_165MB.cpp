class LockingTree {
private:
    vector<int> parent;
    vector<vector<int>> children;
    unordered_map<int, int> locked;
    
public:
    LockingTree(vector<int>& parent) {
        const int N = parent.size();
        this->parent = parent;
        this->children.assign(N, {});
        for(int node = 1; node < N; ++node){
            children[parent[node]].push_back(node);
        }
    }
    
    bool lock(int num, int user) {
        if(!locked.count(num)){
            locked[num] = user;
            return true;
        }
        return false;
    }
    
    bool unlock(int num, int user) {
        if(locked.count(num) && locked[num] == user){
            locked.erase(num);
            return true;
        }
        return false;
    }
    
    bool upgrade(int num, int user) {
        // Check 1: node is unlocked
        // Check 3: ancestors are unlocked
        for(int ancestor = num; ancestor != -1; ancestor = parent[ancestor]){
            if(locked.count(ancestor)){
                return false;
            }
        }
        
        bool containsLockedDescendants = false;
        queue<int> q;
        q.push(num);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(int child: children[node]){
                if(locked.count(child)){
                    locked.erase(child);
                    containsLockedDescendants = true;
                }
                q.push(child);
            }
        }
        
        // Check 2: there is at least one locked descendant
        if(containsLockedDescendants){
            locked[num] = user;
            return true;
        }
        
        return false;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */