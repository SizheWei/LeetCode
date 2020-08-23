//
//  main.cpp
//  TA_test
//
//  Created by 魏思哲 on 4/4/20.
//  Copyright © 2020 SizheWei. All rights reserved.
//

#include<iostream>
#include<vector>
#include<string>

using namespace std;
class priorityQueue{
  private:
     vector<int> s;
  public:
  void insert(int x)
     {
      if(s.empty()) {s[0]=x; return;}
      int temp=s.size();//cout<<temp<<endl;
      for(;temp>0&&x<s[(temp-1)/2];temp=(temp-1)/2)
      s[temp]=s[(temp-1)/2];
      s[temp]=x;
     }
     void find(int x)
     {int lens=s.size(),i=0,maxMIN=s[lens-1],maxMINj=lens-1;
      for(;i<lens;++i)
      {if(s[i]==x) break;
      }
      for(int j=i+1;j<lens-1;++j)
      {if(s[j]<=maxMIN) {maxMIN=s[j];maxMINj=j;}
      }
      cout<<maxMINj+1<<endl;
     }
    void decrease(int i,int v)
    {int x=s[i-1]-v,j=i-1;
    if(i==1){s[0]-=v; return;}
     for(;j>0&&x<s[(j-1)/2];j=(j-1)/2)
      s[j]=s[(j-1)/2];
      s[j]=x;
    }
};

int main()
{int nums;
 priorityQueue Q;
 cin>>nums;

for(int j=0;j<nums;++j){
 string str; cin.ignore();
 getline(cin,str);
if(str=="insert")
  {int p;
   cin>>p;
   Q.insert(p);
  }
else if(str=="find")
  {int p;
   cin>>p;
   Q.find(p);
  }
 else {int p,q;
       cin>>p>>q;
       Q.decrease(p,q);
      }
 }
 return 0;
}


