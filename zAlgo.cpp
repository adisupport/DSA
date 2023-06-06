#include <iostream>
#include<vector>
class zAlgo{
public:
  std::vector<int> zValue(std::string s){
    int n = s.size();  
    std::vector<int>Z(n);
     int l = 0,r = 0; 
   for(int i=1;i<n;i++){
      if(i>r){
        int j = i,k=0;
        while(j<n && s[k]==s[j]){k++;j++;}
        Z[i] = k;
        r = j-1;
        l = i;
      }else{
        if(Z[i-l]<=r-i){
          Z[i] = Z[i-l];
        }else{
          int j=r+1,k=r-l+1;
          while(j<n && s[k]==s[j]){k++;j++;}
          Z[i] = k;
          r=j-1;
          l=i;
        }
      }
    }
    return Z;
  } 
  std::vector<int>find(std::string p,std::string s){
    std::string a = p + '#' + s;
    int n = s.size(),m = p.size();
    auto Z = zValue(a);
    std::vector<int>index;
    for(int i=1;i<Z.size();i++){
      if(Z[i] == m){
        index.push_back(i-(m+1));
      }
    }
    return index;
  }
};
