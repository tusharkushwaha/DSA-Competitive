#include<bits/stdc++.h>
using namespace::std;

int opr(int &val1, int &val2, char op){
    switch(op){
        case '+': return val1 + val2;
        case '-': return val1 - val2;
        case '*': return val1 * val2;
        case '/': return val1 / val2;
    }
}

int value(string s){
    stack<int>st; int n = s.length(); int val1; int val2;
    for(int i = 0; i<n; i++){
        if(isdigit(s[i]) != 0) st.push(s[i] - '0');
        else{
            val2 = st.top(); st.pop(); val1 = st.top(); st.pop();
            st.push(opr(val1, val2, s[i]));
        }
    }
    return st.top();
}
vector<string> toprefix(string s){
    stack<string>infix, prefix; string val1, val2;
    int n = s.length();
    for(int i=0; i<n; i++){
        if(isdigit(s[i])){
            val1 = s[i];
            prefix.push(val1); infix.push(val1);
        } 
        else{
            val2 = prefix.top(); prefix.pop(); val1 = prefix.top(); prefix.pop();
            prefix.push(s[i]+val1+val2);
            val2 = infix.top(); infix.pop(); val1 = infix.top(); infix.pop();
            infix.push("("+val1+s[i]+val2+")");
            
        }
    }
    return {infix.top(), prefix.top()};
}
int main(){
    string s;
    getline(cin, s);
    cout<<value(s)<<endl;
    auto result = toprefix(s);
    for(auto &i: result){
        cout<<i<<endl;
    }
    
}

