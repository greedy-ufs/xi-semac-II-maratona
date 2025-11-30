#include <iostream>
#include <sstream>
#include <string>

int main(){
    std::string referencia;
    std::string total;
    std::cin >> referencia;
    std::cin >> total;
    long long int j = referencia.size();
    long long int x = 0;
    int erro = 0;
    long long int i = 0;

    while(i < total.size() && x < j){
        if(total[i] == referencia[x]){
            x++;
        }
        else{
            if(erro == 0 && x > 0)
                erro++;
            else if(erro >= 1){
                x = 0;
                erro = 0;
            }
        }
        i++;
    }

    if(x == j)
        std::cout << "MUITO FACIL\n";
    else
        std::cout << "NAO MUITO FACIL\n";

    return 0;
}