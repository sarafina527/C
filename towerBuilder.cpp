class Kata
{
public:
    std::vector<std::string> towerBuilder(int nFloors)
    {
    	std::vector<std::string> v = std::vector<std::string>();
    	for(int i=1;i<=nFloors;i++){
    		std::string temp = "";
    		for(int j=0;j<nFloors-i;j++){
    			temp+=" ";
    		}
    		for(int j=0;j<2*i-1;j++){
    			temp+="*";
    		}
    		for(int j=0;j<nFloors-i;j++){
    			temp+=" ";
    		}
    		v.push_back(temp);
    	}
        return v;
    }
};