#include <GL/freeglut.h>


static void RenderSceneCB()
{
    glClear(GL_COLOR_BUFFER_BIT);//чистка буфера кадра
    glutSwapBuffers();//менять фоновый буфер и буфер кадра местами
}

static void InitializeGlutCallbacks()
{
    glutDisplayFunc(RenderSceneCB);//взаимодействие с оконной системой и отрисовывается 1 кадр
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);//инициализация GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);//GLUT_DOUBLE включает двойную буферизацию
    glutInitWindowSize(1024, 768);//размер окна
    glutInitWindowPosition(100, 100);//позиция окна
    glutCreateWindow("Karimova Regina Tutorial 01");//название окна

    InitializeGlutCallbacks();

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);//устанавливает цвет, который будет использован во время очистки буфера кадра

    glutMainLoop();//В этом цикле он ждёт событий от оконной системы, в данной случае вызывает только функцию отображения на экран

    return 0;
}
