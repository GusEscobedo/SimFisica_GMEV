#include <iostream>
#include <Box2D/Box2D.h>

int main()
{
    // Configuración mundo - Box2d
    b2Vec2 gravity(0.0f, -9.8f); // Gravedad en -y
    b2World world(gravity);

    // Configuración bala - Box2d
    b2BodyDef bodyBulletDef;
    bodyBulletDef.type = b2_dynamicBody; // Hacemos nuestra bala un cuerpo dinámico
    b2Body* bodyBullet = world.CreateBody(&bodyBulletDef);

    b2CircleShape shapeBullet;
    shapeBullet.m_radius = 1.0f; // Radio de la bala

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &shapeBullet;
    fixtureDef.friction = 0.3f; // Fricción

    bodyBullet->CreateFixture(&fixtureDef);

    float initialAngle = 10.0f;
    float initialSpeed = 5.0f;

    float initialSpeedX = initialSpeed * cos(initialAngle);
    float initialSpeedY = initialSpeed * sin(initialAngle);

    b2Vec2 VinitalSpeed(initialSpeedX, initialSpeedY);

    bodyBullet->SetLinearVelocity(VinitalSpeed);

    // Simulación - Box2d

    float timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    for(int i = 0; i < 300; i ++)
    {
        world.Step(timeStep, velocityIterations, positionIterations); // Correr a 60 FPS

        float PositionY = bodyBullet->GetPosition().y;
        //std::cout<<PositionY<<", ";

        if (PositionY <= 0.0f) // Revisar si la bala a tocado el suelo
        {
            std::cout << "Temporizador: " << timeStep << " s\n";
            break;
        }

    }

    return 0;
}