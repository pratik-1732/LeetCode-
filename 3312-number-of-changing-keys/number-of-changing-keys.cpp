class Solution {
public:
    int countKeyChanges(string s) {
        int n = s.length();
	    string temp;
	    for(auto i: s){
		    i = tolower(i);
		    temp+=i;
	    }
	    // cout<<temp<<endl;
	    int cnt=0;
	    for(int i=0; i<n; i++){
		    if(temp[i]!=temp[i+1] && i!=n-1) cnt++;
	    }
        return cnt;
    }
};