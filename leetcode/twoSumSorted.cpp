class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans = vector<int>();

        int i=0,len=numbers.size();
        int j=len-1;
        while(i<j){
        	if(numbers[i]+numbers[j]==target){
        		ans.push_back(i+1,j+1);
        		break;
        	}else if(numbers[i]+numbers[j]<target){
        		i++;
        	}else{
        		j++;
        	}
        }
        return ans;
    }
};