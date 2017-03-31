// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long p = 1,q = n;//考虑到两个较大数相加会溢出
        while(p<=q){
        	int mid = (p+q)/2;
        	if(isBadVersion(mid)){
        		if(mid==1||!isBadVersion(mid-1))
	        		return mid;
	        	q = mid-1;
        	}else{
        		p = mid+1;
        	}
        }
        return -1;
    }
};