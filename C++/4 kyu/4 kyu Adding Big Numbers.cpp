#include <string>

std::string add(const std::string& a, const std::string& b) {
  int la = a.length(), lb = b.length();
  std::string sa = a, sb = b;
  if(la < lb) {std::swap(sa, sb); std::swap(la, lb);}  // to ensure b is not longer than a
  int upDigit = 0;
  std::string ret;
  for(int i=1; i<=lb; i++) {
    int nc = sa[la-i] - '0' + sb[lb-i] - '0' + upDigit;
    upDigit = nc / 10;
    nc %= 10;
    ret = std::to_string(nc) + ret;
  }
  la -= lb + 1;
  while(la >= 0) {
    int nc = sa[la] - '0' + upDigit;
    upDigit = nc / 10;
    nc %= 10;
    ret = std::to_string(nc) + ret;
    la--;
  }
  if(upDigit) ret = std::to_string(upDigit) + ret;
  return ret;
}