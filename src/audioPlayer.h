//
// Created by newe on 23/06/2020.
//

#ifndef ACNL_PLAYER_AUDIOPLAYER_H
#define ACNL_PLAYER_AUDIOPLAYER_H
#include <mpg123.h>
#include <ao/ao.h>
#include <string>
#include <bits/stl_tree.h>

#define BITS 8

class AudioManager
        {
private:
    mpg123_handle *mh;
    char *buffer;
    size_t buffer_size;
    size_t done;
    int err;

    ao_device *dev;
    ao_sample_format format;

    int channels, encoding;
    long rate;

public:
    AudioManager();
    int playFile(const std::basic_string<char>& fileName);
    int audioCleanUp();
};

#endif //ACNL_PLAYER_AUDIOPLAYER_H
