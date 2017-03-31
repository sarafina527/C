#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

bool isBadVersion(int version){
	return version>=1702766719;
}
int firstBadVersion(int n) {
        long long p = 1,q = n;
        while(p<=q){
        	int mid = (p+q)/2;
        	cout<<mid<<endl;
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
    int main(){
    	cout<<firstBadVersion(2126753390)<<endl;
	}
    
