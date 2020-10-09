#include <string>
#include <vector>

template <typename T> std::vector<T> uniqueInOrder(const std::vector<T>& iterable){
  std::vector<T> ret;
  T last;
  for(auto& cur: iterable) {
    if(cur != last)
      ret.push_back(cur);
    last = cur;
  }
  return ret;
}
std::vector<char> uniqueInOrder(const std::string& iterable){
  std::vector<char> ret;
  char last;
  for(auto& cur: iterable) {
    if(cur != last)
      ret.push_back(cur);
    last = cur;
  }
  return ret;
}