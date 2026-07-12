class Solution {
public:
    bool isPalindrome(int x) {
    int dup=x;
    long long resNum=0;
    while (x>0){
        int lastdigit = x%10;
        resNum = (resNum*10)+lastdigit;
        x=x/10;
    }
    if (resNum == dup){
        return true;
    }
    else {
        return false;
    }
        
    }
};
