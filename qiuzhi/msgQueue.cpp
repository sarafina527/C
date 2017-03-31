#include <iostream>
#include <vector>
using namespace std;


vector<int> compute(int queueNums,int msgNums,int expandTime,int sendSpeed,int comsumeSpeed,int targetTime){
	vector<int> ans;
	vector<int> head(2*queueNums,0);//标记队头点位
	vector<int> tail(2*queueNums,0);//标记队尾点位
	int sofarsend = 0;//已经生产的个数
	int sofarenq = 0;//已经入队的个数
	for(int t=1;t<=targetTime&&t<expandTime;t++){
		sofarenq = sofarsend;
		sofarsend = sofarsend+sendSpeed<=msgNums?sofarsend+sendSpeed:msgNums;//判定有无生产结束
		for(int i=sofarenq;i<sofarsend;i++){
			tail[i%queueNums]++;//入队
		}
		for(int q=0;q<queueNums;q++){
			head[q] = head[q]+comsumeSpeed<tail[q]?head[q]+comsumeSpeed:tail[q]; //出队判空
		}
	}
	if(targetTime>=expandTime){//是否已经扩张
		vector<int> oldMsgPos(tail.begin(),tail.begin()+queueNums);
		for(int t=expandTime;t<=targetTime;t++){
			sofarenq = sofarsend;
			sofarsend = sofarsend+sendSpeed<=msgNums?sofarsend+sendSpeed:msgNums;//判定有无生产结束
			for(int i=sofarenq;i<sofarsend;i++){
				tail[i%(2*queueNums)]++;//立马新队列可以入队
			}
			if(head[0]<oldMsgPos[0]){//旧的未完成则只消费旧的，第一个队列总是入队最多的
				for(int q=0;q<queueNums;q++){
					head[q] = head[q]+comsumeSpeed<oldMsgPos[q]?head[q]+comsumeSpeed:oldMsgPos[q];
				}
			}else{
				for(int q=0;q<queueNums*2;q++){
					head[q] = head[q]+comsumeSpeed<tail[q]?head[q]+comsumeSpeed:tail[q]; //出队判空
				}
			}
			
		}
		return head;
	}else{
		ans = vector<int>(head.begin(),head.begin()+queueNums);
		return ans;
	}
}
void print(vector<int> &v){
	for(int i=0;i<v.size();i++){
		cout<<i<<" "<<v[i]<<endl;
	}
}

int main(){
	vector<int> ans;
	ans = compute(2,20,5,5,2,7);
	//ans = compute(2,20,2,5,2,3);
	print(ans);
	return 1;

}
