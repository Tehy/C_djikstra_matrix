// ConsoleApplication1.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <limits.h>
#include "stdafx.h"

#define V 5

using namespace std;

//haetaan solmu jota ei viela kasitelty ja jolla pienin etaisyys
int minDist(int dist[], bool routes[]) {
	int min = INT_MAX;
	int min_index;

	//kaydaan verkon solmut lapi
	for (int v = 0; v < V; v++)
	{
		//asetetaan solmulle uusi etaisyys lahteesta jos 
		//a) reittia ei viela kasitelty
		//b) solmun etaisyys on pienempi tai yhtasuuri kuin arvo min (aareton)
		if (routes[v] == false && dist[v] <= min) {
			min = dist[v];
			min_index = v;
		}
		
	}
	//palautetaan solmun indeksi, jolla pienin etaisyys arvo
	return min_index;
}

//valmiin verkon tulostus
void valmisVerkko(int dist[]) {
	cout << "Solmu \t etaisyys lahteesta" << endl;
	for (int i = 0; i < V; i++)
	{
		cout << i << "\t" << dist[i] << endl;
	}
}

//paafunktio lyhimpien reittien laskentaan
void dijkstra(int graph[V][V], int src) {
	//lyhimmat reitit
	int dist[V];

	//reitti taulukko(tieto, onko reittia kayty lapi)
	bool routes[V];

	//alustetaa kaikki etaisyydet aarettomiksi ja reitit arvoon false
	for (int i = 0; i < V; i++)
	{
		dist[i] = INT_MAX;
		routes[i] = false;
	}

	//alustetaan syotetyn lahdesolmun etaisyys nollaksi
	dist[src] = 0; // src= 0; ???

	//etsitaan lyhimmat reiti lahdesolmusta verkon muihin solmuihin
	for (int x = 0; x < V-1; x++)
	{
		// haetaan solmu jolla on nnyt pienin etaisyys lahdesolmusta
		int u = minDist(dist, routes);

		// merkitaan solmu kasitellyksi
		routes[u] = true;
		
		// etaisyyden paivittaminen
		for (int v = 0; v < V; v++)
		{
			// paivitetaan solmun v etaisyys jos
			// a) reitti ei loydy reittilistalta ja
			// b) solmusta u on yhteys solmuun v ja
			// c) etaisyys lahteesta solmun u kautta solmuun v on pienempi kuin solmulle v aiemmin merkitty etaisyys
			if (!routes[v] && graph[u][v] && dist[u]+graph[u][v] < dist[v])
			{
				dist[v] = dist[u] + graph[u][v];
			}
		}

	}
	// tulostetaan valmis verkko
	valmisVerkko(dist);
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
	dijkstra(graph, 0);

}

