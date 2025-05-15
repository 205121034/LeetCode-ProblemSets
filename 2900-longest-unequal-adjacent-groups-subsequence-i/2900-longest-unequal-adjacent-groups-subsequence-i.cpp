class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        for(int i=0;i<words.size()-1;i++){
            while(i+1 != words.size() && groups[i] == groups[i+1]){
                words.erase(words.begin()+i+1);
                groups.erase(groups.begin()+i+1);
            }
        }
        return words;
    }
};