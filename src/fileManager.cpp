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

    /*
    for(int i=1; i<=24; i++) {
        int a = 0;
        if (i <= 12) {
            //Iterating through the vectors to find the correct file for the correct hour, since the strings are not sorted in the vector
            while (returnVector[a].substr(sizeof(ASSETSPATH)+type.size()+6, std::to_string(i).length())!=std::to_string(i)  PROBLEMATIC PART ->  && returnVector[a].substr(sizeof(ASSETSPATH)+type.size()+8, 2)!="PM"){
                a++;
            }

        } else { //Since we store the strings along side the 24-hour format hour digit, we need a check for both AM & PM
            while (returnVector[a].substr(sizeof(ASSETSPATH)+type.size()+6, 1)!=std::to_string(i) && returnVector[a].substr(sizeof(ASSETSPATH)+type.size()+8, 2)!="AM"){
                a++;
            }
        }
        std::cout <<"'"<<returnVector[a].substr(sizeof(ASSETSPATH)+type.size()+6, 1) << "' || '"<< returnVector[a].substr(sizeof(ASSETSPATH)+type.size()+8, 2) <<"'"<< std::endl;

        if(type=="hourly"){
            hourlySongs[i]=returnVector[a];
        } else if(type=="rainy"){
            hourlyRainySongs[i]=returnVector[a];
        } else if(type=="snowy"){
            hourlySnowySongs[i]=returnVector[a];
        }
    } */
}

std::string FileManager::getFilePathFromHour(int &h){
    //ToDo: hourlySongs[0]=key(1) = 2 AM, hourlySongs[24] should be 1 AM but results to "", 1 Am is missing; find why
    std::cout << hourlySongs.at(h-1) << std::endl;
    auto a = this->hourlySongs.at((char)h-1);
    return a;
}