#include <iostream>
using namespace std;

string getMinimum(int m, int s) {
  string res(m--, ' ');
  while(s > 9)
  {
    res[m--] = '9';  
    s -= 9;
  }
  if(m == 0) 
  {
    res[0] = s + '0';
    return res;
  }
  res[m] = s - 1 + '0';
  for(--m; m >= 1; m--)
  {
    res[m] = '0';
  }
  res[0] = '1'; 
  return res;
}

//Prove that the greedy algorithm above produces the optimial solution.
//Proof. Let s* be the greedy solution, s be the solution of the greedy algorithm. Assume that s* != s. But we can make s* better by
//taking as much as possibe away from each of the digit d and placing to the first digit that is smaller than 9 starting from the back, 
//until either d becomes '0' (or d becomes '1' if d is the first digit), or every digit to the back of d becomes '9'. By repeating 
//this process for every digit starting from the back, s* eventually becomes s.

string getMaximum(int m, int s) {
  string res(m, ' ');
  int i, upTo = s/9;
  for (i = 0; i < upTo; i++) {
    res[i] = '9';
  }

  res[i] = (s % 9) + '0';
  for (++i; i < m; i++) {
    res[i] = '0';
  }
  return res;
}

pair<string, string> solve(int m, int s) {
  return {getMinimum(m, s), getMaximum(m, s)};
}
int main() {
  int m, s;
  cin >> m >> s;
  if (s == 0) {
    if (m > 1) {
      cout << "-1 -1" << '\n';
      return 0;
    }
    cout << "0 0" << '\n';
    return 0;
  }

  if (s > 9 * m) {
    cout << "-1 -1";
    return 0;
  }
  pair<string, string> res = solve(m, s);
  cout << res.first << ' ' << res.second << '\n';
  return 0;
}
