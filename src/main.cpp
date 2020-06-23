#include <iostream>
#include "fileManager.h"
#include "audioPlayer.h"
int main() {
    auto *a = new audioManager();
    a->playFile("./assets/OST/main.mp3");

}
