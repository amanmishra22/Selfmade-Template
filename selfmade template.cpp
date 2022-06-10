#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ll long long int
#define lp(i,a,b) for(ll i=a;i<b;i++)
#define lpa(i,a,b,x) for(ll i=a;i<b;i+=x)
#define pl(i,a,b) for(ll i=a;i>=b;i--)
#define sb(x) __builtin_popcountll(x)
#define lz(x) __builtin_clzll(x)
#define tz(x) __builtin_ctzll(x)
#define eb push_back
#define all(v) v.begin(),v.end()
#define ubv(v,a) upper_bound(all(v),a)
#define lbv(v,a) lower_bound(all(v),a)
#define bsv(v,a) binary_search(all(v),a)
#define uba(a,n,c) upper_bound(a,a+n,c)
#define lba(a,n,c) lower_bound(a,a+n,c)
#define bsa(a,n,c) binary_search(a,a+n,c)
#define ms(a,x) memset(a,x,sizeof(a))
#define si(i,s) for(set<ll>::iterator i=s.begin();i!=s.end();i++)
#define sp(n,a) cout<<fixed<<setprecision(n)<<a
#define maxa(a,n) *max_element(a,a+n)
#define mina(a,n) *min_element(a,a+n)
#define aca(a,n,x) accumulate(a,a+n,x)
#define ca(a,n,x) count(a,a+n,x)
#define fi(a,n,x) find(a,a+n,x)-a
#define ap(s) do{cout<<s<<endl;}while(next_permutation(all(s)))
#define pll pair<ll,ll>
#define vpll vector<pll>
#define vll vector<ll>
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define disa(a,n) lp(i,0,n)cout<<a[i]<<" ";cout<<"\n";
#define disv(v) lp(i,0,v.size())cout<<v[i]<<" ";cout<<"\n";
#define ff first
#define ss second
const ll mod1= 1000000007;
const ll mod2= 998244353;
const ll INF= 5000000000000000000;
const ll INM= -5000000000000000000;
const double pi= 3.1415926535897932384626433832795;
//is_sorted(a,a+n)
/*void sleep(int delay)
 {   time_t t1,t2;
     t1=time(NULL);
     t2=t1+delay;
     while(t1<=t2)t1=time(NULL);
 }*/
using namespace std;
using namespace __gnu_pbds;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update>pbds;
ll lcm(ll a, ll b) 
{ return (a*b)/(__gcd(a,b));}
ll msb(ll a){ ll k=log(a); return 1<<k;}
ll lsb(ll a){ return (a&(-a));}
ll pm(ll x,ll y)
{  ll res=1;   x%=mod1;
  while(y>0) 
  { if(y&1)res=(res*x)%mod1;
    y=y>>1;   x=(x*x)%mod1;}  return res;
}
bool myc(pll p1,pll p2)
{
   if(p1.first!=p2.first)
    return p1.first<p2.first;
   else  return p1.second<p2.second;
}
vpll vp(ll a[],ll n)
{ vpll vt;
  lp(i,0,n)vt.eb(make_pair(a[i],i+1));
  sort(all(vt),myc); return vt;
}
vector<ll>primeser(ll n)
{ vector<ll>prime(n+1,1);
   prime[0]=0;prime[1]=0;
   lp(i,0,sqrt(n)+1)
   { if(prime[i])
     {for(ll j=i*i;j<=n;j+=i)
       prime[j]=0;}} return prime;
}
vll linearsieve (ll n) {
    vll prime;
    bool is_composite[n+2];
	fill (is_composite,is_composite+n,false);
	lp(i,2,n){
		if (!is_composite[i]) prime.eb(i);
		for (ll j=0;j<prime.size()&&i*prime[j]<n;++j) {
			is_composite[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}return prime;
}
void subset(ll a[],ll n)
{
  lp(i,0,(1<<n)) {lp(j,0,n)
  { if(i&(1<<j))cout<<a[j]<<" ";}
    cout<<"\n";}
}
bool is_prime(ll a)
{
  if(a==1)return false;  if(a==2)return true;
  if((a&1)==0)return false;
  lpa(i,3,sqrt(a)+1,2)
  if(a%i==0)return false; return true;
}
string DTB(ll n)
{
    //finding the binary form of the number and converting it to string. 
    string s = bitset<32> (n).to_string();
    return s;
}
ll merge(ll a[],ll temp[],ll le,ll mid,ll ri)
{ ll ic=0,i=le,j=mid,k=le;
  while((i<=mid-1)&&(j<=ri))
  { if(a[i]<=a[j])temp[k++]=a[i++];
    else{
    temp[k++]=a[j++];ic+=(mid-i);}}
  while(i<=mid-1)temp[k++]=a[i++];
  while(j<=ri)temp[k++]=a[j++];
  lp(i,le,ri+1)a[i]=temp[i];
   return ic;
}
ll mg(ll a[],ll temp[],ll le,ll ri)
{
   ll mid,ic=0;
   if(ri>le){
   mid=(ri+le)/2;
   ic=mg(a,temp,le,mid);
   ic+=mg(a,temp,mid+1,ri);
   ic+=merge(a,temp,le,mid+1,ri);}
   return ic;}  
ll countswap(ll a[],ll n)
{ ll temp[n];
  return mg(a,temp,0,n-1);
} 
ll minswap(ll a[],ll n)
{
   pll ap[n];
   lp(i,0,n){
    ap[i].first=a[i];ap[i].second=i;}
   sort(ap,ap+n);
   vector<bool>vis(n,false);
   ll ans=0;
   lp(i,0,n){
   if(vis[i]||ap[i].second==i)continue;
   ll cs=0;ll j=i;
    while(!vis[j]){
    vis[j]=1;j=ap[j].second;cs++;}
   if(cs)ans+=(cs-1);}
    return ans;
}
void consttree(ll a[],ll seg[],ll l,ll h,ll p){
     if(l==h){seg[p]=a[l];return;}
     ll mid=(l+h)/2;
     consttree(a,seg,l,mid,2*p+1);
     consttree(a,seg,mid+1,h,2*p+2);
     seg[p]=min(seg[2*p+1],seg[2*p+2]);
 }
 ll rq(ll seg[],ll ql,ll qh,ll l,ll h,ll p){
       if(ql<=l&&qh>=h)return seg[p];
       if(ql>h||qh<l)return INF;
       ll mid=(l+h)/2;
       return min(rq(seg,ql,qh,l,mid,2*p+1),rq(seg,ql,qh,mid+1,h,2*p+2));
 }
void solve()
{
   ll n;cin>>n;
   ll a[n];
   lp(i,0,n)cin>>a[i];
}
int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll t;
  cin>>t;
  lp(i,1,t+1)
  { //cout<<"Case #"<<i<<": ";
  solve();}
}