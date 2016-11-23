#include <iostream>
#include <vector>
#include <string> 
//std::string encrypt(std::string text, int n)
//{
//	std::vector<int> visit = std::vector<int>();
//
//	int size = text.size();
//	for(int i=0;i<size;i++){
//		visit.push_back(0);
//	}
//	std::string en = "";
//	int i=1;
//	while(en.size()<size){
//		if(visit[i]!=1){
//			en += text[i];
//			visit[i] = 1;
//		}
//		i=(i+1)%size;
//		while(visit[i]==1){
//			i=(i+1)%size;
//		}
//		i=(i+1)%size;
//		while(visit[i]==1){
//			i=(i+1)%size;
//		}
//	}
//    return en;
//}
//std::string encrypt(std::string text, int n)
//{
//	std::vector<int> next = std::vector<int>();
//	int size = text.size();
//	for(int i=0;i<size-1;i++){
//		next.push_back(i+1);
//	}
//	next.push_back(0);
//	std::string en = "";
//	for(int i=0;i<n;i++){
//		en = "";
//		int cur = 0,pre=0;
//
//		while(en.size()<size){
//			cur = next[cur];
////			std::cout<<"pre"<<pre<<std::endl;
////			std::cout<<"cur="<<cur<<std::endl;
////			std::cout<<"text="<<text[cur]<<std::endl;
//			en += text[cur];
////			next[pre] = next[cur];			
//			cur = next[cur];
////			pre = cur;
//
//		}
//		text = en;
//	}
//	
//    return text;
//}
//环
// std::string encrypt(std::string text, int n)
// {
// 	std::vector<int> next = std::vector<int>();
// 	int size = text.size();
	
// 	std::string en = "";
// 	for(int i=0;i<n;i++){
// 		en = "";
// 		int cur = 0,pre=0;

// 		while(en.size()<size){
// 			cur = next[cur];
// //			std::cout<<"pre"<<pre<<std::endl;
// //			std::cout<<"cur="<<cur<<std::endl;
// //			std::cout<<"text="<<text[cur]<<std::endl;
// 			en += text[cur];
// //			next[pre] = next[cur];			
// 			cur = next[cur];
// //			pre = cur;

// 		}
// 		text = en;
// 	}
	
//     return text;
// }
std::string encrypt(std::string text, int n)
{
	int size = text.size();
	std::string en = "";
	for(int i=0;i<n;i++){
		en = "";
		for(int j=1;j<size;j+=2){
			en += text[j];
		}
		for (int j = 0; j < size; j+=2)
		{
			en += text[j];
		}
		text = en;
	}
    return text;
}
std::string decrypt(std::string encryptedText, int n)
{
	int size = encryptedText.size();	
	std::string de = "";
	for(int i=0;i<n;i++){
		de = "";
		int eveni = 0;
		int oddi = size/2;
		while(oddi<size){
			if(eveni<size/2){
				de+=encryptedText[oddi++];
				de+=encryptedText[eveni++];
			}else{
				de += encryptedText[oddi++];
			}
			
		}	
		encryptedText = de;
	}	
    return encryptedText;
}
int main(){
	std::cout<<encrypt("This is a test!", 1)<<std::endl;
	std::cout<<decrypt("hsi  etTi sats!", 1)<<std::endl;
}
