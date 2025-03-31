# Jogo-giroto-atividade
Trabalho criado apartir de uma atividade avaliativa. Com o Objetivo de: O projeto busca desenvolver as seguintes competências nos alunos:
● Resolução de problemas;
● Raciocínio lógico e algorítmico;
● Trabalho em equipe e desenvolvimento de competências interpessoais;
● Aplicação prática dos conceitos fundamentais de algoritmos.
trabalho feito em dupla.

integrantes: Guilherme Jensen e Lucas Augusto


aqui irei mostrar alguns passos do nosso jogo. Como iniciamos esse projeto e algumas duvidas que tivemos no caminho.
de inicio, o codigo foi facil afinal apenas precisei inciar declarando algumas variaveis e usando alguns codigos para funçoes que no futuro vieram a ser mais complicadas pois ainda nao tinha ciencia desses codigos e suas respectivas funções.
sendo assim busquei na internet e fui atras de alguns conhecimentos que antes nao tinha.
pesquisando em sites e tambem com a ajuda de algumas inteligencias artificais, me deparei com alguns codigos que deixaram meu jogo um pouco mais interativo com o usuario.
abaixo deixarei algumas duvidas que tive e que pedi para o chatGPT me explicar e me ajudar a aplicar algumas dessas funçoes no codigo.

A unica inteligencia artificial usada foi o Code Manager Pro
usamos o code manager pro para retirada de duvidas e em algumas partes para deixar o jogo mais interativo e com melhor aparencia.

Conversa com a IA.
2. Funções de Utilidade
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
Estas funções de utilidade são pequenas mas importantes para a interface do usuário:

gotoxy: Posiciona o cursor em uma coordenada específica na tela do console. É essencial para a navegação no menu e para criar interfaces mais sofisticadas. Usa a API do Windows para controlar a posição do cursor.

limparTela: Simplifica a chamada a system("cls") e melhora a legibilidade. Este tipo de função também facilita a futura portabilidade, pois se o código precisar ser adaptado para outro sistema operacional, só será necessário mudar esta função.

pausar: Padroniza a forma de esperar o usuário pressionar Enter antes de continuar. Inclui fflush(stdin) para limpar o buffer de entrada, evitando problemas com entradas anteriores.
