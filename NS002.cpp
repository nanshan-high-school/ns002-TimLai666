#include <iostream>
#include <deque>
using namespace std;
int dequeit(int, string); // 計算配對成功組數
int fail(int, int); // 計算配對失敗人數
int salary(int, int); // 媒婆的薪水
void print(int, int, int); // 輸出結果

int main() {
    int n = 0, pairs = 0, failp = 0, money = 0;
    string p;
    cout << "輸入括號總數:";
    cin >> n;
    cout << "輸入括號人:";
    cin >> p;

    pairs = dequeit(n, p);
    failp = fail(n, pairs);
    money = salary(failp, pairs);
    print(pairs, failp, money);
}


// 計算配對成功組數
int dequeit(int n, string p) {
    deque <char> pairnum; // 第一次
    deque <char> pairnumc; // 第二次
    int pairs = 0; // 存組數
    bool a = 0; // 布林值，用來協助判斷

    // 把資料存進pairnum
    for(int i = 0; i < n; i++) {
        pairnum.push_back(p[i]);
    }


    for(int rt = 0; rt < n; rt++) {
        // 計算組數(第一次)
        for(int i = 0; ! pairnum.empty(); i++) {
            if(pairnum.front() == '(' && a == 0 && i < n - 1) {
                a = 1;
                pairnum.pop_front();
            }else if(pairnum.front() == ')' && a == 1) {
                a = 0;
                pairnum.pop_front();
                pairs++;
            }else {
                pairnumc.push_back(pairnum.front());
                pairnum.pop_front();
            } 
        }
        a = 0; // 歸零


        // 計算組數(第二次)
        for(int i = 0; ! pairnumc.empty(); i++) {
            if(pairnumc.front() == '(' && a == 0 && i < n - 1) {
                a = 1;
                pairnumc.pop_front();
            }else if(pairnumc.front() == ')' && a == 1) {
                a = 0;
                pairnumc.pop_front();
                pairs++;
            }else {
                pairnum.push_back(pairnumc.front());
                pairnumc.pop_front();
            } 
        }
        a = 0; // 歸零
    }

    
    return pairs; 
}


// 計算配對失敗人數
int fail(int n, int pairs) {
    int fail = n - pairs * 2;

    return fail;
}


// 媒婆的薪水
int salary(int f, int pairs) {
    int total = 0;
    total += 5000 * pairs; // 感謝金
    total -= 3500 * f; // 賠償金

    return total;
}


// 輸出結果
void print(int pairs, int failp, int money) {
    string earn;
    if(money < 0) {
        earn = "賠";
        money *= -1;
    }else {
        earn = "賺";
    }
    printf("共有%i組配對成功 %i人配對失敗\n%s %i元", pairs, failp, earn.c_str(), money);
}