//384. Shuffle an Array
//tag：容器重排
//问题描述：不重复地对一组数字进行洗牌。
//思路：使用STL的random_shuffle
class Solution {
    vector<int> original;
    vector<int> shuffled;
public:
    Solution(vector<int> nums) {
        original = vector<int>(nums.begin(),nums.end());
        shuffled = vector<int>(nums.begin(),nums.end());
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        random_shuffle(shuffled.begin(),shuffled.end());
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */