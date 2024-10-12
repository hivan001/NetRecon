#ifndef BASESCAN_H
#define BASESCAN_H
#include <iostream>
#include <asio.hpp>

class BaseScan 
{
    public:
        virtual ~BaseScan() = default; //virtual destructor
        virtual void Scan() = 0; // Implemented by concrete factories
        void ParseIp() const;

};


#endif