class Solution {
public:
    bool isValid(string chulu) {
       stack<char> s;
       
       for(char uv : chulu ){
        if(uv == '[' || uv == '{' || uv == '('){
            s.push(uv);
        }
        else{
            if(s.empty()){
                return false;
            }
            char top = s.top();
            if(uv == '}' && top != '{')return false;
            if(uv == ')' && top != '(' )return false;
            if(uv == ']' && top != '[')return false;
            s.pop();
        }
       }
       return s.empty();
    }
};