#include <GL/glut.h>
#include <screen.h>
#include <keyboard.h>
#include <position.h>

int isHover(GLfloat xMouse, GLfloat yMouse, GLfloat xObj, GLfloat yObj, GLfloat wObj, GLfloat hObj)
{
    return (xMouse > xObj && xMouse < xObj + wObj && yMouse > yObj && yMouse < yObj + hObj);
}

void mouse(int button, int estado, int x, int y)
{
    int alturaMax = glutGet(GLUT_WINDOW_HEIGHT); // Armazena a altura máxima da tela

    // Converte a coordenada y do mouse para o sistema de coordenadas do OpenGL
    int yInvertido = alturaMax - y;

    // Desenha o primeiro retângulo
    if (button == GLUT_LEFT_BUTTON && estado == GLUT_DOWN && !telaAtual)
    {
        if (isHover(x, y, xButtonStart, yButtonStart, wButtonStart, hButtonStart)) // Verifica se "iniciar" foi selecionado
        {
            glutSetCursor(GLUT_CURSOR_INHERIT);
            glutDisplayFunc(segundaTela); // Troca para a tela de jogo
        }
    }

    if (button == GLUT_LEFT_BUTTON && estado == GLUT_DOWN && pause)
    {
        if (x >= retXcont && x <= (retXcont + largura) && yInvertido >= retYcont && yInvertido <= (retYcont + altura)) // Verifica se "continuar" foi selecionado
        {
            glutDisplayFunc(segundaTela); // Troca para a tela de jogo
        }
    }

    if (button == GLUT_LEFT_BUTTON && estado == GLUT_DOWN && telaOver)
    {
        if (x >= retXcont && x <= (retXcont + largura) && yInvertido >= retYcont && yInvertido <= (retYcont + altura)) // Verifica se "continuar" foi selecionado
        {
            glutDisplayFunc(telaInicial); // Troca para a tela de jogo
        }
    }

    if (button == GLUT_LEFT_BUTTON && estado == GLUT_DOWN && (pause || telaOver))
    {
        if (x >= retXexit && x <= (retXexit + largura) && yInvertido >= retYexit && yInvertido <= (retYexit + altura)) // Verifica se "sair" foi selecionado tanto na tela de pause, como na tela fim
        {
            exit(0); // Sai do jogo
        }
    }

    glutPostRedisplay();
}

void passiveMouse(int x, int y)
{
    // Converte a coordenada Y para corresponder ao sistema de coordenadas do GLUT
    y = glutGet(GLUT_WINDOW_HEIGHT) - y;

    // Verifica se o mouse está sobre o botão
    if (isHover(x, y, xButtonStart, yButtonStart, wButtonStart, hButtonStart) && (telaAtual == HOME_SCREEN))
    {
        // Muda o cursor para quando estiver sobre o botão
        glutSetCursor(GLUT_CURSOR_INFO);
    }
    else
    {
        // Caso contrário, volta para o cursor padrão
        glutSetCursor(GLUT_CURSOR_INHERIT);
    }
}