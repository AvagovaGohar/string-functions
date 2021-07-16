# String-Functions

#include <iostream>
#include <string>
#include <vector>
bool isUnque(std::string& str) {
	bool ch[58] = {false};//123-65
	for (int i = 0; i < str.length(); i++)
	{
		if (ch[str[i]-65]) {
			return false;
		}
		ch[str[i]-65] = true;
	}
	return true;
}
std::string U_20(std::string& str , size_t j) {
	std::string tmp;
	for (int i = 0; i < j; i++)
	{
		if (str[i] == ' ') {
			tmp += "%2";
			continue;
		}
		tmp += str[i];
	}
	return tmp;
}
bool OneArray(const std::string& s1, const std::string& s2) {
	int j = 0;
	for (int i = 0; i < s2.length(); i++) {
		bool t = false;
		for ( ; j < s1.length(); j++)
		{
			if (s2[i] == s1[j]) {
				j++;
				t = true;
				break;
			}
		}
		if (!t) {
			return false;
		}
	}
	return true;
}
std::string SCompression(std::string& s) {
	std::string tmp = "";
	int count = 1;
	for (int i = 1; i < s.length(); i++)
	{
		if (s[i] == s[i - 1]) {
			count++;
		}
		else {
			tmp += s[i - 1];
			tmp += (char)(count+48);
			count = 1;
		}
	}
	if (tmp.length() == s.length() * 2) {
		return s;
	}
	return tmp;
}
void deleteAll(int** r, int size) {
	for (int i = size-1; i >= 0; i--)
	{
		delete[] r[i];
	}
	delete[] r;
}
void Print(int** r, int size) {
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++) {
			std::cout << r[i][j] << '\t';
		}
		std::cout << '\n';
	}
}
int** RotateMatrix(int** mtx,int n) {
	int** a = new int* [n];
	for (int i = 0; i <n; i++)
	{
		a[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int i1 = 0 ;i1 < n; i1++)
		{
			 a[n-i1-1][i] = mtx[i][i1];
		}
	}
	Print(a, n);
	std::cout << "\n\n\n";
	Print(mtx, n);
	deleteAll(mtx, n);
	return a;
}
int** ToZero(int** mtx, int n) {
	std::vector<int> x;
	std::vector<int> y;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			if (mtx[i][j] == 0) {
				x.push_back(i);
				y.push_back(j);
			}
		}
	}
	for (int i = 0; i < x.size(); i++)
	{
		for (int j = 0; j < n; j++)
		{
			mtx[x[i]][j] = 0;
			mtx[j][y[i]] = 0;
		}
	}
	return mtx;
}
bool Substring(std::string str, std::string tm) {
	bool t;
	for (int i = 0; i < tm.length(); i++)
	{
		t = false;
		for (int j = 0; j < str.length(); j++)
		{
			if (tm[i] == str[j]) {
				t = true; 
				str.erase(j, 1);
				break;
			}
		}
		if (!t) {
			return false;
		}
	}
}
bool isEqual(std::string str) {
	int count = 1;
	bool t = false;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ') {
			str.erase(i, 1);
			continue;
		}
		for (int j = 0; j < str.length(); j++)
		{
			if (j == i) {
				continue;
			}
			if (str[i] == str[j]) {
				count++;
				str.erase(j, 1);
				j--;
			}
		}
		if (count % 2 != 0 && (t || str.length()%2==0)) {
			return false;
		}
		else if (count % 2 != 0 && !t) {
			t = true;
		}
		count = 1;
		str.erase(i, 1);
		i--;
	}
	return true;

}
int main()
{
	std::cout << (isEqual("heeheehi") == 0 ? "false" : "true");
}
