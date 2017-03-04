class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        return findMSortedArr(nums1,0,nums1.size()-1,nums2,0,nums2.size()-1);

    }
    double findMSortedArr(vector<int> &nums1,int p1,int q1,vector<int> &nums2,int p2,int q2){
        if(q1-p1<=2&&q2-p2<=2){
            vector<int> temp;
            int i=p1,j=p2;
            while(i<=q1&&j<=q2){
                if(nums1[i]<nums2[j]){
                    temp.push_back(nums1[i]);
                    i++;
                }else{
                    temp.push_back(nums2[j]);
                    j++;
                }
            }
            while(i<=q1){
                temp.push_back(nums1[i]);
                i++;
            }
            while(j<=q2){
                temp.push_back(nums2[j]);
                j++;
            }
            if(temp.size()%2){
                return temp[(temp.size()-1)/2];
            }else{
                return (temp[(temp.size()-1)/2]+temp[(temp.size())/2])/2.0;
            }
        }else{
            int m1 = (p1+q1)/2;
            int m2 = (p2+q2)/2;
            if(nums1[m1]<nums2[m2]){
                if((q1-p1+q1-m1)%2)
                    m1-=1;
                if((q2-p2+m2-p2)%2){
                    m2+=1;
                }
                cout<<m1<<" "<<m2<<endl;
                return findMSortedArr(nums1,m1,q1,nums2,p2,m2);
            }else{
                if((q1-p1+m1-p1)%2)
                    m1+=1;
                if((q2-p2+q2-m2)%2){
                    m2-=1;
                }
                return findMSortedArr(nums1,p1,m1,nums2,m2,q2);
            }
        }
        
            
    }

    
};