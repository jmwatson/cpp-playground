#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using std::string;

string GetStop();
void PrintTicketInfo(bool &stop_found, string &stop, std::map<string, int> &ticket_costs, char* buffer);

int main(int argc, char const * argv[])
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
    return 0;
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