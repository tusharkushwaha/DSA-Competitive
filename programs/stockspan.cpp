// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        int left[n] ; stack<int> s;
        for(int i=0; i<n; i++){
            while(s.empty() != false and arr[s.top()]>=arr[i]){
                s.pop();
            }
            if(s.empty()==true) left[i]= i;
            else left[i] = i-st.top;
            s.push(arr[i]);
        }
        int right[n] ; stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(st.empty() != false and arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()==true) right[i]= n+1 - i;
            else right[i] = st.top() - i-1;
            st.push(arr[i]);
        }
        long long result = 0;
        for(i =0; i<n;i++){
            if(reslt < arr[i] * (left[i] + right[i] +1))
            result =arr[i] * (left[i] + right[i] +1);
        }
        return result;
        
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends