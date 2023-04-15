#include<bits/stdc++.h>
using namespace std;

int main(){
    string ref_string{""},tem{""};
    int framesize{0},fifo{0},lru{0},optimal{0};
    vector<int>ref_vec,c_frame(100,0);
    deque<int> q;
    cout << "Enter reference string: ";
    getline(cin, ref_string);
    for(auto i : ref_string){
        if(i == ' '){
            ref_vec.push_back(stoi(tem));
            tem = "";
        }
        tem += i;
    }
    ref_vec.push_back(stoi(tem));
    cout << "Enter Framesize: ";
    cin >> framesize;
    for(auto i : ref_vec){
        if(q.size() < framesize){
            if(!c_frame[i]){
                c_frame[i]++;
                q.push_back(i);
                fifo++;
            }
            else continue;
        }
        else{
            if(!c_frame[i]){
                c_frame[q.front()]--;
                c_frame[i]++;
                q.pop_front();
                q.push_back(i);
                fifo++;
            }
            else continue;
        }
        for(auto i : q){
            cout << i << " ";
        }
        cout << "\n";
    }
    cout << "fifo: " << fifo << "\n";
    cout << "\n";
    c_frame.assign(100, 0);
    q.clear();

    for(auto i : ref_vec){
        if(q.size() < framesize){
            if(!c_frame[i]){
                c_frame[i]++;
                q.push_back(i);
                lru++;
            }
            else{
                q.erase(find(q.begin(), q.end(), i));
                q.push_back(i);
            }
        }
        else{
            if(!c_frame[i]){
                int lru_page = q.front();
                c_frame[lru_page]--;
                q.pop_front();
                c_frame[i]++;
                q.push_back(i);
                lru++;
            }
            else{
                q.erase(find(q.begin(), q.end(), i));
                q.push_back(i);
            }
        }
        for(auto i : q){
            cout << i << " ";
        }
        cout << "\n";
    }
    cout << "lru: " << lru << "\n";
    cout << "\n";
    c_frame.assign(100, 0);
    q.clear();

    for(int i=0; i<ref_vec.size(); i++){
        if(q.size() < framesize){
            if(!c_frame[ref_vec[i]]){
                c_frame[ref_vec[i]]++;
                q.push_back(ref_vec[i]);
                optimal++;
            }
            else continue;
        }
        else{
            if(!c_frame[ref_vec[i]]){
                int idx = -1, farthest = -1;
                for(int j=0; j<q.size(); j++){
                    int val = q[j];
                    bool found = false;
                    for(int k=i+1; k<ref_vec.size(); k++){
                        if(val == ref_vec[k]){
                            found = true;
                            if(k > farthest){
                                farthest = k;
                                idx = j;
                            }
                            break;
                        }
                    }
                    if(!found){
                        idx = j;
                        break;
                    }
                }
                c_frame[q[idx]]--;
                q.erase(q.begin() + idx);
                c_frame[ref_vec[i]]++;
                q.push_back(ref_vec[i]);
                optimal++;
            }
            else continue;
        }
        for(auto i : q){
            cout << i << " ";
        }
        cout << "\n";
    }
    cout << "optimal: " << optimal << "\n";

    return 0;
}