#include <iostream>
#include <Box2d/Box2d.h>

int main() {

    //Definimos la gravedad
    b2Vec2 gravity(0.0f, -1.62f);
    b2World world(gravity);

    //Definimos la posicion del suelo
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, -10.0f);

    //Creamos el suelo en el mundo
    b2Body* groundBody = world.CreateBody(&groundBodyDef);

    //Definimos la forma
    b2PolygonShape groundBox;
    groundBox.SetAsBox(1.0f, 1.0f);

    groundBody->CreateFixture(&groundBox, 0.0f);

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(0.0f, 15.0f);
    b2Body* body = world.CreateBody(&bodyDef);

    //Definimos la forma
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(1.0f, 1.0f);

    //Definimos densidad y friccion
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 15600.0f;
    fixtureDef.friction = 0.0f;

    //Asignamos la densidad y la friccion
    body->CreateFixture(&fixtureDef);

    //Definimos la frecuencia en el muestreo
    float timeStep = 1.0f;

    //Definimos los ciclos de muestreo
    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    //Proyeccion del mundo
    for (int32 i = 0; i < 60; ++i)
    {
        world.Step(timeStep, velocityIterations, positionIterations);
        b2Vec2 position = body->GetPosition();
        float angle = body->GetAngle();
        printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
    }

}
