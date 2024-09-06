class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n= beginWord.length();

        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);

        int ans=0;

        while(!q.empty()){
            string word= q.front().first;
            int len= q.front().second;
            q.pop();

            if(word==endWord) return len;
            
            int i=0;
            while(i<n){
                string temp= word;
                for(char ch='a'; ch<='z'; ch++){
                    temp[i]= ch;
                    if(st.find(temp)!=st.end()){
                        st.erase(temp);
                        q.push({temp, len+1});
                    }
                }
                i++;
            }
        }
        return ans;
    }
};