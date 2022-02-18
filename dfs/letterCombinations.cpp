class Solution {
public:
    vector<string> letterCombinations(string digits) {
		vector<string> result;

		if(digits.size() == 0) return result;
        unordered_map <char, string> numMap;
        numMap['2']="abc";
        numMap['3']="def";
        numMap['4']="ghi";
        numMap['5']="jkl";
        numMap['6']="mno";
        numMap['7']="pqrs";
        numMap['8']="tuv";
        numMap['9']="wxyz";
        dfs(result, "" , 0, digits, numMap );
        return result;
    }
    
    void dfs(vector<string>& result, string current, int level, string digits, unordered_map <char, string>& numMap ){
        if (level == digits.size()){  // base case
			result.push_back(current);
			return; 
		}
		
		string letters = numMap[digits[level]]; // get abc
        for(int i = 0; i < letters.size(); ++i){  // loop a, b, c
			letter = letters[i];
			current = current + letter; // ae
			dfs(result, current, level + 1, digits, numMap );
			current = "";
        }
    }
};