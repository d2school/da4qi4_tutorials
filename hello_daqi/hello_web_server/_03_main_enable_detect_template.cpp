#include "daqi/da4qi4.hpp"

using namespace da4qi4;

int main()
{
    auto svc = Server::Supply("127.0.0.1", 4098);
    auto app = svc->DefaultApp();
    app->SetTemplateRoot("view/03"); //模板文件根目录
    app->InitTemplates();

    svc->EnableDetectTemplates(3); //3秒
    svc->Run();
}
