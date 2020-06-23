#include "audioPlayer.h"

audioManager::audioManager() {
    ao_initialize();
    driver = ao_default_driver_id();

    mpg123_init();
    mh = mpg123_new(NULL, &err);
    buffer_size = mpg123_outblock(mh);
    buffer = (char *) malloc(buffer_size * sizeof(char));

    /* set the output format and open the output device */
    format.bits = mpg123_encsize(encoding) * 8;
    format.channels = 2;
    format.rate = 44100;
    format.byte_format = AO_FMT_NATIVE;

    char key;
    char value;
    ao_option aoption{
            (char*)"dev",
            (char*)"hw:0,1",
            NULL
    };

    dev = ao_open_live(ao_driver_id("alsa"), &format, &aoption);
    if(dev==NULL){
        fprintf(stderr, "Error opening device.\n");
        return;
    }
}

int audioManager::playFile(const char *fileName) {
    /* open the file and get the decoding format */
    mpg123_open(mh, fileName);
    mpg123_getformat(mh, &rate, &channels, &encoding);

    /* decode and play */
    printf("entering play loop");
    while (mpg123_read(mh, buffer, buffer_size, &done) == MPG123_OK)
        ao_play(dev, buffer, sizeof(buffer));
    printf("Play loop ended");
    return 0;
}

int audioManager::audioCleanUp() {
    free(buffer);
    ao_close(dev);
    mpg123_close(mh);
    mpg123_delete(mh);
    mpg123_exit();
    ao_shutdown();

    return 0;
}
