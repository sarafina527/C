#include <time.h>  
#include <windows.h> 
//1
int main1(){
	while(1){
		long long busy = 9600000000;
		for(long long i=0;i<busy;i++);
		
		Sleep(5);
	}
	return 0;
} 
//2
int main(){
	const DWORD busytime = 10;
	const DWORD idletime = busytime;
	while(1){
		DWORD startTime = GetTickCount();
		while((GetTickCount()-startTime)<=busytime);
		Sleep(idletime); 
	}
}
