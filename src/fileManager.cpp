#include "fileManager.h"

namespace fs = std::filesystem;

FileManager::FileManager(){
    printf("File manager instance created");
}

void FileManager::getFileListAndStore(const std::string& type) {
    const fs::path p = ASSETSPATH + type;
    auto *returnVector= new std::vector<std::string>{};
    returnVector->reserve(23); //Reserve memory for 23 items

    // Fill returnVector with unsorted folder contents
    for(auto& entry : fs::directory_iterator(ASSETSPATH + type)){
        returnVector->push_back(entry.path().string());
    }

    std::sort(returnVector->begin(), returnVector->end());

    int *iTemp= new int(0);
    for(auto const& value: *returnVector) {
        std::cout << (*returnVector)[*iTemp] << std::endl;
        if(type=="hourly"){
            hourlySongs[*iTemp]=(*returnVector)[*iTemp];
        } else if(type=="rainy"){
            hourlyRainySongs[*iTemp]=(*returnVector)[*iTemp];
        } else if(type=="snowy"){
            hourlySnowySongs[*iTemp]=(*returnVector)[*iTemp];
        }
        ++*iTemp;
    }
    //Deleting the iTemp pointer and returnVector since we don't need them anymore
    delete(iTemp);
    delete(returnVector);

}

std::string FileManager::getFilePathFromHour(int &h){
    //ToDo: hourlySongs[0]=key(1) = 2 AM, hourlySongs[24] should be 1 AM but results to "", 1 Am is missing; find why
    std::cout << hourlySongs.at(h-1) << std::endl;
    auto a = this->hourlySongs.at((char)h-1);
    return a;
}