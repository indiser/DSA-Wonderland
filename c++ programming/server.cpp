#include <iostream>

#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/io_context.hpp>

namespace beast = boost::beast;
namespace websocket = beast::websocket;
namespace net = boost::asio;

using tcp = net::ip::tcp;

int main()
{
    try
    {
        net::io_context ioContext;

        tcp::acceptor acceptor(
            ioContext,
            tcp::endpoint(tcp::v4(), 8080)
        );

        std::cout << "WebSocket server running on port 8080...\n";

        while (true)
{
    try
    {
        tcp::socket socket(ioContext);

        acceptor.accept(socket);

        websocket::stream<tcp::socket> ws(std::move(socket));

        ws.accept();

        std::cout << "Client connected!\n";

        while (true)
        {
            beast::flat_buffer buffer;

            ws.read(buffer);

            std::string msg =
                beast::buffers_to_string(buffer.data());

            std::cout << "Received: "
                      << msg
                      << "\n";

            std::string response =
                "Echo: " + msg;

            ws.write(net::buffer(response));
        }
    }
    catch (std::exception const& e)
    {
        std::cerr << "Client error: "
                  << e.what()
                  << "\n";
    }
}
    }
    catch (std::exception const& e)
    {
        std::cerr << "Error: "
                  << e.what()
                  << "\n";
    }

    return 0;
}