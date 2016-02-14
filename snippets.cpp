# Read File Into Vector
snippet readfile
	std::vector<char> v;
	if (FILE *${2:fp} = fopen(${1:"filename"}, "r")) {
		char buf[1024];
		while (size_t len = fread(buf, 1, sizeof(buf), $2))
			v.insert(v.end(), buf, buf + len);
		fclose($2);
	}${3}
# std::map
snippet map
	std::map<${1:key}, ${2:value}> map${3};
# std::vector
snippet vector
	std::vector<${1:char}> v${2};
# Namespace
snippet ns
	namespace ${1:`Filename('', 'my')`} {
		${2}
	} /* $1 */
# Class
snippet cl
	class ${1:`Filename('$1_t', 'name')`} {
	public:
		$1 (${2:arguments});
		virtual ~$1 ();

	private:
		${3:/* data */}
	};
snippet fori
	for (int ${2:i} = 0; $2 < ${1:count}; $2${3:++}) {
		${4:/* code */}
	}

snippet temp
	/*******************************
	// Author : Abdul Qadir Faridi
	// IPG-3rd yr
	// Institute : ABV-IIITM,Gwalior
	*********************************/

	//header files

	#include <iostream>
	#include <cstdio>
	#include <cstring>
	#include <cmath>
	#include <cstdlib>
	#include <climits>
	#include <cassert>
	#include <iomanip>
	#include <vector>
	#include <utility>
	#include <map>
	#include <set>
	#include <list>
	#include <stack>
	#include <queue>
	#include <deque>
	#include <bitset>
	#include <complex>
	#include <numeric>
	#include <functional>
	#include <sstream>
	#include <algorithm>
	
	//Preprocessor directives

	#define gc getchar_unlocked
	
	//macros input-output

	#define si(n)                       scanf("%d",&n)
	#define sll(n)                      scanf("%lld",&n)
	#define sf(n)                       scanf("%f",&n)
	#define ss(str)                     scanf("%s",str)
	#define sd(n)                       scanf("%lf",&n)
	#define INF                         INT_MAX
	#define LINF                        (LL)1e18
	#define maX(a,b)                    ((a)>(b)?(a):(b))
	#define miN(a,b)                    ((a)<(b)?(a):(b))
	#define abS(x)                      ((x)<0?-(x):(x))
	#define	forr(i,a,b)                 for(int i=a;i<b;i++)
	#define rep(i,n)                    forr(i,0,n) 
	#define pn()                        printf("\n")
	#define pi(n)                       printf("%d",n)
	#define pll(n)                      printf("%lld",n)
	#define pd(n)                       printf("%lf",n)
	#define ps(str)                     printf("%s",str)

	//macros stl

	#define mp                          make_pair
	#define tri(a,b,c)                  mp(a,mp(b,c))
	#define pb                          push_back
	#define fill(a,v)                   memset(a,v,sizeof a)
	#define all(x)                      x.begin(),x.end()
	#define uniq(v)                     sort(all(v));v.erase(unique(all(v)),v.end())
	#define findval(arr,val)            (lower_bound(all(arr)),val)-arr.begin()
	#define clr(a)                      memset(a,0,sizeof a)

	
	//debug

	#define debug                       if(1)
	#define debugoff                    if(0)	
	
	#define print(x)                 cerr << x << " ";    
	#define trace1(x)                cerr << #x << ": " << x << endl;
	#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
	#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;

	//Translator

	bool isUpperCase(char c){return c>='A' && c<='Z';}
	bool isLowerCase(char c){return c>='a' && c<='z';}
	bool isLetter(char c){return c>='A' && c<='Z' || c>='a' && c<='z';}
	bool isDigit(char c){return c>='0' && c<='9';}
	char toLowerCase(char c){return (isUpperCase(c))?(c+32):c;}
	char toUpperCase(char c){return (isLowerCase(c))?(c-32):c;}

	//constants

	#define PI                          M_PI
	#define E                           M_E
	using namespace std;

	//typedef

	typedef long long LL;
	typedef unsigned long long uLL;
	typedef pair<int,int> pii;
	typedef pair<LL,LL> pll;
	typedef pair<int,pii> tri;

	//FAST IO
	#define sync ios::sync_with_stdio(false);
	#define untie cin.tie(NULL);
	#define endll '\n'
	//#define input(n) readInt(&n)
	
	inline void readNat(int *x)
	{
		register int c = gc();
		*x = 0;
		for(;(c<48 || c>57);c = gc());//ignore whitespace in front
		//2x + 8x = 10x  optimisation
	 		for(;c>47 && c<58;c = gc()) {*x = (*x<<1) + (*x<<3) + c - 48;}
	}
	inline void readInt(int &x)
	{
	    register int c = gc();
	    x = 0;
	    int neg = 0;
	    for(;((c<48 || c>57) && c != '-');c = gc());
	    if(c=='-') {neg=1;c=gc();}
	    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
	    if(neg) x=-x;
	}
	inline void read_string(char *str)
	{
	  	register char c = 0;
	   	register int i = 0;
	 
	    while (c < 33)
	        c = getchar_unlocked();
	 
	    while (c != '\n') 
	    {
	        str[i] = c;
	        c = getchar_unlocked();
	        i = i + 1;
	    }
	 
	    str[i] = '\0';
	}
	namespace IO
	{
		const int SIZE = 1 << 19;
		char buff[SIZE], *p = buff + SIZE;
	 	char buf2[SIZE];
		int bufL2 = 0;

		inline char read_char()
		{
	   		if( p == buff + SIZE ) //only once check (whole i/p file)
	   		{
	     		fread( buff, 1, SIZE, stdin );
	       		p = buff;
		    }
		    return *(p++);//further invokes from buff ptr
		}
	 
		inline int read_int()
		{
		    char c;
			int val = 0;

			do 
			{
				c = read_char() ;
			}while( c < '-' ) ;//this while loop will continue until it finds '-' or ' ' or '\n'
			
			if( c == '-' ) 
			{
				//this means the current integer is negative
				for( c = read_char() ; c >= '0' ; c = read_char() ) 
				{
					val = val * 10 + ( c - '0' ) ;//get the integer
				}
				return - val ;//return the negative number
			}
			else 
			{
				for( ; c >= '0' ; c = read_char() ) 
				{
					val = val * 10 + ( c - '0' ) ;
				}
				return val ;//return the positive number

			}
		  
		}
		inline void write_flush() 
		{
			fwrite( buf2 , sizeof( char ) , bufL2 , stdout ) ;//flushes output to stdout
			bufL2 = 0 ;//pointer returns to the beginning since output buffer array(buf2) has been flushed
		}

		inline void write_char( char c ) 
		{
			buf2[ bufL2++ ] = c ;//bufL2 points to current index in the output buffer array(buf2)  
			if( bufL2 == SIZE ) 
			{
				//array full so let's flush it
				write_flush() ;
			}
		}

		inline void write_str(char* str)
		{
			for(int i=0;str[i];i++)
				write_char(str[i]);
		}
		inline void write_int(int n)
		{
			//recursive function to load the number to output buffer array(buf2)
			if( n >= 10 ) 
			{
				write_int( n / 10 ) ;
			}
				write_char( '0' + n % 10 ) ;
		}
		
		inline void write_Int(int n)
		{
			if(n<0)
			{
				write_char('-');
				write_flush();
				n *= (-1);
			}
			write_int(n);
		}
	}
	
	using namespace IO;

	//file read

	#define read_file(x) freopen(x,"r",stdin)
	#define write_file(x) freopen(x,"w",stdout)	
	#define MAX 1000010
	#define MOD 1000000007
	
	int main()
	{
		int t;
		int n;
		si(t);
		while(t--)
		{
			si(n);
		    ${1}	
		}
		return  0;
	}


snippet temp2
	/*******************************
	// Author : Abdul Qadir Faridi
	// IPG-3rd yr
	// Institute : ABV-IIITM,Gwalior
	*********************************/

	//header files

	#include <iostream>
	#include <cstdio>
	#include <cstring>
	#include <cmath>
	#include <cstdlib>
	#include <climits>
	#include <cassert>
	#include <iomanip>
	#include <vector>
	#include <utility>
	#include <map>
	#include <set>
	#include <list>
	#include <stack>
	#include <queue>
	#include <deque>
	#include <bitset>
	#include <complex>
	#include <numeric>
	#include <functional>
	#include <sstream>
	#include <algorithm>
	
	//Preprocessor directives

	#define gc getchar_unlocked
	
	//macros input-output

	#define si(n)                       scanf("%d",&n)
	#define sll(n)                      scanf("%lld",&n)
	#define sf(n)                       scanf("%f",&n)
	#define ss(str)                     scanf("%s",str)
	#define sd(n)                       scanf("%lf",&n)
	#define INF                         INT_MAX
	#define LINF                        (LL)1e18
	#define maX(a,b)                    ((a)>(b)?(a):(b))
	#define miN(a,b)                    ((a)<(b)?(a):(b))
	#define abS(x)                      ((x)<0?-(x):(x))
	#define	forr(i,a,b)                 for(int i=a;i<b;i++)
	#define rep(i,n)                    forr(i,0,n) 
	#define pn()                        printf("\n")
	#define pi(n)                       printf("%d",n)
	#define pll(n)                      printf("%lld",n)
	#define pd(n)                       printf("%lf",n)
	#define ps(str)                     printf("%s",str)

	//macros stl

	#define mp                          make_pair
	#define tri(a,b,c)                  mp(a,mp(b,c))
	#define pb                          push_back
	#define fill(a,v)                   memset(a,v,sizeof a)
	#define all(x)                      x.begin(),x.end()
	#define uniq(v)                     sort(all(v));v.erase(unique(all(v)),v.end())
	#define findval(arr,val)            (lower_bound(all(arr)),val)-arr.begin()
	#define clr(a)                      memset(a,0,sizeof a)

	//Translator

	bool isUpperCase(char c){return c>='A' && c<='Z';}
	bool isLowerCase(char c){return c>='a' && c<='z';}
	bool isLetter(char c){return c>='A' && c<='Z' || c>='a' && c<='z';}
	bool isDigit(char c){return c>='0' && c<='9';}
	char toLowerCase(char c){return (isUpperCase(c))?(c+32):c;}
	char toUpperCase(char c){return (isLowerCase(c))?(c-32):c;}

	//debug

	#define debug                       if(1)
	#define debugoff                    if(0)	

	//constants

	#define PI                          M_PI
	#define E                           M_E
	using namespace std;

	//typedef

	typedef long long LL;
	typedef unsigned long long uLL;
	typedef pair<int,int> pii;
	typedef pair<LL,LL> pll;
	typedef pair<int,pii> tri;

	//FAST IO

	#define sync ios::sync_with_stdio(false);	
	#define untie cin.tie(NULL);
	#define endll '\n'
	//#define input(n) readInt(&n)
	
	inline void readNat(int *x)
	{
		register int c = gc();
		*x = 0;
		for(;(c<48 || c>57);c = gc());//ignore whitespace in front
		//2x + 8x = 10x  optimisation
	 		for(;c>47 && c<58;c = gc()) {*x = (*x<<1) + (*x<<3) + c - 48;}
	}
	inline void readInt(int &x)
	{
	    register int c = gc();
	    x = 0;
	    int neg = 0;
	    for(;((c<48 || c>57) && c != '-');c = gc());
	    if(c=='-') {neg=1;c=gc();}
	    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
	    if(neg) x=-x;
	}
	inline void read_string(char *str)
	{
		register char c = 0;
		register int i = 0;
	 
		while (c < 33)
			c = getchar_unlocked();
	 
		while (c != '\n') 
		{
			str[i] = c;
			c = getchar_unlocked();
			i = i + 1;
		}
	 
		str[i] = '\0';
	}
		
	#define MAX 1000010
	#define MOD 1000000007

	int main()
	{
		int t;
		int n;
		si(t);
		while(t--)
		{
			si(n);
				${1}	
		}
		return  0;
	}	 



snippet temp1
	#include <iostream>
	#include <cstdio>
	#include <algorithm>
	#include <cstring>
	#include <sstream>
	#include <vector>
	#include <iomanip>
	#include <cmath>
	#include <set>
	#include <map>
	#include <queue>

	using namespace std;
	typedef long long LL;
	typedef pair<int,int> pii;
	typedef pair<int,pair<int,int> > tri;
	typedef vector<vector<int> > vvi;
	typedef vector<int> vi;
	typedef vector< pii > vpii;

	#define pb push_back
	#define mp make_pair
	#define sz size()
	#define ln length()
	#define forr(i,a,b)                 for(int i=a;i<b;i++)
	#define fore(i,a,b)                 for(int i=a;i<=b;i++)
	#define rep(i,n)                    forr(i,0,n)
	#define all(v)                      v.begin(),v.end()
	#define uniq(v)                 	sort(all(v));v.erase(unique(all(v)),v.end())
	#define clr(a)                      memset(a,0,sizeof a)

	#define debug                       if(1)
	#define debugoff                    if(0)

	#define print(x)                 cerr << x << " ";
	#define pn()                     cerr << endl;
	#define trace1(x)                cerr << #x << ": " << x << endl;
	#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
	#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;

	ostream& operator<<(ostream& out,vi& v)
	{
		for(int x=0;x<v.size();x++)
			out << v[x];
		out << endl;
		return out;
	}
	ostream& operator<<(ostream& out,vvi& v)
	{
		int n = v.size();
		int m = v[0].size();
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++)
				out<<v[i][j]<<" ";
			out<<endl;
		}
		return out;
	}

	void print_arr(int arr[],int n)
	{
		for(int i=0;i<n;i++)
			cout<<arr[i]<<" ";
		cout<<endl;
	}

	void print_arr2d(int arr2[][20],int n,int m)
	{
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++)
				cout<<arr2[i][j]<<" ";
			cout<<endl;
		}
	}

	void print_vi(vi& v,int n)
	{
		for(int i=0;i<n;i++)
			cout<<v[i]<<" ";
		cout<<endl;
	}

	void print_vii(vvi& v,int n,int m)
	{
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++)
				cout<<v[i][j]<<" ";
			cout<<endl; 
		}
	}

	string end = "============******=============\n";

	#define MAX 9
	#define MOD 1000000007
	vi inner(MAX,0);
	//vvi a(MAX,inner);
	//vvi cumm(MAX,inner);
	//vvi cummb(MAX,inner);

	int main()
	{
		ios::sync_with_stdio(false);
		int n;
		cin>>n;
		${1}
		
		return 0; 
	}


snippet temp3
	/*******************************
	// Author : Abdul Qadir Faridi
	// IPG-3rd yr
	// Institute : ABV-IIITM,Gwalior
	*********************************/

	//header files

	#include <iostream>
	#include <cstdio>
	#include <cstring>
	#include <cmath>
	#include <cstdlib>
	#include <climits>
	#include <cassert>
	#include <iomanip>
	#include <vector>
	#include <utility>
	#include <map>
	#include <set>
	#include <list>
	#include <stack>
	#include <queue>
	#include <deque>
	#include <bitset>
	#include <complex>
	#include <numeric>
	#include <functional>
	#include <sstream>
	#include <algorithm>
	
	//Preprocessor directives
	
	#define gc getchar_unlocked
	
	//macros input-output

	#define si(n)                       scanf("%d",&n)
	#define sll(n)                      scanf("%lld",&n)
	#define sf(n)                       scanf("%f",&n)
	#define ss(str)                     scanf("%s",str)
	#define sd(n)                       scanf("%lf",&n)
	#define INF                         INT_MAX
	#define LINF                        (LL)1e18
	#define maX(a,b)                    ((a)>(b)?(a):(b))
	#define miN(a,b)                    ((a)<(b)?(a):(b))
	#define abS(x)                      ((x)<0?-(x):(x))
	#define	forr(i,a,b)                 for(int i=a;i<b;i++)
	#define rep(i,n)                    forr(i,0,n) 
	#define pn()                        printf("\n")
	#define pi(n)                       printf("%d",n)
	#define pll(n)                      printf("%lld",n)
	#define pd(n)                       printf("%lf",n)
	#define ps(str)                     printf("%s",str)

	//macros stl

	#define mp                          make_pair
	#define tri(a,b,c)                  mp(a,mp(b,c))
	#define pb                          push_back
	#define fill(a,v)                   memset(a,v,sizeof a)
	#define all(x)                      x.begin(),x.end()
	#define uniq(v)                     sort(all(v));v.erase(unique(all(v)),v.end())
	#define findval(arr,val)            (lower_bound(all(arr)),val)-arr.begin()
	#define clr(a)                      memset(a,0,sizeof a)

	//Translator

	bool isUpperCase(char c){return c>='A' && c<='Z';}
	bool isLowerCase(char c){return c>='a' && c<='z';}
	bool isLetter(char c){return c>='A' && c<='Z' || c>='a' && c<='z';}
	bool isDigit(char c){return c>='0' && c<='9';}
	char toLowerCase(char c){return (isUpperCase(c))?(c+32):c;}
	char toUpperCase(char c){return (isLowerCase(c))?(c-32):c;}

	//debug

	#define debug                       if(1)
	#define debugoff                    if(0)	

	//constants

	#define PI                          M_PI
	#define E                           M_E
	using namespace std;

	//typedef

	typedef long long LL;
	typedef unsigned long long uLL;
	typedef pair<int,int> pii;
	typedef pair<LL,LL> pll;
	typedef pair<int,pii> tri;

	#define MAX 1000010
	#define MOD 1000000007
		
	int main()
	{
		int t;
		int n;
		si(t);
		while(t--)
		{
			si(n);
				${1}	
		}
		return  0;
	}

snippet temp4

	/*******************************
	// Author : Abdul Qadir Faridi
	// IPG-3rd yr
	// Institute : ABV-IIITM,Gwalior
	*********************************/

	//header files

	#include <iostream>
	#include <cstdio>
	#include <cstring>
	#include <cmath>
	#include <cstdlib>
	#include <climits>
	#include <cassert>
	#include <iomanip>
	#include <vector>
	#include <utility>
	#include <map>
	#include <set>
	#include <list>
	#include <stack>
	#include <queue>
	#include <deque>
	#include <bitset>
	#include <complex>
	#include <numeric>
	#include <functional>
	#include <sstream>
	#include <algorithm>
	
	//Preprocessor directives
	
	#define gc getchar_unlocked
	
	//macros input-output

	#define si(n)                       scanf("%d",&n)
	#define sll(n)                      scanf("%I64",&n)
	#define sf(n)                       scanf("%f",&n)
	#define ss(str)                     scanf("%s",str)
	#define sd(n)                       scanf("%lf",&n)
	#define INF                         INT_MAX
	#define LINF                        (LL)1e18
	#define maX(a,b)                    ((a)>(b)?(a):(b))
	#define miN(a,b)                    ((a)<(b)?(a):(b))
	#define abS(x)                      ((x)<0?-(x):(x))
	#define	forr(i,a,b)                 for(int i=a;i<b;i++)
	#define rep(i,n)                    forr(i,0,n) 
	#define pn()                        printf("\n")
	#define pi(n)                       printf("%d",n)
	#define pll(n)                      printf("%I64",n)
	#define pd(n)                       printf("%lf",n)
	#define ps(str)                     printf("%s",str)

	//macros stl

	#define mp                          make_pair
	#define tri(a,b,c)                  mp(a,mp(b,c))
	#define pb                          push_back
	#define fill(a,v)                   memset(a,v,sizeof a)
	#define all(x)                      x.begin(),x.end()
	#define uniq(v)                     sort(all(v));v.erase(unique(all(v)),v.end())
	#define findval(arr,val)            (lower_bound(all(arr)),val)-arr.begin()
	#define clr(a)                      memset(a,0,sizeof a)

	//Translator

	bool isUpperCase(char c){return c>='A' && c<='Z';}
	bool isLowerCase(char c){return c>='a' && c<='z';}
	bool isLetter(char c){return c>='A' && c<='Z' || c>='a' && c<='z';}
	bool isDigit(char c){return c>='0' && c<='9';}
	char toLowerCase(char c){return (isUpperCase(c))?(c+32):c;}
	char toUpperCase(char c){return (isLowerCase(c))?(c-32):c;}

	//debug

	#define debug                       if(1)
	#define debugoff                    if(0)	

	//constants

	#define PI                          M_PI
	#define E                           M_E
	using namespace std;

	//typedef

	typedef long long LL;
	typedef unsigned long long uLL;
	typedef pair<int,int> pii;
	typedef pair<LL,LL> pll;
	typedef pair<int,pii> tri;

	#define MAX 1000010
	#define MOD 1000000007
		
	int main()
	{
		int t;
		int n;
		si(t);
		while(t--)
		{
			si(n);
				${1}	
		}
		return  0;
	}
snippet translator

	bool isUpperCase(char c){return c>='A' && c<='Z';}
	bool isLowerCase(char c){return c>='a' && c<='z';}
	bool isLetter(char c){return c>='A' && c<='Z' || c>='a' && c<='z';}
	bool isDigit(char c){return c>='0' && c<='9';}
	char toLowerCase(char c){return (isUpperCase(c))?(c+32):c;}
	char toUpperCase(char c){return (isLowerCase(c))?(c-32):c;}

snippet temp5
	#include <iostream>
	#include <cstdio>
	#include <algorithm>
	#include <cstring>
	#include <sstream>
	#include <vector>
	#include <iomanip>
	#include <cmath>
	#include <set>
	#include <map>
	#include <queue> 
	#include <climits>
	#include <cassert>

	using namespace std;
	typedef long long LL;
	typedef pair<int,int> pii;
	
	#define pb push_back
	#define mp make_pair
	#define sz size()
	#define ln length()
	#define forr(i,a,b)                 for(int i=a;i<b;i++)
	#define rep(i,n)                    forr(i,0,n) 
	#define all(v)                      v.begin(),v.end()	
	#define uniq(v)                     sort(all(v));v.erase(unique(all(v)),v.end())
	#define clr(a)                      memset(a,0,sizeof a)
		
	#define debug                       if(1)
	#define debugoff                    if(0)	

	#define print(x)                 cerr << x << " ";    
	#define pn()				     cerr << endl;
	#define trace1(x)                cerr << #x << ": " << x << endl;
	#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
	#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
	
	#define MAX 100010
	#define MOD 1000000007
	
	int main()
	{
		ios::sync_with_stdio(false);
		int t,n;
		cin>>t;
		while(t--)
		{
			cin>>n;
			${1}
		}
		return 0; 
	}

snippet temp6
	/*
	ID: aqfari1
	PROG: ride
	LANG: C++
	*/

	#include <iostream>
	#include <cstdio>
	#include <algorithm>
	#include <cstring>
	#include <sstream>
	#include <vector>
	#include <iomanip>
	#include <cmath>
	#include <set>
	#include <map>
	#include <queue> 
	#include <climits>
	#include <cassert>
	#include <fstream>

	using namespace std;
	typedef long long LL;
	typedef pair<int,int> pii;
	
	#define pb push_back
	#define mp make_pair
	#define sz size()
	#define ln length()
	#define forr(i,a,b)                 for(int i=a;i<b;i++)
	#define rep(i,n)                    forr(i,0,n) 
	#define all(v)                      v.begin(),v.end()	
	#define uniq(v)                     sort(all(v));v.erase(unique(all(v)),v.end())
	#define clr(a)                      memset(a,0,sizeof a)
		
	#define debug                       if(1)
	#define debugoff                    if(0)	

	#define print(x)                 cerr << x << " ";    
	#define pn()				     cerr << endl;
	#define trace1(x)                cerr << #x << ": " << x << endl;
	#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
	#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
	
	#define MAX 100010
	#define MOD 1000000007
	
	int main()
	{
	    ofstream fout("ride.out");
	    ifstream fin("ride.in");
		int t,n;
		fin>>t;
		//fout<<t;
		while(t--)
		{
			fin>>n;
			${1}
		}
		return 0; 
	}
snippet simpleBIT
	template<class T>
	class simpleBIT
	{
		T *tree;
		int maxVal;
		public:
		simpleBIT(int N)
		{
			tree = new T[N+1];
			memset(tree,0,sizeof(T)*(N+1));
			maxVal = N;
		}
		void update(int idx,T val)
		{
			while(idx <= maxVal)
			{
				tree[idx] += val;
				idx += (idx & -idx);
			}
		}
		
		T query(int idx)
		{
			T sum = 0;
			while(idx > 0)
			{
				sum += tree[idx];
				idx -= (idx & -idx);
			}
			return sum;
		}
		
		T readSingle(int idx)
		{
			T sum = tree[idx];
			if(idx > 0)
			{
				int z = idx - (idx & -idx);
				idx--;
				while(idx != z)
				{
					sum -= tree[idx];
					idx -= (idx & -idx);
				}
			}
			return sum;
		}
	};
	
snippet BIT
	template<class T>
	class BIT
	{
		T *tree1,*tree2;
		int maxVal;
		public:
		BIT(int N)
		{
			tree1 = new T[N+1];
			tree2 = new T[N+1];
			memset(tree1,0,sizeof(T)*(N+1));
			memset(tree2,0,sizeof(T)*(N+1));
			maxVal = N;
		}
		void update(int idx,T val)
		{
			int var = idx - 1; // var can be a or b
			while(idx <= maxVal)
			{
				tree1[idx] += val;
				tree2[idx] += val*var;
				idx += (idx & -idx);
			}            
		}
		void update_range(int a,int b,T val)
		{
			update(a,val);
			update(b+1,-val);
		}
		T cumm_freq(int idx)
		{
			T sum1 = 0,sum2 = 0;
			int p = idx;
			while(idx > 0)
			{
				sum1 += tree1[idx];
				sum2 += tree2[idx];
				idx -= (idx & -idx);
			}
			return (sum1 * p - sum2);
		}
		T get_freq(int idx)
		{
			T freq = 0;
			while(idx > 0)
			{
				freq += tree1[idx];
				idx -= (idx & -idx);
			}
			return freq;
		}
	};
snippet suffixArray
	namespace suffixArray
	{
				
		#define MAX 1000010
		#define rep(i,n) for(int i=0;i<n;i++)
		int n,gap;
		int sa[MAX],pos[MAX],tmp[MAX],lcp[MAX];
		char str[100010];
		bool cmp(int i,int j)
		{
			if(pos[i] != pos[j])
				return pos[i]<pos[j];
			i+=gap;j+=gap;
			return (i<n && j<n) ? pos[i]<pos[j] : i>j;//if ith pos reached end then return 1(i>j) since ith is smaller
		}
		void buildSA()
		{
			n = strlen(str);
			rep(i,n)    sa[i] = i , pos[i] = str[i];//ascii value in pos firsttime
			for(gap = 1;;gap*=2)
			{
				sort(sa,sa+n,cmp);
				rep(i,n-1)  
					tmp[i+1] = tmp[i] + cmp(sa[i],sa[i+1]);//lexo. names acc.to pos(prev)::increment by 1 when diff occurs
				rep(i,n)
					pos[sa[i]] = tmp[i];//pos updated by rank
			
				//terminating condition
				if(tmp[n-1] == n-1) break;//all rank assigned no further changes in tmp
			}
		}
		void buildLCP()
		{
			for(int i=0,k=0 ; i<n ; i++)
			{
				if(pos[i] != n-1)//no adjacent suffix exists
				{
					for(int j = sa[ (pos[i]+1) ] ; str[i+k] == str[j+k];)
					{
						++k;
					}
					lcp[pos[i]] = k;
					if(k)//next lcp(suffix and its adj.) is atleast k-1 
						--k;
				}        
			}
		}

	} 
snippet KMP

	namespace KMP
	{
		#define MAX 1000010
		int b[MAX],m,n;
		void LPS(string pat)
		{
			int i=0,j=-1;//j => border
			m = pat.length();
			b[i] = j;
			while(i<m)
			{
				while(j>=0 && pat[i]!=pat[j]) j=b[j];//next widest border
				i++;j++;
				b[i] = j;
			}
		}
		void kmpSearch(string txt,string pat)
		{	
			int i=0,j=0;
			n = txt.length();
			while(i<n)
			{
				while(j>=0 && txt[i]!=pat[j]) j=b[j];//next widest border of some prefix of pat
				i++;j++;
				if(j==m)
				{
					printf("%d\n",(i-j));
					j = b[j]; //widest border of pat
				}
			}			
		}
	}
snippet sieve
	namespace sieve
	{
		#define MAX 1000010
		#define LIM 1000
		#define PRM 78500
		unsigned flag[MAX >> 6];
		unsigned segment[MAX >> 6];
		LL primes[PRM];
		#define ifc(n) (flag[n>>6] & (1<<((n>>1)&31)))
		#define isc(n) (flag[n>>6] |= (1<<((n>>1)&31)))
		#define seg_ifc(n) (segment[n>>6] & (1<<((n>>1)&31)))
		#define seg_isc(n) (segment[n>>6] |= (1<<((n>>1)&31)))
		void make_sieve()
		{
			unsigned i,j,k;
			isc(1);
			for(i=3;i<=LIM;i+=2)
			{
				if(!ifc(i))
					for(j=i*i,k=(i<<1);j<MAX;j+=k)
						isc(j);
			}
			primes[0] = 2;
			for(i=3,k=1;i<MAX;i+=2)
				if(!ifc(i))
					primes[k++] = i;
			/*
			for(int i=0;i<100;i++)
				cout<<primes[i]<<" ";
			cout<<k<<endl;
			*/
		}
		LL segmented_sieve(LL a,LL b)
		{
			memset(segment,0,sizeof(segment));
			//handle 2 separately
			LL i,j,k,cnt = (a<=2 && b>=2)? 1 : 0;
			if(b<2) return 0;
			if(a<3) a=3;
			if(!(a&1)) a++;
			for(i=1;(primes[i]*primes[i])<=b;i++)
			{
				j = primes[i] * ((a+primes[i]-1)/primes[i]);
				if(!(j&1)) j += primes[i];
				for(k=(primes[i]<<1);j<=b;j+=k)
					if(j!=primes[i])
						seg_isc(j-a);
			}

			for(i=0;i<=(b-a);i+=2)
				if(!seg_ifc(i))
				{
					//cout<<a+i<<endl;
					cnt++;
				}
			return cnt;
		}
	}
snippet segmentTree
	namespace segmentTree
	{
		#define MAX 50010
		int input[MAX];
		struct data
		{
			int sum,Lmax,Rmax,maxv;
		};
		data tree[3*MAX];
		data combine_data(data left,data right)
		{
			data res;
			res.sum = left.sum + right.sum;
			res.Lmax = max(left.Lmax,left.sum + right.Lmax);
			res.Rmax = max(right.Rmax,right.sum + left.Rmax);
			res.maxv = max(max(left.maxv,right.maxv),left.Rmax+right.Lmax);
			return res;
		}
		data make_data(int val)
		{
			data res;
			//res.Lmax = res.Rmax = res.maxv = max(0,val);//for getting 0 ans
			//when all numbers are negative
			//res.sum = val;
			res.Lmax = res.Rmax = res.maxv = res.sum = val;
			return res;
		}
		void init_tree(int node,int b,int e)
		{
			if(b==e) // leaf node
			{
				tree[node] = make_data(input[b]);
				return ;
			}
			int mid = (b+e)/2;
			init_tree(2*node,b,mid);
			init_tree(2*node+1,mid+1,e);
			tree[node] = combine_data(tree[2*node],tree[2*node+1]);
		}
		void update(int node,int b,int e,int index,int newval)
		{
			if(b==e)
			{
				tree[node] = make_data(newval);
				return ;
			}

			int mid = (b+e)/2;
			// go to left or right child acc to mid in the search of
			// indexleafnode
			if(index<=mid)
				update(2*node,b,mid,index,newval);
			else
				update(2*node+1,mid+1,e,index,newval);

			tree[node] = combine_data(tree[2*node],tree[2*node+1]);
		}
		data query(int node,int b,int e,int i,int j)    
		{
			if(b>=i &&  e<=j)//in range   
				return tree[node];
			
			//out of range ?? what to return( 0 , INT_MIN  nothing ) ?? 
			//not sure,  So go to left or right child acc to mid
			int mid = (b+e)/2;
			if(j<=mid)
				return query(2*node,b,mid,i,j);
			else if(i>mid)//not else if ?? can go to both sides
				return query(2*node+1,mid+1,e,i,j);
			/***********out of range condition finished**********/
			data p1 = query(2*node,b,mid,i,j);
			data p2 = query(2*node+1,mid+1,e,i,j);
			
			return combine_data(p1,p2);
		}


	}
snippet trie
	namespace trie
	{
		#define size 10
		char ch='0';
		struct node
		{
			int words;
			int prefixes;
			node* child[size];
		};

		node* init_root()
		{
			node* root = new node;
			for(int i=0;i<size;i++)
				root -> child[i] = NULL;
			root -> words = 0;
			root -> prefixes = 0;

			return root;
		}

		node* addNode()
		{
			node* temp = new node;
			for(int i=0;i<size;i++)
				temp -> child[i] = NULL;
			temp -> words = 0;
			temp -> prefixes = 0;    
			return temp;
		}
		
		void addWord(node* root,string str)
		{
			int l = str.length(),idx;
			node* curr = root;
			node* parent = root;

			for(int i=0;i<l;i++)
			{
				idx = str[i] - ch;
				parent = curr;
				curr = curr -> child[idx];
				if(curr == NULL)
					parent->child[idx] = addNode();
				curr = parent -> child[idx];
				curr ->prefixes++;
				if(i == l-1)
					curr -> words++;
			}
		}

		int findWord(node* root,string str)
		{
			node* curr = root;
			int idx,l = str.length();
			for(int i=0;i<l;i++)
			{
				idx = str[i]- ch;
				curr = curr -> child[idx];
				if(curr == NULL)
					return 0;
			}
			return curr->words;
		}

		int countPrefix(node* root,string prefix)
		{
			node* curr = root;
			int idx,l = prefix.length();
			for(int i=0;i<l;i++)
			{
				idx = prefix[i] - ch;
				curr = curr -> child[idx];
				if(curr == NULL)
					return 0;
			}
			return curr -> prefixes;
		}

		int chkWord(node* root,string prefix)
		{
			node* curr = root;
			node* parent = root;
			int idx,l = prefix.length();
			for(int i=0;i<l;i++)
			{
				idx = prefix[i] - ch;
				parent = curr;
				curr = curr -> child[idx];
				if(curr == NULL)
					return (parent -> words);
			}
			return curr -> prefixes;
		}
	}
snippet manacher
	namespace manacher
	{
		#define MAX 100010
		int P[MAX],n,cnt;
		string s;
		//append ^$ to avoid bound check
		string make_T()
		{
			int n = s.length();
			if(n==0)    return "^$";
			string ret = "^";
			for(int i=0;i<n;i++)
				ret += ("#" + s.substr(i,1));
		
			ret += "#$";

			return ret;
		}

		void make_P()
		{
			string T = make_T();
			n = T.length();
			int C = 0 , R = 0;
			for(int i=1;i<n-1;i++)
			{
				int i_mirror = C - (i-C);
				P[i] = (R>i) ? min(R-i,P[i_mirror]) : 0;//if i is after R then initialize P[i] =0
				//expand palin centered at i
				while(T[i+1+P[i]] == T[i-1-P[i]])
					P[i]++;
				//if palin centered at i expand past R,
				//adjust new center and new Right Edge
				if(i+P[i] > R)
				{
					C = i;
					R = i + P[i];
				}
		   } 
		}

		string LPSub()
		{
			int maxlen = 0;
			int center = 0;
			for(int i=1;i<n-1;i++)
			{
				if(P[i] > maxlen)
				{
					maxlen = P[i];
					center = i;
				}
			}
			return s.substr((center-1-maxlen)/2,maxlen);
		}

		int count_all()
		{
			cnt = 0;
			for(int i=1;i<n-1;i++)
				cnt += (P[i]+1)/2;
			return cnt;
		}
		void print_all()
		{
			int center,l;
			for(int i=1;i<n-1;i++)
			{
				center = i;
				l = 2;
				if(P[i] & 1)
					l = 1;
				for(;l<=P[i];l+=2)
					cout<<s.substr((center-1-l)/2,l)<<endl;
				
			}
		}

		void process_all()
		{
			int center,l;
			for(int i=1;i<n-1;i++)
			{
				center = i;
				l = 2;
				if(P[i] & 1)
					l = 1;
				for(;l<=P[i];l+=2)
				{
					//process length of each palin = l
					
				}
				
			}
		}

	}
snippet suffix_automation
	namespace suffix_automation
	{
		struct state 
		{
			int len,link;
			map<char,int> next;
		}; 
		
		const int MAXLEN = 250020;
		state st[MAXLEN*2];
		int sz,last; 
		void sa_init() 
		{
			sz = last = 0;
			st[0].len = 0;
			st[0].link = -1;
			sz++;
		 }

		void sa_extend(char c) 
		{
			int cur = sz++;
			st[cur].len = st[last].len + 1;
			int p;
			for(p = last; p != -1 && !st[p].next.count(c);p = st[p].link)
				st[p].next[c] = cur;
			if (p == -1)
				st[cur].link = 0;
			else 
			{
				int q = st[p].next[c];
				if(st[p].len + 1 == st[q].len)
					st[cur].link = q;
				else
				{
					int clone = sz++;
					st[clone].len = st[p].len + 1;
					st[clone].next = st[q].next;
					st[clone].link = st[q].link;
					for(;p != -1 && st[p].next[c] == q ; p = st[p].link)
						st[p].next[c] = clone;
					st[q].link = st[cur].link = clone;
				}
			}
			last = cur;
		}

		int lcs(char* s,char* t)
		{
			int l1 = strlen(s);
			int l2 = strlen(t);
			sa_init( );
			for(int i=0;i < l1;i++)
				sa_extend(s[i]);
					 
			int v = 0,l = 0,best = 0,bestpos = 0;
			for(int i=0;i < l2;i++) 
			{
				while(v && !st[v].next.count(t[i])) 
				{
					v = st[v].link;
					l = st[v].len;
				}

				if(st[v].next.count(t[i])) 
				{
					v = st[v].next[t[i]];
					++l;
				}
				if(l > best)
					best = l,bestpos = i;
			}
			return best;
		}
	} 
snippet readNat
	#define gc getchar_unlocked
	inline void readNat(int *x)
	{
		register int c = gc();
		*x = 0;
		for(;(c<48 || c>57);c = gc());//ignore whitespace in front
		//2x + 8x = 10x  optimisation
	 		for(;c>47 && c<58;c = gc()) {*x = (*x<<1) + (*x<<3) + c - 48;}
	}

snippet bigint
	// base and base_digits must be consistent
	const int base = 1000000000;
	const int base_digits = 9;

	struct bigint {
		vector<int> a;
		int sign;

		bigint() :
			sign(1) {
		}

		bigint(long long v) {
			*this = v;
		}

		bigint(const string &s) {
			read(s);
		}

		void operator=(const bigint &v) {
			sign = v.sign;
			a = v.a;
		}

		void operator=(long long v) {
			sign = 1;
			if (v < 0)
				sign = -1, v = -v;
			for (; v > 0; v = v / base)
				a.push_back(v % base);
		}

		bigint operator+(const bigint &v) const {
			if (sign == v.sign) {
				bigint res = v;

				for (int i = 0, carry = 0; i < (int) max(a.size(), v.a.size()) || carry; ++i) {
					if (i == (int) res.a.size())
						res.a.push_back(0);
					res.a[i] += carry + (i < (int) a.size() ? a[i] : 0);
					carry = res.a[i] >= base;
					if (carry)
						res.a[i] -= base;
				}
				return res;
			}
			return *this - (-v);
		}

		bigint operator-(const bigint &v) const {
			if (sign == v.sign) {
				if (abs() >= v.abs()) {
					bigint res = *this;
					for (int i = 0, carry = 0; i < (int) v.a.size() || carry; ++i) {
						res.a[i] -= carry + (i < (int) v.a.size() ? v.a[i] : 0);
						carry = res.a[i] < 0;
						if (carry)
							res.a[i] += base;
					}
					res.trim();
					return res;
				}
				return -(v - *this);
			}
			return *this + (-v);
		}

		void operator*=(int v) {
			if (v < 0)
				sign = -sign, v = -v;
			for (int i = 0, carry = 0; i < (int) a.size() || carry; ++i) {
				if (i == (int) a.size())
					a.push_back(0);
				long long cur = a[i] * (long long) v + carry;
				carry = (int) (cur / base);
				a[i] = (int) (cur % base);
				//asm("divl %%ecx" : "=a"(carry), "=d"(a[i]) : "A"(cur), "c"(base));
			}
			trim();
		}

		bigint operator*(int v) const {
			bigint res = *this;
			res *= v;
			return res;
		}

		friend pair<bigint, bigint> divmod(const bigint &a1, const bigint &b1) {
			int norm = base / (b1.a.back() + 1);
			bigint a = a1.abs() * norm;
			bigint b = b1.abs() * norm;
			bigint q, r;
			q.a.resize(a.a.size());

			for (int i = a.a.size() - 1; i >= 0; i--) {
				r *= base;
				r += a.a[i];
				int s1 = r.a.size() <= b.a.size() ? 0 : r.a[b.a.size()];
				int s2 = r.a.size() <= b.a.size() - 1 ? 0 : r.a[b.a.size() - 1];
				int d = ((long long) base * s1 + s2) / b.a.back();
				r -= b * d;
				while (r < 0)
					r += b, --d;
				q.a[i] = d;
			}

			q.sign = a1.sign * b1.sign;
			r.sign = a1.sign;
			q.trim();
			r.trim();
			return make_pair(q, r / norm);
		}

		bigint operator/(const bigint &v) const {
			return divmod(*this, v).first;
		}

		bigint operator%(const bigint &v) const {
			return divmod(*this, v).second;
		}

		void operator/=(int v) {
			if (v < 0)
				sign = -sign, v = -v;
			for (int i = (int) a.size() - 1, rem = 0; i >= 0; --i) {
				long long cur = a[i] + rem * (long long) base;
				a[i] = (int) (cur / v);
				rem = (int) (cur % v);
			}
			trim();
		}

		bigint operator/(int v) const {
			bigint res = *this;
			res /= v;
			return res;
		}

		int operator%(int v) const {
			if (v < 0)
				v = -v;
			int m = 0;
			for (int i = a.size() - 1; i >= 0; --i)
				m = (a[i] + m * (long long) base) % v;
			return m * sign;
		}

		void operator+=(const bigint &v) {
			*this = *this + v;
		}
		void operator-=(const bigint &v) {
			*this = *this - v;
		}
		void operator*=(const bigint &v) {
			*this = *this * v;
		}
		void operator/=(const bigint &v) {
			*this = *this / v;
		}

		bool operator<(const bigint &v) const {
			if (sign != v.sign)
				return sign < v.sign;
			if (a.size() != v.a.size())
				return a.size() * sign < v.a.size() * v.sign;
			for (int i = a.size() - 1; i >= 0; i--)
				if (a[i] != v.a[i])
					return a[i] * sign < v.a[i] * sign;
			return false;
		}

		bool operator>(const bigint &v) const {
			return v < *this;
		}
		bool operator<=(const bigint &v) const {
			return !(v < *this);
		}
		bool operator>=(const bigint &v) const {
			return !(*this < v);
		}
		bool operator==(const bigint &v) const {
			return !(*this < v) && !(v < *this);
		}
		bool operator!=(const bigint &v) const {
			return *this < v || v < *this;
		}

		void trim() {
			while (!a.empty() && !a.back())
				a.pop_back();
			if (a.empty())
				sign = 1;
		}

		bool isZero() const {
			return a.empty() || (a.size() == 1 && !a[0]);
		}

		bigint operator-() const {
			bigint res = *this;
			res.sign = -sign;
			return res;
		}

		bigint abs() const {
			bigint res = *this;
			res.sign *= res.sign;
			return res;
		}

		long long longValue() const {
			long long res = 0;
			for (int i = a.size() - 1; i >= 0; i--)
				res = res * base + a[i];
			return res * sign;
		}

		friend bigint gcd(const bigint &a, const bigint &b) {
			return b.isZero() ? a : gcd(b, a % b);
		}
		friend bigint lcm(const bigint &a, const bigint &b) {
			return a / gcd(a, b) * b;
		}

		void read(const string &s) {
			sign = 1;
			a.clear();
			int pos = 0;
			while (pos < (int) s.size() && (s[pos] == '-' || s[pos] == '+')) {
				if (s[pos] == '-')
					sign = -sign;
				++pos;
			}
			for (int i = s.size() - 1; i >= pos; i -= base_digits) {
				int x = 0;
				for (int j = max(pos, i - base_digits + 1); j <= i; j++)
					x = x * 10 + s[j] - '0';
				a.push_back(x);
			}
			trim();
		}

		friend istream& operator>>(istream &stream, bigint &v) {
			string s;
			stream >> s;
			v.read(s);
			return stream;
		}

		friend ostream& operator<<(ostream &stream, const bigint &v) {
			if (v.sign == -1)
				stream << '-';
			stream << (v.a.empty() ? 0 : v.a.back());
			for (int i = (int) v.a.size() - 2; i >= 0; --i)
				stream << setw(base_digits) << setfill('0') << v.a[i];
			return stream;
		}

		static vector<int> convert_base(const vector<int> &a, int old_digits, int new_digits) {
			vector<long long> p(max(old_digits, new_digits) + 1);
			p[0] = 1;
			for (int i = 1; i < (int) p.size(); i++)
				p[i] = p[i - 1] * 10;
			vector<int> res;
			long long cur = 0;
			int cur_digits = 0;
			for (int i = 0; i < (int) a.size(); i++) {
				cur += a[i] * p[cur_digits];
				cur_digits += old_digits;
				while (cur_digits >= new_digits) {
					res.push_back(int(cur % p[new_digits]));
					cur /= p[new_digits];
					cur_digits -= new_digits;
				}
			}
			res.push_back((int) cur);
			while (!res.empty() && !res.back())
				res.pop_back();
			return res;
		}

		typedef vector<long long> vll;

		static vll karatsubaMultiply(const vll &a, const vll &b) {
			int n = a.size();
			vll res(n + n);
			if (n <= 32) {
				for (int i = 0; i < n; i++)
					for (int j = 0; j < n; j++)
						res[i + j] += a[i] * b[j];
				return res;
			}

			int k = n >> 1;
			vll a1(a.begin(), a.begin() + k);
			vll a2(a.begin() + k, a.end());
			vll b1(b.begin(), b.begin() + k);
			vll b2(b.begin() + k, b.end());

			vll a1b1 = karatsubaMultiply(a1, b1);
			vll a2b2 = karatsubaMultiply(a2, b2);

			for (int i = 0; i < k; i++)
				a2[i] += a1[i];
			for (int i = 0; i < k; i++)
				b2[i] += b1[i];

			vll r = karatsubaMultiply(a2, b2);
			for (int i = 0; i < (int) a1b1.size(); i++)
				r[i] -= a1b1[i];
			for (int i = 0; i < (int) a2b2.size(); i++)
				r[i] -= a2b2[i];

			for (int i = 0; i < (int) r.size(); i++)
				res[i + k] += r[i];
			for (int i = 0; i < (int) a1b1.size(); i++)
				res[i] += a1b1[i];
			for (int i = 0; i < (int) a2b2.size(); i++)
				res[i + n] += a2b2[i];
			return res;
		}

		bigint operator*(const bigint &v) const {
			vector<int> a6 = convert_base(this->a, base_digits, 6);
			vector<int> b6 = convert_base(v.a, base_digits, 6);
			vll a(a6.begin(), a6.end());
			vll b(b6.begin(), b6.end());
			while (a.size() < b.size())
				a.push_back(0);
			while (b.size() < a.size())
				b.push_back(0);
			while (a.size() & (a.size() - 1))
				a.push_back(0), b.push_back(0);
			vll c = karatsubaMultiply(a, b);
			bigint res;
			res.sign = sign * v.sign;
			for (int i = 0, carry = 0; i < (int) c.size(); i++) {
				long long cur = c[i] + carry;
				res.a.push_back((int) (cur % 1000000));
				carry = (int) (cur / 1000000);
			}
			res.a = convert_base(res.a, 6, base_digits);
			res.trim();
			return res;
		}
	};
	bigint modulo(bigint a,bigint n,bigint m)
	{
		bigint result = 1;
		while(n>0)
		{
			if(n%2 == 1)
				result = (result*a)%m;
			a = (a*a)%m;
			n /= 2;
		}
		return (result + m)%m;
	}

snippet fastio
	int scan_d() 
	{
		int ip=getchar_unlocked(),ret=0,flag=1;
		for(;ip<'0'||ip>'9';ip=getchar_unlocked())if(ip=='-'){flag=-1;ip=getchar_unlocked();break;}
		for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';
		return flag*ret;
	}

	void println_d(int n) 
	{
		if(n<0){n=-n;putchar_unlocked('-');}
		int i=10;
		char output_buffer[11];
		output_buffer[10]='\n';
		do{output_buffer[--i]=(n%10)+'0';
			n/=10;}while(n);
		do{putchar_unlocked(output_buffer[i]);
		}while(++i<11);
	}
snippet z_algorithm
	int z[MAX];
	void z_algorithm(string s)
	{
		int L=0,R=0,n = s.length();
		z[0] = n;

		for(int i=1;i<n;i++)
		{
			if(i > R){   // case 1 - brute
				L = R = i;
				while(R < n && s[R-L] == s[R]) R++;
				z[i] = R-L; R--;
			}
			else{
				int k = i-L;
				if(z[k] < R-i+1)    z[i] = z[k]; //2a
				else{              //2b & 2c  -brute
				   L = i;           //beta = R-i (0-based)
				   while(R < n && s[R-L] == s[R]) R++;
				   z[i] = R-L; R--;                
				}
			}
		}
	}
snippet expo
	LL expo(LL a,LL n)
	{
		LL result = 1;
		while(n)
		{
			if((n&1))
				result *= a;
			a *= a;
			n >>= 1;
		}
		return result;
	}
snippet mod_expo
	LL mod_expo(LL a,LL n,LL m)
	{
		LL result = 1;
		while(n)
		{
			if((n&1))
				result = (result*a)%m;
			a = (a*a)%m;
			n >>= 1;
		}
		return result%m;
	}

snippet merge_interval
	vpii merge_interval(vpii& v)
	{
		vpii q;
		sort(all(v));
		int size = v.size();
		int l = v[0].first;
		int r = v[0].second;
		for(int i=1;i<size;i++)
		{
			if(v[i].first <= r)
				r = max(r,v[i].second);
			else
			{
				q.pb(mp(l,r));
				l = v[i].first;
				r = v[i].second;
			}            
		}
		
		q.pb(mp(l,r));

		return q;
	}


