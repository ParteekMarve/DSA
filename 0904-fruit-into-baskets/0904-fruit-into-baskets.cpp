class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int max_fruits = 0;
        unordered_map<int,int> basket;
        int l = 0;
        for(int r = 0;r<n;r++){
            basket[fruits[r]]++;
            while(basket.size() > 2){
                basket[fruits[l]]--;
                if(basket[fruits[l]] == 0){
                    basket.erase(fruits[l]);
                }
                l++;
            }
            max_fruits = max(max_fruits,r-l+1);
        }

        return max_fruits;
    }
};