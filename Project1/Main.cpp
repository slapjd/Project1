#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <Windows.h>
//Required include statements

using namespace std;
//Avoids me typing "std::" before everything

int main() {
	//Global variables
	string sSentence, sWord;
	//Strings above, vectors below, labelled accordingly (s for string, vs for vector string, etc)
	vector<string> vsSentence;
	vector<int> viPositions;
	
	cout << "Please enter a sentence without punctuation" << endl;
	getline(cin, sSentence);
	cout << "Please enter a word to find in the previous sentence" << endl;
	cin >> sWord;
	{
		stringstream issStream(sSentence);
		string sTempString;
		while (issStream >> sTempString) {
			vsSentence.push_back(sTempString);
		}
	}
	//Above is the input block, 2 inputs, 1 sentence 1 word, sentence split into words

	for (int iCounter = 0; iCounter < vsSentence.size(); iCounter++) {
		if (vsSentence[iCounter] == sWord) {
			viPositions.push_back(iCounter + 1);
		}
	}
	//Search loop above. Finds the word in the sentence

	cout << endl;
	if (viPositions.empty()) {
		cout << "Your word was not found in your sentence";
	}
	else {
		cout << "Your word was found in these positions: ";
		for each (auto aCurrentWord in viPositions) {
			cout << aCurrentWord << " ";
		}
	}
	//Output block above, outputs the final result onto the screen.

	cout << endl;
	system("pause");
	//Windows pause command to allow user to exit properly

	return 0;
}