#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

int main()
{
    bool stop_while = false;
    vector <int> list {12,3,4,5,3,2,54,23,7};
    char user_input {};

    do
    {
        cout<<"\nSelect an option from below menu"<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"P - Print numbers"<<endl;
        cout<<"A - Add a number"<<endl;
        cout<<"M - Display mean of the numbers"<<endl;
        cout<<"S - Display the smallest number"<<endl;
        cout<<"L - Display the largest number"<<endl;
        cout<<"O - Display the number of occurencies of an integer in the list"<<endl;
        cout<<"C - Clear the list"<<endl;
        cout<<"R - Remove dulicates if exists"<<endl;
        cout<<"Q - Quit"<<endl<<endl;
        cout<<"Enter your choice: ";
        cin>>user_input;
        if (user_input=='p' || user_input=='P')
        {
            if (list.size() == 0)
            {
                cout<<"[] - the list is empty"<<endl;
            }
            else
            {
                cout<<"[ ";
                for (auto elem:list)
                {
                    cout<<elem<<" ";
                }
                cout<<"] "<<endl;
            }
        }
        else if (user_input=='a' || user_input=='A')
        {
            int user_integer {};
            cout<<"Add an integer to the list: ";
            cin>>user_integer;
            list.push_back(user_integer);
            cout<<list.at(list.size() - 1)<<" added"<<endl;
        }
        else if (user_input=='m' || user_input=='M')
        {
            int sum {};
            if (list.size() == 0)
            {
                cout<<"Unable to calculate the mean - no data";
            }
            else
            {
                for (auto i : list)
                {
                    sum += i;
                }
                cout<<"The mean is "<<double(sum) / list.size()<<endl;
            }
            
        }
        else if (user_input=='s' || user_input=='S')
        {
            int smallest {};
            if (list.size() == 0)
            {
                cout<<"Unable to determine the smallest number - no data";
            }
            else
            {   
                smallest = list.at(0);
                for (int j {0}; j < list.size(); j++)
                {
                    if(list.at(j) < smallest )
                    {
                        smallest = list.at(j);
                    }
                }
                cout<<"The smallest number is "<<smallest<<endl;
            }
        }
        else if (user_input=='l' || user_input=='L')
        {
            int largest {};
            if (list.size() == 0)
            {
                cout<<"Unable to determine the largest number - no data";
            }
            else
            {   
                largest = list.at(0);
                for (int j {0}; j < list.size(); j++)
                {
                    if(list.at(j) > largest )
                    {
                        largest = list.at(j);
                    }
                }
                cout<<"The largest number is "<<largest<<endl;
            }
        }
        else if (user_input=='o' || user_input=='O')
        {
            int searched_number {}, occurencies {};
            cout<<"What number are you looking for? ";
            cin>>searched_number;
            for (auto elem:list)
            {
                if(elem == searched_number)
                {
                    occurencies += 1;

                }
                
            }
            if (occurencies !=0)
            {
                cout<<"The number "<<searched_number<<" appears "<<occurencies<<" time/times in the list";
            }
            else
            {
                    cout<<"Number "<<searched_number<<" not found in the list"<<endl;
            }

        }
         else if (user_input=='c' || user_input=='C')
        {
            char user_clear_list {};
            cout<<"You are about the clear the list. Are you sure? y/n ";
            cin>>user_clear_list;
            if (user_clear_list == 'y' || user_clear_list == 'Y')
            {
                list.clear();
                cout<<"The list is cleared!"<<endl;
            }
            else if (user_clear_list == 'n' || user_clear_list == 'N')
            {
                cout<<"The list is NOT cleared!"<<endl;
            }
            else
            {
                cout<<"Start again selecting a valid answer y/n";
            }
            

        }
         else if (user_input=='r' || user_input=='R')
        {
            if(list.size() == 0)
            {
                cout<<"The list is empty"<<endl;
            }
            else
            {
                sort(list.begin(), list.end());
                auto last = unique(list.begin(), list.end());
                list.erase(last, list.end());
                cout<<"[ ";
                for (auto i: list)
                {
                    cout<<i<<" ";
                }
                cout<<"] "<<endl;
            }
        
               
        }
        else if (user_input=='q' || user_input=='Q')
        {
            cout<<"Goodbye"<<endl;
            stop_while = true;
        }
        else
        {
            cout<<"Unknown selection, please try again"<<endl;
        }

        
    } while (stop_while==false);
    
    

}


   