/**
* This solution program is only for letter combination of a phone number for leetcode
* Recursive programming
* By KY
*/
public class Solution_LetterCombination{
    private String[] mapping = {"0", "1", "abc", "def", "ghi","jkl", "mno", "pqrs", "tuv","wxyz"};
    
    public List<String> letterCombinations(String digits) {
        LinkedList<String> res = new LinkedList<String>();
        res = recursive(new LinkedList<String>(), digits);
        return res;
    }
        
    
    
    
    private LinkedList<String> recursive(LinkedList<String> previous, String digits){
        
        
        if(digits.length() == 0){
            System.out.println("NA");
            return new LinkedList<String>();
        }
        int num = digits.charAt(0) - '0';
        LinkedList<String> l1 = new LinkedList<String>();
        
        if(previous.size() == 0){
            
            for(char s : mapping[num].toCharArray()){
                String tmp = "";
                tmp += s;
                l1.add(tmp);
                //tmp = "";
            }
        }
        else{
            for(int i = 0; i < previous.size(); ++i){
                for(char s : mapping[num].toCharArray()){
                    String tmp = previous.get(i);
                    tmp += s;
                    l1.add(tmp);
                }
            }
        }
        if(digits.length() == 1) return l1;
        return recursive(l1,digits.substring(1));
    }
    
}


