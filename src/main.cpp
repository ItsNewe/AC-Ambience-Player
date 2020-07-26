#include <iostream>
#include "fileManager.h"
#include "audioPlayer.h"
#include <string>
#include <ctime>
#include <csignal>

int hourStore;
bool breakSwitch;

void sigintCb(int signum) {
    printf("Caught signal %d", signum );
    exit(signum);
}

int getCurrentHourInt(){
    time_t timeNow = time(0);
    tm *lTime = localtime(&timeNow);
    return lTime->tm_hour;
}

int main(int argc, char *argv[]) {
    //Debug example

    signal(SIGINT, sigintCb);

    auto *a = new AudioManager();
    auto *f = new FileManager();

    f->getFileListAndStore("hourly");

    while(!breakSwitch){
        int h = getCurrentHourInt();
        if(hourStore!=h){
            a->playFile(h, f);
        }
    }
}