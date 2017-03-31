class Solution {
public:
    int compareVersion(string version1, string version2) {
    	if(version1.size()==0&&version2.size()==0) return 0;
        else if(version1.size()==0){
        	version1 = "0";
        } 
		else if(version2.size()==0){
			version2 = "0";
		} 
		
        int f1 = version1.find('.');
        int f2 = version2.find('.');
        string fpart1=version1,fpart2=version2,left1="",left2="";
        if(f1!=string::npos){
        	fpart1 = version1.substr(0,f1);
        	left1 = version1.substr(f1+1);
        }	
        if(f2!=string::npos){
        	fpart2 = version2.substr(0,f2);
        	left2 = version2.substr(f2+1);
        }
        int v1 = stringToInteger(fpart1);
        int v2 = stringToInteger(fpart2);
        if(v1==v2){
        	return compareVersion(left1,left2);
        }else if(v1<v2)
        	return -1;
        else
        	return 1; 
    }
    int stringToInteger(const string& str) {
        std::istringstream stream(str);
        stream >> std::setbase(10);
        int value;
        stream >> value;
        return value;
    }
};