/*
 * Рок-група ЧЕРВ2 дасть концерт у Чернівцях у червні цього року.
 * N фанів U2 (N<=200) стоять у черзі й хочуть купити білети.
 * Кожен хоче купити один білет, у той же час касир може продати не більше двох білетів одній людині.
 * Касир витрачає час ti для продажу одного білета i-му фану і час ri для продажу двох білетів i-му фану.
 * Тому, якщо це економить час, двоє фанів, що стоять в черзі поруч (i-й та (i+1)-й) можуть домовитися,
 * і один з них ((i+1)-й) піде з черги, а інший (i-й) купить два білети.
 * Визначити, за який мінімальний час можна обслужити усю чергу фанів та який варіант
 * (сам бере білет чи об’єднується з сусідом) дасть цей найкращий варіант.
 */

/*
Вхідні дані
7
5 4 3 2 1 4 4
7 3 4 2 2 4

6
2 3 1 4 2 2
1 3 3 1 7
Вихідні дані
14

5
 */


#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin >> n;
    int t[n+1], r[n];
    for(int i = 1; i <= n; i++){
        cin >> t[i];
    }


    for(int i = 1; i < n; i++){
        cin >> r[i];
    }

    int d[n+1];
    d[0] = 0;
    d[1] = t[1];

    for(int i = 2; i <= n; i++){
        d[i] = min(d[i-1]+t[i], d[i-2]+r[i-1]);
    }

    cout << d[n] << endl;

    for(int i = n; i >= 1; i--) {
        if (d[i] == d[i - 1] + t[i]) {
            cout << i;
            if (i > 1) cout << ", ";
        } else {
            cout << "(" << i << ", " << i - 1 << ")";
            i--;
            if (i > 1) cout << ", ";
        }
    }
    return 0;
}