#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<string> permutations(string s) {
  vector<string> ret;
  unordered_set<string> vis;
  vector<char> v;
  for(auto& ch: s) v.push_back(ch);
  sort(v.begin(), v.end());
  do {
      string cur;
      for(auto& item: v) cur += item;
      if(!vis.count(cur)) {
        ret.push_back(cur);
        vis.insert(cur);
      }
  } while(next_permutation(v.begin(), v.end()));
  return ret;
}