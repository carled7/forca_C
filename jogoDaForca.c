#include <stdio.h>
#include <string.h>

/*
Nome completo dos integrantes do grupo
- Carlos Eduardo
- Claudio
- Micael
- Samuel
- Vinicius
- Vitor Augusto
*/

int menu();

void cabecalhoCadastro();

int  main(){

    int option = 1, acertos = 0, erros = 0, cadastrado = 0, i, vitoria = 0, errototal = 0, derrotas = 0;
    char palavraChave[30], tema[30], resposta[15], tentativa = ' ', verifica;
    palavraChave[0] = '\0';
    for(i = 0; i < 15; i++){	                
        resposta[i] = ' ';	
	}
    while(option != 0){
        option = menu();

        if(option == 0){
            printf("\nPrograma encerrado. Pressione qualquer tecla!");
            scanf("%c", &tentativa);
            return 0;
        }

        else if(option == 1){
            do{
                cabecalhoCadastro();

                scanf("%s", palavraChave);
                fflush(stdin);

                if(palavraChave[0] == '0'){
                    break;
                }

                verifica = ' ';
                do{
                    if(!(verifica == ' ')){
                        cabecalhoCadastro();
                        printf("%s\n", palavraChave);
                    }

                    printf("\nA palavra digitada foi: '%s', correto? 'S' para sim ou 'N' para nao: ", palavraChave);
                    scanf("%c", &verifica);
                    fflush(stdin);
                } while(!((verifica == 'S') || (verifica == 's') || (verifica == 'N') || (verifica == 'n')));

            } while(!((verifica == 'S') || (verifica == 's')));

            verifica = '\0';
            do{
                if(verifica != '\0'){
                    cabecalhoCadastro();
                    printf("%s\n", palavraChave);
                }
                printf("\nDigite o tema: ");
                scanf("%[^\n]", tema);
                fflush(stdin);

                do{
                    if(verifica != '\0'){
                        cabecalhoCadastro();
                        printf("%s\n\nDigite o tema: %s\n", palavraChave, tema);
                    }
                    printf("\nO tema digitado foi: '%s', correto? 'S' para sim ou 'N' para nao: ", tema);
                    scanf("%c", &verifica);
                    fflush(stdin);
                } while(!((verifica == 'S') || (verifica == 's') || (verifica == 'N') || (verifica == 'n')));
            } while(!((verifica == 'S') || (verifica == 's')));

            cadastrado = strlen(palavraChave);
        }

        else if((option == 2)){
            if(cadastrado != 0){
                do{
                    system("cls"); //esse comando limpa o console

                    printf(  "========================================");
                    printf("\n----------- ADVINHAR PALAVRA -----------");
                    printf("\n========================================");
					
					printf("\nA dica eh: %s", tema);
					printf("\nA palavra possui %d letras\n", cadastrado);
					
                    for(i = 0; i < cadastrado; i++){
                    	
                        if(tentativa == ' '){
                            resposta[i] = '-';
                            continue;
                        }
                        

                        if(tentativa == palavraChave[i]){
                            resposta[i] = palavraChave[i];
                            acertos++;
                        }
                        else{
                        	erros++;
						}
                        
						if(resposta[i] != '-'){
							
                            continue;
                        }else{
                            resposta[i] = '-';
                			            
                        }
                    }
                    
                    printf("\n%s ", resposta);
                    if(acertos == cadastrado){
					                    	
                    	printf("\nParabens voce acertou a palavra!");
                    	acertos = 0;
                    	vitoria++;
                    	tentativa = ' ';
                    	break;
                    	
					}
                									
					if(erros == cadastrado){				
						
						errototal++;
						if(errototal == 1){
							printf("O");
						}
						else if(errototal == 2){
							printf("\n");
						}
						else if(errototal == 3){
							//printf("");
						}
						
						if(errototal == 6){
						                   		
                    		printf("Voce morreu!");
                    		derrotas++;
                    		break;
						}
						
					}       
                                     
					scanf("%c", &tentativa);
					fflush(stdin);
                    erros = 0;
                    
                } while(errototal < 6);
                for(i = 0; i < 15; i++){	                
        			resposta[i] = ' ';	
				}
                
                errototal = 0;
                tentativa = ' ';
                printf("\n[1] - Voltar. ");
                scanf("%d", &option);

                
                cadastrado = 0;
                
            }
            //Verifica se tem alguma palavra cadastrado se sim o usuário pode jogar

            else{
                printf("Cadastre uma palavra primeiro!");
            }
            //Se não tem nenhuma palavra cadastrada pede ao usuário que cadastre uma
        }
        //Quando (option == 2) realiza o jogo com palavra cadastrada

        else{
                printf("\n========================================");
                printf("\n--- QUANTIDADE DE VITORIAS/ DERROTAS ---");
                printf("\n========================================");
                printf("\nVoce venceu %d vezes.", vitoria);
                printf("\nVoce perdeu %d vezes.", derrotas);
                printf("\n[1] - Voltar. ");
                scanf("%d", &option);
                
        }
        //Quando (option == 3) confere as vitorias e derrotas do jogador
    }

    return 0;
}

int menu(){
    int option;

    do{
        system("cls");
        printf(  "========================================");
        printf("\n---------------- MENU ------------------");
        printf("\n========================================");
        printf("\n[1] - Cadastrar palavra.");
        printf("\n[2] - Advinhar palavra (JOGAR).");
        printf("\n[3] - Quantidade de vitorias/derrotas.");
        printf("\n[0] - Sair do programa.");
        printf("\nDigite uma opcao valida: ");
        scanf("%d", &option);
        fflush(stdin);
    } while(!((option == 0) || (option == 1) || (option == 2) || (option == 3)));

    return option;
}


void cabecalhoCadastro(){
    system("cls");
    printf(  "========================================");
    printf("\n---------- CADASTRAR PALAVRA -----------");
    printf("\n========================================");
    printf("\nDigite aqui a palavra ou 0 (zero) para retornar ao Menu: ");
}