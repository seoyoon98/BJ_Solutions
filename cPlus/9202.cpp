#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

int dx[8] = {0, 0, 1, -1, -1, -1, 1, 1};
int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};

int word_num; // 1 < word_num < 300000
int boggle_num; // 1 < boggle_num < 30
int maxScore;
int max_word_length;

char boggle[4][4]; // boggle grid

bool visited[4][4];

set<string> found_str; // 찾은 문자열들을 저장하는 집합
string max_word;

class Node {
    public:
        char data;
        string str_data;
        vector<Node*> child;
};

class Trie {
    private:
        Node* root = new Node;
    
    public:
        void push(string str) {
            insert(str, 0, root);
        }

        void insert(string str, int index, Node* node) {
            if (index >= str.length()) {
                node->str_data = str;
                return;
            }

            int next = -1;

            for (int i = 0; i < node->child.size(); i++) {
                if (str[index] == node->child[i]->data) {
                    next = i;
                    break;
                }
            }

            if (next != -1)
                insert(str, index + 1, node->child[next]);
            else {
                Node* newNode = new Node;
                newNode->data = str[index];
                node->child.push_back(newNode);
                insert(str, index + 1, newNode);
            }
        }

        bool search(string str) {
            return findWord(str, 0, root);
        }

        bool findWord(string str, int index, Node* node) {
            if (!node->child.empty() && index >= str.length()) {
                if (node->str_data == str) 
                    return true; // 리프노드가 아니지만 해당 단어가 존재하는 곳
                else
                    return false;
            }

            if (index >= str.length())
                return true; // 리프노드

            int next = -1;

            for (int i = 0; i < node->child.size(); i++) {
                if (str[index] == node->child[i]->data) {
                    next = i;
                    break;
                }
            }

            if (next != -1) return findWord(str, index + 1, node->child[next]);
            else return false;
        }
};

Trie* trie = new Trie;

int score(int size){
	switch (size){
		case 1: 
		case 2:
			return 0;
			break;
		case 3:
		case 4: 
			return 1;
			break;
		case 5:
			return 2;
			break;
		case 6:
			return 3;
			break;
		case 7:
			return 5;
			break;
		case 8:
			return 11;
			break;
	}
	return 0;
}

void dfs(int x, int y, string str) {
    if (visited[x][y] || str.size() > 8) return;

    if (trie->search(str)) {
        if (found_str.find(str) == found_str.end()) {
            found_str.insert(str);
            maxScore += score(str.length());

            if (max_word_length < str.length()) {
                max_word_length = str.length();
                max_word = str;
            }

            else if (max_word_length == str.length()) {
                max_word = min(max_word, str);
            }
        }
    }

    visited[x][y] = true;

    for (int i = 0; i < 8; i++) {
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if (next_x < 0 || next_y < 0 || next_x >= 4 || next_y >= 4)
            continue;

        str += boggle[next_x][next_y];
        //cout << "Word: " << str << "\n";
        dfs(next_x, next_y, str);        
        str.pop_back();
    }
    visited[x][y] = false;
}

int main() {
    ios::sync_with_stdio(false);
    // ios_base::sync_with_stdio 구문은 c의 stdio와 cpp의 iostream을 동기화시켜주는 역할을 하는데, 이 때 iostream과 stdio의 버퍼를 모두 사용하기 때문에 딜레이가 발생합니다.
    // 따라서, ios_base::sync_with_stdio(false); 코드를 작성해줌으로써 동기화를 비활성화시켜줍니다.
	cin.tie(NULL);
    // cin과 cout의 묶음을 풀어줍니다.
    // 기본적으로 cin과 cout은 묶여있고 묶여있는 스트림들은 한 스트림이 다른 스트림에서 각 IO 작업을 진행하기 전에 자동으로 버퍼를 비워줌을 보장합니다.

    cin >> word_num;

    string temp_str;

    for (int i = 0; i < word_num; i++) {
        cin >> temp_str;
        trie->push(temp_str);
    }

    cin >> boggle_num;

    while(boggle_num--) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                visited[i][j] = false;
                cin >> boggle[i][j];
            }
        }

        maxScore = 0, max_word_length = 0, max_word.clear(), found_str.clear();

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                string s;
                s.push_back(boggle[i][j]);
                dfs(i, j, s);
            }
        }

        cout << maxScore << " " << max_word << " " << found_str.size()<< "\n";
    }

    return 0;
}