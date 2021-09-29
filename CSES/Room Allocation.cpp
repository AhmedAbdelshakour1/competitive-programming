// https://cses.fi/problemset/task/1164/

#include <bits/stdc++.h>
 
using namespace std;
 
void IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
 
typedef long long ll;
 
int main() {
    IO();
    int n; cin >> n;
    vector<pair<pair<int, int>, int>> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].first.first >> v[i].first.second;
        v[i].second = i;
    }
    sort(v.begin(), v.end());
    vector<int> ans(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int rooms = 0, currRoom = 0;
    for(int i = 0; i < n; i++){
        if(pq.empty()){
            pq.push({v[i].first.second, ++currRoom});
            ans[v[i].second] = currRoom;
        }
        else{
            pair<int, int> min = pq.top();
            if(min.first < v[i].first.first){
                pq.pop();
                pq.push({v[i].first.second, min.second});
                ans[v[i].second] = min.second;
            }else{
              pq.push({v[i].first.second, ++currRoom});
              ans[v[i].second] = currRoom;
            }
        }
        rooms = max(rooms, (int)pq.size());
    }
    cout << rooms << "\n";
    for(int i : ans) cout << i << " ";
}
 
 
/*   Think TWICE, Code ONCE!
     Do not make STUPID MISTAKES!
     No idea is a BAD idea!
     NEVER to assume something not mentioned!
     Thinking Concretely, Symbolically, Pictorically..
     Think in the smallest boundaries (e.g. n = 0, 1, 2 - R*C = {1*1, 1*2, 2*1, 2, 2} - str = "", str = "a", ...)
     Think in the largest boundaries (e.g. n = MAX, array is fully, string has max characters, ...)
     Think in especial cases (array filled with zeros, 1 1 1 1, .....)
     Make sure that you know exactly what is output and its "format"
 */
