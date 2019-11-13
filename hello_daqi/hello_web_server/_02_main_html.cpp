#include "daqi/da4qi4.hpp"

using namespace da4qi4;

int main()
{
    auto svc = Server::Supply("127.0.0.1", 4098);

    svc->AddHandler(_GET_, "/", [](Context ctx)
    {
        std::string html = R"(<html><body><h1 style="color:blue">Hello world</h1></body></html>)";
        ctx->Res().ReplyOk(html);
        ctx->Pass();
    });

    svc->Run();
    return 0;
}
