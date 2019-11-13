#include "daqi/da4qi4.hpp"

using namespace da4qi4;

void hello(Context ctx)
{
    ctx->Res().ReplyOk("Hello World!");
    ctx->Pass();
}

int main()
{
    auto svc = Server::Supply("127.0.0.1", 4098);
    svc->AddHandler(_GET_, "/", hello);
    svc->Run();

    return 0;
}
