#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

string cifrarTexto(string texto, int chave)
{
    string textoCifrado = "";
    int i = 0;
    char c;

    for(i; i < texto.length(); i++)
    {
        c = texto[i];
        
        if(isalpha(c))
        {
            c = char(int(c + chave - 97) % 26 + 97);
        }

        textoCifrado += c;
    }

    return textoCifrado;
}

int main()
{
    string texto;
    int chave;

    cout << "\nInforme o texto a ser cifrado, lembre-se de não utilizar acentuação: ";
    getline(cin, texto);

    cout << "\nDigite a chave (número de deslocamentos): ";
    cin >> chave;

    transform(texto.begin(), texto.end(), texto.begin(), ::tolower);

    string textoCifrado = cifrarTexto(texto, chave);
    cout << "\nMensagem Cifrada: " << textoCifrado << endl;

    return 0;
}