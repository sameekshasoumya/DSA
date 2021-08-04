/*

Given a string s, sort it in decreasing order based on the frequency of characters, and return the sorted string.

*/

//using custom comp
class comp
{
public:
    bool operator()(pair<char, int> const &a, pair<char, int> const &b)
    {
        return a.second < b.second;
    }
};
string frequencySort(string s)
{
    unordered_map<char, int> hash;
    for (auto i : s)
        hash[i]++;
    priority_queue<pair<char, int>, vector<pair<char, int>>, comp> heap;
    for (auto i : hash)
        heap.push(make_pair(i.first, i.second));
    string ans = "";
    //s=""; i.e the old string can be reutilized
    while (!heap.empty())
    {
        char curr = heap.top().first;
        heap.pop();
        while (hash[curr]--)
            ans += curr;
    }
    return ans;
}

//without custom comp
//utilizing the property that heap will sort based on the first element. so we create a max heap with freq as first element of heap
//to save space, we redeclare the string s given;

string frequencySort(string s)
{
    unordered_map<char, int> hash;
    for (auto i : s)
        hash[i]++;
    priority_queue<pair<int, char>> heap;
    for (auto i : hash)
        heap.push(make_pair(i.second, i.first));
    s = "";
    while (!heap.empty())
    {
        char curr = heap.top().second;
        int char_freq = heap.top().first;
        heap.pop();
        while (char_freq--)
            s += curr;
    }
    return s;
}