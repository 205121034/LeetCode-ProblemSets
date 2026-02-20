class Solution {
private:
    int count(int n){
        int ans=0;
        for(int i=6;i>=0;i--){
            if(n>>i & 1)ans++;
        }
        return ans;
    }
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string>a;
        if(turnedOn==9 || turnedOn==10){return a;}
        for(int i=0;i<12;i++){
            for(int j=0;j<60;j++){
                if(count(i)+count(j)==turnedOn){
                    string s="";
                    s+=to_string(i);
                    s+=":";
                    if(j<10)s+="0";
                    s+=to_string(j);
                    a.push_back(s);
                }
            }
        }
        return a;
    }
};