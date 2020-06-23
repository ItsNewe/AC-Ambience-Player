#include <iostream>
#include "fileManager.h"
#include "audioPlayer.h"
int main() {
    //Debug example
    auto *a = new audioManager();
    a->playFile("./assets/OST/main.mp3");
    a->audioCleanUp();
}