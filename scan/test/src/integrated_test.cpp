#include <gtest/gtest.h>
#include "Menu.h"
#include "TcpScan.h"
#include "WriteResults.h"
#include <asio.hpp>
#include <fstream>

class MockTcpIntegratedScan : public TcpScan {
public:
    MockTcpIntegratedScan(asio::io_context& io_context, asio::error_code& error)
        : TcpScan(io_context, error) {
            open_port(80);
        }

    std::string get_user_input() const override {
        return "127.0.0.1";
    }

    void open_port(int port){

        try
        {   asio::io_context test_io_context;
            asio::ip::tcp::endpoint test_endpoint(asio::ip::address::from_string("127.0.0.1"), port);

            asio::ip::tcp::acceptor test_acceptor(test_io_context, test_endpoint);
            asio::ip::tcp::socket test_socket(test_io_context);
            test_acceptor.accept(test_socket);
        }
        catch(const asio::system_error& e)
        {   std::cout<<"Unable to create port on test target"<<std::endl;
            std::cerr << e.what() << '\n';
        }
        

    }

};
class MockMenuIntegrated : public Menu{
    public:
    MockMenuIntegrated(int argc, char* argv[]):Menu(argc,argv){}

    int init(std::string scan_type) override
    {   WriteResults writer;

        if(scan_type == "tcp")
        {
            MockTcpIntegratedScan scanner(io_context, error);

            if(scanner.Scan() == 1)
            {
                std::cout<<"TCP Scan failed"<<std::endl;
                return 1;
            }
            else
            {
                scanner.printResults();
                // results = scanner.resultsToJSON();
                writer.addScanToResults(scanner.resultsToJSON());
                writer.writeJSONFile("/test_results");
            }
        }
        else if(scan_type == "udp")
        {
            //udp scan
        }
        else if(scan_type == "m60")
        {
            //both tcp and udp
        }


        // WriteResults writer;

        // writer.addScanToResults(results);

        // writer.writeJSONFile();
        std::string filepath = "/test_results/results.json";
        std::ofstream TestResults(filepath);

        
        if(TestResults.is_open())
        {
            std::string line;
            while (std::getline(TestResults, line)) 
            { 
                std::cout << line << std::endl; // Print the content
            }
        }

        TestResults.close();


        return 0;


    }
};

class IntegratedTest : public testing::Test {
    int argc;
    char** argv;

    MockMenuIntegrated menu;

    IntegratedTest() 
        : argc(1), argv(new char*[2]), menu() {
        argv[0] = strdup("-t");
        argv[1] = nullptr;
    }

    ~IntegratedTest() {
        free(argv[0]);
        delete[] argv;
    }
};


TEST_F(IntegratedTest, TestInit){
    ASSERT_TRUE(1==1);
}