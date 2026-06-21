#include <iostream>

void toLower(char *text) {
    while (*text) {
        if ('A' <= *text && *text <= 'Z') {
            *text += ('a' - 'A');
        }
        text++;
    }
}

void toUpper(char *text) {
    while (*text) {
        if ('a' <= *text && *text <= 'z') {
        *text += ('A' - 'a');
    }
    text++;
}
}

int textSize(char *text) {
    int size = 0;
    while (*text) {
        size++;
        text++;
    }
    return size;
}

int main() {
    char text[] = "Ala ma kota.";
    printf("%s\n", text);
    toLower(text);
    printf("%s\n", text);
    printf("%d\n", textSize(text));
    toUpper(text);
    printf("%s\n", text);
    printf("%d\n", textSize(text));

    return 0;
}
