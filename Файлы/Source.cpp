#include <iostream>
#include <string>
#include <fstream>
using namespace std;
void findWord(string*& splited, int curIndex, int row)
{
	int maxA = 0;
	int maxAIndex = 0;
	for (int i = 0; i <= curIndex; i++)
	{
		int a = 0;
		for (int j = 0; j < size(splited[i]); j++) 
		{
			if (splited[i][j] == 'а') 
			{
				a++;
			}
		}
		if (maxA < a) {
			maxA = a;
			maxAIndex = i;
		}
	}
	if (maxA > 0) {
		cout << "В строке под номером " << row << "слово, в котором больше всего букв 'а', под номером " << maxAIndex + 1 << ": " << splited[maxAIndex] << endl;
	}
	else {
		cout << "В строке под номером " << row << " нет слов с буквой 'а'" << endl;
	}
}

bool isHaveDuble(int curIndex, string *&splited )
{
	int f;
	int watchedIndex = 0;
	string* watched = new string[curIndex + 1];
	for (int i = 0; i < curIndex; i++)
	{
		int pos = -1;
		for (int k = 0; k < watchedIndex; k++) 
		{
			if (watched[k] == splited[i]) 
			{
				pos = k;
			}
		}
		if (pos != -1)
		{
			continue;
		}
		watched[watchedIndex++] = splited[i];

		f = 0;
		for (int j = i + 1; j <= curIndex; j++)
		{

			if (splited[i] == splited[j])
			{
				f++;
			}
		}
		if (f == 1)
		{
			return true;
		}
	}
	return false;
}

int splitedOn(string n, string*& split) // функция разбивает строку на слова и записывает их в массив
{
	int curIndex = 0;
	for (int i = 0; i < n.size(); i++) 
	{
		if (n[i] == ' ' || n[i] == '\n' || n[i] == '\0') 
		{
			curIndex++;
			continue;
		}
		split[curIndex] += n[i];
	}
	return curIndex;
}



int main()
{
	system("color F0");
	setlocale(LC_ALL, "RUS");
	ifstream F1("Fail1.txt");
	if (F1.is_open())
	{
		ofstream F2("Fail2.txt");
		int row = 1;
		while (!F1.eof())
		{
			string n;
			int wordInN;
			getline(F1, n);
			wordInN = count(n.begin(), n.end(), ' ') + 1;
			string* splited = new string[wordInN];
			int curIndex = splitedOn(n, splited);
			bool answ = isHaveDuble(curIndex, splited);
			if (answ) {
				F2 << n << endl;
			}
			findWord(splited, curIndex, row);
			row++;
		}
	}
	else
	{
		cout << "Не удалось открыть файл F1";
	}
	F1.close();
	return 0;
}