#include "../headers/Bullet.h"

Bullet::Bullet(std::string path, Vector2f(pos)){
    textureS.loadFromFile(path);
    sprite.setTexture(textureS);
    sprite.setScale(1,4);
    sprite.setPosition(pos);
}
//TODO da guardare se è necessario
Bullet::Bullet(std::string path1, std::string path2, Vector2f(pos)){
    textureA1.loadFromFile(path1);
    textureA2.loadFromFile(path2);
    sprite.setTexture(textureA1);
    sprite.setScale(1,4);
    sprite.setPosition(pos);
}

void Bullet::draw(RenderTarget &target) {
    target.draw(sprite);
}

void Bullet::update(int direction) {
    sprite.move(0.0f, BULLET_SPEED * direction);
}

Vector2f Bullet::getPosition() {
    return sprite.getPosition();
}



