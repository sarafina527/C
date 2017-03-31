//面试经典5.1
//将正数M插入到N的第i位到第j位,假设足以容纳M
int updateBits(int n,int m,int i,int j){
	//1.创建掩码将i到j位清零
	int left = ~0,right;
	left = left<<(j+1);
	right = (1<<i)-1;
	int mask = left|right;
	//2.将i到j位清零
	int ans &=mask;
	//3.将m左移到相应位置然后或操作
	ans |= m<<i;
	return ans;
}