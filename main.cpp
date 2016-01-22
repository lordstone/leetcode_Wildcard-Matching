class Solution {
public:
    //DFS
    bool isMatch(string s, string p) {
        if(s.length() == 0 && p.length() == 0) return true;
        if(p.length() == 0) return false;
        if(s.length() == 0) return false;
        int s_ptr = 0, p_ptr = 0;
        //vector<vector<bool>> res (s.length(), vector<int> (p.length(), false));
        stack<pair<int, int>> stkStars;
        while(p_ptr < p.length() || s_ptr < s.length()){
            //if(s_ptr == s.length() - 1 && p_ptr < p.length() - 1) return false;
            if(s_ptr == s.length() - 1 && p_ptr == p.length() - 1) return true;
            if(p[p_ptr] == '?'{
                if(p_ptr == p.length() - 1 && s_ptr == s.length() - 1){
                    return true;
                }else if(s_ptr == s.length() - 1 || p_ptr == p.length() - 1){
                    if(stkStars.size() == 0){
                        return false;
                    }else{
                        stkStars.pop();
                        p_ptr = stkStars.top().second;
                        s_ptr = stkStars.top().first;
                    }
                }else{
                    p_ptr ++;
                    s_ptr ++;
                }
            }else if(p[p_ptr] == '*'){
                if(s_ptr == s.length() - 1) return true;
                if(p_ptr == p.length() - 1) return true;
                stkStars.push(pair<int, int> (s_ptr, ++p_ptr));
            }else{//if other char
                if(s[s_ptr] == p[p_ptr]){
                    s_ptr ++; p_ptr ++;
                }else{//if not match
                    if(stkStars.size() == 0){//if no * available
                        return false;
                    }else{//if there is star
                        if(p_ptr == p.length() - 1 || s_str == s.length() - 1){
                            //if already cannot make it on current star at the end
                            stkStars.pop();
                            if(stkStars.empty()) return false;
                            p_ptr = stkStars.top().second;
                            s_ptr = stkStars.top().first;
                        }else{//if not till the end, use the next star
                            p_ptr = stkStars.top().second;
                            s_ptr = ++ (stkStars.top().first);//increment the s start point
                        }
                    }
                }
            }//end main if
        }//end while
        return true;
    }//end main func
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
