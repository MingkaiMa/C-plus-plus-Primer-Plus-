#include <iostream>
#include <string>
#include <memory>

class Report
{
private:
    std::string str;
public:
    Report(const std::string s) : str(s)
    {
        std::cout << "Object created!\n";
    }
    ~Report(){std::cout << "Object deleted\n";}
    void comment() const {std::cout << str << "\n";}
};

int main()
{
    {
        std::auto_ptr<Report> ps (new Report("Using auto_ptr"));
        ps->comment();
    }

    {
        std::shared_ptr<Report> ps (new Report("Using shared_ptr"));
        ps->comment();
    }

    {
        std::unique_ptr<Report> ps (new Report("Using unique_ptr"));
        ps->comment();
    }

    return 0;
}