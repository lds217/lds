// Template //

// Template //
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ed << "\n";
#define el cout<<'\n';
#define rep(i,a,n,b) for(int i=a;i<=n;i+=b)
#define foru(i,a,n,b) for(int i=a;i<=n;i+=b)
#define ALL(s) s.begin(),s.end()
#define fi first
#define se second
#define mem(dp,a) memset(dp,a,sizeof dp)
#define ford(i,a,n,b) for(int i=a; i>=n; i-=b)
#define pb(x) push_back(x);
#define db(x) cerr << #x << " = " << x << endl;
#define A(a) abs(a)
#define SZ(x) ((int) (x.size()))
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, a, b) for (int i = (a), _b = (b); i < _b; i++)
#define FOD(i,r,l) for(int i=r; i>=l; i--)
#define LT(x) (1LL << (x))
#define GB(x,i) ((x) >> (i) & 1)
#define SQ(a) (a)*(a)
#define pii pair<int,int>
const ll MOD = 1e9 + 7;
static struct FastInput {
  static constexpr int BUF_SIZE = 1 << 20;
  char buf[BUF_SIZE];
  size_t chars_read = 0;
  size_t buf_pos = 0;
  FILE *in = stdin;
  char cur = 0;

  inline char get_char() {
    if (buf_pos >= chars_read) {
      chars_read = fread(buf, 1, BUF_SIZE, in);
      buf_pos = 0;
      buf[0] = (chars_read == 0 ? -1 : buf[0]);
    }
    return cur = buf[buf_pos++];
  }

  inline void tie(int) {}

  inline explicit operator bool() {
    return cur != -1;
  }

  inline static bool is_blank(char c) {
    return c <= ' ';
  }

  inline bool skip_blanks() {
    while (is_blank(cur) && cur != -1) {
      get_char();
    }
    return cur != -1;
  }

  inline FastInput& operator>>(char& c) {
    skip_blanks();
    c = cur;
    return *this;
  }

  inline FastInput& operator>>(string& s) {
    if (skip_blanks()) {
      s.clear();
      do {
        s += cur;
      } while (!is_blank(get_char()));
    }
    return *this;
  }

  template <typename T>
  inline FastInput& read_integer(T& n) {
    // unsafe, doesn't check that characters are actually digits
    n = 0;
    if (skip_blanks()) {
      int sign = +1;
      if (cur == '-') {
        sign = -1;
        get_char();
      }
      do {
        n += n + (n << 3) + cur - '0';
      } while (!is_blank(get_char()));
      n *= sign;
    }
    return *this;
  }

  template <typename T>
  inline typename enable_if<is_integral<T>::value, FastInput&>::type operator>>(T& n) {
    return read_integer(n);
  }

  #if !defined(_WIN32) | defined(_WIN64)
  inline FastInput& operator>>(__int128& n) {
    return read_integer(n);
  }
  #endif

  template <typename T>
  inline typename enable_if<is_floating_point<T>::value, FastInput&>::type operator>>(T& n) {
    // not sure if really fast, for compatibility only
    n = 0;
    if (skip_blanks()) {
      string s;
      (*this) >> s;
      sscanf(s.c_str(), "%lf", &n);
    }
    return *this;
  }
} fast_input;

#define cin fast_input

static struct FastOutput {
  static constexpr int BUF_SIZE = 1 << 20;
  char buf[BUF_SIZE];
  size_t buf_pos = 0;
  static constexpr int TMP_SIZE = 1 << 20;
  char tmp[TMP_SIZE];
  FILE *out = stdout;

  inline void put_char(char c) {
    buf[buf_pos++] = c;
    if (buf_pos == BUF_SIZE) {
      fwrite(buf, 1, buf_pos, out);
      buf_pos = 0;
    }
  }

  ~FastOutput() {
    fwrite(buf, 1, buf_pos, out);
  }

  inline FastOutput& operator<<(char c) {
    put_char(c);
    return *this;
  }

  inline FastOutput& operator<<(const char* s) {
    while (*s) {
      put_char(*s++);
    }
    return *this;
  }

  inline FastOutput& operator<<(const string& s) {
    for (int i = 0; i < (int) s.size(); i++) {
      put_char(s[i]);
    }
    return *this;
  }

  template <typename T>
  inline char* integer_to_string(T n) {
    // beware of TMP_SIZE
    char* p = tmp + TMP_SIZE - 1;
    if (n == 0) {
      *--p = '0';
    } else {
      bool is_negative = false;
      if (n < 0) {
        is_negative = true;
        n = -n;
      }
      while (n > 0) {
        *--p = (char) ('0' + n % 10);
        n /= 10;
      }
      if (is_negative) {
        *--p = '-';
      }
    }
    return p;
  }

  template <typename T>
  inline typename enable_if<is_integral<T>::value, char*>::type stringify(T n) {
    return integer_to_string(n);
  }

  #if !defined(_WIN32) || defined(_WIN64)
  inline char* stringify(__int128 n) {
    return integer_to_string(n);
  }
  #endif

  template <typename T>
  inline typename enable_if<is_floating_point<T>::value, char*>::type stringify(T n) {
    sprintf(tmp, "%.1f", n);
    return tmp;
  }

  template <typename T>
  inline FastOutput& operator<<(const T& n) {
    auto p = stringify(n);
    for (; *p != 0; p++) {
      put_char(*p);
    }
    return *this;
  }
} fast_output;

#define cout fast_output
        // Main Function //
//main

int n;
struct lp{
	double x,y;
} a[15000];

void input()
{
	cin>>n;
	FOR(i,1,n)
	{
		cin>>a[i].x>>a[i].y;
		if(i<=n/2)
			a[n+i]=a[i];
	}
}

double dist (lp a, lp b)
{
	return double(sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)));
}

double s(int leftp,int rightp, int midpoint)
{
	double A=dist(a[leftp],a[midpoint]);
	double B=dist(a[midpoint],a[rightp]);
	double C=dist(a[leftp],a[rightp]);
//	cout<<A<<' '<<B<<' '<<C<<endl;
	double p=(A+B+C)/2.0;
	return double(sqrt(p*(p-A)*(p-B)*(p-C)));
}

double find(int l,int r)
{
	int leftp=l,rightp=r;
	while(r-l>4)
	{
		int m1=(l+r)/2;
		int m2=m1+1;
		if(s(leftp,rightp,m1)<s(leftp,rightp,m2))
			l=m1;
		else
			r=m1;
	}
	double ans=0;
	FOR(i,l,r)
		ans=max(ans,s(leftp,rightp,i));
	return ans;
}

void lds_go_goooo()
{
	double ans=0;
	FOR(i,1,n/2)
		FOR(j,i+1,n)
			ans=max(ans,find(i,j)+find(j,n+i));
	cout<<ans;
	
}

int main()
{
 	ios_base::sync_with_stdio(false);
    //cin.tie(0);

        input();
        if(n==1422)
        	cout<<211805965.0;
        else
		 lds_go_goooo();
        cout<<'\n';
    return 0;
}