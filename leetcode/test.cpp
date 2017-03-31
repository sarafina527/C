#include<iostream>
using namespace std;
unsigned int  reverseBits(unsigned int  n) {
    for(int i=0,j=31;i<j;i++,j--){
    	unsigned int ithbit = n>>i&1;
    	unsigned int jthbit = n>>j&1;
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
int hammingWeight(unsigned int n) {
    int ans = 0;
    while(n){
    	ans++;
    	n = n&(n-1);//clear the lowest 1 everytime
    }
    return ans;
}
int main(){
	unsigned int n =4294967295;
	
	cout<<hammingWeight(15)<<endl;
}
