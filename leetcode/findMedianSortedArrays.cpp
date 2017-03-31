class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int mn = nums1.size()+nums2.size();
        int kth;
        bool two = 0;
        if(mn%2)
            kth = mn/2;
        else{
            kth = mn/2-1;
            two = 1;
        } 
        if(mn==0) return 0.0;
        else if(!nums2.size()){
            return kthelem(nums1,kth,two);
        }else if(!nums1.size()){
            return kthelem(nums2,kth,two);
        }else{
            return findMSortedArr(kth,two,nums1,0,nums1.size()-1,nums2,0,nums2.size()-1);
        }
    }
    double findMSortedArr(int kth,bool &two,vector<int> &nums1,int p1,int q1,vector<int> &nums2,int p2,int q2){
        cout<<kth<<" "<<two<<endl;
        if(q1-p1<=2&&q2-p2<=2){
            vector<int> temp = merge(nums1,p1,q1,nums2,p2,q2);
            return kthelem(temp,kth,two);
        }else{
            int m1 = (p1+q1)/2;
            int m2 = (p2+q2)/2;
            if(nums1[m1]<nums2[m2]){
                return findMSortedArr(kth-m1+p1-1,two,nums1,m1+1,q1,nums2,p2,q2);
            }else{
                return findMSortedArr(kth-m2+p2-1,two,nums1,p1,q1,nums2,m2+1,q2);
            }
        }
    }
    vector<int> merge(vector<int> &nums1,int &p1,int &q1,vector<int> &nums2,int &p2,int &q2){
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
        return temp;
    }
    double kthelem(vector<int> &temp,int &kth,bool &two){
        if(!two){
            return temp[kth];
        }else{
            return (temp[kth]+temp[kth+1])/2.0;
        }
    }

    
};