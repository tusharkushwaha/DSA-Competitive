// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& arr, int n) 
    {
        stack<int> st;
        for(int i = 0; i<n; i++){
            st.push(i);
        }
        int val1, val2;
        for(int i =0 ; i<n-1; i++){
            val2 = st.top(); st.pop() ; val1 = st.top(); st.pop();
            if(arr[val1][val2] == 0) st.push(val1);
            else st.push(val2);
        }
        for(int i = 0; i<n; i++){
            if(arr[st.top()][i] == 1) return -1;
            
        }
        for(int i = 0; i<n; i++) {
            if(arr[i][st.top()] == 0 and i!= st.top()) 
            return -1;
            
        }
        return st.top();
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends