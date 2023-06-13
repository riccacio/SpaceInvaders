#include "../headers/BulletPower.h"

BulletPower::BulletPower():change(true){
    for (int i = 0; i<9; i++)
        textures.emplace_back();
}

//functions
void BulletPower::draw(RenderTarget &target){}

 void BulletPower::changeSprite(){
     change = !change;
}

//getter
 Vector2f BulletPower::getPosition(){
    return sprite.getPosition();
}
 IntRect BulletPower::getHitBox() const{
     return IntRect (sprite.getPosition().x, sprite.getPosition().y, sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);
}
 Sprite BulletPower::getSprite(){
     return sprite;
}


