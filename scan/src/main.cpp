#include <array>
#include <iostream>
#include <asio.hpp>
#include "TcpScan.h"
#include "WriteResults.h"

int main()
{
asio::io_context io_context;
asio::error_code error;

TcpScan scanner(io_context, error);
WriteResults writer;

scanner.Scan();

scanner.printResults();

writer.addScanToResults(scanner.resultsToJSON());

writer.writeJSONFile();

return 0;

}

