#include "daqi/da4qi4.hpp"

using namespace da4qi4;

int main()
{
    auto svc = Server::Supply(4098);
    svc->AddHandler(_GET_, "/", [](Context ctx)
    {
        ctx->Res().ReplyOk("Hello World!");
        ctx->Pass();
    });

    svc->Run();
}
