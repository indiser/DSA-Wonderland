#include <iostream>
#include <thread>

#include <boost/asio.hpp>

using boost::asio::ip::tcp;

void handleClient(tcp::socket socket)
{
    try
    {
        std::cout << "Client connected: "
                  << socket.remote_endpoint()
                  << "\n";

        std::string message =
            "Hello from Boost.Asio server!\n";

        boost::asio::write(
            socket,
            boost::asio::buffer(message)
        );

        char data[1024];

        boost::system::error_code error;

        size_t length =
            socket.read_some(
                boost::asio::buffer(data),
                error
            );

        if (!error)
        {
            std::cout << "Received: "
                      << std::string(data, length)
                      << "\n";
        }
    }
    catch (std::exception& e)
    {
        std::cerr << "Client error: "
                  << e.what()
                  << "\n";
    }
}

int main()
{
    try
    {
        boost::asio::io_context ioContext;

        tcp::acceptor acceptor(
            ioContext,
            tcp::endpoint(tcp::v4(), 8080)
        );

        std::cout << "Server listening on port 8080...\n";

        while (true)
        {
            tcp::socket socket(ioContext);

            acceptor.accept(socket);

            std::thread(
                handleClient,
                std::move(socket)
            ).detach();
        }
    }
    catch (std::exception& e)
    {
        std::cerr << "Server error: "
                  << e.what()
                  << "\n";
    }

    return 0;
}