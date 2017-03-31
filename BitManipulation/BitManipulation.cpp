//Bit Manipulation

/*
1.int2binary 转二进制
*/
//C的方式：
int i = 343543;
for(int j=sizeof(int)*8-1; j>=0; --j)
   cout << ((i >> j) & 1);

//C++的方式：
int i = 343543;
bitset<32> intBit(i);
   cout << intBit.to_string() << endl;

//2.测试一个数字含有多少个1位：
int count(int x)
{
    int n = 0;
    while(x) { 
       x &= (x-1); //将x的最右边的1位变成0
       ++n;
    }
    return n;
}
//2.1测试一个数字含有多少个0位：
sizeof(x)*8 - count(x);


//3.even or odd
bool isOdd(int x){
	if(x & 1) return 1;
	else return 0;
}

//4.2^n
bool is2power(int x){
	if(x&(x-1)==0)
		return 1;
	else 
		return 0;
}

//补码
-x = ~x + 1 = ~(x-1);
~x = -x-1;
~(-x) = x-1;
//加减法
x+y = x - ~y-1 = (x|y)+(x&y);
x-y = x + ~y + 1 = (x|~y) - (~x&y);
//异或与或关系
x^y = (x|y) - (x&y);
x|y = (x& ~y) + y;
x&y = (~x|y)- ~x;

///x == y:
~(x-y|y-x);
///x != y:
x-y|y-x;
///x < y:
(x-y)^((x^y)&((x-y)^x));
///x <= y:
(x|~y)&((x^y)|~(y-x));
///x < y:
(~x&y)|((~x|y)&(x-y)); ///无符号x,y的比较
///x <= y:
(~x|y)&((x^y)|~(y-x)) ///无符号x,y的比较

///计算绝对值：
int abs(int x)
{
    int y;
    y = x >> 31;
    return (x^y)-y; ///or:(x+y)^y
}
///符号函数：
sign(int x)
{
    return (x>>31)|(unsigned(-x))>>31; //x=-2的31次方时失败
}
///三值比较：cmp(x, y) = -1(x<y);0(x==y);1(x>y)
int cmp(int x, int y)
{
    return (x>y)-(x-y);
}

