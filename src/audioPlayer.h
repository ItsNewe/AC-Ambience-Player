//
// Created by newe on 23/06/2020.
//

#ifndef ACNL_PLAYER_AUDIOPLAYER_H
#define ACNL_PLAYER_AUDIOPLAYER_H
#include <mpg123.h>
#include <ao/ao.h>
#include <string>

#define BITS 8

class audioManager
        {
private:
    mpg123_handle *mh;
    char *buffer;
    size_t buffer_size;
    size_t done;
    int err;

    int driver;
    ao_device *dev;
    ao_sample_format format;

    int channels, encoding;
    long rate;
public:
    audioManager();
    int playFile(const char *fileName);
    int audioCleanUp();
};

#endif //ACNL_PLAYER_AUDIOPLAYER_H
