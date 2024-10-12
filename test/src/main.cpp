#include <array>
#include <iostream>
#include <asio.hpp>
#include "BaseScan.h"

int main()
{
asio::io_context io_context;
asio::error_code error;

BaseScan scanner;

scanner.checkIp();

  return 0;

}

