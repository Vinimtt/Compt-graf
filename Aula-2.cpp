#include <GLFW/glfw3.h>
#include <math.h>

void display() {
    
    
    // Limpa o buffer de pixels
    glClear(GL_COLOR_BUFFER_BIT);

    // Desenha a figura (Hexagono atual)
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.2, 0.3);
    glVertex2f(0, 0.4);
    glVertex2f(0.2,0.3);
    glVertex2f(0.3, 0);
    glVertex2f(0.2,-0.3);
    glVertex2f(0, -0.4);
    glVertex2f(-0.2, -0.3);
    glVertex2f(-0.3, 0);

    glEnd();

    // Inicia o processo de desenho através dos dados bufferizados
    glFlush();
}
//Criar uma reta
void dda(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;

    int passos = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xinc = dx / passos;
    float yinc = dy / passos;

    float x = x1;
    float y = y1;

    for (int i = 0; i <= passos; i++) {
        glBegin(GL_POINTS);
        glVertex2d(round(x) / 639, round(y) / 479);
        glEnd();
        x = x + xinc;
        y = y + yinc;
    }
}
void vertice() {

    // Inicia o processo de desenho através dos dados bufferizados
    glFlush();
}
int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
       
        //especificações da linha
        glClear(GL_COLOR_BUFFER_BIT);
        dda(0,0,5,5);
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }
    
    glfwTerminate();
    return 0;
}
