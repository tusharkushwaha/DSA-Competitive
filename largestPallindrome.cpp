#include <iostream>
#include <vector>
using namespace std;

string longestPalindrome(string s)
{
   int n = s.length();
   int l;
   int h;
   pair<int, int> {0,0};
   int count=0;
   for (int i = 0; i < n; i++)
   {
      l = i;
      h = i + 1;
      while (s[l] == s[h] && l >= 0 && h < n)
      {
         if ((h - l) > count)
         {  
            count= h-l;
            p = {l, h};
         }
         l--;
         h++;
      }
      l=i; h=i+2;
      while (s[l] == s[h] && l >= 0 && h < n)
      {
         if ((h - l) > count)
         {  
            count= h-l;
            p = {l, h};
         }
         l--;
         h++;
      }
   }
   string result= s.substr(p.first,p.second+1);
   
   return result;

   }

int main()
{
   string S = "babad";
   cout << longestPalindrome(S);
   return 0;
}