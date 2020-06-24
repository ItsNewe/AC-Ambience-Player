#include "audioPlayer.h"
#include <stdio.h>

AudioManager::AudioManager() {
    ao_initialize();
    mpg123_init();
    this->mh = mpg123_new(NULL, &err);
    this->buffer_size = mpg123_outblock(mh);
    this->buffer = (char *) malloc(buffer_size * sizeof(char));
}

int AudioManager::playFile(const std::string &fileName) {
    // open the file and get the decoding format
    printf("Received fileName: %s", fileName);
    mpg123_open(this->mh, fileName.c_str());
    mpg123_getformat(this->mh, &this->rate, &this->channels, &this->encoding);

    // set the output format and open the output device
    this->format.bits = mpg123_encsize(this->encoding) * BITS;
    this->format.rate = this->rate;
    this->format.channels = this->channels;
    this->format.byte_format = AO_FMT_NATIVE;
    this->format.matrix = 0;

    this->dev = ao_open_live(ao_driver_id("pulse"), &this->format, NULL);
    if (this->dev == NULL) {
        fprintf(stderr, "Error opening device.\n");
        return 1;
    }

    // decode and play
    while (mpg123_read(this->mh, this->buffer, this->buffer_size, &this->done) == MPG123_OK)
        ao_play(this->dev, this->buffer, this->done);

    return 0;
}

int AudioManager::audioCleanUp() {
    free(this->buffer);
    ao_close(this->dev);
    mpg123_close(this->mh);
    mpg123_delete(this->mh);
    mpg123_exit();
    ao_shutdown();

    return 0;
}
