// https://www.hackerrank.com/challenges/ctci-bubble-sort/problem

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int sw = 0;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1 - i; j++){
            if(a[j] > a[j + 1]){
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                sw++;
            }
        }
    }
    cout << "Array is sorted in " << sw << " swaps." << endl;
    cout << "First Element: " << a[0] << endl;
    cout << "Last Element: " << a[n - 1];
 
}
