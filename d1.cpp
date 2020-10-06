#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    
    system ("clear");
    cout << "================================================================================" << endl;
    cout << "-------------------------------AULA PO: DESAFIO 1-------------------------------" << endl;
    cout << "================================================================================" << endl;


    int matriz[4][4]={4, 1, 2, 3, 5, 2, 1, 400, 2, 1, 3, 8, 7, 1, 2, 5};
    int i, j, intine=0;
    cout << "Digite a coordenada das cidades e depois -1 para finalizar: " << endl;
    cin >> i;
    if (i >= 0 && i < 4){
        cin >> j;
        intine += matriz[i][j];
    }
    else if (i == -1){
        cout << "Intinerario: " << intine << endl;
        return 0;
    }
    else{
        cout << "Cidade não encontrada" << endl;
        return 0;
    }
    
    while (j != -1){
        i = j;
        cin >> j;
        if (j >= 0 && j < 4){
            intine += matriz[i][j];
        }
        else if (j == -1){
            cout << "Intinerario: " << intine << endl;
            return 0;
        }
        else{
            cout << "Cidade não encontrada" << endl;
            return 0;
        }
    }
    return 0;
}

