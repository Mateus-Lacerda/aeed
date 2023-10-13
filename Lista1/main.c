#include <stdio.h>

int main(){
    // Questão 1 - Quadrado
    int q1(){
        int contador1 = 0;
        for (contador1=1; contador1<=5; contador1++){
            if (contador1==1 || contador1==5){
                printf("XXXXX\n");
            }
            else {
                printf("X   X\n");
            }
        }
        return 0;
    }

    // Questão 2 - Aplicativo bancário
    int q2(){
        float interest = 0.005;
        float deposit;
        float investment;
        int months;
        printf("Digite seu depósito inicial: ");
        scanf("%f", &deposit);
        printf("Digite seu investimento mensal: ");
        scanf("%f", &investment);
        printf("Digite o tempo, em meses, de rendimento: ");
        scanf("%d", &months);

        int contador;
        float profit = deposit;
        for (contador=1; contador<=months; contador+=1){
            if (contador==1){
                profit+=(profit*interest);
            }
            else{
                profit+=investment;
                profit+=(profit*interest);
            }
        }
        printf("Seu lucro final foi de %fR$\n", profit);
        return 0;
    }

    // Questão 3 - Diamante de asteriscos
    int q3(){
        int num;
        printf("Digite aqui um número inteiro ímpar: ");
        scanf("%d", &num);
        if ((num%2)==0){
            q3();
        }
        else {
            int counter, counter2, counter3;
            for (counter=1; counter<=num; counter+=2){
                printf("\n");
                for (counter3=1; counter3<=((num-counter)/2); counter3++){
                    printf(" ");
                }
                for (counter2=0; counter2<counter; counter2++){
                    printf("*");
                }
            }

            for (counter=num-2; counter>=0; counter-=2){
                printf("\n");
                for (counter3=1; counter3<=((num-counter)/2); counter3++){
                    printf(" ");
                }
                for (counter2=0; counter2<counter; counter2++){
                    printf("*");
                }
            }
        }
        return 0;
    }

    // Questão 4 - Matriz de inteiros
    int q4(){
        int size;
        printf("\nDigite a dimensão de sua matriz: ");
        scanf("%d", &size);
        int matrix[size][size];
        for (int i=0; i<size; i++){
            for (int j=0; j<size; j++){
                printf("Digite o item na linha %d e coluna %d de sua matriz: ", (i+1),(j+1));
                scanf("%d", &matrix[i][j]);
            }
        }

        printf("Sua matriz:\n");
        for (int i=0; i<size; i++){
            for (int j=0; j<size; j++){
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }

        int minvalue = matrix[0][0];
        int line = 1;
        for (int i=0; i<size; i++){
            for (int j=0; j<size; j++){
                if (matrix[i][j] < minvalue){
                    minvalue = matrix[i][j];
                    line = i + 1;
                }
            }
        }
        printf("Menor valor da sua matriz: %d. Está localizado na linha %d.\n", minvalue, line);

        return 0;
    }

    // Questo 5 - Dados de pessoas
    int q5(){
        struct people_data
        {
            char name[40];
            int age;
            float weight;
            float height;
        };

        char namevec[3][40];
        printf("Digite o nome de 3 pessoas:\n");
        for (int i=0; i<3; i++){
            printf("Pessoa %d: ", (i+1));
            scanf("%s", &namevec[i]);
        }

        printf("Registro dos dados de %s:\n", namevec[0]);
        struct people_data person1;
        printf("Idade: ");
        scanf("%d", &person1.age);
        printf("Peso (Kg): ");
        scanf("%f", &person1.weight);
        printf("Altura (m): ");
        scanf("%f", &person1.height);

        printf("Registro dos dados de %s:\n", namevec[1]);
        struct people_data person2;
        printf("Idade: ");
        scanf("%d", &person2.age);
        printf("Peso (Kg): ");
        scanf("%f", &person2.weight);
        printf("Altura (m): ");
        scanf("%f", &person2.height);

        printf("Registro dos dados de %s:\n", namevec[2]);
        struct people_data person3;
        printf("Idade: ");
        scanf("%d", &person3.age);
        printf("Peso (Kg): ");
        scanf("%f", &person3.weight);
        printf("Altura (m): ");
        scanf("%f", &person3.height);

        printf("\nDados de %s:\n", namevec[0]);
        printf("Idade: %d anos.\n", person1.age);
        printf("Peso: %fkg.\n", person1.weight);
        printf("Altura: %fm.\n", person1.height);

        printf("\nDados de %s:\n", namevec[1]);
        printf("Idade: %d anos.\n", person2.age);
        printf("Peso: %fkg.\n", person2.weight);
        printf("Altura: %fm.\n", person2.height);

        printf("\nDados de %s:\n", namevec[2]);
        printf("Idade: %d anos.\n", person3.age);
        printf("Peso: %fkg.\n", person3.weight);
        printf("Altura: %fm.\n", person3.height);

        return 0;
    }

    // Questão 6 - Multiplicar matriz
    int q6(){
        int size;
        printf("\nDigite a dimensão de sua matriz: ");
        scanf("%d", &size);
        int matrix[size][size];
        for (int i=0; i<size; i++){
            for (int j=0; j<size; j++){
                printf("Digite o item na linha %d e coluna %d de sua matriz: ", (i+1),(j+1));
                scanf("%d", &matrix[i][j]);
            }
        }

        printf("Sua matriz:\n");
        for (int i=0; i<size; i++){
            for (int j=0; j<size; j++){
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }

        char choice1;
        int line, column, multiplier, multmatrix[size][size];
        printf(R"(Deseja multiplicar uma linha ou uma coluna (digite "l" ou "c")? )");
        scanf(" %c", &choice1);

        if (choice1 == 'l'){
            printf("Qual linha deseja multiplicar? ");
            scanf("%d", &line);
            printf("Por quanto deseja multiplicar? ");
            scanf("%d", &multiplier);
            for (int i=0; i<size; i++) {
                for (int j=0; j<size; j++) {
                    if (i == line-1){
                        multmatrix[i][j] = matrix[i][j]*multiplier;
                    }
                    else {multmatrix[i][j] = matrix[i][j];}
                }
            }
        }
        if (choice1 == 'c'){
            printf("Qual coluna deseja multiplicar? ");
            scanf("%d", &column);
            printf("Por quanto deseja multiplicar? ");
            scanf("%d", &multiplier);
            for (int i=0; i<size; i++) {
                for (int j=0; j<size; j++) {
                    if (j == column-1){
                        multmatrix[i][j] = matrix[i][j]*multiplier;
                    }
                    else {multmatrix[i][j] = matrix[i][j];}
                }
            }
        }

        printf("Sua matriz multiplicada:\n");
        for (int i=0; i<size; i++){
            for (int j=0; j<size; j++){
                printf("%d ", multmatrix[i][j]);
            }
            printf("\n");
        }

    return 0;
    }

    // Menu
    int run;
    do {
        run = 1;
        char choice;
        printf("\nEscolha a questão de 1 a 6, ou digite P para parar: ");
        scanf(" %c", &choice);
        if (choice == '1'){q1();}
        if (choice == '2'){q2();}
        if (choice == '3'){q3();}
        if (choice == '4'){q4();}
        if (choice == '5'){q5();}
        if (choice == '6'){q6();}
        if (choice == 'p' || choice == 'P'){printf("Obrigado por visualizar esta lista! ");run = 0;}
    } while (run == 1);

    return 0;
}
