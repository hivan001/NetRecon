
#include <iostream>
#include <asio.hpp>
#include "BaseScan.h"
#include "TcpScan.h"

using asio::ip::tcp;


    TcpScan::TcpScan(asio::io_context& io_context, asio::error_code& error):io_context(io_context), error(error), 
    socket(io_context), resolver(io_context){
        this->results = results;
    };

    std::vector<asio::ip::tcp::endpoint> TcpScan::make_tcp_endpoints(std::vector<asio::ip::address> ips)
    {   
        std::vector<asio::ip::tcp::endpoint> endpoints;
        // Going to start by only scanning the 1023 most common ports

        for(asio::ip::address ip : ips)
        {   
            try
            {
                for(int i = 0; i < 1024; i++)
                {   
                    asio::ip::tcp::endpoint endpoint(ip, i);
                    endpoints.push_back(endpoint);
                }
            }
            catch(const asio::system_error &ec)
            {
                std::cout<<"Unable to create endpoints for "+ip.to_string()<<std::endl;
            }

        }

        return endpoints;
    }

    void TcpScan::Scan()
    {   
        this->ips = get_Ips();

        this->endpoints = make_tcp_endpoints(ips);


        try{

            for(const auto& endpoint : endpoints)
            {
                asio::error_code error;

                std::string port = std::to_string(endpoint.port());

                if(socket.is_open())
                {
                    socket.close();
                }

                asio::ip::tcp::resolver::results_type endpointScan = resolver.resolve(endpoint); //can't iterate of endpoints and pass in directly

                asio::connect(socket,endpointScan, error);

                if(error == asio::error::connection_refused)
                {
                    continue;
                }
                else
                {
                    std::cout<<"\033[32m"<<"Connection is open on port: "+port<<std::endl<<std::endl;
                    results[endpoint.address().to_string()].ports.push_back(port);

                }
            }         

        }catch (const asio::system_error& e) 
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    void TcpScan::printResults()
    {
        for(const auto& result : results)
        {   std::cout<<std::endl;
            std::cout<<"\033[0m"<<result.first<<" has "<<result.second.ports.size()<<" port(s) open"<<std::endl<<std::endl;
            std::cout<<"\033[32m"<<"Ports open: \n";
            for(std::string port : result.second.ports)
            {
                std::cout<<"\033[32m"<<port<<std::endl;
            }
        }
    }

    