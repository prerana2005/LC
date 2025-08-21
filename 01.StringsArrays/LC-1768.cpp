//Merge Strings Alternatively

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";
        int i = 0;
        while(i<min(word1.length(),word2.length())){
            result += word1[i];
            result += word2[i];
            i++;
        }
        while(i<word1.length()){
            result += word1[i];
            i++;
        }
        while(i<word2.length()){
            result += word2[i];
            i++;
        }
        return result;
    }
};
