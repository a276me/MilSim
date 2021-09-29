#pragma once


#include "raylib.h"
#include "main.hpp"
#include "Division.hpp"

const int SCREEN_WIDTH = 1280*1.5;
const int SCREEN_HEIGHT = 960*1.2;

Texture2D natoTest;
Texture2D natoInf;
Texture2D natoArmor;
Texture2D natoMechInf;
Texture2D hostileInf;
Texture2D hostileArmor;
Texture2D hostileMechInf;

void initRL();
void endRL();
void drawUI();
void drawDivision();
void drawCamera();
void drawScreen();
void loadResources();
void updateVariables();


Camera2D camera = { 0 };

void updateVariables(){

    int t = 1;

    if(IsKeyDown(KEY_LEFT_SHIFT)) t = 3;

    int s = 10;

    if (IsKeyDown(KEY_A)) camera.target.x -= t*s;
    else if (IsKeyDown(KEY_D)) camera.target.x += t*s;

    if (IsKeyDown(KEY_W)) camera.target.y -= t*s;
    else if (IsKeyDown(KEY_S)) camera.target.y += t*s;

        // Camera zoom controls
        camera.zoom += ((float)GetMouseWheelMove()*t*0.02f);

        if (camera.zoom > 3.f) camera.zoom = 3.f;
        else if (camera.zoom < .01f) camera.zoom = .01f;

        // Camera reset (zoom and rotation)
        if (IsKeyPressed(KEY_R))
        {
            camera.zoom = 1.0f;
            camera.rotation = 0.0f;
            camera.target = (Vector2){0,0};
        }
}

void loadResources(){
    natoTest = LoadTexture("nato.png");
    natoInf = LoadTexture("./assets/NATO/friendly_infantry.png");
    natoMechInf = LoadTexture("./assets/NATO/friendly_mech_infantry.png");
    natoArmor = LoadTexture("./assets/NATO/friendly_armor.png");
    hostileInf = LoadTexture("./assets/HOSTILE/hostile_inf.png");
    hostileMechInf = LoadTexture("./assets/HOSTILE/hostile_mech_inf.png");
    hostileArmor = LoadTexture("./assets/HOSTILE/hostile_armor.png");
}

void initRL(){
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "raylib [core] example - basic window");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

    loadResources();

    camera.target = (Vector2){ 0,0 };
    camera.offset = (Vector2){ SCREEN_WIDTH/2.0f, SCREEN_HEIGHT/2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    MaximizeWindow();

}

void endRL(){
    CloseWindow(); 
}


void drawUI(){
    ClearBackground((Color){ 245, 245, 245, 255 });
    DrawFPS(10,10);

}

void drawDivision(){

    float s = 0.7f;
    float ss = 100.f;

    for(int i=0; i<divisions.size(); i++){
        DrawCircleV((Vector2){divisions[i].position.x*ss, -divisions[i].position.y*ss}, ss*divisions[i].getBD()/2.f, (Color){ 100, 100, 100, 100 });
        if(divisions[i].moving) DrawLineEx((Vector2){divisions[i].position.x*ss,-divisions[i].position.y*ss}, (Vector2){divisions[i].getTarget().x*ss,  -divisions[i].getTarget().y*ss}, 20, (Color){0,0,0,255});
    } 

    for(int i=0; i<divisions.size(); i++){
        if(divisions[i].team == 0){
            if(divisions[i].getType() == INFANTRY_DIV){
                DrawTextureEx(natoInf, (Vector2){ss*divisions[i].getPos().x-(natoInf.width/2)*s,ss*-divisions[i].getPos().y-(natoInf.height/2)*s}, 0, s,(Color){ 255, 255, 255, 255 });
            } else if(divisions[i].getType() == ARMORED_DIV){
                DrawTextureEx(natoArmor, (Vector2){ss*divisions[i].getPos().x-(natoArmor.width/2)*s,ss*-divisions[i].getPos().y-(natoArmor.height/2)*s}, 0, s,(Color){ 255, 255, 255, 255 });
            } else if(divisions[i].getType() == MECH_INFANTRY_DIV){
                DrawTextureEx(natoMechInf, (Vector2){ss*divisions[i].getPos().x-(natoMechInf.width/2)*s,ss*-divisions[i].getPos().y-(natoMechInf.height/2)*s}, 0, s,(Color){ 255, 255, 255, 255 });
            }
            
        }else if(divisions[i].team == 1){
            if(divisions[i].getType() == INFANTRY_DIV){
                DrawTextureEx(hostileInf, (Vector2){ss*divisions[i].getPos().x-(hostileInf.width/2)*s,ss*-divisions[i].getPos().y-(hostileInf.height/2)*s}, 0, s,(Color){ 255, 255, 255, 255 });
            } else if(divisions[i].getType() == ARMORED_DIV){
                DrawTextureEx(hostileArmor, (Vector2){ss*divisions[i].getPos().x-(hostileArmor.width/2)*s,ss*-divisions[i].getPos().y-(hostileArmor.height/2)*s}, 0, s,(Color){ 255, 255, 255, 255 });
            } else if(divisions[i].getType() == MECH_INFANTRY_DIV){
                DrawTextureEx(hostileMechInf, (Vector2){ss*divisions[i].getPos().x-(hostileMechInf.width/2)*s,ss*-divisions[i].getPos().y-(hostileMechInf.height/2)*s}, 0, s,(Color){ 255, 255, 255, 255 });
            }
        }

        DrawText(divisions[i].getName().c_str(),ss*divisions[i].getPos().x-(MeasureText(divisions[i].getName().c_str(), 200)/2), ss*-divisions[i].getPos().y-(hostileInf.height/2)*s-220,200,(Color){ 0, 0, 0, 255 });
        DrawText(std::to_string((int)divisions[i].getOrg()).c_str(),ss*divisions[i].getPos().x+(natoInf.width/2)*s+20, ss*-divisions[i].getPos().y-210,200,(Color){ 0, 0, 0, 255 });
        DrawText(std::to_string((int)divisions[i].getStrength()).c_str(),ss*divisions[i].getPos().x+(natoInf.width/2)*s+20, ss*-divisions[i].getPos().y,200,(Color){ 0, 0, 0, 255 });
        DrawText(std::to_string((int)divisions[i].getBV()).c_str(),ss*divisions[i].getPos().x-(natoInf.width/2)*s-MeasureText(std::to_string((int)divisions[i].getBV()).c_str(),200)-30, ss*-divisions[i].getPos().y-200,200,(Color){ 0, 0, 0, 255 });
        DrawText(std::to_string((int)divisions[i].getDV()).c_str(),ss*divisions[i].getPos().x-(natoInf.width/2)*s-MeasureText(std::to_string((int)divisions[i].getDV()).c_str(),200)-30, ss*-divisions[i].getPos().y+20,200,(Color){ 0, 0, 0, 255 });


    }
}

void drawCamera(){

    updateVariables();

    BeginMode2D(camera);

    drawDivision();

    EndMode2D();
}


void drawScreen(){
    BeginDrawing();

            drawUI();
            drawCamera();

    EndDrawing();
}







