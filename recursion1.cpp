#include <iostream>
#include <vector>
using namespace std;

int recursion(int x, int n){
   if (n==1)
   {
      return x;
   }
   int rn = x* recursion(x, n-1);
   return rn;

}

int main(){
   int x=5; int n=2;
   cout<<recursion(5,2);
   return 0;
}