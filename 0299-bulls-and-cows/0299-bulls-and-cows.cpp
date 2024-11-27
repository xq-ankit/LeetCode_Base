class Solution {
public:
    string getHint(string secret, string guess) {
        int b=0,c=0;
        map<char,int>mpp;
        for(char c:guess){
            mpp[c]++;
        }
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]){
                b++;
                secret[i]='*';
                mpp[guess[i]]--;
                if(mpp[guess[i]]==0) mpp.erase(guess[i]);
            }
        }
        for(int i=0;i<secret.size();i++){
            if(mpp.find(secret[i])!=mpp.end()){
                c++;
                mpp[secret[i]]--;
                if(mpp[guess[i]]==0) mpp.erase(guess[i]);
            }
        }
        string ans="";
        
        ans+=to_string(b)+'A'+to_string(c)+'B';
        return ans;

            }
};