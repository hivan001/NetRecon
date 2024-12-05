#ifndef WRITERESULTS_H
#define WRITERESULTS_H
#include <iostream>
#include <asio.hpp>
#include <unordered_map>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
class WriteResults
{
    public:
        WriteResults();
        void addScanToResults(json results);
        void writeJSONFile();
        json getScanResults();


    private:
        json scanResults;

};


#endif