class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);
        int p=0,q=nums.size()-1,found=-1;
        while(p<=q){
            int mid = (p+q)/2;
            if(nums[mid]<target)
                p = mid+1;
            else if(nums[mid]>target)
                q = mid-1;
            else{
                found = mid;
                break;
            }
        }
        if(found!=-1){
            ans[0] = found;
            ans[1] = found;
            p=0;q=found-1;
            while(p<=q){//find the start
                if(nums[q]!=target)
                    break;
                int mid = (p+q)/2;
                if(nums[mid]==target){
                    if(mid==0||nums[mid-1]<target){
                        ans[0] = mid;
                        break;
                    }
                    ans[0] = mid;
                    q = mid-1;  
                }else
                    p = mid+1;
            }
            p=found+1,q=nums.size()-1;
            while(p<=q){
                int mid = (p+q)/2;
                if(nums[p]!=target)
                    break;
                if(nums[mid]==target){
                    if(mid==nums.size()-1||nums[mid+1]>target){
                        ans[1] = mid;
                        break;
                    }
                    ans[1] = mid;
                    p = mid+1;  
                }else
                    q = mid-1;
            }
        }
        return ans;
    }
};