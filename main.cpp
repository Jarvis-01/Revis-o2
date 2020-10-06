#include <iostream>
#include <fstream>

using namespace std;
    
void cabe(){
    system ("clear");
    cout << "================================================================================" << endl;
    cout << "-------------------------------AULA PO: DESAFIO 2-------------------------------" << endl;
    cout << "================================================================================" << endl;
}

int main() {
    
    char resp='s';
    int lin, col=3, vertice, aresta;
    string nomeArq, ler;
    ifstream arquivoE;

    cabe();
    
    while (!arquivoE.is_open()){
        cout << "Nome do arquivo: ";
        getline(cin, nomeArq);
        
        arquivoE.open(nomeArq);
        if (arquivoE.is_open()){

            arquivoE.seekg(0);
            arquivoE >> vertice;
            
            arquivoE.seekg(1);
            arquivoE >> aresta;
            
            lin = aresta;
            
            int matriz[lin][col], matrizA[vertice][vertice], linA, colA, peso, estradaS[vertice], estradaE[vertice], grauS=0, grauE=0;
            
            arquivoE.seekg(3);
            for (int x = 0; x < lin; x++){
                for (int y = 0; y < col; y++){
                    arquivoE >> matriz[x][y];
                }
            }
            for (int x = 0; x < vertice; x++){
                for (int y = 0; y < vertice; y++){
                    matrizA[x][y] = 0;
                }
            }
            for (int i = 0; i < aresta; i++){
                linA = matriz[i][0];
                colA = matriz[i][1];
                peso = matriz[i][2];
                matrizA[linA][colA] = peso;
            }
            
            for (int i = 0; i < vertice; i++){
                estradaS[i] = 0;
            }
            
            for (int x = 0; x < vertice; x++){
                for (int y = 0; y < vertice; y++){
                    grauS += matrizA[x][y];
                    grauE += matrizA[y][x];
                }
                estradaS[x] = grauS;
                estradaE[x] = grauE;
                grauS = 0;
                grauE = 0;
            }
            cabe();
    
            char resp='s', alt;
            int K;
    
            while (resp != 'n'){
                cout << endl;
                cout << "Digite a alternativa do desafio 2 (outra telha para sair):" << endl;
                cout << "a), b), c), d), e), f), g) ou h)" << endl;
                cout << endl;
                cout << "--> ";
                cin >> alt;
        
                if (alt == 'a'){
                    cabe();
                    
                    cout << "Determie K (representado pela cidade): ";
                    cin >> K;
                    cout << "Estradas que saem de " << K << ": " << estradaS[K] << endl;
                    cout << "Estradas que chegam a " << K << ": " << estradaE[K] << endl;
                }
                else if (alt == 'b'){
                    int maiorE, estra;
                    
                    cabe();
                    
                    for (int i = 0; i < vertice; i++ ){
                        if (maiorE < estradaE[i]){
                            maiorE = estradaE[i];
                            estra = i;
                        }
                    }
                    cout << estra << " chaga o maior numero de estradas: " << maiorE << endl;
                    cout << endl;
                }
                else if (alt == 'c'){
                    cabe();
                    
                   int K;
                   
                   cout << "Digite a cidade K: ";
                   cin >> K;
                   
                   cabe();
                   
                   cout << "Estradas de " << K << ":" << endl; 
                   for (int i = 0; i < vertice; i++){
                       if (matrizA[K][i] != 0){
                           if (matrizA[i][K] != 0){
                               cout << "Entre " << K << " e " << i << " tem mão dupla" << endl;
                           }
                           else{
                               cout << "Entre " << K << " e " << i << " tem mão unica" << endl; 
                           }
                        }
                   }
                }
                else if (alt == 'd'){
                    cabe();
                    
                   int K;
                   
                   cout << "Digite a cidade K: ";
                   cin >> K;
                   
                   cabe();
                   
                   cout << "Saidas diretas para " << K << "\nCidade(s): "; 
                   for (int i = 0; i < vertice; i++){
                        if (matrizA[i][K] != 0){
                            cout << i << " "; 
                        }  
                   }
                   cout << endl;
                }
                else if(alt == 'e'){
                    cabe();
                    
                    int isola=0, entra=0, saida=0;
                    
                    for (int x = 0; x < vertice; x++){
                        for (int y = 0; y < vertice; y++){
                            if (matrizA[x][y] == 0 || matrizA[y][x] == 0 || x != y){
                               isola += 1; 
                            }
                            else if (matrizA[y][x] > 0 && matrizA[x][y] == 0){
                                entra += 1;
                            }
                            else if (matrizA[x][y] > 0 && matrizA[y][x] == 0){
                                saida += 1;
                            }
                        }
                        if (isola == 0){
                            cout << "Cidade " << x << " isolada" << endl;
                        }
                        else if (entra != 0){
                            cout << "Cidade " << x << " possui entrada mas não possui saida" << endl;
                        }
                        else if (saida != 0){
                            cout << "Cidade " << x << " possui saida mas não possui entrada" << endl;
                        }
                        else{
                            cout << "Cidade " << x << " possui saida e entrada" << endl;
                        }
                    }
                }
                else if (alt == 'f'){
                    cabe();
                    
                    int M, num1, num2, resp=0;
                    
                    cout << "Digite M (quantidade de numeros da sequencia): ";
                    cin >> M;
                    
                    int vetor[M];
                    
                    cabe();
                    
                    cout << "Digite a sequencia: ";
                    for (int i = 0; i < M; i++){
                        cin >> vetor[i];
                    }
                    for (int i = 0; i < M; i++){
                        num1 = vetor[i];
                        if ((i+1) < M){
                            num2 = vetor[i+1];
                        
                            if (matrizA[num1][num2] != 0){
                                resp += 1;
                            }
                        }
                    }
                    if (resp == M-1){
                        cabe();
                        
                        cout << "Sequencia possivel" << endl;
                    }
                    else if (resp < M-1){
                        cabe();
                        
                        cout << "Sequencia impossivel" << endl;
                    }
                }
                else if (alt == 'g'){ //REVER
                    cabe();
                    
                    int K, P;
                    
                    cout << "Digite as cidades 'K' e 'P': ";
                    cin >> K;
                    cin >> P;
                    
                    if (matrizA[K][P] != 0){
                        cout << "Caminho mais curto: " << K << "->" << P << endl;
                    }
                    else{
                        for (int j=(vertice-1); j >= 0; j-- ){
                            if (matrizA[K][j] != 0 && matrizA[j][P] != 0){ 
                                cout << "Caminho mais curto: " << K << "->" << j << "->" << P << endl;  
                            } 
                            else if (matrizA[K][j-1] != 0 && matrizA[j-1][j] != 0 && matrizA[j][P] != 0){
                                    cout << "Caminho mais curto: " << K << "->" << (j-1) << "->" << j << "->" << P << endl;
                                
                            }
                        }
                        
                    }
                }
                else if (alt == 'h'){
                    //continua...
                }
                else{
                    return 0;
                }
            }
        }
        else{
            cabe();
            cout << "Arquivo não encontrado" << endl;
        }
    }
    arquivoE.close();
    return 0;
}