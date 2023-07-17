#include "../headers/Shield.h"


Shield::Shield(Type type, Vector2f pos) : type(type) , hitted(false){
    for (int j = 0; j<10; j++)
        textures.emplace_back();

    /*
     * 0 shield
     * 1 shield destroyed
     */
    int i=0;
    for(int j = 0; j<5; j++){
        for(int k = 0; k<2; k++){
            textures[i].loadFromFile("sprite/shield_" + std::to_string(j) + "_" + std::to_string(k) + ".png");
            i++;
        }
    }
    switch(type){
        case Type::LeftUp:
            sprite.setTexture(textures[0]);
            break;
        case Type::LeftBot:
            sprite.setTexture(textures[6]);
            break;
        case Type::RightUp:
            sprite.setTexture(textures[4]);
            break;
        case Type::Unique:
            sprite.setTexture(textures[2]);
            break;
        case Type::RightBot:
            sprite.setTexture(textures[8]);
            break;
        default:
            break;
    }
    sprite.setScale(5, 5);
    sprite.setPosition(pos);
}

void Shield::draw(RenderTarget &target) {
    if(hitted){
        switch(type){
            case Type::LeftUp:
                sprite.setTexture(textures[1]);
                break;
            case Type::LeftBot:
                sprite.setTexture(textures[7]);
                break;
            case Type::RightUp:
                sprite.setTexture(textures[5]);
                break;
            case Type::Unique:
                sprite.setTexture(textures[3]);
                break;
            case Type::RightBot:
                sprite.setTexture(textures[9]);
                break;
            default:
                break;
        }
    }
    target.draw(sprite);
}

void Shield::update() {

}

bool Shield::checkCollision(FloatRect hitBox) {
    if(getHitBox().intersects(hitBox))
        return true;
    else
        return false;
}

Sprite &Shield::getSprite() {
    return sprite;
}

FloatRect Shield::getHitBox() {
    return FloatRect (sprite.getPosition().x, sprite.getPosition().y, sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);
}

bool Shield::isHitted() const {
    return hitted;
}

void Shield::setHitted(bool hitted) {
    Shield::hitted = hitted;
}

bool Shield::isDeletable() const {
    return deletable;
}

void Shield::setDeletable(bool deletable) {
    Shield::deletable = deletable;
}


