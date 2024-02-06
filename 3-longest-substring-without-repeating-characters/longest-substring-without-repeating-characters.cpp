class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
	   if(s.empty()) return 0;
	
    if(s==" ") return 1;

	
	    map<string,int> lenCount;
	    int count=0; string ans;
	    map<char,int> cntAlpha;
	    
	    for(int i=0; i<s.length(); i++){
	    	// cout<<i<<endl;
            // if(s[i]==' ') continue;
		    cntAlpha[s[i]]++;
		    if(cntAlpha[s[i]]==1){
			    count++;
			    ans+=s[i];
			    lenCount.insert({ans,count});
		    }
		    else{
		    	i=i-count;
			    // cntAlpha[s[i]-'a']=0;
			    // fill(cntAlpha.begin(), cntAlpha.end(), 0);
                cntAlpha.clear();
			    count=0;
			    ans="";
		    }
	    }
	    int len=INT_MIN;
	    for(auto i: lenCount){
		    // cout<<i.first<<" "<<i.second<<endl;
		    len=max(len,i.second);
	    }
	    //map<string, int>::iterator itr;

        // Display the last element in m.
  	    // itr = lenCount.end();
  	    // --itr;
  	
  	    // int len=itr->second;
          if(len==INT_MIN) return 1;

  	    return len;
    }
};