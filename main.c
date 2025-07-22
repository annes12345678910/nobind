#include "raylib.h"
#include "ui.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
//#include <unistd.h>
int createFolder(const char *folderName) {
    int status = mkdir(folderName, 0755);
    if (status == 0) {
        printf("Folder created: %s\n", folderName);
        return 0;
    } else {
        perror("mkdir failed");
        return -1;
    }
}
int createFileWithText(const char *filePath, const char *text) {
    FILE *fp = fopen(filePath, "w");
    if (!fp) {
        perror("File open failed");
        return -1;
    }
    fprintf(fp, "%s", text);
    fclose(fp);
    printf("File created: %s\n", filePath);
    return 0;
}
int main() {
    InitWindow(800, 600, "Button Test");

    bool showError = false;
    char error[256] = "";  // Store error message

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (uiButton((Rectangle){100, 100, 150, 40}, "Make new project")) {
            TraceLog(LOG_INFO, "NewProject");
            if (createFolder("Project") != 0) {
                snprintf(error, sizeof(error), "An error occurred creating folder!");
                showError = true;
            } else {
                showError = false;
            }
        }

        if (showError) {
            DrawText(error, 20, 200, 20, RED);  // NO format string here!
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}