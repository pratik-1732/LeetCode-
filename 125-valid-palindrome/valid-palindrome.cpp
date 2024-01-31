class Solution {
public:
    bool isPalindrome(string s) {
        int n= s.length();

        for (int i=0; i<s.size(); i++) {
		    int temp=(int) s[i];
		// if (s[i] < 'A' || s[i] > 'Z' && s[i] < 'a'|| s[i] > 'z' && s[i]<0 || s[i]>9) {
		// 	s.erase(i, 1);
		// 	i--;
		// }
		    if(temp<48 || temp>57 && temp<65 || temp>90 && temp<97 || temp>122){
			    s.erase(i,1);
			    i--;
		    }
		}

        for(int i=0; i<n; i++){
		    char ch=s[i];
		    s[i]=tolower(ch);
	    }

	    n=s.length();
        // if(n==1) return true;
        
	    for(int i=0; i<n/2; i++){
		    if(s[i]!=s[n-1-i]) return false;
	    }

	    return true;
	
    }
};