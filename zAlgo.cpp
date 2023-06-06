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
        //i-l pointing to current character from 0 side.
        //r-i length of remaining window
        //if Z[i-l] < r-i means value of Z[i] valid and can be copy.
        if(Z[i-l]<=r-i){
          Z[i] = Z[i-l];
        }else{
          //as we already copied check till window so we can skip checking window char and start from char just after window(R+ 1)
          //j = r+1
          //So K,as we Know l is representing 0 index K = r-l+1.
          //K is left pointer.
          //j is right pointer.
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
