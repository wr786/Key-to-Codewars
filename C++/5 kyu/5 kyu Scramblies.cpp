#include<string>
#include<unordered_map>
using namespace std;

bool scramble(const string& s1, const string& s2){
  unordered_map<char, int> counter;
  for(auto& ch: s1) counter[ch]++;
  for(auto& ch: s2) {
    counter[ch]--;
    if(counter[ch] < 0) return false;
  } 
  return true;
}