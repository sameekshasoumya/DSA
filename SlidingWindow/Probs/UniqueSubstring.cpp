/*

Given a string s, find the length of the longest substring without repeating characters.

*/

//O(N) time, O(N) space  : hashmap

int lengthOfLongestSubstring(string s)
{
    int len = 0;
    unordered_map<char, int> hash;
    //initialize both front and end pointer with 0. We maintain a lookup (hashmap) for last index of char occurence
    int ptr_front = 0, ptr_back = 0;
    //DRY RUN
    //a a b a a b ! b b
    //          i
    //        j
    while (ptr_front < s.size())
    {
        if (hash.find(s[ptr_front]) == hash.end())
        {
            hash[s[ptr_front]] = ptr_front;
        }
        else if (!(hash[s[ptr_front]] < ptr_back))
        {
            ptr_back = hash[s[ptr_front]] + 1;
            hash[s[ptr_front]] = ptr_front;
        }
        else
        {
            hash[s[ptr_front]] = ptr_front;
        }
        len = max(len, (ptr_front - ptr_back) + 1);
        ptr_front++;
    }
    return len;
}