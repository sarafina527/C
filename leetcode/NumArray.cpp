class NumArray {
    vector<int> innums;
    vector<long long> insums;
public:
    NumArray(vector<int> nums) {
        for(int i=0;i<nums.size();i++){
        	innums.push_back(nums[i]);
        	long long tmp = nums[i];
        	if(i==0)
        		insums.push_back(tmp);
        	else
        		insums.push_back(tmp+insums.back());
        }
    }
    
    int sumRange(int i, int j) {
        if(!(i>=0&&i<insums.size())||!(j>=i&&j<insums.size())) return 0;
    	assert(i>=0&&i<insums.size());
    	assert(j>=i&&j<insums.size());
        return insums[j]-insums[i]+innums[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */