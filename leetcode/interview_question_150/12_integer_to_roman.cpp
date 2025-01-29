#include <string>

std::string intToRoman(int num)
{
  std::string ans;
  // over 1000
  while (num >= 1000)
  {
    ans += 'M';
    num -= 1000;
  }

  // 900++
  if (num >= 900)
  {
    ans += "CM";
    num -= 900;
  }

  // 500++
  if (num >= 500)
  {
    ans += "D";
    num -= 500;
  }

  // 400++
  if (num >= 400)
  {
    ans += "CD";
    num -= 400;
  }

  // 100-399
  while (num >= 100)
  {
    ans += "C";
    num -= 100;
  }

  // 90++
  if (num >= 90)
  {
    ans += "XC";
    num -= 90;
  }

  // 50++
  if (num >= 50)
  {
    ans += "L";
    num -= 50;
  }

  // 40++
  if (num >= 40)
  {
    ans += "XL";
    num -= 40;
  }

  // 10-39
  while (num >= 10)
  {
    ans += "X";
    num -= 10;
  }

  // 9++
  if (num >= 9)
  {
    ans += "IX";
    num -= 9;
  }

  // 5++
  if (num >= 5)
  {
    ans += "V";
    num -= 5;
  }

  // 4++
  if (num >= 4)
  {
    ans += "IV";
    num -= 4;
  }

  // 10-39
  while (num >= 1)
  {
    ans += "I";
    num -= 1;
  }
  return ans;
}
int main()
{
  int num = 0;
  auto ans = intToRoman(num);
  return 0;
}