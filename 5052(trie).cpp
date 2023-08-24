// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <string>

// using namespace std;

// int test_num, p_num;

// class Trie {
//     private:
//         bool isEnd = false;
//         Trie* child[10];

//     public:
//         Trie():child() {}

//         void Insert(string phone_number) {
//             Trie* now = this;
            
//             for (int i = 0; i < phone_number.length(); i++) {
//                 if (now->child[phone_number[i] - '0'] == nullptr)
//                     now->child[phone_number[i]- '0'] = new Trie();

//                 now = now->child[phone_number[i] - '0'];

//                 if (i == phone_number.length() - 1)
//                     now->isEnd = true;
//             }
//         }

//         bool isTherePrefix(string phone_number) {
//             Trie* now = this;

//             for (int i = 0; i < phone_number.length(); i++) {
//                 if (now->child[phone_number[i] - '0'] != nullptr) {
//                     now = now->child[phone_number[i] - '0'];
//                     if (now->isEnd)
//                         return true;
//                 }
//                 else return false;
//             }
//             return false;
//         }
// };

// int main() {
//     setbuf(stdout, NULL);
//     ios::sync_with_stdio(false);
//     cin.tie(0); cout.tie(0);

//     scanf("%d", &test_num);

//     for (int z = 0; z < test_num; z++) {
//         scanf("%d", &p_num);
//         vector<string> vs(p_num);

//         for (int i = 0; i < p_num; i++)
//             cin >> vs[i];

//         sort(vs.begin(), vs.end());

//         Trie* trie = new Trie();

//         bool flag = true;

//         for (auto phone_number : vs) {
//             if (trie->isTherePrefix(phone_number)) {
//                 flag = false;
//                 break;
//             }
//             trie->Insert(phone_number);
//         }

//         if (flag) printf("YES\n");
//         else printf("NO\n");
//     }

//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;

class Trie {
private :
    bool isEnd = false;  // 이 Trie 노드 객체가 문자열(단어)의 끝인지를 알 수 있는
    Trie* child[10]; // Trie 객체들은 각각 서브 트리들의 루트 노드가 된다. 자식 10 개( 0 ~ 9 )를 담을 수 있는 배열을 가지고 있음 (배열말고 해시로 해도 된다.)
    
public :
    Trie() : child() { }
    
    /* 트라이 트리 만들기 */
    void Insert(string phone_number) {
        Trie* now = this; // 루트에서부터 시작 (루트 Trie 객체에서만 이 Insert 를 한번 실행하도록 함. 재귀 안 쓰고 반복문 써서..)
        for (int i = 0; i < phone_number.length(); ++i) {
            if (now->child[phone_number[i] - '0'] == nullptr) 
                now->child[phone_number[i] - '0'] = new Trie(); // 해당 글자 자식이 없다면 Trie 객체 만들어주기. 이미 있다면 만들어줄 필요 없음. 
            // 다음 글자 노드로 이동 (트리 타고 내려감) 
            now = now->child[phone_number[i] - '0'];
            // 문자열의 끝에 도달했다면 해당 글자 노드의 isEnd 를 True 로
            if (i == phone_number.length() - 1) now->isEnd = true;
        }
    }
    /* 트라이 트리에 phone_number 문자열을 타고 내려가되 중간에 isEnd 가 True 인 노드를 만나면 접두어가 있다고 판단함 */
    bool IsTherePrefix(string phone_number) {
        Trie* now = this; // 루트에서부터 시작 (루트 Trie 객체에서만 이 IsTherePrefix 를 한번 실행하도록 함. 재귀 안 쓰고 반복문 써서..)
        for (int i = 0; i < phone_number.length(); ++i) {
            if (now->child[phone_number[i] - '0'] != nullptr) {
                now = now->child[phone_number[i] - '0']; // 다음 글자 노드로 이동 (트리 타고 내려감) 
                if (now->isEnd) // 다음 글자가 있는 상태인데(위 if) isEnd 가 True 인 경우를 만났다는 것은 이 글자가 끝인 다른 단어가 있다는 것. 접두어! 
                    return true;
            }
            else // 다음 글자도 없다면(문자열 끝에 도달) 한번도 접두어가 없었던 것! (같은 문자열이 중복으로 주어지는 경우는 없다고 제한했으니 같은 문자열 접두사 있을 걱정은 안해도 되므로 그냥 더 이상 자식 없을 때까지 걸린적 없으면 접두사 없는 것임)
                return false;
        }
        return false;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n;
    cin >> t;
    
    for (int i = 0; i < t; ++i) {
        cin >> n;
        vector<string> phone_number_list(n);
        for (int j = 0; j < n; ++j)
            cin >> phone_number_list[j];
        sort(phone_number_list.begin(), phone_number_list.end()); // 정렬
        Trie* trie = new Trie(); // 트라이 트리의 루트 
        bool ok = true;
        for(auto phone_number : phone_number_list) {
            if (trie->IsTherePrefix(phone_number)) { // 접두사 있는지 검사
                ok = false;
                break;
            }
            trie->Insert(phone_number); // 접두사 없으면 추가
        }
        if (ok) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}