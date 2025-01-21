#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

typedef string Token;

typedef enum Simbolos
{
    simb_end,
    simb_var,
    simb_bool,
    simb_char,
    simb_int,
    simb_longint,
    simb_string,
    simb_abre_chaves,
    simb_fecha_chave,
    simb_abre_colchete,
    simb_fecha_colchete,
    simb_abre_parenteses,
    simb_fecha_parenteses,
    simb_pontoFina,
    simb_mais,
    simb_atribuicao,
    simb_intervalo,
    simb_identificador,
    simb_numero,
    simb_erro,
    simb_program,
    simb_begin,
    simb_menorQue,
    simb_maiorQue,
    simb_menorIgual,
    simb_maiorIgual,
    simb_doisPontos,
    simb_virgula,
    simb_exclamacao
} Simbolos;

unordered_map<string, Simbolos> palavras_chave = {
    {"program", simb_program},
    {"char", simb_char},
    {"integer", simb_int},
    {"var", simb_var},
    {"boolean", simb_bool},
    {"longint", simb_longint},
    {"begin", simb_begin},
    {"end.", simb_end},
    {"string", simb_string}};

unordered_map<char, Simbolos> simbolos_especiais = {
    {'(', simb_abre_parenteses},
    {')', simb_fecha_parenteses},
    {'[', simb_abre_colchete},
    {']', simb_fecha_colchete},
    {'<', simb_menorQue},
    {'>', simb_maiorQue},
    {'{', simb_abre_chaves},
    {'}', simb_fecha_chave},
    {':', simb_doisPontos},
    {',', simb_virgula},
    {'.', simb_pontoFina},
    {'+', simb_mais},
    {'!', simb_exclamacao}};

void proximo_char(string &input, long long &index, char &atual)
{
    if (index < input.length())
        atual = input[index++];
    else
        atual = '\0';
}

void analisador_lexico(string &input, long long &index, Token &token, Simbolos &simbolo)
{
    char atual;
    proximo_char(input, index, atual);

    while (isspace(atual))
        proximo_char(input, index, atual);

    token.clear();

    if (simbolos_especiais.find(atual) != simbolos_especiais.end())
    {
        token += atual;
        proximo_char(input, index, atual);

        if (token == ":")
        {
            if (atual == '=')
            {
                token += atual;
                proximo_char(input, index, atual);
                simbolo = simb_atribuicao;
            }
            else
            {
                simbolo = simb_doisPontos;
            }
        }
        else if (token == ".")
        {
            if (atual == '.')
            {
                token += atual;
                proximo_char(input, index, atual);
                simbolo = simb_intervalo;
            }
            else
            {
                simbolo = simb_pontoFina;
            }
        }
        else if (token == "<")
        {
            if (atual == '=')
            {
                token += atual;
                proximo_char(input, index, atual);
                simbolo = simb_menorIgual;
            }
            else
            {
                simbolo = simb_menorQue;
            }
        }
        else if (token == ">")
        {
            if (atual == '=')
            {
                token += atual;
                proximo_char(input, index, atual);
                simbolo = simb_maiorIgual;
            }
            else
            {
                simbolo = simb_maiorQue;
            }
        }
        else
        {
            simbolo = simbolos_especiais[token[0]];
        }
    }
    else if (isalpha(atual))
    {
        while (isalnum(atual))
        {
            token += atual;
            proximo_char(input, index, atual);
        }
        if (palavras_chave.find(token) != palavras_chave.end())
        {
            simbolo = palavras_chave[token];
        }
        else
        {
            simbolo = simb_identificador;
        }
    }
    else if (isdigit(atual))
    {
        while (isdigit(atual))
        {
            token += atual;
            proximo_char(input, index, atual);
        }
        if (isalpha(atual))
        {
            simbolo = simb_erro; // Identificador não pode começar com número
        }
        else
        {
            simbolo = simb_numero;
        }
    }
    else
    {
        simbolo = simb_erro;
    }
    
    // Voltar um caractere se necessário para não perder símbolos especiais
    if (index > 0 && simbolos_especiais.find(input[index - 1]) != simbolos_especiais.end())
    {
        index--;
    }
}

int main()
{
    ifstream myfile("teste.pas");
    string input((istreambuf_iterator<char>(myfile)), istreambuf_iterator<char>());
    Token token;
    Simbolos simbolo;
    long long index = 0;

    while (index < input.length())
    {
        analisador_lexico(input, index, token, simbolo);
        cout << "Token: " << token << ", Símbolo: " << simbolo << endl;
    }

    return 0;
}
