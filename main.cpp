/*******************************************************************************
 * 		       Minimum Spanning Trees (Bacon Number)
 *										
 * Author: Mangesh Sakordekar and Michael Brock
 * Class: CSC 315 Data Structures and Algorithms
 * Instructor: Dr. Weiss
 * Due Date: 4/24/18
 * Date Written: April 2018
 *
 * This program creates a Minimum Spanning Tree containing a actors from a text file.
 * The tree contains all the paths of from one actor to Kevin Bacon. An edge is
 * created between any two actors that were in the same cast of a movie. This tr//Counter for movies and actors
  int movie_count = 0;
  int actor_count = 0;
  int kb_movie_count = 0;ee
 * is used to find the path to Kevin Bacon from any actor in the file.
 *
 * Program Usage: bacon database_file [actor]
 * External Files: movies2018.dat action2006.dat
 *
 ****************************************************************************/

#include <iostream>
#include<fstream>
#include<ctime>
#include "maps.h"

using namespace std;

/*******************************************************************************
 *				   Main
 * 										
 * Contains function calls and manages program.
 *
*******************************************************************************/
int main( int argc, char *argv[] )
{
    //Maps to store the data
    unordered_map <string, vector<string> > movie_to_actors;
    unordered_map <string, vector<string> > actor_to_movies;
    unordered_map <string, graphNode> actor_info;

    // process command-line arguments
    char* filename;         // input filename
    string key="Kevin Bacon";

    //Variables for storing runtime
    clock_t t1,t2;

    t1=clock(); //Stores time at the start of the program

    switch ( argc )
    {
        case 3:
            key = argv[2];
        case 2:
            filename = argv[1];
            break;
        default:
            printf( "Usage: %s file.dat\n", argv[0] );
            return -1;
    }

    //Opening the file
    ifstream fin;
    fin.open(filename);		// open file

    //Checking for successful opening of the file
    if(!fin)
      {
	cout << endl << "Could not open the file " << filename;
	cout << endl <<endl;
	exit(1);
      }

    // reads in data from text file into maps
    cout << endl << "Reading in " << filename << " ........";
    cout << endl << endl;
    readData(fin,movie_to_actors,actor_to_movies,actor_info,key);
   
	
	// calculates run time to read in text file
    t2 = clock();
    float diff ((float)t2 - (float)t1);
    cout << "(elapsed time: " << diff / 1000000 << "s)" << endl << endl;

    
    // runs breadth first search algorithm to create MST
    bfs(movie_to_actors,actor_to_movies, actor_info, key);
	
    // calculates run time to run bfs 
    t2 = clock();
    float diff2 ((float)t2 - (float)t1);
    cout << "(elapsed time: " << diff2 / 1000000 << "s)" << endl << endl;

    //Performing statistic analysis on the data
    //Temporary variable to store maximum bacon number
    int m = countBacon(actor_info);
    find_longest(actor_info, m);
    findBacon(actor_info);
   
    return 0;
}
