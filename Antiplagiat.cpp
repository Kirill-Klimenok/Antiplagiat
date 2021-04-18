#include <iostream>

using namespace std;

double antiPlagiarism(string text, string fragment);
string getUnsignedText(string text);
string getTextWithoutNumbers(string text);
string getRussianText(string text);
char getRussianLetter(char text);
string getLowercaseText(string text);
char getLowercase(char element);
string getCorrectedText(string text, char element);
char getReplacingElements(char text, char element);
int getSizeStr(string text);
string deleteRepeatedWords(string text);
string checkRepeatWord(string text, string word, int lastIndex);
string deleteStr(string text, int firstIndex, int lastIndex);
string deleteSpaces(string text);

int main()
{
	setlocale(LC_ALL, "Russian");

	string text("Уже убрали с полей картофель!?№;% 1 2 3 4 5 6 7 8 9 0 Уже убрали с полей картофель.На огородахдками.На краю леса краснеет рябина.Кудрявое дерево её усыпано ягодами, словно яркими бусами.По опушкам алеют зрелые ягоды калины.Сильнее дует осенний ветер.В комнатах потеют окошки.");

	antiPlagiarism(text, " ");

	return 0;
}

double antiPlagiarism(string text, string fragment) {

	text = getUnsignedText(text);
	fragment = getUnsignedText(fragment);

	text = getTextWithoutNumbers(text);
	fragment = getTextWithoutNumbers(fragment);

	text = getRussianText(text);
	fragment = getRussianText(fragment);

	text = getLowercaseText(text);
	fragment = getLowercaseText(fragment);

	text = deleteRepeatedWords(text);
	fragment = deleteRepeatedWords(fragment);

	cout << text << endl;

	text = deleteSpaces(text);

	cout << endl << text;

	system("pause");

	return 0;
}

string getLowercaseText(string text)
{
	for (int i = 0; text[i] != '\0'; i++)
	{
		text[i] = getLowercase(text[i]);
	}

	return text;
}

char getLowercase(char element)
{
	if (element >= -64 and element <= -33)
	{
		int number = element;
		return number + 32;
	}
	else if (element == -88)
	{
		return 'ё';
	}
	else return element;
}

string getRussianText(string text)
{
	for (int i = 0; text[i] != '\0'; i++)
	{
		text[i] = getRussianLetter(text[i]);
	}

	return text;
}

char getRussianLetter(char text)
{
	if (text == 'y')
	{
		return 'у';
	}
	else if (text == 'K')
	{
		return 'К';
	}
	else if (text == 'E')
	{
		return 'Е';
	}
	else if (text == 'e')
	{
		return 'е';
	}
	else if (text == 'H')
	{
		return 'Н';
	}
	else if (text == 'X')
	{
		return 'Х';
	}
	else if (text == 'x')
	{
		return 'х';
	}
	else if (text == 'B')
	{
		return 'В';
	}
	else if (text == 'A')
	{
		return 'А';
	}
	else if (text == 'a')
	{
		return 'а';
	}
	else if (text == 'P')
	{
		return 'Р';
	}
	else if (text == 'p')
	{
		return 'р';
	}
	else if (text == 'O')
	{
		return 'О';
	}
	else if (text == 'o')
	{
		return 'о';
	}
	else if (text == 'C')
	{
		return 'C';
	}
	else if (text == 'c')
	{
		return 'c';
	}
	else if (text == 'T')
	{
		return 'Т';
	}
	else return text;
}

string getTextWithoutNumbers(string text)
{
	char numbers[] = "0123456789";

	for (int i = 0; numbers[i] != '\0'; i++)
	{
		text = getCorrectedText(text, numbers[i]);
	}

	return text;
}

string getUnsignedText(string text)
{
	char characters[] = "!.?,():;«»+-*/=%№";

	for (int i = 0; characters[i] != '\0'; i++)
	{
		text = getCorrectedText(text, characters[i]);
	}

	return text;
}

string getCorrectedText(string text, char element)
{
	for (int i = 0; text[i] != '\0'; i++)
	{
		text[i] = getReplacingElements(text[i], element);
	}

	return text;
}

char getReplacingElements(char text, char element)
{
	if (text == element)
	{
		return ' ';
	}
	else return text;
}

/*
5. проверка текст на повторяющиеся слова и удаляем если таковые есть();
6. удаляем все устоявшееся фразы и сокращения, согласно массиву выражений();
7. удаляем все союзы согласно массиву союзов();
*/

int getSizeStr(string text) {
	int counter = 0;

	while (text[counter] != '\0') counter++;

	return counter;
}

string deleteRepeatedWords(string text) {
	string word = "";

	for (int i = 0; text[i] != '\0'; i++) {
		if (text[i] != ' ') {
			word += text[i];
		}
		else {
			text = checkRepeatWord(text, word, i);
			word = "";
		}
	}

	return text;
}

string checkRepeatWord(string text, string word, int lastIndex) {
	string wordInText = "";
	int wordSize = 0;
	int textSize = getSizeStr(text);
	for (int i = lastIndex; i < textSize + 1; i++) {
		if (text[i] != ' ') {
			wordInText += text[i];
		}
		else if (word == wordInText) {
			wordSize = getSizeStr(wordInText);
			text = deleteStr(text, i - wordSize, i);
			wordInText = "";
		}
		else {
			wordInText = "";
		}


	}

	return text;
}

string deleteStr(string text, int firstIndex, int lastIndex) {
	for (int i = firstIndex; i < lastIndex; i++) {
		text[i] = ' ';
	}
	return text;
}
string deleteSpaces(string text) {
	int sizeText = getSizeStr(text);
	string newText = "";
	int counter = 0;
	for (int i = 0; i < sizeText - 1; i++) {
		if (text[i] == ' ' && counter == 0) {
			newText += ' ';
			counter = 1;
		}


		if (text[i]!=' ')
		{
			counter = 0;
			newText += text[i];
		}

	}
	return newText;
}