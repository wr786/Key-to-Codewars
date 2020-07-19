#include <string>
#include <algorithm>

std::string sum_strings(const std::string& a, const std::string& b) {
    std::string ret, sa = a, sb = b;
    if(sa.length() < sb.length()) std::swap(sa, sb);
    size_t la = sa.length(), lb = sb.length();
    size_t upDigit = 0;
    for(size_t i=1; i<=lb; i++) {
        int na = sa[la - i] - '0', nb = sb[lb - i] - '0';
        int nc = na + nb + upDigit;
        upDigit = nc / 10, nc %= 10;
        ret = std::to_string(nc) + ret;
    }
    for(size_t i=lb+1; i<=la; i++) {
        int nc = sa[la-i] - '0' + upDigit;
        upDigit = nc / 10, nc %= 10;
        ret = std::to_string(nc) + ret;
    }
    if(upDigit) ret = std::to_string(upDigit) + ret;
    return ret;
}