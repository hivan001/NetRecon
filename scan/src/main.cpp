#include <array>
#include <iostream>
#include <asio.hpp>
#include "TcpScan.h"

int main()
{
asio::io_context io_context;
asio::error_code error;

TcpScan scanner(io_context, error);


scanner.Scan();

scanner.printResults();

return 0;

}

