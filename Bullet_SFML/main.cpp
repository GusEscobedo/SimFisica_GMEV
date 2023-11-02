#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include <iostream>

class Bullet {
public:
    Bullet(float x, float y, float initialSpeed, float angle) {
        this-> x = x;
        this-> y = y;
        this-> initialSpeed = initialSpeed;
        this-> angle = angle;
        this-> timeS = 0.0f;
    }

    void Update() {
        this-> x += this-> initialSpeed * cos(this-> angle) * this-> timeS;
        this-> y -= this-> initialSpeed * sin(this-> angle) * this-> timeS;
        this-> timeS += 0.01f;
    }

    bool impact() {
        return this-> y <= 0.0f;
    }

    float x, y;
    float initialSpeed;
    float angle;
    float timeS;
};

int main() {
    // Crear ventana
    sf::RenderWindow window(sf::VideoMode(1024, 640), "Bullet");

    // Crear bala
    Bullet bullet(100.0f, 100.0f, 50.0f, 10.0f);

    // Bucle
    while (window.isOpen()) {

        sf::Event state;
        while (window.pollEvent(state)) {
            if (state.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Actualizar bala
        bullet.Update();

        // Dibujar bala
        sf::CircleShape bulletShape(10.0f);
        bulletShape.setPosition(bullet.x, bullet.y);
        window.draw(bulletShape);

        // Buscar el impacto
        if (bullet.impact()) {
            std::cout << "Temporizador: " << bullet.timeS << " s" << std::endl;
        }

        // ACtualizar ventana
        window.display();
    }

    return 0;
}