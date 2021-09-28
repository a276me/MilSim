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
void updateVariables();


Camera2D camera = { 0 };

void updateVariables(){
    if (IsKeyDown(KEY_RIGHT)) camera.target.x += 2;
    else if (IsKeyDown(KEY_LEFT)) camera.target.x -= 2;

    if (IsKeyDown(KEY_Q)) camera.rotation++;
    else if (IsKeyDown(KEY_E)) camera.rotation--;

        // Camera zoom controls
        camera.zoom += ((float)GetMouseWheelMove()*0.05f);

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
    DrawTextureV(natoTest, (Vector2){0-natoTest.width/2,0-natoTest.height/2}, (Color){ 255, 255, 255, 255 });
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







