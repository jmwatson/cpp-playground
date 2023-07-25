#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cstdarg>

using std::string;

void RunTrainTickets();
string GetStop();
void PrintTicketInfo(bool &stop_found, string &stop, std::map<string, int> &ticket_costs, char* buffer);
size_t Max(int, ...);
void TestMax();

int main(int argc, char const * argv[])
{
    TestMax();
    return 0;
}

void RunTrainTickets()
{
    std::map<string, int> ticket_costs =
    {
        {"first", 400},
        {"second", 600},
        {"third", 1200}
    };
    char buffer[35];
    string stop;
    bool stop_found = false;

    do    
    {
        stop = GetStop();
        stop_found = std::any_of(std::begin(ticket_costs), std::end(ticket_costs),
            [&stop](std::pair<string, int> ticket)
            {
                return (ticket.first == stop);
            });
        PrintTicketInfo(stop_found, stop, ticket_costs, buffer);
    } while (stop_found);
}

string GetStop()
{
    string stop;
    std::cout <<"Make stop selection: ";
    std::cin >> stop;

    return stop;
}

void PrintTicketInfo(bool &stop_found, string &stop, std::map<string, int> &ticket_costs, char* buffer)
{
    if (stop_found)
    {
        sprintf(buffer, "The %s stop's ticket cost is %d", stop.c_str(), ticket_costs[stop]);
        std::cout << buffer << std::endl;
    }
}

size_t Max(int num, ...)
{
    va_list valist;
    va_start(valist, num);
    
    size_t max = va_arg(valist, size_t);
    for (int i = 1; i < num; i++)
    {
        size_t val = va_arg(valist, size_t);
        if (val > max)
        {
            max = val;
        }
    }

    va_end(valist);
    return max;
}

void TestMax()
{
    std::cout << "Max of 1, 2, 3, 4, 5: " << Max(5, 1, 2, 3, 4, 5) << std::endl;
    std::cout << "Max of 120, 140, 500000000, 76, 34, 354: " << Max(6, 120, 140, 500000000, 76, 34, 354) << std::endl;
}