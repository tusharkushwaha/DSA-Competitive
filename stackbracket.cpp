#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
   stack<char> st;
   string s;
   getline(cin, s);
   for (int i = 0; i < s.length(); i++)
   {
      if(s[i]== ')'){
         if(st.top() == '('){
            cout<<true;
            break;
         }
         while(st.top() != '('){
            st.pop();
         }
         st.pop();
         if(i==s.length()-1) cout<<false;
      }
      else{
         st.push(s[i]);
      }
   }
   return 0;
}

