#include <chrono>
#include <iostream>
#include <string>
#include <deque>
#include <conio.h>

#define DEBATE_TIME 60
#define INDIV_TIME 10

void AddToQueue(std::string str, std::deque<std::string>& queue)
{

    for(std::deque<std::string>::iterator i; i!=queue.end(); ++i){

        if(str != *i){

            queue.push_back(str);
            break;

            std::cout << "teste";
            //testing git

        }

    }

}

int main()
{

    std::cout << "Enter paritipants name:\n";

    std::deque<std::string> queue;
    std::string str;

    do //Fills queue
    {

        std::cin >> str;
        std::cout << "ponto?\n";


        if(str != ".")
        {

            int max = queue.size();

            for(int i=0; i <= max; ++i)
            {

                if(str != queue[i]){

                    queue.push_back(str);

                }               

            }

        }
        else
        {
            
            std::cout << "ponto!\n";

        }
        

    }while(str != ".");

    std::cout << "Press enter when ready\n";
    getch();

    std::cout << "Starting!\n";

    std::chrono::steady_clock::time_point deb = std::chrono::steady_clock::now() + std::chrono::seconds(DEBATE_TIME);

    while (std::chrono::steady_clock::now() < deb)
    {
        
        std::cout << "Time for " << *queue.begin() << std::endl;
        std::chrono::steady_clock::time_point indv = std::chrono::steady_clock::now() + std::chrono::seconds(INDIV_TIME);

        while(std::chrono::steady_clock::now() < indv){

            if(kbhit()){

                std::cin >> str;
                if(str == ".")
                {

                    break;
                    
                }
                else
                {
                    
                    AddToQueue(str, queue);

                }
                
            }

        }

        std::cout << "Time's up!\n";

        queue.pop_front();

    }
    std::cout << "end\n";

    return 0;

}