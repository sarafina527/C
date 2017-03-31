class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        map<pair<int,int>,bool> book;
        pair<int,int> lp;
        longestPalindrome(s,0,s.size()-1,book,lp);
        ans = s.substr(lp.first,lp.second-lp.first+1);
        return ans;
    }
    bool longestPalindrome(string &s,int p,int q,map<pair<int,int>,bool> &book,pair<int,int> &lp){
    	pair<int,int> pp = make_pair(p,q);
    	if(book.find(pp)!=book.end())
    		return book[pp];
    	else if(q-p+1==0){
    		book[pp] = 1;
    		return true;
    	}else if(p==q){
    		if(q-p+1>lp.second-lp.first+1)
    			lp = pp;
    		book[pp]=1;
    		return true;
    	}
    	else{
    		if(s[p]==s[q]&&longestPalindrome(s,p+1,q-1,book,lp)){
				if(q-p+1>lp.second-lp.first+1)
					lp = pp;
				book[pp] = 1;
				return true;
    		}else{
    		    book[pp] = 0;
            	int i = p-1,j = q+1;
            	while(i>=0&&j<s.size()){
            		pair<int,int> p = make_pair(i,j);
            		book[p] = 0;
            		i--;
            		j++;
            	}
                if(book.find(make_pair(p,q-1))==book.end())
    			    longestPalindrome(s,p,q-1,book,lp);
                if(book.find(make_pair(p+1,q))==book.end())
    			    longestPalindrome(s,p+1,q,book,lp);
    		}
    	}
    	return false;
    }
};
//超时
//"civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth"