#include<bits/stdc++.h>
using namespace std;

int maxProduct(vector<string>& words) {
	int length = words.size();
	vector<int> masks(length);
	for (int i = 0; i < length; i++) {
		string word = words[i];
		int wordLength = word.size();
		for (int j = 0; j < wordLength; j++) {
			masks[i] |= 1 << (word[j] - 'a');
		}
	}
	int maxProd = 0;
	for (int i = 0; i < length; i++) {
		for (int j = i+1; j < length; j++) {
			if ((masks[i] & masks[j]) == 0) {
				maxProd = max(maxProd, int(words[i].size() * words[j].size()));
			}
		} 
	}
	return maxProd;
}

int main()
{
	vector<string> words;
	int n;
	cin >> n;
	while(n--) {
		string tmp;
		cin >> tmp;
		words.push_back(tmp);
	}
	cout << maxProduct(words) << endl;
	return 0;
}
