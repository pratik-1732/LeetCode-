class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        // int j=0;
        // for(auto i: mps){
            //     if(i.first!=(mpt[j]).first && i.second!=(mpt[j]).second) return false;
            //     else j++;
        // }
        // set<map<char,int> > setOfMaps; 
        // setOfMaps.insert(mps); 
        // setOfMaps.insert(mpt);
    
        // int n=0;
        // auto it=setOfMaps.begin();
        // advance(it,n);
     
        // // Printing the element at index n
        // cout<<*it;

        vector<int> counts(26,0);
        vector<int> countt(26,0);
        //cout<<s<<" "<<t<<endl;
        for(int i=0; i<s.length();i++){
            counts[(s[i]-'a')]++;
        }
        for(int i=0; i<t.length();i++){
            countt[(t[i]-'a')]++;
        }
        if(counts==countt) return true;
        else return false;
    }
};