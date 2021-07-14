#include <iostream>
#include <vector>
using namespace std;

string countAndSay(int n)
{
   if (n == 0)
      return " ";
   else if (n == 1)
      return "1";
   else
   {
      string tempstring = "1"; string result;
      char letter = tempstring[0];
      int j = 0;
      int strlenght;
      for (int i = 1; i < n; i++)
      {
         
         
         int count = 0; result= tempstring; tempstring.clear();
         strlenght = result.length(); letter = result[0];
         int poiner=0;j=0;
         while (j < strlenght)
         {
            if (j == strlenght - 1 && result[j] != letter)
            {
               tempstring += to_string(count);
               tempstring.push_back(result[j - 1]);
               tempstring.push_back('1');
               tempstring.push_back(result[j]);
               
            }
            else if (result[j] != letter)
            {
               tempstring += to_string(count);
               tempstring.push_back(result[j - 1]);
               letter = result[j];
               count = 1;
               j++;
               continue;
            }

            else if (j == strlenght - 1)
            {
               tempstring += to_string(++count);
               tempstring.push_back(result[j]);
               
            }
            count++;
            j++;
         }
      }
      return tempstring;
   }
}

int main()
{
   int n = 5;
   string s = countAndSay(n);
   cout << s;
   return 0;
}