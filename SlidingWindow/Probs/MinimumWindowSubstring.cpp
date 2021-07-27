/*

Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

A substring is a contiguous sequence of characters within the string.

*/

/*

Solution : 

The question asks us to return the minimum window from the string SS which has all the characters of the string TT. Let us call a window desirable if it has all the characters from TT.

We can use a simple sliding window approach to solve this problem.

In any sliding window based problem we have two pointers. One rightright pointer whose job is to expand the current window and then we have the leftleft pointer whose job is to contract a given window. At any point in time only one of these pointers move and the other one remains fixed.

The solution is pretty intuitive. We keep expanding the window by moving the right pointer. When the window has all the desired characters, we contract (if possible) and save the smallest window till now.

The answer is the smallest desirable window.

*/

string minWindow(string s, string t)
{
    int min_len = INT_MAX, len = 0;
    int ptr_front = 0, count = 0, start = -1;
    unordered_map<char, int> hash_s, hash_t;
    //storing every char of t in hashmap
    for (char i : t)
        hash_t[i]++;
    for (int i = 0; i < s.size(); i++)
    {
        hash_s[s[i]]++;
        //if the char is common in both the strings and freq_of_char_s < freq_of_char_t we increment the count variable
        if ((hash_t[s[i]] > 0) && (hash_s[s[i]] <= hash_t[s[i]]))
            count++;
        //if count is equal to length of t
        if (count == t.length())
        {
            while (hash_t.find(s[ptr_front]) == hash_t.end() || hash_t[s[ptr_front]] < hash_s[s[ptr_front]])
            {
                hash_s[s[ptr_front]]--;
                ptr_front++;
            }
            len = i - ptr_front + 1;
            if (min_len > len)
            {
                min_len = len;
                start = ptr_front;
            }
        }
    }
    if (start == -1)
        return "";
    return s.substr(start, min_len);
}