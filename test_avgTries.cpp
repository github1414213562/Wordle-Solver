#include "solver.h"
#include <bits/stdc++.h>

using namespace std;

int cnt = 0;
string ActAns;
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

pair<string,string> query(int noWords, string q) {
	cnt++;
	return make_pair(q, get_answer(q, ActAns));
}

void errExit() {
	cout << "ERROR";
	exit(0);
}

vector<string> getWordList() {
	return possibleWords;
}

vector<string> getAnsList() {
	return possibleAnswers;
}

int test(string word) {
	ActAns = word; cnt = 0;
	findword(); return cnt;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ifstream fin("wordList.in");
	string S; fin >> S;
	for(int i = 0; i < 12972; i++) {
		possibleWords.push_back(S.substr(8 * i + 1, 5));
		if(i < 2315) possibleAnswers.push_back(S.substr(8 * i + 1, 5));
	}
	int freq[100]; memset(freq, 0, sizeof(freq));
	for(auto i: possibleAnswers) {
		int tries = test(i);
		freq[tries]++;
		cout << "It took " << tries << " guesses for the solver to guess the word " << i << "." << endl;
	}
	for(int i = 0; i < 100; i++) if(freq[i] != 0) {
		cout << freq[i] << " words took " << i << " guesses to solve.\n";
	}
	while(true) {}
}