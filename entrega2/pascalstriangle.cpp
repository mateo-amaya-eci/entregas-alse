#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
    public:
        vector<vector<int>> generate(int filas) {
            vector<vector<int>> triangle(filas);          
            for (int i = 0; i < filas; i++) {
                triangle[i].resize(i + 1);                    
                triangle[i][0] = triangle[i][i] = 1;          
                for (int j = 1; j < i; j++) {                 
                    triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
                }
            }
            return triangle;
        }
};
int main() {
    Solution sol;
    int filas;
    cout << "Ingrese el número de filas para el Triángulo de Pascal: ";
    cin >> filas;
vector<vector<int>> triangle = sol.generate(filas);
    cout << "Triángulo de Pascal con " << filas << " filas:" << endl;
    string c = "";
    int espacio = filas;    
    for (int i=0; i<filas; i++) {
        c = c + string(espacio - i, ' ');
        for (int j=0 ; j < triangle[i].size() ; j++) {
            c= c + to_string(triangle[i][j]) + " ";
        }
        c=c +  "\n";
    }
    cout << c;
    return 0;
} 