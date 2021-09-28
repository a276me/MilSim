#pragma once


#include "raylib.h"
#include "main.hpp"
#include "Division.hpp"

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 960;

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

    if (IsKeyDown(KEY_LEFT)) camera.target.x -= t*2;
    else if (IsKeyDown(KEY_RIGHT)) camera.target.x += t*2;

    if (IsKeyDown(KEY_UP)) camera.target.y -= t*2;
    else if (IsKeyDown(KEY_DOWN)) camera.target.y += t*2;

        // Camera zoom controls
        camera.zoom += ((float)GetMouseWheelMove()*t*0.02f);

        if (camera.zoom > 1.f) camera.zoom = 1.f;
        else if (camera.zoom < .01f) camera.zoom = .01f;

        // Camera reset (zoom and rotation)
        if (IsKeyPressed(KEY_R))
        {
            camera.zoom = 1.0f;
            camera.rotation = 0.0f;
        }
}

void loadResources(){
    natoTest = LoadTexture("nato.png");
    natoInf = LoadTexture("./assets/NATO/friendly_infantry.png");
    natoMechInf = LoadTexture("./assets/NATO/friendly_mech_inf.png");
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

}

void endRL(){
    CloseWindow(); 
}


void drawUI(){
    ClearBackground((Color){ 245, 245, 245, 255 });

}

void drawDivision(){

    for(int i=0; i<divisions.size(); i++){
        if(divisions[i].team == 0){

            if(divisions[i].getType() == INFANTRY_DIV){
                DrawTextureV(natoInf, (Vector2){divisions[i].getPos().x-natoInf.width/2,-divisions[i].getPos().y-natoInf.height/2}, (Color){ 255, 255, 255, 255 });
            } else if(divisions[i].getType() == ARMORED_DIV){
                DrawTextureV(natoArmor, (Vector2){divisions[i].getPos().x-natoArmor.width/2,-divisions[i].getPos().y-natoArmor.height/2}, (Color){ 255, 255, 255, 255 });
            } else if(divisions[i].getType() == MECH_INFANTRY_DIV){
                DrawTextureV(natoMechInf, (Vector2){divisions[i].getPos().x-natoMechInf.width/2,-divisions[i].getPos().y-natoMechInf.height/2}, (Color){ 255, 255, 255, 255 });
            }
            
        }else if(divisions[i].team == 1){
            if(divisions[i].getType() == INFANTRY_DIV){
                DrawTextureV(hostileInf, (Vector2){divisions[i].getPos().x-hostileInf.width/2,-divisions[i].getPos().y-hostileInf.height/2}, (Color){ 255, 255, 255, 255 });
            } else if(divisions[i].getType() == ARMORED_DIV){
                DrawTextureV(hostileArmor, (Vector2){divisions[i].getPos().x-hostileArmor.width/2,-divisions[i].getPos().y-hostileArmor.height/2}, (Color){ 255, 255, 255, 255 });
            } else if(divisions[i].getType() == MECH_INFANTRY_DIV){
                DrawTextureV(hostileMechInf, (Vector2){divisions[i].getPos().x-hostileMechInf.width/2,-divisions[i].getPos().y-hostileMechInf.height/2}, (Color){ 255, 255, 255, 255 });
            }
        }
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







