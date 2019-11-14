#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	vector<string> monomial;
	string PX;
	cout << "输入生成多项式P(X)：";
	cin >> PX;
	int lastIndex = 0;
	int currentIndex = 0;
	while ((currentIndex = PX.find("+", lastIndex)) != -1)
	{
		monomial.push_back(PX.substr(lastIndex, currentIndex - lastIndex));
		lastIndex = currentIndex + 1;
	}
	monomial.push_back(PX.substr(lastIndex, PX.size() - lastIndex));
	int* tmp = nullptr;
	int len = 0;
	for (int i = 0; i < monomial.size(); i++)
	{
		if (monomial[i].find("^") == -1)
		{
			if (monomial[i] == "x" || monomial[i] == "X")
			{
				if (!tmp) tmp = new int[len = 2]{ 0 };
				tmp[1] = 1;
			}
			else if (monomial[i] == "1")
			{
				if (!tmp)
					tmp = new int[len = 1]{ 0 };
				tmp[0] = 1;
			}
		}
		else
		{
			if (!tmp) tmp = new int[len = (stoi(PX.substr(2, PX.size() - 2)) + 1)]{ 0 };
			tmp[stoi(PX.substr(2, PX.size() - 2))] = 1;
		}
	}
	string binExp = "";
	if (tmp)
		for (int i = len - 1; i >= 0; i--)
			binExp += (tmp[i] + '0');
	cout << "#1. 数据发送生成检验码" << endl << "#2. 数据接受检验校验码" << endl;
	int choice = 0;
	cin >> choice;
	string binData;
	cout << "输入" << (choice == 1 ? "待发送" : "接收到") << "的数据：";
	cin >> binData;
	if (choice == 1)
		for (int i = 0; i < len - 1; i++)
			binData += "0";
	int idx = 0;
	string quotient = "";
	int cnt = 0;
	while (idx < binData.size())
	{
		quotient += binData[idx++];
		if (quotient.size() == len)
		{
			string tmp = "";
			for (int i = len - 1; i >= 0; i--)
				if (binExp[i] != quotient[i]) tmp.insert(0, "1");
				else tmp.insert(0, "0");
			if (tmp.find("0") == 0)
			{
				int zeroLen = 0;
				while (tmp[zeroLen] == '0') zeroLen++;
				if (zeroLen == len) tmp = "";
				else tmp = tmp.substr(zeroLen , tmp.size() - zeroLen);
			}
			quotient = tmp;
		}
	}
	cout << "余数为：" << quotient << endl;
	return 0;
}
