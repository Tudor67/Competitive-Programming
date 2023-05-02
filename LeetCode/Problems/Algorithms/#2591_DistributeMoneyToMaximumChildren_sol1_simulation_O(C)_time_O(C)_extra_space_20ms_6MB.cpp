class Solution {
public:
    int distMoney(int money, int children) {
        // Step 1: special case when some children don't receive money
        if(money < children){
            return -1;
        }
        
        vector<int> moneyOf(children);

        // Step 2: each child receives 1 dollar
        fill(moneyOf.begin(), moneyOf.end(), 1);
        money -= children;

        // Step 3: each child receives another 7 dollars (if possible)
        for(int child = 0; child < children; ++child){
            if(money >= 7){
                moneyOf[child] += 7;
                money -= 7;
            }else if(money >= 1){
                moneyOf[child] += money;
                money = 0;
            }
        }

        // Step 4: the last child takes all the remaining dollars
        moneyOf.back() += money;
        money = 0;

        // Step 5: if there is one child with 4 dollars it gives 1 dollar to its next neighbor
        //         a special case is the last child which will give 1 dollar to its previous neighbor
        for(int child = 0; child < children; ++child){
            if(moneyOf[child] == 4){
                moneyOf[child] -= 1;
                if(child + 1 < children){
                    moneyOf[child + 1] += 1;
                }else{
                    moneyOf[child - 1] += 1;
                }
            }
        }

        return count(moneyOf.begin(), moneyOf.end(), 8);
    }
};