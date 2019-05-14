#include <iostream>
#include<vector>
using namespace std;

int main(){
  vector<int> v = {1,1,1,1,1,1,1,1};
  for(int &i: v)
    i =0;
  while(true){for(int i: v)
    cout<<i<<" ";}
  return 0;
}
