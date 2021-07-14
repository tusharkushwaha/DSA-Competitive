#include <iostream>
#include <vector>
using namespace std;
#include <unordered_map>

void isPlaindrome(string s1, string s2)
{
   string temp = s1+s1;
   cout<<temp.find(s2);;
}
int main()
{
   string s1 = "tushar kushwha";
   string s2 ="sffh";
   isPlaindrome(s1, s2);
   return 0;

}