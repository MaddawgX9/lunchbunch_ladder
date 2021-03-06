#include <iostream>
#include <fstream>
#include "Ladder.h"

using namespace std;

int main(int argc, char* argv[])
{
    Ladder ladder;
    if(argc==2)
    {
	char* ladder_filename = argv[1];
	if(!ladder.load(ladder_filename))
	    cout << "Failed to load filename: " << ladder_filename << endl;
    
	while(1)
        {
	    cout << endl;
	    cout << "Menu:" << endl;
	    cout << "1. Generate Matchup" << endl;
	    cout << "2. Add Entity" << endl;
	    cout << "3. Print Ladder" << endl;
	    cout << "4. Report Winner" << endl;
	    cout << "5. Remove Entity" << endl;
	    cout << "6. Randomize Ladder" << endl;
	    cout << "7. Save & Exit" << endl;
	    string choice;
	    getline(cin,choice);
	    
	    if(choice=="1")
	    {
		ladder.generate_matchup();
	    }
	    else if(choice=="2")
	    {
		string entity_name;
		cout << "Enter Name: ";
		getline(cin,entity_name);
		ladder.create_entity(entity_name);
	    }
	    else if(choice=="3")
	    {
		cout << endl;
		ladder.print();
	    }
	    else if(choice=="4")
	    {
		string rank;
		cout << endl;
		ladder.print();
		cout << "Input the rank of the winning entity: ";
		getline(cin,rank);
		ladder.report_winner(atoi(rank.c_str()));
	    }
	    else if(choice=="5")
	    {
		string rank;
		cout << endl;
		ladder.print();
		cout << "Input the rank of the entity you wish to remove: ";
		getline(cin,rank);
		ladder.remove_entity_by_rank(atoi(rank.c_str()));
	    }
	    else if(choice=="6")
	    {
		ladder.randomize();
		cout << "Randomized Ladder: " << endl;
		ladder.print();
	    }
	    else if(choice=="7")
            {
		ladder.save();
		return 0;
	    }
	    else
		cout << "Please enter a valid number!" << endl;
	}
    }
    else
      cout << "Please enter a db filename!" << endl;
    return 0;
}
