// Given a /24 CIDR address or single IP, return a vector of IP objects
//Should be 254 IPs for a /24 network
// Example input is "192.168.100.0/24"

#include <iostream>
#include <asio.hpp>
#include "BaseScan.h"

void BaseScan::checkIp(std::string& input, asio::system_error& ec, std::string& cidr) const 
{ 
    std::string address = "";
try{
    if(cidr != "")
    {   int numCidr = 0;
        try
        {
            numCidr = std::stoi(cidr);
        }
        catch(const std::exception& e)
        {   std::cout<<"Invalid CIDR passed in, please try again"<<std::endl;
            std::cerr << e.what() << '\n';

            get_Ips();
        }

        if(numCidr > 30 || numCidr < 24)
        {
            throw std::invalid_argument("/" + std::to_string(numCidr) + " network is not supported. Please choose a CIDR from /24 - /30\n");
        }

        address = input;
        address.erase(input.length() - 3);
    }
    else
    {
        address = input;
    }

        asio::ip::address adr = asio::ip::make_address(address);
    }
    catch(const asio::system_error &ec)
    {
        std::cout<<"Unable to resolve the IP address, please try a different IP or CIDR \n"<<std::endl;
        get_Ips();
    }
    catch(const std::invalid_argument &e)
    {
        std::cerr<<e.what()<<std::endl;
        get_Ips();
    }
    
}

std::vector<asio::ip::address> BaseScan::get_Ips() const
{
    std::string input;
    asio::system_error ec;
    std::string cidr = "";
    int hosts = 0;
    std::vector<asio::ip::address> Ips;
    std::cin.clear();

    std::cout<<"Enter IP"<<std::endl;

    std::cin>>input;

    //Checking to see if user passed in a CIDR
    std::size_t cidrSearch = input.find("/");

    if(cidrSearch != std::string::npos)
    {
        cidr = input.substr(input.length() - 2, 2);
    }

    checkIp(input, ec, cidr);

    //Either single IP or CIDR is good
    if(cidr == "")
    {   
        Ips.reserve(1);
        asio::ip::address adr = asio::ip::make_address(input);

        Ips.push_back(adr);

    }
    else
    {
        auto hostFinder = cidrHosts.find(cidr);
        hosts = hostFinder->second;

        Ips.reserve(hosts);

        std::string firstThreeOctets = "";
        std::string strLastOctet;
        int lastOctet = 0;
        int count = 0;

        input.erase(input.length() - 3,3);
        firstThreeOctets = input;

        for(int i = 0; i < input.length(); i++)
        {   
            if(count == 3)
            {
                strLastOctet+=input[i];
            }
            else if(input[i] == '.')
            {
                count++;
            }
            else
            {
                continue;
            }
            
        }   

        lastOctet = std::stoi(strLastOctet);

        std::string pattern = strLastOctet;
        size_t found = firstThreeOctets.rfind(pattern);

        firstThreeOctets.replace(found,pattern.length(),"");

        for(lastOctet; lastOctet <= (lastOctet+hosts) && lastOctet < 255; lastOctet++)
        {   
            asio::ip::address adr = asio::ip::make_address(firstThreeOctets + std::to_string(lastOctet));
            Ips.push_back(adr);
        }

    }
    return Ips;

}