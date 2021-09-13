class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord == endWord) return 0;

        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return 0;
        
        unordered_set<string>s;
        for(auto st:wordList) s.insert(st);
        
        queue<string>q;
        q.push(beginWord);
        int len = 0;
        
        while(!q.empty()) {
            len++;
            int n=q.size();
            for(int i=0;i<n;i++) {
                string word = q.front();
                q.pop();
                string final = word;
                
                for(int w=0;w<word.size();w++)
                {
                    for(char c='a';c<='z';c++)
                    {
                        word[w]=c;
                        
                        if(word == endWord)
                            return 1+len;
                        
                        if(s.find(word) == s.end()) continue;
                        
                        q.push(word);
                        s.erase(word);
                    }
                    
                    word = final;
                }
            }
        }
        
        return 0;
    }
};
