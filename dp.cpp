#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int recursionFib(int n){
   if(n==1 or n==2) return n-1;
   return recursionFib(n-1)+recursionFib(n-2);
}
int memomizationfib(int n, vector<int> *qb){
   if(n==1 or n==2) return n-1;
   if(qb[n-1] != 0) return qb[n-1];
   cout<<n-1<<endl;
   qb[n-1] = memomizationfib(n-1,qb) + memomizationfib(n-2, qb);
   return qb[n-1];
}
int tabulation(int n, vector<int> qb){
   qb[0]=0; qb[1]= 1;
   for(int i=2; i<n; i++){
      qb[i]= qb[i-1]+qb[i-2];
   }
   return qb[n-1];
}
int main(){
   int n=10;
   vector<int>qb(n,0);
   cout<< memomizationfib(n,&qb);
   return 0;
}

