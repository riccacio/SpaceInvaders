#include "../headers/PowerUp.h"

PowerUp::PowerUp(Vector2f pos, Type type): type(type), change(true){
    for (int i = 0; i<9; i++)
        textures.emplace_back();

    int i=0;
    for(int j = 0; j<4; j++){
        for(int k = 0; k<2; k++){
            textures[i].loadFromFile("sprite/powerup" + std::to_string(j) + std::to_string(k) + ".png");
            i++;
        }
    }

    switch(type){
        case Type::SHIELD:
            sprite.setTexture(textures[0]);
            break;
        case Type::THREE_BUL:
            sprite.setTexture(textures[2]);
            break;
        case Type::FAST:
            sprite.setTexture(textures[4]);
            break;
        case Type::CHANGE_MOV:
            sprite.setTexture(textures[6]);
            break;
        default:
            break;
    }
    sprite.setScale(SPRITE_SCALE, SPRITE_SCALE);
    sprite.setPosition(pos.x-sprite.getGlobalBounds().width/2.f, pos.y);
}

//functions
void PowerUp::draw(RenderTarget &target) {
    switch(type){
        case Type::SHIELD:
            sprite.setTexture((change)?textures[0]:textures[1]);
            break;
        case Type::THREE_BUL:
            sprite.setTexture((change)?textures[2]:textures[3]);
            break;
        case Type::FAST:
            sprite.setTexture((change)?textures[4]:textures[5]);
            break;
        case Type::CHANGE_MOV:
            sprite.setTexture((change)?textures[6]:textures[7]);
            break;
        default:
            break;
    }
    target.draw(sprite);
}

void PowerUp::update(){
    sprite.move(0.f, POWERUP_SPEED);
}

void PowerUp::changeSprite() {
    change = !change;
}

//getter
Vector2f PowerUp::getPosition() {
    return sprite.getPosition();
}

IntRect PowerUp::getHitBox() const{
    return IntRect (sprite.getPosition().x, sprite.getPosition().y, sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);
}

Sprite PowerUp::getSprite() {
    return sprite;
}