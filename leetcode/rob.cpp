class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> book(nums.size()+3,-1);
        int ans = rob(nums,0,book); 
        return ans;
    }
    int rob(vector<int>& nums,int p,vector<int> &book) {
        if(p>=nums.size()){
            book[p] = 0;
            return 0;
        }else if(p==nums.size()-1){
            book[p] = nums[p];
            return nums[p];
        }else{
            int ans;
            int p2 = book[p+2]!=-1?book[p+2]:rob(nums,p+2,book);
            int p3 = book[p+3]!=-1?book[p+3]:rob(nums,p+3,book);
            if(nums[p]+p2>=nums[p+1]+p3)
                ans = nums[p]+p2;
            else
                ans = nums[p+1]+p3;
            book[p] = ans;
            return ans;
        }
    }
};