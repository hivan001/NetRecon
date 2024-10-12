#ifndef TCPSCAN_H
#define TCPSCAN_H
// #include "TcpScan.h"
#include <iostream>
#include <asio.hpp>
#include "BaseScan.h"

using asio::ip::tcp;

class TcpScan : public BaseScan
{
    //difference between using initialization list and using the this keyword is that an initialization list sets the member variables at the time of construction not after
    public:
    TcpScan(asio::io_context& io_context, asio::error_code& error)
        : io_context(io_context), error(error), resolver(io_context), socket(io_context) {
        this->endpoints = resolver.resolve("127.0.0.1", std::to_string(8080));
    }

    void Scan() override
    {  asio::connect(socket,endpoints,error);

    if(error == asio::error::connection_refused)
     {
        std::cout<<"\033[31m"<<"Connection Refused on port"<<std::endl;
     }
     else
     {
        std::cout<<"\033[32m"<<"Connection is open on port: "<<std::endl;
     }

     socket.close();
    }

    void ParseIp() const
    {
        std::cout<<"Test"<<std::endl;
    }


    private:
    asio::io_context& io_context;
    asio::error_code& error;
    asio::ip::tcp::resolver resolver;
    asio::ip::tcp::resolver::results_type endpoints;
    asio::ip::tcp::socket socket;
    
};

#endif