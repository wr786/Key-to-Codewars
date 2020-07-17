std::vector<int> tribonacci(std::vector<int> signature, int n)
{
    int len = signature.size();
    if(len > n) {  // special case
      std::vector<int> tmp;
      for(int i=0; i<n; i++) {tmp.push_back(signature[i]);}
      return tmp;
    }
    std::vector<int> result = signature;
    while(len < n) {
      result.push_back(result[len-1] + result[len-2] + result[len-3]);
      len = result.size();
    }
    return result;
}