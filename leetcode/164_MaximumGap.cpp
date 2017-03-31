//164. Maximum Gap
//tag: sort,bucket sort
//问题描述：给定一个未排序的数组，返回排序后连续元素之间的最大差值。线性时间/空间
//特殊样例：数组少于2个元素返回0
//假设：假设数组中的所有元素都是非负整数，在32位有符号整数范围内。
//思路：1.先找到数组中元素的范围[min,max],而后划分成len+1个区间
//      2.将所有元素一一放入桶中（区间内），每个桶中保存数组中出现的该区间内的最大值和最小值
//      3.只需对比每个桶内的最大差异（bmax-bmin）和桶间最大差异（bmin-premax）即当前桶的最小值减去前一个桶的最大值，更新最大值
//      4.注意求区间偏移时可能小于1，当数组中出现重复的值，出现的数比范围内的数还多，这时候偏移应该等于1 
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int ans = 0, max=INT_MIN,min=INT_MAX,nexist=nums.size();
        getMaxMin(nums,max,min);
        if(nums.size()<2||max-min==0) return 0;//特殊情况元素小于2个或者重复返回0；
        
        vector<pair<int,int> > bucket(nums.size()+1,make_pair(INT_MAX,INT_MIN));//存放最小值和最大值
        int n = max-min+1;//区间里共有n个数
        int offset = n>nexist?1.0*n/nums.size()+0.5:1;//每个区间有的个数,若是存在的数有重复则一个区间一个数
        for(int i=0;i<nums.size();i++){//将所有数散列到桶中，保存每个桶中的最大值和最小值
            int index = (nums[i]-min)/offset;
            if(nums[i]>bucket[index].second)
               bucket[index].second = nums[i];
            if(nums[i]<bucket[index].first)
                bucket[index].first = nums[i];
        }
        int premax = INT_MAX;//保存前一个区间的最大值
        for(int i=0;i<bucket.size();i++){
            if(bucket[i].first==INT_MAX&&bucket[i].second==INT_MIN)//该桶是空的
                continue;
            else{
                int diffpre = bucket[i].first - premax;
                int diffbtw = bucket[i].second - bucket[i].first;
                if(diffpre>ans)
                    ans = diffpre;
                if(diffbtw>ans)
                    ans = diffbtw;
                premax = bucket[i].second;
            }
        }
        return ans;
    }
    void getMaxMin(vector<int>& nums,int &max,int&min){
        for(int i=0;i<nums.size();i++){
            if(nums[i]>max)
                max = nums[i];
            if(nums[i]<min)
                min = nums[i];
        }
    }
};