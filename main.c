// #include <stdio.h>
// #include <stdlib.h>
// #include <SDL2/SDL.h>
// #include <string.h>
// #include "logicalPart.h"
// #include "fileReadStore.h"
// int main(int argc, char *argv[])
// {
//     int CELL = 0;
//     int length;
//     int width;
//     char option[5];
//     int **istate;
//     printf("select a pattern(1:Read from exiting file 2:Custom initial state by yourself):\n");
//     fflush(stdin);
//     fgets(option, 5, stdin);
//     if (strlen(option) != sizeof(option) - 1)
//         option[strlen(option) - 1] = '\0';
//     fflush(stdin);
//     while ((strcmp(option, "1") != 0) && (strcmp(option, "2") != 0))
//     {
//         printf("select a pattern(1:Read from exiting file 2:Custom initial state by yourself):\n");
//         fflush(stdin);
//         fgets(option, 5, stdin);
//         if (strlen(option) != sizeof(option) - 1)
//             option[strlen(option) - 1] = '\0';
//         fflush(stdin);
//     }
//     if (strcmp(option, "1") == 0)
//     {
//         FILE *file = fopen("initial.txt", "r");
//         if (file == NULL)
//         {
//             return -1;
//         }
//         else
//         {
//             findSize(file, &length, &width);
//             fclose(file);
//             file = fopen("initial.txt", "r");
//             istate = createArray(&length, &width);
//             readArray(file, istate, &length, &width);
//             fclose(file);
//             if (length < 10)
//             {
//                 CELL = 250 / length;
//             }
//             else
//             {
//                 CELL = 500 / length;
//             }
//         }
//         //初始化sdl
//         SDL_Init(SDL_INIT_EVERYTHING);
//         //创建窗口
//         SDL_Window *window = SDL_CreateWindow("Life Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, length * CELL, width * CELL, SDL_WINDOW_SHOWN);
//         //创建一个渲染器
//         SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

//         SDL_SetRenderDrawColor(renderer, 225, 255, 225, 225);

//         /* Clear the entire screen to our selected color. */
//         SDL_RenderClear(renderer);

//         SDL_SetRenderDrawColor(renderer, 126, 139, 146, 225);
//         // 创建一个矩形
//         for (int i = 0; i < width; i++)
//         {
//             for (int j = 0; j < length; j++)
//             {
//                 if (istate[i][j] == 1)
//                 {
//                     SDL_Rect rect1 = {j * CELL, i * CELL, CELL, CELL};
//                     //设置渲染颜色
//                     SDL_SetRenderDrawColor(renderer, 0, 0, 0, 1);
//                     //绘制线框矩形
//                     SDL_RenderFillRect(renderer, &rect1);
//                 }
//             }
//         }
//         SDL_SetRenderDrawColor(renderer, 126, 139, 146, 225);
//         for (int i = 0; i < width; i++)
//         {
//             //绘制直线
//             SDL_RenderDrawLine(renderer, 0, i * CELL, length * CELL, i * CELL);
//         }
//         for (int i = 0; i < length; i++)
//         {
//             //绘制直线
//             SDL_RenderDrawLine(renderer, i * CELL, 0, i * CELL, width * CELL);
//         }

//         // //设置渲染颜色
//         // SDL_SetRenderDrawColor(renderer, 0, 0, 225, 225);
//         // //绘制线框矩形
//         // SDL_RenderDrawRect(renderer, &rect1);

//         //更新屏幕
//         SDL_RenderPresent(renderer);
//         int quit = 0;    //退出
//         SDL_Event event; //监听退出活动

//         while (!quit)
//         { //主消息循环
//             SDL_WaitEvent(&event);
//             switch (event.type)
//             {
//             //用户从菜单要求退出程序
//             case SDL_QUIT:
//                 quit = 1;
//                 break;
//             case SDL_MOUSEBUTTONDOWN:
//                 if (SDL_BUTTON_LEFT == event.button.button)
//                 {

//                     NextState(&width, &length, istate);
//                     SDL_SetRenderDrawColor(renderer, 225, 255, 225, 225);

//                     /* Clear the entire screen to our selected color. */
//                     SDL_RenderClear(renderer);

//                     SDL_SetRenderDrawColor(renderer, 255, 255, 255, 225);
//                     // 创建一个矩形
//                     for (int i = 0; i < width; i++)
//                     {
//                         for (int j = 0; j < length; j++)
//                         {
//                             if (istate[i][j] == 1)
//                             {
//                                 SDL_Rect rect1 = {j * CELL, i * CELL, CELL, CELL};
//                                 //设置渲染颜色
//                                 SDL_SetRenderDrawColor(renderer, 0, 0, 0, 1);
//                                 //绘制线框矩形
//                                 SDL_RenderFillRect(renderer, &rect1);
//                             }
//                         }
//                     }
//                     SDL_SetRenderDrawColor(renderer, 126, 139, 146, 225);
//                     for (int i = 0; i < width; i++)
//                     {
//                         //绘制直线
//                         SDL_RenderDrawLine(renderer, 0, i * CELL, length * CELL, i * CELL);
//                     }
//                     for (int i = 0; i < length; i++)
//                     {
//                         //绘制直线
//                         SDL_RenderDrawLine(renderer, i * CELL, 0, i * CELL, width * CELL);
//                     }
//                     SDL_RenderPresent(renderer);
//                 }
//                 break;
//             case SDL_KEYDOWN:
//                 if (SDLK_s == event.key.keysym.sym)
//                 {
//                     file = fopen("initial.txt", "w");
//                     storeArray(file, istate, &length, &width);
//                     fclose(file);
//                     quit = 1;
//                 }
//                 break;
//             }
//         }
//         SDL_DestroyRenderer(renderer);
//         SDL_DestroyWindow(window);
//         SDL_Quit();

//         // file = fopen("initial.txt", "w");
//         // storeArray(file, istate, &length, &width);
//         // fclose(file);
//     }
//     if (strcmp(option, "2") == 0)
//     {
//         int x_set;
//         int y_set;
//         printf("input the length you want:");
//         scanf("%d", &length);
//         printf("input the width you want:");
//         scanf("%d", &width);
//         if (length < 10)
//         {
//             CELL = 250 / length;
//         }
//         else
//         {
//             CELL = 500 / length;
//         }
//         istate = createArray(&length, &width);

//         //初始化sdl
//         SDL_Init(SDL_INIT_EVERYTHING);
//         //创建窗口
//         SDL_Window *window = SDL_CreateWindow("Life Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, length * CELL, width * CELL, SDL_WINDOW_SHOWN);
//         //创建一个渲染器
//         SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

//         SDL_SetRenderDrawColor(renderer, 225, 255, 225, 225);

//         /* Clear the entire screen to our selected color. */
//         SDL_RenderClear(renderer);

//         SDL_SetRenderDrawColor(renderer, 126, 139, 146, 225);
//         // 创建一个矩形
//         for (int i = 0; i < width; i++)
//         {
//             for (int j = 0; j < length; j++)
//             {
//                 if (istate[i][j] == 1)
//                 {
//                     SDL_Rect rect1 = {j * CELL, i * CELL, CELL, CELL};
//                     //设置渲染颜色
//                     SDL_SetRenderDrawColor(renderer, 0, 0, 0, 1);
//                     //绘制线框矩形
//                     SDL_RenderFillRect(renderer, &rect1);
//                 }
//             }
//         }
//         SDL_SetRenderDrawColor(renderer, 126, 139, 146, 225);
//         for (int i = 0; i < width; i++)
//         {
//             //绘制直线
//             SDL_RenderDrawLine(renderer, 0, i * CELL, length * CELL, i * CELL);
//         }
//         for (int i = 0; i < length; i++)
//         {
//             //绘制直线
//             SDL_RenderDrawLine(renderer, i * CELL, 0, i * CELL, width * CELL);
//         }

//         // //设置渲染颜色
//         // SDL_SetRenderDrawColor(renderer, 0, 0, 225, 225);
//         // //绘制线框矩形
//         // SDL_RenderDrawRect(renderer, &rect1);

//         //更新屏幕
//         SDL_RenderPresent(renderer);
//         int quit = 0;    //退出
//         SDL_Event event; //监听退出活动

//         while (!quit)
//         { //主消息循环
//             SDL_WaitEvent(&event);
//             switch (event.type)
//             {
//             //用户从菜单要求退出程序
//             case SDL_QUIT:
//                 quit = 1;
//                 break;
//             case SDL_MOUSEBUTTONDOWN:
//                 if (SDL_BUTTON_LEFT == event.button.button)
//                 {
//                     x_set = event.button.x;
//                     y_set = event.button.y;
//                     istate[y_set / (int)CELL][x_set / (int)CELL] = 1;

//                     SDL_SetRenderDrawColor(renderer, 225, 255, 225, 225);

//                     /* Clear the entire screen to our selected color. */
//                     SDL_RenderClear(renderer);

//                     SDL_SetRenderDrawColor(renderer, 255, 255, 255, 225);
//                     // 创建一个矩形
//                     for (int i = 0; i < width; i++)
//                     {
//                         for (int j = 0; j < length; j++)
//                         {
//                             if (istate[i][j] == 1)
//                             {
//                                 SDL_Rect rect1 = {j * CELL, i * CELL, CELL, CELL};
//                                 //设置渲染颜色
//                                 SDL_SetRenderDrawColor(renderer, 0, 0, 0, 1);
//                                 //绘制线框矩形
//                                 SDL_RenderFillRect(renderer, &rect1);
//                             }
//                         }
//                     }
//                     SDL_SetRenderDrawColor(renderer, 126, 139, 146, 225);
//                     for (int i = 0; i < width; i++)
//                     {
//                         //绘制直线
//                         SDL_RenderDrawLine(renderer, 0, i * CELL, length * CELL, i * CELL);
//                     }
//                     for (int i = 0; i < length; i++)
//                     {
//                         //绘制直线
//                         SDL_RenderDrawLine(renderer, i * CELL, 0, i * CELL, width * CELL);
//                     }
//                     SDL_RenderPresent(renderer);
//                 }
//                 if (SDL_BUTTON_RIGHT == event.button.button)
//                 {
//                     NextState(&width, &length, istate);
//                     SDL_SetRenderDrawColor(renderer, 225, 255, 225, 225);

//                     /* Clear the entire screen to our selected color. */
//                     SDL_RenderClear(renderer);

//                     SDL_SetRenderDrawColor(renderer, 255, 255, 255, 225);
//                     // 创建一个矩形
//                     for (int i = 0; i < width; i++)
//                     {
//                         for (int j = 0; j < length; j++)
//                         {
//                             if (istate[i][j] == 1)
//                             {
//                                 SDL_Rect rect1 = {j * CELL, i * CELL, CELL, CELL};
//                                 //设置渲染颜色
//                                 SDL_SetRenderDrawColor(renderer, 0, 0, 0, 1);
//                                 //绘制线框矩形
//                                 SDL_RenderFillRect(renderer, &rect1);
//                             }
//                         }
//                     }
//                     SDL_SetRenderDrawColor(renderer, 126, 139, 146, 225);
//                     for (int i = 0; i < width; i++)
//                     {
//                         //绘制直线
//                         SDL_RenderDrawLine(renderer, 0, i * CELL, length * CELL, i * CELL);
//                     }
//                     for (int i = 0; i < length; i++)
//                     {
//                         //绘制直线
//                         SDL_RenderDrawLine(renderer, i * CELL, 0, i * CELL, width * CELL);
//                     }
//                     SDL_RenderPresent(renderer);
//                 }
//                 break;
//             case SDL_KEYDOWN:
//                 if (SDLK_s == event.key.keysym.sym)
//                 {
//                     FILE *file = fopen("initial.txt", "w");
//                     storeArray(file, istate, &length, &width);
//                     fclose(file);
//                     quit = 1;
//                 }
//                 break;
//             }
//         }
//         SDL_DestroyRenderer(renderer);
//         SDL_DestroyWindow(window);
//         SDL_Quit();
//     }
//     for (int i = 0; i < width; i++)
//     {
//         free(istate[i]);
//     }
//     free(istate);

//     return 0;
// }