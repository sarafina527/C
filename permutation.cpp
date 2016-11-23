#include <stdio.h>
#define N 9

//全局变量
int n = N;
int ans[N+1];
int book[N+1];
int count = 0; 

void dfs(int step){
	int i;
	//解条件
	if(step==n+1){
		for (i = 1; i <=n; ++i)
		{
			printf("%d ",ans[i] );
			
		}
		printf("\n");
		count++;
		return;
	}
	for(i=1;i<=n;i++){
		if(!book[i]){
			ans[step] = i;
			book[i]=1;
			dfs(step+1);
			book[i]=0;
		}
	}
	return;
}
int main(void){
	scanf("%d",&n);
	dfs(1);
	printf("%d\n",count); 
	return 0;
}
