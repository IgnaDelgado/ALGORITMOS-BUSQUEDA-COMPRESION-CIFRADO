#include <iostream>
#include <conio.h> // Para _getch()
#include <vector>
#include <windows.h> // Para manipular la consola en Windows

using namespace std;

// Función para cambiar el color de texto en la consola (solo para Windows)
void setTextColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Función para dibujar una línea horizontal del marco
void drawHorizontalLine(int width) {
    cout << "+";
    for (int i = 0; i < width; i++) {
        cout << "-";
    }
    cout << "+" << endl;
}

// Función para centrar el texto dentro del marco
void printCenteredText(const string& text, int width) {
    int padding = (width - text.length()) / 2;
    cout << "|";
    for (int i = 0; i < padding; i++) {
        cout << " ";
    }
    cout << text;
    for (int i = 0; i < padding; i++) {
        cout << " ";
    }
    if (text.length() % 2 != width % 2) {
        cout << " ";
    }
    cout << "|" << endl;
}

// Función para dibujar el menú con marco
void drawMenu(const vector<string>& options, int selectedIndex) {
    int menuWidth = 30;  // Ancho del marco
    system("cls"); // Limpiar la consola

    drawHorizontalLine(menuWidth);  // Línea superior del marco
    printCenteredText(" MENU PRINCIPAL ", menuWidth);  // Título centrado
    drawHorizontalLine(menuWidth);  // Línea debajo del título

    for (int i = 0; i < options.size(); i++) {
        if (i == selectedIndex) {
            setTextColor(14); // Cambiar a amarillo para la opción seleccionada
            printCenteredText("> " + options[i] + " <", menuWidth);
            setTextColor(7);  // Volver al color blanco normal
        }
        else {
            printCenteredText("  " + options[i], menuWidth);
        }
    }

    drawHorizontalLine(menuWidth);  // Línea inferior del marco
}

int main() {
    vector<string> options = {
       "1. Busqueda",
       "2. Compresion",
       "3. Cifrado",
       "4. Salir"
    };

    int selectedIndex = 0; // Opción seleccionada inicialmente

    cout << "Para navegar por el menu utilizar las flechas para arriba y para abajo de su teclado" << endl;
    cout << "Para seleccionar una opcion precione la tecla enter de su teclado" << endl;

    Sleep(5700);

    while (true) {
        // Dibujar el menú
        drawMenu(options, selectedIndex);

        // Capturar la tecla presionada
        int key = _getch();

        // Verificar si es una tecla especial (como las flechas)
        if (key == 224) {
            // _getch() devuelve 224 seguido por el código de la tecla especial
            key = _getch();
            if (key == 72) {
                // Flecha hacia arriba (código 72)
                selectedIndex = (selectedIndex - 1 + options.size()) % options.size();
            }
            else if (key == 80) {
                // Flecha hacia abajo (código 80)
                selectedIndex = (selectedIndex + 1) % options.size();
            }
        }
        else if (key == 13) {
            switch (selectedIndex + 1) {
            case 1:
                system("BUSQUEDA\\menuBusqueda.exe");
                break;
            case 2:
                system("COMPRESION\\menuCompresion.exe");
                break;
            case 3:
                system("CIFRADO\\menuCifrado.exe");
                break;
            case 4:
                return 0;
            }

            system("pause"); // Pausa para que el usuario vea el mensaje
        }
    }
}
