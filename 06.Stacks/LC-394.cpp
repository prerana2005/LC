class Solution {
public:
    string decodeString(string s) {
        stack<int> numstack;
        stack<string> strstack;
        string curr = "";
        int k = 0;

        for(char c:s){
            if(isdigit(c)){
                k = k*10 + (c-'0');
            }
            else if(c=='['){
                numstack.push(k);
                strstack.push(curr);
                k=0;
                curr="";
            }
            else if(c==']'){
                string temp = curr;
                curr = strstack.top();
                strstack.pop();

                int count = numstack.top();
                numstack.pop();

                for(int i =0; i<count; i++){
                    curr += temp;
                }
            }
            else
            curr.push_back(c);
        }
        return curr;
    }
};