/*
1773. Count Items Matching a Rule


You are given an array items, where each items[i] = [typei, colori, namei] describes the type, 
color, and name of the ith item. You are also given a rule represented by two strings, ruleKey and ruleValue.

The ith item is said to match the rule if one of the following is true:

ruleKey == "type" and ruleValue == typei.
ruleKey == "color" and ruleValue == colori.
ruleKey == "name" and ruleValue == namei.
Return the number of items that match the given rule.

*/

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int count = 0;
        int row = items.size();
        int col = items[0].size();

        if(ruleKey == "type"){
            col = 0;
            for(int i = 0; i < row; i++){
                if(items[i][col] == ruleValue)
                    count++;
            }
        }

        else if(ruleKey == "color"){
            col = 1;
            for(int i = 0; i < row; i++){
                if(items[i][col] == ruleValue)
                    count++;
            }
        }

        else if(ruleKey == "name"){
            col = 2;
            for(int i = 0; i < row; i++){
                if(items[i][col] == ruleValue)
                    count++;
            }
        }


        return count;

    }
};
