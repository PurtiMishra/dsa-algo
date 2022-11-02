class Solution {
public:
   bool check(string &s, int i, int j)
{
    while (i <= j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        i++, j--;
    }
    return true;
}
string longestPalindrome(string s)
{
    int n = s.length();
    int max_len = 0;
    int starting_index = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (check(s, i, j))
            {
                if (j - i + 1 > max_len)
                {
                    max_len = j - i + 1;
                    starting_index = i;
                }
            }
        }
    }
    return s.substr(starting_index, max_len);
}
int main()
{
    string s = "babad";
    cout << longestPalindrome(s) << endl;
    return 0;
}
};