//1.naive 朴素 前面与后面向中间扫，每对对比，一有不一样false
bool IsPalindrome(string input)
{
	for(int k = 0; k < input.size() / 2; ++k)
	if(input[k] != input[input.length() - 1 – k])
		return false;
	return true;
}
//2.利用STL reverse算法，逆转之后是否相等 2pass
bool IsPalindrome(string input)
{
	string reversed = input;
	reverse(input.begin(), input.end());
	return reversed == input;
}
//3.结合rbegin的逆序
bool IsPalindrome(string input)
{
	return equal(input.begin(), input.begin() + input.size() / 2, input.rbegin());
}