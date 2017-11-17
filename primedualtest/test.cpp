#include <bits/stdc++.h>
using namespace std;

//type helpers
#define ll long long
#define vi vector <int>
#define vl vector <ll> 
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpii vector <pii >
#define vpll vector <pll >
//debugging
#define debug(x) cout<<"debugging "<<x<<endl

//loops
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define FORD(i,a,b) for(ll i=a-1;i>=b;i--)
#define iter(it, s) for(auto it=s.begin(); it!=s.end(); it++)

//io helpers
#define sd(n) scanf("%d", &n)
#define sl(n) scanf("%lld", &n)
#define slf(n) scanf("%lf", &n) 
#define pd(n) printf("%d", n)
#define pl(n) printf("%lld", n)
#define plf(n) printf("%0.9lf", n)
#define ps printf(" ")
#define pn printf("\n")


//ds helpers
#define f first
#define s second
#define pb push_back
#define pob pop_back
#define mp make_pair
#define sz(n) (ll)n.size()


//fast input and output when using cin,cout
#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
//some constants
const int INF = 1<<29;
#define MOD 1000000007
#define PI 3.14159265358979323846
#define EPS 0.0000000001
#define max_size 100005

//some helper functions
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9;}
inline ll lcm(ll a,ll b){ return (a*b)/(__gcd(a,b));}
#define mod(a) ((a)%MOD)
inline ll ciel(double a) { ll ret = a; if(a-ret>EPS) ret++; return ret; }
inline ll powf(ll n, ll p) {if(p==0)return 1; if(n<=1)return n;ll res = 1;while(p){if(p&1) res = mod(res*n);n = mod(n*n);p /= 2;} return res;}
inline bool ispoweroftwo(ll x){return (x && !(x&(x-1)));}

#define MAX 30000

int nvertices,nedges;
int vertexweights[MAX]={0};
int vertexstatus[MAX]={0};
int currentweights[MAX]={0};
vector<int> adjvec[MAX];
vector<pair<int,int>> edges;


void findvertexcover(){
	for(int i=0;i<nedges;i++){
		if(!(vertexstatus[edges[i].f]==2 or vertexstatus[edges[i].s]==2)){
			int delta;
			delta = min(vertexweights[edges[i].f]-currentweights[edges[i].f],vertexweights[edges[i].s]-currentweights[edges[i].s]);
			currentweights[edges[i].f] += delta;
			currentweights[edges[i].s] += delta;
			if(currentweights[edges[i].f]==vertexweights[edges[i].f]){
				vertexstatus[edges[i].f]=2;
			}
			if(currentweights[edges[i].s]==vertexweights[edges[i].s]){
				vertexstatus[edges[i].s]=2;
			}
		}
	}
}

int myrandom (int i) {std::srand(time(0));return rand()%i;}

int main(int argc, char const *argv[])
{
	/* code */
	ifstream infile("inp-params.txt");
	//cin>>nvertices>>nedges;
	infile>>nvertices>>nedges;	
	int src,dst;
	char c;
	for(int i=0;i<nedges;i++){
		//cin>>c>>src>>dst;
		infile>>c>>src>>dst;
		cout<<src<<dst<<endl;	
		adjvec[src].pb(dst);
		adjvec[dst].pb(src);
		edges.pb({src,dst});
	}
	for(int i=0;i<nvertices;i++){
		//cin>>vertexweights[i];
		vertexweights[i]=1;
	}
	random_shuffle(edges.begin(),edges.end(),myrandom);
	findvertexcover();
	cout<<"Ans is";
	int count=0;
	for(int i=0;i<nvertices;i++){
		if(vertexstatus[i]==2){
			cout<<i<<endl;
			count++;
		}
	}
	cout<<count<<endl;
	return 0;
}