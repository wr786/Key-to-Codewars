bool validSolution(unsigned int board[9][9]){
  // num validation check
  for(size_t i=0; i<9; i++)
    for(size_t j=0; j<9; j++)
      if(board[i][j] < 1 || board[i][j] > 9) return false;  
  // row validation check
  for(size_t i=0; i<9; i++) {
    int sum = 0;
    for(size_t j=0; j<9; j++) sum |= (1<<(board[i][j]-1));
    if(sum != (1<<9)-1) return false;
  }
  // col validation check
  for(size_t j=0; j<9; j++) {
    int sum = 0;
    for(size_t i=0; i<9; i++) sum |= (1<<(board[i][j]-1));
    if(sum != (1<<9)-1) return false;
  }
  // cell validation check
  std::array<std::pair<int, int>, 9> topLeftArr {{
    {0, 0}, {0, 3}, {0, 6},
    {3, 0}, {3, 3}, {3, 6},
    {6, 0}, {6, 3}, {6, 6}
  }};
  for(auto topLeft: topLeftArr) {
    int sum = 0;
    for(size_t i=0; i<3; i++)
      for(size_t j=0; j<3; j++)
        sum |= (1<<(board[topLeft.first+i][topLeft.second+j]-1));
    if(sum != (1<<9)-1) return false;
  }
  return true;
}