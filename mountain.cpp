#include <iostream>
using namespace std;
#include <vector>

int mountian(vector<int> arr)
{
   int n = arr.size();
   if(n<=2) return 0;
   int result=1;
   int temp = 0;
   int d = 0;
   for (int i = 0; i < n; i++)
   {
      if (d == 0 && arr[i + 1] > arr[i])
         temp++;
      else if (d == 0 && i > 0 && arr[i] > arr[i - 1] && arr[i + 1] < arr[i])
      {
         temp++;
         d = 1;
      }
      else if (i==n-1 || (d == 1 && arr[i + 1] > arr[i]))
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
   // if(temp>result) result=temp;
   if (result >= 3)
      return result;
   return 0;
}

int main()
{
   vector<int> a{0,1,0,1};

   int result = mountian(a);
   cout << result;
   return 0;
}