#include <stdio.h>
#include <string.h>


struct Funcionario {
    char nome[50];
    char cargo[50];
    float salario_base;
    float beneficios;
    float descontos;
};


float calcularSalarioLiquido(struct Funcionario funcionario) {
    return funcionario.salario_base + funcionario.beneficios - funcionario.descontos;
}

int main() {
    struct Funcionario funcionarios[MAX_FUNCIONARIOS];
    int num_funcionarios;

   
    printf("Quantos funcion�rios deseja cadastrar (at� %d)? ", MAX_FUNCIONARIOS);
    scanf("%d", &num_funcionarios);

    if (num_funcionarios > MAX_FUNCIONARIOS) {
        printf("O n�mero de funcion�rios excede o limite.\n");
        return 1;
    }

    for (int i = 0; i < num_funcionarios; i++) {
        printf("\nFuncion�rio %d:\n", i + 1);
        printf("Nome: ");
        scanf("%s", funcionarios[i].nome);
        printf("Cargo: ");
        scanf("%s", funcionarios[i].cargo);
        printf("Sal�rio base: ");
        scanf("%f", &funcionarios[i].salario_base);
        printf("Benef�cios: ");
        scanf("%f", &funcionarios[i].beneficios);
        printf("Descontos: ");
        scanf("%f", &funcionarios[i].descontos);
    }


    printf("\nDados dos funcion�rios:\n");
    for (int i = 0; i < num_funcionarios; i++) {
        printf("\nFuncion�rio %d:\n", i + 1);
        printf("Nome: %s\n", funcionarios[i].nome);
        printf("Cargo: %s\n", funcionarios[i].cargo);
        printf("Sal�rio L�quido: %.2f\n", calcularSalarioLiquido(funcionarios[i]));
    }

    
    float total_salarios = 0;
    for (int i = 0; i < num_funcionarios; i++) {
        total_salarios += calcularSalarioLiquido(funcionarios[i]);
    }
    float media_salarial = total_salarios / num_funcionarios;
    printf("\nM�dia Salarial da Loja: %.2f\n", media_salarial);


    int indice_maior_salario = 0;
    for (int i = 1; i < num_funcionarios; i++) {
        if (calcularSalarioLiquido(funcionarios[i]) > calcularSalarioLiquido(funcionarios[indice_maior_salario])) {
            indice_maior_salario = i;
        }
    }
    printf("Funcion�rio com Maior Sal�rio: %s\n", funcionarios[indice_maior_salario].nome);

    return 0;
}

