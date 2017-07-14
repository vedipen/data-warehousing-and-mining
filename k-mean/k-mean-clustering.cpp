#include<bits/stdc++.h>

#define ll long long
#define pl pair<l,l>
#define pll pair<ll,ll>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007
#define vll vector<ll>
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;

ll meanOf(vll v) {
    ll sum;
    for(ll a: v) {
        sum+=a;
    }
    sum/=(ll)v.size();
    return sum;
}

int main() {
    fio;
    ll n;
    cin>>n;
    vll v(n,0);
    for(ll i=0;i<n;i++) {
        cin>>v[i];
    }
    ll k;
    cin>>k;
    ll flag=1;
    vll m(k,0);
    for(ll i=0;i<k;i++) {
        cin>>m[i];
    }
    vector<vll> v1(k);
    vector<vll> history(k);
    ll times=0;
    ll selected;
    cout<<"Clustering Starts.."<<endl;
    while(true) {
        if(flag==1) {
            for(ll i=0;i<n;i++) {
                ll temp=1e5;
                for(ll j=0;j<k;j++) {
                    if((abs(v[i]-m[j]))<temp) {
                        temp=abs(v[i]-m[j]);
                        selected=j;
                    }
                }
                v1[selected].pb(v[i]);
            }
            for(ll i=0;i<k;i++) {
                    m[i]=meanOf(v1[i]);
                    cout<<"Mean of "<<i<<" is now "<<m[i]<<endl;
            }
            times++;
        }
        if(times!=1) {
            flag=0;
            for(ll i=0;i<k;i++) {
                if(v1[i].size()!=history[i].size()) {
                    flag=1;
                }
            }
        } 
        if(flag==0) {
            cout<<"Done in "<<times<<" "<<endl;
            break;
        }
        for(ll i=0;i<k;i++) {
            for(ll j=0;j<v1[i].size();j++) {
                cout<<v1[i][j]<<" ";
            }
            cout<<endl;
        }
        for(ll i=0;i<k;i++) {
            history[i].clear();
            for(ll x : v1[i]) {
                history[i].pb(x);
            }
            v1[i].clear();
        }
    }
    return 0;
}


//vedipen

/*
Input - 

10
1 2 3 4 5 6 7 8 9 10
2
2 3


Output -

Clustering Starts..
Mean of 0 is now 1
Mean of 1 is now 6
1 2 
3 4 5 6 7 8 9 10 
Mean of 0 is now 2
Mean of 1 is now 7
1 2 3 
4 5 6 7 8 9 10 
Mean of 0 is now 2
Mean of 1 is now 7
1 2 3 4 
5 6 7 8 9 10 
Mean of 0 is now 2
Mean of 1 is now 7
Done in 4 
*/