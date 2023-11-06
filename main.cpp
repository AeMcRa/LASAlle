
//
//  main.cpp
//  LLTemplate
//
//  Created by James Shockey on 12/6/16.
//  Copyright © 2016 James Shockey. All rights reserved.
//

/*
 *
 *	Linked List lab.
 *	- Build a library for singly linked list.
 *	- Replace the airport array in main with a Linked List.
 *  - sort the array.
 *
 */

#include "slist.h"
#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void simpleSortTotal(Linkedlist *a, int c, double alat, double alon);
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d);

int main() {
  cout << "start" << endl;
  ifstream infile;
  int i = 0;
  int c = 0;
  char cNum[128];
  Linkedlist *Airports = new Linkedlist();
  Node *previous = Airports->head;
  // Airport* airportArr[13500];			// Replace array with
  // Linked List
  int airportCount;
  // Airport* a[13500];
  cout << "reading file" << endl;
  infile.open("airport-codes_US.csv", ifstream::in);
  if (infile.is_open()) {

    cout << "opened" << endl;
    infile.ignore(500, '\n');

    while (infile.good()) {
      char cd[5];
      double lon;
      double lat;

      infile.getline(cd, 256, ',');
      infile.getline(cNum, 256, ',');
      infile.getline(cNum, 256, ',');
      infile.getline(cNum, 256, ',');
      lon = atof(cNum);
      infile.getline(cNum, 256, ',');
      lat = atof(cNum);
      infile.getline(cNum, 256, '\n');
      Node *newNode = new Node(cd, lon, lat);
      Airports->add(newNode);

      /*
  airportArr[c] = new Airport();
  infile.getline(airportArr[c]->code, 256, ',');
  infile.getline(cNum, 256, ',');
  airportArr[c]->longitude = atof(cNum);
  infile.getline(cNum, 256, '\n');
  airportArr[c]->latitude = atof(cNum);





  if (!(c % 1000))
      cout << airportArr[c]->code << " long: " << airportArr[c]->longitude
  << " lat: " << airportArr[c]->latitude <<  endl;
*/
      /*
      if (!(c % 1000))
      {
          cout << airportArr[c]->code << " long: " << airportArr[c]->longitude
      << " lat: " << airportArr[c]->latitude <<  endl; cout <<
      airportArr[c+1]->code << endl; //" long: " << airportArr[c+1]->longitude
      << " lat: " << airportArr[c+1]->latitude <<  endl;
      }
      */

      i++;
      c++;
    }
    c -= 6;
    infile.close();
    /*
     for (int c=0; c < airportCount; c++)
        if (!(c % 1000))
        {
            cout << airportArr[c]->code << " long: " << airportArr[c]->longitude
     << " lat: " << airportArr[c]->latitude <<  endl; cout <<
     airportArr[c+1]->code << " long: " << airportArr[c+1]->longitude << " lat:
     " << airportArr[c+1]->latitude <<  endl; cout <<"Distance between " <<
     airportArr[c]->code << " and " << airportArr[c+1]->code << " is "
              << distanceEarth( airportArr[c]->longitude,
     airportArr[c]->latitude , airportArr[c+1]->longitude,
     airportArr[c+1]->latitude) << endl;
        }
*/

  }

  else {
    cout << "Error opening file";
  }

  string tcode = "KAUS";
  Node *temp = Airports->head;

  string curcode = temp->code;
  while (curcode != tcode) {

    temp = temp->next;
    curcode = temp->code;
  }
  double alat = temp->latitude;
  double alon = temp->longitude;

  simpleSortTotal(Airports, c, alat, alon);

  Node *temp2 = Airports->head;
  int counter = 0;
  while (counter < c) {
    if(distanceEarth(alat, alon, temp2->latitude, temp2->longitude) <=100)
    cout << temp2->code << " "
         << distanceEarth(alat, alon, temp2->latitude, temp2->longitude)
         << endl;
    temp2 = temp2->next;
    counter++;
  }
}

#define pi 3.14159265358979323846
#define earthRadiusKm 6371.0

// This function converts decimal degrees to radians
double deg2rad(double deg) { return (deg * pi / 180); }

//  This function converts radians to decimal degrees
double rad2deg(double rad) { return (rad * 180 / pi); }

/**
 * Returns the distance between two points on the Earth.
 * Direct translation from http://en.wikipedia.org/wiki/Haversine_formula
 * @param lat1d Latitude of the first point in degrees
 * @param lon1d Longitude of the first point in degrees
 * @param lat2d Latitude of the second point in degrees
 * @param lon2d Longitude of the second point in degrees
 * @return The distance between the two points in kilometers
 */
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d) {
  double lat1r, lon1r, lat2r, lon2r, u, v;
  lat1r = deg2rad(lat1d);
  lon1r = deg2rad(lon1d);
  lat2r = deg2rad(lat2d);
  lon2r = deg2rad(lon2d);
  u = sin((lat2r - lat1r) / 2);
  v = sin((lon2r - lon1r) / 2);
  return 2.0 * earthRadiusKm *
         asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}

/*
        Provide sort routine on linked list
*/

void simpleSortTotal(Linkedlist *a, int c, double alat, double alon) {

  for (int i = 0; i < c - 1; i++) {
    Node **pjnode = &a->head;
    Node *jnode = a->head;
    for (int j = 0; j < c - i - 1; j++) {
      /* if(j > 210){
        cout<<"hi"<<endl;
       } */

      // cout << jnode->code << endl;

      // cout <<distanceEarth(alat, along, jnode->latitude, jnode->longitude)
      // <<" " << distanceEarth(alat, along, jnode->next->latitude,
      // jnode->next->longitude) <<endl;

      if (distanceEarth(alat, alon, jnode->latitude, jnode->longitude) >
          distanceEarth(alat, alon, jnode->next->latitude,
                        jnode->next->longitude)) {

        // a->shape();

        a->fasterSwap(pjnode, &jnode->next, jnode, jnode->next, j, j + 1);

        jnode = *pjnode;
        // cout <<inode->code << endl;
        // cout << jnode->code << endl;
        // a->shape();
      }
      pjnode = &jnode->next;
      jnode = jnode->next;
    }
    // cout <<jnode->code << " "<< distanceEarth(alat, along,
    // jnode->latitude,jnode->longitude)<< endl;
  }
  cout << "hi" << endl;
}
