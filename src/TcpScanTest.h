// #ifndef TCPSCAN_H
// #define TCPSCAN_H
// #include <iostream>
// #include <asio.hpp>
// #include "BaseScan.h"

// using asio::ip::tcp;

// class TcpScan : public BaseScan
// {
//     public:
//     TcpScan(asio::io_context& io_context, asio::error_code& error);
//     void Scan() override;
//     void ParseIp() const;


//     private:
//     asio::io_context& io_context;
//     asio::error_code& error;
//     asio::ip::tcp::resolver resolver;
//     asio::ip::tcp::resolver::results_type endpoints;
//     asio::ip::tcp::socket socket;
    
// };

// #endif