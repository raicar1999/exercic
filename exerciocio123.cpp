#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    char nome[50];
    Data dataNascimento;
    int idade;
    char sexo; 
} Cliente;


int calcularIdade(Data dataNascimento, Data dataAtual) {
    int idade = dataAtual.ano - dataNascimento.ano;
    
    if (dataAtual.mes < dataNascimento.mes ||
        (dataAtual.mes == dataNascimento.mes && dataAtual.dia < dataNascimento.dia)) {
        idade--;
    }
    
    return idade;
}

int main() {
    Cliente cliente;
    Data dataAtual;
    
    
    time_t t = time(NULL);
    struct tm *data = localtime(&t);
    dataAtual.dia = data->tm_mday;
    dataAtual.mes = data->tm_mon + 1;
    dataAtual.ano = data->tm_year + 1900;

    printf("Nome do cliente: ");
    fgets(cliente.nome, sizeof(cliente.nome), stdin);
    
    printf("Data de nascimento (dia mes ano): ");
    scanf("%d %d %d", &cliente.dataNascimento.dia, &cliente.dataNascimento.mes, &cliente.dataNascimento.ano);
    
    getchar(); 
    
    printf("Sexo (M/F): ");
    scanf("%c", &cliente.sexo);
    
 
    cliente.idade = calcularIdade(cliente.dataNascimento, dataAtual);
    
    printf("\nInformacoes do cliente:\n");
    printf("Nome: %s", cliente.nome);
    printf("Data de Nascimento: %d/%d/%d\n", cliente.dataNascimento.dia, cliente.dataNascimento.mes, cliente.dataNascimento.ano);
    printf("Sexo: %c\n", cliente.sexo);
    printf("Idade: %d\n", cliente.idade);

    return 0;
}

