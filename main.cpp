#include </home/kali/cpprest/cpprestsdk/Release/include/cpprest/http_listener.h>
#include </home/kali/cpprest/cpprestsdk/Release/include/cpprest/json.h>

using namespace web;
using namespace http;
using namespace http::experimental::listener;

int main() {
    http_listener listener("http://localhost:8080");

    listener.support(methods::GET, [](http_request request) {
        json::value response = json::value::object();
        response["message"] = json::value::string("Hello, world!");

        request.reply(status_codes::OK, response);
    });

    listener.open().wait();

    std::cout << "Listening on port 8080..." << std::endl;

    while (true);

    return 0;
}

