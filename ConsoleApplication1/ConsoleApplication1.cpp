// ConsoleApplication1.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <limits.h>
#include "stdafx.h"

#define V 5

using namespace std;

//haetaan solmu jolla pienin etaisyys
int minDist(int dist[], bool routes[]) {

}

//valmiin verkon tulostus
void valmisVerkko(int dist[]) {

}

//paafunktio lyhimpien reittien laskentaan
void djikstra(int graph[V][V], int src) {

}

//paaohjelma
int main()
{
    //verkkomatriisi
	int graph[V][V] = { {0,4,0,0,1},
					{4,0,2,0,2},
					{0,2,0,2,5},
					{0,0,2,0,1},
					{1,2,5,1,0} };
	
	//kustutaan paafunktiota
	djikstra(graph, 0);

}

