
/*****************************************************************************

	File Description :
	Includes functions which builds the MST on the graph actor_info
	by running BFS treversal on it.

*****************************************************************************/

#include<iostream>
#include"maps.h"

using namespace std;


/*******************************************************************************
 *			      bfs
 * Author: Mangesh Sakordekar
 *
 * Description:
 * bfs runs the breadth first search algorithm on the graphs stored by readbin.cpp.
 * This creates the minimum spanning tree with Kevin Bacon as the root.
 *
 * Parameters: unordered_map <string,vector<string>> &movie_to_actors
 *				-map of movies and the cast of each
 *			unordered_map <string,vector<string>> &actor_to_movies
 *				-map of actors and all the movies they have been in
 * 			unordered_map <string, graphNode> &actor_info
 *				-map of all actors and the information associated with them
 *			string key			-name of actor at root of MST
 *
*******************************************************************************/
void bfs( unordered_map <string, vector<string>> &movie_to_actors,
	  unordered_map <string, vector<string>> &actor_to_movies, 
	  unordered_map <string, graphNode> &actor_info, string key)
{
  //A queue for breadth first search trevarsal 
  queue < graphNode > Q;

  //Temporart graph nodes
  graphNode temp,prev;
  
  // iterators for traversing maps
  unordered_map <string, graphNode> :: iterator itr1, itr2;
  vector <string> :: iterator it1,it2;
  unordered_map <string, vector<string> > :: iterator atm, mta;
  
  cout << "Building MST..... ";
  
  // starts iterator at the root actor
  itr1 = actor_info.find(key);
  
  // checks if actor is in map
  if(itr1 == actor_info.end())
     cout << "Not found" << endl;
     
  // sets root in MST to the root actor 
  itr1->second.bac_num = 0;
  temp = itr1->second;
  temp.bac_num = 0;
  Q.push(temp);
  
  // creates MST from map
  while(!Q.empty())
    {
      prev = Q.front();
      Q.pop();
      atm = actor_to_movies.find(prev.actor);
      
      // iterates through map of actors and all of the movies they have played in
      for(it1 = atm->second.begin(); it1 != atm->second.end(); it1++)
	  {
	    mta = movie_to_actors.find(*it1);
	    
	    // iterates through map of movies and the cast of each
	    for(it2 = mta->second.begin(); it2 != mta->second.end(); it2++)
	    {
		  itr2 = actor_info.find(*it2);
		  temp = itr2->second;
		  
		  // no path to an actor was found
		  if(temp.bac_num == -1 )
		  {
		    temp.par_actor = prev.actor;
		    itr2->second.par_actor = prev.actor;
		    temp.film = *it1;
		    itr2->second.film = *it1;
		    temp.bac_num = prev.bac_num + 1;
		    itr2->second.bac_num = prev.bac_num + 1;
		    temp.actor = itr2->second.actor;
		    Q.push(temp);
		  }
	    }
	  }
    }
  cout << "done!" << endl;
}
