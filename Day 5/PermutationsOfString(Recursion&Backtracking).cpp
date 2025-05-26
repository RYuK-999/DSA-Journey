class Solution {
  public:
    void permute(string &s,int index,vector<string>& result){
        if (index==s.size()){
            result.push_back(s);
            return;
        }
        
        unordered_set<char> used;    //using to avoid duplicate
        
        for (int i=index;i<s.size();i++){
            if (used.find(s[i])!=used.end()){
                continue;
            }
            used.insert(s[i]);
            
            swap(s[index],s[i]);                // Choosing
            permute(s,index+1,result);          // Exploring
            swap(s[index],s[i]);                // Unchoosing (Backtracking)
        }
    }
    
    
    vector<string> findPermutation(string &s) {
        vector<string> result;
        int index = 0;
        
        permute(s,index,result);
        
        return result;
    }
};

/* Step by Step Explanation
Initial string: "ABC"

Call: permute("ABC", index = 0)
Loop i = 0 to 2:

1️⃣ i = 0
Swap s[0] with s[0] → "ABC" (no change)

🔁 Call permute("ABC", index = 1)

Call: permute("ABC", index = 1)
Loop i = 1 to 2

a. i = 1
Swap s[1] with s[1] → "ABC" (no change)

🔁 Call permute("ABC", index = 2)

Base case → Add "ABC" to result
⬅️ Backtrack: Swap s[1] with s[1] → "ABC" (no change)

b. i = 2
Swap s[1] with s[2] → "ACB"

🔁 Call permute("ACB", index = 2)

Base case → Add "ACB" to result
⬅️ Backtrack: Swap s[1] with s[2] → "ABC"

⬅️ Backtrack to index = 0: Swap s[0] with s[0] again → "ABC" (no change)

2️⃣ i = 1
Swap s[0] with s[1] → "BAC"

🔁 Call permute("BAC", index = 1)

Call: permute("BAC", index = 1)
Loop i = 1 to 2

a. i = 1
Swap s[1] with s[1] → "BAC"

🔁 Call permute("BAC", index = 2)

Base case → Add "BAC" to result
⬅️ Backtrack: swap s[1] with s[1] → "BAC"

b. i = 2
Swap s[1] with s[2] → "BCA"

🔁 Call permute("BCA", index = 2)

Base case → Add "BCA" to result
⬅️ Backtrack: swap s[1] with s[2] → "BAC"

⬅️ Backtrack to index = 0: Swap s[0] with s[1] → "ABC"

3️⃣ i = 2
Swap s[0] with s[2] → "CBA"

🔁 Call permute("CBA", index = 1)

Call: permute("CBA", index = 1)
Loop i = 1 to 2

a. i = 1
Swap s[1] with s[1] → "CBA"

🔁 Call permute("CBA", index = 2)

Base case → Add "CBA" to result
⬅️ Backtrack: swap s[1] with s[1] → "CBA"

b. i = 2
Swap s[1] with s[2] → "CAB"

🔁 Call permute("CAB", index = 2)

Base case → Add "CAB" to result
⬅️ Backtrack: swap s[1] with s[2] → "CBA"

⬅️ Backtrack to index = 0: Swap s[0] with s[2] → "ABC"
*/