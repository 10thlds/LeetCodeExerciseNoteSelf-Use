class FirstSolution
{
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs)
    {
        if(strs.empty()) return "";

        // 1. Find the min size of strings
        int min_len = strs[0].size();
        for(std::string str:strs)
        {
            if (str.size()<min_len) {min_len=str.size();}
        }
        
        // 2. Compare each string, remember dont oversize
        size_t outer_index = 0;
        std::string res = "";
        for(char c:strs[0])
        {
            for(size_t index=1; index<strs.size(); index++)
            {
                if (strs[index][outer_index]!=c||outer_index>min_len) return res;
            }
            res+=c;
            outer_index++;
        }
        return res;
    }
};

class SecondSolution //copied from "zefengsong" in LeetCode
{
public:
    std::string longestCommonPrefix(std::vector<string>& strs)
	{
        if(strs.empty()) return "";
        std::string res = strs[0];
        for(auto s: strs) res = match(res, s);
        return res;
    }
	
    std::string match(const std::string& pre, const std::string& s)
	{
        int i = 0, len = min(pre.size(), s.size());		// find the min string length
        for(; i < len; i++) if(s[i] != pre[i]) break;	// break when finding the diff char
        return pre.substr(0, i);	// return the common string
    }
};
