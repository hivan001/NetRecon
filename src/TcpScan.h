#ifndef TCPSCAN_H
#define TCPSCAN_H
#include <iostream>
#include <asio.hpp>
#include "BaseScan.h"

using asio::ip::tcp;

struct ScannedIp {
    std::vector<std::string> ports;
};

class TcpScan : public BaseScan
{
    //difference between using initialization list and using the this keyword is that an initialization list sets the member variables at the time of construction not after
    public:
    TcpScan(asio::io_context& io_context, asio::error_code& error);
    std::vector<asio::ip::tcp::endpoint> make_tcp_endpoints(std::vector<asio::ip::address> Ips);
    void printResults();
    void Scan() override;


    private:
    asio::io_context& io_context;
    asio::error_code& error;
    asio::ip::tcp::resolver resolver;
    asio::ip::tcp::socket socket;
    std::vector<asio::ip::address> ips;
    std::vector<asio::ip::tcp::endpoint> endpoints; 
    std::unordered_map<std::string, ScannedIp> results;
    
};

#endif