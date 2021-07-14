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
      if (s[i] == ')')
      {
         if(st.empty()== true){
            cout<<false;
            break;
         }
         while (st.top() != '(')
         {
            if (st.top() == '{')
            {
               cout << false;
               break;
            }
            if (st.top() == '[')
            {
               cout << false;
               break;
            }
         }
         st.pop();
      }
      else if (s[i] == '}'){
         if(st.empty()== true){
            cout<<false;
            break;
         }
         while (st.top() != '{')
         {
            if(st.top()=='('){
               cout<<false;
               break;
            }
            if(st.top()== '['){
               cout<<false;
               break;
            }
         }
         st.pop();
      }
      else if(s[i] == ']'){
         if(st.empty()== true){
            cout<<false;
            break;
         }
         while (st.top() != ']')
         {
            if(st.top() == '('){
               cout<<false;
               break;
            }
            if(st.top() == '{'){
               cout<< false;
               break;
            }
         }
         st.pop();
      }
      else{
         st.push(s[i]);
      }
      
   }
   return 0;
}