#include <iostream>
#include <math.h>

using namespace std;

void cabe(){
    system ("clear");
    cout << "================================================================================" << endl;
    cout << "----------------------------ATIVIDADES AULA PO 06/10----------------------------" << endl;
    cout << "================================================================================" << endl;
}

int atividade08(int vetor[], int tamanho){
    if (tamanho == 0){
       return 0;
    }
    else{
        return (vetor[tamanho-1] + atividade08(vetor, tamanho-1));
    }
}
void atividade09(){
    int n, i=1, resp=0;
    
    cabe();
    
    cout << "Digite o valor de 'n' (para n > 0): ";
    cin >> n;
    
    for (int j = 0; j < n; j++){
        resp += i*(i+1);
        i++;
    }
    cout << "Resposta: " << resp << endl;
}
void atividade10(){
    int n, i, j, resp=0;
    
    cabe();
    
    cout << "Qual a ordem das matrizes 'A' e 'B' (Ex: 3 se for 3x3): ";
    cin >> n;
    int matA[n][n], matB[n][n];
    
    //Questão pede as matrizes do exercicio 3 mas elas não foram salvas pois o exercicio não pede para salva-las
    for (int lin=0; lin < n; lin++){
        cout << "Digite os numeros da " << (lin+1) << "ª linha da mariz 'A': ";
        for (int col=0; col < n; col++){
            cin >>matA[lin][col];
        }
    }
    for (int lin=0; lin < n; lin++){
        cout << "Digite os numeros da " << lin << "ª linha da mariz 'B': ";
        for (int col=0; col < n; col++){
            cin >>matB[lin][col];
        }
    }
    
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            resp += (matA[i][j] * matB[i][j]);
        }
    }

    cout << "Resposta: " << resp << endl;
}

void atividade11(){
    cabe();
    
    int i, n, Snu, Sde, S2nu, S2de;
    
    cout << "Digite o valor de 'n': ";
    cin >> n;
     
    if (n >= 1){
        Snu = ((2*1) - 1);
        Sde =  (pow((-2),(1+1)));
        
        for (i = 2; i <= n; i++){
            S2nu = ((2*i) - 1);
            S2de =  (pow((-2),(i+1)));
            
            Snu = ((Snu*S2de) + (Sde*S2nu));
            Sde = (Sde * S2de);
            
            if (Snu < 0 && Sde < 0){
                Snu *= -1;
                Sde *= -1;
            }
        }
        while (Snu%2 == 0 && Sde%2 == 0){
            Snu /= 2;
            Sde /= 2;
        }
    }
    cout << "S = " << Snu << "/" << Sde << endl;
}
 
int main(){
    int resp=8;
    
    cabe();
    while (resp){
        cout << "Deseja ver a resposta da atividade 8, 9, 10 ou 11? (outra tecla para sair) ";
        cin >> resp;
    
        if (resp == 8){
           int t;
           
           cout << "Tamanho do vetor: ";
           cin >> t;
           int vet[t], p=0;
           
           for (int i = 0; i < t; i++){
               cout << "Digite o " << (i+1) << "º numero: ";
               cin >> vet[i];
           }           
           cout << "Soma: " << atividade08(vet, t) << endl;
        }
        else if (resp == 9){
            atividade09();
        }
        else if (resp == 10){
           atividade10();
        }
        else if (resp == 11){
            atividade11();
        }
        else{
            return 0;
        }
    }
}

