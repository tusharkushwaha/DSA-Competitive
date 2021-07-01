#include <iostream>
#include <vector>
#include <typeinfo>
#include <string>
using namespace std;

vector<int> stringSearch(string big, string small)
{
   vector<int> result = {};
   int it = big.find(small);
   if (it == -1)
      return {};
   result.push_back(it);
   while (true)
   {
      it = big.find(small, it + 1);
      if (it == -1)
         break;
      result.push_back(it);
   }
   return result;
}

int main()
{
   string arr{"I like the movie the very the much the"};
   auto p = stringSearch(arr, " ");
   for (auto &&i : p)
   {
      cout << i << " ";
   }

   return 0;
}