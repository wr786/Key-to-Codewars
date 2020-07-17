#include <string>
using namespace std;

string rot13(string msg)
{
  string ret;
  for(const auto& ch: msg) {
     if('a' <= ch && ch <= 'z') {  // lower case
       ret += (ch - 'a' + 13) % 26 + 'a';
     } else if ('A' <= ch && ch <= 'Z') {  // upper case
       ret += (ch - 'A' + 13) % 26 + 'A';
     } else {  // not an alpha
       ret += ch;
     }
  }
  return ret;
}
