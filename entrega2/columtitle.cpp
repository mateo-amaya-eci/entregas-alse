#include <iostream>
#include <string>
using namespace std;
class Solution {
    public:
        int titleToNumber(string columnTitle) {
            int result = 0;
            for (char c : columnTitle) {
                c=toupper(c);
                result = result * 26 + (c - 'A' + 1);
            }
            return result;
        }
};
int main(){
    Solution sol;
    string columnTitle;
    cout << "ingrese el titulo de la columna: " ;cin >> columnTitle;
    int columnNumber = sol.titleToNumber(columnTitle);
    cout << "El número de columna correspondiente a '" << columnTitle << "' es: " << columnNumber << endl;
    return 0;   
}