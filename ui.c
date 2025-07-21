#include "ui.h"

bool uiButton(Rectangle bounds, const char *text) {
    Vector2 mouse = GetMousePosition();
    bool hovered = CheckCollisionPointRec(mouse, bounds);
    bool clicked = hovered && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);

    DrawRectangleRec(bounds, hovered ? DARKGRAY : GRAY);
    DrawText(text, bounds.x + 10, bounds.y + 10, 20, BLACK);

    return clicked;
}
