bool valid_braces(std::string braces) 
{
  std::stack<char> s;
  for(auto ch: braces) {
    if(ch == '(' or ch == '[' or ch == '{') {
      s.push(ch);
    } else if (s.empty()) {
      return false;  // no left
    } else if (ch == ')') {
      if(s.top() != '(') return false;
      s.pop();
    } else if (ch == ']') {
      if(s.top() != '[') return false;
      s.pop();
    } else if (ch == '}') {
      if(s.top() != '{') return false;
      s.pop();
    }
  }
  return s.empty();
}