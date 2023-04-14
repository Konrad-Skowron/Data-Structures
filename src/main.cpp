#include <windows.h>
#include "views.h"
#include "controllers.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    dsInit();
    menuMain();
    dsDelete();
    system("PAUSE");
    return 0;
}
