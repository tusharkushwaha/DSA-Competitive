#include <iostream>
#include <vector>
using namespace std;

void toh(int n, char from, char to, char Using){
   if(n==1) {cout<<n<<" : "<<from<<" ---> "<<to<<endl; return;}
   toh(n-1, from, Using,to);
   cout<<n<<" : "<<from<<" ---> "<<to<<endl;
   toh(n-1, Using, to, from);
}

int main(){
   int n=4; char from='A'; char to= 'B';
   char Using = 'C';
   toh(n,from,to,Using);

   return 0;
}