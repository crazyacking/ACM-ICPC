class Solution
{
public:

    vector<int> findSubstring(string s, vector<string> &words)
    {
        vector<int> ans;
        int n = s.size(), cnt = words.size();
        if (n <= 0 || cnt <= 0) return ans;

        // init word occurence
        unordered_map<string, int> dict;
        for (int i = 0; i < cnt; ++i)  //统计每个单词出现的次数
            dict[words[i]]++;

        // travel all sub string combinations
        int wl = words[0].size();
        for (int i = 0; i < wl; ++i)
        {
            int left = i, continueWords = 0;
            unordered_map<string, int> tdict;
            for (int j = i; j <= n - wl; j += wl)
            {
                string str = s.substr(j, wl);
                // a valid word, accumulate results
                if (dict.count(str))
                {
                    tdict[str]++;
                    if (tdict[str] <= dict[str])
                        continueWords++;
                    else
                    {
                        // a more word, advance the window left side possiablly
                        while (tdict[str] > dict[str])
                        {
                            string str1 = s.substr(left, wl);
                            tdict[str1]--;
                            if (tdict[str1] < dict[str1]) continueWords--;
                            left += wl;
                        }
                    }

                    // come to a result
                    if (continueWords == cnt)
                    {
                        ans.push_back(left);
                        // advance one word
                        tdict[s.substr(left, wl)]--;
                        continueWords--;
                        left += wl;
                    }
                }
                // not a valid word, reset all vars
                else
                {
                    tdict.clear();
                    continueWords = 0;
                    left = j + wl;
                }
            }
        }
        return ans;
    }
};
