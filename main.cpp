class Solution {
public:
    //DFS
    class Solution {
public:
    //DFS
    bool isMatch(string s, string p) {
        if(s.length() == 0 && p.length() == 0) return true;
        if(p.length() == 0) return false;
        //if(s.length() == 0) return false;
        int s_ptr = 0, p_ptr = 0;
        //vector<vector<bool>> res (s.length(), vector<int> (p.length(), false));
        int preP = -1, preS = -1;
        while(s_ptr < s.length()){
            //if(s_ptr == s.length() - 1 && p_ptr < p.length() - 1) return false;
            
            if(p_ptr < p.length() && isTwoMatch(s[s_ptr],p[p_ptr])){
                p_ptr ++;
                s_ptr ++;
            }else if(p[p_ptr] == '*' && p_ptr < p.length()){
                //if(p_ptr == p.length()) return true;
                preP = (p_ptr ++);
                preS = s_ptr;
            }else if(preP != -1){//if other char
                p_ptr = preP;
                s_ptr = ++ preS;
                p_ptr ++;
            }else{
                return false;
            }//end main if
        }//end while
        while(p_ptr < p.length()){
            if(p[p_ptr] == '*'){
                p_ptr ++;
            }else{
                return false;
            }
        }
        return true;
    }
    bool isTwoMatch(char a, char b){
        return a == b || b == '?';
    }
};


    //memory limit exceeds
    /*
    bool isMatch(string s, string p) {
        if(s.length() == 0 && p.length() == 0) return true;
        if(p.length() == 0) return false;
        if(s.length() == 0) return false;
        
        if(p[0] == '?'){
            return isMatch(s.substr(1), p.substr(1));
            
        }else if(p[0] == '*'){
            if(p.length() == 1) return true;
            return isMatch(s.substr(1), p);
            
        }else{
            if(s[0] == p[0]){
                return isMatch(s.substr(1), p.substr(1));
            }else{
                return false;
            }
        }
    }
    */
};
