#include "solver.h"
#include <bits/stdc++.h>

#define HARDMODE 0

int strToNo(string str) {
	int x = 0;
	for(int i = 0; i < 5; i++) {
		if(str[i] == 'y') x += pow(3, i);
		if(str[i] == 'g') x += 2 * pow(3, i);
	}
	return x;
}

void findword(){
	vector<pair<int,string>> scores;
	vector<string> possibleWords = getWordList();
	vector<string> remWords = getAnsList();
	vector<int> freq; bool queriedAns = false;
	while(remWords.size() != 1) {
		string bestWord = ""; float bestV = 1e9;
		if(remWords.size() != 2315) for(auto i: ((HARDMODE) ? remWords : possibleWords)) {
			freq.clear();
			for(int j = 0; j < 243; j++) freq.push_back(0);
			for(auto j: remWords) freq[strToNo(get_answer(i, j))]++;
			float avg = 0;
			for(int j = 0; j < 243; j++) if(freq[j] != 0) avg += freq[j] * log2(freq[j]) / log2(100);
			avg /= 243; avg++;
			if(freq[242]) avg *= (1 - 1 / (float) remWords.size());
			if(bestV > avg) {
				bestV = avg;
				bestWord = i;
			}
			//cout << i << "\n";
		} else bestWord = "soare";
		pair<string,string> res = query(remWords.size(), bestWord);
		if(res.second == "ggggg") queriedAns = true;
		vector<string> nRemWords;
		for(auto i: remWords) {
			if(get_answer(res.first, i) == res.second) nRemWords.push_back(i);
		}
		remWords.clear(); for(auto i: nRemWords) remWords.push_back(i);
		/*for(auto i: remWords) {
			cout << i << "\n";
		}*/
		if(remWords.empty()) errExit();
	}
	if(!queriedAns) while(query(1, remWords[0]).first != remWords[0]) {}
}