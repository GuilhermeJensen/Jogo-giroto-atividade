#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <locale.h>
#include <string.h>
// Estrutura para armazenar informações sobre uma pergunta
typedef struct {
    char pergunta[200];
    char alternativas[4][100];
    char resposta_correta;
} Pergunta;
// Funções de utilidade
void gotoxy(int x, int y) {
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void limparTela() {
    system("cls");
}
void pausar() {
    printf("\nPressione \"enter\" para continuar...");
    fflush(stdin);
    getchar();
}
// Funções do jogo Perguntas e Respostas
void inicializarPerguntas(Pergunta perguntas[][8], int numPerguntasPorNivel) {
    // Perguntas de nível fácil
    strcpy(perguntas[0][0].pergunta, "QUANTO SAO 5+5?");
    strcpy(perguntas[0][0].alternativas[0], "5");
    strcpy(perguntas[0][0].alternativas[1], "7");
    strcpy(perguntas[0][0].alternativas[2], "10");
    strcpy(perguntas[0][0].alternativas[3], "2");
    perguntas[0][0].resposta_correta = 'C';
    
    strcpy(perguntas[0][1].pergunta, "O QUE ESTA ESCRITO NA BANDEIRA DO BRASIL?");
    strcpy(perguntas[0][1].alternativas[0], "ORDEM E REGRESSO");
    strcpy(perguntas[0][1].alternativas[1], "ORDEM E RETROCESSO");
    strcpy(perguntas[0][1].alternativas[2], "ORDEM E PROGRESSO");
    strcpy(perguntas[0][1].alternativas[3], "PROGRESSO E ORDEM");
    perguntas[0][1].resposta_correta = 'C';
    
    strcpy(perguntas[0][2].pergunta, "QUAL O SIGNIFICADO DA PALAVRA INGLESA 'HORSE'?");
    strcpy(perguntas[0][2].alternativas[0], "CASA");
    strcpy(perguntas[0][2].alternativas[1], "CAVALO");
    strcpy(perguntas[0][2].alternativas[2], "ELEFANTE");
    strcpy(perguntas[0][2].alternativas[3], "HIPOPOTAMO");
    perguntas[0][2].resposta_correta = 'B';
    
    strcpy(perguntas[0][3].pergunta, "COMO E CONHECIDO O INVENTOR DO AVIAO?");
    strcpy(perguntas[0][3].alternativas[0], "SANTOS DUMONT");
    strcpy(perguntas[0][3].alternativas[1], "SANTOS DUMORRO");
    strcpy(perguntas[0][3].alternativas[2], "SANTOS DRUMOM");
    strcpy(perguntas[0][3].alternativas[3], "SANTOS SILVA");
    perguntas[0][3].resposta_correta = 'A';
    
    strcpy(perguntas[0][4].pergunta, "QUAL DOS ITENS ABAIXO NAO E UMA FRUTA?");
    strcpy(perguntas[0][4].alternativas[0], "LARANJA");
    strcpy(perguntas[0][4].alternativas[1], "MANGA");
    strcpy(perguntas[0][4].alternativas[2], "QUIABO");
    strcpy(perguntas[0][4].alternativas[3], "BANANA");
    perguntas[0][4].resposta_correta = 'C';
    
    strcpy(perguntas[0][5].pergunta, "QUAL E O SATELITE NATURAL DA TERRA?");
    strcpy(perguntas[0][5].alternativas[0], "SPUTNICK");
    strcpy(perguntas[0][5].alternativas[1], "RUBLE");
    strcpy(perguntas[0][5].alternativas[2], "SOYUS");
    strcpy(perguntas[0][5].alternativas[3], "LUA");
    perguntas[0][5].resposta_correta = 'D';
    
    strcpy(perguntas[0][6].pergunta, "QUAL DOS ESTADOS ABAIXO NAO POSSUI PRAIAS?");
    strcpy(perguntas[0][6].alternativas[0], "RIO DE JANEIRO");
    strcpy(perguntas[0][6].alternativas[1], "CEARA");
    strcpy(perguntas[0][6].alternativas[2], "GOIAS");
    strcpy(perguntas[0][6].alternativas[3], "SAO PAULO");
    perguntas[0][6].resposta_correta = 'C';
    
    strcpy(perguntas[0][7].pergunta, "QUAL O SIGNIFICADO DA SILGLA ONU?");
    strcpy(perguntas[0][7].alternativas[0], "ORGANIZACAO NACIONAL UNICA");
    strcpy(perguntas[0][7].alternativas[1], "ORDEN NACIONAL UNICA");
    strcpy(perguntas[0][7].alternativas[2], "ORGANIZACAO DAS NACOES UNIDAS");
    strcpy(perguntas[0][7].alternativas[3], "NENHUMA DAS ALTERNATIVAS");
    perguntas[0][7].resposta_correta = 'C';
    
    // Perguntas de nível médio
    strcpy(perguntas[1][0].pergunta, "QUANTOS ESTADOS POSSUI O BRASIL?");
    strcpy(perguntas[1][0].alternativas[0], "20 ESTADOS");
    strcpy(perguntas[1][0].alternativas[1], "25 ESTADOS");
    strcpy(perguntas[1][0].alternativas[2], "27 ESTADOS");
    strcpy(perguntas[1][0].alternativas[3], "30 ESTADOS");
    perguntas[1][0].resposta_correta = 'C';
    
    strcpy(perguntas[1][1].pergunta, "QUAL O NOME DA ESCALA QUE MEDE A MAGNITUDE DOS TERREMOTOS?");
    strcpy(perguntas[1][1].alternativas[0], "ESCALA RICHMOR");
    strcpy(perguntas[1][1].alternativas[1], "ESCALA SISMICA");
    strcpy(perguntas[1][1].alternativas[2], "ESCALA TERMICA");
    strcpy(perguntas[1][1].alternativas[3], "ESCALA RICHTER");
    perguntas[1][1].resposta_correta = 'D';
    
    // Preencha as demais perguntas de nível médio aqui
    
    // Perguntas de nível difícil (preencha conforme necessário)
}
int fazerPergunta(Pergunta p, int numeroPergunta, const char *nivelNome) {
    char resposta;
    
    limparTela();
    printf("--------------------------------\n");
    printf("|  Pergunta n. %.2d - Nivel %s  |\n", numeroPergunta, nivelNome);
    printf("--------------------------------\n\n");
    printf("%s\n", p.pergunta);
    printf("-------------------------------------------------------------------------------\n");
    printf("A) %s\n", p.alternativas[0]);
    printf("B) %s\n", p.alternativas[1]);
    printf("C) %s\n", p.alternativas[2]);
    printf("D) %s\n", p.alternativas[3]);
    printf("-------------------------------------------------------------------------------\n");
    printf("Qual a resposta certa? ");
    
    fflush(stdin);
    scanf(" %c", &resposta);
    resposta = toupper(resposta);
    
    if (resposta == p.resposta_correta) {
        printf("Resposta correta\n");
        return 1;
    } else {
        printf("Resposta errada\n");
        printf("Resposta correta: Letra \"%c\"\n", p.resposta_correta);
        return 0;
    }
}
void jogarPerguntasERespostas() {
    char nome[40];
    char jogarNovamente;
    int nivel;
    Pergunta perguntas[3][8]; // 3 níveis, 8 perguntas por nível
    int pontosPorNivel[] = {2, 4, 6}; // Pontos por nível (fácil, médio, difícil)
    const char *nomeNiveis[] = {"Facil", "Medio", "Dificil"};
    int acertos, erros;
    int numPerguntas = 8;
    int i;
    
    inicializarPerguntas(perguntas, numPerguntas);
    
    do {
        limparTela();
        printf(" JOGO PERGUNTAS E RESPOSTAS, VAMOS TESTAR OS CONHECIMENTOS \n");
        printf("\nInforme o nome do participante e em seguida pressione \"enter\".\n\n");
        printf("\nNOME DO PARTICIPANTE: ");
        fflush(stdin);
        gets(nome);
        
        limparTela();
        printf("\nSEJA BEM VINDO \"%s\"\n", nome);
        printf("-------------------------------------------------------------------------------\n");
        printf("Este e um jogo divertido de perguntas e respostas. O jogador devera escolher\n");
        printf("dentre as 4 alternativas apenas uma e em seguida pressionar \"enter\".\n\n");
        printf("O jogo possui 3 niveis de dificuldade:\n\n");
        printf("Nivel facil   - Cada resposta certa valera %d pontos\n", pontosPorNivel[0]);
        printf("Nivel medio   - Cada resposta certa valera %d pontos\n", pontosPorNivel[1]);
        printf("Nivel dificil - Cada resposta certa valera %d pontos\n", pontosPorNivel[2]);
        printf("-------------------------------------------------------------------------------\n");
        printf("Boa sorte e bom jogo\n\n");
        pausar();
        
        do {
            limparTela();
            printf("-----------------------------\n");
            printf("|    NIVEIS DE DIFICULDADE    |\n");
            printf("-----------------------------\n");
            printf("|  1 - NIVEL FACIL           |\n");
            printf("|  2 - NIVEL MEDIO           |\n");
            printf("|  3 - NIVEL DIFICIL         |\n");
            printf("-----------------------------\n");
            printf("DESEJA JOGAR EM QUAL NIVEL? \n");
            scanf("%d", &nivel);
            
            if (nivel < 1 || nivel > 3) {
                printf("Nível inválido! Escolha entre 1 e 3.\n");
                pausar();
                continue;
            }
            
            nivel--; // Ajusta para índice 0-2
            
            limparTela();
            printf(" nivel %s\n", nomeNiveis[nivel]);
            printf("AS PERGUNTAS DE NIVEL \"%s\" VALEM %d PONTOS CADA\n\n", 
                   nomeNiveis[nivel], pontosPorNivel[nivel]);
            
            fflush(stdin);
            pausar();
            
            acertos = 0;
            erros = 0;
            
            // Apresentar cada pergunta do nível
            for (i = 0; i < numPerguntas; i++) {
                if (fazerPergunta(perguntas[nivel][i], i+1, nomeNiveis[nivel])) {
                    acertos++;
                } else {
                    erros++;
                }
                
                printf("-------------------------------------------------------------------------------\n");
                pausar();
            }
            
            // Mostrar resultado
            limparTela();
            printf("As perguntas deste nível terminaram.\n\n");
            printf("Resultados:\n");
            printf("- Respostas corretas: %d\n", acertos);
            printf("- Respostas erradas: %d\n", erros);
            printf("- Pontuação total: %d pontos\n\n", acertos * pontosPorNivel[nivel]);
            
            printf("Deseja jogar em outro nível? (s/n): ");
            fflush(stdin);
            scanf(" %c", &jogarNovamente);
            
        } while (jogarNovamente == 's' || jogarNovamente == 'S');
        
        printf("\nDeseja jogar novamente com outro nome? (s/n): ");
        fflush(stdin);
        scanf(" %c", &jogarNovamente);
        
    } while (jogarNovamente == 's' || jogarNovamente == 'S');
}
// Funções para o jogo Cobra na Caixa
void jogarCobraNaCaixa() {
    char jogador1[40], jogador2[40];
    int caixaCobra, caixaBotao;
    int caixaEscolhida;
    int jogadorAtual;
    int jogarNovamente;
    
    do {
        limparTela();
        printf("==================================\n");
        printf("         COBRA NA CAIXA!          \n");
        printf("==================================\n\n");
        printf("Dois exploradores ficaram presos em uma tumba egípcia!\n");
        printf("No centro da sala, há cinco caixas: uma contém o botão para abrir a porta,\n");
        printf("enquanto outra esconde uma cobra mortal.\n\n");
        
        printf("Digite o nome do Jogador 1: ");
        fflush(stdin);
        gets(jogador1);
        
        printf("Digite o nome do Jogador 2: ");
        fflush(stdin);
        gets(jogador2);
        
        // Sorteio para determinar quem começa
        srand(time(NULL));
        jogadorAtual = rand() % 2 + 1; // 1 ou 2
        
        // Posições aleatórias para cobra e botão
        caixaCobra = rand() % 5 + 1; // 1 a 5
        do {
            caixaBotao = rand() % 5 + 1; // 1 a 5
        } while (caixaBotao == caixaCobra);
        
        printf("\n%s e %s estão presos na tumba!\n", jogador1, jogador2);
        printf("O sorteio determinou que %s começa!\n\n", 
               jogadorAtual == 1 ? jogador1 : jogador2);
        
        pausar();
        
        int fimDeJogo = 0;
        
        while (!fimDeJogo) {
            limparTela();
            printf("==================================\n");
            printf("         COBRA NA CAIXA!          \n");
            printf("==================================\n\n");
            
            printf("Vez de %s\n\n", jogadorAtual == 1 ? jogador1 : jogador2);
            printf("Caixas disponíveis: [1] [2] [3] [4] [5]\n\n");
            
            printf("Escolha uma caixa (1-5): ");
            scanf("%d", &caixaEscolhida);
            
            if (caixaEscolhida < 1 || caixaEscolhida > 5) {
                printf("\nCaixa inválida! Escolha entre 1 e 5.\n");
                pausar();
                continue;
            }
            
            if (caixaEscolhida == caixaCobra) {
                limparTela();
                printf("OH NÃO! %s encontrou a COBRA!\n\n",
                       jogadorAtual == 1 ? jogador1 : jogador2);
                printf("      /^\\/^\\\n");
                printf("     _|__|  O|\n");
                printf("\\/  /~     \\_/ \\\n");
                printf(" \\____|__________/ \\\n");
                printf("        \\_______      \\\n");
                printf("                `\\     \\\n");
                
                printf("\n%s PERDEU! %s VENCEU!\n", 
                       jogadorAtual == 1 ? jogador1 : jogador2,
                       jogadorAtual == 1 ? jogador2 : jogador1);
                
                fimDeJogo = 1;
            }
            else if (caixaEscolhida == caixaBotao) {
                limparTela();
                printf("PARABÉNS! %s encontrou o BOTÃO!\n\n", 
                       jogadorAtual == 1 ? jogador1 : jogador2);
                printf("    ________\n");
                printf("   /        \\\n");
                printf("  /          \\\n");
                printf(" | [BOTÃO]    |\n");
                printf("  \\          /\n");
                printf("   \\________/\n");
                
                printf("\n%s VENCEU! A porta da tumba se abriu!\n", 
                       jogadorAtual == 1 ? jogador1 : jogador2);
                
                fimDeJogo = 1;
            }
            else {
                printf("\nA caixa está vazia! Nada aconteceu.\n");
                pausar();
                
                // Alternar jogador
                jogadorAtual = (jogadorAtual == 1) ? 2 : 1;
            }
        }
        
        printf("\nDeseja jogar novamente? (1-Sim / 0-Não): ");
        scanf("%d", &jogarNovamente);
        
    } while (jogarNovamente == 1);
}
// Estruturas e funções para o jogo Gousmas War
typedef struct {
    int furia;
    int ativa;
} Gousma;
typedef struct {
    char nome[40];
    Gousma gousmas[2];
} Jogador;
void inicializarJogadores(Jogador *jogador1, Jogador *jogador2) {
    int i;
    
    printf("Nome do Jogador 1: ");
    fflush(stdin);
    gets(jogador1->nome);
    
    printf("Nome do Jogador 2: ");
    fflush(stdin);
    gets(jogador2->nome);
    
    // Inicializar Gousmas
    for (i = 0; i < 2; i++) {
        jogador1->gousmas[i].furia = 1;
        jogador1->gousmas[i].ativa = 1;
        jogador2->gousmas[i].furia = 1;
        jogador2->gousmas[i].ativa = 1;
    }
}
void mostrarEstadoJogo(Jogador jogador1, Jogador jogador2) {
    int i;
    
    printf("%s:\n", jogador1.nome);
    for (i = 0; i < 2; i++) {
        if (jogador1.gousmas[i].ativa) {
            printf("Gousma %d: Fúria %d\n", i+1, jogador1.gousmas[i].furia);
        } else {
            printf("Gousma %d: Inativa\n", i+1);
        }
    }
    
    printf("\n%s:\n", jogador2.nome);
    for (i = 0; i < 2; i++) {
        if (jogador2.gousmas[i].ativa) {
            printf("Gousma %d: Fúria %d\n", i+1, jogador2.gousmas[i].furia);
        } else {
            printf("Gousma %d: Inativa\n", i+1);
        }
    }
}
int contarGousmasAtivas(Jogador jogador) {
    int i, count = 0;
    
    for (i = 0; i < 2; i++) {
        if (jogador.gousmas[i].ativa) {
            count++;
        }
    }
    
    return count;
}
void jogarGousmasWar() {
    Jogador jogador1, jogador2;
    Jogador *jogadorAtual, *jogadorOponente;
    int jogadorAtualNum = 1;
    int gousmaOrigem, gousmaAlvo;
    int acao;
    int jogarNovamente;
    int i;
    
    do {
        limparTela();
        printf("==================================\n");
        printf("         GOUSMAS WAR              \n");
        printf("==================================\n\n");
        printf("Um jogo de estratégia com criaturas chamadas Gousmas!\n\n");
        
        inicializarJogadores(&jogador1, &jogador2);
        
        printf("\nCada jogador começa com duas Gousmas com nível de fúria 1.\n");
        printf("Quando uma Gousma ataca, transfere toda sua fúria para a Gousma atacada.\n");
        printf("Se uma Gousma atingir fúria maior que 5, ela se desintegra.\n");
        printf("Você pode dividir uma Gousma se tiver apenas uma ativa.\n");
        printf("O jogador que perder todas as Gousmas perde o jogo.\n\n");
        
        pausar();
        
        int fimDeJogo = 0;
        
        while (!fimDeJogo) {
            limparTela();
            
            // Definir jogador atual e oponente
            if (jogadorAtualNum == 1) {
                jogadorAtual = &jogador1;
                jogadorOponente = &jogador2;
            } else {
                jogadorAtual = &jogador2;
                jogadorOponente = &jogador1;
            }
            
            printf("==================================\n");
            printf("         GOUSMAS WAR              \n");
            printf("==================================\n\n");
            
            printf("Turno de: %s\n\n", jogadorAtual->nome);
            
            // Mostrar estado atual do jogo
            mostrarEstadoJogo(jogador1, jogador2);
            
            // Verificar se o jogador atual perdeu
            if (contarGousmasAtivas(*jogadorAtual) == 0) {
                printf("\n%s perdeu todas as Gousmas!\n", jogadorAtual->nome);
                printf("%s é o vencedor!\n", jogadorOponente->nome);
                fimDeJogo = 1;
                break;
            }
            
            // Verificar se o oponente perdeu
            if (contarGousmasAtivas(*jogadorOponente) == 0) {
                printf("\n%s perdeu todas as Gousmas!\n", jogadorOponente->nome);
                printf("%s é o vencedor!\n", jogadorAtual->nome);
                fimDeJogo = 1;
                break;
            }
            
            // Escolher ação
            printf("\nAções disponíveis:\n");
            printf("1. Atacar\n");
            
            if (contarGousmasAtivas(*jogadorAtual) == 1) {
                // Encontrar a Gousma ativa
                int gousmaAtiva = -1;
                for (i = 0; i < 2; i++) {
                    if (jogadorAtual->gousmas[i].ativa) {
                        gousmaAtiva = i;
                        break;
                    }
                }
                
                if (jogadorAtual->gousmas[gousmaAtiva].furia >= 2) {
                    printf("2. Dividir Gousma\n");
                    printf("\nEscolha sua ação (1-2): ");
                } else {
                    printf("\nEscolha sua ação (1): ");
                }
            } else {
                printf("\nEscolha sua ação (1): ");
            }
            
            scanf("%d", &acao);
            
            if (acao == 1) { // Atacar
                // Selecionar Gousma atacante
                printf("\nEscolha sua Gousma para atacar (1-2): ");
                scanf("%d", &gousmaOrigem);
                gousmaOrigem--; // Ajustar para índice 0-1
                
                if (gousmaOrigem < 0 || gousmaOrigem > 1 || !jogadorAtual->gousmas[gousmaOrigem].ativa) {
                    printf("\nGousma inválida! Tente novamente.\n");
                    pausar();
                    continue;
                }
                
                // Selecionar Gousma alvo
                printf("\nEscolha a Gousma inimiga para atacar (1-2): ");
                scanf("%d", &gousmaAlvo);
                gousmaAlvo--; // Ajustar para índice 0-1
                
                if (gousmaAlvo < 0 || gousmaAlvo > 1 || !jogadorOponente->gousmas[gousmaAlvo].ativa) {
                    printf("\nGousma inválida! Tente novamente.\n");
                    pausar();
                    continue;
                }
                
                // Realizar ataque
                int furiaAtacante = jogadorAtual->gousmas[gousmaOrigem].furia;
                
                printf("\n%s ataca com Gousma %d (Fúria %d)!\n", 
                       jogadorAtual->nome, gousmaOrigem + 1, furiaAtacante);
                
                jogadorOponente->gousmas[gousmaAlvo].furia += furiaAtacante;
                
                printf("A Gousma %d de %s agora tem Fúria %d!\n", 
                       gousmaAlvo + 1, jogadorOponente->nome, 
                       jogadorOponente->gousmas[gousmaAlvo].furia);
                
                // Verificar se a Gousma atacada se desintegrou
                if (jogadorOponente->gousmas[gousmaAlvo].furia > 5) {
                    printf("A Gousma %d de %s se desintegrou por excesso de fúria!\n", 
                           gousmaAlvo + 1, jogadorOponente->nome);
                    jogadorOponente->gousmas[gousmaAlvo].ativa = 0;
                }
            }
            else if (acao == 2 && contarGousmasAtivas(*jogadorAtual) == 1) {
                // Encontrar a Gousma ativa
                int gousmaAtiva = -1;
                for (i = 0; i < 2; i++) {
                    if (jogadorAtual->gousmas[i].ativa) {
                        gousmaAtiva = i;
                        break;
                    }
                }
                
                // Encontrar o slot vazio
                int gousmaVazia = (gousmaAtiva == 0) ? 1 : 0;
                
                if (jogadorAtual->gousmas[gousmaAtiva].furia >= 2) {
                    // Dividir a fúria
                    int furiaTotal = jogadorAtual->gousmas[gousmaAtiva].furia;
                    int furiaNova = furiaTotal / 2;
                    
                    jogadorAtual->gousmas[gousmaAtiva].furia = furiaTotal - furiaNova;
                    jogadorAtual->gousmas[gousmaVazia].furia = furiaNova;
                    jogadorAtual->gousmas[gousmaVazia].ativa = 1;
                    
                    printf("\n%s dividiu sua Gousma %d!\n", jogadorAtual->nome, gousmaAtiva + 1);
                    printf("Gousma %d: Fúria %d\n", gousmaAtiva + 1, jogadorAtual->gousmas[gousmaAtiva].furia);
                    printf("Gousma %d: Fúria %d\n", gousmaVazia + 1, jogadorAtual->gousmas[gousmaVazia].furia);
                } else {
                    printf("\nSua Gousma precisa ter pelo menos 2 de fúria para dividir!\n");
                }
            }
            else {
                printf("\nAção inválida! Tente novamente.\n");
                pausar();
                continue;
            }
            
            pausar();
            
            // Alternar jogador
            jogadorAtualNum = (jogadorAtualNum == 1) ? 2 : 1;
        }
        
        printf("\nDeseja jogar novamente? (1-Sim / 0-Não): ");
        scanf("%d", &jogarNovamente);
        
    } while (jogarNovamente == 1);
}
// Função para exibir e navegar no menu principal
int exibirMenu() {
    int opcao = 0;
    int tecla;
    int posicaoSeta = 2;
    int posicaoAnterior = 2;
    int indiceMenu = 2;
    
    limparTela();
    system("color 3f");
    
    printf("\n\n      1 - PERGUNTA E RESPOSTA\n");
    printf("      2 - COBRA NA CAIXA\n");
    printf("      3 - GOUSMAS WAR\n");
    printf("      4 - SAIR\n");
    
    // Exibir a seta inicial
    gotoxy(1, posicaoSeta);
    printf("-->");
    
    // Loop de navegação no menu
    do {
        gotoxy(10, 6); // Move o cursor para fora das opções
        
        if (kbhit()) {
            tecla = getch();
            
            // Seta para baixo
            if (tecla == 80 && indiceMenu < 5) {
                posicaoAnterior = posicaoSeta;
                posicaoSeta++;
                indiceMenu++;
            }
            // Seta para cima
            else if (tecla == 72 && indiceMenu > 2) {
                posicaoAnterior = posicaoSeta;
                posicaoSeta--;
                indiceMenu--;
            }
            
            // Atualizar posição da seta
            if (posicaoSeta != posicaoAnterior) {
                gotoxy(1, posicaoAnterior);
                printf("   ");
                gotoxy(1, posicaoSeta);
                printf("-->");
                posicaoAnterior = posicaoSeta;
            }
            
            // Enter pressionado
            if (tecla == 13) {
                opcao = indiceMenu - 1;
            }
        }
    } while (opcao == 0);
    
    return opcao;
}
// Função principal
int main() {
    int opcao;
    
    // Definir localização para suporte a caracteres especiais
    setlocale(LC_ALL, "Portuguese");
    
    // Inicializar gerador de números aleatórios
    srand((unsigned)time(NULL));
    
    do {
        opcao = exibirMenu();
        
        switch (opcao) {
            case 1:
                jogarPerguntasERespostas();
                break;
            case 2:
                jogarCobraNaCaixa();
                break;
            case 3:
                jogarGousmasWar();
                break;
            case 4:
                limparTela();
                printf("Obrigado por jogar! Até a próxima.\n");
                break;
            default:
                printf("Opção inválida!\n");
                pausar();
        }
    } while (opcao != 4);
    
    return 0;
}
