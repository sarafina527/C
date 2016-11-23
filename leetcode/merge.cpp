class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m+n-1,i=m-1,j=n-1;
        while(k>=0){
        	if(nums2[j]>=nums1[i]){
        		nums1[k--] = nums2[j--];
        	}else{
        		nums1[k--] = nums1[i--];
        	}
        }
    }
};