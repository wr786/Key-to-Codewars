std::string encrypt(std::string text, int n)
{
    std::string ret = text;
    size_t len = ret.length();
    while(n-- > 0) {
      std::string s1, s2;  // front and rear
      for(size_t i=0; i<len; i++) {
        if(i % 2) s1 += ret[i];
        else s2 += ret[i];
      }
      ret = s1 + s2;
    }
    return ret;
}

std::string decrypt(std::string encryptedText, int n)
{
    std::string ret = encryptedText;
    size_t len = ret.length();
    while(n-- > 0) {
      std::string tmp;
      for(size_t i=0; i<len/2; i++) {
        if(i + len / 2 < len) tmp += ret[i + len / 2];
        tmp += ret[i];
      }
      if(len % 2) tmp += ret[len - 1];  // special case
      ret = tmp;
    }
    return ret;
}