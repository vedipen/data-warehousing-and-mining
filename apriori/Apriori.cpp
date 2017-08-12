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
  freopen("database1","r",stdin);
  string s1;
  ll noOfTransaction=0;
  map<string,ll> c1,l1,c2,l2,c3,l3;
  map<string,double> association;
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
    v[i].pb(s);
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
    for(auto it1=it; it1!=l1.end();it1++) {
      if(it1==it) continue;
      ll cnt=0;
      for(ll k=0;k<noOfTransaction;k++) {
        if(find(v[k].begin(),v[k].end(),it->first)!=v[k].end() && find(v[k].begin(),v[k].end(),it1->first)!=v[k].end()) {
          cnt++;
        }
      }
      c2[(it->first)+","+(it1->first)]=cnt;
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
  for(auto it=l2.begin();it!=l2.end();it++) {
    for(auto it1=it; it1!=l2.end();it1++) {
      if(it1==it) continue;
      string firstFirst=(it->first).substr(0,(it->first).find(","));
      string firstSecond=(it->first).substr((it->first).find(",")+1,(it->first).size());
      string secondFirst=(it1->first).substr(0,(it1->first).find(","));
      string secondSecond=(it1->first).substr((it1->first).find(",")+1,(it1->first).size());
      set<string> st;
      st.insert(firstFirst);
      st.insert(firstSecond);
      st.insert(secondFirst);
      st.insert(secondSecond);
      if(st.size()!=3) {
        continue;
      }
      auto it2=st.begin();
      string one=*it2;
      it2++;
      string two=*it2;
      it2++;
      string three=*it2;
      ll cnt=0;
      for(ll k=0;k<noOfTransaction;k++) {
        if(find(v[k].begin(),v[k].end(),one)!=v[k].end() && find(v[k].begin(),v[k].end(),two)!=v[k].end() && find(v[k].begin(),v[k].end(),three)!=v[k].end()) {
          cnt++;
        }
      }
      c3[one+","+two+","+three]=cnt;
    }
  }

  //Printing C3
  cout<<"C3 ---> "<<endl<<endl;
  cout<<"Item Set"<<"\t\t"<<"Support Count"<<endl;
  cout<<"-------------------------------------------"<<endl;
  for(auto it=c3.begin();it!=c3.end();it++) {
    cout<<it->first<<"\t\t\t"<<it->second<<endl;
  }
  cout<<endl<<endl;

  //Finding L3
  cout<<"L3 ---> "<<endl<<endl;
  cout<<"Item Set"<<"\t\t"<<"Support Count"<<endl;
  cout<<"-------------------------------------------"<<endl;
  for(auto it=c3.begin();it!=c3.end();it++) {
    if(it->second>=support) {
      l3[it->first]=it->second;
      cout<<it->first<<"\t\t\t"<<l3[it->first]<<endl;
    }
  }
  cout<<endl<<endl;

  //Contraint Check
  if(l3.size()!=1) {
    return 0;
  }

  //Association Rules
  vector<ll> confidenceTable;
  cout<<"Association Rule\t\tSupport\t\tConfidence\t\tConfidence %"<<endl;
  cout<<"--------------------------------------------------------------------------------------"<<endl;
  auto it=l3.begin();
  string full=it->first;
  string one=full.substr(0,full.find(","));
  full.erase(0,full.find(",")+1);
  string two=full.substr(0,full.find(","));
  full.erase(0,full.find(",")+1);
  string three=full;
  //one,two -> three
  //two,three -> one
  //one,three -> two
  //three -> one,two
  //one -> two,three
  //two -> one,three
  confidenceTable.pb(l2[one+","+two]);
  confidenceTable.pb(l2[two+","+three]);
  confidenceTable.pb(l2[one+","+three]);
  confidenceTable.pb(l1[three]);
  confidenceTable.pb(l1[one]);
  confidenceTable.pb(l1[two]);
  association[one+"^"+two+"=>"+three]=(double)(it->second)*1.00/(confidenceTable[0]);
  cout<<one<<"^"<<two<<" => "<<three<<"\t\t\t"<<it->second<<"\t\t"<<it->second<<"/"<<confidenceTable[0]<<" = "<<association[one+"^"+two+"=>"+three]<<"\t\t"<<association[one+"^"+two+"=>"+three]*100<<endl;
  association[two+"^"+three+"=>"+one]=(double)(it->second)*1.00/(confidenceTable[1]);
  cout<<two<<"^"<<three<<" => "<<one<<"\t\t\t"<<it->second<<"\t\t"<<it->second<<"/"<<confidenceTable[1]<<" = "<<association[two+"^"+three+"=>"+one]<<"\t\t"<<association[two+"^"+three+"=>"+one]*100<<endl;

  return 0;
}
