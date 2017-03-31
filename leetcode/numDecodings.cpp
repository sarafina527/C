class Solution {
public:
    int numDecodings(string s) {
        map<string,int> book;
        return numDecodings(s,book);
    }
    int numDecodings(string s,map<string,int> &book){
        int ans = 0;
        if(s.size()==0||s[0]<'1'||s[0]>'9') ans=0;
        else if(s.size()==1) ans = 1;
        else if(s.size()==2){
            int num = (s[0]-'0')*10+s[1]-'0';
            if(num>=1&&num<=26){
                if(s[1]>='1'&&s[1]<='9')
                    ans = 2;
                else
                    ans = 1;
            }else if(s[1]>='1'&&s[1]<='9')
                ans = 1;
            else
                ans = 0;
        }else{
            int num = (s[0]-'0')*10+s[1]-'0';
            if(num>=1&&num<=26){//满足两位需求
                string deone = s.substr(1);
                string detwo = s.substr(2);
                int numone,numtwo;
                if(book.find(detwo)!=book.end())
                    numtwo = book[detwo];
                else{
                    numtwo = numDecodings(detwo,book);
                    book[detwo] = numtwo;
                }
                if(book.find(deone)!=book.end())
                    numone = book[deone];
                else{
                    numone = numDecodings(deone,book);
                    book[deone] = numone;
                }   
                ans = numone+numtwo;
                
            }else if(s[0]>='1'&&s[1]<='9'){//满足一位需求
                string deone = s.substr(1);
                if(book.find(deone)!=book.end())
                    ans = book[deone];
                else{
                    ans = numDecodings(deone,book);
                    book[deone] = ans;
                }
            }
        }
        book[s] = ans;
        return ans;
    }
};
//"12457162426791551819232487"