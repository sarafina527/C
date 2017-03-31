class Solution {
public:
	struct comp  
	{  
	    bool operator ()(const vector<int> &v1, const vector<int> &v2)  
	    {  
	        for(int i=0;i<v1.size()&&i<v2.size();i++){
	            if(v1[i]==v2[i])
	                continue;
	            else
	                return v1[i]<v2[i];
	        }
	        return v1.size()<v2.size();
	    }  
	};
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    	vector<vector<int>> ans;
    	if(nums.size()<4) return ans;
        map<int,int> book;
        set<vector<int>,comp> anset;
        sort(nums.begin(),nums.end());
        book[nums[0]]++;
        for(int i=1;i<nums.size()-2;i++){
        	for(int j=i+1;j<nums.size()-1;j++){
        		if(j!=i+1&&nums[j]==nums[j-1])
        			continue;
        		else{
        			map<int,int>::iterator it;
        			for(it=book.begin();it!=book.end();it++){
        				int tmp = nums[i]+nums[j]+it->first;
        				if(binarySearch(nums,j+1,nums.size()-1,target-tmp)!=-1){
        					vector<int> oneans(4,0);
        					oneans[0] = it->first;
        					oneans[1] = nums[i];
        					oneans[2] = nums[j];
        					oneans[3] = target-tmp;
        					anset.insert(oneans);
        				}
        			}        			
        		}
        	}
        	book[nums[i]]++;
        }
        ans.assign(anset.begin(), anset.end());
        return ans;
    }
    int binarySearch(vector<int> &nums,int p,int q,int target){
    	int index = -1;
    	while(p<=q){
    		int mid = (p+q)/2;
    		if(nums[mid]==target){
    			index = mid;
    			break;
    		}else if(target<nums[mid])
    			q = mid-1;
    		else
    			p = mid+1;
    	}
    	return index;
    }
};