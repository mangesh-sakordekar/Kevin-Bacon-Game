//Header file for the program
#include <unordered_map>
#include<string>
#include<queue>
#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

/******************************************************************************
			       graphNode
Description:
Vertices of MST

Parameters: string par_actor		- name of parent vertex of actor vertex
	    string actor		- name of actor in vertex
	    string film			- name of film in vertex
	    int bac_num			- distance (bacon number) from root actor

******************************************************************************/
struct graphNode
{
  string par_actor;
  string actor;
  string film;
  int bac_num;
};

/******************************************************************************
				 Function Prototypes

******************************************************************************/
void readData(ifstream &fin, unordered_map<string,
	      vector<string>> &movie_to_actors, unordered_map<string,
	      vector<string>> &actor_to_movies, 
	      unordered_map <string, graphNode> &actor_info, string key);

void bfs( unordered_map <string, vector<string> > &movie_to_actors, 
	  unordered_map <string, vector<string> > &actor_to_movies, 
	  unordered_map <string, graphNode> &actor_info,string key);

int countBacon(unordered_map < string, graphNode > &actor_info);
void find_longest(unordered_map < string, graphNode > &actor_info, int max);
void print_longest(unordered_map < string, graphNode > &actor_info, string actor);
void findBacon(unordered_map < string, graphNode > &actor_info);
void print_find(unordered_map < string, graphNode > &actor_info, string actor);

