#include "iostream"
#include <Box2d/box2d.h>

int main() {

    //Definimos la variable para la forma del triangulo
    b2PolygonShape triangleShape;
    //Definimos un arreglo de 3 vertices
    b2Vec2 vertexTriangle[3];
    //Asignamos los posiciones de cada vertice
    vertexTriangle[0].Set(0.0f, 0.0f);
    vertexTriangle[1].Set(1.0f, 0.0f);
    vertexTriangle[2].Set(0.0f, 1.0f);
    //Creamos la forma del triangulo usando los vertices anteriores
    triangleShape.Set(vertexTriangle, 3);

    //Definimos la variable para la forma del cuadrado
    b2PolygonShape squareShape;
    //Definimos un arreglo de 4 vertices
    b2Vec2 vertexSquare[4];
    //Asignamos las posiciones de cada vertice
    vertexSquare[0].Set(0.0f, 0.0f);
    vertexSquare[1].Set(1.0f, 0.0f);
    vertexSquare[2].Set(1.0f, 1.0f);
    vertexSquare[3].Set(0.0f, 1.0f);
    //Creamos la forma del cuadrado usando los vertices anterioes
    squareShape.Set(vertexSquare, 4);

    //Definimos la variable para la forma del pentagono
    b2PolygonShape pentagonShape;
    //Definimos un arreglo de 5 vertices
    b2Vec2 vertices[5];
    //Ciclo para asignar las posciones de cada vertice
    for (int i = 0; i < 5; ++i) {
        float angle = i * (2 * b2_pi / 5);
        vertices[i].Set(cos(angle), sin(angle));
    }
    //Creamos la forma del pentagono usando los vertices anteriores
    pentagonShape.Set(vertices, 5);


    //Definimos la variable para la forma del hexagono
    b2PolygonShape hexagonShape;
    //Definimos un arreglo de 6 vertices
    b2Vec2 verticesh[6];
    //Ciclo para asignar las posciones de cada vertice
    for (int i = 0; i < 6; ++i) {
        float angle = i * (2 * b2_pi / 6);
        verticesh[i].Set(cos(angle), sin(angle));
    }
    //Creamos la forma del hexagono usando los vertices anteriores
    hexagonShape.Set(verticesh, 6);

    //Definimos la variable para la forma del octagono
    b2PolygonShape octagonShape;
    //Definimos un arreglo de 8 vertices
    b2Vec2 verticesO[8];
    //Ciclo para asignar las posiciones de cada vertice
    for (int i = 0; i < 8; ++i) {
        float angle = i * (2 * b2_pi / 8);
        verticesO[i].Set(cos(angle), sin(angle));
    }
    //Creamos la forma del octagono usando los vertices anteriores
    octagonShape.Set(verticesO, 8);

}