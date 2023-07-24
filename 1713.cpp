#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> photo_frame; // photo frame
int recomm_list[1001]; // number of recommended people of each candidate

int main() {
    int frame_num;
    int recomm_num;

    cin >> frame_num >> recomm_num;

    int candidate_num;
    photo_frame = vector<int>();

    for (int i = 1; i <= recomm_num; i++) {
        cin >> candidate_num;
        bool existed = false;

        if (photo_frame.size() < frame_num) {
            for (int i = 0; i < photo_frame.size(); i++) {
                if (photo_frame[i] == candidate_num) {
                    recomm_list[candidate_num]++;
                    existed = true;
                    break;
                }
            }

            if (existed == true)
                continue;

            else {
                photo_frame.push_back(candidate_num);
                recomm_list[candidate_num]++;
            }
        }

        else if (photo_frame.size() == frame_num) {
            for (int i = 0; i < frame_num; i++) {
                if (photo_frame[i] == candidate_num) {
                    recomm_list[candidate_num]++;
                    existed = true;
                    break;
                }
            }

            if (existed == true)
                continue;
            
            else {
                int min_index = 0;
                int min_count = recomm_list[photo_frame[min_index]];

                for (int i = 1; i < frame_num; i++) {
                    if (min_count > recomm_list[photo_frame[i]]) {
                        min_count = recomm_list[photo_frame[i]];
                        min_index = i;
                    }
                }

                recomm_list[photo_frame[min_index]] = 0;
                photo_frame.erase(photo_frame.begin() + min_index);

                photo_frame.push_back(candidate_num);
                recomm_list[candidate_num]++;
            }
        }

        // vector<int>::iterator iter;
        // for(iter = photo_frame.begin(); iter!= photo_frame.end(); iter++)
        // {
        //     cout << "Iterator : " << *iter << " ";
        // }
        // cout << endl;
    }

    sort(photo_frame.begin(), photo_frame.end());
    for (int i = 0; i < photo_frame.size(); i++) {
        cout << photo_frame[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
    풀이
    구조체 배열
    struct {s.no(학생번호), count(추천 횟수), index}
*/