#include <array>
#include <iostream>
#include <asio.hpp>
#include "TcpScan.h"

int main()
{
asio::io_context io_context;
asio::error_code error;

TcpScan scan(io_context, error);


scan.Scan();

return 0;

}

