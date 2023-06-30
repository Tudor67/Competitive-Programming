struct CombHelper{
    const long long MAX_N;
    const long long MODULO;
    vector<long long> f;
    vector<long long> fInv;
    vector<long long> inv;

    CombHelper(const long long MAX_N, const long long MODULO): MAX_N(MAX_N), MODULO(MODULO){
        f.assign(MAX_N + 1, 1);
        fInv.assign(MAX_N + 1, 1);
        inv.assign(MAX_N + 1, 1);
        for(int i = 2; i <= MAX_N; ++i){
            inv[i] = MODULO - ((MODULO / i) * inv[MODULO % i] % MODULO);
            f[i] = (f[i - 1] * i) % MODULO;
            fInv[i] = (fInv[i - 1] * inv[i]) % MODULO;
        }
    }

    long long getComb(const int N, const int K){
        return (f[N] * fInv[N - K] % MODULO) * fInv[K] % MODULO;
    }
};

struct BSTNode{
    int val;
    int subtreeSize;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int val = 0, int subtreeSize = 1, BSTNode* left = nullptr, BSTNode* right = nullptr){
        this->val = val;
        this->subtreeSize = subtreeSize;
        this->left = left;
        this->right = right;
    }

    ~BSTNode(){
        delete left;
        delete right;
    }
    
    BSTNode* insert(BSTNode* node, int val){
        if(node == nullptr){
            return new BSTNode(val);
        }
        node->subtreeSize += 1;
        if(val < node->val){
            node->left = insert(node->left, val);
        }else{
            node->right = insert(node->right, val);
        }
        return node;
    }

    void insert(int val){
        insert(this, val);
    }
};

class Solution {
private:
    const int MODULO = 1e9 + 7;

    long long solve(BSTNode* node, CombHelper& combHelper){
        if(node == nullptr || node->subtreeSize <= 2){
            return 1;
        }
        long long leftSolution = solve(node->left, combHelper);
        long long rightSolution = solve(node->right, combHelper);
        int leftSize = (node->left == nullptr ? 0 : node->left->subtreeSize);
        int rightSize = (node->right == nullptr ? 0 : node->right->subtreeSize);
        long long p = combHelper.getComb(leftSize + rightSize, leftSize);
        return (p * (leftSolution * rightSolution % MODULO)) % MODULO;
    }

public:
    int numOfWays(vector<int>& nums) {
        const int N = nums.size();

        BSTNode root(nums[0]);
        for(int i = 1; i < N; ++i){
            root.insert(nums[i]);
        }

        CombHelper combHelper(N, MODULO);
        return (solve(&root, combHelper) - 1 + MODULO) % MODULO;
    }
};