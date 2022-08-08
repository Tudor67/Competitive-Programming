class FoodRatings {
private:
    set<tuple<string, int, string>> crfSystem;
    unordered_map<string, string> cuisineOf;
    unordered_map<string, int> ratingOf;
    
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        const int N = foods.size();
        for(int i = 0; i < N; ++i){
            crfSystem.emplace(cuisines[i], -ratings[i], foods[i]);
            cuisineOf[foods[i]] = cuisines[i];
            ratingOf[foods[i]] = ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        crfSystem.erase({cuisineOf[food], -ratingOf[food], food});
        ratingOf[food] = newRating;
        crfSystem.emplace(cuisineOf[food], -ratingOf[food], food);
    }
    
    string highestRated(string cuisine) {
        return get<2>(*crfSystem.upper_bound({cuisine, INT_MIN, ""}));
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */