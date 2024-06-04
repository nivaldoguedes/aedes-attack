#ifndef SCREEN_H
#define SCREEN_H

extern int larguraJanela, alturaJanela, telaAtual, telaOver;
extern const GLuint *textureID;
extern float largura, altura, retXinic, retYinic, retXcont, retYcont, retXexit, retYexit;

/* Estados das Telas do Jogo */
#define HOME_SCREEN 0
#define GAME_SCREEN 1
#define GAME_PAUSE_SCREEN 2
#define END_GAME_SCREEN 3
#define LOADING_SCREEN 4

void changeScreen(int screenId);

void loadingScreen();

void telaInicial();

void segundaTela();

void telaPause();

void telaFim();

#endif
