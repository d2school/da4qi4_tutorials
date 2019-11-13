#include "daqi/da4qi4.hpp"

using namespace da4qi4;

int main()
{
    auto svc = Server::Supply("127.0.0.1", 4098);
    auto app = svc->DefaultApp();  //取得由Server自动创建的默认应用
    app->SetTemplateRoot("view/02/"); //本课HTML模板文件放于此处
    app->InitTemplates();
    svc->Run();
}
