#include <iostream>

using namespace std;

double antiPlagiarism(string text, string fragment);
string deleteRepeatWords(string text, int size);
int getSizeStr(string str);
string searchRepeatWords(string text,string word, int size, int lastIndex);
string deleteWordInText(string text, int firstIndex, int lastIndex);

int main()
{
	string text = "наступила весна на реке пошёл лёд берегу было много народу все смотрели как идёт лёд вдруг все увидали на одной льдине собаку она жалобно выла витя схватил длинный багор и зацепил льдину витя тихонько потянул льдину к берегу Когда льдина была у берега собака соскочила на землю";
	string fragments = "весна собака много";
	antiPlagiarism(text, fragments);

	return 0;
}

double antiPlagiarism(string text, string fragment) {
	int size = getSizeStr(text);

	text = deleteRepeatWords(text, size);
	return 100;
}

string deleteRepeatWords(string text, int size) {
	string word = "";

	for (int i = 0; i < size; i++) {
		if (text[i] != ' ') {
			word += text[i];
		}
		else {
			text = searchRepeatWords(text, word,size,i);
			word = "";
		}
	}
	return " ";
}

string searchRepeatWords(string text, string word, int size,int lastIndex) {
	string repetedWord = "";
	int sizeRepetedWord = getSizeStr(word);

	for (int i = lastIndex; i < size; i++) {
		if (text[i] != ' ') {
			repetedWord += text[i];
		}
		else {
			if (repetedWord == word) {
				text = deleteWordInText(text,i - sizeRepetedWord,i - 1);
				repetedWord = "";
			}
			else {
				repetedWord = "";
			}
		}
	}
}







//general methods for working with strings

int getSizeStr(string str) {
	int counter = 0;

	while (str[counter] != '\0') {
		counter++;
	}

	return counter;
}