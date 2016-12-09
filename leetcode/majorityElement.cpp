class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int k = nums.size()/2;
        int q = select(nums,0,nums.size()-1,k);
        return q;
        
    }
    int select(vector<int>& nums,int p,int r,int k){//找到当前区间的顺序第k个
        if(p==r) return nums[p];
        int x = nums[r];
        int i=p-1,j=p;//i标记<pivot的数，i到j是>=pivot的数，遇小于则交换
        
        while(j<r){//根据第一个元素划分
            if(nums[j]>x){
                j++;
            }else{
                int tmp = nums[++i];
                nums[i] = nums[j];
                nums[j++] = tmp;
            }
        }
        nums[r] = nums[i+1];
        nums[++i] = x;
        cout<<i<<endl;
        int kt = i-p+1;
        if(kt==k){
            return nums[i];
        }else if(kt>k){
            return select(nums,p,i-1,k);
        }else{
            return select(nums,i+1,r,k-kt);
        }
    }
};