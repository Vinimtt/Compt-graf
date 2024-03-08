#include <GLFW/glfw3.h>
#include <stdio.h>
#include <math.h>


/*exibe um quadrado 2D */
void display()
{
    //limpa o buffer de pixels 
    //glClear(GL_COLOR_BUFFER_BIT);
    //desenha o quadrado
    glBegin(GL_LINE_LOOP);
    glVertex2f(100, 150);
    glVertex2f(100, 100);
    glVertex2f(150, 100);
    glVertex2f(150, 150);
    glEnd();
    //inicia o processo de desenho através dos dados bufferizados
    glFlush();
}
void pm(int x1, int y1, int x2, int y2){
int dx, dy, incE, incNE, d, x, y;
int valor;
    dx = x2 - x1;
    dy = y2 - y1;
    d = 2 * dy - dx;
    incE = 2 * dy;
    incNE = 2 * (dy - dx);
    x = x1; y = y1;
    glBegin(GL_POINTS);
    glVertex2d(x, y);
    glEnd();
    while (x < x2) {
        if (d <= 0) {
            d = d + incE;
            x = x + 1;
        }
        else {
            d = d + incNE;
            x = x + 1; y = y + 1;
        }
    }
    glBegin(GL_POINTS);
    glVertex2d(x, y);
    glEnd();


    }


static void dda(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;

    int passos = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xinc = (float)dx / passos;
    float yinc = (float)dy / passos;

    float x = (float)x1;
    float y = (float)y1;

    for (int i = 0; i <= passos; i++) {
        glBegin(GL_POINTS);
        glVertex2d(round(x), round(y));
        glEnd();
        x = x + xinc;
        y = y + yinc;
    }
}


static void teclado(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}


int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Reta: algoritmo DDA", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwSetWindowPos(window, 50, 100);

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0.0f, 640, 0, 480, 0.0f, 1.0f);

        dda(60, 90, 110, 120);
        dda(60, 90, 15, 120);
        dda(15, 120, 60, 160);
        dda(60, 160, 110, 120);
        display();
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();

        glfwSetKeyCallback(window, teclado);

    }

    glfwTerminate();
    return 0;
}