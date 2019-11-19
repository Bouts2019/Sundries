#include <iostream>
#include <string>
#include <vector>
using namespace std;

string GetNetID(string IP, string musk)
{
	int cur = 0;
	int pre = -1;
	vector<int> IP_Parts;
	for (; (cur = IP.find(".", pre + 1)) != -1; pre = cur)
		IP_Parts.push_back(stoi(IP.substr(pre + 1, cur - pre - 1)));
	IP_Parts.push_back(stoi(IP.substr(pre + 1, IP.length() - pre)));

	cur = 0;
	pre = -1;
	vector<int> musk_Parts;
	for (; (cur = musk.find(".", pre + 1)) != -1; pre = cur)
		musk_Parts.push_back(stoi(musk.substr(pre + 1, cur - pre - 1)));
	musk_Parts.push_back(stoi(musk.substr(pre + 1, musk.length() - pre)));

	string res = "";
	for (int i = 0; i < 4; i++)
		res += to_string(IP_Parts[i] & musk_Parts[i]) + (i == 4 - 1 ? "" : ".");

	cout << res << endl;
	return res;
}

int main(int argc, char** argv)
{
  	GetNetID("127.0.0.1", "255.255.255.0");
  	return 0;
}
