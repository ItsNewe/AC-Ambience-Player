#include "fileManager.h"

namespace fs = std::filesystem;

void getFileList(const std::string& searchPath) {
    const fs::path p = searchPath;
    for(auto& entry : fs::directory_iterator(p)){
        std::cout << (entry.path()) << std::endl;
    }

}

std::string getCleanFileName(std::string &fileName){

}