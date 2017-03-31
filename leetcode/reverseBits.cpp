class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        for(int i=0,j=31;i<j;i++,j--){
        	uint32_t ithbit = n>>i&1;
        	uint32_t jthbit = n>>j&1;
        	if(ithbit==jthbit)
        		continue;
        	else{
        		if(jthbit)
	        		n |= 1<<i;//set 1
	        	else
	        		n ^= 1<<i;
	        	if(ithbit)
	        		n |= 1<<j;
	        	else
	        		n ^= 1<<j;
        	}
        }
        return n;
    }
};
