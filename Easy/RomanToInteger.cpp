#include<iostream>
#include<unordered_map>

class Solution {
public:
	intromanToInt(string s)
    {
        std::unordered_map<char, int> rToI = {{'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};
        int res = 0;
        for (size_t i=0; i<s.size(); i++)
        {
            if(rToI[s[i]]<rToI[s[i+1]]) {res-=rToI[s[i]];}
            else {res+=rToI[s[i]];}
		}
		return res;
    }
};
