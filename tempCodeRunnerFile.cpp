int main()
{
   stack<char> st;
   string s;
   getline(cin, s);
   for (int i = 0; i < s.length(); i++)
   {
      st.push(s[i]);
   }
   return 0;
}