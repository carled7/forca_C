#include <stdio.h>
#include <string.h>

/*
Nome completo dos integrantes do grupo
- Carlos Eduardo
- Claudio
- Micael
- Samuel
- Vinicius
- Vicente
*/

int  main(){

    int option = 0, acertos = 0, erros = 0;
    char palavraChave[15], tema[15], resposta[15], tentativa = ' ';
    while(option != 4){
        system("cls");
        switch(option){
        case 1:
            printf("\n========================================");
            printf("\n---------- CADASTRAR PALAVRA -----------");
            printf("\n========================================");
            printf("\nDigite aqui a palavra: ");
            scanf("%s", palavraChave);
            printf("\nDigite aqui o tema: ");
            scanf("%s", tema);

            option = 0;
            break;
        case 2:
            do {
                system("cls"); //esse comando limpa o console

                printf("\n========================================");
                printf("\n----------- ADVINHAR PALAVRA -----------");
                printf("\n========================================");

                printf("\n");
                for(int i = 0; i < strlen(palavraChave); i++){

                    if(tentativa == ' '){
                        resposta[i] = '-';
                        continue;
                    }

                    if(tentativa == palavraChave[i]){
                        resposta[i] = palavraChave[i];
                        acertos++;
                    }else if(resposta != '-'){
                        continue;
                    }else{
                        resposta[i] = '-';
                    }
                }
                printf("\n%s ", resposta);
                scanf("%c", &tentativa);
                fflush(stdin);
            }while(erros < 6);
            printf("\n[0] - Voltar. ");
            scanf("%d", &option);
            break;
        case 3:
            printf("\n========================================");
            printf("\n--- QUANTIDADE DE VITORIAS/ DERROTAS ---");
            printf("\n========================================");
            printf("\n[0] - Voltar. ");
            scanf("%d", &option);
            break;
        default:
            printf("\n========================================");
            printf("\n---------------- MENU ------------------");
            printf("\n========================================");
            printf("\n[1] - Cadastrar palavra.");
            printf("\n[2] - Advinhar palavra (JOGAR).");
            printf("\n[3] - Quantidade de vitorias/derrotas.");
            printf("\n[4] - Sair do programa. ");
            scanf("%d", &option);
        }
    }
return 0;
}
