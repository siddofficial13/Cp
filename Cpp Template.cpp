#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

//****************************************DEFINES**********************************************************
#define ll long long
#define ull unsigned long long
#define mod 1000000007
#define mod1 998244353
#define endl "\n"
#define ld long double
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
typedef __gnu_pbds::tree<ll, __gnu_pbds::null_type, less<ll>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
#define N 1e5 +6
#define INF 1e18
const ll PMAX=1e6+10;
#define PI 3.141592653589793238462
#define all(x) (x).begin(), (x).end()
//****************************************DEFINES***********************************************************
//****************************************DEBUGS***********************************************************
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

//****************************************DEBUGS***********************************************************

//****************************************FUNCTIONS*********************************************************
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}

bool comp(pair<ll,pair<ll,ll>> &p1,pair<ll,pair<ll,ll>> &p2){
    if(p1.first!=p2.first){
        return p1.first>p2.first;
    }
    if(p1.second.first!=p2.second.first){
        return p1.second.first<p2.second.first;
    }
    return p1.second.second<p2.second.second;
}
ll __lcm(ll a, ll b)
{
    return ((a*b)/ __gcd(a, b));
}
ll smallestprimeDivisor(ll n)
{
    if (n % 2 == 0)
        return 2;
    for (ll i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return i;
    }
    return n;
}
ll hashfunction(string s){
    ll p =31;
    ll hashVal=0;
    ll pow=1;
    for (char c : s) {
        hashVal = (hashVal + (c - 'a' + 1) * pow) % mod;
        pow = (pow * p) % mod;
    }
    return hashVal;
}
ll binexpo(ll x, ll y, ll m) {
    ll res = 1;
    while (y > 0) {
        if (y & 1)res = (res * x) % m;
        x = (x * x) % m;
        y = y >> 1;
    }

    return res;
}
vector<bool> isPrime(PMAX,1);
vector<ll>prime;
void primeseive()
{
    isPrime[0]=isPrime[1]=0;
    for(ll i=2;i<PMAX;i++)
        if(isPrime[i]==true)
            for(ll j=2*i;j<PMAX;j+=i)
                isPrime[j]=false;
    for(ll i=2;i<PMAX;i++)
        if(isPrime[i])
            prime.push_back(i);
}
struct Node{
    int val;
    Node * links[2];
};
Node * newNode(){
    Node * root = new Node;
    root->val=0;
    root->links[0] = NULL;
    root->links[1] = NULL;
    return root;
}
void insert(Node *root2, int xor_val){
    Node *temp= root2;
    for(int i=31;i>=0;i--){
        bool bitval= xor_val&(1<<i);
        if(temp->links[bitval]==NULL){
            temp->links[bitval] = newNode();
        }
        temp=temp->links[bitval];
    }
    temp->val=xor_val;
}
int q(Node *root2, int xor_val){
    Node *temp= root2;
    for(int i=31;i>=0;i--){
        bool bitval= xor_val&(1<<i);
        if(temp->links[1-bitval]!=NULL){
            temp=temp->links[1-bitval];
        }
        else if(temp->links[bitval]!=NULL){
            temp=temp->links[bitval];
        }

    }
    int ans = xor_val^(temp->val);
    return ans;
}
int solve(vector<int> &v, int n){
    Node *root = newNode();
    insert(root,0);
    int maxm=INT_MIN;
    int xor_val=0;
    for(auto it: v){
        xor_val=xor_val^it;
        insert(root,xor_val);
        maxm=max(maxm,q(root,xor_val));
    }
    return maxm;
}

ll fact(ll n)
{
    if(n==0)
        return 1;
    ll res = 1;
    for (ll i = 2; i <= n; i++)
        res = res * i;
    return res;
}
ll nCr(ll n, ll r)
{
    return fact(n) / (fact(r) * fact(n - r));
}
string decimalToBaseK(int decimal, int k) {
    if (decimal == 0) {
        return "0";
    }

    string result = "";

    while (decimal > 0) {
        int remainder = decimal % k;
        result = to_string(remainder) + result;
        decimal /= k;
    }

    return result;
}

bool check_prime(ll n){
    if(n<=1) return false;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}
bool is_square(ll x) {
    ll lo = 1, ri = 1e9;
    while(lo <= ri) {
        ll mid = lo + (ri - lo) / 2;
        if(mid * mid == x) return true;
        if(mid * mid > x) ri = mid - 1;
        else lo = mid + 1;
    }
    return false;
}
ll inv(ll a, ll b){
    return 1<a ? b - inv(b%a,a)*b/a : 1;
}
ll power_val(ll base,ll n){
    ll ans=1;
    while(n!=0){
        if(n%2){
            n=n-1;
            ans=(1ll*ans*base)%mod;
        }
        else{
            n=n/2;
            base=(1ll*base*base)%mod;
        }
    }
    return ans%mod;
}
ll max_subarray_sum(vector<ll> &v,ll n){
    ll max_so_far=LLONG_MIN;
    ll max_ending_here=0;
    for(ll i=0;i<n;i++){
        max_ending_here+=v[i];
        if(max_so_far<max_ending_here){
            max_so_far=max_ending_here;
        }
        if(max_ending_here<0){
            max_ending_here=0;
        }
    }
    return max_so_far;
}
map<ll,ll> factorize(ll n)
{
    ll cnt=0;
    map<ll,ll> mp;
    while (!(n % 2)) {
        n >>= 1;
        cnt++;
    }
    if (cnt) mp[2]+=cnt;
    for (ll i = 3; i <= sqrt(n); i += 2) {
        cnt = 0;
        while (n % i == 0) {
            cnt++;
            n = n / i;
        }
        if (cnt)
            mp[i]=cnt;
    }

    if (n > 2) mp[n]=1;

    return mp;
}
ll countFactors(ll n, ll p)
{
    ll pwr = 0;
    while (n > 0 && n % p == 0) {
        n /= p;
        pwr++;
    }
    return pwr;
}

// ****************************************FUNCTIONS**********************************************************


// ****************************************SOLVE**********************************************************
void solution() {

}
// ****************************************SOLVE**********************************************************

// ****************************************MAIN**********************************************************
int main(){

#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
//    primeseive();
    while(t--) {
        solution();
    }




    return 0;
}





// ****************************************MAIN**********************************************************
