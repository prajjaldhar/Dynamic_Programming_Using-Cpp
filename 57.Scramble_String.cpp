#include<bits/stdc++.h>
using namespace std;
bool checkScramble(string s1, string s2)
{
	if (s1.length() != s2.length())
		return false;
	if (s1.length() == 0 && s2.length() == 0)
		return true;
	if (s1.compare(s2) == 0)
		return true;
	if (s1.length() <= 1 || s2.length() <= 1)
		return false;
	int n = s1.length();

	//check anagram(if both string have same characters then anagram)
	string copy_S1 = s1, copy_S2 = s2;
	sort(copy_S1.begin(), copy_S1.end());
	sort(copy_S2.begin(), copy_S2.end());

	if (copy_S1 != copy_S2) {
		return false;
	}

	bool flag = false;
	for (int i = 1; i <= n - 1; ++i)
	{
		if (checkScramble(s1.substr(0, i), s2.substr(n - i, i))
		        &&
		        checkScramble(s1.substr(i, n - i), s2.substr(0, n - i)));
		{
			return true;
		}
		if (checkScramble(s1.substr(0, i), s2.substr(0, i))
		        &&
		        checkScramble(s1.substr(i, n - i), s2.substr(i, n - i)));
		{
			return true;
		}
	}
	return false;
}

bool checkScramble_memorization(string s1, string s2, unordered_map<string, bool>&mp)
{
	if (s1.length() != s2.length())
		return false;
	if (s1.length() == 0 && s2.length() == 0)
		return true;
	if (s1.compare(s2) == 0)
		return true;
	if (s1.length() <= 1 || s2.length() <= 1)
		return false;
	int n = s1.length();

	//check anagram(if both string have same characters then anagram)
	string copy_S1 = s1, copy_S2 = s2;
	sort(copy_S1.begin(), copy_S1.end());
	sort(copy_S2.begin(), copy_S2.end());

	if (copy_S1 != copy_S2) {
		return false;
	}

	// make key of type string for search in map
	string key = (s1 + " " + s2);
	// checking if both string are before calculated or not
	// if calculated means find in map then return it's
	// value
	if (mp.find(key) != mp.end()) {
		return mp[key];
	}

	bool flag = false;
	for (int i = 1; i <= n - 1; ++i)
	{
		if (checkScramble_memorization(s1.substr(0, i), s2.substr(n - i, i), mp)
		        &&
		        checkScramble_memorization(s1.substr(i, n - i), s2.substr(0, n - i), mp));
		{
			flag = true;
			return true;
		}
		if (checkScramble_memorization(s1.substr(0, i), s2.substr(0, i), mp)
		        &&
		        checkScramble_memorization(s1.substr(i, n - i), s2.substr(i, n - i), mp));
		{
			flag = true;
			return true;
		}
	}
	mp[key] = flag;
	return false;
}



int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string a = "coder", b = "ocred";
		bool ans;
		//ans = checkScramble(a, b);
		// map declaration for storing key value pair
		// means for storing subproblem result
		unordered_map<string, bool> mp;
		ans = checkScramble_memorization(a, b, mp);
		cout << ans;
	}
}
//caebd