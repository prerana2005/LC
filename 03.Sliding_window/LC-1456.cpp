class Solution {
public:
    int maxVowels(string s, int k) {
        int windowvowels = 0;
        int maxvowels = 0;

        unordered_set<char> vowels = {'a','e','i','o','u'};

        for(int i =0; i<k; i++){
            if(vowels.count(s[i]))
            windowvowels++;
        }
        maxvowels = windowvowels;
        
        for(int i=k;i<s.size();i++){
            if(vowels.count(s[i-k]))
            windowvowels--;
            if(vowels.count(s[i]))
            windowvowels++;

            maxvowels = max(maxvowels,windowvowels);
        }
        return maxvowels;
    }
};