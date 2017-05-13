#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;

#define M 5
#define N 20
 
knuth(int n, int m)
{ 
    srand((unsigned int)time(0)); 
    for (int i = 0; i < n; i++) { 
        if ( rand()%(n-i)<m) { 
            cout << i << endl;
            m--;
        }
     }
}
//分解质因数
void prim(int m, int n)
 {
     if (m >= n)
     {
         while (m%n) n++;
         (m/=n);
         prim(m, n);
         cout << n << endl;
     }
 }
 void example(char acWelcome[]){
    printf("%d",sizeof(acWelcome));
    return;
}
void Func(char str_arg[100])
{
       printf("%d\n",sizeof(str_arg));
}

int fun(char(* ss)[N], int *n)
 {
     int i, k = 0, len = N;
     for (i = 0; i < M; i++)
     {
         len = strlen(ss[i]);
         if (i == 0)
             *n = len;
         if (len < * n)
         {
             *n = len;
             k = i;
         }
     }
     return (k);
 }
 
 int FindSubString( char* pch )
{
    int   count  = 0;
    char  * p1   = pch;
    while ( *p1 != '\0' )
    {   
        if ( *p1 == p1[1] - 1 )
        {
            p1++;
            count++;
        }else  {
            break;
        }
    }
    int count2 = count;
    while ( *p1 != '\0' )
    {
        if ( *p1 == p1[1] + 1 )
        {
            p1++;
            count2--;
        }else  {
            break;
        }
    }
    if ( count2 == 0 )
        return(count);
    return(0);
}
int sum(int a)
{
auto int c = 0;
static int b = 3;
c += 1;
b += 2;
return (a + b + c);
}
void ModifyString( char* pText )
{
    char  * p1   = pText;
    char  * p2   = p1;
    while ( *p1 != '\0' )
    {
        int count = FindSubString( p1 );
        cout<<count<<endl;
        if ( count > 0 )
        {
            *p2++ = *p1;
            sprintf( p2, "%i", count );
            while ( *p2 != '\0' )
            {
                p2++;
            }
            p1 += count + count + 1;
        }else  {
            *p2++ = *p1++;
        }
    }
}
class MyClass
{
public:
    MyClass(int i = 0)
    {
        cout << i;
    }
    MyClass(const MyClass &x)
    {
        cout << 2;
    }
    MyClass &operator=(const MyClass &x)
    {
        cout << 3;
        return *this;
    }
    ~MyClass()
    {
        cout << 4;
    }
};
char *myString()
{
    char buffer[6] = {0};
    char *s = "Hello World!";
    cout<<sizeof(buffer)<<endl;
    for (int i = 0; i < sizeof(buffer) - 1; i++)
    {
        buffer[i] = *(s + i);
        cout<<buffer[i]<<" ";
    }
    return buffer;
}
int main(){
	//knuth(5,3);
	//prim(8,2);
	char acWelcome[]="Welcome to Huawei Test";
    example(acWelcome);
    
    char str[]="Hello";
     printf("%d\n",sizeof(str));
    printf("%d\n",strlen(str));
    char*p=str;
    printf("%d\n",sizeof(p));
    Func(str);
    
    char text[32] = "XYBCDCBABABA";
 	ModifyString( text );
 	printf( text );
 	
 	int i;
    int a = 2;
    for (i = 0; i < 5; i++) 
    { 
        printf("%d,", sum(a)); 
    } 
    
    printf("%s\n", myString());
    
    int m = 9;
    MyClass obj1(1), obj2(2);
    MyClass obj3 = obj1;
    
    
    
    
    return 0;
}
