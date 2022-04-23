#include <stdio.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "math_3d.h"//подключить вспомогательные структуры - вектор

GLuint VBO; //назначить GLuint в качестве глобальной переменной для хранения указателя на буфер вершин

static void RenderSceneCB()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glEnableVertexAttribArray(0);/*координаты вершин, используемые в буфере, рассматриваются как атрибут вершины с индексом 0 
    в фиксированной функции конвейера (которая становится активной, если не используется шейдер)*/
    glBindBuffer(GL_ARRAY_BUFFER, VBO);//мы обратно привязываем наш буфер, приготавливая его для отрисовки
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);/*Первый параметр указывает на индекс атрибута. 
    Второй параметр - это количество компонентов в атрибуте (3 для X, Y и Z). Третий параметр - тип данных для каждого компонента. 
    Следующий - хотим ли мы нормализовать атрибуты перед использованием в конвейере. 
    Пятый параметр (названный "шаг") является числом байтов между 2 экземплярами атрибута. 
    Поскольку мы храним только один атрибут (например, буфер хранит только координаты вершины) и данные плотно упакованы, мы передаем нулевое значение. 
    Последний параметр - полезен в случае с предыдущим примером.*/

    glDrawArrays(GL_POINTS, 0, 1);//вызов функцию для отрисовки

    glDisableVertexAttribArray(0);//Это признак хорошего тона отключать каждый атрибут вершины, как только отпадает необходимость в нем

    glutSwapBuffers();
}


static void InitializeGlutCallbacks()
{
    glutDisplayFunc(RenderSceneCB);
}

static void CreateVertexBuffer()
{
    Vector3f Vertices[1];//создать массив из одного экземпляра структуры Vector3f
    Vertices[0] = Vector3f(0.0f, 0.0f, 0.0f);//точка в середине экрана

    glGenBuffers(1, &VBO);//первый определяет количество объектов, которые вы хотите создать, и второй ссылка на массив типа GLuints для хранения указателя, по которому будут храниться данные
    glBindBuffer(GL_ARRAY_BUFFER, VBO);//Привязываем указатель к названию цели, Параметр GL_ARRAY_BUFFER означает, что буфер будет хранить массив вершин
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);/*принимает название цели 
    (такое же как и при привязывании), размер данных в байтах, адрес массива вершин, и флаг, 
    который обозначает использование паттернов для этих данных*/
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Karimova Regina Tutorial 02");

    InitializeGlutCallbacks();

    // Must be done after glut is initialized!
    GLenum res = glewInit();
    if (res != GLEW_OK) {
        fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
        return 1;
    }//проверка на ошибки

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    CreateVertexBuffer();

    glutMainLoop();

    return 0;
}