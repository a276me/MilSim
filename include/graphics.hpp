#pragma once


#include "raylib.h"

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 960;

Texture2D natoTest;

void initRL();
void endRL();
void drawUI();
void drawDivision();
void drawCamera();
void drawScreen();
void loadResources();


Camera2D camera = { 0 };

void loadResources(){
    natoTest = LoadTexture("nato.png");
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
    ClearBackground(RAYWHITE);

}

void drawDivision(){
    DrawTextureV(natoTest, {0-natoTest.width/2,0-natoTest.height/2}, WHITE);
}

void drawCamera(){
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







