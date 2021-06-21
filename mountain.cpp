#include <iostream>
using namespace std;
#include <vector>

int mountian(vector<int> a)
{
   int n = a.size();
   int result, temp = 1;
   int d = 0;
   for (int i = 0; i < n; i++)
   {
      if (d == 0 && a[i + 1] > a[i])
         temp++;
      else if (d == 0 && i > 0 && a[i] > a[i - 1] && a[i + 1] < a[i])
      {
         temp++;
         d = 1;
      }
      else if (d == 1 && a[i + 1] > a[i])
      {  temp++;
         if (result < temp)
         {
            result = temp;
         }
         temp = 1;
         d = 0;
      }
      else if (d > 0)
         temp++;
   }
   if (result >= 3)
      return result;
   return 0;
}

int main()
{
   vector<int> a{5, 6, 1, 2, 3, 4, 5, 4, 3, 2, 0, 1, 2, 3, -2, 4};

   int result = mountian(a);
   cout << result;
   return 0;
}