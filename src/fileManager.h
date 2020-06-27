//
// Created by newe on 23/06/2020.
//

#ifndef ACNL_PLAYER_FILEMANAGER_H
#define ACNL_PLAYER_FILEMANAGER_H

#include <cstdio>
#include <string>
#include <filesystem>
#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <algorithm>

#define ASSETSPATH "./assets/"

class FileManager{
private:
    //3 maps with the format [24hour, filePath], one for each weather variation

    //ToDo: Switch file handling & storing logic from being managed by main.cpp to being managed by &this
    std::map<int, std::string> hourlySongs{};
    std::map<int, std::string> hourlyRainySongs{};
    std::map<int, std::string> hourlySnowySongs{};

public:
    FileManager();
    void getFileListAndStore(const std::string& searchPath);

    const char *getFilePathFromHour(int *h);
};

#endif //ACNL_PLAYER_FILEMANAGER_H
