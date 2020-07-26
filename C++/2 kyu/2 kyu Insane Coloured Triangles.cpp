using namespace std;

int C(int n, int m) { // return % 3 of yanghui triangle
  // C(n, m) % 3 == MUL(C(n_i, m_i)) % 3, n_i => the i-th digit of n in base-3
  if(n < m || n < 0 || m < 0) return 0;
  int ret = 1;
  while(n || m) {
    int ni = n % 3, mi = m % 3;
    if(mi > ni) return 0;
    if(ni == 2 && mi == 1) ret = (ret * 2) % 3; // in other case, the ret do not change 
    n /= 3, m /= 3;
  }
  return ret;
}

int ctoi(char c) {
  switch(c) {
    case 'R': return 0;
    case 'G': return 1;
    case 'B': return 2;
  }
}

char triangle(const string &row) {
  int n = row.size(), sum = 0;
  for(int i=0; i<n; i++)
    sum = (sum + C(n-1, i) * ctoi(row[i])) % 3;
  if(n % 2 == 0) sum = (6 - sum) % 3;  // a, b => -a-b
  switch(sum) {
    case 0: return 'R';
    case 1: return 'G';
    case 2: return 'B';
  }
}