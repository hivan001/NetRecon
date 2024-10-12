// Given a /24 CIDR address, return all of the IPs in that address
//Should be 256 IPs for a /24 network
// Example input is "192.168.100.0/24"
// Need to perform some form of validation of the passed in IP address

#include <iostream>
#include <unordered_map>
#include <vector>
#include <asio.hpp>
#include "BaseScan.h"

// void BaseScan::Scan() {}; // Implemented by concrete factories
void BaseScan::checkIp() const 
{   std::string input;
    asio::system_error ec;

    std::cout<<"Enter IP"<<std::endl;

    std::cin>>input;
try{
    if(input.substr(input.length() - 3, 2) != "24" || input.substr(input.length() - 3, 2) != "25" || input.substr(input.length() - 3, 2) != "26"||
    input.substr(input.length() - 3, 2) != "27"||input.substr(input.length() - 3, 2) != "28"||input.substr(input.length() - 3, 2) != "29"||input.substr(input.length() - 3, 2) != "30")
    {   
        throw asio::system_error(ec);
    }


    std::string address = input;
    address.erase(input.length() - 3);

    asio::ip::address adr = asio::ip::make_address(address);
    }
catch(asio::system_error &ec)
{
    std::cout<<"You entered an invalid IP address and CIDR. Please try again\n"<<std::endl;
    checkIp();
} 
    
}




// int main() {
// string input;  
// string cidr;
// int hosts = 0;
// string strLastOctet;
// int lastOctet;
// vector<string> ips;
// string firstThreeOctets;


// cout<<"Enter an IP address"<<endl;
// cin>>input;

// firstThreeOctets = input;

// unordered_map<string, int> cidrHosts = {
//   {"24", 254},
//   {"25", 126},
//   {"26", 62},
//   {"27", 30},
//   {"28", 14},
//   {"29", 6},
//   {"30", 2}
// };

// cidr+= input[input.length()-2];
// cidr+= input[input.length()-1];

// auto hostFinder = cidrHosts.find(cidr);

// hosts = hostFinder->second;

// for(int i,j = 0; i<input.length()-3; i++)
// {
//   if(j==3)
//   {
//     strLastOctet+=input[i];
//   }
//   else if(input[i] == '.')
//   {
//     j++;
//   }
//   else
//   {
//     continue;
//   }

// }

// firstThreeOctets.erase(firstThreeOctets.length() - 3,3);

// string pattern = strLastOctet;
// size_t found = firstThreeOctets.rfind(pattern);

// firstThreeOctets.replace(found,pattern.length(),"");
// lastOctet = stoi(strLastOctet);


// for(int i = lastOctet; i < lastOctet + hosts && i < 255; i++ )
// { 

//   ips.push_back(firstThreeOctets + to_string(i));

// }

// for(int i = 0; i<ips.size();i++)
// {

//   cout<<ips[i]<<endl;

// }

//   return 0;

// }