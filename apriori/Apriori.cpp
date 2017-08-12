#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

int main() {
  ll minSupport,minConfidence;
  cout<<"Enter min support % : ";
  cin>>minSupport;
  cout<<"Enter min confidence % : ";
  cin>>minConfidence;
  freopen("database","r",stdin);
  string s1;
  ll noOfTransaction=0;
  map<string,ll> c1,l1,c2,l2,c3,l3;
  vector< vector<string> > v(100);
  ll i=0;
  while(1) {
    getline(cin,s1);
    if(cin.eof()) break;
    noOfTransaction++;
    //Remove 1st word
    string s=s1;
    string delimiter1 = " ";
    size_t pos1 = 0;
    string token1;
    while ((pos1=s.find(delimiter1)) != string::npos) {
        token1 = s.substr(0, pos1);
        s.erase(0, pos1 + delimiter1.length());
    }

    //Store items
    string delimiter = ",";
    size_t pos = 0;
    string token;
    while ((pos=s.find(delimiter)) != string::npos) {
        token = s.substr(0, pos);
        // cout << token << endl;
        c1[token]++;
        v[i].pb(token);
        s.erase(0, pos + delimiter.length());
    }
    v[i].pb(token);
    i++;
    c1[s]++;
    // cout<<s<<endl;
  }

  //Finding support
  cout<<endl;
  cout<<"Total Transactions : "<<noOfTransaction<<endl;
  ll support = (minSupport*noOfTransaction)/100;
  cout<<"Support is "<<support<<endl<<endl;

  //Printing C1
  cout<<"C1 ---> "<<endl<<endl;
  cout<<"Item Set"<<"\t\t"<<"Support Count"<<endl;
  cout<<"-------------------------------------------"<<endl;
  for(auto it=c1.begin();it!=c1.end();it++) {
    cout<<it->first<<"\t\t\t"<<it->second<<endl;
  }
  cout<<endl<<endl;

  //Finding L1
  cout<<"L1 ---> "<<endl<<endl;
  cout<<"Item Set"<<"\t\t"<<"Support Count"<<endl;
  cout<<"-------------------------------------------"<<endl;
  for(auto it=c1.begin();it!=c1.end();it++) {
    if(it->second>=support) {
      l1[it->first]=it->second;
      cout<<it->first<<"\t\t\t"<<l1[it->first]<<endl;
    }
  }
  cout<<endl<<endl;

  //Finding C2
  for(auto it=l1.begin();it!=l1.end();it++) {
    for(ll j=0;j<noOfTransaction;j++) {
      ll flag=0;
      for(ll k=0;k<v[j].size();k++) {
        // cout<<it->first+"+"+v[j][k]<<endl;
        if(v[j][k]==it->first) {
          flag=1;
          continue;
        }
        if(flag==1) {
          c2[it->first+","+v[j][k]]++;
        }
      }
    }
  }

  //Printing C2
  cout<<"C2 ---> "<<endl<<endl;
  cout<<"Item Set"<<"\t\t"<<"Support Count"<<endl;
  cout<<"-------------------------------------------"<<endl;
  for(auto it=c2.begin();it!=c2.end();it++) {
    cout<<it->first<<"\t\t\t"<<it->second<<endl;
  }
  cout<<endl<<endl;

  //Finding L2
  cout<<"L2 ---> "<<endl<<endl;
  cout<<"Item Set"<<"\t\t"<<"Support Count"<<endl;
  cout<<"-------------------------------------------"<<endl;
  for(auto it=c2.begin();it!=c2.end();it++) {
    if(it->second>=support) {
      l2[it->first]=it->second;
      cout<<it->first<<"\t\t\t"<<l2[it->first]<<endl;
    }
  }
  cout<<endl<<endl;

  //Finding C3
  for(auto it=l1.begin();it!=l1.end();it++) {
    for(ll j=0;j<noOfTransaction;j++) {
      ll flag=0;
      for(ll k=0;k<v[j].size();k++) {
        // cout<<it->first+"+"+v[j][k]<<endl;
        if(v[j][k]==it->first) {
          flag=1;
          continue;
        }
        if(flag==1) {
          c2[it->first+","+v[j][k]]++;
        }
      }
    }
  }

  return 0;
}
