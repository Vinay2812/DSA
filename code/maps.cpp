#include<map>
#include<unordered_map>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    //map<key,value>mp

    map<string,vector<int>>mp;
    
    //pair<string,vector<int>>p;
    /*
    unordered map->O(1)//all operations
    map->O(log n)//all operation
    pair<string,vector<int>>p   p.first ->key   p.second->value
      {vinay , {1,2,3}}  {zaid , {4,5,6}}
                                p  
    */
   mp["zaid"].push_back(10);
   mp.insert({"vinay",{1,2,3}});

   for( auto p : mp ){
       cout<<p.first<<": ";
        for(auto x : p.second){
            cout<<x<<" ";
        }
   }
    
    return 0;
}