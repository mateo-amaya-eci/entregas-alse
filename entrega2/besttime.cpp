#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class Solution {
public:
    
    vector<int> generatedays() {
        vector<int> days(7);
        srand(time(0)); 
        for (int i = 0; i < 7; i++) {
            days[i] = rand() % 11; 
        }
        return days ;
    }
    int mintime(vector<int>& days, int dia) {
        int minprice = days[0];
        int minDay = 0;
        for (int i = 0; i < dia; i++) {
            if (days[i] < minprice) {
                minprice = days[i];
                minDay = i;
            }
        }
        return minDay;
    }
};

int main() {
    Solution sol;
    vector<int> days = sol.generatedays();
    cout << "Precios en los días generados: " << endl;
    for (int i = 0; i < 7; i++) {
        cout << days[i] << ", ";
    }
    cout << endl;
    cout << "¿Qué día piensa vender acciones?" << endl;
    int day;
    cin >> day ;
    day -= 1;
    if (day + 1 == 1 ) {
        cout << "Día inválido. para poder vender el dia 1 primero se tienen que comprar acciones algun dia anterior, y no hay dia anterior" << endl;
        return 1;
    }else if (day + 1 > 6 ||  day + 1 < 1){
        cout << "Día inválido. El rango de días es entre 1 y 7" << endl;
        return 1;
    }
    int buyday = sol.mintime(days, day);
    cout << "Compra acciones el día " << buyday+ 1 << " donde se compra a un precio de " << days[buyday] << " y se venden acciones el día ";
    cout << day + 1<< " a un precio de " << days[day] << " con una ganancia de " << days[day] << " - " << days[buyday] << " = " << days[day] - days[buyday] << endl;
    return 0;
}