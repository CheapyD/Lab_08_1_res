#include <iostream>

using namespace std;

char* Change(char* dest, const char* str, char* t, int i, const char ch)
{
	if (str[i] != 0)
	{
		if (ch == str[i])
		{
			strcat_s(t, 3, "**");
			return Change(dest, str, t + 2, i + 1, ch);
		}
		else
		{
			*t++ = str[i++];
			*t = '\0';
			return Change(dest, str, t, i, ch);
		}
	}
	else
	{
		*t++ = str[i++];
		*t++ = str[i++];
		*t = '\0';
		return dest;
	}
}
int main()
{
	char str[101];
	char ch = '.';

	cout << "Enter string:" << endl;
	cin.getline(str, 100);

	char* dest1 = new char[151];
	dest1[0] = '\0';

	char* dest2;
	dest2 = Change(dest1, str, dest1, 0, ch);

	cout << "Modified string (param) : " << dest1 << endl;
	cout << "Modified string (result): " << dest2 << endl;

	system("pause");
	return 0;
}
