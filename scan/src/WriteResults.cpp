#include <iostream>
#include <asio.hpp>
#include <unordered_map>
#include <nlohmann/json.hpp>
#include "WriteResults.h"

WriteResults::WriteResults():scanResults(scanResults)
{
    scanResults["IPs"] = "";
}