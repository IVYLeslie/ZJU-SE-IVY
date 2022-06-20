#include<iostream>

using namespace std;

#define M 0x8000 //offset
#define F 0xffff //maximum 判断溢出
#define B 16 //bit

typedef unsigned int word;

/*字符串转换成对应的二进制*/
word atom(string s) {
    word i = 0;
    word x = 0;
    bool flag = false;  //false: s>=0   true: s<0
    if (s[0] == '-') {
        flag = true;
        i++;
    }
    while (s[i]) { //convert string to number
    x = x * 10 + (s[i] - 48);
        i++;
    }
    if (flag) x = M - x;   //calculate frame shift
    else x = M + x;
  return x;
}

/*二进制移码转换成字符串*/
string mtoa(word x) {
  if (x & M) { //case x>=0
    x = x - M;
    return to_string(x);
  } else { //case x<0
    x = M - x;
    return "-" + to_string(x);
  }
}

/*移码的加法操作*/
word madd(word x , word y) {
  return (x + y) & F ^ M;
}

/*移码的减法操作*/
word msub(word x , word y) {
  return (x - y) & F ^ M;
}

/*移码的乘法操作*/
word mmul(word x , word y) {
  word product = 0;
  bool flag = (x & M) ^ (y & M); //flag:true xy<0 false:xy>=0
  if (x&M) x = x ^ M;
  else x = (M - x) & F; //abs
  if (y&M) y = y ^ M;
  else y = (M - y) & F; //abs
  while (y) {
    if (y & 1) product = (product + x) & F;
    x = x << 1;
    y = y >> 1;
  }
  if (flag) product = (M - product) & F; //convert to frame shift
  else product = (M + product) & F;
  return product;
}

/*移码的除法操作*/
word mdiv(word x , word y) {
    word quotient = 0;
  word i = B; //maximum power
  bool flag = (x&M) ^ (y&M); //flag:true xy<0 false:xy>=0
  if (x&M) x = x ^ M;
  else x = (M - x) & F; //abs
  if (y&M) y = y ^ M;
  else y = (M - y) & F; //abs
  while (i) {
    if (x >= y << (i - 1)) {
      quotient = (quotient + (1 << (i - 1))) & F;
      x = (x - (y << (i - 1))) & F;
    }
    i--;
  }
  if (flag) quotient = (M - quotient) & F; //convert to frame shift
  else quotient = (M + quotient) & F;
  return quotient;
}

/*移码的取余操作*/
word mmod(word x , word y) {
  word quotient = 0;
  word remainder = 0;
  word i = B; //maximum power
  bool flag = x & M; //flag:true x>=0 false:x<0
  if (x&M) x = x ^ M;
  else x = (M - x) & F; //abs
  if (y&M) y = y ^ M;
  else y = (M - y) & F; //abs
  while (i) {
    if (x >= y << (i - 1)) {
      quotient = (quotient + (1 << (i - 1))) & F;
      x = (x - (y << (i - 1))) & F;
    }
    i--;
  }
  remainder = x;
  if (flag) remainder = (M + remainder) & F; //convert to frame shift
  else remainder = (M - remainder) & F;
  return remainder;
}


void test(string &p, string &q) {
  word x = atom(p);
  word y = atom(q);
  word plus = madd(x , y);
  word minus = msub(x , y);
  word multi = mmul(x , y);
  word divide = mdiv(x , y);
  word mod = mmod(x , y);
  cout << "test:" << endl;
  cout << mtoa(x) << " + " << mtoa(y) << " = " << mtoa(plus) << "\t\t";
  cout << mtoa(x) << " - " << mtoa(y) << " = " << mtoa(minus) << "\t\t";
  cout << mtoa(x) << " * " << mtoa(y) << " = " << mtoa(multi) << "\t\t";
  cout << mtoa(x) << " / " << mtoa(y) << " = " << mtoa(divide) << "\t\t";
  cout << mtoa(x) << " % " << mtoa(y) << " = " << mtoa(mod) << endl;
}


int main(void) {
  string p , q;
  cin >> p;
  while (p.compare("end")) {
    cin >> q;
    test(p , q);
    cin >> p;
  }
}
