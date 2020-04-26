/*
 * https://github.com/ivokaragyozov/CompetitiveProgramming/blob/master/POI/POI10-sums.cpp
*/
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
using namespace std;
#define sqr 547
#define mp make_pair
#define mid (l+r)/2
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define era erase
#define C continue
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define mset multiset
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
const ll inf=1e18;
const ll mod=1e9+7;
const ld pai=acos(-1);
int n ;
int a [5009] , dis [50009] , done [50009] ;
int main () {
	cin >> n ;
	for ( int i = 0 ; i < n ; i ++ ) scanf("%d",&a[i]) ;
	for ( int i = 1 ; i < a [0] ; i ++ ) dis [i] = 2e9 ;
	priority_queue< pi , vpi , greater < pi > > pq;
	pq .push ( { 0 , 0 } ) ;
	while ( pq.size() ) {
		int node = pq.top().se ;
		int t =  pq.top().fi ;
		pq .pop () ;
		if ( done [ node ] ) C ;
		done [ node ] = 1 ;
		for ( int i = 0 ; i < n ; i ++ ) {
			int u = ( node + a[i] ) % a[0] ;
			if ( done [u] ) C ;
			if ( t + a[i] >= dis [u] ) C ;
			dis [u] = t + a[i] ;
			pq.push ( { dis[u] , u} ) ;
		}
	}
	int q ;
	scanf("%d",&q);
	while ( q -- ) {
		int x ;
		scanf("%d",&x);
		if ( dis [ x % a[0] ] <= x ) printf("TAK\n") ;
		else printf("NIE\n") ;
	}
}
