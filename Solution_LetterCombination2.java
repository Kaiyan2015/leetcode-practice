/**
* Iterative Solution
* Code is more simple
* From Discuss, original in c, I rewrite it in java
*/

public class Solution_LetterCombination2 {
    public List<String> letterCombinations(String digits) {
        String[] mapping = {"0", "1", "abc", "def", "ghi","jkl", "mno", "pqrs", "tuv","wxyz"};
        LinkedList<String> res = new LinkedList<String>();
        res.add("");
        
        if(digits.length() == 0){
            //System.out.println("NA");
            return new LinkedList<String>();
        }
        
        for(int i = 0; i < digits.length(); ++i){
            LinkedList<String> tmp = new LinkedList<String>();
            String letters = mapping[digits.charAt(i) - '0'];
            for(int j = 0; j < letters.length(); ++j){
                for(int k = 0; k < res.size(); ++k){
                    tmp.add(res.get(k)+letters.charAt(j));
                }
            }
            res = tmp;
        }
        return res;
    }
}