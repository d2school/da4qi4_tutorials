#include "daqi/da4qi4.hpp"

using namespace da4qi4;

void add(Context ctx)
{
    try
    {
        //取得URL参数 a 和 b:
        std::string a = ctx->Req().GetUrlParameter("a");
        std::string b = ctx->Req().GetUrlParameter("b");

        //把字符串转换为整数:
        int na = std::stoi(a);  //stoi 是 C++11新标中的字符串转换整数的函数
        int nb = std::stoi(b);

        //本例的核心业务逻辑，其实就这一行：
        int c = na + nb;
       ctx->ModelData()["c"] = c;
    }
   catch(std::exception const& e)
   {
        ctx->ModelData()["c"] = std::string("处理入参转换异常.") + e.what();
   }

   ctx->Render().Pass();  //Render 是动词：渲染
}

int main()
{
    auto svc = Server::Supply("127.0.0.1", 4098);
    auto app = svc->DefaultApp();
    app->SetTemplateRoot("view/03"); //模板文件根目录
    app->InitTemplates();
    app->AddHandler(_GET_, "/add", add);

    svc->EnableDetectTemplates(3); //3秒
    svc->Run();
}
