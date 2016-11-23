class Kata
{
public:
	//数组折叠
    std::vector<int> foldArray(std::vector<int> array, int runs)
    {
    	while(runs){
    		for(int s=0,e=array.size()-1;s<e;s++,e--){
    			array[s]+=array[e];
    			array.pop_back();
    		}
    		runs--;
    	}
        return array;
    }
};