#include<iostream>
using namespace std;

//alien dictiomnary 

//words are sorted in lexicoraphically order ie dictionary wise 


//  If a string s1 is lexicographically smaller than a string s2, and the first position at which they differ 
//contains letter a in s1 and letter b in s2, then a must appear before b in the alien alphabet.
//If one word is a prefix of the other, the shorter word must appear before the longer word.

//so basically topo sort 


//code wriiten bt=y me it does not count that there can be b,d only it was witten to get twith charector staring from a 
class Solution {
	public:
	string findOrder(vector<string> &words) {
		// code here
		// lexicographical order =dictionary order;
		int n = words.size();
		
		int k = 0;
		for (const auto& it:words) {
			for (auto ch:it) {//so this fails 
				k = max(k, ch - 'a' + 1); // here +1 is important because we need to determine how any rows will be there
			}
		}
		vector<vector<int>> adj(k);
		
		for (int i = 0; i<n - 1; i++) {
			string s1 = words[i];
			string s2 = words[i + 1];
			
			int m = min(s1.size(), s2.size());
			int j;
			for (j = 0; j<m; j++) {
				if (s1[j] != s2[j]) {
					adj[s1[j]-'a'].push_back(s2[j]-'a');
					break;
				}
			}
			
			if (j == m && s1.size()>s2.size()) {
				return "";
			}
		}
		
		// kahn algo to get the inorder
		vector<int>inord(k, 0);
		for (const auto& it:adj) {
			for (auto ch:it) {
				inord[ch]++;
			}
		}
		
		queue<int>q;
		for (int i = 0; i<inord.size(); i++) {
			if (inord[i] == 0) {
				q.push(i);
			}
		}
		string ans = "";
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			ans += node + 'a';
			
			for (auto it:adj[node]) {
				if (--inord[it] == 0)q.push(it);
			}
		}
		
		return ans;
		
	}
};



//real soln which count the exact cases 


class Solution {
	public:
	string findOrder(vector<string> &words) {
		// code here
		// lexicographical order =dictionary order;
		int n = words.size();
		
		int total = 0;
		vector<bool>present(26,false);
		for(const auto& it:words){
		    for(auto ch:it){
		        if(!present[ch-'a']){
		            present[ch-'a']=true;
		            total++;
		        }
		    }
		}
		vector<vector<int>> adj(26);
		
		for (int i = 0; i<n - 1; i++) {
			const string& s1 = words[i];
			const string& s2 = words[i + 1];
			
			int m = min(s1.size(), s2.size());
			int j;
			for (j = 0; j<m; j++) {
				if (s1[j] != s2[j]) {
					adj[s1[j]-'a'].push_back(s2[j]-'a');
					break;
				}
			}
			
			if (j == m && s1.size()>s2.size()) {//to see if the edge case where first word is abcd
                // and the 2nd word is ab
				return "";
			}
		}
		
		// kahn algo to get the inorder
		vector<int>inord(26, 0);
		for (const auto& it:adj) {
			for (auto ch:it) {
				inord[ch]++;
			}
		}
		
		queue<int>q;
		for (int i = 0; i<26; i++) {
			if (present[i]&&inord[i] == 0) {
				q.push(i);
			}
		}
		string ans = "";
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			ans += node + 'a';
			
			for (auto it:adj[node]) {
				if (--inord[it] == 0)q.push(it);
			}
		}
		
		if((int)ans.size()!=total)return "";//to chaack if there is a cycle 
		
		return ans;
		
	}
};