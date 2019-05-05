// Copyright 2019 SD_Homework_Team

#ifndef SOLVER_H_
#define SOLVER_H_
#include <fstream>
#include <iostream>
#include "citymap.h"

class solver {
   public:
    Citymap map;
    int32_t N,M;

    void task1_solver(std::ifstream& fin, std::ofstream& fout) {
        // Read the number of intersections and streets
        fin >> N >> M;

        for(int32_t i=0; i<N; i++) {
            std::string lastRead;
            fin >> lastRead;
            map.addIntersection(lastRead);
        }

        for(int32_t i=0; i<M; i++) {
            std::string src, dest;
            fin >> src >> dest;
            map.addStreet(src, dest);
        }

        int32_t queryN;
        fin >> queryN;
        for(int32_t i=0; i<queryN; i++) {
            std::string src, dest;
            fin >> src >> dest;
            if(map.routeExist(src, dest)==0) {
                fout << "n\n";
            } else {
                fout << "y\n";
            }
        }
    }

    void task2_solver(std::ifstream& fin, std::ofstream& fout) {
        int32_t queryN;
        fin >> queryN;
        for(int32_t i=0; i<queryN; i++) {
            std::string src, dest;
            fin >> src >> dest;
            fout << map.routeLength(src, dest) << "\n";
        }
    }

    void task3_solver(std::ifstream& fin, std::ofstream& fout) {
        int32_t queryN;
        fin >> queryN;
        for(int32_t i=0; i<queryN; i++) {
            u_int32_t type;
            std::string src, dest, option;
            fin >> option >> src >> dest >> type;
            if(option == "c") {
                if(type == 0) {
                    map.addStreet(src, dest);
                } else if(type == 1) {
                    map.remove2WayStret(src, dest);
                } else if(type == 2) {
                    map.add2WayStreet(src, dest);
                } else {
                    map.switchWay(src, dest);
                }
            } else {
                if(type == 0) {
                    if(map.routeExist(src, dest) == 0) {
                        fout << "n\n";
                    } else {
                        fout << "y\n";
                    }
                } else if(type == 1) {
                    fout << map.routeLength(src, dest) << "\n";
                } else {
                    std::string inter;
                    fin >> inter;

                    int32_t length = 0;
                    int32_t last = map.routeLength(src, inter);
                    if(last!=-1) {
                        length += last;
                        last = map.routeLength(inter, dest);
                        if(last!=-1) {
                            length += last;
                            fout << length << "\n";
                        }   else {
                            fout << "-1\n";
                        }
                    } else {
                        fout << "-1\n";
                    }
                }
            }
        }
    }

    void task4_solver(std::ifstream& fin, std::ofstream& fout) {}

    void task5_solver(std::ifstream& fin, std::ofstream& fout) {}
};
#endif  // SOLVER_H_
