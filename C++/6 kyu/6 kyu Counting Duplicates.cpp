size_t duplicateCount(const std::string& in); // helper for tests

#include<cstring>
#include<cctype>

size_t duplicateCount(const char* in)
{
    size_t ans = 0;
    std::unordered_map<char, int> cnt;
    int len = strlen(in);
    for(int i=0; i<len; i++) {
      char ch = tolower(in[i]);
      cnt[ch]++;
      if(cnt[ch] >= 2) {
        ans++;
        cnt[ch] = -0x3f3f3f3f;
      }
    }
    return ans;
}