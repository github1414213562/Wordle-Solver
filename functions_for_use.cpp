#include "solver.h"
#include <bits/stdc++.h>

using namespace std;

vector<string> possibleWords, possibleAnswers;

string get_answer(string q, string actAns) {
	string colours = "bbbbb";
	for(int i = 0; i < 5; i++) {
		if(q[i] == actAns[i]) {
			colours[i] = 'g';
			actAns[i] = '0';
		}
	}
	for(int i = 0; i < 5; i++) if(colours[i] != 'g') {
		for(int j = 0; j < 5; j++) if(actAns[j] == q[i]) {
			colours[i] = 'y';
			actAns[i] = '0';
			break;
		}
	}
	return colours;
}

void errExit() {
	cout << "You have entered conflicting answers.";
	exit(0);
}

pair<string,string> query(int noWords, string q) {
	cout << "\nThe recommended word is: " << q << " and there are " << noWords << " possible answers based on the information you have given.\n\nPut the response wordle gives you. Refer to readme.md if you do not know how to do so.\n>> ";
	string response; cin >> response;
	if(response.length() == 5) {
		return make_pair(q, response);
	} else if(response.length() == 10) {
		return make_pair(response.substr(0, 5), response.substr(5, 5));
	} else {
		cout << "Invalid answer.\n";
		return query(noWords, q);
	}
}

vector<string> getWordList() {
	return possibleWords;
}

vector<string> getAnsList() {
	return possibleAnswers;
}

int main() {
	ifstream fin("wordList.in");
	string S; fin >> S;
	for(int i = 0; i < 12972; i++) {
		possibleWords.push_back(S.substr(8 * i + 1, 5));
		if(i < 2315) possibleAnswers.push_back(S.substr(8 * i + 1, 5));
	}
	findword();
}